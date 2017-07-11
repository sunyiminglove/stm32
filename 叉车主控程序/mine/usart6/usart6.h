#ifndef __USART6_H
#define __USART6_H
#include "stdio.h"	
#include "stm32f4xx_conf.h"
#include "sys.h" 

void usart6_init(u32 bound);
extern u16 receive_ok;
extern u8 send_ok;
#endif


