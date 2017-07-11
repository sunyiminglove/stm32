#include "sys.h"
#include "dma.h"	
#include "uart4.h"	
#include "Modbus_slave.h"
////////////////////////////////////////////////////////////////////////////////// 	 
//���ʹ��ucos,����������ͷ�ļ�����.
#if SYSTEM_SUPPORT_OS
#include "includes.h"					//ucos ʹ��	  
#endif

//��ʼ��IO ����4
//bound:������
void uart4_init(u32 bound)
{
  //GPIO�˿�����
	GPIO_InitTypeDef GPIO_InitStructure;
	USART_InitTypeDef USART_InitStructure;
	NVIC_InitTypeDef NVIC_InitStructure;
	
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA,ENABLE); //ʹ��GPIOAʱ��
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_UART4,ENABLE);//ʹ��UART4ʱ��
 
	//����4��Ӧ���Ÿ���ӳ��
	GPIO_PinAFConfig(GPIOA,GPIO_PinSource0,GPIO_AF_UART4);
	GPIO_PinAFConfig(GPIOA,GPIO_PinSource1,GPIO_AF_UART4);

	//UART4�˿�����
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1; //GPIOA9��GPIOA10
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;//���ù���
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;	//�ٶ�50MHz
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP; //���츴�����
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP; //����
	GPIO_Init(GPIOA,&GPIO_InitStructure); //��ʼ��PA0��PA1
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
	GPIO_Init(GPIOA,&GPIO_InitStructure);	
	GPIO_ResetBits(GPIOA,GPIO_Pin_2);

  //UART4 ��ʼ������
	USART_InitStructure.USART_BaudRate = bound;									//����������
	USART_InitStructure.USART_WordLength = USART_WordLength_8b;	//�ֳ�Ϊ8λ���ݸ�ʽ
	USART_InitStructure.USART_StopBits = USART_StopBits_1;			//һ��ֹͣλ
	USART_InitStructure.USART_Parity = USART_Parity_No;					//����żУ��λ
	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;//��Ӳ������������
	USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;	//�շ�ģʽ
	USART_Init(UART4, &USART_InitStructure);										//��ʼ������1
	
	//Usart4 NVIC ����
	NVIC_InitStructure.NVIC_IRQChannel = UART4_IRQn;  
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 3;
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
  NVIC_Init(&NVIC_InitStructure);
	
	USART_ITConfig(UART4, USART_IT_IDLE, ENABLE);
	USART_Cmd(UART4, ENABLE);  									//ʹ�ܴ���4
	USART_ClearFlag(UART4, USART_FLAG_TC);
	USART_DMACmd(UART4, USART_DMAReq_Tx, ENABLE);
  USART_DMACmd(UART4, USART_DMAReq_Rx, ENABLE);
	
}



void UART4_IRQHandler(void)                
{
#if SYSTEM_SUPPORT_OS 	
	OSIntEnter();    
#endif
	if(USART_GetITStatus(UART4, USART_IT_IDLE) != RESET) 
	{
		DMA_Cmd(DMA1_Stream2,DISABLE);
        rece_index = UART4->SR; 
        rece_index = UART4->DR; 
        rece_index = UART_RX_LEN - DMA_GetCurrDataCounter(DMA1_Stream2); 
        DMA1_Stream2->NDTR = UART_RX_LEN;
		if(rece_index>0)
		{
			if(receBuf[0]==0x01||receBuf[0]==0x00)
			{
				AnalyzeRecieve();
				if(receBuf[0]==0x01)
				send_comm();
			}
		} 		
    DMA_Cmd(DMA1_Stream2, ENABLE);
	} 
	if(USART_GetITStatus(UART4, USART_IT_TC) != RESET)
	{
		GPIO_ResetBits(GPIOA,GPIO_Pin_2);
		NVIC_ClearPendingIRQ(UART4_IRQn);
		USART_ClearITPendingBit(UART4,USART_IT_TC);
	}
#if SYSTEM_SUPPORT_OS 	
	OSIntExit();  											 
#endif
} 


 



