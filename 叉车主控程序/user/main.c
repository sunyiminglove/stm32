#include "sys.h"
#include "can.h"
#include "adc.h"
#include "dma.h"
#include "usart.h"
#include "usart2.h"
#include "usart3.h"
#include "uart4.h"
#include "usart6.h"
#include "Modbus_slave.h"
#include "Modbus_slave_170M.h"
#include "w25qxx.h"
#include "xf.h"
#include "delay.h"
#include "pwm.h"
#include "CDHdata.h"
#include "pid.h"
#include "led.h"
#include "control.h" 
#include "baohu.h" 
#include "includes.h"
#include "route.h"
#include "wdg.h"
#include "math.h" 
#include "read.h"

#define SPEEKTIME 0
/*************���������忪ʼ************/
#if 1
//�������ȼ�
#define START_TASK_PRIO		3
//�����ջ��С	
#define START_STK_SIZE 		128
//������ƿ�
OS_TCB StartTaskTCB;
//�����ջ	
CPU_STK START_TASK_STK[START_STK_SIZE];
//������
void start_task(void *p_arg);

//�������ȼ�
#define Control_TASK_PRIO		4
//�����ջ��С	
#define Control_STK_SIZE 		128
//������ƿ�
OS_TCB Control_TaskTCB;
//�����ջ	
CPU_STK Control_TASK_STK[Control_STK_SIZE];
//������
void Control_task(void *p_arg);

//�������ȼ�
#define Automode_TASK_PRIO		5
//�����ջ��С	
#define Automode_STK_SIZE 		128
//������ƿ�
OS_TCB Automode_TaskTCB;
//�����ջ	
CPU_STK Automode_TASK_STK[Automode_STK_SIZE];
//������
void Automode_task(void *p_arg);

//�������ȼ�
#define Task1_TASK_PRIO		6
//�����ջ��С	
#define Task1_STK_SIZE 		128
//������ƿ�
OS_TCB Task1_TaskTCB;
//�����ջ	
CPU_STK Task1_TASK_STK[Task1_STK_SIZE];
void Task1_task(void *p_arg);

//�������ȼ�
#define Task4_TASK_PRIO		7
//�����ջ��С	
#define Task4_STK_SIZE 		128
//������ƿ�
OS_TCB Task4_TaskTCB;
//�����ջ	
CPU_STK Task4_TASK_STK[Task4_STK_SIZE];
//������
void Task4_task(void *p_arg);

//�������ȼ�
#define Cansend_TASK_PRIO		8
//�����ջ��С	
#define Cansend_STK_SIZE 		128
//������ƿ�
OS_TCB Cansend_TaskTCB;
//�����ջ	
CPU_STK Cansend_TASK_STK[Cansend_STK_SIZE];
//������
void Cansend_task(void *p_arg);

//�������ȼ�
 #define RunLED_TASK_PRIO		9
//�����ջ��С	
#define RunLED_STK_SIZE 		128
//������ƿ�
OS_TCB RunLED_TaskTCB;
//�����ջ	
CPU_STK RunLED_TASK_STK[RunLED_STK_SIZE];
//������
void RunLED_task(void *p_arg);

//�������ȼ�
#define RFID_TASK_PRIO		5
//�����ջ��С	
#define RFID_STK_SIZE 		128
//������ƿ�
OS_TCB RFID_TaskTCB;
//�����ջ	
CPU_STK RFID_TASK_STK[RFID_STK_SIZE];
//������
void RFID_task(void *p_arg);

//�������ȼ�
#define YAOKONG_TASK_PRIO		10
//�����ջ��С	
#define YAOKONG_STK_SIZE 		128
//������ƿ�
OS_TCB YAOKONG_TaskTCB;
//�����ջ	
CPU_STK YAOKONG_TASK_STK[YAOKONG_STK_SIZE];
//������
void YAOKONG_task(void *p_arg);

//�������ȼ�
#define Task5_TASK_PRIO		11
//�����ջ��С	
#define Task5_STK_SIZE 		128
//������ƿ�
OS_TCB Task5_TaskTCB;
//�����ջ	
CPU_STK Task5_TASK_STK[Task5_STK_SIZE];
//������
void Task5_task(void *p_arg);

//�������ȼ�
#define Task6_TASK_PRIO		12
//�����ջ��С	
#define Task6_STK_SIZE 		128
//������ƿ�
OS_TCB Task6_TaskTCB;
//�����ջ	
CPU_STK Task6_TASK_STK[Task6_STK_SIZE];
//������
void Task6_task(void *p_arg);

//�������ȼ�
#define Task7_TASK_PRIO		12
//�����ջ��С	
#define Task7_STK_SIZE 		128
//������ƿ�
OS_TCB Task7_TaskTCB;
//�����ջ	
CPU_STK Task7_TASK_STK[Task7_STK_SIZE];
//������
void Task7_task(void *p_arg);

//�������ȼ�
#define Task8_TASK_PRIO		12
//�����ջ��С	
#define Task8_STK_SIZE 		128
//������ƿ�
OS_TCB Task8_TaskTCB;
//�����ջ	
CPU_STK Task8_TASK_STK[Task8_STK_SIZE];
//������
void Task8_task(void *p_arg);

//�������ȼ�
#define Task9_TASK_PRIO		12
//�����ջ��С	
#define Task9_STK_SIZE 		128
//������ƿ�
OS_TCB Task9_TaskTCB;
//�����ջ	
CPU_STK Task9_TASK_STK[Task9_STK_SIZE];
//������
void Task9_task(void *p_arg);

//�������ȼ�
#define Task10_TASK_PRIO		12
//�����ջ��С	
#define Task10_STK_SIZE 		128
//������ƿ�
OS_TCB Task10_TaskTCB;
//�����ջ	
CPU_STK Task10_TASK_STK[Task10_STK_SIZE];
//������
void Task10_task(void *p_arg);

//�������ȼ�
#define Task11_TASK_PRIO		12
//�����ջ��С	
#define Task11_STK_SIZE 		128
//������ƿ�
OS_TCB Task11_TaskTCB;
//�����ջ	
CPU_STK Task11_TASK_STK[Task11_STK_SIZE];
//������
void Task11_task(void *p_arg);


//�������ȼ�
#define Task12_TASK_PRIO		13
//�����ջ��С	
#define Task12_STK_SIZE 		128
//������ƿ�
OS_TCB Task12_TaskTCB;
//�����ջ	
CPU_STK Task12_TASK_STK[Task12_STK_SIZE];
//������
void Task12_task(void *p_arg);


//�������ȼ�
#define Task13_TASK_PRIO		14
//�����ջ��С	
#define Task13_STK_SIZE 		128
//������ƿ�
OS_TCB Task13_TaskTCB;
//�����ջ	
CPU_STK Task13_TASK_STK[Task13_STK_SIZE];
//������
void Task13_task(void *p_arg);




//�������ȼ�
#define Task15_TASK_PRIO		15
//�����ջ��С	
#define Task15_STK_SIZE 		128
//������ƿ�
OS_TCB Task15_TaskTCB;
//�����ջ	
CPU_STK Task15_TASK_STK[Task15_STK_SIZE];
//������
void Task15_task(void *p_arg);

#endif
/*************�������������************/
/*********���еײ���ƺ������忪ʼ********/

u8 lastscreenNum=0;

#if 1
void jiejin()
{
	JJB=0;
	osdelay_ms(100);
}
void qianjin()
{
	JJB=0;
	osdelay_ms(500);
	IN1=1;
	IN2=0;
}
void houtui()
{
	JJB=0;
	osdelay_ms(500);
	IN1=0;
	IN2=1;
}
void tingzhi()
{
	JJB=1;
	osdelay_ms(500);
	IN1=0;
	IN2=0;
		//����״̬
	HmiTaskState = 4;
}

u8 Bi_Zhang_flag=0;
void bzqianjin()
{
	IN1=1;
	IN2=0;
	Bi_Zhang_flag=0;
}
void bzhoutui()
{
	IN1=0;
	IN2=1;
	Bi_Zhang_flag=0;
}
void bztingzhi()
{
	IN1=0;
	IN2=0;
	Bi_Zhang_flag=1;
}

#endif
/*********���еײ���ƺ����������********/
/*********����ȫ�ֲ������忪ʼ************/
#if 1

u8 Chu_Gui_dir=0;//ǰ������ĳ��췽���־0������2������߳���1�����ұ߳���
u16 speed=0,speed_ture=0;
u8 Police_flag=0;//��ʾ�Ƶ���˸����رձ�־	0������˸1���ر���˸
u8 QBZ_Yflag=0,QBZ_Jflag=0;//ǰ����(Զ����)������־	0������	1���ر�
u8 HBZ_flag=0;				//����Ͽ�����־		0������	1���ر�
u8 Mode_flag = 0;			//1:�Զ�����ģʽ 0���ֶ�����ģʽ
u8 last_flag=0;
u8 FX_flag=1;					//1:ǰ��	2:������	3:������ 4:���� 5:����
u8 QD_flag=0;					//������־ 0:ֹͣ 1:����
u8 road_mode=0;
u8 FC_flag=2;					//0:�зֲ� 1:��ֲ� 2���ҷֲ�
u8 tz_flag=0,qj_flag=0,htz_flag=0,hty_flag=0;//�ж���ʻ�����ֹͣ���ı�־λ�����Զ��������ã�
u16 Xuan_Zhuang_Ci_Shu = 1;

u16 CDH12_data=0,lastCDH12_data=0;//ǰ�ŵ���ԭʼ����ֵ�Լ��ϴε�ԭʼ����ֵ�������ж�ͻ��Ĵ�����
u8 CDH3_data=0,lastCDH3_data=0,CDH4_data=0,CDH5_data=0,lastCDH4_data=0,lastCDH5_data=0;//��ŵ���ԭʼ����ֵ�Լ��ϴε�ԭʼ����ֵ�������ж�ͻ��Ĵ�����
//3:ǰ��4:��,5:��
u8 ture_numF=0,ture_numL=0,ture_numR=0;

u16 CDH12_num=0,Last_CDH12_num=16;			//16λ�ŵ�������
u8 CDH1_num=0,CDH2_num=0,CDH3_num=0;//�ŵ�������

int deg=0;						//��ǰ����Ҫ��ĽǶ�
u16 keynumber=0;			//�ر�ֵ�Ĵ���
u16 WriteBuffer[1000];//flash��д��Ĵ���
u16 ReadBuffer[1000]; //flash�Ķ����Ĵ���
double ADC_POWER=0.0;	//�����ɼ�
u16 time=0;						//��̬����ǰ��ʱ�Ĳ�������
u8 yuyin_flag=0;			//���͸��������ı�־
u16 Yuyin[4]={4,4,4,4};//������ʾ�洢����
u16 low_speed=0,middle_speed=0,high_speed=0;	

#endif

//��������
void zuoxuan(u8 FX) //����
{
	int Z_deg=0;//��ת�ķ���ֵ
	
	FX_flag=4;					//�����ϵĺ����Ұ�ťȷ�����Ʋ泵����ʻ�����־FX_flag
	yuyin_flag=20;
	HmiScreenRunState = 1;
	
	tz_flag=0,qj_flag=0,htz_flag=0,hty_flag=0;	//�������������־
	Ruan_Qi(SPEED_min,0);//�ٶȸ�ֵ
	qianjin();
	Z_deg=deg;
	while(Z_deg>SystemParameter[4]&&QD_flag==1)
	{
		Z_deg-=4;
		if(Z_deg<6)
		{
			Z_deg = 0;
		}
		PWM_val(TIM4,4,Z_deg);	//����PWM �����	
		osdelay_ms(10);				
	}
	
	Ruan_Qi(SPEED_min,550);//�ٶȸ�ֵ
	if(Xuan_Zhuang_Ci_Shu<1)
	{
		Xuan_Zhuang_Ci_Shu=1;
	}
	while(Xuan_Zhuang_Ci_Shu)
	{
		Xuan_Zhuang_Ci_Shu--;
		while(PLC_Data[3]!=0xffff&&QD_flag==1)
		{
			osdelay_ms(20);
		}	
		while(front_cdh16.Num<3&&FX_flag==4)
		{
			if(QD_flag==0)			
			{
				Ruan_Qi(SPEED_min,0);//�ٶȸ�ֵ;
				tingzhi();
				while(FX_flag==4&&QD_flag==0)
				{
					osdelay_ms(20);
				}
				if(FX_flag==4)
				{
					qianjin();
					osdelay_ms(100);
					Ruan_Qi(SPEED_min,550);//�ٶȸ�ֵ
				}		
			}		
			osdelay_ms(20);
		}
	}

	Ruan_Qi(SPEED_min,0);//�ٶȸ�ֵ;
	while(Z_deg<PLC_Data[12]&&QD_flag==1)
	{
		Z_deg+=4;
		
		PWM_val(TIM4,4,Z_deg);	
		osdelay_ms(10);				
	}
	//�������
	FX_flag = FX;
	osdelay_ms(20);	
	Ruan_Qi(SPEED_min,speed);//�ٶȸ�ֵ
}
//��������
void youxuan(u8 FX) //����
{
	int Z_deg=0;//��ת�ķ���ֵ
	
	FX_flag=5;					//�����ϵĺ����Ұ�ťȷ�����Ʋ泵����ʻ�����־FX_flag
	yuyin_flag=21;
	HmiScreenRunState = 1;
	
	tz_flag=0,qj_flag=0,htz_flag=0,hty_flag=0;	//�������������־
	Ruan_Qi(SPEED_min,0);//�ٶȸ�ֵ
	houtui();
	
	Z_deg=deg;
	while(Z_deg>SystemParameter[5]&&QD_flag==1)
	{
		Z_deg-=4;
		if(Z_deg<6)
		{
			Z_deg=0;
		}	
		PWM_val(TIM4,4,Z_deg);	//����PWM �����	
		osdelay_ms(10);				
	}
	Ruan_Qi(SPEED_min,550);//�ٶȸ�ֵ
	if(Xuan_Zhuang_Ci_Shu<1)
	{
		Xuan_Zhuang_Ci_Shu=1;
	}
	while(Xuan_Zhuang_Ci_Shu)
	{
		Xuan_Zhuang_Ci_Shu--;
		while(PLC_Data[3]!=0xffff&&FX_flag==5)
		{
			osdelay_ms(20);
		}
		while(front_cdh16.Num<3)
		{
			if(QD_flag==0)			
			{
				Ruan_Qi(SPEED_min,0);//�ٶȸ�ֵ;
				tingzhi();
				while(FX_flag==5&&QD_flag==0)
				{
					osdelay_ms(20);
				}
				if(FX_flag==5)
				{
					houtui();
					osdelay_ms(100);
					Ruan_Qi(SPEED_min,550);//�ٶȸ�ֵ
				}		
			}
			osdelay_ms(20);
		}
	}
	Ruan_Qi(SPEED_min,0);//�ٶȸ�ֵ
	while(Z_deg<PLC_Data[12]&&QD_flag==1)
	{
		Z_deg+=4;
		PWM_val(TIM4,4,Z_deg);	
		osdelay_ms(10);				
	}
	//�������
	FX_flag = FX;
	osdelay_ms(20);	
	Ruan_Qi(SPEED_min,speed);//�ٶȸ�ֵ
	
}


/*********����ȫ�ֲ����������************/
//������
int main(void)
{
	OS_ERR err;
	CPU_SR_ALLOC();
	
	delay_init(168);  				//ʱ�ӳ�ʼ��
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);//�жϷ�������
	
	LED_Init();           		//LED��ʼ��	
	BAOHU_Init();							//���ֱ����������ĳ�ʼ��
	W25QXX_Init();						//flash��ʼ��  
	
	DMA_adc1_Init();					//�����ɼ�adc DMA��ʼ��
	DMA_Uart2_Init();					//����2	DMA�ر��ʼ��
	DMA_Uart3_Init();					//����3	DMA���߳�ʼ��
	DMA_Uart4_Init();					//����4	DMA��������ʼ��
	DMA_Uart6_Init();					//����6	DMA wifi��ʼ��
	
	ADC1_Init();							//�����ɼ�adc ��ʼ��
	uart_init(9600);					//����1��ʼ��(����rs232����)
	usart2_init(9600);		    //����2��ʼ��(RFID����) 
	usart3_init(115200);      //170M����
	uart4_init(9600);		    	//����4��ʼ����������RS484���ڣ� 
	usart6_init(115200);		    //����6��ʼ����WIFIģ�鴮�ڣ�
