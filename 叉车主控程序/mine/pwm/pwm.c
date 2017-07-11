#include "pwm.h"
#include "usart.h"
 
#define RRECISION 1000

u16 arr1,val1,val2;

//��������źŶ˿ڳ�ʼ��

void Control_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;

	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOC, ENABLE);
  //GPIOD3,4��ʼ������
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4 | GPIO_Pin_5;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;//��ͨ���ģʽ
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;//�������
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;//100MHz
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;//����
  GPIO_Init(GPIOC, &GPIO_InitStructure);//��ʼ��
	
	IN1=0;// �泵��ʻ������ƿ�1
	IN2=0;// �泵��ʻ������ƿ�2
	
//	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB|RCC_AHB1Periph_GPIOG, ENABLE);

//	//DJ1��DJ2�ĳ�ʼ������
//  //GPIOB3,4��ʼ������
//  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3 | GPIO_Pin_4;
//  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;//��ͨ���ģʽ
//  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;//�������
//  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;//100MHz
//  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;//����
//  GPIO_Init(GPIOB, &GPIO_InitStructure);//��ʼ��
//	
//	//GPIOG12,13,14,15��ʼ������
//  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12 | GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_15;
//  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;//��ͨ���ģʽ
//  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;//�������
//  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;//100MHz
//  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;	//����
//  GPIO_Init(GPIOG, &GPIO_InitStructure);				//��ʼ��
//	
//	GPIO_SetBits(GPIOB,GPIO_Pin_3 | GPIO_Pin_4);
//	GPIO_SetBits(GPIOG,GPIO_Pin_12 | GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_15);

//DJ3��DJ4�ĳ�ʼ������	
//  //GPIOB3,4��ʼ������
//  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5 | GPIO_Pin_6 | GPIO_Pin_7;
//  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;//��ͨ���ģʽ
//  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;//�������
//  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;//100MHz
//  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;//����
//  GPIO_Init(GPIOB, &GPIO_InitStructure);//��ʼ��
//	
//	//GPIOG9,10,11,12��ʼ������
//  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9 | GPIO_Pin_10 | GPIO_Pin_11;
//  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;//��ͨ���ģʽ
//  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;//�������
//  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;//100MHz
//  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;	//����
//  GPIO_Init(GPIOG, &GPIO_InitStructure);				//��ʼ��
//	
//	GPIO_SetBits(GPIOB,GPIO_Pin_5 | GPIO_Pin_6 | GPIO_Pin_7);
//	GPIO_SetBits(GPIOG,GPIO_Pin_9 | GPIO_Pin_10 | GPIO_Pin_11);
	
}


