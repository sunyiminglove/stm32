#include "dma.h"																	   	  
#include "delay.h"
#include "usart6.h"

u16 AD_Value[30][3];
double After_filter[3];//ADC的寄存器
u8 rece_index=0,rece2_index=0,rece6_index=0,rece3_index=0;
u8  sendBuf[UART_RX_LEN];  //定义发送数组，最大允许发送32个字，64个字节
u8  receBuf[UART_RX_LEN];	//定义接收数组，最大允许接收32个字，64个字节写入
char  rece_buf[UART_RX_LEN];
char  send_buf[UART_RX_LEN];
char  rece6_buf[UART6_RX_LEN];
char  send6_buf[UART6_RX_LEN];
u8  rece3_buf[UART6_RX_LEN];
u8  send3_buf[UART6_RX_LEN];
u8 u6sendflag=0;
//u8 *ps=sendBuf;
//u8 *pr=receBuf;
void DMA_adc1_Init(void)
{
		NVIC_InitTypeDef NVIC_InitStructure;
    DMA_InitTypeDef DMA_InitStructure;  
    /* DMA clock enable */
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_DMA2, ENABLE);
      
    DMA_Cmd(DMA2_Stream0, DISABLE);
    DMA_DeInit(DMA2_Stream0);
		DMA_InitStructure.DMA_Channel = DMA_Channel_0;
    DMA_InitStructure.DMA_PeripheralBaseAddr = ADC1_DR_Addr;
    DMA_InitStructure.DMA_Memory0BaseAddr = (uint32_t)AD_Value;
    DMA_InitStructure.DMA_DIR = DMA_DIR_PeripheralToMemory ;
    DMA_InitStructure.DMA_BufferSize = 90;
    DMA_InitStructure.DMA_PeripheralInc = DMA_PeripheralInc_Disable;
    DMA_InitStructure.DMA_MemoryInc = DMA_MemoryInc_Enable;
    DMA_InitStructure.DMA_PeripheralDataSize = DMA_PeripheralDataSize_HalfWord;
    DMA_InitStructure.DMA_MemoryDataSize = DMA_PeripheralDataSize_HalfWord;
    DMA_InitStructure.DMA_Mode = DMA_Mode_Circular;
		DMA_InitStructure.DMA_FIFOMode = DMA_FIFOMode_Disable; 
    DMA_InitStructure.DMA_FIFOThreshold = DMA_FIFOThreshold_Full;	
    DMA_InitStructure.DMA_Priority = DMA_Priority_VeryHigh;
		DMA_InitStructure.DMA_MemoryBurst = DMA_MemoryBurst_Single;//存储器突发单次传输
		DMA_InitStructure.DMA_PeripheralBurst = DMA_PeripheralBurst_Single;//外设突发单次传输
		
		DMA_Init(DMA2_Stream0, &DMA_InitStructure);
		
		DMA_ITConfig(DMA2_Stream0, DMA_IT_TC, ENABLE);
    DMA_Cmd(DMA2_Stream0, ENABLE); 

		NVIC_InitStructure.NVIC_IRQChannel = DMA2_Stream0_IRQn;  
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 3;
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 2;
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&NVIC_InitStructure);
}	  
void  DMA2_Stream0_IRQHandler(void)//ADC1的DMA的服务函数
{
	long  sum = 0;
	u8 count,i;
	if(DMA_GetITStatus(DMA2_Stream0,DMA_IT_TCIF0) != RESET)
	{
	   for(i=0;i<3;i++)
	   {
				for(count=0;count<30;count++)
				{
					sum += AD_Value[count][i];
				}
				After_filter[i]=sum/30;
				sum=0;
	   }
	  DMA_ClearITPendingBit(DMA2_Stream0,DMA_IT_TCIF0);
	}
} 
/**********************************/
void DMA_Uart2_Init(void)
{
		NVIC_InitTypeDef NVIC_InitStructure;
    DMA_InitTypeDef DMA_InitStructure;  
    /* DMA clock enable */
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_DMA1, ENABLE);//注意用的那个AHB
      
	/*--- LUMMOD_UART_Tx_DMA_Channel DMA Config ---*/
 
    DMA_Cmd(DMA1_Stream6, DISABLE);
    DMA_DeInit(DMA1_Stream6);
		DMA_InitStructure.DMA_Channel = DMA_Channel_4;
    DMA_InitStructure.DMA_PeripheralBaseAddr = (uint32_t)(&USART2->DR);
    DMA_InitStructure.DMA_Memory0BaseAddr = (uint32_t)send_buf;
    DMA_InitStructure.DMA_DIR = DMA_DIR_MemoryToPeripheral;
    DMA_InitStructure.DMA_BufferSize = UART_TX_LEN;
    DMA_InitStructure.DMA_PeripheralInc = DMA_PeripheralInc_Disable;
    DMA_InitStructure.DMA_MemoryInc = DMA_MemoryInc_Enable;
    DMA_InitStructure.DMA_PeripheralDataSize = DMA_PeripheralDataSize_Byte;
    DMA_InitStructure.DMA_MemoryDataSize = DMA_MemoryDataSize_Byte;
    DMA_InitStructure.DMA_Mode = DMA_Mode_Circular;	
		DMA_InitStructure.DMA_FIFOMode = DMA_FIFOMode_Disable; 
    DMA_InitStructure.DMA_FIFOThreshold = DMA_FIFOThreshold_Full;	
    DMA_InitStructure.DMA_Priority = DMA_Priority_VeryHigh;
		DMA_InitStructure.DMA_MemoryBurst = DMA_MemoryBurst_Single;//存储器突发单次传输
		DMA_InitStructure.DMA_PeripheralBurst = DMA_PeripheralBurst_Single;//外设突发单次传输
		
    DMA_Init(DMA1_Stream6, &DMA_InitStructure);
		DMA_Cmd(DMA1_Stream6, DISABLE);
    DMA_ITConfig(DMA1_Stream6, DMA_IT_TC, ENABLE);
   