//	CDH_Init();					      //�ŵ����˿ڳ�ʼ��(��CAN2����Ҫ)
	Control_Init();			      //�泵��ʻ��������źų�ʼ��
	PWM_Init(TIM4,4,10000,0);	//���PWM�˿ڳ�ʼ��
	PWM_Init(TIM4,2,10000,0);	//�ٶ�PWM�˿ڳ�ʼ��

	//�������Ź�
	IWDG_Init(4,500);    	//Ԥ��Ƶ��Ϊ64,����ֵΪ500,���ʱ��Ϊ1s	  

	PID_Init();
	PID1_Init();
	PID4_Init();
	CAN2_Mode_Init(CAN_SJW_1tq,CAN_BS2_6tq,CAN_BS1_7tq,6,CAN_Mode_Normal);//CAN2��ʼ����ͨģʽ,������500Kbps 
	CAN1_Mode_Init(CAN_SJW_1tq,CAN_BS2_6tq,CAN_BS1_7tq,6,CAN_Mode_Normal);//CAN��ʼ������ģʽ,������500Kbps 
	/****�����帴λʱ���̵����巢��һ����־����ָ�֮ǰ��״̬��ʼ*/
	can_Sebuf[2]=0x55;
	CanSend();	
	can_Sebuf[2]=0;
	/****�����帴λʱ���̵����巢��һ����־����ָ�֮ǰ��״̬����*/
	speek(" ");
	HmiScreenSetGet=47;//����ʼ��Ϊ��ҳ
	
	OSInit(&err);		    //��ʼ��UCOSIII
	OS_CRITICAL_ENTER();	//�����ٽ���			 
	//������ʼ����
	OSTaskCreate((OS_TCB 	* )&StartTaskTCB,		//������ƿ�
				 (CPU_CHAR	* )"start task", 		//��������
                 (OS_TASK_PTR )start_task, 			//������
                 (void		* )0,					//���ݸ��������Ĳ���
                 (OS_PRIO	  )START_TASK_PRIO,     //�������ȼ�
                 (CPU_STK   * )&START_TASK_STK[0],	//�����ջ����ַ
                 (CPU_STK_SIZE)START_STK_SIZE/10,	//�����ջ�����λ
                 (CPU_STK_SIZE)START_STK_SIZE,		//�����ջ��С
                 (OS_MSG_QTY  )0,					//�����ڲ���Ϣ�����ܹ����յ������Ϣ��Ŀ,Ϊ0ʱ��ֹ������Ϣ
                 (OS_TICK	  )0,					//��ʹ��ʱ��Ƭ��תʱ��ʱ��Ƭ���ȣ�Ϊ0ʱΪĬ�ϳ��ȣ�
                 (void   	* )0,					//�û�����Ĵ洢��
                 (OS_OPT      )OS_OPT_TASK_STK_CHK|OS_OPT_TASK_STK_CLR, //����ѡ��
                 (OS_ERR 	* )&err);				//��Ÿú�������ʱ�ķ���ֵ
	OS_CRITICAL_EXIT();	//�˳��ٽ���	 
	OSStart(&err);      //����UCOSIII
}


//��ʼ����������
void start_task(void *p_arg)
{
	OS_ERR err;
	CPU_SR_ALLOC();
	p_arg = p_arg;

	CPU_Init();
#if OS_CFG_STAT_TASK_EN > 0u
   OSStatTaskCPUUsageInit(&err);  	//ͳ������                
#endif
	
#ifdef CPU_CFG_INT_DIS_MEAS_EN		//���ʹ���˲����жϹر�ʱ��
    CPU_IntDisMeasMaxCurReset();	
#endif
	
#if	OS_CFG_SCHED_ROUND_ROBIN_EN  //��ʹ��ʱ��Ƭ��ת��ʱ��
	 //ʹ��ʱ��Ƭ��ת���ȹ���,ʱ��Ƭ����Ϊ1��ϵͳʱ�ӽ��ģ���1*5=5ms
	OSSchedRoundRobinCfg(DEF_ENABLED,1,&err);  
#endif	
	
	OS_CRITICAL_ENTER();	//�����ٽ���
	
#if	1		//Ϊ�����Ŷ��ӵ�
	//����Task1����1
	OSTaskCreate((OS_TCB 	* )&Task1_TaskTCB,		
				 (CPU_CHAR	* )"Task1 task", 		
                 (OS_TASK_PTR )Task1_task, 			
                 (void		* )0,					
                 (OS_PRIO	  )Task1_TASK_PRIO,     
                 (CPU_STK   * )&Task1_TASK_STK[0],	
                 (CPU_STK_SIZE)Task1_STK_SIZE/10,	
                 (CPU_STK_SIZE)Task1_STK_SIZE,		
                 (OS_MSG_QTY  )0,					
                 (OS_TICK	  )0,					
                 (void   	* )0,					
                 (OS_OPT      )OS_OPT_TASK_STK_CHK|OS_OPT_TASK_STK_CLR,
                 (OS_ERR 	* )&err);				
				 
	//����Automode����2
	OSTaskCreate((OS_TCB 	* )&Automode_TaskTCB,		
				 (CPU_CHAR	* )"Automode task", 		
                 (OS_TASK_PTR )Automode_task, 			
                 (void		* )0,					
                 (OS_PRIO	  )Automode_TASK_PRIO,     	
                 (CPU_STK   * )&Automode_TASK_STK[0],	
                 (CPU_STK_SIZE)Automode_STK_SIZE/10,	
                 (CPU_STK_SIZE)Automode_STK_SIZE,		
                 (OS_MSG_QTY  )0,					
                 (OS_TICK	  )0,					
                 (void   	* )0,				
                 (OS_OPT      )OS_OPT_TASK_STK_CHK|OS_OPT_TASK_STK_CLR, 
                 (OS_ERR 	* )&err);	
	//����TASK1����3
	OSTaskCreate((OS_TCB 	* )&Control_TaskTCB,		
				 (CPU_CHAR	* )"Control task", 		
                 (OS_TASK_PTR )Control_task, 			
                 (void		* )0,					
                 (OS_PRIO	  )Control_TASK_PRIO,     
                 (CPU_STK   * )&Control_TASK_STK[0],	
                 (CPU_STK_SIZE)Control_STK_SIZE/10,	
                 (CPU_STK_SIZE)Control_STK_SIZE,		
                 (OS_MSG_QTY  )0,					
                 (OS_TICK	  )0,					
                 (void   	* )0,					
                 (OS_OPT      )OS_OPT_TASK_STK_CHK|OS_OPT_TASK_STK_CLR,
                 (OS_ERR 	* )&err);				
				 
	//����TASK2����4
	OSTaskCreate((OS_TCB 	* )&Task4_TaskTCB,		
				 (CPU_CHAR	* )"Task4 task", 		
                 (OS_TASK_PTR )Task4_task, 			
                 (void		* )0,					
                 (OS_PRIO	  )Task4_TASK_PRIO,     	
                 (CPU_STK   * )&Task4_TASK_STK[0],	
                 (CPU_STK_SIZE)Task4_STK_SIZE/10,	
                 (CPU_STK_SIZE)Task4_STK_SIZE,		
                 (OS_MSG_QTY  )0,					
                 (OS_TICK	  )0,					
                 (void   	* )0,				
                 (OS_OPT      )OS_OPT_TASK_STK_CHK|OS_OPT_TASK_STK_CLR, 
                 (OS_ERR 	* )&err);	
								 
	//����TASK1����5
	OSTaskCreate((OS_TCB 	* )&Cansend_TaskTCB,		
				 (CPU_CHAR	* )"Cansend task", 		
                 (OS_TASK_PTR )Cansend_task, 			
                 (void		* )0,					
                 (OS_PRIO	  )Cansend_TASK_PRIO,     
                 (CPU_STK   * )&Cansend_TASK_STK[0],	
                 (CPU_STK_SIZE)Cansend_STK_SIZE/10,	
                 (CPU_STK_SIZE)Cansend_STK_SIZE,		
                 (OS_MSG_QTY  )0,					
                 (OS_TICK	  )0,					
                 (void   	* )0,					
                 (OS_OPT      )OS_OPT_TASK_STK_CHK|OS_OPT_TASK_STK_CLR,
                 (OS_ERR 	* )&err);				
				 
	//����TASK2����6
	OSTaskCreate((OS_TCB 	* )&RunLED_TaskTCB,		
				 (CPU_CHAR	* )"RunLED task", 		
                 (OS_TASK_PTR )RunLED_task, 			
                 (void		* )0,					
                 (OS_PRIO	  )RunLED_TASK_PRIO,     	
                 (CPU_STK   * )&RunLED_TASK_STK[0],	
                 (CPU_STK_SIZE)RunLED_STK_SIZE/10,	
                 (CPU_STK_SIZE)RunLED_STK_SIZE,		
                 (OS_MSG_QTY  )0,					
                 (OS_TICK	  )0,					
                 (void   	* )0,				
                 (OS_OPT      )OS_OPT_TASK_STK_CHK|OS_OPT_TASK_STK_CLR, 
                 (OS_ERR 	* )&err);	
	
	//����TASK2����7
	OSTaskCreate((OS_TCB 	* )&RFID_TaskTCB,		
				 (CPU_CHAR	* )"RFID task", 		
                 (OS_TASK_PTR )RFID_task, 			
                 (void		* )0,					
                 (OS_PRIO	  )RFID_TASK_PRIO,     	
                 (CPU_STK   * )&RFID_TASK_STK[0],	
                 (CPU_STK_SIZE)RFID_STK_SIZE/10,	
                 (CPU_STK_SIZE)RFID_STK_SIZE,		
                 (OS_MSG_QTY  )0,					
                 (OS_TICK	  )0,					
                 (void   	* )0,				
                 (OS_OPT      )OS_OPT_TASK_STK_CHK|OS_OPT_TASK_STK_CLR, 
                 (OS_ERR 	* )&err);
								 
	//����TASK3����8
	OSTaskCreate((OS_TCB 	* )&YAOKONG_TaskTCB,		
				 (CPU_CHAR	* )"YAOKONG task", 		
                 (OS_TASK_PTR )YAOKONG_task, 			
                 (void		* )0,					
                 (OS_PRIO	  )YAOKONG_TASK_PRIO,     	
                 (CPU_STK   * )&YAOKONG_TASK_STK[0],	
                 (CPU_STK_SIZE)YAOKONG_STK_SIZE/10,	
                 (CPU_STK_SIZE)YAOKONG_STK_SIZE,		
                 (OS_MSG_QTY  )0,					
                 (OS_TICK	  )0,					
                 (void   	* )0,				
                 (OS_OPT      )OS_OPT_TASK_STK_CHK|OS_OPT_TASK_STK_CLR, 
                 (OS_ERR 	* )&err);
								 
								 
	//����TASK5����9
	OSTaskCreate((OS_TCB 	* )&Task5_TaskTCB,		
				 (CPU_CHAR	* )"Task5 task", 		
                 (OS_TASK_PTR )Task5_task, 			
                 (void		* )0,					
                 (OS_PRIO	  )Task5_TASK_PRIO,     	
                 (CPU_STK   * )&Task5_TASK_STK[0],	
                 (CPU_STK_SIZE)Task5_STK_SIZE/10,	
                 (CPU_STK_SIZE)Task5_STK_SIZE,		
                 (OS_MSG_QTY  )0,					
                 (OS_TICK	  )0,					
                 (void   	* )0,				
                 (OS_OPT      )OS_OPT_TASK_STK_CHK|OS_OPT_TASK_STK_CLR, 
                 (OS_ERR 	* )&err);
								 
	//����TASK6����10
	OSTaskCreate((OS_TCB 	* )&Task6_TaskTCB,		
				 (CPU_CHAR	* )"Task6 task", 		
                 (OS_TASK_PTR )Task6_task, 			
                 (void		* )0,					
                 (OS_PRIO	  )Task6_TASK_PRIO,     	
                 (CPU_STK   * )&Task6_TASK_STK[0],	
                 (CPU_STK_SIZE)Task6_STK_SIZE/10,	
                 (CPU_STK_SIZE)Task6_STK_SIZE,		
                 (OS_MSG_QTY  )0,					
                 (OS_TICK	  )0,					
                 (void   	* )0,				
                 (OS_OPT      )OS_OPT_TASK_STK_CHK|OS_OPT_TASK_STK_CLR, 
                 (OS_ERR 	* )&err);
								 
	//����TASK7����11
	OSTaskCreate((OS_TCB 	* )&Task7_TaskTCB,		
				 (CPU_CHAR	* )"Task7 task", 		
                 (OS_TASK_PTR )Task7_task, 			
                 (void		* )0,					
                 (OS_PRIO	  )Task7_TASK_PRIO,     	
                 (CPU_STK   * )&Task7_TASK_STK[0],	
                 (CPU_STK_SIZE)Task7_STK_SIZE/10,	
                 (CPU_STK_SIZE)Task7_STK_SIZE,		
                 (OS_MSG_QTY  )0,					
                 (OS_TICK	  )0,					
                 (void   	* )0,				
                 (OS_OPT      )OS_OPT_TASK_STK_CHK|OS_OPT_TASK_STK_CLR, 
                 (OS_ERR 	* )&err);
								 
	//����Task8����12
	OSTaskCreate((OS_TCB 	* )&Task8_TaskTCB,		
				 (CPU_CHAR	* )"Task8 task", 		
                 (OS_TASK_PTR )Task8_task, 			
                 (void		* )0,					
                 (OS_PRIO	  )Task8_TASK_PRIO,     	
                 (CPU_STK   * )&Task8_TASK_STK[0],	
                 (CPU_STK_SIZE)Task8_STK_SIZE/10,	
                 (CPU_STK_SIZE)Task8_STK_SIZE,		
                 (OS_MSG_QTY  )0,					
                 (OS_TICK	  )0,					
                 (void   	* )0,				
                 (OS_OPT      )OS_OPT_TASK_STK_CHK|OS_OPT_TASK_STK_CLR, 
                 (OS_ERR 	* )&err);
								 
	//����Task9����13
	OSTaskCreate((OS_TCB 	* )&Task9_TaskTCB,		
				 (CPU_CHAR	* )"Task9 task", 		
                 (OS_TASK_PTR )Task9_task, 			
                 (void		* )0,					
                 (OS_PRIO	  )Task9_TASK_PRIO,     	
                 (CPU_STK   * )&Task9_TASK_STK[0],	
                 (CPU_STK_SIZE)Task9_STK_SIZE/10,	
                 (CPU_STK_SIZE)Task9_STK_SIZE,		
                 (OS_MSG_QTY  )0,					
                 (OS_TICK	  )0,					
                 (void   	* )0,				
                 (OS_OPT      )OS_OPT_TASK_STK_CHK|OS_OPT_TASK_STK_CLR, 
                 (OS_ERR 	* )&err);
								 
	//����Task10����14
	OSTaskCreate((OS_TCB 	* )&Task10_TaskTCB,		
				 (CPU_CHAR	* )"Task10 task", 		
                 (OS_TASK_PTR )Task10_task, 			
                 (void		* )0,					
                 (OS_PRIO	  )Task10_TASK_PRIO,     	
                 (CPU_STK   * )&Task10_TASK_STK[0],	
                 (CPU_STK_SIZE)Task10_STK_SIZE/10,	
                 (CPU_STK_SIZE)Task10_STK_SIZE,		
                 (OS_MSG_QTY  )0,					
                 (OS_TICK	  )0,					
                 (void   	* )0,				
                 (OS_OPT      )OS_OPT_TASK_STK_CHK|OS_OPT_TASK_STK_CLR, 
                 (OS_ERR 	* )&err);


		//����Task11����15
	OSTaskCreate((OS_TCB 	* )&Task11_TaskTCB,		
				 (CPU_CHAR	* )"Task11 task", 		
                 (OS_TASK_PTR )Task11_task, 			
                 (void		* )0,					
                 (OS_PRIO	  )Task11_TASK_PRIO,     	
                 (CPU_STK   * )&Task11_TASK_STK[0],	
                 (CPU_STK_SIZE)Task11_STK_SIZE/10,	
                 (CPU_STK_SIZE)Task11_STK_SIZE,		
                 (OS_MSG_QTY  )0,					
                 (OS_TICK	  )0,					
                 (void   	* )0,				
                 (OS_OPT      )OS_OPT_TASK_STK_CHK|OS_OPT_TASK_STK_CLR, 
                 (OS_ERR 	* )&err);		


		//����Task12
	OSTaskCreate((OS_TCB 	* )&Task12_TaskTCB,		
				 (CPU_CHAR	* )"Task12 task", 		
                 (OS_TASK_PTR )Task12_task, 			
                 (void		* )0,					
                 (OS_PRIO	  )Task12_TASK_PRIO,     	
                 (CPU_STK   * )&Task12_TASK_STK[0],	
                 (CPU_STK_SIZE)Task12_STK_SIZE/10,	
                 (CPU_STK_SIZE)Task12_STK_SIZE,		
                 (OS_MSG_QTY  )0,					
                 (OS_TICK	  )0,					
                 (void   	* )0,				
                 (OS_OPT      )OS_OPT_TASK_STK_CHK|OS_OPT_TASK_STK_CLR, 
                 (OS_ERR 	* )&err);	

		//����Task13
	OSTaskCreate((OS_TCB 	* )&Task13_TaskTCB,		
				 (CPU_CHAR	* )"Task13 task", 		
                 (OS_TASK_PTR )Task13_task, 			
                 (void		* )0,					
                 (OS_PRIO	  )Task13_TASK_PRIO,     	
                 (CPU_STK   * )&Task13_TASK_STK[0],	
                 (CPU_STK_SIZE)Task13_STK_SIZE/10,	
                 (CPU_STK_SIZE)Task13_STK_SIZE,		
                 (OS_MSG_QTY  )0,					
                 (OS_TICK	  )0,					
                 (void   	* )0,				
                 (OS_OPT      )OS_OPT_TASK_STK_CHK|OS_OPT_TASK_STK_CLR, 
                 (OS_ERR 	* )&err);									 
								 
								
		//����Task15
	OSTaskCreate((OS_TCB 	* )&Task15_TaskTCB,		
				 (CPU_CHAR	* )"Task15 task", 		
                 (OS_TASK_PTR )Task15_task, 			
                 (void		* )0,					
                 (OS_PRIO	  )Task15_TASK_PRIO,     	
                 (CPU_STK   * )&Task15_TASK_STK[0],	
                 (CPU_STK_SIZE)Task15_STK_SIZE/10,	
                 (CPU_STK_SIZE)Task15_STK_SIZE,		
                 (OS_MSG_QTY  )0,					
                 (OS_TICK	  )0,					
                 (void   	* )0,				
                 (OS_OPT      )OS_OPT_TASK_STK_CHK|OS_OPT_TASK_STK_CLR, 
                 (OS_ERR 	* )&err);	
	#endif
									
	OS_CRITICAL_EXIT();	//�˳��ٽ���
	OSTaskDel((OS_TCB*)0,&err);	//ɾ��start_task��������
}

