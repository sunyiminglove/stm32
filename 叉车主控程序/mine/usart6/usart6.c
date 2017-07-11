#include "sys.h"
#include "dma.h"	
#include "usart6.h"	
#include "Modbus_slave.h"
////////////////////////////////////////////////////////////////////////////////// 	 
//���ʹ��ucos,����������ͷ�ļ�����.
#if SYSTEM_SUPPORT_OS
#include "includes.h"					//ucos ʹ��	  
#endif
u16 receive_ok = 0;
u8 send_ok = 0;

//��ʼ��IO ����4
//bound:������
void usart6_init(u32 bound)
{
	NVIC_InitTypeDef NVIC_InitStructure;
	
	GPIO_InitTypeDef GPIO_InitStructure;
	USART_InitTypeDef USART_InitStructure;
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOC,ENABLE); 
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART6,ENABLE);
	
	GPIO_PinAFConfig(GPIOC,GPIO_PinSource6,GPIO_AF_USART6);
	GPIO_PinAFConfig(GPIOC,GPIO_PinSource7,GPIO_AF_USART6);
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6|GPIO_Pin_7;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
	GPIO_Init(GPIOC,&GPIO_InitStructure);
	
	USART_InitStructure.USART_BaudRate            = bound  ;
	USART_InitStructure.USART_WordLength          = USART_WordLength_8b;
	USART_InitStructure.USART_StopBits            = USART_StopBits_1;
	USART_InitStructure.USART_Parity              = USART_Parity_No ;
	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
	USART_InitStructure.USART_Mode                = USART_Mode_Rx | USART_Mode_Tx;
	USART_Init(USART6, &USART_InitStructure);
	USART_ITConfig(USART6, USART_IT_IDLE, ENABLE);	
	USART_Cmd(USART6, ENABLE);  
	USART_ClearFlag(USART6, USART_FLAG_TC);
	USART_DMACmd(USART6, USART_DMAReq_Rx, ENABLE);
	USART_DMACmd(USART6, USART_DMAReq_Tx, ENABLE);//ע�͵�������дu6_printf��������
	
	NVIC_InitStructure.NVIC_IRQChannel = USART6_IRQn;  
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 2;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 2;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStructure);
}


void USART6_IRQHandler(void)             
{
	#if SYSTEM_SUPPORT_OS 	
	OSIntEnter();    
	#endif
	if(USART_GetITStatus(USART6, USART_IT_IDLE) != RESET) 
	{
		DMA_Cmd(DMA2_Stream1,DISABLE);
		rece6_index = USART6->SR;
		rece6_index = USART6->DR; //���IDLE��־
		rece6_index = UART6_RX_LEN - DMA_GetCurrDataCounter(DMA2_Stream1); 
		DMA2_Stream1->NDTR = UART6_RX_LEN;
		receive_ok = 1;
	} 
	#if SYSTEM_SUPPORT_OS 	
	OSIntExit();  											 
	#endif
} 