/*--- LUMMOD_UART_Rx_DMA_Channel DMA Config ---*/
 
    DMA_Cmd(DMA1_Stream5, DISABLE);
    DMA_DeInit(DMA1_Stream5);
		DMA_InitStructure.DMA_Channel = DMA_Channel_4;
    DMA_InitStructure.DMA_PeripheralBaseAddr = (uint32_t)(&USART2->DR);
    DMA_InitStructure.DMA_Memory0BaseAddr = (uint32_t)rece_buf;
    DMA_InitStructure.DMA_DIR = DMA_DIR_PeripheralToMemory ;
    DMA_InitStructure.DMA_BufferSize = UART_RX_LEN;
    DMA_InitStructure.DMA_PeripheralInc = DMA_PeripheralInc_Disable;
    DMA_InitStructure.DMA_MemoryInc = DMA_MemoryInc_Enable;
    DMA_InitStructure.DMA_PeripheralDataSize = DMA_PeripheralDataSize_Byte;
    DMA_InitStructure.DMA_MemoryDataSize = DMA_MemoryDataSize_Byte;
    DMA_InitStructure.DMA_Mode = DMA_Mode_Circular;
		DMA_InitStructure.DMA_FIFOMode = DMA_FIFOMode_Disable; 
    DMA_InitStructure.DMA_FIFOThreshold = DMA_FIFOThreshold_Full;	
    DMA_InitStructure.DMA_Priority = DMA_Priority_VeryHigh;
		DMA_InitStructure.DMA_MemoryBurst = DMA_MemoryBurst_Single;//存储器突发单次传输
		DMA_InitStructure.DMA_PeripheralBurst = DMA_PeripheralBurst_Single;//外设突发单次传输
		
    DMA_Init(DMA1_Stream5, &DMA_InitStructure);
    DMA_Cmd(DMA1_Stream5, ENABLE);  

		NVIC_InitStructure.NVIC_IRQChannel = DMA1_Stream6_IRQn;  
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&NVIC_InitStructure);	
}
 /**********************************/