//�ŵ������ݲɼ�������������
void Task1_task(void *p_arg)
{	
	p_arg = p_arg;
	while(1)
	{		
		/***************ʵʱ��ʾ�ŵ������ݿ�ʼ****************/
		
		PLC_Data[3]=CDH16;		//ǰ��16λ�ŵ������ݶ�������ʾ�ڴ�������
		PLC_Data[4]=CDH8_2;		//����8λ�ŵ������ݶ�������ʾ�ڴ�������	
		PLC_Data[5]=CDH8_3;		//����8λ�ŵ������ݶ�������ʾ�ڴ�������	
		
		/***************ʵʱ��ʾ�ŵ������ݽ���****************/
		
		//���κ�����¾��ɼ�ǰ�ŵ������ݲ�����
		front_cdh16=FindSpace(PLC_Data[3],16,FC_flag);//�����������ĵ���������
		CDH12_num=front_cdh16.Distance;//���ŵ����ɼ���ԭʼ���ݴ����������ֵ��CDH12_num
		//ǰ�ŵ������췽��ķ�����Ѱ���������ε���������ʱ������ʱҲѰ��
		
		/***************************ǰ��������ʱ��¼���췽���־��ʼ***************************/
		if(CDH12_num!=0)//δ����ʱ��������ʱ��
		{
			Last_CDH12_num=CDH12_num;//Ϊ1~31�ķ�Χ
			if(CDH12_num>5&&CDH12_num<25)//�м䷶Χ��
			{
				Chu_Gui_dir=0;
			}
			else if(CDH12_num<6)//�ŵ���̫ƫ��
			{
				Chu_Gui_dir=2;
			}
			else if(CDH12_num>24)//�ŵ���̫ƫ��
			{
				Chu_Gui_dir=1;
			}
		}
		else//����ʱ
		{
			if(Last_CDH12_num<16)//����߳���
			{
				Chu_Gui_dir=2;
			}
			else if(Last_CDH12_num>16)//���ұ߳���
			{
				Chu_Gui_dir=1;
			}
			else//���м����
			{
				Chu_Gui_dir=0;
			}
		}
		
		/***************************ǰ��������ʱ��¼���췽���־����***************************/
		if(Mode_flag==1)//���Զ�ģʽ�²�ִ�����²���
		{			
				/***********����ʻ�����־��ȷ���ɼ���·�ŵ������ݿ�ʼ*************/
				switch(FX_flag)//����ʻ�����־��ȷ���ɼ���·�ŵ�������
				{
					case 0:
								break;
					case 2://������
								{										
									backl_cdh8=FindSpace1(PLC_Data[4],8,FC_flag);//����ʱ���ŵ���
									CDH2_num=backl_cdh8.Distance;//�����Ľ��ŵ����ɼ���ԭʼ���ݴ����������ֵ��CDH2_num
									PLC_Data[7]=CDH2_num;
								}
								break;
					case 3://������
								{										
									backr_cdh8=FindSpace1(PLC_Data[5],8,FC_flag);//����ʱ���ŵ����⵽�������Ƿ��зֲ����
									CDH3_num=backr_cdh8.Distance;//�����Ľ��ŵ����ɼ���ԭʼ���ݴ����������ֵ��CDH3_num
									PLC_Data[7]=CDH3_num;
								}
								break;
					default :	
								 break;
				}
				/************����ʻ�����־��ȷ���ɼ���·�ŵ������ݽ���***********/
		}
		else 						//���ֶ�ģʽ�²�ִ�����²���
		{
			LED2=1;
			LED3=1;
			LED4=1;
		}
		osdelay_ms(20);
	}
}

//Automode����������������������ʻ��PID����
void Automode_task(void *p_arg)
{
	u8 t=0,t1=0,t2=0;//�泵��ʻ�����LED����˸ʱ�䣨����Ҫ��
	
	int ut=0; 	//��ǰ����ƫ��
	int Z_deg1=0;//��ת�ķ���ֵ
	
	int distance16=0;
	int distanceR=0;
	int distanceL=0;

	u8 Chu_Gui_time=0;//����Ѱ����ʱ���ۻ�ϵ��
	
	p_arg = p_arg;
	
	while(1)
	{
		while(QD_flag==0)//ֹͣ��ѭ��
		{	
			if(tz_flag==0)
			{
				Ruan_Qi(SPEED_min,0);//�ٶȸ�ֵ
				tingzhi();
				tz_flag=1,qj_flag=0,htz_flag=0,hty_flag=0;
				LED2=1;                                   
				LED3=1;                                   
				LED4=1; 
			}                                           
			osdelay_ms(20);
		}
		while(FX_flag==1&&QD_flag==1) //ǰ����ѭ��
		{
			if(qj_flag==0)
			{
				Bi_Zhang_flag=0;//�Ա��ϱ�־�� 0
				switch(Chu_Gui_dir)//��������ʱ���ж�һ��
				{
					case 0://����
					{
						
					}break;
					case 1://�ϴγ����Ǵ���߳���
					{
						Ruan_Qi(SPEED_min,0);//�ٶȸ�ֵΪ0
						qianjin();
						if(deg==0)
						{
							deg=PLC_Data[12];
						}
						Z_deg1=deg;
						while(Z_deg1>100&&QD_flag==1)//�����
						{
							Z_deg1-=10;
							if(Z_deg1<0)
							{
								Z_deg1=0;
							}
							PWM_val(TIM4,4,Z_deg1);	//����PWM �����	
							osdelay_ms(10);				
						}
						osdelay_ms(500);
						Ruan_Qi(SPEED_min,550);//�ٶȸ�ֵΪ400
						Chu_Gui_time=0;//�����ڿ�ʼ��ת��ʱ������
						while((CDH12_num<5||CDH12_num>25)&&Chu_Gui_time<200&&QD_flag==1)//û��ת�����ʵ�ֵʱ����ת����ʱ�䵽֮ǰһֱת
						{
							if(Bi_Zhang_flag==0)//û�б��ϵ������
							{
								Chu_Gui_time++;
							}
							osdelay_ms(20);
						}	
						Ruan_Qi(SPEED_min,0);//�ٶȸ�ֵΪ0
						while(Z_deg1<PLC_Data[12]&&QD_flag==1)//����
						{
							Z_deg1+=10;	
							PWM_val(TIM4,4,Z_deg1);	//����PWM 
							osdelay_ms(10);				
						}
						if(Chu_Gui_time>199)//��Ϊʱ�䵽��ûѰ����ֹͣ��ѭ��
						{
							Ting_Zhi();
						}
					}break;
					case 2://�ϴγ����Ǵ��ұ߳���
					{
						Ruan_Qi(SPEED_min,0);//�ٶȸ�ֵΪ0
						qianjin();
						if(deg==0)
						{
							deg=PLC_Data[12];
						}
						Z_deg1=deg;
						while(Z_deg1<1000&&QD_flag==1)//�Ҵ���
						{
							Z_deg1+=10;
							if(Z_deg1>1000)
							{
								Z_deg1=1000;
							}
							PWM_val(TIM4,4,Z_deg1);	//����PWM �����	
							osdelay_ms(10);				
						}
						osdelay_ms(500);
						Ruan_Qi(SPEED_min,550);//�ٶȸ�ֵΪ450
						Chu_Gui_time=0;//�����ڿ�ʼ��ת��ʱ������
						while((CDH12_num<5||CDH12_num>25)&&Chu_Gui_time<200&&QD_flag==1)//û��ת�����ʵ�ֵʱ����ת����ʱ�䵽֮ǰһֱת
						{
							if(Bi_Zhang_flag==0)//û�б��ϵ������
							{
								Chu_Gui_time++;
							}
							osdelay_ms(20);
						}
						Ruan_Qi(SPEED_min,0);//�ٶȸ�ֵΪ0
						while(Z_deg1>PLC_Data[12]&&QD_flag==1)//����
						{
							Z_deg1-=10;	
							PWM_val(TIM4,4,Z_deg1);	//����PWM 
							osdelay_ms(10);				
						}
						if(Chu_Gui_time>199)//��Ϊʱ�䵽��ûѰ����ֹͣ��ѭ��
						{
							Ting_Zhi();
						}
					}break;
				}
				if(CDH12_num!=0)//������û�������Ѱ�ϴ����˲��ٴ�������ʻ
				{
					qianjin();
				}
				else
				{
					Ting_Zhi();
				}
				tz_flag=0,qj_flag=1,htz_flag=0,hty_flag=0;
				LED2=1;
				LED3=1;
				LED4=1;
			}
			
			if(Bi_Zhang_flag==0&&front_cdh16.Num>0&&front_cdh16.zeroNum<2)//����ڱ��ϻ�����ȫ����������򲻵���PID
			{
					PLC_Data[7] = front_cdh16.Distance;
					
					//û��ͻ�䣬��������
					if(abs(distance16-front_cdh16.Distance)<2)
					{
						ut=PosPIDCalc(CDH12_num,1);//����λ��ʽPIDCDH12_num
					}
					distance16 = front_cdh16.Distance;
					
					if(ut>0)
					{
						ut=(int)(0.727*ut);
					}
					deg=579+ut;//�����ֵ���Ϊ579������Ϊ0���Ҽ���ΪΪ1000	
					if(deg<0)
					{
						deg=0;
					}
					if(deg>1000)
					{
						deg=1000;
					}
					PWM_val(TIM4,4,deg);	//����PWM
					speed_ture=speed*((1+((fabs(deg-500))/500)*(fabs(deg-500))/500));
					Ruan_Qi(SPEED_min,speed_ture);//�ٶȸ�ֵ
					PLC_Data[1]=speed_ture;
					PLC_Data[2]=deg;		//����Ļ����ʾ�趨�Ƕ�PWM������
			}
			t++;
			if(t==25)
			{
				LED2=~LED2;
				t=0;
			}
				
			//������ִ�ж�
			if(front_cdh16.Num==0)				//������죨��3s����û��Ѱ�������������ʻ����ֹͣ��
			{	
				Chu_Gui_time=0;
				while(FX_flag==1&&front_cdh16.Num==0&&Chu_Gui_time<150&&QD_flag==1)
				{
					if(Bi_Zhang_flag==0)//û�б��ϵ������
					{
						Chu_Gui_time++;
					}
					osdelay_ms(20);
				}

				if(FX_flag!=1)
				{
					
				}
				else if(front_cdh16.Num==0&&QD_flag==1)//���ɳ�����ֹͣ
				{
					Ting_Zhi();
					//����״̬
					HmiTaskState = 12;
				}
			}	
			//PID����ʱ���
			if(PLC_Data[11]>0&&PLC_Data[11]<100)
			{
				osdelay_ms(PLC_Data[11]+10);
			}
			else 
			{
				osdelay_ms(20);
			}
			
		}
		while(FX_flag==2&&QD_flag==1)	//�������ѭ��
		{
			if(htz_flag==0)
			{
				Bi_Zhang_flag=0;//�Ա��ϱ�־�� 0
				houtui();
				Ruan_Qi(SPEED_min,260);//�ٶȸ�ֵ
				tz_flag=0,qj_flag=0,htz_flag=1,hty_flag=0;
				LED2=1;
				LED3=1;
				LED4=1;
			}

			
			if(Bi_Zhang_flag==0&&backl_cdh8.Num>0&&backl_cdh8.zeroNum<2)//����ڱ��ϵ�������򲻵��������ȫ��ʱ������
			{
				
				//û��ͻ�䣬��������
				if(abs(distanceL-backl_cdh8.Distance)<2)
				{
					deg=PosPIDCalc(CDH2_num,3);//����λ��ʽPID
				}
				distanceL = backl_cdh8.Distance;
		
				PWM_val(TIM4,4,deg);//����PWM
				
				speed_ture=speed*((1+((fabs(deg-500))/500)*(fabs(deg-500))/500));
				Ruan_Qi(SPEED_min,speed_ture);//�ٶȸ�ֵ
				PLC_Data[1]=speed_ture;
				PLC_Data[2]=deg;		//����Ļ����ʾ�趨�Ƕ�PWM������
			}
			t1++;
			if(t1==25)
			{
				LED3=~LED3;
				t1=0;
			}
			
			if(backl_cdh8.Num==0)				//�������ֹͣ
			{
				Chu_Gui_time=0;
				while(FX_flag==2&&backl_cdh8.Num==0&&Chu_Gui_time<100&&QD_flag==1)
				{
					if(Bi_Zhang_flag==0)//û�б��ϵ������
					{
						Chu_Gui_time++;
					}
					osdelay_ms(20);
				}
				if(FX_flag!=2)
				{
					
				}
				else if(backl_cdh8.Num==0&&QD_flag==1)
				{
					Ting_Zhi();
					HmiTaskState = 10;
				}
			}
			osdelay_ms(10);
		}
		while(FX_flag==3&&QD_flag==1)	//�����ҵ�ѭ��
		{
			if(hty_flag==0)
			{
				Bi_Zhang_flag=0;//�Ա��ϱ�־�� 0
				houtui();
				Ruan_Qi(SPEED_min,260);//�ٶȸ�ֵ
				tz_flag=0,qj_flag=0,htz_flag=0,hty_flag=1;
				LED2=1;
				LED3=1;
				LED4=1;
			}
			
			if(Bi_Zhang_flag==0&&backr_cdh8.Num>0&&backr_cdh8.zeroNum<2)//����ڱ��ϵ�������򲻵��������ȫ��ʱ������
			{
				//û��ͻ�䣬��������
				if(abs(distanceR-backr_cdh8.Distance)<2)
				{
					deg=PosPIDCalc(CDH3_num,3);//����λ��ʽPID
				}
				distanceR = backr_cdh8.Distance;
				
				PWM_val(TIM4,4,deg);//����PWM
				//���ٿ���
				speed_ture=speed*((1+((fabs(deg-500))/500)*(fabs(deg-500))/500));
				Ruan_Qi(SPEED_min,speed_ture);//�ٶȸ�ֵ
				
				PLC_Data[1]=speed_ture;
				PLC_Data[2]=deg;		//����Ļ����ʾ�趨�Ƕ�PWM������
			}
			t2++;
			if(t2==25)
			{
				LED4=~LED4;
				t2=0;
			}
			
			if(backr_cdh8.Num==0)				//�������ֹͣ
			{
				Chu_Gui_time=0;
				while(FX_flag==3&&backr_cdh8.Num==0&&Chu_Gui_time<100&&QD_flag==1)
				{
					if(Bi_Zhang_flag==0)//û�б��ϵ������
					{
						Chu_Gui_time++;
					}
					osdelay_ms(20);
				}
				if(FX_flag!=3)
				{
					
				}
				else if(backr_cdh8.Num==0&&QD_flag==1)
				{
					Ting_Zhi();
					HmiTaskState = 11;
				}
			}

			osdelay_ms(10);
		}
				
		osdelay_ms(20);
	}
}

//Control������:�ֶ��������Զ��л��̵������ͨ��
void Control_task(void *p_arg)
{
	OS_ERR err;
	u8 Hand_flag=0,Auto_flag=0;
	p_arg = p_arg;
	
	while(1)
	{	
		if(Mode_flag==1)									//�Զ�����ģʽ��־������
		{		
				Police_flag=0;								//��ʾ�ƴ�
				if(Hand_flag==1)							//����ϴ��Ƿ�Ϊ�ֶ�����ģʽ
				{
					Hand_flag=0;								//����ֶ����Ʊ�־
				}
				if(Auto_flag==1)							//����ϴ����޴������Զ����ߣ�û�еĻ������Զ�����	
				{
					OSTaskResume((OS_TCB*)&Automode_TaskTCB,&err);//�ָ�Automode����						 					 
					
					P24 =0;//�ֱ�+24�л��̵���
					N24 =0;//�ֱ�GND�л��̵���
					CBS =1;//��������̵���
					CBX =1;//����½��̵���
					JJC =0;//�ӽ����ضϴ����һ�˼̵���
					JJB =1;//�ӽ����ضϲ����һ�˼̵���
					FX1 =0;//�泵��ʻ������ƶ�1�̵���
					FX2 =0;//�泵��ʻ������ƶ�2�̵���
					ZPWM=0;//ת��PWM�̵���
					FPWM=0;//����PWM�̵���
					
					Auto_flag=0;							//���Զ���־λΪ1�������´��ظ���������ϵͳ����	
				}
		}
		else															//�ֶ�����ģʽ��־������
		{
				Police_flag=1;
				if(Auto_flag==0)							//����ϴ��Ƿ�Ϊ�Զ�����ģʽ
				{
					OSTaskSuspend((OS_TCB*)&Automode_TaskTCB,&err); //����Automode����
					Auto_flag=1;							  //����Զ����б�־
				}
				if(Hand_flag==0)							//����ϴ����޴������ֶ����ߣ�û�еĻ������ֶ�����	
				{							 						 
					P24 =1;//�ֱ�+24�л��̵���
					N24 =1;//�ֱ�GND�л��̵���
					CBS =1;//��������̵���
					CBX =1;//����½��̵���
					JJC =1;//�ӽ����ضϴ����һ�˼̵���
					JJB =1;//�ӽ����ضϲ����һ�˼̵���
					FX1 =1;//�泵��ʻ������ƶ�1�̵���
					FX2 =1;//�泵��ʻ������ƶ�2�̵���
					ZPWM=1;//ת��PWM�̵���
					FPWM=1;//����PWM�̵���
					
					Hand_flag=1;								//���ֶ���־λΪ1�������´��ظ���������ϵͳ����
				}
		}
		osdelay_ms(20); //��ʱ20ms
	}

}

