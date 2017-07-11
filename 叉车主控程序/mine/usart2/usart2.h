#ifndef __USART2_H
#define __USART2_H
#include "stdio.h"	
#include "stm32f4xx_conf.h"
#include "sys.h" 

extern u16 keynumber;			//µÿ±Í÷µ
extern u8 BEEP_flag;

void usart2_init(u32 bound);

#endif