void DMA_Uart3_Init(void)
{
		NVIC_InitTypeDef NVIC_InitStructure;
    DMA_InitTypeDef DMA_InitStructure;  
    /* DMA clock enable */
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_DMA1, ENABLE);//注意用的那个AHB
      
	/*--- LUMMOD_UART_Tx_DMA_Channel DMA Config ---*/
 
		DMA_Cmd(DMA1_Stream3, DISABLE);
		DMA_DeInit(DMA1_Stream3);
		DMA_InitStructure.DMA_Channel = DMA_Channel_4;
		DMA_InitStructure.DMA_PeripheralBaseAddr = (uint32_t)(&USART3->DR);
		DMA_InitStructure.DMA_Memory0BaseAddr = (uint32_t)send3_buf;
		DMA_InitStructure.DMA_DIR = DMA_DIR_MemoryToPeripheral;
		DMA_InitStructure.DMA_BufferSize = UART_TX_LEN;
		DMA_InitStructure.DMA_PeripheralInc = DMA_PeripheralInc_Disable;
		DMA_InitStructure.DMA_MemoryInc = DMA_MemoryInc_Enable;
		DMA_InitStructure.DMA_PeripheralDataSize = DMA_PeripheralDataSize_Byte;
		DMA_InitStructure.DMA_MemoryDataSize = DMA_MemoryDataSize_Byte;
		DMA_InitStructure.DMA_Mode = DMA_Mode_Circular;	
		DMA_InitStructure.DMA_FIFOMode = DMA_FIFOMode_Disable; 
		DMA_InitStructure.DMA_FIFOThreshold = DMA_FIFOThreshold_Full;	
		DMA_InitStructure.DMA_Priority = DMA_Priority_VeryHigh;
		DMA_InitStructure.DMA_MemoryBurst = DMA_MemoryBurst_Single;//存储器突发单次传输
		DMA_InitStructure.DMA_PeripheralBurst = DMA_PeripheralBurst_Single;//外设突发单次传输
		DMA_Init(DMA1_Stream3, &DMA_InitStructure);
		DMA_Cmd(DMA1_Stream3, DISABLE);
		DMA_ITConfig(DMA1_Stream3, DMA_IT_TC, ENABLE);
   
/*--- LUMMOD_UART_Rx_DMA_Channel DMA Config ---*/
 
    DMA_Cmd(DMA1_Stream1, DISABLE);
    DMA_DeInit(DMA1_Stream1);
		DMA_InitStructure.DMA_Channel = DMA_Channel_4;
    DMA_InitStructure.DMA_PeripheralBaseAddr = (uint32_t)(&USART3->DR);
    DMA_InitStructure.DMA_Memory0BaseAddr = (uint32_t)rece3_buf;
    DMA_InitStructure.DMA_DIR = DMA_DIR_PeripheralToMemory ;
    DMA_InitStructure.DMA_BufferSize = UART_RX_LEN;
    DMA_InitStructure.DMA_PeripheralInc = DMA_PeripheralInc_Disable;
    DMA_InitStructure.DMA_MemoryInc = DMA_MemoryInc_Enable;
    DMA_InitStructure.DMA_PeripheralDataSize = DMA_PeripheralDataSize_Byte;
    DMA_InitStructure.DMA_MemoryDataSize = DMA_MemoryDataSize_Byte;
    DMA_InitStructure.DMA_Mode = DMA_Mode_Circular;
		DMA_InitStructure.DMA_FIFOMode = DMA_FIFOMode_Disable; 
    DMA_InitStructure.DMA_FIFOThreshold = DMA_FIFOThreshold_Full;	
    DMA_InitStructure.DMA_Priority = DMA_Priority_VeryHigh;
		DMA_InitStructure.DMA_MemoryBurst = DMA_MemoryBurst_Single;//存储器突发单次传输
		DMA_InitStructure.DMA_PeripheralBurst = DMA_PeripheralBurst_Single;//外设突发单次传输
	
    DMA_Init(DMA1_Stream1, &DMA_InitStructure);
    DMA_Cmd(DMA1_Stream1, ENABLE);   
		
		NVIC_InitStructure.NVIC_IRQChannel = DMA1_Stream3_IRQn;  
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 2;
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&NVIC_InitStructure);
}
void Uart3_Start_DMA_Tx(u16 size)
{
    DMA_SetCurrDataCounter(DMA1_Stream3,size);
    DMA_Cmd(DMA1_Stream3, ENABLE);
}