//��������������
void Task4_task(void *p_arg)
{
	p_arg = p_arg;
	
	W25QXX_Read_16(Yuyin,91,4);	//��λʱ�ȴ�flash�ж���������־����
	PLC_Data[23]=Yuyin[0];
	while(1)
	{
		//����ѡ��
		if(Yuyin[0]!=PLC_Data[23])//����ѡ��
		{
			Yuyin[0]=PLC_Data[23];
			W25QXX_Write_16(Yuyin,91,4);		//����ǰ��������д�뵽flash��
			if(Yuyin[0]==0)
			{
				rensheng(0);//����ѡ��
			}
			else if(Yuyin[0]==1)
			{
				rensheng(1);//����ѡ��
			}
			else if(Yuyin[0]==2)
			{
				rensheng(2);//����ѡ��
			}
			else if(Yuyin[0]==3)
			{
				rensheng(3);//����ѡ��
			}
			else if(Yuyin[0]==4)
			{
				rensheng(4);//����ѡ��
			}
			else if(Yuyin[0]==5)
			{
				rensheng(5);//����ѡ��
			}
		}
		//����ѡ��
		if(PLC_OutPut[18]==1)//����+
		{
			Yuyin[1]++;
			if(Yuyin[1]>9)
			{
				Yuyin[1]=9;
			}
			W25QXX_Write_16(Yuyin,91,4);		//����ǰ��������д�뵽flash��
			yinling(Yuyin[1]);//����ѡ��
		}
		else if(PLC_OutPut[19]==1)//����-
		{
			Yuyin[1]--;
			if(Yuyin[1]<1)
			{
				Yuyin[1]=1;
			}
			W25QXX_Write_16(Yuyin,91,4);		//����ǰ��������д�뵽flash��
			yinling(Yuyin[1]);//����ѡ��
		}
		//����ѡ��
		else if(PLC_OutPut[22]==1)//����+
		{
			Yuyin[2]++;
			if(Yuyin[2]>9)
			{
				Yuyin[2]=9;
			}
			W25QXX_Write_16(Yuyin,91,4);		//����ǰ��������д�뵽flash��
			yusu(Yuyin[2]);//����ѡ��
		}
		else if(PLC_OutPut[23]==1)//����-
		{
			Yuyin[2]--;
			if(Yuyin[2]<1)
			{
				Yuyin[2]=1;
			}
			W25QXX_Write_16(Yuyin,91,4);		//����ǰ��������д�뵽flash��
			yusu(Yuyin[2]);//����ѡ��
		}
		//���ѡ��
		else if(PLC_OutPut[20]==1)//���+
		{
			Yuyin[3]++;
			if(Yuyin[3]>9)
			{
				Yuyin[3]=9;
			}
			W25QXX_Write_16(Yuyin,91,4);		//����ǰ��������д�뵽flash��
			yudiao(Yuyin[3]);//���ѡ��
		}
		else if(PLC_OutPut[21]==1)//���-
		{
			Yuyin[3]--;
			if(Yuyin[3]<1)
			{
				Yuyin[3]=1;
			}
			W25QXX_Write_16(Yuyin,91,4);		//����ǰ��������д�뵽flash��
			yudiao(Yuyin[3]);//���ѡ��
		}
		

		switch(yuyin_flag)
		{
			case 0:break;
			case 1:
				{
					yuyin_flag=0;
					speek("�Զ�");
					//osdelay_s(1);
					break;
				}
			case 2:
				{
					yuyin_flag=0;
					speek("�ֶ�");
					//osdelay_s(1);
					break;
				}
			case 3:
				{
					yuyin_flag=0;
					speek("ǰ��");
					//osdelay_s(2);
					break;
				}
			case 4:
				{
					yuyin_flag=0;
					speek("������");
					//osdelay_s(2);
					break;
				}
			case 5:
				{
					yuyin_flag=0;
					speek("������");
					//osdelay_s(2);
					break;
				}
			case 6:
				{
					yuyin_flag=0;
					speek("ֹͣ");
					//osdelay_s(1);
					break;
				}
			case 7:
				{
					yuyin_flag=0;
					speek("����");
					//osdelay_s(1);
					break;
				}
			case 8:
				{
					yuyin_flag=0;
					speek("��ֲ�");
					//osdelay_s(2);
					break;
				}
			case 9:
				{
					yuyin_flag=0;
					speek("�зֲ�");
					//osdelay_s(2);
					break;
				}
			case 10:
				{
					yuyin_flag=0;
					speek("�ҷֲ�");
					//osdelay_s(2);
					break;
				}
			case 11:
				{
					yuyin_flag=0;
					speek("�������");
					//osdelay_s(2);
					break;
				}
			case 12:
				{
					yuyin_flag=0;
					speek("����½�");
					//osdelay_s(2);
					break;
				}
			case 13:
			{
				yuyin_flag=0;
				speek("ң��ǰ��");
				break;
			}
			case 14:
			{
				yuyin_flag=0;
				speek("ң�غ���");
				break;
			}
			case 15:
			{
				yuyin_flag=0;
				speek("ǰ�����ϰ��������");
				break;
			}
			case 16:
			{
				yuyin_flag=0;
				speek("�ϰ������");
				break;
			}
			case 17:
			{
				yuyin_flag=0;
				speek("ǰ�����ϰ�����С�ļ�ʻ");
				break;
			}
			case 18:
			{
				yuyin_flag=0;
				speek("��λok");
				break;
			}
			case 19:
			{
				yuyin_flag=0;
				speek("ȥһ¥");
				break;
			}
			case 20:
			{
				yuyin_flag=0;
				speek("��ת");
				break;
			}
			case 21:
			{
				yuyin_flag=0;
				speek("��ת");
				break;
			}
			
		}

		osdelay_ms(20);
	}
}

//Cansend������������չ���ͨ��
void Cansend_task(void *p_arg)
{
	p_arg = p_arg;
	
	while(1)
	{
		CanSend();
		osdelay_ms(20);
	}
}

//RunLED������������ϵͳ����ָʾ��
void RunLED_task(void *p_arg)
{
	p_arg = p_arg;
	while(1)
	{
		LED1=1;							//��Ƭ������ָʾ
		PLC_OutPut[1]=1;		//��Ļ����ָʾ
		osdelay_ms(300);
		LED1=0;
		PLC_OutPut[1]=0;
		osdelay_ms(300);
	}
}

//RFID��������ɨ���ر���������һ��
void RFID_task(void *p_arg)
{
	p_arg = p_arg;
	
	while(1)
	{
		if(BEEP_flag==1)
		{
			BEEP=1;
			osdelay_ms(50);
			BEEP=0;
			BEEP_flag=0;
		}
		osdelay_ms(20);
	}
}


//YAOKONG��������ң�ؿ��Ʋ泵ʱ�������
void YAOKONG_task(void *p_arg)
{
	u8 last_MAIN=0,last_FRONT=0,last_BACK=0,last_LIFT=0,last_RIGHT=0,last_UP=0,last_DOWN=0;
	u8 TZ_flag=0,LIFT_flag=0,RIGHT_flag=0;
	u16 deg_num=597;//��ת�Ƕȱ任	������579
	u16 speed_num=500;//
	
	u8 ykqbz_flag=0,ykhbz_flag=0;
	
	p_arg = p_arg;                        
	                                      
	while(1)                              
	{  		
		if(HmiTask==0)
		{
			if(Mode_flag==1)                    
			{                                   
				if(last_MAIN==0&&MAIN==1)//��ң���ϵļ�ͣ����ʱ
				{
					Ting_Zhi();
				}
				if(START==0&&QD_flag==0)//��ң�����ϰ�����������
				{
					Qi_Dong();
				}
				if(QD_flag==0)//���Զ�ֹͣ״̬ʱң�ز�����
				{
					if(FRONT==1&&BACK==1&&TZ_flag==0)
					{
						tingzhi();
						TZ_flag=1;
					}
					else if(last_FRONT==1&&FRONT==0)//ң��ǰ��
					{
						qianjin();
						yuyin_flag=13;
						TZ_flag=0;
					}
					else if(last_BACK==1&&BACK==0)//ң�غ���
					{
						houtui();
						yuyin_flag=14;
						TZ_flag=0;
					}
					else 
					{
						;
					}	
					
					if(LIFT==0)//��ת
					{
						if(LIFT_flag==0)
						{
							jiejin();
							LIFT_flag=1;
						}
						
						deg_num-=2;
						if(deg_num<2)
						{
							deg_num=2;
						}	
						PWM_val(TIM4,4,deg_num);	//����PWM
						if(deg_num<400)
						{
							speed_num+=2;
							if(speed_num>950)
							{
								speed_num=950;
							}	
							PWM_val(TIM4,2,speed_num);//�趨�ٶ�PWM
						}
					}
					else if(RIGHT==0)//��ת
					{
						if(RIGHT_flag==0)
						{
							jiejin();
							RIGHT_flag=1;
						}
						deg_num+=2;
						if(deg_num>998)
						{
							deg_num=998;
						}
						PWM_val(TIM4,4,deg_num);	//����PWM
						if(deg_num>700)
						{
							speed_num+=2;
							if(speed_num>950)
							{
								speed_num=950;
							}
							PWM_val(TIM4,2,speed_num);//�趨�ٶ�PWM
						}
					}
					else//����
					{
						if(PLC_Data[12]>400&&PLC_Data[12]<800)
						{
							deg_num=PLC_Data[12];
						}
						else
						{
							deg_num=597;
						}
						speed_num=500;
						PWM_val(TIM4,4,deg_num);	//����PWM
						PWM_val(TIM4,2,speed_num);//�趨�ٶ�PWM
					}
					
					///////////////ң�ر��ϴ���ʼ//////////////////////
					if(FRONT==0)				
					{                   
						if(QBZ2N==0||QBZ2F==0||JXBZ==1)   
						{
								if(ykqbz_flag==0)
								{
									bztingzhi();					
									ykqbz_flag=1;
									yuyin_flag=17;
								}
						}	
						else	
						{
								if(ykqbz_flag==1)//�Ӵ�����������ʱִֻ��һ��
								{
									bzqianjin();
									ykqbz_flag=0;
									yuyin_flag=16;
								}
						}							
					}                  
					else if(BACK==0)    
					{                   
						 if(CBBZ1==0||CBBZ2==0)  
						 {
								if(ykhbz_flag==0)
								{
									bztingzhi();					
									ykhbz_flag=1;
									yuyin_flag=17;
								}
						 }
						 else	
						 {
								if(ykhbz_flag==1)
								{
									bzhoutui();
									ykhbz_flag=0;
									yuyin_flag=16;
								}
						 }
							 
					}
					else
					{
						ykqbz_flag=0,ykhbz_flag=0;
					}
					///////////////ң�ر��ϴ������/////////////////	
						
						
					if(last_LIFT==0&&LIFT==1)//�����ɿ�ʱ���ӽ����ؿ������ر�־��0
					{
						LIFT_flag=0;
					}
					else if(last_RIGHT==0&&RIGHT==1)//�����ɿ�ʱ���ӽ����ؿ������ر�־��0
					{
						RIGHT_flag=0;
					}
					else 
					{
						;
					}
				}
				
			}
			if(last_UP==1&&UP==0)
			{
				CBX=1;					//�رղ���½��ļ̵���
				osdelay_ms(50);
				CBS=0;					//�򿪲�������ļ̵���
				yuyin_flag=11;
			}
			else if(last_UP==0&&UP==1)
			{
				CBS=1;
				CBX=1;
			}
			if(last_DOWN==1&&DOWN==0)
			{
				CBS=1;					//�رղ�������ļ̵���			
				osdelay_ms(50);
				CBX=0;					//�򿪲���½��ļ̵���
				yuyin_flag=12;
			}
			else if(last_DOWN==0&&DOWN==1)
			{
				CBX=1;
				CBS=1;
			}
			last_MAIN=MAIN,last_FRONT=FRONT,last_BACK=BACK,last_LIFT=LIFT,last_RIGHT=RIGHT,last_UP=UP,last_DOWN=DOWN;
		}
		osdelay_ms(20);
	}
}


void AGV_QuYiLou()//AGVȥһ¥����
{	
		//��ͣ���������е��ݵ���¥���ȵ��ݵ���¥�����ſ���λ�ٽ����ݣ�AGV����λ�����õ�����һ¥��һ¥������ӣ�����һ¥��ȵ���ȫ����ʱ��ʻ
		Ting_Zhi();							
		PLC2_Data[18]=0;//��¥�����ť
		while(PLC2_Data[24]!=0)//��¥ƽ�㣨��������¥����0:��������¥ 1:���ݲ�����¥��
		{
			osdelay_ms(20);
		}
		PLC2_Data[22]=10;				//�����źŸ�ֵΪ10�Ա����ϵͳȷ���ų���
		while(PLC2_Data[26]!=1) //�ȴ���¥�ſ���λ ��¥��״̬����1/��0��
		{
			osdelay_ms(20);
		}
		Qian_Jin();
		osdelay_ms(SPEEKTIME);
		Qi_Dong();
		ture_numL=0;//�������ͻ�����
		ture_numR=0;//����Ҳ��ͻ�����
		//�ȴ��泵AGV�����ݵ�λ���������ֵ�λģʽ���ر�3������ͻ����Ҳ��ͻ�䣩
		while(keynumber!=HmiDianTiDiBiao3&&ture_numL<1&&ture_numR<1)
		{
			osdelay_ms(20);
		}
		osdelay_ms(500);
		HmiRfidNum = HmiDianTiDiBiao1;
		Ting_Zhi();							//ֹͣ
		PLC2_Data[22]=1;//�����ź���1�Ա�����Ų��ǳ���״̬
		PLC2_Data[23]=0;//����
		PLC2_Data[19]=0;//һ¥�����ť
		while(PLC2_Data[25]!=0)//һ¥ƽ�㣨������һ¥����0:������һ¥ 1:���ݲ���һ¥��
		{
			osdelay_ms(20);
		}
		PLC2_Data[22]=10;				//�����źŸ�ֵΪ10�Ա����ϵͳȷ���ų���
		while(PLC2_Data[27]!=1)//һ¥��״̬����1/��0��
		{
			osdelay_ms(20);
		}
		Qian_Jin();
		osdelay_ms(SPEEKTIME);
		Qi_Dong();
		osdelay_ms(SPEEKTIME);	

		while(keynumber!=HmiChuDianTiDiBiao)//��¥��״̬����1/��0��
		{	
			osdelay_ms(20);
		}
		HmiRfidNum = HmiDianTiDiBiao1;
		PLC2_Data[22]=1;//�����ź���1�Ա�����Ų��ǳ���״̬
		PLC2_Data[23]=0;//����	
}


void AGV_QuSanLou()//AGVȥ��¥����
{
		//��ͣ���������е��ݵ�һ¥���ȵ��ݵ�һ¥�����ſ���λ�ٽ����ݣ�AGV����λ�����õ���ȥ��¥����¥������ӣ�������¥��ȵ���ȫ����ʱ��ʻ
		Ting_Zhi();							
		PLC2_Data[19]=0;//һ¥�����ť
		while(PLC2_Data[25]!=0)//һ¥ƽ�㣨������һ¥����0:������һ¥ 1:���ݲ���һ¥��
		{
			osdelay_ms(20);
		}
		PLC2_Data[22]=10;				//���� �źŸ�ֵΪ10�Ա����ϵͳȷ���ų���
		while(PLC2_Data[27]!=1) //�ȴ�һ¥�ſ���λ һ¥��״̬����1/��0��
		{
			osdelay_ms(20);
		}
		Qian_Jin();
		osdelay_ms(SPEEKTIME);
		Qi_Dong();
		ture_numL=0;//�������ͻ�����
		ture_numR=0;//����Ҳ��ͻ�����
		//�ȴ��泵AGV�����ݵ�λ���������ֵ�λģʽ���ر�3������ͻ����Ҳ��ͻ�䣩
		while(keynumber!=HmiDianTiDiBiao1&&ture_numL<3&&ture_numR<3)
		{
			osdelay_ms(20);
		}
		osdelay_ms(500);
		HmiRfidNum = HmiDianTiDiBiao1;
		Ting_Zhi();							//ֹͣ
		PLC2_Data[22]=1;//�����ź���1�Ա�����Ų��ǳ���״̬
		PLC2_Data[18]=0;//��¥�����ť		
		PLC2_Data[23]=0;//����

		while(PLC2_Data[24]!=0)//��¥ƽ�㣨��������¥����0:��������¥ 1:���ݲ�����¥��
		{
			osdelay_ms(20);
		}
		PLC2_Data[22]=10;				//�����źŸ�ֵΪ10�Ա����ϵͳȷ���ų���
		while(PLC2_Data[26]!=1)//��¥��״̬����1/��0��
		{
			osdelay_ms(20);
		}
		Qian_Jin();
		osdelay_ms(SPEEKTIME);
		Qi_Dong();
		osdelay_ms(SPEEKTIME);
		while(keynumber!=HmiChuDianTiDiBiao)//��¥��״̬����1/��0��
		{	
			osdelay_ms(20);
		}
		HmiRfidNum = HmiDianTiDiBiao1;
		PLC2_Data[22]=1;//�����ź���1�Ա�����Ų��ǳ���״̬
		PLC2_Data[23]=0;//����		
}





