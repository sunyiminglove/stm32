#include "sys.h"
#include "dma.h"	
#include "usart2.h"	
//#include "delay.h"
//#include "led.h" 
#include "Modbus_slave.h"
////////////////////////////////////////////////////////////////////////////////// 	 
//如果使用ucos,则包括下面的头文件即可.
#if SYSTEM_SUPPORT_OS
#include "includes.h"					//ucos 使用	  
#endif

u8 BEEP_flag=0;

//初始化IO 串口4
//bound:波特率
void usart2_init(u32 bound)
{
  //GPIO端口设置
	GPIO_InitTypeDef GPIO_InitStructure;
	USART_InitTypeDef USART_InitStructure;
	NVIC_InitTypeDef NVIC_InitStructure;
	
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD,ENABLE); //使能GPIOA时钟
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART2,ENABLE);//使能UART4时钟
 
	//串口2对应引脚复用映射
	GPIO_PinAFConfig(GPIOD,GPIO_PinSource5,GPIO_AF_USART2);
	GPIO_PinAFConfig(GPIOD,GPIO_PinSource6,GPIO_AF_USART2);

	//UART2端口配置
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5 | GPIO_Pin_6; //GPIOA9与GPIOA10
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;//复用功能
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;	//速度50MHz
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP; //推挽复用输出
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP; //上拉
	GPIO_Init(GPIOD,&GPIO_InitStructure); //初始化PA0，PA1
	

  //UART2 初始化设置
	USART_InitStructure.USART_BaudRate = bound;									//波特率设置
	USART_InitStructure.USART_WordLength = USART_WordLength_8b;	//字长为8位数据格式
	USART_InitStructure.USART_StopBits = USART_StopBits_1;			//一个停止位
	USART_InitStructure.USART_Parity = USART_Parity_No;					//无奇偶校验位
	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;//无硬件数据流控制
	USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;	//收发模式
	USART_Init(USART2, &USART_InitStructure);	
	
	NVIC_InitStructure.NVIC_IRQChannel = USART2_IRQn;  
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
  NVIC_Init(&NVIC_InitStructure);
	
	USART_ITConfig(USART2, USART_IT_IDLE, ENABLE);
	USART_Cmd(USART2, ENABLE);  
	USART_ClearFlag(USART2, USART_FLAG_TC);
	USART_DMACmd(USART2, USART_DMAReq_Tx, ENABLE);
	USART_DMACmd(USART2, USART_DMAReq_Rx, ENABLE);
	
}

void USART2_IRQHandler(void)             
{
	char *p;
	char dst[4]={0,0,0,0};
	char *l="$";
    u8 i=0;	

#if SYSTEM_SUPPORT_OS 	
	OSIntEnter();    
#endif
	if(USART_GetITStatus(USART2, USART_IT_IDLE) != RESET) 
	{
		DMA_Cmd(DMA1_Stream5,DISABLE);
		rece2_index = USART2->SR;
		rece2_index = USART2->DR; //清除IDLE标志
		rece2_index = UART_RX_LEN - DMA_GetCurrDataCounter(DMA1_Stream5); 
		DMA1_Stream5->NDTR = UART_RX_LEN;
		//解析地标
		//rece_buf
		if(rece2_index>0)
		{
			p=strstr(rece_buf,l);
			if(p)
			{
				dst[0]=p[13];
				dst[1]=p[14];
				dst[2]=p[15];
				dst[3]=p[16];
				for(i=0;i<rece2_index;i++)
				rece_buf[i]=0;
				rece2_index=0;
				keynumber=(dst[0]-0x30)*1000+(dst[1]-0x30)*100+(dst[2]-0x30)*10+(dst[3]-0x30);
				PLC_Data[16]=keynumber;
				BEEP_flag=1;
				
			}
		} 
		DMA_Cmd(DMA1_Stream5, ENABLE);
		
		
	}
#if SYSTEM_SUPPORT_OS 	
	OSIntExit();  											 
#endif
} 


 