//��������:	PWM��ʼ������
//TIMx:			����TIM1��TIM8��TIM2��TIM3��TIM4��TIM5��TIM9��TIM10��TIM11��TIM12��TIM13��TIM14
//x:				��TIM2~TIM5��ȡֵ1~4����TIM1��TIM8��ȡֵ1~7
//1��8��9��10��11����AHB2����������AHB1��
//arr:			PWMƵ��
//val:			PWMռ�ձ�
void PWM_Init(TIM_TypeDef* TIMx,u16 x,u16 arr,u16 val)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	TIM_OCInitTypeDef  TIM_OCInitStructure;
	
	arr1=(u16)(1000000/arr-1);
	val1=(u16)(((arr1+1)*val)/RRECISION);
	
	
	if(TIMx==TIM1)
	{
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM1,ENABLE);  	//TIM2ʱ��ʹ��    
		RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE); 	//ʹ��PORTFʱ��	
		
		switch(x)
			{
				case 1:
				{
					GPIO_PinAFConfig(GPIOA,GPIO_PinSource8,GPIO_AF_TIM1);
					GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8;           //GPIOF9
					GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;        //���ù���
					GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;	//�ٶ�100MHz
					GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;      //���츴�����
					GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;        //����
					GPIO_Init(GPIOA,&GPIO_InitStructure);              //��ʼ��PF9
				}break;
				case 2:
				{
					GPIO_PinAFConfig(GPIOA,GPIO_PinSource9,GPIO_AF_TIM1);
					GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9;           //GPIOF9
					GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;        //���ù���
					GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;	//�ٶ�100MHz
					GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;      //���츴�����
					GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;        //����
					GPIO_Init(GPIOA,&GPIO_InitStructure);              //��ʼ��PF9
				}break;
				case 3:
				{
					GPIO_PinAFConfig(GPIOA,GPIO_PinSource10,GPIO_AF_TIM1);
					GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10;           //GPIOF9
					GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;        //���ù���
					GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;	//�ٶ�100MHz
					GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;      //���츴�����
					GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;        //����
					GPIO_Init(GPIOA,&GPIO_InitStructure);              //��ʼ��PF9
				}break;
				case 4:
				{
					GPIO_PinAFConfig(GPIOA,GPIO_PinSource11,GPIO_AF_TIM1);
					GPIO_InitStructure.GPIO_Pin = GPIO_Pin_11;           //GPIOF9
					GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;        //���ù���
					GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;	//�ٶ�100MHz
					GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;      //���츴�����
					GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;        //����
					GPIO_Init(GPIOA,&GPIO_InitStructure);              //��ʼ��PF9
				}break;
			}
	}
	
	else if(TIMx==TIM2)
	{
		RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2,ENABLE);  		//TIM2ʱ��ʹ��    
		RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE); 	//ʹ��PORTFʱ��	
		
		switch(x)
			{
				case 1:
				{
					GPIO_PinAFConfig(GPIOA,GPIO_PinSource0,GPIO_AF_TIM2);
					GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;           //GPIOA0
					GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;        //���ù���
					GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;	//�ٶ�100MHz
					GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;      //���츴�����
					GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;        //����
					GPIO_Init(GPIOA,&GPIO_InitStructure);               //��ʼ��PA0
				}break;
				case 2:
				{
					GPIO_PinAFConfig(GPIOA,GPIO_PinSource1,GPIO_AF_TIM2);
					GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1;           //GPIOA1
					GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;        //���ù���
					GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;	//�ٶ�100MHz
					GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;      //���츴�����
					GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;        //����
					GPIO_Init(GPIOA,&GPIO_InitStructure);               //��ʼ��PA1
				}break;
				case 3:
				{
					GPIO_PinAFConfig(GPIOA,GPIO_PinSource2,GPIO_AF_TIM2);
					GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2;           //GPIOA2
					GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;        //���ù���
					GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;	//�ٶ�100MHz
					GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;      //���츴�����
					GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;        //����
					GPIO_Init(GPIOA,&GPIO_InitStructure);               //��ʼ��PA2
				}break;
				case 4:
				{
					GPIO_PinAFConfig(GPIOA,GPIO_PinSource3,GPIO_AF_TIM2);
					GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3;           //GPIOA3
					GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;        //���ù���
					GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;	//�ٶ�100MHz
					GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;      //���츴�����
					GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;        //����
					GPIO_Init(GPIOA,&GPIO_InitStructure);               //��ʼ��PA3
				}break;
			}
	}	
	else if(TIMx==TIM3)
	{
		RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3,ENABLE);  	//TIM2ʱ��ʹ��    
		RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA|RCC_AHB1Periph_GPIOB, ENABLE); 	//ʹ��PORTFʱ��	
		
		switch(x)
			{
				case 1:
				{
					GPIO_PinAFConfig(GPIOA,GPIO_PinSource6,GPIO_AF_TIM3);
					GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6;           //GPIOA6
					GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;        //���ù���
					GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;	//�ٶ�100MHz
					GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;      //���츴�����
					GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;        //����
					GPIO_Init(GPIOA,&GPIO_InitStructure);              	//��ʼ��PA6
				}break;
				case 2:
				{
					GPIO_PinAFConfig(GPIOA,GPIO_PinSource7,GPIO_AF_TIM3);
					GPIO_InitStructure.GPIO_Pin = GPIO_Pin_7;           //GPIOA7
					GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;        //���ù���
					GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;	//�ٶ�100MHz
					GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;      //���츴�����
					GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;        //����
					GPIO_Init(GPIOA,&GPIO_InitStructure);               //��ʼ��PA7
				}break; 
				case 3:
				{
					GPIO_PinAFConfig(GPIOB,GPIO_PinSource0,GPIO_AF_TIM3);
					GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;           //GPIOB0
					GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;        //���ù���
					GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;	//�ٶ�100MHz
					GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;      //���츴�����
					GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;        //����
					GPIO_Init(GPIOB,&GPIO_InitStructure);               //��ʼ��PB0
				}break;
				case 4:
				{
					GPIO_PinAFConfig(GPIOB,GPIO_PinSource1,GPIO_AF_TIM3);
					GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1;           //GPIOB1
					GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;        //���ù���
					GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;	//�ٶ�100MHz
					GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;      //���츴�����
					GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;        //����
					GPIO_Init(GPIOB,&GPIO_InitStructure);               //��ʼ��PB1
				}break;
			}
	}
	else if(TIMx==TIM4)
	{	
		RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4,ENABLE);  	//TIM2ʱ��ʹ��    
		RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE); 	//ʹ��PORTFʱ��	
		
		switch(x)
			{
				case 1:
				{
					GPIO_PinAFConfig(GPIOD,GPIO_PinSource12,GPIO_AF_TIM4);  //GPIOD12����Ϊ��ʱ��4
					GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12;           		//GPIOD12
					GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;        		//���ù���
					GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;			//�ٶ�100MHz
					GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;      		//���츴�����
					GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;        		//����
					GPIO_Init(GPIOD,&GPIO_InitStructure);               		//��ʼ��PD12
				}break;
				case 2:
				{
					GPIO_PinAFConfig(GPIOD,GPIO_PinSource13,GPIO_AF_TIM4);  //GPIOD13����Ϊ��ʱ��4
					GPIO_InitStructure.GPIO_Pin = GPIO_Pin_13;           		//GPIOD13
					GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;        		//���ù���
					GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;			//�ٶ�100MHz
					GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;      		//���츴�����
					GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;        		//����
					GPIO_Init(GPIOD,&GPIO_InitStructure);             		  //��ʼ��PD13
				}break;
				case 3:
				{
					GPIO_PinAFConfig(GPIOD,GPIO_PinSource14,GPIO_AF_TIM4);  //GPIOD14����Ϊ��ʱ��4
					GPIO_InitStructure.GPIO_Pin = GPIO_Pin_14;           		//GPIOD14
					GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;        		//���ù���
					GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;			//�ٶ�100MHz
					GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;      		//���츴�����
					GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;        		//����
					GPIO_Init(GPIOD,&GPIO_InitStructure);              			//��ʼ��PD14
				}break;
				case 4:
				{
					GPIO_PinAFConfig(GPIOD,GPIO_PinSource15,GPIO_AF_TIM4); 	//GPIOD15����Ϊ��ʱ��4
					GPIO_InitStructure.GPIO_Pin = GPIO_Pin_15;           		//GPIOD15
					GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;        		//���ù���
					GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;			//�ٶ�100MHz
					GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;      		//���츴�����
					GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;        		//����
					GPIO_Init(GPIOD,&GPIO_InitStructure);               		//��ʼ��PD15
				}break;
			}
	}
	else if(TIMx==TIM5)
	{
		RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM5,ENABLE);  	//TIM2ʱ��ʹ��    
		RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE); 	//ʹ��PORTFʱ��	
		
		switch(x)
			{
				case 1:
				{
					GPIO_PinAFConfig(GPIOA,GPIO_PinSource0,GPIO_AF_TIM5);
					GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;           //GPIOF9
					GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;        //���ù���
					GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;	//�ٶ�100MHz
					GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;      //���츴�����
					GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;        //����
					GPIO_Init(GPIOA,&GPIO_InitStructure);              //��ʼ��PF9
				}break;
				case 2:
				{
					GPIO_PinAFConfig(GPIOA,GPIO_PinSource1,GPIO_AF_TIM5);
					GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1;           //GPIOF9
					GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;        //���ù���
					GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;	//�ٶ�100MHz
					GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;      //���츴�����
					GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;        //����
					GPIO_Init(GPIOA,&GPIO_InitStructure);              //��ʼ��PF9
				}break;
				case 3:
				{
					GPIO_PinAFConfig(GPIOA,GPIO_PinSource2,GPIO_AF_TIM5);
					GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2;           //GPIOF9
					GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;        //���ù���
					GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;	//�ٶ�100MHz
					GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;      //���츴�����
					GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;        //����
					GPIO_Init(GPIOA,&GPIO_InitStructure);              //��ʼ��PF9
				}break;
				case 4:
				{
					GPIO_PinAFConfig(GPIOA,GPIO_PinSource3,GPIO_AF_TIM5);
					GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3;           //GPIOF9
					GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;        //���ù���
					GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;	//�ٶ�100MHz
					GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;      //���츴�����
					GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;        //����
					GPIO_Init(GPIOA,&GPIO_InitStructure);              //��ʼ��PF9
				}break;
			}
	}
	else if(TIMx==TIM8)
	{
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM8,ENABLE);  	//TIM2ʱ��ʹ��    
		RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOC, ENABLE); 	//ʹ��PORTFʱ��	
		
		switch(x)
			{
				case 1:
				{
					GPIO_PinAFConfig(GPIOC,GPIO_PinSource6,GPIO_AF_TIM8);
					GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6;           //GPIOF9
					GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;        //���ù���
					GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;	//�ٶ�100MHz
					GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;      //���츴�����
					GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;        //����
					GPIO_Init(GPIOC,&GPIO_InitStructure);              //��ʼ��PF9
				}break;
				case 2:
				{
					GPIO_PinAFConfig(GPIOC,GPIO_PinSource7,GPIO_AF_TIM8);
					GPIO_InitStructure.GPIO_Pin = GPIO_Pin_7;           //GPIOF9
					GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;        //���ù���
					GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;	//�ٶ�100MHz
					GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;      //���츴�����
					GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;        //����
					GPIO_Init(GPIOC,&GPIO_InitStructure);              //��ʼ��PF9
				}break;
				case 3:
				{
					GPIO_PinAFConfig(GPIOC,GPIO_PinSource8,GPIO_AF_TIM8);
					GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8;           //GPIOF9
					GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;        //���ù���
					GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;	//�ٶ�100MHz
					GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;      //���츴�����
					GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;        //����
					GPIO_Init(GPIOC,&GPIO_InitStructure);              //��ʼ��PF9
				}break;
				case 4:
				{
					GPIO_PinAFConfig(GPIOC,GPIO_PinSource9,GPIO_AF_TIM8);
					GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9;           //GPIOF9
					GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;        //���ù���
					GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;	//�ٶ�100MHz
					GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;      //���츴�����
					GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;        //����
					GPIO_Init(GPIOC,&GPIO_InitStructure);              //��ʼ��PF9
				}break;
			}
	}
	
	else if(TIMx==TIM9)
	{
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM9,ENABLE);  	//TIM2ʱ��ʹ��    
		RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOE, ENABLE); 	//ʹ��PORTFʱ��	
		
		switch(x)
			{
				case 1:
				{
					GPIO_PinAFConfig(GPIOE,GPIO_PinSource5,GPIO_AF_TIM9);
					GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5;           //GPIOF9
					GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;        //���ù���
					GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;	//�ٶ�100MHz
					GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;      //���츴�����
					GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;        //����
					GPIO_Init(GPIOE,&GPIO_InitStructure);              //��ʼ��PF9
				}break;
				case 2:
				{
					GPIO_PinAFConfig(GPIOE,GPIO_PinSource6,GPIO_AF_TIM9);
					GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6;           //GPIOF9
					GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;        //���ù���
					GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;	//�ٶ�100MHz
					GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;      //���츴�����
					GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;        //����
					GPIO_Init(GPIOE,&GPIO_InitStructure);              //��ʼ��PF9
				}break;
			}
	}
	else if(TIMx==TIM10)
	{
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM10,ENABLE);  	//TIM2ʱ��ʹ��    
		RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE); 	//ʹ��PORTFʱ��	
		
		switch(x)
			{
				case 1:
				{
					GPIO_PinAFConfig(GPIOB,GPIO_PinSource8,GPIO_AF_TIM10);
					GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8;           //GPIOF9
					GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;        //���ù���
					GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;	//�ٶ�100MHz
					GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;      //���츴�����
					GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;        //����
					GPIO_Init(GPIOB,&GPIO_InitStructure);              //��ʼ��PF9
				}break;
			}
	}
	else if(TIMx==TIM11)
	{
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM11,ENABLE);  	//TIM2ʱ��ʹ��    
		RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE); 	//ʹ��PORTFʱ��	
		
		switch(x)
			{
				case 1:
				{
					GPIO_PinAFConfig(GPIOB,GPIO_PinSource9,GPIO_AF_TIM11);
					GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9;           //GPIOF9
					GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;        //���ù���
					GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;	//�ٶ�100MHz
					GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;      //���츴�����
					GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;        //����
					GPIO_Init(GPIOB,&GPIO_InitStructure);              //��ʼ��PF9
				}break;
			}
	}
	else if(TIMx==TIM12)
	{
		RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM12,ENABLE);  	//TIM2ʱ��ʹ��    
		RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE); 	//ʹ��PORTFʱ��	
		
		switch(x)
			{
				case 1:
				{
					GPIO_PinAFConfig(GPIOB,GPIO_PinSource14,GPIO_AF_TIM12);
					GPIO_InitStructure.GPIO_Pin = GPIO_Pin_14;           //GPIOF9
					GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;        //���ù���
					GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;	//�ٶ�100MHz
					GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;      //���츴�����
					GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;        //����
					GPIO_Init(GPIOB,&GPIO_InitStructure);              //��ʼ��PF9
				}break;
				case 2:
				{
					GPIO_PinAFConfig(GPIOB,GPIO_PinSource15,GPIO_AF_TIM12);
					GPIO_InitStructure.GPIO_Pin = GPIO_Pin_15;           //GPIOF9
					GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;        //���ù���
					GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;	//�ٶ�100MHz
					GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;      //���츴�����
					GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;        //����
					GPIO_Init(GPIOB,&GPIO_InitStructure);              //��ʼ��PF9
				}break;
			}
	}
	else if(TIMx==TIM13)
	{
		RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM13,ENABLE);  	//TIM2ʱ��ʹ��    
		RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE); 	//ʹ��PORTFʱ��	
		
		switch(x)
			{
				case 1:
				{
					GPIO_PinAFConfig(GPIOA,GPIO_PinSource6,GPIO_AF_TIM13);
					GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6;           //GPIOF9
					GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;        //���ù���
					GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;	//�ٶ�100MHz
					GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;      //���츴�����
					GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;        //����
					GPIO_Init(GPIOA,&GPIO_InitStructure);              //��ʼ��PF9
				}break;
			}
	}
	else if(TIMx==TIM14)
	{
		RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM14,ENABLE);  	//TIM2ʱ��ʹ��    
		RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE); 	//ʹ��PORTFʱ��	
		
		switch(x)
			{
				case 1:
				{
					GPIO_PinAFConfig(GPIOA,GPIO_PinSource7,GPIO_AF_TIM14);
					GPIO_InitStructure.GPIO_Pin = GPIO_Pin_7;           //GPIOF9
					GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;        //���ù���
					GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;	//�ٶ�100MHz
					GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;      //���츴�����
					GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;        //����
					GPIO_Init(GPIOA,&GPIO_InitStructure);              //��ʼ��PF9
				}break;
			}
	}
	
	
	
	TIM_TimeBaseStructure.TIM_Period=arr1;   											//�Զ���װ��ֵ
	TIM_TimeBaseStructure.TIM_Prescaler=83;  											//��ʱ����Ƶ
	TIM_TimeBaseStructure.TIM_CounterMode=TIM_CounterMode_Up; 		//���ϼ���ģʽ
	TIM_TimeBaseStructure.TIM_ClockDivision=TIM_CKD_DIV1; 
	
	TIM_TimeBaseInit(TIMx,&TIM_TimeBaseStructure);								//��ʼ����ʱ��TIMx
	
	//��ʼ��TIMx Channex PWMģʽ	 
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1; 						//ѡ��ʱ��ģʽ:TIM�����ȵ���ģʽ2
 	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable; //�Ƚ����ʹ��
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High; 		//�������:TIM����Ƚϼ��Ը�

	switch(x)
			{
				case 1:
				{
					TIM_OC1Init(TIMx, &TIM_OCInitStructure);  //����Tָ���Ĳ�����ʼ������TIMx OC1
					TIM_OC1PreloadConfig(TIMx, TIM_OCPreload_Enable);  //ʹ��TIMx��CCR1�ϵ�Ԥװ�ؼĴ���		 
					TIM_ARRPreloadConfig(TIMx,ENABLE);//ARPEʹ�� 			
					TIM_Cmd(TIMx, ENABLE);  //ʹ��TIMx			
					TIM_SetCompare1(TIMx,val1);//ռ�ձȳ�ʼ��
				}break;
				case 2:
				{
					TIM_OC2Init(TIMx, &TIM_OCInitStructure);  //����Tָ���Ĳ�����ʼ������TIM1 4OC1
					TIM_OC2PreloadConfig(TIMx, TIM_OCPreload_Enable);  //ʹ��TIM14��CCR1�ϵ�Ԥװ�ؼĴ���		 
					TIM_ARRPreloadConfig(TIMx,ENABLE);//ARPEʹ�� 			
					TIM_Cmd(TIMx, ENABLE);  //ʹ��TIMx				
					TIM_SetCompare2(TIMx,val1);
				}break;
				case 3:
				{
					TIM_OC3Init(TIMx, &TIM_OCInitStructure);  //����Tָ���Ĳ�����ʼ������TIM1 4OC1
					TIM_OC3PreloadConfig(TIMx, TIM_OCPreload_Enable);  //ʹ��TIM14��CCR1�ϵ�Ԥװ�ؼĴ���		 
					TIM_ARRPreloadConfig(TIMx,ENABLE);//ARPEʹ�� 			
					TIM_Cmd(TIMx, ENABLE);  //ʹ��TIMx				
					TIM_SetCompare3(TIMx,val1);
				}break;
				case 4:
				{
					TIM_OC4Init(TIMx, &TIM_OCInitStructure);  //����Tָ���Ĳ�����ʼ������TIM1 4OC1
					TIM_OC4PreloadConfig(TIMx, TIM_OCPreload_Enable);  //ʹ��TIM14��CCR1�ϵ�Ԥװ�ؼĴ���		 
					TIM_ARRPreloadConfig(TIMx,ENABLE);//ARPEʹ�� 			
					TIM_Cmd(TIMx, ENABLE);  //ʹ��TIMx			
					TIM_SetCompare4(TIMx,val1);
				}break;
			}
}

//��������:	PWMռ�ձȵ��ں���
//TIMx:			����TIM1��TIM8��TIM2��TIM3��TIM4��TIM5��TIM9��TIM10��TIM11��TIM12��TIM13��TIM14
//x:				��TIM2~TIM5��ȡֵ1~4����TIM1��TIM8��ȡֵ1~7
//val:			PWMռ�ձ�
void PWM_val(TIM_TypeDef* TIMx,u16 x,u16 val)
{
	
	val2=(u16)(((arr1+1)*val)/RRECISION);
	switch(x)
	{
		case 1:
			TIM_SetCompare1(TIMx,val2);break;
		case 2:
			TIM_SetCompare2(TIMx,val2);break;
		case 3:
			TIM_SetCompare3(TIMx,val2);break;
		case 4:
			TIM_SetCompare4(TIMx,val2);break;
	}
}