//ִ��վ�㶯��
void StationAction(u16 num)
{
	u16 RfidNum = 0;//��⵽��RFID��
	//�������Զ�
	while(QD_flag != 1 || Mode_flag != 1)
	{
		osdelay_ms(20);
	}
	
	HmiStationSerialNum++;
	//��յر�
	keynumber=0;
	ture_numL = 0;
	ture_numR = 0;
	ture_numF = 0;
	
	//Ŀ��ر���ʾ
	HmiNextRfidNum = NowRouteInfor[num][5];
	
	//�ȴ�Ŀ��ر�
	while(RfidNum!=NowRouteInfor[num][5])	//ɨ���ر꣬��Ŀ��ֵ�Ļ�������while
	{				
		if(Mode_flag == 1)//�Զ�ģʽ�¼��ر꣬�ֶ�ģʽ�²����ر�
		{
			if(keynumber!=0)
			{
				RfidNum = keynumber;
				//������ٶȵر�,�����ٶ�
				if(keynumber == 4)//����
				{
					speed = HmiZhongSu;//�ٶȸ�ֵ,����
				}
				else
				if(keynumber == 5)//����
				{
					speed = HmiGaoSu;//�ٶȸ�ֵ,����
				}
				
				keynumber = 0;
			}
			
			//����ر���
			//��
			if(NowRouteInfor[num][12]&&ture_numL==NowRouteInfor[num][15])
			{
				RfidNum = NowRouteInfor[num][5];
			}
			//��
			if(NowRouteInfor[num][13]&&ture_numR==NowRouteInfor[num][16])
			{
				RfidNum = NowRouteInfor[num][5];
			}
			//ǰ
			if(NowRouteInfor[num][14]&&ture_numF==NowRouteInfor[num][17])
			{
				RfidNum = NowRouteInfor[num][5];
			}		
		}

		osdelay_ms(20);	
	}

	HmiRfidNum = keynumber;
	switch(NowRouteInfor[num][6])//ֹͣ��ǰ���������󡢺����ҡ�����������	
	{
		case 0:	break;//�����ϴ���Ϣ
		case 1://ֹͣ
		case 2://ǰ��
		case 3://������
		case 4://������
		case 6://����
		case 7://����						
		{
			Ting_Zhi();
			osdelay_ms(SPEEKTIME);
		}break;	
		case 5:break;//ͨ��				
	}			
	switch(NowRouteInfor[num][4])//�ٶȵ�λ�ж�
	{
		case 0:	break;//�����ϴ���Ϣ
		case 1://����
		{
			speek("1��");
			speed=HmiDiSu;
			osdelay_ms(SPEEKTIME);
		}break;					
		case 2://����
		{
			speek("2��");
			speed=HmiZhongSu;
			osdelay_ms(SPEEKTIME);
		}break;				
		case 3://����
		{
			speek("3��");
			speed=HmiGaoSu;
			osdelay_ms(SPEEKTIME);						
		}break;					
	}
	switch(NowRouteInfor[num][0])//Զ���⿪���ж�
	{
		case 0:	break;//�����ϴ���Ϣ
		case 1://Զ���⿪
		{
			QBZ_Yflag=0;
			speek("Զ��");	
			osdelay_ms(SPEEKTIME);						
		}break;					
		case 2://Զ�����
		{
			QBZ_Yflag=1;
			speek("Զ��");
			osdelay_ms(SPEEKTIME);						
		}break;							
	}				
	switch(NowRouteInfor[num][1])//�����⿪���ж�
	{
		case 0:	break;//�����ϴ���Ϣ
		case 1://�����⿪
		{
			QBZ_Jflag=0;
			speek("����");
			osdelay_ms(SPEEKTIME);						
		}break;					
		case 2://�������
		{
			QBZ_Jflag=1;
			speek("����");
			osdelay_ms(SPEEKTIME);						
		}break;								
	}

	switch(NowRouteInfor[num][19])//��ۺ��⿪���ж�
	{
		case 0:	break;//�����ϴ���Ϣ
		case 1://��
		{
			HBZ_flag = 0;
			speek("��");
			osdelay_ms(SPEEKTIME);						
		}break;					
		case 2://��
		{
			HBZ_flag=1;
			speek("���");
			osdelay_ms(SPEEKTIME);						
		}break;								
	}	
	
	switch(NowRouteInfor[num][2])//�ֲ��ж�
	{
		case 0:	break;//�����ϴ���Ϣ
		case 1://��ֲ�
		{
			Zuo_Fen();
			osdelay_ms(SPEEKTIME);						
		}break;	
		case 2://�ҷֲ�
		{
			You_Fen();
			osdelay_ms(SPEEKTIME);						
		}break;			
	}
	
	
	switch(NowRouteInfor[num][3])//��������ж�
	{
		case 0:	break;//�����ϴ���Ϣ
		case 1://�������
		{
			Cha_Sheng();	
		}break;	
		case 2://����½�
		{
			Cha_Jiang();
		}break;			
									
	}

	
	//�ж��Ƿ���Ҫ��ʱ
	if(NowRouteInfor[num][8]!=0)
		osdelay_s(NowRouteInfor[num][8]);
	
	switch(NowRouteInfor[num][11])//���е���豸ͨ��
	{
		case 0:	
			//û���������
			PLC2_Data[32] = 0;
			break;//û�����豸����
		case 1://��һ���豸����
		{
			//���豸������������ź�
			PLC2_Data[32] = NowRouteInfor[num][11];
			Ting_Zhi();
			osdelay_ms(SPEEKTIME);
			speek("�������");
			osdelay_s(1);
			//�ȴ�׼���ź�
			while(PLC2_Data[33]!=1)
			{
				osdelay_ms(10);
			}
			speek("�������");
			osdelay_s(1);
			
			Qi_Dong();
			
			//�����������ź�			
			PLC2_Data[32] = 0;
			//���׼���ź�
			PLC2_Data[33] = 0;
		}break;					
		case 2://�Ͷ����豸����
		{
			//���豸������������ź�
			PLC2_Data[32] = NowRouteInfor[num][11];
			speek("�������");
			osdelay_s(1);
			//�ȴ�׼���ź�
			while(PLC2_Data[34]!=1)
			{
				osdelay_ms(10);
			}
			speek("�������");
			osdelay_s(1);			
			
			Qi_Dong();
			
			//�����������ź�			
			PLC2_Data[32] = 0;			
			//���׼���ź�
			PLC2_Data[34] = 0;
		}break;			
		case 3://�������豸����
		{
			//���豸������������ź�
			PLC2_Data[32] = NowRouteInfor[num][11];
			speek("�������");
			osdelay_s(1);
			//�ȴ�׼���ź�
			while(PLC2_Data[35]!=1)
			{
				osdelay_ms(10);
			}
			speek("�������");
			osdelay_s(1);
			
			Qi_Dong();
			
			//�����������ź�			
			PLC2_Data[32] = 0;	
			//���׼���ź�
			PLC2_Data[35] = 0;
		}break;			
		case 4://���ĺ��豸����
		{
			//���豸������������ź�
			PLC2_Data[32] = NowRouteInfor[num][11];
			speek("�������");
			osdelay_s(1);
			//�ȴ�׼���ź�
			while(PLC2_Data[36]!=1)
			{
				osdelay_ms(10);
			}
			speek("�������");
			osdelay_s(1);
			
			Qi_Dong();
			
			//�����������ź�			
			PLC2_Data[32] = 0;			
			//���׼���ź�
			PLC2_Data[36] = 0;
		}break;		
	}
	
	switch(NowRouteInfor[num][7])//�����豸������
	{
		case 0:
			PLC2_Data[38] = 0;	
			PLC2_Data[39] = 0;	
			PLC2_Data[40] = 0;	
			PLC2_Data[41] = 0;		
			break;
		case 1:
			PLC2_Data[38] = 1;	
		break;		
		case 2:
			PLC2_Data[39] = 1;	
			break;		
		case 3:
			PLC2_Data[40] = 1;	
			break;		
		case 4:
			PLC2_Data[41] = 1;	
			break;	
	}
	
	switch(NowRouteInfor[num][18])//�豸��AGV���͵������ź�
	{
		case 0://���ȴ�	
			break;
		case 1://�ȴ�һ���豸
			while(PLC2_Data[42]==0)
			{
				osdelay_ms(10);
			}	
		break;		
		case 2://�ȴ������豸
			while(PLC2_Data[43]==0)
			{
				osdelay_ms(10);
			}
			break;		
		case 3://�ȴ������豸
			while(PLC2_Data[44]==0)
			{
				osdelay_ms(10);
			}
			break;		
		case 4://�ȴ��ĺ��豸
			while(PLC2_Data[45]==0)
			{
				osdelay_ms(10);
			}
			break;	
	}
	
	
	//AGV�Ե��ݵ�ʹ�����
	switch(NowRouteInfor[num][10])
	{
		case 0:	break;//���ݲ�ʹ��
		case 1://AGVȥһ¥
		{
			AGV_QuYiLou();
		}break;				
		case 2://AGVȥ��¥
		{
			AGV_QuSanLou();
		}break;	
	}

	switch(NowRouteInfor[num][6])//����ִ�����ж�	
	{
			case 0:	break;//�����ϴ���Ϣ
			case 1: break;//ֹͣ
			case 2://ǰ��
			{
				Qian_Jin();
				osdelay_ms(SPEEKTIME);
				Qi_Dong();
				osdelay_ms(SPEEKTIME);
			}break;	
			case 3://������
			{
				Hou_Zuo();
				osdelay_ms(SPEEKTIME);
				Qi_Dong();
				osdelay_ms(SPEEKTIME);
			}break;
			case 4://������
			{
				Hou_You();
				osdelay_ms(SPEEKTIME);
				Qi_Dong();
				osdelay_ms(SPEEKTIME);
			}break;
			case 6://����
			{
				Xuan_Zhuang_Ci_Shu = NowRouteInfor[num][9];
				last_flag=FX_flag;
				osdelay_ms(SPEEKTIME);
				QD_flag=1;
				//��ת����
				if(NowRouteInfor[num][18]==0)//����
				{
					zuoxuan(last_flag);
				}
				else
				{
					zuoxuan(NowRouteInfor[num][18]);
				}
			}break;
			case 7://����
			{
				Xuan_Zhuang_Ci_Shu = NowRouteInfor[num][9];
				last_flag=FX_flag;
				osdelay_ms(SPEEKTIME);
				QD_flag=1;
				//��ת����
				if(NowRouteInfor[num][18]==0)//����
				{
					youxuan(last_flag);
				}
				else
				{
					youxuan(NowRouteInfor[num][18]);
				}
			}break;
		}
	}
	

//�л�����Ϊǰ��
void go()
{
//	FX_flag=1;//ǰ��
	QBZ_Yflag=0;//��Զ����
	FC_flag = 2;//�ҷֲ�
	speed = HmiZhongSu;
}

//ִ������
void Task5_task(void *p_arg)
{	
	u16 i,j,k;
	p_arg = p_arg;

	while(1)
	{
		if(Mode_flag == 1&&QD_flag==1)//�Զ�ģʽ��������
		{
			//ִ��·��
			if(HmiTask==1)
			{
				go();
				
				//�����ǰ�ر�
				HmiRfidNum = 0;
				HmiStationSerialNum = 0;
				//������ѡ·����ִ����Ӧ����
				for(i=0;i<HmiStationNum;i++)
				{
					StationAction(i);
				}
				HmiTask = 0;
				
				//����������
				PLC2_Data[32] = 0;
				//����豸���ź�
				PLC2_Data[38] = 0;	
				PLC2_Data[39] = 0;	
				PLC2_Data[40] = 0;	
				PLC2_Data[41] = 0;
			}
			else
			{
				//ִ������
				if(HmiTask == 2)
				{
					go();
					//�����ǰ�ر�
					HmiRfidNum = 0;
					HmiProcessSerialNum = 0;
					for(i=0;i<HmiStepNum;i++)
					{
						HmiProcessSerialNum++;
						switch(NowProcessInfor[i][1])
						{
							case 0://����ִ��
								//����·����
								HmiRouteNum = NowProcessInfor[i][0];
							  //��ȡ·������վ����
								GetRouteStationNum(HmiRouteNum);
								//��ȡ��ǰ·����Ϣ
								GetRouteData(HmiRouteNum);

  							HmiStationSerialNum = 0;
								//������ѡ·����ִ����Ӧ����
								for(j=0;j<HmiStationNum;j++)
								{
									StationAction(j);
								}
								break;
							case 1://˳��ִ��
								for(k=NowProcessInfor[i][0];k<=NowProcessInfor[i][2];k++)
								{
									//����·����
									HmiRouteNum = k;
									//��ȡ·������վ����
									GetRouteStationNum(HmiRouteNum);
									//��ȡ��ǰ·����Ϣ
									GetRouteData(HmiRouteNum);
									
									HmiStationSerialNum = 0;
									//������ѡ·����ִ����Ӧ����
									for(j=0;j<HmiStationNum;j++)
									{
										StationAction(j);
									}
								}
								break;
							case 2://����ִ��
								for(k=NowProcessInfor[i][0];k>=NowProcessInfor[i][2];k--)
								{
									//����·����
									HmiRouteNum = k;
									//��ȡ·������վ����
									GetRouteStationNum(HmiRouteNum);
									//��ȡ��ǰ·����Ϣ
									GetRouteData(HmiRouteNum);
  
									HmiStationSerialNum = 0;
 									//������ѡ·����ִ����Ӧ����
									for(j=0;j<HmiStationNum;j++)
									{
										StationAction(j);
									}
								}
								break;
							case 3://ѭ��ִ��
								//����·����
								HmiRouteNum = NowProcessInfor[i][0];
							  //��ȡ·������վ����
								GetRouteStationNum(HmiRouteNum);
								//��ȡ��ǰ·����Ϣ
								GetRouteData(HmiRouteNum);
								for(k=0;k<NowProcessInfor[i][2];k++)
								{
    							HmiStationSerialNum = 0;
									//������ѡ·����ִ����Ӧ����
									for(j=0;j<HmiStationNum;j++)
									{
										StationAction(j);
									}
								}
								break;
							default:break;
						}
					}
					HmiTask = 0;
					//����������
					PLC2_Data[32] = 0;
					//����豸���ź�
					PLC2_Data[38] = 0;	
					PLC2_Data[39] = 0;	
					PLC2_Data[40] = 0;	
					PLC2_Data[41] = 0;
					
					if(lastscreenNum!=0)
					{
						HmiScreenSetGet = lastscreenNum;
						lastscreenNum = 0;
					}
				}	
			}				
		}
		osdelay_ms(10);
	}
}