/**********************************/
void DMA_Uart4_Init(void)
{
		NVIC_InitTypeDef NVIC_InitStructure;
    DMA_InitTypeDef DMA_InitStructure;  
    /* DMA clock enable */
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_DMA1, ENABLE);
      
	/*--- LUMMOD_UART_Tx_DMA_Channel DMA Config ---*/
 
    DMA_Cmd(DMA1_Stream4, DISABLE);
    DMA_DeInit(DMA1_Stream4);
		DMA_InitStructure.DMA_Channel = DMA_Channel_4;
    DMA_InitStructure.DMA_PeripheralBaseAddr = (uint32_t)(&UART4->DR);
    DMA_InitStructure.DMA_Memory0BaseAddr = (uint32_t)sendBuf;
    DMA_InitStructure.DMA_DIR = DMA_DIR_MemoryToPeripheral;
    DMA_InitStructure.DMA_BufferSize = UART_TX_LEN;
    DMA_InitStructure.DMA_PeripheralInc = DMA_PeripheralInc_Disable;
    DMA_InitStructure.DMA_MemoryInc = DMA_MemoryInc_Enable;
    DMA_InitStructure.DMA_PeripheralDataSize = DMA_PeripheralDataSize_Byte;
    DMA_InitStructure.DMA_MemoryDataSize = DMA_MemoryDataSize_Byte;
    DMA_InitStructure.DMA_Mode = DMA_Mode_Circular;	
		DMA_InitStructure.DMA_FIFOMode = DMA_FIFOMode_Disable; 
    DMA_InitStructure.DMA_FIFOThreshold = DMA_FIFOThreshold_Full;	
    DMA_InitStructure.DMA_Priority = DMA_Priority_VeryHigh;
		DMA_InitStructure.DMA_MemoryBurst = DMA_MemoryBurst_Single;//存储器突发单次传输
		DMA_InitStructure.DMA_PeripheralBurst = DMA_PeripheralBurst_Single;//外设突发单次传输
		
    DMA_Init(DMA1_Stream4, &DMA_InitStructure);
		DMA_Cmd(DMA1_Stream4, DISABLE);
    DMA_ITConfig(DMA1_Stream4, DMA_IT_TC, ENABLE);
   
