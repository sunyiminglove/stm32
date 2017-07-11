#ifndef __DMA_H
#define	__DMA_H	   
#include "stm32f4xx.h"
#define UART_RX_LEN     250
#define UART_TX_LEN     250
#define UART6_RX_LEN    250
#define ADC1_DR_Addr   ((uint32_t)0x4001204C)
extern u8 u6sendflag;
extern u16 AD_Value[30][3];
extern double After_filter[3];//ADCµÄ¼Ä´æÆ÷
extern u8 rece_index,rece2_index,rece6_index,rece3_index;
extern u8 sendBuf[UART_RX_LEN],receBuf[UART_RX_LEN],*ps,*pr;
extern char rece_buf[UART_RX_LEN],send_buf[UART_RX_LEN],rece6_buf[UART6_RX_LEN];
extern u8  rece3_buf[UART6_RX_LEN];
extern u8  send3_buf[UART6_RX_LEN];

extern char  rece6_buf[UART6_RX_LEN];
extern char  send6_buf[UART6_RX_LEN];

void DMA_adc1_Init(void);
void DMA_Uart2_Init(void);
void DMA_Uart3_Init(void);
void DMA_Uart4_Init(void);
void DMA_Uart6_Init(void);
void Uart3_Start_DMA_Tx(u16 size);
void Uart4_Start_DMA_Tx(u16 size);
void Uart6_Start_DMA_Tx(u16 size);
#endif






