void UserConfigInit(void)
{
	//��ȡ����ϵͳ����
	GetAllParameterFromSystem();

	if(SystemParameter[0]!=6)//�״�flash��û����ʱ��ˢ���ʼ��
	{
		#if 1						//Ϊǰ100���ڴ���д���ʼ��
		SystemParameter[0]=6;	//�ж��Ƿ��һ��д��ı�־
		SystemParameter[1]=0;
		SystemParameter[2]=0;
		SystemParameter[3]=0;
		SystemParameter[4]=5;//�����Ƕ�
		SystemParameter[5]=5;//�����Ƕ�
		SystemParameter[6]=400;		//��ʼ�ٶ�
		SystemParameter[7]=0;     
		SystemParameter[8]=15;    //ǰ������Kp
		SystemParameter[9]=300;   //ǰ������Ki
		SystemParameter[10]=0;    //ǰ������Kd
		SystemParameter[11]=10;   //ǰ�������PID��������
		SystemParameter[12]=579;  //�泵�Ķ�����ֵ
		SystemParameter[13]=0;    //���Kp
		SystemParameter[14]=0;    //���Ki
		SystemParameter[15]=0;    //���Kd
		SystemParameter[16]=0;    
		SystemParameter[17]=0;    
		SystemParameter[18]=250; //����    
		SystemParameter[19]=340; //����   
		SystemParameter[20]=400; //����   
		SystemParameter[21]=0;    
		SystemParameter[22]=0;    
		SystemParameter[23]=0;    
		SystemParameter[24]=1;  //·����
		SystemParameter[25]=1;  //���̺�  
		SystemParameter[26]=0;  //�����  
		SystemParameter[27]=1;  //���ݵر�1 
		SystemParameter[28]=3;  //���ݵر�3  
		SystemParameter[29]=2;  //�����ݵر�
		SystemParameter[30]=0;    
		SystemParameter[31]=0;    
		SystemParameter[32]=0;    
		SystemParameter[33]=0;    
		SystemParameter[34]=0;    
		SystemParameter[35]=0;    
		SystemParameter[36]=0;    
		SystemParameter[37]=0;    
		SystemParameter[38]=0;    
		SystemParameter[39]=0;    
		SystemParameter[40]=0;    
		SystemParameter[41]=0;    
		SystemParameter[42]=0;    
		SystemParameter[43]=0;    
		SystemParameter[44]=0;    
		SystemParameter[45]=0;    
		SystemParameter[46]=0;    
		SystemParameter[47]=0;    
		SystemParameter[48]=0;    
		SystemParameter[49]=0;    
		SystemParameter[50]=0;    
		SystemParameter[51]=0;    
		SystemParameter[52]=1;//�泵��    
		SystemParameter[53]=0;    
		SystemParameter[54]=0;    
		SystemParameter[55]=0;    
		SystemParameter[56]=0;    
		SystemParameter[57]=0;    
		SystemParameter[58]=0;    
		SystemParameter[59]=2;    //�������ʱ��
		
		SystemParameter[60]=40;   //��۷���Ŀ���ϵ��
		SystemParameter[61]=45;   //��۷���Ŀ���ϵ��
		SystemParameter[62]=50;   //��۷���Ŀ���ϵ��
		SystemParameter[63]=60;   //��۷���Ŀ���ϵ��
		SystemParameter[64]=65;   //��۷���Ŀ���ϵ��
		SystemParameter[65]=80;   //��۷���Ŀ���ϵ��
		SystemParameter[66]=95;   //��۷���Ŀ���ϵ��
		SystemParameter[67]=100;  //��۷���Ŀ���ϵ��
		SystemParameter[68]=105;  //��۷���Ŀ���ϵ��
		SystemParameter[69]=120;  //��۷���Ŀ���ϵ��
		SystemParameter[70]=135;  //��۷���Ŀ���ϵ��
		SystemParameter[71]=140;  //��۷���Ŀ���ϵ��
		SystemParameter[72]=150;  //��۷���Ŀ���ϵ��
		SystemParameter[73]=155;  //��۷���Ŀ���ϵ��
		SystemParameter[74]=160;  //��۷���Ŀ���ϵ��
		SystemParameter[75]=55;   //��۷���Ŀ���ϵ��
		SystemParameter[76]=145;  //��۷���Ŀ���ϵ��
		SystemParameter[77]=0;
		SystemParameter[78]=0;
		SystemParameter[79]=0;
		SystemParameter[80]=0;
		SystemParameter[81]=0;
		SystemParameter[82]=0;
		SystemParameter[83]=0;
		SystemParameter[84]=0;
		SystemParameter[85]=0;
		SystemParameter[86]=0;
		SystemParameter[87]=0;
		SystemParameter[88]=0;
		SystemParameter[89]=0;
		#endif	          
		
		//�洢����ϵͳ����
		SetAllParameterToSystem();
		
		//���·������վ����
		memset(RouteStationNum,0,RouteNum);
		//��������·��������վ����
		SetAllStationNum();
		
		//������̰�������
		memset(ProcessStepNum,0,ProcessNum);
		//�����������̰����Ĳ���
		SetAllStepNum();
	}
	
	
	
	STATIONNUM_170M = PLC_Data[52]= SystemParameter[52];//�泵��
	STATIONNUM_170M+=1;
	
	PLC_Data[60]= SystemParameter[60];		//��۷���ĵ���ϵ��
	PLC_Data[61]= SystemParameter[61];    //��۷���ĵ���ϵ��
	PLC_Data[62]= SystemParameter[62];    //��۷���ĵ���ϵ��
	PLC_Data[63]=	SystemParameter[63];    //��۷���ĵ���ϵ��
	PLC_Data[64]=	SystemParameter[64];    //��۷���ĵ���ϵ��
	PLC_Data[65]=	SystemParameter[65];    //��۷���ĵ���ϵ��
	PLC_Data[66]= SystemParameter[66];    //��۷���ĵ���ϵ��
	PLC_Data[67]= SystemParameter[67];    //��۷���ĵ���ϵ��
	PLC_Data[68]= SystemParameter[68];    //��۷���ĵ���ϵ��
	PLC_Data[69]=	SystemParameter[69];    //��۷���ĵ���ϵ��
	PLC_Data[70]=	SystemParameter[70];    //��۷���ĵ���ϵ��
	PLC_Data[71]=	SystemParameter[71];    //��۷���ĵ���ϵ��
	PLC_Data[72]= SystemParameter[72];    //��۷���ĵ���ϵ��
	PLC_Data[73]= SystemParameter[73];    //��۷���ĵ���ϵ��
	PLC_Data[74]= SystemParameter[74];    //��۷���ĵ���ϵ��
	PLC_Data[75]= SystemParameter[75];    //��۷���ĵ���ϵ��
	PLC_Data[76]= SystemParameter[76];    //��۷���ĵ���ϵ��
			
	
	PID.Kp = PLC_Data[8]	=	SystemParameter[8];			//��ʼ����Ļ��PID����kp
	PID.Ki = PLC_Data[9] = SystemParameter[9];     //��ʼ����Ļ��PID����ki
	PID.Kd = PLC_Data[10]= SystemParameter[10];    //��ʼ����Ļ��PID����kd
	                               
	PID4.Kp = PLC_Data[13]=	SystemParameter[13];		//��ʼ����Ļ��PID4����kp��ŵ��� 
	PID4.Ki = PLC_Data[14]= SystemParameter[14];    //��ʼ����Ļ��PID4����ki��ŵ��� 
	PID4.Kd = PLC_Data[15]= SystemParameter[15];    //��ʼ����Ļ��PID4����kd��ŵ���	 
	                               	
	PLC_Data[6] =	SystemParameter[6];     //������Ļ���ٶ���ʾֵ
	PLC_Data[11] = SystemParameter[11];		//����ǰ����PID��������
	
	HmiDiSu    = SystemParameter[18];		//һ���ٶ� 
	HmiZhongSu = SystemParameter[19];   //�����ٶ�
	HmiGaoSu   = SystemParameter[20];   //�����ٶ�
	
	HmiRouteNum   = SystemParameter[24]; //·����
	HmiProcessNum = SystemParameter[25]; //���̺�
//	HmiTask       = SystemParameter[26]; //�����
	HmiTask  = 0;
	
	HmiDianTiDiBiao1   =	SystemParameter[27];  //���ݵر�1 
	HmiDianTiDiBiao3   =	SystemParameter[28];  //���ݵر�3  
	HmiChuDianTiDiBiao =	SystemParameter[29];  //�����ݵر�
	
	PLC_Data[12] = SystemParameter[12]; //�����ֵ
	
	PLC_Data[59] = SystemParameter[59];//�������ʱ��
	
	//�����Զ�������Ϣ
	HmiAutoReload();
	  
	speed=PLC_Data[6]; 								//������Ļ���ٶ���ʾֵ
//	PWM_val(TIM4,2,speed);				 	//�趨�ٶ�PWM��ֵ����
	time=PLC_Data[11];			       		//����ǰ����PID��������
	
	low_speed 	 = HmiDiSu ;	 				//һ���ٶ� 
	middle_speed = HmiZhongSu ;				//�����ٶ�
	high_speed	 = HmiGaoSu ;  				//�����ٶ�
	
	PLC_Data[98] =	SystemParameter[4];//�����Ƕ�
	PLC_Data[99] =	SystemParameter[5];//�����Ƕ�
	//��ȡ·������վ����
	GetRouteStationNum(HmiRouteNum);

	//��ȡ��ǰ·����Ϣ
	GetRouteData(HmiRouteNum);
		
	//��ȡ��������������
	GetProcessData();
}


//ִ������
void ActiveProcess()
{
	//�������̺�
	SetOneParameterToSystem(HmiProcessNum,25);
	SystemParameter[26] = HmiTask;
	//���������
	SetOneParameterToSystem(HmiTask,26);
	
	//����״̬Ϊ��������
	HmiTaskState = 5;

	HmiTask = 2;
	
	//�����Զ�������Ϣ
	HmiAutoReload();
		
	
	FX_flag=1;//�����л���ǰ��
	
	//��ת���Զ�����
	HmiScreenSetGet = ZiDongJieMian;
}

//��Ļ����
	u32 mima=0;