/*--- LUMMOD_UART_Rx_DMA_Channel DMA Config ---*/
 
    DMA_Cmd(DMA1_Stream2, DISABLE);
    DMA_DeInit(DMA1_Stream2);
		DMA_InitStructure.DMA_Channel = DMA_Channel_4;
    DMA_InitStructure.DMA_PeripheralBaseAddr = (uint32_t)(&UART4->DR);
    DMA_InitStructure.DMA_Memory0BaseAddr = (uint32_t)receBuf;
    DMA_InitStructure.DMA_DIR = DMA_DIR_PeripheralToMemory ;
    DMA_InitStructure.DMA_BufferSize = UART_RX_LEN;
    DMA_InitStructure.DMA_PeripheralInc = DMA_PeripheralInc_Disable;
    DMA_InitStructure.DMA_MemoryInc = DMA_MemoryInc_Enable;
    DMA_InitStructure.DMA_PeripheralDataSize = DMA_PeripheralDataSize_Byte;
    DMA_InitStructure.DMA_MemoryDataSize = DMA_MemoryDataSize_Byte;
    DMA_InitStructure.DMA_Mode = DMA_Mode_Circular;
		DMA_InitStructure.DMA_FIFOMode = DMA_FIFOMode_Disable; 
    DMA_InitStructure.DMA_FIFOThreshold = DMA_FIFOThreshold_Full;	
    DMA_InitStructure.DMA_Priority = DMA_Priority_VeryHigh;
		DMA_InitStructure.DMA_MemoryBurst = DMA_MemoryBurst_Single;//存储器突发单次传输	
		DMA_InitStructure.DMA_PeripheralBurst = DMA_PeripheralBurst_Single;//外设突发单次传输
		
    DMA_Init(DMA1_Stream2, &DMA_InitStructure);
    DMA_Cmd(DMA1_Stream2, ENABLE);  

		NVIC_InitStructure.NVIC_IRQChannel = DMA1_Stream4_IRQn;  
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 3;
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&NVIC_InitStructure);	
}
void Uart4_Start_DMA_Tx(u16 size)
{
	GPIO_SetBits(GPIOA,GPIO_Pin_2);
  DMA_SetCurrDataCounter(DMA1_Stream4,size);
  DMA_Cmd(DMA1_Stream4, ENABLE);
}
 /**********************************/
void DMA_Uart6_Init(void)
{
	NVIC_InitTypeDef NVIC_InitStructure;

	DMA_InitTypeDef DMA_InitStructure;  

	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_DMA2, ENABLE);

	DMA_Cmd(DMA2_Stream7, DISABLE);
	DMA_DeInit(DMA2_Stream7);
	DMA_InitStructure.DMA_Channel = DMA_Channel_5;
	DMA_InitStructure.DMA_PeripheralBaseAddr = (uint32_t)(&USART6->DR);
	DMA_InitStructure.DMA_Memory0BaseAddr = (uint32_t)send6_buf;
	DMA_InitStructure.DMA_DIR = DMA_DIR_MemoryToPeripheral;
	DMA_InitStructure.DMA_BufferSize = UART_TX_LEN;
	DMA_InitStructure.DMA_PeripheralInc = DMA_PeripheralInc_Disable;
	DMA_InitStructure.DMA_MemoryInc = DMA_MemoryInc_Enable;
	DMA_InitStructure.DMA_PeripheralDataSize = DMA_PeripheralDataSize_Byte;
	DMA_InitStructure.DMA_MemoryDataSize = DMA_MemoryDataSize_Byte;
	DMA_InitStructure.DMA_Mode = DMA_Mode_Circular;	
	DMA_InitStructure.DMA_FIFOMode = DMA_FIFOMode_Disable; 
	DMA_InitStructure.DMA_FIFOThreshold = DMA_FIFOThreshold_Full;	
	DMA_InitStructure.DMA_Priority = DMA_Priority_VeryHigh;
	DMA_InitStructure.DMA_MemoryBurst = DMA_MemoryBurst_Single;//存储器突发单次传输
	DMA_InitStructure.DMA_PeripheralBurst = DMA_PeripheralBurst_Single;//外设突发单次传输
	DMA_Init(DMA2_Stream7, &DMA_InitStructure);
	DMA_Cmd(DMA2_Stream7, DISABLE);
	DMA_ITConfig(DMA2_Stream7, DMA_IT_TC, ENABLE);				

	DMA_Cmd(DMA2_Stream1, DISABLE);
	DMA_DeInit(DMA2_Stream1);
	DMA_InitStructure.DMA_Channel = DMA_Channel_5;
	DMA_InitStructure.DMA_PeripheralBaseAddr = (uint32_t)(&USART6->DR);
	DMA_InitStructure.DMA_Memory0BaseAddr = (uint32_t)rece6_buf;
	DMA_InitStructure.DMA_DIR = DMA_DIR_PeripheralToMemory ;
	DMA_InitStructure.DMA_BufferSize = UART6_RX_LEN;
	DMA_InitStructure.DMA_PeripheralInc = DMA_PeripheralInc_Disable;
	DMA_InitStructure.DMA_MemoryInc = DMA_MemoryInc_Enable;
	DMA_InitStructure.DMA_PeripheralDataSize = DMA_PeripheralDataSize_Byte;
	DMA_InitStructure.DMA_MemoryDataSize = DMA_MemoryDataSize_Byte;
	DMA_InitStructure.DMA_Mode = DMA_Mode_Circular;
	DMA_InitStructure.DMA_FIFOMode = DMA_FIFOMode_Disable; 
	DMA_InitStructure.DMA_FIFOThreshold = DMA_FIFOThreshold_Full;	
	DMA_InitStructure.DMA_Priority = DMA_Priority_VeryHigh;
	DMA_InitStructure.DMA_MemoryBurst = DMA_MemoryBurst_Single;//存储器突发单次传输
	DMA_InitStructure.DMA_PeripheralBurst = DMA_PeripheralBurst_Single;//外设突发单次传输
	DMA_Init(DMA2_Stream1, &DMA_InitStructure);
	DMA_Cmd(DMA2_Stream1, ENABLE); 

	NVIC_InitStructure.NVIC_IRQChannel = DMA2_Stream7_IRQn;  
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 2;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 4;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStructure);	
}
void Uart6_Start_DMA_Tx(u16 size)
{
	DMA_SetCurrDataCounter(DMA2_Stream7,size);
	DMA_Cmd(DMA2_Stream7, ENABLE);
}



