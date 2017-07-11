#ifndef _TIMER_H
#define _TIMER_H
#include "sys.h"

//叉车时的控制方向的输出口
#define IN1 PCout(4)  // 叉车行驶方向控制口1
#define IN2 PCout(5)	// 叉车行驶方向控制口2

//有驱动器的电机控制信号
//#define EN1 PBout(4)  // 电机1使能
//#define FR1 PBout(3)	// 电机1反向        
//#define BK1 PGout(15)	// 电机1刹车

//#define EN2 PGout(14) // 电机2使能
//#define FR2 PGout(13) // 电机2反向
//#define BK2 PGout(12) // 电机2刹车

//#define EN3 PBout(7)  // 电机3使能
//#define FR3 PBout(6)  // 电机3反向
//#define BK3 PBout(5)  // 电机3刹车

//#define EN4 PGout(11) // 电机4使能
//#define FR4 PGout(10) // 电机4反向
//#define BK4 PGout(9) 	// 电机4刹车


void Control_Init(void);																//电机控制信号端口初始化
void PWM_Init(TIM_TypeDef* TIMx,u16 x,u16 arr,u16 val); //PWM初始化函数
void PWM_val(TIM_TypeDef* TIMx,u16 x,u16 val);					//PWM占空比调节函数

#endif