void Task6_task(void *p_arg)
{
	u16 i,j;
	OS_ERR err;
	p_arg = p_arg;
	UserConfigInit();		//�û�������ʼ��
	//���ݰ�ť��ʼ��
	PLC2_Data[18]=1;//��¥�����ť
	PLC2_Data[19]=1;//һ¥�����ť
	PLC2_Data[20]=1;//3��ť
	PLC2_Data[21]=1;//1��ť
	PLC2_Data[22]=1;//����
	PLC2_Data[23]=1;//����
	
	while(1)
	{	 	
		switch(HmiScreenSetGet)
		{
			case 9: //�ֶ����ƽ���Ĳ���
						{						
							while(HmiScreenSetGet == 9)
							{
								if(PLC_OutPut[4]==1)						//��Ļ���ֶ���������ʱ
								{
									Shou_Dong();		//�е��ֶ�����
								}
								else if(PLC_OutPut[5]==1)				//��Ļ���Զ���������ʱ
								{
									Zi_Dong();			//�е��Զ�����
								}
								else if(PLC_OutPut[9]==1)				//���������ť����ʱ
								{
									Cha_Sheng();
								} 
								else if(PLC_OutPut[10]==1)			//����½���ť����ʱ
								{
									Cha_Jiang();
								}
								else if(PLC_OutPut[13]==1)			//��ֲ水ť����ʱ
								{
									Zuo_Fen();
								}
								else if(PLC_OutPut[14]==1)			//�ҷֲ水ť����ʱ
								{
									You_Fen();
								}		

								if(Mode_flag == 1)
								{
									if(PLC_OutPut[11]==1)			//����
									{
										Qi_Dong();
									}
									if(PLC_OutPut[12]==1)		 	//ֹͣ
									{
										Ting_Zhi();
									}
									else if(PLC_OutPut[6]==1)	//�����ϵ�ǰ����ťȷ�����Ʋ泵����ʻ�����־FX_flag
									{
										Qian_Jin();
									}
									else if(PLC_OutPut[7]==1) //�����ϵĺ�����ťȷ�����Ʋ泵����ʻ�����־FX_flag
									{
										Hou_Zuo();
									}
									else if(PLC_OutPut[8]==1) //�����ϵĺ����Ұ�ťȷ�����Ʋ泵����ʻ�����־FX_flag
									{
										Hou_You();
									}	

								}
								/*********����Ļ�ϲ��������ı�ʱ��¼������flash��ʼ********/
								if(speed!=PLC_Data[6])
								{
									speed = PLC_Data[6];									//������Ļ���ٶ���ʾֵ
									Ruan_Qi(SPEED_min,speed);					//�趨�ٶ�PWM��ֵ����
																									
									SystemParameter[6] = speed;
									
									SetOneParameterToSystem(SystemParameter[6],6);
								}
								/*********����Ļ�ϲ��������ı�ʱ��¼������flash����********/
								
								osdelay_ms(10);
							}																
						}break;
			case 11://ϵͳ�������棬�ٶȵĵ�λ����
						{
							while(HmiScreenSetGet == 11)
							{
								low_speed 	 = HmiDiSu;	  //һ���ٶ� 
								middle_speed = HmiZhongSu; //�����ٶ�
								high_speed	 = HmiGaoSu;   //�����ٶ�
												
								SystemParameter[18] = HmiDiSu;
								SystemParameter[19] = HmiZhongSu;
								SystemParameter[20] = HmiGaoSu;
								
								//����
								STATIONNUM_170M = PLC_Data[52]+1;
								SystemParameter[52]=PLC_Data[52];

								//���ݵر�����
								SystemParameter[27] =	HmiDianTiDiBiao1  ;         //���ݵر�1 
								SystemParameter[28] =	HmiDianTiDiBiao3  ;         //���ݵر�3  
								SystemParameter[29] =	HmiChuDianTiDiBiao;         //�����ݵر�
								
								SystemParameter[4] =	PLC_Data[98];//�����Ƕ�
								SystemParameter[5] = PLC_Data[99];//�����Ƕ�
								
								SystemParameter[59] = PLC_Data[59];//�������ʱ��

								osdelay_ms(10);
							}
							
							W25QXX_Write_16(SystemParameter,0,SystemParaNum);	//����ǰ��Ļ����д�뵽flash��
						}break;
			case 13://������������״̬���µ���Ļ��
						{
							PLC_OutPut[25]=CBBZ2;	//��ۺ������2�����ۣ�
							PLC_OutPut[26]=CBJC2; //��ۻ��ﵽλ������2�����ۣ�
							PLC_OutPut[27]=CBBZ1; //��ۺ������1���Ҳ�ۣ�
							PLC_OutPut[28]=CBJC1; //��ۻ��ﵽλ������1���Ҳ�ۣ�
							PLC_OutPut[29]=QBZ2N; //�������2	:�����ϣ�ǰ���ϣ�
							PLC_OutPut[30]=QBZ2F; //�������2	:Զ���ϣ�ǰ���ϣ�
							PLC_OutPut[46]=JXBZ;  //��е����
						}break;
			case 14://���ݵ��Խ���(�ڳ��϶Ե��ݵ�һ�н��вٿغ���ʾ����״̬)
						{
								if(PLC_OutPut[31]==1)//��¥�����ť
								{
									PLC2_Data[18]=0;
								}
								else if(PLC_OutPut[32]==1)//һ¥�����ť
								{
									PLC2_Data[19]=0;
								}
								else if(PLC_OutPut[33]==1)//3��ť
								{
									PLC2_Data[20]=0;
								}
								else if(PLC_OutPut[34]==1)//1��ť
								{
									PLC2_Data[21]=0;
								}
								else if(PLC_OutPut[35]==1)//����
								{
									PLC2_Data[22]=0;
								}
								else if(PLC_OutPut[36]==1)//����
								{
									PLC2_Data[23]=0;
								}
								PLC_OutPut[37]=PLC2_Data[24];//��¥ƽ�㣨��������¥��
								PLC_OutPut[38]=PLC2_Data[25];//һ¥ƽ�㣨������һ¥��
								PLC_OutPut[39]=PLC2_Data[26];//��¥��״̬����/�أ�
								PLC_OutPut[40]=PLC2_Data[27];//һ¥��״̬����/�أ�
						}break;
			case 15://���ݲ��Դ���ִ��
						{
							while(HmiScreenSetGet == 15)
							{
																		
								PID.Kp = PLC_Data[8];		              //������Ļ��PID����kp
								PID.Ki = PLC_Data[9];                 //������Ļ��PID����ki
								PID.Kd = PLC_Data[10];                //������Ļ��PID����kd
																											
								PID4.Kp = PLC_Data[13];	              //������Ļ��PID4����kp
								PID4.Ki = PLC_Data[14];               //������Ļ��PID4����ki
								PID4.Kd = PLC_Data[15];               //������Ļ��PID4����kd
							
								time=PLC_Data[11];										//����ǰ����PID��������
								speed=PLC_Data[6];										//������Ļ���ٶ���ʾֵ
								Ruan_Qi(SPEED_min,speed);							//�ٶȸ�ֵ
								
								SystemParameter[11]= PLC_Data[11];
								SystemParameter[8] = PLC_Data[8];
								SystemParameter[9] = PLC_Data[9];
								SystemParameter[10]= PLC_Data[10];
								SystemParameter[13]= PLC_Data[13];
								SystemParameter[14]= PLC_Data[14];
								SystemParameter[15]= PLC_Data[15];
								SystemParameter[6] = PLC_Data[6];
								
								SystemParameter[12] = PLC_Data[12]; //�����ֵ	
								osdelay_ms(10);
							}
							
							W25QXX_Write_16(SystemParameter,0,90);			//����ǰ��Ļ����д�뵽flash��
						}break;
			case 23:
						{
							//���·����Ϊ�㣬����һ
							if(HmiRouteNum==0)
							{
								HmiRouteNum = 1;
							}
						}break;
			case 19:
			case 20:	
			case 24: 
			case 25://·������
						{	
								while(HmiScreenSetGet==19||HmiScreenSetGet==20||HmiScreenSetGet==24||HmiScreenSetGet==25||HmiScreenSetGet==FuZhiLuJingTanChuJieMian)
								{  
									//����·��
									if(HmiScreenSetGet==FuZhiLuJingTanChuJieMian)
									{
										//������·���ų�ʼ��Ϊ1
										HmiRouteCopiedNum = 1;
										while(HmiScreenSetGet==FuZhiLuJingTanChuJieMian)//���ڸ���·������
										{
											//������·����Ϊ��ʱ��1
											if(HmiRouteCopiedNum==0)
												HmiRouteCopiedNum=1;	
											if(HmiRouteCopiedNum>RouteNum)
											{
												HmiRouteCopiedNum = 1;
											}
											
											//����ı��������̺ű仯ʱ����
											if(HmiRouteCopiedNumTemp!=HmiRouteCopiedNum)
												HmiRouteCopiedCount = GetRouteStationNum(HmiRouteCopiedNum);
											
											
											//ȷ������
											if(HmiRoutemode==1)
											{
												//��ȡ��������Ϣ����ǰ
												GetRouteData(HmiRouteCopiedNum);
												
												//���沢���±�������Ϣ
												SetRouteData(HmiRouteNum);	
												
												UpdataStationToHmi();
												
												//���õ�ǰվ��Ϊ1
												if(HmiStationNum!=0)
													HmiStationSerialNum = 1;
												
												//�˳�����ģʽ
												HmiRoutemode=0;
											}
											osdelay_ms(10);
										}
									}

									//���վ��
									if(HmiRoutemode==2)
									{ 
										//վ������һ
										HmiStationNum ++;
										//վ��ŵ���վ����
										HmiStationSerialNum = HmiStationNum;
										
										//�ر������
										keynumber = 0;		
										
										ClearStationToHmi();	
										
										while(HmiRoutemode==2)
										{
											//��������ر꣬���µ���ʾ��
											if(keynumber!=0)
											{
												HmiRfidNum = keynumber;//ˢ�µر��
											}			
											
											//ȷ��
											if(HmiRouteEnter==1)
											{
												HmiRouteEnter = 0;
												//����վ�����ݵ���ǰ����
												UpdataStationToNow();
												//���浱ǰվ������
												SetRouteData(HmiRouteNum);
												//�˳����ģʽ
												HmiRoutemode=	0;
											}
											else
											//ȡ��
											if(HmiRouteEnter==2)
											{
												HmiRouteEnter = 0;
												//վ������һ
												HmiStationNum--;
												//վ��ŵ���վ����
												HmiStationSerialNum = HmiStationNum;
												//�˳����ģʽ
												HmiRoutemode=	0;
											}
											osdelay_ms(10);
										}
									}
									//����վ��
									if(HmiRoutemode==3)
									{
										//վ������һ
										HmiStationNum ++;
										//վ���Ϊ��ʱ��һ
										if(HmiStationNum==0)
											HmiStationSerialNum = 1;
										
										//�ر������
										keynumber = 0;		
										
										ClearStationToHmi();										

										while(HmiRoutemode==3)
										{
											//��������ر꣬���µ���ʾ��
											if(keynumber!=0)
											{
												HmiRfidNum = keynumber;//ˢ�µر��
											}												
											
											//ȷ��
											if(HmiRouteEnter==1)
											{
												HmiRouteEnter = 0;
												
												//վ����Ϣ����ƶ�һ��λ�ã������뵱ǰվ����Ϣ
												for(i=HmiStationNum;i>=HmiStationSerialNum;i--)
												{
													for(j=0;j<StaiionInfor;j++)
													{
														NowRouteInfor[i][j] = NowRouteInfor[i-1][j];
													}
												}
												
												//����վ����Ϣ����ǰ
												UpdataStationToNow();
												
												//����·����Ϣ
												SetRouteData(HmiRouteNum);

												//�˳����ģʽ
												HmiRoutemode=	0;
											}
											else
											//ȡ��
											if(HmiRouteEnter==2)
											{
												HmiRouteEnter = 0;
												//վ������һ
												HmiStationNum--;
												//վ���Ϊ1ʱ����
												if(HmiStationSerialNum==1)
													HmiStationSerialNum = 0;
												//�˳����ģʽ
												HmiRoutemode=	0;
											}

											osdelay_ms(10);
										}

									}
									//����վ��
									if(HmiRoutemode==4)
									{ 
										keynumber = 0;
										while(HmiRoutemode==4)
										{
											//��������ر꣬���µ���ʾ��
											if(keynumber!=0)
											{
												HmiRfidNum = keynumber;//ˢ�µر��
											}			
											
											//ȷ��
											if(HmiRouteEnter==1)
											{
												HmiRouteEnter = 0;
												//����վ�����ݵ���ǰ����
												UpdataStationToNow();
												//���浱ǰվ������
												SetRouteData(HmiRouteNum);
												//�˳����ģʽ
												HmiRoutemode=	0;
											}
											else
											//ȡ��
											if(HmiRouteEnter==2)
											{
												HmiRouteEnter = 0;
												//���µ�����
												UpdataStationToHmi();
												//�˳����ģʽ
												HmiRoutemode=	0;
											}
											osdelay_ms(10);
										}
									}
								
									//ɾ��վ��
									if(HmiRoutemode==5)
									{
										if(HmiStationNum>0)
										{
											//��������������ǰ�ƶ�һλ
											if((HmiStationNum>0)&&((HmiStationNum)!=HmiStationSerialNum))
											{
												//վ����Ϣ��ǰ�ƶ�һ��λ��
												for(i=HmiStationSerialNum;i<HmiStationNum;i++)
												{
													for(j=0;j<StaiionInfor;j++)
													{
														NowRouteInfor[i-1][j] = NowRouteInfor[i][j];
													}
												}
											}

											HmiStationNum--;
											if(HmiStationNum==0)
												HmiStationSerialNum = 0;
											else
												if((HmiStationNum+1)==HmiStationSerialNum)
													HmiStationSerialNum--;
											//����·����Ϣ
											SetRouteData(HmiRouteNum);
											
											//���½���
											UpdataStationToHmi();
										}	
										HmiRoutemode = 0;
									}
									
									//��ѯվ��
									if(HmiRoutemode==0)
									{
										//��·��վ��������0���������Ϊ0ʱ���������Ϊ1����������ʾ����
										if((HmiStationNum>0)&&(HmiStationSerialNum==0))
										{
											HmiStationSerialNum = 1;
											//���µ�����
											UpdataStationToHmi();
										}
										else
										if(HmiStationNum==0)
										{
											HmiStationSerialNum = 0;
										}
										
										//·���ű仯ʱ�����½���
										if(HmiRouteNumFlag != HmiRouteNum)
										{
											HmiRouteNumFlag = HmiRouteNum;
											//��ȡ·����Ϣ
											GetRouteData(HmiRouteNum);
											if(HmiStationNum>0)
												HmiStationSerialNum = 1;
											//���µ�����
											UpdataStationToHmi();
										}
										
										//��һ��
										if(HmiStationLast == 1)
										{
											HmiStationLast = 0;
											if(HmiStationSerialNum>1)
												HmiStationSerialNum--;
											else
												HmiStationSerialNum = HmiStationNum;
										}
										//��һ��
										if(HmiStationNext == 2)
										{
											HmiStationNext = 0;
											if(HmiStationSerialNum<HmiStationNum)
													HmiStationSerialNum++;
												else
													if(HmiStationSerialNum!=0)
														HmiStationSerialNum = 1;
										}
										
										if(HmiStationNum==0)		//û��վ��
										{
											//���վ����Ϣ
											ClearStationToHmi();
										}
										else
										{
											//����վ����Ϣ
											UpdataStationToHmi();
										}
									}
									osdelay_ms(10);
								}
						}break;
			case 26://��۴ŵ������ݵ���
						{	
							if(SystemParameter[60]!=PLC_Data[60]||SystemParameter[61]!=PLC_Data[61]||SystemParameter[62]!=PLC_Data[62]||
								 SystemParameter[63]!=PLC_Data[63]||SystemParameter[64]!=PLC_Data[64]||SystemParameter[65]!=PLC_Data[65]||
								 SystemParameter[66]!=PLC_Data[66]||SystemParameter[67]!=PLC_Data[67]||SystemParameter[68]!=PLC_Data[68]||
								 SystemParameter[69]!=PLC_Data[69]||SystemParameter[70]!=PLC_Data[70]||SystemParameter[71]!=PLC_Data[71]||
								 SystemParameter[72]!=PLC_Data[72]||SystemParameter[73]!=PLC_Data[73]||SystemParameter[74]!=PLC_Data[74]||
								 SystemParameter[75]!=PLC_Data[75]||SystemParameter[76]!=PLC_Data[76])
							{	
									SystemParameter[60]	= PLC_Data[60];	 
									SystemParameter[61]	= PLC_Data[61];  
									SystemParameter[62]	= PLC_Data[62];  
									SystemParameter[63]	=	PLC_Data[63];
									SystemParameter[64]	=	PLC_Data[64];
									SystemParameter[65]	=	PLC_Data[65];
									SystemParameter[66]	= PLC_Data[66];	 
									SystemParameter[67]	= PLC_Data[67];  
									SystemParameter[68]	= PLC_Data[68];  
									SystemParameter[69]	=	PLC_Data[69];
									SystemParameter[70]	=	PLC_Data[70];
									SystemParameter[71]	=	PLC_Data[71];
									SystemParameter[72]	= PLC_Data[72];	 
									SystemParameter[73]	= PLC_Data[73];  
									SystemParameter[74]	= PLC_Data[74]; 
									SystemParameter[75]	= PLC_Data[75];  
									SystemParameter[76]	= PLC_Data[76];								
									
									W25QXX_Write_16(&SystemParameter[60],60,17);			//����ǰ��Ļ����д�뵽flash��
							}
						}break;				
			case LiuChengGuiHuaJieMian://��������
			case FuZhiLiuChengTanChuJieMian:
			case QueDingChaRuLiuChengJieMian:
			case QueDingShanChuLiuChengJieMian:
						{
								while(HmiScreenSetGet==LiuChengGuiHuaJieMian||HmiScreenSetGet==FuZhiLiuChengTanChuJieMian||HmiScreenSetGet==QueDingChaRuLiuChengJieMian||HmiScreenSetGet==QueDingShanChuLiuChengJieMian)
								{ 
									//�鿴ģʽ
									if(HmiProcessMode==0)
									{
										//��ǰ���̲�������0�����ҽ������Ϊ0ʱ���������Ϊ1����������ʾ����
										if((HmiStepNum>0)&&(HmiProcessSerialNum==0))
										{
											HmiProcessSerialNum = 1;
											GetProcessData();
										}
										else
										if(HmiStepNum==0)
										{
											HmiProcessSerialNum = 0;
											HmiProcessStartNum = 0;
											HmiProcessStopNum = 0;
											HmiProcessAction = 0;
										}
										
										//���̺ű仯ʱ�����½���
										if(HmiProcessNumFlag != HmiProcessNum)
										{
											HmiProcessNumFlag = HmiProcessNum;
											GetProcessData();
										}
										
										if(HmiProcessLast==1)//��һ��
										{
											HmiProcessLast = 0;
											if(HmiProcessSerialNum>1)
												HmiProcessSerialNum--;
											else
												HmiProcessSerialNum = HmiStepNum;
										}
										else
											if(HmiProcessNext==2)//��һ��
											{
												HmiProcessNext = 0;
												if(HmiProcessSerialNum<HmiStepNum)
													HmiProcessSerialNum++;
												else
													if(HmiProcessSerialNum!=0)
														HmiProcessSerialNum = 1;
											}
											
										if(HmiStepNum==0)
										{
											ClearStepToHmi();
										}
										else
										{
											UpdataProcessToHmi();
										}
										
									}									
									
									//��������
									if(HmiScreenSetGet==FuZhiLiuChengTanChuJieMian)
									{
										//��ʼ����������Ϊ1
										HmiProcessCopiedNum = 1;
										while(HmiScreenSetGet==FuZhiLiuChengTanChuJieMian)
										{
											//���������̺�Ϊ��ʱ��1
											if(HmiProcessCopiedNum==0)
												HmiProcessCopiedNum=1;	
											if(HmiProcessCopiedNum > ProcessNum)
												HmiProcessCopiedNum=1;	
											
											//����ı��������̺ű仯ʱ����
											if(HmiProcessCopiedNumTemp!=HmiProcessCopiedNum)
												HmiProcessCopiedCount = GetProcessStepNum(HmiProcessCopiedNum);
											
											//ȷ������
											if(HmiProcessMode==1)
											{
												//��ȡ��������Ϣ����ǰ
												GetProcessDataFrom(HmiProcessCopiedNum);
												//���汻������Ϣ
												SetProcessData();	
												
												//���õ�ǰ���Ϊ1
												if(HmiStepNum!=0)
													HmiProcessSerialNum = 1;
											
												//�˳�����ģʽ
												HmiProcessMode = 0;
											}
											osdelay_ms(10);
										}
									}
									
									//�������
									if(HmiProcessMode==2)
									{
										//���̲�����һ
										HmiStepNum++;
										//��ŵ���������
										HmiProcessSerialNum = HmiStepNum;
										
										ClearStepToHmi();

										while(HmiProcessMode==2)
										{
											switch(HmiProcessAction)
											{
												case 0://����ִ��
													break;
												case 1://˳��ִ�е�
													if(HmiProcessStopNum<=HmiProcessStartNum)
													{
														if(HmiProcessStartNum==ProcessNum)
															HmiProcessStopNum=HmiProcessStartNum;
														else
															HmiProcessStopNum=HmiProcessStartNum+1;
													}
													break;
												case 2://����ִ��
													if(HmiProcessStopNum>=HmiProcessStartNum)
													{
														if(HmiProcessStartNum==1)
															HmiProcessStopNum=HmiProcessStartNum;
														else
															HmiProcessStopNum=HmiProcessStartNum-1;
													}
													break;
												case 3://ѭ��ִ��
													if(HmiProcessStopNum==0)
													{
															HmiProcessStopNum=1;
													}
													break;
												default:break;
											}
											
											//ȷ��
											if(HmiProcessEnter==1)
											{
												HmiProcessEnter = 0;
												//���沢��������
												SetProcessData();
												
												//�˳����ģʽ
												HmiProcessMode = 0;
											}
											//ȡ��
											else if(HmiProcessEnter==2) 
											{
												HmiProcessEnter = 0;
												
												//���̲�����һ
												HmiStepNum--;
												//��ŵ���������
												HmiProcessSerialNum = HmiStepNum;
												
												//�˳����ģʽ
												HmiProcessMode = 0;
											}
											osdelay_ms(10);
										}
									}
									
									
									//��������
									if(HmiProcessMode==3)
									{
										//���̲�����һ
										HmiStepNum++;
										//���Ϊ��ʱ��һ
										if(HmiProcessSerialNum==0)
											HmiProcessSerialNum = 1;
										
										ClearStepToHmi();
										
										while(HmiProcessMode==3)
										{
											switch(HmiProcessAction)
											{
												case 0://����ִ��
													break;
												case 1://˳��ִ�е�
													if(HmiProcessStopNum<=HmiProcessStartNum)
													{
														if(HmiProcessStartNum==ProcessNum)
															HmiProcessStopNum=HmiProcessStartNum;
														else
															HmiProcessStopNum=HmiProcessStartNum+1;
													}
													break;
												case 2://����ִ��
													if(HmiProcessStopNum>=HmiProcessStartNum)
													{
														if(HmiProcessStartNum==1)
															HmiProcessStopNum=HmiProcessStartNum;
														else
															HmiProcessStopNum=HmiProcessStartNum-1;
													}
													break;
												case 3://ѭ��ִ��
													if(HmiProcessStopNum==0)
													{
															HmiProcessStopNum=1;
													}
													break;
												default:break;
											}
											
											//ȷ��
											if(HmiProcessEnter==1)
											{
												HmiProcessEnter = 0;
												
												//���沢��������
												InsertProcessData();
												
												//�˳�����ģʽ
												HmiProcessMode = 0;
											}
											//ȡ��
											else if(HmiProcessEnter==2) 
											{
												HmiProcessEnter = 0;
												
												//���̲�����һ
												HmiStepNum--;
												//���Ϊ1ʱ��һ
												if(HmiProcessSerialNum==1)
													HmiProcessSerialNum = 0;
												
												//�˳����ģʽ
												HmiProcessMode = 0;
											}
											osdelay_ms(10);
										}
									}									
									
									//��������
									if(HmiProcessMode==4)
									{
										while(HmiProcessMode==4)
										{
											switch(HmiProcessAction)
											{
												case 0://����ִ��
													break;
												case 1://˳��ִ�е�
													if(HmiProcessStopNum<=HmiProcessStartNum)
													{
														if(HmiProcessStartNum==ProcessNum)
															HmiProcessStopNum=HmiProcessStartNum;
														else
															HmiProcessStopNum=HmiProcessStartNum+1;
													}
													break;
												case 2://����ִ��
													if(HmiProcessStopNum>=HmiProcessStartNum)
													{
														if(HmiProcessStartNum==1)
															HmiProcessStopNum=HmiProcessStartNum;
														else
															HmiProcessStopNum=HmiProcessStartNum-1;
													}
													break;
												case 3://ѭ��ִ��
													if(HmiProcessStopNum==0)
													{
															HmiProcessStopNum=1;
													}
													break;
												default:break;
											}
											
											//ȷ��
											if(HmiProcessEnter==1)
											{
												HmiProcessEnter = 0;
												//���沢��������
												SetProcessData();
												
												//�˳�����ģʽ
												HmiProcessMode = 0;
											}
											//ȡ��
											else if(HmiProcessEnter==2) 
											{
												HmiProcessEnter = 0;

												//�˳����ģʽ
												HmiProcessMode = 0;
											}
											osdelay_ms(10);
										}
									}									
									
									//ɾ������
									if(HmiProcessMode==5)
									{
										DeleteProcessData();
										//�˳�ɾ��ģʽ
										HmiProcessMode = 0;
									}
									
									osdelay_ms(10);
								}
						}break;
			case LiuChengSheZhiJieMian: 
							{		
								//���·����Ϊ�㣬����һ
								if(HmiProcessNum==0)
								{
									HmiProcessNum = 1;
								}
							}
							break;
			case ZhiXingLuJingJieMian: //ִ��·��
							{		
								while(HmiScreenSetGet==ZhiXingLuJingJieMian)
								{
									if(ZhiXingLuJingQueDing==1)
									{
										//����·����
										SetOneParameterToSystem(HmiRouteNum,24);
										SystemParameter[26] = HmiTask;
										//���������
										SetOneParameterToSystem(HmiTask,26);
										ZhiXingLuJingQueDing = 0;
										
										//�����Զ�������Ϣ
										HmiAutoReload();
										
										HmiTask = 1;
										
										FX_flag=1;//�����л���ǰ��

										//��ת���Զ�����
										HmiScreenSetGet = ZiDongJieMian;
									}
									osdelay_ms(10);
								}
							}
							break;
			case ZhiXingLiuChengJieMian: //ִ������
							{		
								while(HmiScreenSetGet==ZhiXingLiuChengJieMian)
								{
									if(ZhiXingLiuChengQueDing==1)
									{
										ActiveProcess();
										ZhiXingLiuChengQueDing = 0;
									}
									osdelay_ms(10);
								}							
							}
							break;			
			case ZiDongJieMian: //�Զ�����
							{		
								while(HmiScreenSetGet==ZiDongJieMian)
								{
									if(PLC_OutPut[4]==1)						//��Ļ���ֶ���������ʱ
									{
										Shou_Dong();		//�е��ֶ�����
									}
									else if(PLC_OutPut[5]==1)				//��Ļ���Զ���������ʱ
									{
										Zi_Dong();			//�е��Զ�����
									}
									if(Mode_flag == 1)
									{
											if(PLC_OutPut[11]==1)			//����
											{
												Qi_Dong();
											}
											if(PLC_OutPut[12]==1)		 	//ֹͣ
											{
												Ting_Zhi();
											}
									}
									osdelay_ms(10);
								}		
							}
							break;	
			case QuXiaoRenWuJieMian: //ȡ������
							{		
								while(HmiScreenSetGet==QuXiaoRenWuJieMian)
								{
									if(QuXiaoRenWuQueDing==1)
									{
										QuXiaoRenWuQueDing = 0;
										
										HmiTask = 0;
										
										//����״̬Ϊ����
										HmiTaskState = 0;
										
										//ͣ��
										Ting_Zhi();
										
										//��������ź�
										PLC2_Data[22]=1;//(1,�����Ű�ť��10�����¿��Ű�ť)
										
										//�л������ʶΪǰ��
										FX_flag=1;
										
										//����������
										PLC2_Data[32] = 0;
										//����豸���ź�
										PLC2_Data[38] = 0;	
										PLC2_Data[39] = 0;	
										PLC2_Data[40] = 0;	
										PLC2_Data[41] = 0;	
										
										//��ת���棬����֮ǰ����
										if(lastscreenNum!=0)
										{
											HmiScreenSetGet = lastscreenNum;
											lastscreenNum = 0;
										}
										else
											HmiScreenSetGet = 16;

										//ɾ������
										OSTaskDel((OS_TCB*)&Task5_TaskTCB,&err);
										//���´�������
										OSTaskCreate((OS_TCB 	* )&Task5_TaskTCB,		
									  (CPU_CHAR	* )"Task5 task", 		
													 (OS_TASK_PTR )Task5_task, 			
													 (void		* )0,					
													 (OS_PRIO	  )Task5_TASK_PRIO,     	
													 (CPU_STK   * )&Task5_TASK_STK[0],	
													 (CPU_STK_SIZE)Task5_STK_SIZE/10,	
													 (CPU_STK_SIZE)Task5_STK_SIZE,		
													 (OS_MSG_QTY  )0,					
													 (OS_TICK	  )0,					
													 (void   	* )0,				
													 (OS_OPT      )OS_OPT_TASK_STK_CHK|OS_OPT_TASK_STK_CLR, 
													 (OS_ERR 	* )&err);
									}
									osdelay_ms(10);
								}							
							}
							break;
							
			case 48://�������������뵯������
						{
							//���������ʾ
							PLC_Data[104] = 0;
							while(HmiScreenSetGet==48)
							{
								//ȷ����ť����
								if(PLC_Data[105]==1)
								{
									//������ȷ,��ת����������
									if(PLC_Data[103]==41320)
									{
										//��ʾ������ȷ
										PLC_Data[104] = 1;
										osdelay_s(1);
										HmiScreenSetGet = 8;
									}		
									else
									{
										//���������ʾ
										PLC_Data[104] = 0;
										osdelay_ms(200);
										//�ٴ���ʾ��ʾ�������
										PLC_Data[104] = 2;
									}
									PLC_Data[105]=0;
								}
								osdelay_ms(20);
							}
						}
							break;
			case 47://��ҳ
						{
							while(HmiScreenSetGet==47)
							{
								if(PLC_Data[106]==1)
								{
									if(PLC_Data[103]==41320)
									{
										HmiScreenSetGet = 8;
									}	
									else
									{
										HmiScreenSetGet = 48;
									}
									PLC_Data[106] = 0;
								}
								osdelay_ms(20);
							}
						}
				break;
			case 49://�����̰���
				{
					HmiProcessNum = 1;
					while(HmiScreenSetGet==49)
					{
						PLC_Data[108] = HmiProcessNum;
						PLC_Data[109] = PLC_Data[108]*8;
						
						if(PLC_Data[107]==1)
						{
							PLC_Data[107]=0;
							
							lastscreenNum = 49;
							//ִ������
							ActiveProcess();
						}
						osdelay_ms(20);
					}
				}
				break;
			case 50://ж�����
				{
					HmiProcessNum = 7;
					while(HmiScreenSetGet==50)
					{
						PLC_Data[111] = HmiProcessNum-6;
						PLC_Data[112] = PLC_Data[111]*8;
						
						if(PLC_Data[110]==1)
						{
							PLC_Data[110]=0;
							lastscreenNum = 50;
							//ִ������
							ActiveProcess();
						}
						osdelay_ms(20);
					}
				}
				break;
			case 51://���˵���¥
				{
					HmiProcessNum = 13;
					while(HmiScreenSetGet==51)
					{
						PLC_Data[114] = HmiProcessNum-12;
						PLC_Data[115] = PLC_Data[114]*8;
						
						if(PLC_Data[113]==1)
						{
							PLC_Data[113]=0;
							lastscreenNum = 51;
							//ִ������
							ActiveProcess();
						}
						osdelay_ms(20);
					}
				}
				break;
			case 52://���˵�һ¥
				{
					HmiProcessNum = 19;
					while(HmiScreenSetGet==52)
					{
						PLC_Data[117] = HmiProcessNum-18;
						PLC_Data[118] = PLC_Data[117]*8;
						if(PLC_Data[116]==1)
						{
							PLC_Data[116]=0;
							lastscreenNum = 52;
							//ִ������
							ActiveProcess();
						}
						osdelay_ms(20);
					}
				}
				break;
			case 53://�����ת��
				{
					HmiProcessNum = 25;
					while(HmiScreenSetGet==53)
					{
						if(PLC_Data[119]==1)
						{
							PLC_Data[119]=0;
							lastscreenNum = 53;
							//ִ������
							ActiveProcess();
						}
						osdelay_ms(20);
					}
				}
				break;
			default:break;
		}	
	
		osdelay_ms(20);
	}	

}