void  DMA1_Stream6_IRQHandler(void)//uart2的DMA的服务函数
{
    if(DMA_GetITStatus(DMA1_Stream6, DMA_IT_TCIF6))
    {
			DMA_ClearITPendingBit(DMA1_Stream6, DMA_IT_TCIF6);
			DMA_Cmd(DMA1_Stream6, DISABLE);
    }
}

void  DMA1_Stream3_IRQHandler(void)//uart3的DMA的服务函数
{
    if(DMA_GetITStatus(DMA1_Stream3, DMA_IT_TCIF3))
    {
			DMA_ClearITPendingBit(DMA1_Stream3, DMA_IT_TCIF3);
			DMA_Cmd(DMA1_Stream3, DISABLE);
    }
}
void  DMA1_Stream4_IRQHandler(void)//uart4的DMA的服务函数
{
    if(DMA_GetITStatus(DMA1_Stream4, DMA_IT_TCIF4))
    {
			USART_ITConfig(UART4, USART_IT_TC, ENABLE);

			DMA_ClearITPendingBit(DMA1_Stream4, DMA_IT_TCIF4);
			DMA_Cmd(DMA1_Stream4, DISABLE);
    }
}


void  DMA2_Stream1_IRQHandler(void)//uart6的DMA的服务函数
{
    if(DMA_GetITStatus(DMA2_Stream1, DMA_IT_TCIF1))
    {
			DMA_ClearITPendingBit(DMA2_Stream1, DMA_IT_TCIF1);
			DMA_Cmd(DMA2_Stream1, DISABLE);
    }
}

void  DMA2_Stream7_IRQHandler(void)//串口6发送DMA中断
{
	if(DMA_GetITStatus(DMA2_Stream7, DMA_IT_TCIF7))
	{
		DMA_ClearITPendingBit(DMA2_Stream7, DMA_IT_TCIF7);
		DMA_Cmd(DMA2_Stream7, DISABLE);
		send_ok = 1;
	}
}


















