#ifndef __LED_H
#define __LED_H
#include "sys.h"

//////////////////////////////////////////////////////////////////////////////////	 
//本程序只供学习使用，未经作者许可，不得用于其它任何用途
//ALIENTEK STM32F407开发板
//LED驱动代码	   
//正点原子@ALIENTEK
//技术论坛:www.openedv.com
//创建日期:2014/5/2
//版本：V1.0
//版权所有，盗版必究。
//Copyright(C) 广州市星翼电子科技有限公司 2014-2024
//All rights reserved									  
////////////////////////////////////////////////////////////////////////////////// 	

#define BEEP PAout(3)	// DS1
//LED端口定义
#define LED1 PBout(8)	// DS0
#define LED2 PBout(9)	// DS1
#define LED3 PEout(0)	// DS0
#define LED4 PEout(1)	// DS1	 

#define Police_LED PAout(8)	//警示灯端口

void LED_Init(void);//初始化	
void Police_led(u16 num);
#endif