//ι������
void Task7_task(void *p_arg)
{
	p_arg = p_arg;
	while(1)
	{	
		//ι��
		IWDG_Feed();
		osdelay_ms(100);
	}	

}


//����ͨ��170M���߷���������ϵͳ
void Task8_task(void *p_arg)
{
	u16 num=0;
	p_arg = p_arg;
	
	while(1)
	{
		PLC2_Data[0]=HmiRfidNum;				//�ر��ϴ�
		PLC2_Data[17]=HmiNextRfidNum; //��һ���ر�
		
		PLC2_Data[1]=PLC_Data[3];	//���ŵ���1���ݷ��͵�����ϵͳ��ʾ				
		PLC2_Data[2]=PLC_Data[4];	//���ŵ���2���ݷ��͵�����ϵͳ��ʾ				
		PLC2_Data[3]=PLC_Data[5];	//���ŵ���3���ݷ��͵�����ϵͳ��ʾ			
		PLC2_Data[9]=speed;	//�ٶ�ʵʱ��ʾ�ڵ���ϵͳ
		
		
		PLC2_Data[10]=CBBZ2;	//��ۺ������2�����ۣ�
		PLC2_Data[11]=CBBZ1;	//��ۺ������1���Ҳ�ۣ�
		PLC2_Data[12]=CBJC2;	//��ۻ��ﵽλ������2�����ۣ�
		PLC2_Data[13]=CBJC1;	//��ۻ��ﵽλ������1���Ҳ�ۣ�
		PLC2_Data[14]=QBZ2F;	//�������2	:Զ���ϣ�ǰ���ϣ�
		PLC2_Data[15]=QBZ2N;	//�������2	:�����ϣ�ǰ���ϣ�
		PLC2_Data[16]=JXBZ;		//��е����
		
		PLC2_Data[28]=HmiRouteNum;//��ǰ�泵��·����
		
		PLC2_Data[29]=HmiProcessNum;//��ǰ�泵�����̺�

		//��������״̬�����ڵ���ϵͳ
		PLC2_Data[4]=QD_flag;
		
		//�ֶ����Զ�����ģʽ�ϴ�
		PLC2_Data[8]=Mode_flag;
		
		//����
		if(PLC2_Data[30]==55)
		{
			Qi_Dong();
			PLC2_Data[30]=0;
		}
		
		//ֹͣ
		if(PLC2_Data[31]==55)
		{
			Ting_Zhi();
			PLC2_Data[31]=0;
		}		
		
		//������ϸ����ڵ���ϵͳ
		if(FX_flag==1&&QD_flag==0&&front_cdh16.Num==0)			//ǰ��ʱ�������ϴ��й���
		{
			PLC2_Data[5]=1;//�й�����1
		}
		else if(FX_flag==1&&QD_flag==0&&front_cdh16.Num!=0) //ǰ��ʱ���������ϴ��޹���
		{
			PLC2_Data[5]=0;//�޹�����0
		}
		
		if(FX_flag==2&&QD_flag==0&&backl_cdh8.Num==0)				//������ʱ�������ϴ��й���
		{
			PLC2_Data[6]=1;//�й�����1
		}
		else if(FX_flag==2&&QD_flag==0&&backl_cdh8.Num!=0)	//������ʱ���������ϴ��޹���
		{
			PLC2_Data[6]=0;//�޹�����0
		}
		
		if(FX_flag==3&&QD_flag==0&&backr_cdh8.Num==0)				//������ʱ�������ϴ��й���
		{
			PLC2_Data[7]=1;//�й�����1
		}
		else if(FX_flag==3&&QD_flag==0&&backr_cdh8.Num!=0)	//������ʱ���������ϴ��޹���
		{
			PLC2_Data[7]=0;//�޹�����0
		}

		if(Mode_flag==0&&((PLC2_Data[5]+PLC2_Data[6]+PLC2_Data[7])!=0))
		{
			PLC2_Data[5]=0;//�޹�����0
			PLC2_Data[6]=0;//�޹�����0
			PLC2_Data[7]=0;//�޹�����0
		}
		
		//100*20ms���һ������״̬
		num++;
		if(num==100)
		{
			num = 0;
			PLC2_Data[37] = 0;
		}
//		else
//		if(num==50)
//		{
			PLC_Data[97]=!PLC2_Data[37];
//		}

		osdelay_ms(20);
	}
	
}



//������ϡ��������Ȱ�ȫ�������� ������ϵ�ֹͣ
void Task9_task(void *p_arg)
{
	//����ǰ��Զ���⡢�����⡢ͬʱ�����⣬ͬʱ��������ı�־
	u8 qbz_yflag=0,qbz_jflag=0,qbz_flag=0,t_flag=0;
	//Ϊ������һ�ֱ���״̬��Ϊ��һ��ʱ������
	u8 qbz_yflag1=0,qbz_jflag1=0,qbz_flag1=0;
	u8 hbz_flag=0;//���˷���ı��Ͽ���ʱһ������ʱ��ִ�ж���������
	u8 jxbz_flag=0;//��е���ϵı��Ͽ���ʱһ������ʱ��ִ�ж���������
	u8 last_mbtz=0;//���ֹͣ�ϴε�״̬
	
	p_arg = p_arg;

	while(1)
	{
		if(Mode_flag==1)												//���Զ�ģʽ�²��п��ܽ��б��ϼ��
		{		
			if(last_mbtz==1&&MBTZ==0&&QD_flag==1) //������״̬�����ֹͣ����ʱ
			{
				Ting_Zhi();
				//����״̬
				HmiTaskState = 2;
			}	
			last_mbtz=MBTZ;		
			
			if(qj_flag==1)												//ǰ��ʱ���ǰ������ĺ������
			{
				if(JXBZ==1)//��е���ϴ���ʱ
				{
					if(jxbz_flag==0)
					{
						bztingzhi();
						//����״̬
						HmiTaskState = 9;
						jxbz_flag=1;
						yuyin_flag=15;
					}
				}
				else			//��е����δ����ʱ
				{
					if(jxbz_flag==1)
					{
						bzqianjin();
						//����״̬
						HmiTaskState = 5;
						jxbz_flag=0;
						yuyin_flag=16;
					}
				}
				
				if(QBZ_Jflag==0&&QBZ_Yflag==1)//����Զ�ص�ʱ��
				{
					qbz_yflag=0,qbz_flag=0,t_flag=0;
					
					qbz_yflag1=0,qbz_flag1=0;
					
					if(qbz_jflag1==0)
					{
						bzqianjin();
						//����״̬
						HmiTaskState = 5;
						qbz_jflag1=1;
					}
					switch(QBZ2N) //������
					{
						case 0://����ʱ
									{
										if(qbz_jflag==0)//�Ӳ�����������ʱִֻ��һ��
										{
											bztingzhi();
											//����״̬
											HmiTaskState = 2;
											qbz_jflag=1;
											yuyin_flag=15;
										}
									}break;
						case 1://������ʱ
									{
										if(qbz_jflag==1)//�Ӵ�����������ʱִֻ��һ��
										{
											bzqianjin();
											//����״̬
											HmiTaskState = 5;
											qbz_jflag=0;
											yuyin_flag=16;
										}
									}break;
					}
				}
				if(QBZ_Jflag==1&&QBZ_Yflag==0)//����Զ����ʱ��
				{
					qbz_jflag=0,qbz_flag=0,t_flag=0;
					
					qbz_jflag1=0,qbz_flag1=0;
					
					if(qbz_yflag1==0)
					{
						bzqianjin();
						//����״̬
						HmiTaskState = 5;
						qbz_yflag1=1;
					}
					switch(QBZ2F)//Զ����
					{
						case 0://����ʱ
									{
										if(qbz_yflag==0)//�Ӳ�����������ʱִֻ��һ��
										{
											bztingzhi();
											//����״̬
											HmiTaskState = 2;
											qbz_yflag=1;
											yuyin_flag=15;
										}
									}break;
						case 1://������ʱ
									{
										if(qbz_yflag==1)//�Ӵ�����������ʱִֻ��һ��
										{
											bzqianjin();
											//����״̬
											HmiTaskState = 5;
											qbz_yflag=0;
											yuyin_flag=16;
										}
									}break;
					}
				}
				if(QBZ_Jflag==0&&QBZ_Yflag==0)//��������ʱ��
				{
					qbz_yflag=0,qbz_jflag=0,t_flag=0;
					
					qbz_yflag1=0,qbz_jflag1=0;
					
					if(qbz_flag1==0)
					{
						bzqianjin();
						//����״̬
						HmiTaskState = 5;
						qbz_flag1=1;
					}
					switch(QBZ2N & QBZ2F) //Զ���������һ��Ϊ0��Ϊ����
					{
						case 0://����ʱ
									{
										if(qbz_flag==0)//�Ӳ�����������ʱִֻ��һ��
										{
											bztingzhi();
											//����״̬
											HmiTaskState = 2;
											qbz_flag=1;
											yuyin_flag=15;
										}
									}break;
						case 1://������ʱ
									{
										if(qbz_flag==1)//�Ӵ�����������ʱִֻ��һ��
										{
											bzqianjin();
											//����״̬
											HmiTaskState = 5;
											qbz_flag=0;
											yuyin_flag=16;
										}
									}break;
					}
				}
				if(QBZ_Jflag==1&&QBZ_Yflag==1)//���رյ�ʱ��
				{
					if(t_flag==0)
					{
						bzqianjin();
						//����״̬
						HmiTaskState = 5;
						t_flag=1;
					}
					qbz_yflag=0,qbz_jflag=0,qbz_flag=0;
				}
			}
			else if(htz_flag==1||hty_flag==1)			//����ʱ�����˷���ĺ������
			{
				if(HBZ_flag==0)//����۱��ϴ�ʱ�ٶԲ�۱��ϴ��������м�Ⲣִ����Ӧ�Ķ���
				{
					if(CBBZ1==0||CBBZ2==0)//��۱�������һ������ʱ
					{
						if(hbz_flag==0)
						{
							bztingzhi();	
							//����״̬
						  HmiTaskState = 7;							
							hbz_flag=1;
							yuyin_flag=15;
						}
					}
					else	//������۱��ϴ�������������ʱ
					{
						if(hbz_flag==1)
						{
							bzhoutui();
							//����״̬
							HmiTaskState = 5;
							hbz_flag=0;
							yuyin_flag=16;
						}
					}
				}
			}
			else 																	//���Ȳ���ǰ���ֲ��Ǻ���ʱ�������־
			{
				qbz_yflag=0,qbz_jflag=0,qbz_flag=0;
				hbz_flag=0;
			}
		}
		osdelay_ms(20);
	}
	
}



//��ʾ����˸����  ��ͨ������Police_flag��0��1״̬�����ƾ�ʾ����˸���
void Task10_task(void *p_arg)
{
	p_arg = p_arg;

	while(1)
	{	
		Police_flag=PLC_OutPut[17];
		if(Police_flag==0&&(PLC_Data[97]==0))//�����ʾ����˸��,��������ʱ����˸
		{
			Police_led(900);
		}
		else				//�������
		{
			Police_LED=1;
		}
		osdelay_ms(20);
	}	

}



//��λ��Ƭ������
void Task11_task(void *p_arg)
{
	u8 restnum=0;		//��λʱ�����
	p_arg = p_arg;

	while(1)
	{	
		restnum=0;
		while(MBTZ==0&&restnum!=25) //��������λ��Ƭ��
		{
			osdelay_ms(100);
			restnum ++;
		}
		if(restnum==25)							//��������λ��Ƭ��
		{
			yuyin_flag=18;
			HmiScreenSetGet=8;						//��Ļ�ص���ҳ
			osdelay_s(1);
			NVIC_SystemReset();	
		}
		osdelay_ms(20);
	}	

}


//�ŵ�������
void Task12_task(void *p_arg)
{
	while(1)
	{	
		if(Mode_flag==1)//�Զ�ģʽ�²ż��ͻ��
		{
			//3:ǰ��4:��,5:��		
			//ǰ�ŵ�����ͻ������ۼ�ֵ
			CDH3_data=PLC_Data[3];
			if(lastCDH3_data!=0x0000&&CDH3_data==0x0000)
			{
				osdelay_ms(50);//��ʱ����
				if(CDH3_data==0x0000)
				{
					if(ture_numF<=100)
					{
						ture_numF++;
					}					
				}
			}
			lastCDH3_data=CDH3_data;
			
			//���۵�ͻ������ۼ�ֵ
			CDH4_data=PLC_Data[4];
			if(lastCDH4_data!=0x00&&CDH4_data==0x00)
			{
				osdelay_ms(50);//��ʱ����
				if(CDH4_data==0x0000)
				{
					if(ture_numL<=100)
					{
						ture_numL++;
					}
				}
			}
			lastCDH4_data=CDH4_data;
			
			//�Ҳ�۵�ͻ������ۼ�ֵ
			CDH5_data=PLC_Data[5];
			if(lastCDH5_data!=0x00&&CDH5_data==0x00)
			{
				osdelay_ms(50);//��ʱ����
				if(CDH5_data==0x0000)
				{
					if(ture_numR<=100)
					{
						ture_numR++;
					}
				}
			}
			lastCDH5_data=CDH5_data;
		}
		osdelay_ms(20);
	}	
}

void Task13_task(void *p_arg)
{
	while(1)
	{	
		if(receive_ok == 1)
		{
			data_Parameterreceive();
			DMA_Cmd(DMA2_Stream1, ENABLE);
		}
		osdelay_ms(20);
	}	
}

void Task15_task(void *p_arg)
{
	u8 h,m,s;		//��λʱ�����
	p_arg = p_arg;

	while(1)
	{	
		//�ȴ���ʼ����
		while(HmiTask==0)
		{
			osdelay_ms(10);
		}
		//��ʼ��ʱ
		h = 0;m = 0;s = 0;
		PLC_Data[102] = h;
		PLC_Data[100] = m;
		PLC_Data[101] = s;
		
		while(HmiTask!=0)
		{
			//�ֶ�����ʱ
			if(Mode_flag!=0)
				s++;
			
			if(s==60)
			{
				s = 0;
				m++;
			}
			
			if(m==60)
			{
				m = 0;
				h++;
			}
			
			
			osdelay_s(1);
			
			//���µ�����
			PLC_Data[102] = h;
			PLC_Data[100] = m;
			PLC_Data[101] = s;
		}
	}	

}




