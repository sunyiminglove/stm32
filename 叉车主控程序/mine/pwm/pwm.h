#ifndef _TIMER_H
#define _TIMER_H
#include "sys.h"

//�泵ʱ�Ŀ��Ʒ���������
#define IN1 PCout(4)  // �泵��ʻ������ƿ�1
#define IN2 PCout(5)	// �泵��ʻ������ƿ�2

//���������ĵ�������ź�
//#define EN1 PBout(4)  // ���1ʹ��
//#define FR1 PBout(3)	// ���1����        
//#define BK1 PGout(15)	// ���1ɲ��

//#define EN2 PGout(14) // ���2ʹ��
//#define FR2 PGout(13) // ���2����
//#define BK2 PGout(12) // ���2ɲ��

//#define EN3 PBout(7)  // ���3ʹ��
//#define FR3 PBout(6)  // ���3����
//#define BK3 PBout(5)  // ���3ɲ��

//#define EN4 PGout(11) // ���4ʹ��
//#define FR4 PGout(10) // ���4����
//#define BK4 PGout(9) 	// ���4ɲ��


void Control_Init(void);																//��������źŶ˿ڳ�ʼ��
void PWM_Init(TIM_TypeDef* TIMx,u16 x,u16 arr,u16 val); //PWM��ʼ������
void PWM_val(TIM_TypeDef* TIMx,u16 x,u16 val);					//PWMռ�ձȵ��ں���

#endif
