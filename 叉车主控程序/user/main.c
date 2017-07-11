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
/*************所有任务定义开始************/
#if 1
//任务优先级
#define START_TASK_PRIO		3
//任务堆栈大小	
#define START_STK_SIZE 		128
//任务控制块
OS_TCB StartTaskTCB;
//任务堆栈	
CPU_STK START_TASK_STK[START_STK_SIZE];
//任务函数
void start_task(void *p_arg);

//任务优先级
#define Control_TASK_PRIO		4
//任务堆栈大小	
#define Control_STK_SIZE 		128
//任务控制块
OS_TCB Control_TaskTCB;
//任务堆栈	
CPU_STK Control_TASK_STK[Control_STK_SIZE];
//任务函数
void Control_task(void *p_arg);

//任务优先级
#define Automode_TASK_PRIO		5
//任务堆栈大小	
#define Automode_STK_SIZE 		128
//任务控制块
OS_TCB Automode_TaskTCB;
//任务堆栈	
CPU_STK Automode_TASK_STK[Automode_STK_SIZE];
//任务函数
void Automode_task(void *p_arg);

//任务优先级
#define Task1_TASK_PRIO		6
//任务堆栈大小	
#define Task1_STK_SIZE 		128
//任务控制块
OS_TCB Task1_TaskTCB;
//任务堆栈	
CPU_STK Task1_TASK_STK[Task1_STK_SIZE];
void Task1_task(void *p_arg);

//任务优先级
#define Task4_TASK_PRIO		7
//任务堆栈大小	
#define Task4_STK_SIZE 		128
//任务控制块
OS_TCB Task4_TaskTCB;
//任务堆栈	
CPU_STK Task4_TASK_STK[Task4_STK_SIZE];
//任务函数
void Task4_task(void *p_arg);

//任务优先级
#define Cansend_TASK_PRIO		8
//任务堆栈大小	
#define Cansend_STK_SIZE 		128
//任务控制块
OS_TCB Cansend_TaskTCB;
//任务堆栈	
CPU_STK Cansend_TASK_STK[Cansend_STK_SIZE];
//任务函数
void Cansend_task(void *p_arg);

//任务优先级
 #define RunLED_TASK_PRIO		9
//任务堆栈大小	
#define RunLED_STK_SIZE 		128
//任务控制块
OS_TCB RunLED_TaskTCB;
//任务堆栈	
CPU_STK RunLED_TASK_STK[RunLED_STK_SIZE];
//任务函数
void RunLED_task(void *p_arg);

//任务优先级
#define RFID_TASK_PRIO		5
//任务堆栈大小	
#define RFID_STK_SIZE 		128
//任务控制块
OS_TCB RFID_TaskTCB;
//任务堆栈	
CPU_STK RFID_TASK_STK[RFID_STK_SIZE];
//任务函数
void RFID_task(void *p_arg);

//任务优先级
#define YAOKONG_TASK_PRIO		10
//任务堆栈大小	
#define YAOKONG_STK_SIZE 		128
//任务控制块
OS_TCB YAOKONG_TaskTCB;
//任务堆栈	
CPU_STK YAOKONG_TASK_STK[YAOKONG_STK_SIZE];
//任务函数
void YAOKONG_task(void *p_arg);

//任务优先级
#define Task5_TASK_PRIO		11
//任务堆栈大小	
#define Task5_STK_SIZE 		128
//任务控制块
OS_TCB Task5_TaskTCB;
//任务堆栈	
CPU_STK Task5_TASK_STK[Task5_STK_SIZE];
//任务函数
void Task5_task(void *p_arg);

//任务优先级
#define Task6_TASK_PRIO		12
//任务堆栈大小	
#define Task6_STK_SIZE 		128
//任务控制块
OS_TCB Task6_TaskTCB;
//任务堆栈	
CPU_STK Task6_TASK_STK[Task6_STK_SIZE];
//任务函数
void Task6_task(void *p_arg);

//任务优先级
#define Task7_TASK_PRIO		12
//任务堆栈大小	
#define Task7_STK_SIZE 		128
//任务控制块
OS_TCB Task7_TaskTCB;
//任务堆栈	
CPU_STK Task7_TASK_STK[Task7_STK_SIZE];
//任务函数
void Task7_task(void *p_arg);

//任务优先级
#define Task8_TASK_PRIO		12
//任务堆栈大小	
#define Task8_STK_SIZE 		128
//任务控制块
OS_TCB Task8_TaskTCB;
//任务堆栈	
CPU_STK Task8_TASK_STK[Task8_STK_SIZE];
//任务函数
void Task8_task(void *p_arg);

//任务优先级
#define Task9_TASK_PRIO		12
//任务堆栈大小	
#define Task9_STK_SIZE 		128
//任务控制块
OS_TCB Task9_TaskTCB;
//任务堆栈	
CPU_STK Task9_TASK_STK[Task9_STK_SIZE];
//任务函数
void Task9_task(void *p_arg);

//任务优先级
#define Task10_TASK_PRIO		12
//任务堆栈大小	
#define Task10_STK_SIZE 		128
//任务控制块
OS_TCB Task10_TaskTCB;
//任务堆栈	
CPU_STK Task10_TASK_STK[Task10_STK_SIZE];
//任务函数
void Task10_task(void *p_arg);

//任务优先级
#define Task11_TASK_PRIO		12
//任务堆栈大小	
#define Task11_STK_SIZE 		128
//任务控制块
OS_TCB Task11_TaskTCB;
//任务堆栈	
CPU_STK Task11_TASK_STK[Task11_STK_SIZE];
//任务函数
void Task11_task(void *p_arg);


//任务优先级
#define Task12_TASK_PRIO		13
//任务堆栈大小	
#define Task12_STK_SIZE 		128
//任务控制块
OS_TCB Task12_TaskTCB;
//任务堆栈	
CPU_STK Task12_TASK_STK[Task12_STK_SIZE];
//任务函数
void Task12_task(void *p_arg);


//任务优先级
#define Task13_TASK_PRIO		14
//任务堆栈大小	
#define Task13_STK_SIZE 		128
//任务控制块
OS_TCB Task13_TaskTCB;
//任务堆栈	
CPU_STK Task13_TASK_STK[Task13_STK_SIZE];
//任务函数
void Task13_task(void *p_arg);




//任务优先级
#define Task15_TASK_PRIO		15
//任务堆栈大小	
#define Task15_STK_SIZE 		128
//任务控制块
OS_TCB Task15_TaskTCB;
//任务堆栈	
CPU_STK Task15_TASK_STK[Task15_STK_SIZE];
//任务函数
void Task15_task(void *p_arg);

#endif
/*************所有任务定义完毕************/
/*********所有底层控制函数定义开始********/

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
		//任务状态
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
/*********所有底层控制函数定义结束********/
/*********所有全局参数定义开始************/
#if 1

u8 Chu_Gui_dir=0;//前进方向的出轨方向标志0：正常2：从左边出轨1：从右边出轨
u16 speed=0,speed_ture=0;
u8 Police_flag=0;//警示灯的闪烁打开与关闭标志	0：打开闪烁1：关闭闪烁
u8 QBZ_Yflag=0,QBZ_Jflag=0;//前避障(远、近)开启标志	0：开启	1：关闭
u8 HBZ_flag=0;				//后避障开启标志		0：开启	1：关闭
u8 Mode_flag = 0;			//1:自动运行模式 0：手动控制模式
u8 last_flag=0;
u8 FX_flag=1;					//1:前进	2:后退左	3:后退右 4:左旋 5:右旋
u8 QD_flag=0;					//启动标志 0:停止 1:启动
u8 road_mode=0;
u8 FC_flag=2;					//0:中分叉 1:左分叉 2：右分叉
u8 tz_flag=0,qj_flag=0,htz_flag=0,hty_flag=0;//判断行驶方向和停止与否的标志位（在自动任务里用）
u16 Xuan_Zhuang_Ci_Shu = 1;

u16 CDH12_data=0,lastCDH12_data=0;//前磁导航原始数据值以及上次的原始数据值（用来判断突变的次数）
u8 CDH3_data=0,lastCDH3_data=0,CDH4_data=0,CDH5_data=0,lastCDH4_data=0,lastCDH5_data=0;//后磁导航原始数据值以及上次的原始数据值（用来判断突变的次数）
//3:前，4:左,5:右
u8 ture_numF=0,ture_numL=0,ture_numR=0;

u16 CDH12_num=0,Last_CDH12_num=16;			//16位磁导航数字
u8 CDH1_num=0,CDH2_num=0,CDH3_num=0;//磁导航数据

int deg=0;						//当前方向要打的角度
u16 keynumber=0;			//地标值寄存器
u16 WriteBuffer[1000];//flash的写入寄存器
u16 ReadBuffer[1000]; //flash的读出寄存器
double ADC_POWER=0.0;	//电量采集
u16 time=0;						//动态调节前进时的采样周期
u8 yuyin_flag=0;			//发送各种语音的标志
u16 Yuyin[4]={4,4,4,4};//语音提示存储数组
u16 low_speed=0,middle_speed=0,high_speed=0;	

#endif

//左旋动作
void zuoxuan(u8 FX) //左旋
{
	int Z_deg=0;//旋转的方向值
	
	FX_flag=4;					//由屏上的后退右按钮确定控制叉车的行驶方向标志FX_flag
	yuyin_flag=20;
	HmiScreenRunState = 1;
	
	tz_flag=0,qj_flag=0,htz_flag=0,hty_flag=0;	//清除正常动作标志
	Ruan_Qi(SPEED_min,0);//速度赋值
	qianjin();
	Z_deg=deg;
	while(Z_deg>SystemParameter[4]&&QD_flag==1)
	{
		Z_deg-=4;
		if(Z_deg<6)
		{
			Z_deg = 0;
		}
		PWM_val(TIM4,4,Z_deg);	//方向PWM 左打死	
		osdelay_ms(10);				
	}
	
	Ruan_Qi(SPEED_min,550);//速度赋值
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
				Ruan_Qi(SPEED_min,0);//速度赋值;
				tingzhi();
				while(FX_flag==4&&QD_flag==0)
				{
					osdelay_ms(20);
				}
				if(FX_flag==4)
				{
					qianjin();
					osdelay_ms(100);
					Ruan_Qi(SPEED_min,550);//速度赋值
				}		
			}		
			osdelay_ms(20);
		}
	}

	Ruan_Qi(SPEED_min,0);//速度赋值;
	while(Z_deg<PLC_Data[12]&&QD_flag==1)
	{
		Z_deg+=4;
		
		PWM_val(TIM4,4,Z_deg);	
		osdelay_ms(10);				
	}
	//旋完后方向
	FX_flag = FX;
	osdelay_ms(20);	
	Ruan_Qi(SPEED_min,speed);//速度赋值
}
//右旋动作
void youxuan(u8 FX) //右旋
{
	int Z_deg=0;//旋转的方向值
	
	FX_flag=5;					//由屏上的后退右按钮确定控制叉车的行驶方向标志FX_flag
	yuyin_flag=21;
	HmiScreenRunState = 1;
	
	tz_flag=0,qj_flag=0,htz_flag=0,hty_flag=0;	//清除正常动作标志
	Ruan_Qi(SPEED_min,0);//速度赋值
	houtui();
	
	Z_deg=deg;
	while(Z_deg>SystemParameter[5]&&QD_flag==1)
	{
		Z_deg-=4;
		if(Z_deg<6)
		{
			Z_deg=0;
		}	
		PWM_val(TIM4,4,Z_deg);	//方向PWM 左打死	
		osdelay_ms(10);				
	}
	Ruan_Qi(SPEED_min,550);//速度赋值
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
				Ruan_Qi(SPEED_min,0);//速度赋值;
				tingzhi();
				while(FX_flag==5&&QD_flag==0)
				{
					osdelay_ms(20);
				}
				if(FX_flag==5)
				{
					houtui();
					osdelay_ms(100);
					Ruan_Qi(SPEED_min,550);//速度赋值
				}		
			}
			osdelay_ms(20);
		}
	}
	Ruan_Qi(SPEED_min,0);//速度赋值
	while(Z_deg<PLC_Data[12]&&QD_flag==1)
	{
		Z_deg+=4;
		PWM_val(TIM4,4,Z_deg);	
		osdelay_ms(10);				
	}
	//旋完后方向
	FX_flag = FX;
	osdelay_ms(20);	
	Ruan_Qi(SPEED_min,speed);//速度赋值
	
}


/*********所有全局参数定义结束************/
//主函数
int main(void)
{
	OS_ERR err;
	CPU_SR_ALLOC();
	
	delay_init(168);  				//时钟初始化
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);//中断分组配置
	
	LED_Init();           		//LED初始化	
	BAOHU_Init();							//各种保护传感器的初始化
	W25QXX_Init();						//flash初始化  
	
	DMA_adc1_Init();					//电量采集adc DMA初始化
	DMA_Uart2_Init();					//串口2	DMA地标初始化
	DMA_Uart3_Init();					//串口3	DMA无线初始化
	DMA_Uart4_Init();					//串口4	DMA触摸屏初始化
	DMA_Uart6_Init();					//串口6	DMA wifi初始化
	
	ADC1_Init();							//电量采集adc 初始化
	uart_init(9600);					//串口1初始化(语音rs232串口)
	usart2_init(9600);		    //串口2初始化(RFID串口) 
	usart3_init(115200);      //170M无线
	uart4_init(9600);		    	//串口4初始化（触摸屏RS484串口） 
	usart6_init(115200);		    //串口6初始化（WIFI模块串口）
//	CDH_Init();					      //磁导航端口初始化(用CAN2则不需要)
	Control_Init();			      //叉车行驶方向控制信号初始化
	PWM_Init(TIM4,4,10000,0);	//舵机PWM端口初始化
	PWM_Init(TIM4,2,10000,0);	//速度PWM端口初始化

	//启动看门狗
	IWDG_Init(4,500);    	//预分频数为64,重载值为500,溢出时间为1s	  

	PID_Init();
	PID1_Init();
	PID4_Init();
	CAN2_Mode_Init(CAN_SJW_1tq,CAN_BS2_6tq,CAN_BS1_7tq,6,CAN_Mode_Normal);//CAN2初始化普通模式,波特率500Kbps 
	CAN1_Mode_Init(CAN_SJW_1tq,CAN_BS2_6tq,CAN_BS1_7tq,6,CAN_Mode_Normal);//CAN初始化环回模式,波特率500Kbps 
	/****当主板复位时给继电器板发送一个标志让其恢复之前的状态开始*/
	can_Sebuf[2]=0x55;
	CanSend();	
	can_Sebuf[2]=0;
	/****当主板复位时给继电器板发送一个标志让其恢复之前的状态结束*/
	speek(" ");
	HmiScreenSetGet=47;//屏初始化为首页
	
	OSInit(&err);		    //初始化UCOSIII
	OS_CRITICAL_ENTER();	//进入临界区			 
	//创建开始任务
	OSTaskCreate((OS_TCB 	* )&StartTaskTCB,		//任务控制块
				 (CPU_CHAR	* )"start task", 		//任务名字
                 (OS_TASK_PTR )start_task, 			//任务函数
                 (void		* )0,					//传递给任务函数的参数
                 (OS_PRIO	  )START_TASK_PRIO,     //任务优先级
                 (CPU_STK   * )&START_TASK_STK[0],	//任务堆栈基地址
                 (CPU_STK_SIZE)START_STK_SIZE/10,	//任务堆栈深度限位
                 (CPU_STK_SIZE)START_STK_SIZE,		//任务堆栈大小
                 (OS_MSG_QTY  )0,					//任务内部消息队列能够接收的最大消息数目,为0时禁止接收消息
                 (OS_TICK	  )0,					//当使能时间片轮转时的时间片长度，为0时为默认长度，
                 (void   	* )0,					//用户补充的存储区
                 (OS_OPT      )OS_OPT_TASK_STK_CHK|OS_OPT_TASK_STK_CLR, //任务选项
                 (OS_ERR 	* )&err);				//存放该函数错误时的返回值
	OS_CRITICAL_EXIT();	//退出临界区	 
	OSStart(&err);      //开启UCOSIII
}


//开始任务任务函数
void start_task(void *p_arg)
{
	OS_ERR err;
	CPU_SR_ALLOC();
	p_arg = p_arg;

	CPU_Init();
#if OS_CFG_STAT_TASK_EN > 0u
   OSStatTaskCPUUsageInit(&err);  	//统计任务                
#endif
	
#ifdef CPU_CFG_INT_DIS_MEAS_EN		//如果使能了测量中断关闭时间
    CPU_IntDisMeasMaxCurReset();	
#endif
	
#if	OS_CFG_SCHED_ROUND_ROBIN_EN  //当使用时间片轮转的时候
	 //使能时间片轮转调度功能,时间片长度为1个系统时钟节拍，既1*5=5ms
	OSSchedRoundRobinCfg(DEF_ENABLED,1,&err);  
#endif	
	
	OS_CRITICAL_ENTER();	//进入临界区
	
#if	1		//为了缩放而加的
	//创建Task1任务1
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
				 
	//创建Automode任务2
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
	//创建TASK1任务3
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
				 
	//创建TASK2任务4
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
								 
	//创建TASK1任务5
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
				 
	//创建TASK2任务6
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
	
	//创建TASK2任务7
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
								 
	//创建TASK3任务8
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
								 
								 
	//创建TASK5任务9
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
								 
	//创建TASK6任务10
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
								 
	//创建TASK7任务11
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
								 
	//创建Task8任务12
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
								 
	//创建Task9任务13
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
								 
	//创建Task10任务14
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


		//创建Task11任务15
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


		//创建Task12
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

		//创建Task13
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
								 
								
		//创建Task15
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
									
	OS_CRITICAL_EXIT();	//退出临界区
	OSTaskDel((OS_TCB*)0,&err);	//删除start_task任务自身
}

//磁导航数据采集及处理部分任务
void Task1_task(void *p_arg)
{	
	p_arg = p_arg;
	while(1)
	{		
		/***************实时显示磁导航数据开始****************/
		
		PLC_Data[3]=CDH16;		//前面16位磁导航数据二进制显示在触摸屏上
		PLC_Data[4]=CDH8_2;		//后面8位磁导航数据二进制显示在触摸屏上	
		PLC_Data[5]=CDH8_3;		//后面8位磁导航数据二进制显示在触摸屏上	
		
		/***************实时显示磁导航数据结束****************/
		
		//在任何情况下均采集前磁导航数据并处理
		front_cdh16=FindSpace(PLC_Data[3],16,FC_flag);//调用孙先生的点数处理函数
		CDH12_num=front_cdh16.Distance;//将磁导航采集的原始数据处理后的情况赋值给CDH12_num
		//前磁导航出轨方向的反方向寻迹，包括次导航不居中时当启动时也寻中
		
		/***************************前进方向不正时记录出轨方向标志开始***************************/
		if(CDH12_num!=0)//未出轨时（不居中时）
		{
			Last_CDH12_num=CDH12_num;//为1~31的范围
			if(CDH12_num>5&&CDH12_num<25)//中间范围内
			{
				Chu_Gui_dir=0;
			}
			else if(CDH12_num<6)//磁导航太偏左
			{
				Chu_Gui_dir=2;
			}
			else if(CDH12_num>24)//磁导航太偏右
			{
				Chu_Gui_dir=1;
			}
		}
		else//出轨时
		{
			if(Last_CDH12_num<16)//从左边出轨
			{
				Chu_Gui_dir=2;
			}
			else if(Last_CDH12_num>16)//从右边出轨
			{
				Chu_Gui_dir=1;
			}
			else//从中间出轨
			{
				Chu_Gui_dir=0;
			}
		}
		
		/***************************前进方向不正时记录出轨方向标志结束***************************/
		if(Mode_flag==1)//在自动模式下才执行以下步骤
		{			
				/***********用行驶方向标志来确定采集哪路磁导航数据开始*************/
				switch(FX_flag)//用行驶方向标志来确定采集哪路磁导航数据
				{
					case 0:
								break;
					case 2://后退左
								{										
									backl_cdh8=FindSpace1(PLC_Data[4],8,FC_flag);//运行时检测磁导航
									CDH2_num=backl_cdh8.Distance;//正常的将磁导航采集的原始数据处理后的情况赋值给CDH2_num
									PLC_Data[7]=CDH2_num;
								}
								break;
					case 3://后退右
								{										
									backr_cdh8=FindSpace1(PLC_Data[5],8,FC_flag);//运行时检测磁导航测到的数据是否有分叉出现
									CDH3_num=backr_cdh8.Distance;//正常的将磁导航采集的原始数据处理后的情况赋值给CDH3_num
									PLC_Data[7]=CDH3_num;
								}
								break;
					default :	
								 break;
				}
				/************用行驶方向标志来确定采集哪路磁导航数据结束***********/
		}
		else 						//在手动模式下才执行以下步骤
		{
			LED2=1;
			LED3=1;
			LED4=1;
		}
		osdelay_ms(20);
	}
}

//Automode任务函数：包括各个方向行驶的PID控制
void Automode_task(void *p_arg)
{
	u8 t=0,t1=0,t2=0;//叉车行驶方向的LED灯闪烁时间（不重要）
	
	int ut=0; 	//当前方向偏差
	int Z_deg1=0;//旋转的方向值
	
	int distance16=0;
	int distanceR=0;
	int distanceL=0;

	u8 Chu_Gui_time=0;//出轨寻磁条时间累积系数
	
	p_arg = p_arg;
	
	while(1)
	{
		while(QD_flag==0)//停止的循环
		{	
			if(tz_flag==0)
			{
				Ruan_Qi(SPEED_min,0);//速度赋值
				tingzhi();
				tz_flag=1,qj_flag=0,htz_flag=0,hty_flag=0;
				LED2=1;                                   
				LED3=1;                                   
				LED4=1; 
			}                                           
			osdelay_ms(20);
		}
		while(FX_flag==1&&QD_flag==1) //前进的循环
		{
			if(qj_flag==0)
			{
				Bi_Zhang_flag=0;//对避障标志清 0
				switch(Chu_Gui_dir)//当按启动时才判断一次
				{
					case 0://正常
					{
						
					}break;
					case 1://上次出轨是从左边出的
					{
						Ruan_Qi(SPEED_min,0);//速度赋值为0
						qianjin();
						if(deg==0)
						{
							deg=PLC_Data[12];
						}
						Z_deg1=deg;
						while(Z_deg1>100&&QD_flag==1)//左打死
						{
							Z_deg1-=10;
							if(Z_deg1<0)
							{
								Z_deg1=0;
							}
							PWM_val(TIM4,4,Z_deg1);	//方向PWM 左打死	
							osdelay_ms(10);				
						}
						osdelay_ms(500);
						Ruan_Qi(SPEED_min,550);//速度赋值为400
						Chu_Gui_time=0;//从现在开始旋转的时间清零
						while((CDH12_num<5||CDH12_num>25)&&Chu_Gui_time<200&&QD_flag==1)//没有转到合适的值时或旋转所定时间到之前一直转
						{
							if(Bi_Zhang_flag==0)//没有避障的情况下
							{
								Chu_Gui_time++;
							}
							osdelay_ms(20);
						}	
						Ruan_Qi(SPEED_min,0);//速度赋值为0
						while(Z_deg1<PLC_Data[12]&&QD_flag==1)//回正
						{
							Z_deg1+=10;	
							PWM_val(TIM4,4,Z_deg1);	//方向PWM 
							osdelay_ms(10);				
						}
						if(Chu_Gui_time>199)//因为时间到而没寻到则停止大循环
						{
							Ting_Zhi();
						}
					}break;
					case 2://上次出轨是从右边出的
					{
						Ruan_Qi(SPEED_min,0);//速度赋值为0
						qianjin();
						if(deg==0)
						{
							deg=PLC_Data[12];
						}
						Z_deg1=deg;
						while(Z_deg1<1000&&QD_flag==1)//右打死
						{
							Z_deg1+=10;
							if(Z_deg1>1000)
							{
								Z_deg1=1000;
							}
							PWM_val(TIM4,4,Z_deg1);	//方向PWM 左打死	
							osdelay_ms(10);				
						}
						osdelay_ms(500);
						Ruan_Qi(SPEED_min,550);//速度赋值为450
						Chu_Gui_time=0;//从现在开始旋转的时间清零
						while((CDH12_num<5||CDH12_num>25)&&Chu_Gui_time<200&&QD_flag==1)//没有转到合适的值时或旋转所定时间到之前一直转
						{
							if(Bi_Zhang_flag==0)//没有避障的情况下
							{
								Chu_Gui_time++;
							}
							osdelay_ms(20);
						}
						Ruan_Qi(SPEED_min,0);//速度赋值为0
						while(Z_deg1>PLC_Data[12]&&QD_flag==1)//回正
						{
							Z_deg1-=10;	
							PWM_val(TIM4,4,Z_deg1);	//方向PWM 
							osdelay_ms(10);				
						}
						if(Chu_Gui_time>199)//因为时间到而没寻到则停止大循环
						{
							Ting_Zhi();
						}
					}break;
				}
				if(CDH12_num!=0)//本来就没出轨或者寻上磁条了才再次正常行驶
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
			
			if(Bi_Zhang_flag==0&&front_cdh16.Num>0&&front_cdh16.zeroNum<2)//如果在避障或出轨和全亮的情况下则不调整PID
			{
					PLC_Data[7] = front_cdh16.Distance;
					
					//没有突变，正常调整
					if(abs(distance16-front_cdh16.Distance)<2)
					{
						ut=PosPIDCalc(CDH12_num,1);//调用位置式PIDCDH12_num
					}
					distance16 = front_cdh16.Distance;
					
					if(ut>0)
					{
						ut=(int)(0.727*ut);
					}
					deg=579+ut;//舵机中值大概为579，左极限为0，右极限为为1000	
					if(deg<0)
					{
						deg=0;
					}
					if(deg>1000)
					{
						deg=1000;
					}
					PWM_val(TIM4,4,deg);	//方向PWM
					speed_ture=speed*((1+((fabs(deg-500))/500)*(fabs(deg-500))/500));
					Ruan_Qi(SPEED_min,speed_ture);//速度赋值
					PLC_Data[1]=speed_ture;
					PLC_Data[2]=deg;		//在屏幕上显示设定角度PWM的数字
			}
			t++;
			if(t==25)
			{
				LED2=~LED2;
				t=0;
			}
				
			//出轨后的执行段
			if(front_cdh16.Num==0)				//如果出轨（在3s内有没有寻到磁条则继续行驶否则停止）
			{	
				Chu_Gui_time=0;
				while(FX_flag==1&&front_cdh16.Num==0&&Chu_Gui_time<150&&QD_flag==1)
				{
					if(Bi_Zhang_flag==0)//没有避障的情况下
					{
						Chu_Gui_time++;
					}
					osdelay_ms(20);
				}

				if(FX_flag!=1)
				{
					
				}
				else if(front_cdh16.Num==0&&QD_flag==1)//依旧出轨则停止
				{
					Ting_Zhi();
					//任务状态
					HmiTaskState = 12;
				}
			}	
			//PID控制时间段
			if(PLC_Data[11]>0&&PLC_Data[11]<100)
			{
				osdelay_ms(PLC_Data[11]+10);
			}
			else 
			{
				osdelay_ms(20);
			}
			
		}
		while(FX_flag==2&&QD_flag==1)	//后退左的循环
		{
			if(htz_flag==0)
			{
				Bi_Zhang_flag=0;//对避障标志清 0
				houtui();
				Ruan_Qi(SPEED_min,260);//速度赋值
				tz_flag=0,qj_flag=0,htz_flag=1,hty_flag=0;
				LED2=1;
				LED3=1;
				LED4=1;
			}

			
			if(Bi_Zhang_flag==0&&backl_cdh8.Num>0&&backl_cdh8.zeroNum<2)//如果在避障的情况下则不调整出轨和全亮时不调整
			{
				
				//没有突变，正常调整
				if(abs(distanceL-backl_cdh8.Distance)<2)
				{
					deg=PosPIDCalc(CDH2_num,3);//调用位置式PID
				}
				distanceL = backl_cdh8.Distance;
		
				PWM_val(TIM4,4,deg);//方向PWM
				
				speed_ture=speed*((1+((fabs(deg-500))/500)*(fabs(deg-500))/500));
				Ruan_Qi(SPEED_min,speed_ture);//速度赋值
				PLC_Data[1]=speed_ture;
				PLC_Data[2]=deg;		//在屏幕上显示设定角度PWM的数字
			}
			t1++;
			if(t1==25)
			{
				LED3=~LED3;
				t1=0;
			}
			
			if(backl_cdh8.Num==0)				//如果出轨停止
			{
				Chu_Gui_time=0;
				while(FX_flag==2&&backl_cdh8.Num==0&&Chu_Gui_time<100&&QD_flag==1)
				{
					if(Bi_Zhang_flag==0)//没有避障的情况下
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
		while(FX_flag==3&&QD_flag==1)	//后退右的循环
		{
			if(hty_flag==0)
			{
				Bi_Zhang_flag=0;//对避障标志清 0
				houtui();
				Ruan_Qi(SPEED_min,260);//速度赋值
				tz_flag=0,qj_flag=0,htz_flag=0,hty_flag=1;
				LED2=1;
				LED3=1;
				LED4=1;
			}
			
			if(Bi_Zhang_flag==0&&backr_cdh8.Num>0&&backr_cdh8.zeroNum<2)//如果在避障的情况下则不调整出轨和全亮时不调整
			{
				//没有突变，正常调整
				if(abs(distanceR-backr_cdh8.Distance)<2)
				{
					deg=PosPIDCalc(CDH3_num,3);//调用位置式PID
				}
				distanceR = backr_cdh8.Distance;
				
				PWM_val(TIM4,4,deg);//方向PWM
				//恒速控制
				speed_ture=speed*((1+((fabs(deg-500))/500)*(fabs(deg-500))/500));
				Ruan_Qi(SPEED_min,speed_ture);//速度赋值
				
				PLC_Data[1]=speed_ture;
				PLC_Data[2]=deg;		//在屏幕上显示设定角度PWM的数字
			}
			t2++;
			if(t2==25)
			{
				LED4=~LED4;
				t2=0;
			}
			
			if(backr_cdh8.Num==0)				//如果出轨停止
			{
				Chu_Gui_time=0;
				while(FX_flag==3&&backr_cdh8.Num==0&&Chu_Gui_time<100&&QD_flag==1)
				{
					if(Bi_Zhang_flag==0)//没有避障的情况下
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

//Control任务函数:手动控制与自动切换继电器板的通信
void Control_task(void *p_arg)
{
	OS_ERR err;
	u8 Hand_flag=0,Auto_flag=0;
	p_arg = p_arg;
	
	while(1)
	{	
		if(Mode_flag==1)									//自动运行模式标志成立了
		{		
				Police_flag=0;								//警示灯打开
				if(Hand_flag==1)							//检测上次是否为手动控制模式
				{
					Hand_flag=0;								//清除手动控制标志
				}
				if(Auto_flag==1)							//检测上次有无创建过自动行走，没有的话创建自动任务	
				{
					OSTaskResume((OS_TCB*)&Automode_TaskTCB,&err);//恢复Automode任务						 					 
					
					P24 =0;//手柄+24切换继电器
					N24 =0;//手柄GND切换继电器
					CBS =1;//叉臂上升继电器
					CBX =1;//叉臂下降继电器
					JJC =0;//接近开关断串入的一端继电器
					JJB =1;//接近开关断并入的一端继电器
					FX1 =0;//叉车行驶方向控制端1继电器
					FX2 =0;//叉车行驶方向控制端2继电器
					ZPWM=0;//转向PWM继电器
					FPWM=0;//方向PWM继电器
					
					Auto_flag=0;							//置自动标志位为1，以免下次重复创建引起系统混乱	
				}
		}
		else															//手动控制模式标志成立了
		{
				Police_flag=1;
				if(Auto_flag==0)							//检测上次是否为自动控制模式
				{
					OSTaskSuspend((OS_TCB*)&Automode_TaskTCB,&err); //挂起Automode任务
					Auto_flag=1;							  //清除自动运行标志
				}
				if(Hand_flag==0)							//检测上次有无创建过手动行走，没有的话创建手动任务	
				{							 						 
					P24 =1;//手柄+24切换继电器
					N24 =1;//手柄GND切换继电器
					CBS =1;//叉臂上升继电器
					CBX =1;//叉臂下降继电器
					JJC =1;//接近开关断串入的一端继电器
					JJB =1;//接近开关断并入的一端继电器
					FX1 =1;//叉车行驶方向控制端1继电器
					FX2 =1;//叉车行驶方向控制端2继电器
					ZPWM=1;//转向PWM继电器
					FPWM=1;//方向PWM继电器
					
					Hand_flag=1;								//置手动标志位为1，以免下次重复创建引起系统混乱
				}
		}
		osdelay_ms(20); //延时20ms
	}

}

//语音播报任务函数
void Task4_task(void *p_arg)
{
	p_arg = p_arg;
	
	W25QXX_Read_16(Yuyin,91,4);	//复位时先从flash中读出语音标志数据
	PLC_Data[23]=Yuyin[0];
	while(1)
	{
		//人声选择
		if(Yuyin[0]!=PLC_Data[23])//人声选择
		{
			Yuyin[0]=PLC_Data[23];
			W25QXX_Write_16(Yuyin,91,4);		//将当前语音参数写入到flash中
			if(Yuyin[0]==0)
			{
				rensheng(0);//人声选择
			}
			else if(Yuyin[0]==1)
			{
				rensheng(1);//人声选择
			}
			else if(Yuyin[0]==2)
			{
				rensheng(2);//人声选择
			}
			else if(Yuyin[0]==3)
			{
				rensheng(3);//人声选择
			}
			else if(Yuyin[0]==4)
			{
				rensheng(4);//人声选择
			}
			else if(Yuyin[0]==5)
			{
				rensheng(5);//人声选择
			}
		}
		//音量选择
		if(PLC_OutPut[18]==1)//音量+
		{
			Yuyin[1]++;
			if(Yuyin[1]>9)
			{
				Yuyin[1]=9;
			}
			W25QXX_Write_16(Yuyin,91,4);		//将当前语音参数写入到flash中
			yinling(Yuyin[1]);//音量选择
		}
		else if(PLC_OutPut[19]==1)//音量-
		{
			Yuyin[1]--;
			if(Yuyin[1]<1)
			{
				Yuyin[1]=1;
			}
			W25QXX_Write_16(Yuyin,91,4);		//将当前语音参数写入到flash中
			yinling(Yuyin[1]);//音量选择
		}
		//语速选择
		else if(PLC_OutPut[22]==1)//语速+
		{
			Yuyin[2]++;
			if(Yuyin[2]>9)
			{
				Yuyin[2]=9;
			}
			W25QXX_Write_16(Yuyin,91,4);		//将当前语音参数写入到flash中
			yusu(Yuyin[2]);//语速选择
		}
		else if(PLC_OutPut[23]==1)//语速-
		{
			Yuyin[2]--;
			if(Yuyin[2]<1)
			{
				Yuyin[2]=1;
			}
			W25QXX_Write_16(Yuyin,91,4);		//将当前语音参数写入到flash中
			yusu(Yuyin[2]);//语速选择
		}
		//语调选择
		else if(PLC_OutPut[20]==1)//语调+
		{
			Yuyin[3]++;
			if(Yuyin[3]>9)
			{
				Yuyin[3]=9;
			}
			W25QXX_Write_16(Yuyin,91,4);		//将当前语音参数写入到flash中
			yudiao(Yuyin[3]);//语调选择
		}
		else if(PLC_OutPut[21]==1)//语调-
		{
			Yuyin[3]--;
			if(Yuyin[3]<1)
			{
				Yuyin[3]=1;
			}
			W25QXX_Write_16(Yuyin,91,4);		//将当前语音参数写入到flash中
			yudiao(Yuyin[3]);//语调选择
		}
		

		switch(yuyin_flag)
		{
			case 0:break;
			case 1:
				{
					yuyin_flag=0;
					speek("自动");
					//osdelay_s(1);
					break;
				}
			case 2:
				{
					yuyin_flag=0;
					speek("手动");
					//osdelay_s(1);
					break;
				}
			case 3:
				{
					yuyin_flag=0;
					speek("前进");
					//osdelay_s(2);
					break;
				}
			case 4:
				{
					yuyin_flag=0;
					speek("后退左");
					//osdelay_s(2);
					break;
				}
			case 5:
				{
					yuyin_flag=0;
					speek("后退右");
					//osdelay_s(2);
					break;
				}
			case 6:
				{
					yuyin_flag=0;
					speek("停止");
					//osdelay_s(1);
					break;
				}
			case 7:
				{
					yuyin_flag=0;
					speek("启动");
					//osdelay_s(1);
					break;
				}
			case 8:
				{
					yuyin_flag=0;
					speek("左分叉");
					//osdelay_s(2);
					break;
				}
			case 9:
				{
					yuyin_flag=0;
					speek("中分叉");
					//osdelay_s(2);
					break;
				}
			case 10:
				{
					yuyin_flag=0;
					speek("右分叉");
					//osdelay_s(2);
					break;
				}
			case 11:
				{
					yuyin_flag=0;
					speek("叉臂上升");
					//osdelay_s(2);
					break;
				}
			case 12:
				{
					yuyin_flag=0;
					speek("叉臂下降");
					//osdelay_s(2);
					break;
				}
			case 13:
			{
				yuyin_flag=0;
				speek("遥控前进");
				break;
			}
			case 14:
			{
				yuyin_flag=0;
				speek("遥控后退");
				break;
			}
			case 15:
			{
				yuyin_flag=0;
				speek("前方有障碍，请清除");
				break;
			}
			case 16:
			{
				yuyin_flag=0;
				speek("障碍已清除");
				break;
			}
			case 17:
			{
				yuyin_flag=0;
				speek("前方有障碍，请小心驾驶");
				break;
			}
			case 18:
			{
				yuyin_flag=0;
				speek("复位ok");
				break;
			}
			case 19:
			{
				yuyin_flag=0;
				speek("去一楼");
				break;
			}
			case 20:
			{
				yuyin_flag=0;
				speek("左转");
				break;
			}
			case 21:
			{
				yuyin_flag=0;
				speek("右转");
				break;
			}
			
		}

		osdelay_ms(20);
	}
}

//Cansend任务函数：与扩展板的通信
void Cansend_task(void *p_arg)
{
	p_arg = p_arg;
	
	while(1)
	{
		CanSend();
		osdelay_ms(20);
	}
}

//RunLED任务函数：各种系统运行指示灯
void RunLED_task(void *p_arg)
{
	p_arg = p_arg;
	while(1)
	{
		LED1=1;							//单片机运行指示
		PLC_OutPut[1]=1;		//屏幕运行指示
		osdelay_ms(300);
		LED1=0;
		PLC_OutPut[1]=0;
		osdelay_ms(300);
	}
}

//RFID任务函数：扫到地标后蜂鸣器响一下
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


//YAOKONG任务函数：遥控控制叉车时的任务段
void YAOKONG_task(void *p_arg)
{
	u8 last_MAIN=0,last_FRONT=0,last_BACK=0,last_LIFT=0,last_RIGHT=0,last_UP=0,last_DOWN=0;
	u8 TZ_flag=0,LIFT_flag=0,RIGHT_flag=0;
	u16 deg_num=597;//左转角度变换	正常是579
	u16 speed_num=500;//
	
	u8 ykqbz_flag=0,ykhbz_flag=0;
	
	p_arg = p_arg;                        
	                                      
	while(1)                              
	{  		
		if(HmiTask==0)
		{
			if(Mode_flag==1)                    
			{                                   
				if(last_MAIN==0&&MAIN==1)//当遥控上的急停按下时
				{
					Ting_Zhi();
				}
				if(START==0&&QD_flag==0)//在遥控器上按启动则车启动
				{
					Qi_Dong();
				}
				if(QD_flag==0)//在自动停止状态时遥控才有用
				{
					if(FRONT==1&&BACK==1&&TZ_flag==0)
					{
						tingzhi();
						TZ_flag=1;
					}
					else if(last_FRONT==1&&FRONT==0)//遥控前进
					{
						qianjin();
						yuyin_flag=13;
						TZ_flag=0;
					}
					else if(last_BACK==1&&BACK==0)//遥控后退
					{
						houtui();
						yuyin_flag=14;
						TZ_flag=0;
					}
					else 
					{
						;
					}	
					
					if(LIFT==0)//左转
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
						PWM_val(TIM4,4,deg_num);	//方向PWM
						if(deg_num<400)
						{
							speed_num+=2;
							if(speed_num>950)
							{
								speed_num=950;
							}	
							PWM_val(TIM4,2,speed_num);//设定速度PWM
						}
					}
					else if(RIGHT==0)//右转
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
						PWM_val(TIM4,4,deg_num);	//方向PWM
						if(deg_num>700)
						{
							speed_num+=2;
							if(speed_num>950)
							{
								speed_num=950;
							}
							PWM_val(TIM4,2,speed_num);//设定速度PWM
						}
					}
					else//回正
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
						PWM_val(TIM4,4,deg_num);	//方向PWM
						PWM_val(TIM4,2,speed_num);//设定速度PWM
					}
					
					///////////////遥控避障处理开始//////////////////////
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
								if(ykqbz_flag==1)//从触发到不触发时只执行一次
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
					///////////////遥控避障处理结束/////////////////	
						
						
					if(last_LIFT==0&&LIFT==1)//当左松开时将接近开关开启开关标志清0
					{
						LIFT_flag=0;
					}
					else if(last_RIGHT==0&&RIGHT==1)//当右松开时将接近开关开启开关标志清0
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
				CBX=1;					//关闭叉臂下降的继电器
				osdelay_ms(50);
				CBS=0;					//打开叉臂上升的继电器
				yuyin_flag=11;
			}
			else if(last_UP==0&&UP==1)
			{
				CBS=1;
				CBX=1;
			}
			if(last_DOWN==1&&DOWN==0)
			{
				CBS=1;					//关闭叉臂上升的继电器			
				osdelay_ms(50);
				CBX=0;					//打开叉臂下降的继电器
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


void AGV_QuYiLou()//AGV去一楼函数
{	
		//先停车，并呼叫电梯到三楼，等电梯到三楼并且门开到位再进电梯；AGV进到位后再让电梯下一楼（一楼外呼则矣）；到一楼后等到门全部打开时行驶
		Ting_Zhi();							
		PLC2_Data[18]=0;//三楼外呼按钮
		while(PLC2_Data[24]!=0)//三楼平层（电梯在三楼）（0:电梯在三楼 1:电梯不在三楼）
		{
			osdelay_ms(20);
		}
		PLC2_Data[22]=10;				//开门信号赋值为10以便调度系统确认门敞开
		while(PLC2_Data[26]!=1) //等待三楼门开到位 三楼门状态（开1/关0）
		{
			osdelay_ms(20);
		}
		Qian_Jin();
		osdelay_ms(SPEEKTIME);
		Qi_Dong();
		ture_numL=0;//清除左叉臂突变计数
		ture_numR=0;//清除右叉臂突变计数
		//等待叉车AGV进电梯到位（包括三种到位模式：地标3、左叉臂突变和右叉臂突变）
		while(keynumber!=HmiDianTiDiBiao3&&ture_numL<1&&ture_numR<1)
		{
			osdelay_ms(20);
		}
		osdelay_ms(500);
		HmiRfidNum = HmiDianTiDiBiao1;
		Ting_Zhi();							//停止
		PLC2_Data[22]=1;//开门信号置1以便电梯门不是常开状态
		PLC2_Data[23]=0;//关门
		PLC2_Data[19]=0;//一楼外呼按钮
		while(PLC2_Data[25]!=0)//一楼平层（电梯在一楼）（0:电梯在一楼 1:电梯不在一楼）
		{
			osdelay_ms(20);
		}
		PLC2_Data[22]=10;				//开门信号赋值为10以便调度系统确认门敞开
		while(PLC2_Data[27]!=1)//一楼门状态（开1/关0）
		{
			osdelay_ms(20);
		}
		Qian_Jin();
		osdelay_ms(SPEEKTIME);
		Qi_Dong();
		osdelay_ms(SPEEKTIME);	

		while(keynumber!=HmiChuDianTiDiBiao)//三楼门状态（开1/关0）
		{	
			osdelay_ms(20);
		}
		HmiRfidNum = HmiDianTiDiBiao1;
		PLC2_Data[22]=1;//开门信号置1以便电梯门不是常开状态
		PLC2_Data[23]=0;//关门	
}


void AGV_QuSanLou()//AGV去三楼函数
{
		//先停车，并呼叫电梯到一楼，等电梯到一楼并且门开到位再进电梯；AGV进到位后再让电梯去三楼（三楼外呼则矣）；到三楼后等到门全部打开时行驶
		Ting_Zhi();							
		PLC2_Data[19]=0;//一楼外呼按钮
		while(PLC2_Data[25]!=0)//一楼平层（电梯在一楼）（0:电梯在一楼 1:电梯不在一楼）
		{
			osdelay_ms(20);
		}
		PLC2_Data[22]=10;				//开门 信号赋值为10以便调度系统确认门敞开
		while(PLC2_Data[27]!=1) //等待一楼门开到位 一楼门状态（开1/关0）
		{
			osdelay_ms(20);
		}
		Qian_Jin();
		osdelay_ms(SPEEKTIME);
		Qi_Dong();
		ture_numL=0;//清除左叉臂突变计数
		ture_numR=0;//清除右叉臂突变计数
		//等待叉车AGV进电梯到位（包括三种到位模式：地标3、左叉臂突变和右叉臂突变）
		while(keynumber!=HmiDianTiDiBiao1&&ture_numL<3&&ture_numR<3)
		{
			osdelay_ms(20);
		}
		osdelay_ms(500);
		HmiRfidNum = HmiDianTiDiBiao1;
		Ting_Zhi();							//停止
		PLC2_Data[22]=1;//开门信号置1以便电梯门不是常开状态
		PLC2_Data[18]=0;//三楼外呼按钮		
		PLC2_Data[23]=0;//关门

		while(PLC2_Data[24]!=0)//三楼平层（电梯在三楼）（0:电梯在三楼 1:电梯不在三楼）
		{
			osdelay_ms(20);
		}
		PLC2_Data[22]=10;				//开门信号赋值为10以便调度系统确认门敞开
		while(PLC2_Data[26]!=1)//三楼门状态（开1/关0）
		{
			osdelay_ms(20);
		}
		Qian_Jin();
		osdelay_ms(SPEEKTIME);
		Qi_Dong();
		osdelay_ms(SPEEKTIME);
		while(keynumber!=HmiChuDianTiDiBiao)//三楼门状态（开1/关0）
		{	
			osdelay_ms(20);
		}
		HmiRfidNum = HmiDianTiDiBiao1;
		PLC2_Data[22]=1;//开门信号置1以便电梯门不是常开状态
		PLC2_Data[23]=0;//关门		
}





//执行站点动作
void StationAction(u16 num)
{
	u16 RfidNum = 0;//检测到的RFID号
	//启动，自动
	while(QD_flag != 1 || Mode_flag != 1)
	{
		osdelay_ms(20);
	}
	
	HmiStationSerialNum++;
	//清空地标
	keynumber=0;
	ture_numL = 0;
	ture_numR = 0;
	ture_numF = 0;
	
	//目标地标显示
	HmiNextRfidNum = NowRouteInfor[num][5];
	
	//等待目标地标
	while(RfidNum!=NowRouteInfor[num][5])	//扫到地标，是目标值的话则跳出while
	{				
		if(Mode_flag == 1)//自动模式下检测地标，手动模式下不检测地标
		{
			if(keynumber!=0)
			{
				RfidNum = keynumber;
				//如果是速度地标,更改速度
				if(keynumber == 4)//二挡
				{
					speed = HmiZhongSu;//速度赋值,中速
				}
				else
				if(keynumber == 5)//三挡
				{
					speed = HmiGaoSu;//速度赋值,高速
				}
				
				keynumber = 0;
			}
			
			//虚拟地标检测
			//左
			if(NowRouteInfor[num][12]&&ture_numL==NowRouteInfor[num][15])
			{
				RfidNum = NowRouteInfor[num][5];
			}
			//右
			if(NowRouteInfor[num][13]&&ture_numR==NowRouteInfor[num][16])
			{
				RfidNum = NowRouteInfor[num][5];
			}
			//前
			if(NowRouteInfor[num][14]&&ture_numF==NowRouteInfor[num][17])
			{
				RfidNum = NowRouteInfor[num][5];
			}		
		}

		osdelay_ms(20);	
	}

	HmiRfidNum = keynumber;
	switch(NowRouteInfor[num][6])//停止、前进、后退左、后退右、左旋、右旋	
	{
		case 0:	break;//保持上次信息
		case 1://停止
		case 2://前进
		case 3://后退左
		case 4://后退右
		case 6://左旋
		case 7://右旋						
		{
			Ting_Zhi();
			osdelay_ms(SPEEKTIME);
		}break;	
		case 5:break;//通过				
	}			
	switch(NowRouteInfor[num][4])//速度档位判断
	{
		case 0:	break;//保持上次信息
		case 1://低速
		{
			speek("1挡");
			speed=HmiDiSu;
			osdelay_ms(SPEEKTIME);
		}break;					
		case 2://中速
		{
			speek("2挡");
			speed=HmiZhongSu;
			osdelay_ms(SPEEKTIME);
		}break;				
		case 3://高速
		{
			speek("3挡");
			speed=HmiGaoSu;
			osdelay_ms(SPEEKTIME);						
		}break;					
	}
	switch(NowRouteInfor[num][0])//远红外开关判断
	{
		case 0:	break;//保持上次信息
		case 1://远红外开
		{
			QBZ_Yflag=0;
			speek("远开");	
			osdelay_ms(SPEEKTIME);						
		}break;					
		case 2://远红外关
		{
			QBZ_Yflag=1;
			speek("远关");
			osdelay_ms(SPEEKTIME);						
		}break;							
	}				
	switch(NowRouteInfor[num][1])//近红外开关判断
	{
		case 0:	break;//保持上次信息
		case 1://近红外开
		{
			QBZ_Jflag=0;
			speek("近开");
			osdelay_ms(SPEEKTIME);						
		}break;					
		case 2://近红外关
		{
			QBZ_Jflag=1;
			speek("近关");
			osdelay_ms(SPEEKTIME);						
		}break;								
	}

	switch(NowRouteInfor[num][19])//叉臂红外开关判断
	{
		case 0:	break;//保持上次信息
		case 1://开
		{
			HBZ_flag = 0;
			speek("后开");
			osdelay_ms(SPEEKTIME);						
		}break;					
		case 2://关
		{
			HBZ_flag=1;
			speek("后关");
			osdelay_ms(SPEEKTIME);						
		}break;								
	}	
	
	switch(NowRouteInfor[num][2])//分叉判断
	{
		case 0:	break;//保持上次信息
		case 1://左分叉
		{
			Zuo_Fen();
			osdelay_ms(SPEEKTIME);						
		}break;	
		case 2://右分叉
		{
			You_Fen();
			osdelay_ms(SPEEKTIME);						
		}break;			
	}
	
	
	switch(NowRouteInfor[num][3])//叉臂上下判断
	{
		case 0:	break;//保持上次信息
		case 1://叉臂上升
		{
			Cha_Sheng();	
		}break;	
		case 2://叉臂下降
		{
			Cha_Jiang();
		}break;			
									
	}

	
	//判断是否需要延时
	if(NowRouteInfor[num][8]!=0)
		osdelay_s(NowRouteInfor[num][8]);
	
	switch(NowRouteInfor[num][11])//与机械手设备通信
	{
		case 0:	
			//没有请求进入
			PLC2_Data[32] = 0;
			break;//没有与设备交互
		case 1://和一号设备交互
		{
			//向设备发送请求进入信号
			PLC2_Data[32] = NowRouteInfor[num][11];
			Ting_Zhi();
			osdelay_ms(SPEEKTIME);
			speek("请求进入");
			osdelay_s(1);
			//等待准入信号
			while(PLC2_Data[33]!=1)
			{
				osdelay_ms(10);
			}
			speek("允许进入");
			osdelay_s(1);
			
			Qi_Dong();
			
			//清除请求进入信号			
			PLC2_Data[32] = 0;
			//清空准入信号
			PLC2_Data[33] = 0;
		}break;					
		case 2://和二号设备交互
		{
			//向设备发送请求进入信号
			PLC2_Data[32] = NowRouteInfor[num][11];
			speek("请求进入");
			osdelay_s(1);
			//等待准入信号
			while(PLC2_Data[34]!=1)
			{
				osdelay_ms(10);
			}
			speek("允许进入");
			osdelay_s(1);			
			
			Qi_Dong();
			
			//清除请求进入信号			
			PLC2_Data[32] = 0;			
			//清空准入信号
			PLC2_Data[34] = 0;
		}break;			
		case 3://和三号设备交互
		{
			//向设备发送请求进入信号
			PLC2_Data[32] = NowRouteInfor[num][11];
			speek("请求进入");
			osdelay_s(1);
			//等待准入信号
			while(PLC2_Data[35]!=1)
			{
				osdelay_ms(10);
			}
			speek("允许进入");
			osdelay_s(1);
			
			Qi_Dong();
			
			//清除请求进入信号			
			PLC2_Data[32] = 0;	
			//清空准入信号
			PLC2_Data[35] = 0;
		}break;			
		case 4://和四号设备交互
		{
			//向设备发送请求进入信号
			PLC2_Data[32] = NowRouteInfor[num][11];
			speek("请求进入");
			osdelay_s(1);
			//等待准入信号
			while(PLC2_Data[36]!=1)
			{
				osdelay_ms(10);
			}
			speek("允许进入");
			osdelay_s(1);
			
			Qi_Dong();
			
			//清除请求进入信号			
			PLC2_Data[32] = 0;			
			//清空准入信号
			PLC2_Data[36] = 0;
		}break;		
	}
	
	switch(NowRouteInfor[num][7])//进入设备工作区
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
	
	switch(NowRouteInfor[num][18])//设备给AGV发送的启动信号
	{
		case 0://不等待	
			break;
		case 1://等待一号设备
			while(PLC2_Data[42]==0)
			{
				osdelay_ms(10);
			}	
		break;		
		case 2://等待二号设备
			while(PLC2_Data[43]==0)
			{
				osdelay_ms(10);
			}
			break;		
		case 3://等待三号设备
			while(PLC2_Data[44]==0)
			{
				osdelay_ms(10);
			}
			break;		
		case 4://等待四号设备
			while(PLC2_Data[45]==0)
			{
				osdelay_ms(10);
			}
			break;	
	}
	
	
	//AGV对电梯的使用情况
	switch(NowRouteInfor[num][10])
	{
		case 0:	break;//电梯不使用
		case 1://AGV去一楼
		{
			AGV_QuYiLou();
		}break;				
		case 2://AGV去三楼
		{
			AGV_QuSanLou();
		}break;	
	}

	switch(NowRouteInfor[num][6])//动作执行再判断	
	{
			case 0:	break;//保持上次信息
			case 1: break;//停止
			case 2://前进
			{
				Qian_Jin();
				osdelay_ms(SPEEKTIME);
				Qi_Dong();
				osdelay_ms(SPEEKTIME);
			}break;	
			case 3://后退左
			{
				Hou_Zuo();
				osdelay_ms(SPEEKTIME);
				Qi_Dong();
				osdelay_ms(SPEEKTIME);
			}break;
			case 4://后退右
			{
				Hou_You();
				osdelay_ms(SPEEKTIME);
				Qi_Dong();
				osdelay_ms(SPEEKTIME);
			}break;
			case 6://左旋
			{
				Xuan_Zhuang_Ci_Shu = NowRouteInfor[num][9];
				last_flag=FX_flag;
				osdelay_ms(SPEEKTIME);
				QD_flag=1;
				//旋转后方向
				if(NowRouteInfor[num][18]==0)//保持
				{
					zuoxuan(last_flag);
				}
				else
				{
					zuoxuan(NowRouteInfor[num][18]);
				}
			}break;
			case 7://右旋
			{
				Xuan_Zhuang_Ci_Shu = NowRouteInfor[num][9];
				last_flag=FX_flag;
				osdelay_ms(SPEEKTIME);
				QD_flag=1;
				//旋转后方向
				if(NowRouteInfor[num][18]==0)//保持
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
	

//切换方向为前进
void go()
{
//	FX_flag=1;//前进
	QBZ_Yflag=0;//开远避障
	FC_flag = 2;//右分叉
	speed = HmiZhongSu;
}

//执行任务
void Task5_task(void *p_arg)
{	
	u16 i,j,k;
	p_arg = p_arg;

	while(1)
	{
		if(Mode_flag == 1&&QD_flag==1)//自动模式并且启动
		{
			//执行路径
			if(HmiTask==1)
			{
				go();
				
				//清除当前地标
				HmiRfidNum = 0;
				HmiStationSerialNum = 0;
				//根据所选路径，执行相应动作
				for(i=0;i<HmiStationNum;i++)
				{
					StationAction(i);
				}
				HmiTask = 0;
				
				//清除请求进入
				PLC2_Data[32] = 0;
				//清除设备内信号
				PLC2_Data[38] = 0;	
				PLC2_Data[39] = 0;	
				PLC2_Data[40] = 0;	
				PLC2_Data[41] = 0;
			}
			else
			{
				//执行流程
				if(HmiTask == 2)
				{
					go();
					//清除当前地标
					HmiRfidNum = 0;
					HmiProcessSerialNum = 0;
					for(i=0;i<HmiStepNum;i++)
					{
						HmiProcessSerialNum++;
						switch(NowProcessInfor[i][1])
						{
							case 0://单次执行
								//更新路径号
								HmiRouteNum = NowProcessInfor[i][0];
							  //获取路径包含站点数
								GetRouteStationNum(HmiRouteNum);
								//获取当前路径信息
								GetRouteData(HmiRouteNum);

  							HmiStationSerialNum = 0;
								//根据所选路径，执行相应动作
								for(j=0;j<HmiStationNum;j++)
								{
									StationAction(j);
								}
								break;
							case 1://顺序执行
								for(k=NowProcessInfor[i][0];k<=NowProcessInfor[i][2];k++)
								{
									//更新路径号
									HmiRouteNum = k;
									//获取路径包含站点数
									GetRouteStationNum(HmiRouteNum);
									//获取当前路径信息
									GetRouteData(HmiRouteNum);
									
									HmiStationSerialNum = 0;
									//根据所选路径，执行相应动作
									for(j=0;j<HmiStationNum;j++)
									{
										StationAction(j);
									}
								}
								break;
							case 2://倒序执行
								for(k=NowProcessInfor[i][0];k>=NowProcessInfor[i][2];k--)
								{
									//更新路径号
									HmiRouteNum = k;
									//获取路径包含站点数
									GetRouteStationNum(HmiRouteNum);
									//获取当前路径信息
									GetRouteData(HmiRouteNum);
  
									HmiStationSerialNum = 0;
 									//根据所选路径，执行相应动作
									for(j=0;j<HmiStationNum;j++)
									{
										StationAction(j);
									}
								}
								break;
							case 3://循环执行
								//更新路径号
								HmiRouteNum = NowProcessInfor[i][0];
							  //获取路径包含站点数
								GetRouteStationNum(HmiRouteNum);
								//获取当前路径信息
								GetRouteData(HmiRouteNum);
								for(k=0;k<NowProcessInfor[i][2];k++)
								{
    							HmiStationSerialNum = 0;
									//根据所选路径，执行相应动作
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
					//清除请求进入
					PLC2_Data[32] = 0;
					//清除设备内信号
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
	//获取所有系统参数
	GetAllParameterFromSystem();

	if(SystemParameter[0]!=6)//首次flash中没数据时先刷入初始量
	{
		#if 1						//为前100个内存中写入初始量
		SystemParameter[0]=6;	//判断是否第一次写入的标志
		SystemParameter[1]=0;
		SystemParameter[2]=0;
		SystemParameter[3]=0;
		SystemParameter[4]=5;//左旋角度
		SystemParameter[5]=5;//右旋角度
		SystemParameter[6]=400;		//初始速度
		SystemParameter[7]=0;     
		SystemParameter[8]=15;    //前进方向Kp
		SystemParameter[9]=300;   //前进方向Ki
		SystemParameter[10]=0;    //前进方向Kd
		SystemParameter[11]=10;   //前进方向的PID控制周期
		SystemParameter[12]=579;  //叉车的舵轮中值
		SystemParameter[13]=0;    //叉臂Kp
		SystemParameter[14]=0;    //叉臂Ki
		SystemParameter[15]=0;    //叉臂Kd
		SystemParameter[16]=0;    
		SystemParameter[17]=0;    
		SystemParameter[18]=250; //低速    
		SystemParameter[19]=340; //中速   
		SystemParameter[20]=400; //高速   
		SystemParameter[21]=0;    
		SystemParameter[22]=0;    
		SystemParameter[23]=0;    
		SystemParameter[24]=1;  //路径号
		SystemParameter[25]=1;  //流程号  
		SystemParameter[26]=0;  //任务号  
		SystemParameter[27]=1;  //电梯地标1 
		SystemParameter[28]=3;  //电梯地标3  
		SystemParameter[29]=2;  //出电梯地标
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
		SystemParameter[52]=1;//叉车号    
		SystemParameter[53]=0;    
		SystemParameter[54]=0;    
		SystemParameter[55]=0;    
		SystemParameter[56]=0;    
		SystemParameter[57]=0;    
		SystemParameter[58]=0;    
		SystemParameter[59]=2;    //叉臂上升时间
		
		SystemParameter[60]=40;   //叉臂方向的控制系数
		SystemParameter[61]=45;   //叉臂方向的控制系数
		SystemParameter[62]=50;   //叉臂方向的控制系数
		SystemParameter[63]=60;   //叉臂方向的控制系数
		SystemParameter[64]=65;   //叉臂方向的控制系数
		SystemParameter[65]=80;   //叉臂方向的控制系数
		SystemParameter[66]=95;   //叉臂方向的控制系数
		SystemParameter[67]=100;  //叉臂方向的控制系数
		SystemParameter[68]=105;  //叉臂方向的控制系数
		SystemParameter[69]=120;  //叉臂方向的控制系数
		SystemParameter[70]=135;  //叉臂方向的控制系数
		SystemParameter[71]=140;  //叉臂方向的控制系数
		SystemParameter[72]=150;  //叉臂方向的控制系数
		SystemParameter[73]=155;  //叉臂方向的控制系数
		SystemParameter[74]=160;  //叉臂方向的控制系数
		SystemParameter[75]=55;   //叉臂方向的控制系数
		SystemParameter[76]=145;  //叉臂方向的控制系数
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
		
		//存储所有系统参数
		SetAllParameterToSystem();
		
		//清除路径包含站点数
		memset(RouteStationNum,0,RouteNum);
		//保存所有路径包含的站点数
		SetAllStationNum();
		
		//清除流程包含步数
		memset(ProcessStepNum,0,ProcessNum);
		//保存所有流程包含的步数
		SetAllStepNum();
	}
	
	
	
	STATIONNUM_170M = PLC_Data[52]= SystemParameter[52];//叉车号
	STATIONNUM_170M+=1;
	
	PLC_Data[60]= SystemParameter[60];		//叉臂方向的调节系数
	PLC_Data[61]= SystemParameter[61];    //叉臂方向的调节系数
	PLC_Data[62]= SystemParameter[62];    //叉臂方向的调节系数
	PLC_Data[63]=	SystemParameter[63];    //叉臂方向的调节系数
	PLC_Data[64]=	SystemParameter[64];    //叉臂方向的调节系数
	PLC_Data[65]=	SystemParameter[65];    //叉臂方向的调节系数
	PLC_Data[66]= SystemParameter[66];    //叉臂方向的调节系数
	PLC_Data[67]= SystemParameter[67];    //叉臂方向的调节系数
	PLC_Data[68]= SystemParameter[68];    //叉臂方向的调节系数
	PLC_Data[69]=	SystemParameter[69];    //叉臂方向的调节系数
	PLC_Data[70]=	SystemParameter[70];    //叉臂方向的调节系数
	PLC_Data[71]=	SystemParameter[71];    //叉臂方向的调节系数
	PLC_Data[72]= SystemParameter[72];    //叉臂方向的调节系数
	PLC_Data[73]= SystemParameter[73];    //叉臂方向的调节系数
	PLC_Data[74]= SystemParameter[74];    //叉臂方向的调节系数
	PLC_Data[75]= SystemParameter[75];    //叉臂方向的调节系数
	PLC_Data[76]= SystemParameter[76];    //叉臂方向的调节系数
			
	
	PID.Kp = PLC_Data[8]	=	SystemParameter[8];			//初始化屏幕的PID参数kp
	PID.Ki = PLC_Data[9] = SystemParameter[9];     //初始化屏幕的PID参数ki
	PID.Kd = PLC_Data[10]= SystemParameter[10];    //初始化屏幕的PID参数kd
	                               
	PID4.Kp = PLC_Data[13]=	SystemParameter[13];		//初始化屏幕的PID4参数kp后磁导航 
	PID4.Ki = PLC_Data[14]= SystemParameter[14];    //初始化屏幕的PID4参数ki后磁导航 
	PID4.Kd = PLC_Data[15]= SystemParameter[15];    //初始化屏幕的PID4参数kd后磁导航	 
	                               	
	PLC_Data[6] =	SystemParameter[6];     //更新屏幕的速度显示值
	PLC_Data[11] = SystemParameter[11];		//测试前进的PID控制周期
	
	HmiDiSu    = SystemParameter[18];		//一档速度 
	HmiZhongSu = SystemParameter[19];   //二档速度
	HmiGaoSu   = SystemParameter[20];   //三档速度
	
	HmiRouteNum   = SystemParameter[24]; //路径号
	HmiProcessNum = SystemParameter[25]; //流程号
//	HmiTask       = SystemParameter[26]; //任务号
	HmiTask  = 0;
	
	HmiDianTiDiBiao1   =	SystemParameter[27];  //电梯地标1 
	HmiDianTiDiBiao3   =	SystemParameter[28];  //电梯地标3  
	HmiChuDianTiDiBiao =	SystemParameter[29];  //出电梯地标
	
	PLC_Data[12] = SystemParameter[12]; //舵机中值
	
	PLC_Data[59] = SystemParameter[59];//叉臂上升时间
	
	//加载自动界面信息
	HmiAutoReload();
	  
	speed=PLC_Data[6]; 								//更新屏幕的速度显示值
//	PWM_val(TIM4,2,speed);				 	//设定速度PWM赋值给车
	time=PLC_Data[11];			       		//测试前进的PID控制周期
	
	low_speed 	 = HmiDiSu ;	 				//一档速度 
	middle_speed = HmiZhongSu ;				//二档速度
	high_speed	 = HmiGaoSu ;  				//三档速度
	
	PLC_Data[98] =	SystemParameter[4];//左旋角度
	PLC_Data[99] =	SystemParameter[5];//右旋角度
	//获取路径包含站点数
	GetRouteStationNum(HmiRouteNum);

	//获取当前路径信息
	GetRouteData(HmiRouteNum);
		
	//获取及更新流程数据
	GetProcessData();
}


//执行流程
void ActiveProcess()
{
	//保存流程号
	SetOneParameterToSystem(HmiProcessNum,25);
	SystemParameter[26] = HmiTask;
	//保存任务号
	SetOneParameterToSystem(HmiTask,26);
	
	//任务状态为正在运行
	HmiTaskState = 5;

	HmiTask = 2;
	
	//加载自动界面信息
	HmiAutoReload();
		
	
	FX_flag=1;//方向切换到前进
	
	//跳转到自动界面
	HmiScreenSetGet = ZiDongJieMian;
}

//屏幕任务
	u32 mima=0;
void Task6_task(void *p_arg)
{
	u16 i,j;
	OS_ERR err;
	p_arg = p_arg;
	UserConfigInit();		//用户参数初始化
	//电梯按钮初始化
	PLC2_Data[18]=1;//三楼外呼按钮
	PLC2_Data[19]=1;//一楼外呼按钮
	PLC2_Data[20]=1;//3按钮
	PLC2_Data[21]=1;//1按钮
	PLC2_Data[22]=1;//开门
	PLC2_Data[23]=1;//关门
	
	while(1)
	{	 	
		switch(HmiScreenSetGet)
		{
			case 9: //手动控制界面的操作
						{						
							while(HmiScreenSetGet == 9)
							{
								if(PLC_OutPut[4]==1)						//屏幕的手动按键按下时
								{
									Shou_Dong();		//切到手动程序
								}
								else if(PLC_OutPut[5]==1)				//屏幕的自动按键按下时
								{
									Zi_Dong();			//切到自动程序
								}
								else if(PLC_OutPut[9]==1)				//叉臂上升按钮按下时
								{
									Cha_Sheng();
								} 
								else if(PLC_OutPut[10]==1)			//叉臂下降按钮按下时
								{
									Cha_Jiang();
								}
								else if(PLC_OutPut[13]==1)			//左分叉按钮按下时
								{
									Zuo_Fen();
								}
								else if(PLC_OutPut[14]==1)			//右分叉按钮按下时
								{
									You_Fen();
								}		

								if(Mode_flag == 1)
								{
									if(PLC_OutPut[11]==1)			//启动
									{
										Qi_Dong();
									}
									if(PLC_OutPut[12]==1)		 	//停止
									{
										Ting_Zhi();
									}
									else if(PLC_OutPut[6]==1)	//由屏上的前进按钮确定控制叉车的行驶方向标志FX_flag
									{
										Qian_Jin();
									}
									else if(PLC_OutPut[7]==1) //由屏上的后退左按钮确定控制叉车的行驶方向标志FX_flag
									{
										Hou_Zuo();
									}
									else if(PLC_OutPut[8]==1) //由屏上的后退右按钮确定控制叉车的行驶方向标志FX_flag
									{
										Hou_You();
									}	

								}
								/*********当屏幕上参数发生改变时记录参数到flash开始********/
								if(speed!=PLC_Data[6])
								{
									speed = PLC_Data[6];									//更新屏幕的速度显示值
									Ruan_Qi(SPEED_min,speed);					//设定速度PWM赋值给车
																									
									SystemParameter[6] = speed;
									
									SetOneParameterToSystem(SystemParameter[6],6);
								}
								/*********当屏幕上参数发生改变时记录参数到flash结束********/
								
								osdelay_ms(10);
							}																
						}break;
			case 11://系统参数界面，速度的档位设置
						{
							while(HmiScreenSetGet == 11)
							{
								low_speed 	 = HmiDiSu;	  //一档速度 
								middle_speed = HmiZhongSu; //二档速度
								high_speed	 = HmiGaoSu;   //三档速度
												
								SystemParameter[18] = HmiDiSu;
								SystemParameter[19] = HmiZhongSu;
								SystemParameter[20] = HmiGaoSu;
								
								//车号
								STATIONNUM_170M = PLC_Data[52]+1;
								SystemParameter[52]=PLC_Data[52];

								//电梯地标设置
								SystemParameter[27] =	HmiDianTiDiBiao1  ;         //电梯地标1 
								SystemParameter[28] =	HmiDianTiDiBiao3  ;         //电梯地标3  
								SystemParameter[29] =	HmiChuDianTiDiBiao;         //出电梯地标
								
								SystemParameter[4] =	PLC_Data[98];//左旋角度
								SystemParameter[5] = PLC_Data[99];//右旋角度
								
								SystemParameter[59] = PLC_Data[59];//叉臂上升时间

								osdelay_ms(10);
							}
							
							W25QXX_Write_16(SystemParameter,0,SystemParaNum);	//将当前屏幕参数写入到flash中
						}break;
			case 13://各个传感器的状态更新到屏幕上
						{
							PLC_OutPut[25]=CBBZ2;	//叉臂红外避障2（左叉臂）
							PLC_OutPut[26]=CBJC2; //叉臂货物到位红外检测2（左叉臂）
							PLC_OutPut[27]=CBBZ1; //叉臂红外避障1（右叉臂）
							PLC_OutPut[28]=CBJC1; //叉臂货物到位红外检测1（右叉臂）
							PLC_OutPut[29]=QBZ2N; //红外避障2	:近避障（前避障）
							PLC_OutPut[30]=QBZ2F; //红外避障2	:远避障（前避障）
							PLC_OutPut[46]=JXBZ;  //机械避障
						}break;
			case 14://电梯调试界面(在车上对电梯的一切进行操控和显示电梯状态)
						{
								if(PLC_OutPut[31]==1)//三楼外呼按钮
								{
									PLC2_Data[18]=0;
								}
								else if(PLC_OutPut[32]==1)//一楼外呼按钮
								{
									PLC2_Data[19]=0;
								}
								else if(PLC_OutPut[33]==1)//3按钮
								{
									PLC2_Data[20]=0;
								}
								else if(PLC_OutPut[34]==1)//1按钮
								{
									PLC2_Data[21]=0;
								}
								else if(PLC_OutPut[35]==1)//开门
								{
									PLC2_Data[22]=0;
								}
								else if(PLC_OutPut[36]==1)//关门
								{
									PLC2_Data[23]=0;
								}
								PLC_OutPut[37]=PLC2_Data[24];//三楼平层（电梯在三楼）
								PLC_OutPut[38]=PLC2_Data[25];//一楼平层（电梯在一楼）
								PLC_OutPut[39]=PLC2_Data[26];//三楼门状态（开/关）
								PLC_OutPut[40]=PLC2_Data[27];//一楼门状态（开/关）
						}break;
			case 15://数据测试窗口执行
						{
							while(HmiScreenSetGet == 15)
							{
																		
								PID.Kp = PLC_Data[8];		              //更新屏幕的PID参数kp
								PID.Ki = PLC_Data[9];                 //更新屏幕的PID参数ki
								PID.Kd = PLC_Data[10];                //更新屏幕的PID参数kd
																											
								PID4.Kp = PLC_Data[13];	              //更新屏幕的PID4参数kp
								PID4.Ki = PLC_Data[14];               //更新屏幕的PID4参数ki
								PID4.Kd = PLC_Data[15];               //更新屏幕的PID4参数kd
							
								time=PLC_Data[11];										//测试前进的PID控制周期
								speed=PLC_Data[6];										//更新屏幕的速度显示值
								Ruan_Qi(SPEED_min,speed);							//速度赋值
								
								SystemParameter[11]= PLC_Data[11];
								SystemParameter[8] = PLC_Data[8];
								SystemParameter[9] = PLC_Data[9];
								SystemParameter[10]= PLC_Data[10];
								SystemParameter[13]= PLC_Data[13];
								SystemParameter[14]= PLC_Data[14];
								SystemParameter[15]= PLC_Data[15];
								SystemParameter[6] = PLC_Data[6];
								
								SystemParameter[12] = PLC_Data[12]; //舵机中值	
								osdelay_ms(10);
							}
							
							W25QXX_Write_16(SystemParameter,0,90);			//将当前屏幕参数写入到flash中
						}break;
			case 23:
						{
							//如果路径号为零，则置一
							if(HmiRouteNum==0)
							{
								HmiRouteNum = 1;
							}
						}break;
			case 19:
			case 20:	
			case 24: 
			case 25://路径设置
						{	
								while(HmiScreenSetGet==19||HmiScreenSetGet==20||HmiScreenSetGet==24||HmiScreenSetGet==25||HmiScreenSetGet==FuZhiLuJingTanChuJieMian)
								{  
									//复制路径
									if(HmiScreenSetGet==FuZhiLuJingTanChuJieMian)
									{
										//被复制路径号初始化为1
										HmiRouteCopiedNum = 1;
										while(HmiScreenSetGet==FuZhiLuJingTanChuJieMian)//处于复制路径界面
										{
											//被复制路径号为零时置1
											if(HmiRouteCopiedNum==0)
												HmiRouteCopiedNum=1;	
											if(HmiRouteCopiedNum>RouteNum)
											{
												HmiRouteCopiedNum = 1;
											}
											
											//输入的被复制流程号变化时更新
											if(HmiRouteCopiedNumTemp!=HmiRouteCopiedNum)
												HmiRouteCopiedCount = GetRouteStationNum(HmiRouteCopiedNum);
											
											
											//确定复制
											if(HmiRoutemode==1)
											{
												//读取被复制信息到当前
												GetRouteData(HmiRouteCopiedNum);
												
												//保存并更新被复制信息
												SetRouteData(HmiRouteNum);	
												
												UpdataStationToHmi();
												
												//设置当前站点为1
												if(HmiStationNum!=0)
													HmiStationSerialNum = 1;
												
												//退出复制模式
												HmiRoutemode=0;
											}
											osdelay_ms(10);
										}
									}

									//添加站点
									if(HmiRoutemode==2)
									{ 
										//站点数加一
										HmiStationNum ++;
										//站点号等于站点数
										HmiStationSerialNum = HmiStationNum;
										
										//地标号清零
										keynumber = 0;		
										
										ClearStationToHmi();	
										
										while(HmiRoutemode==2)
										{
											//如果读到地标，更新到显示器
											if(keynumber!=0)
											{
												HmiRfidNum = keynumber;//刷新地标号
											}			
											
											//确定
											if(HmiRouteEnter==1)
											{
												HmiRouteEnter = 0;
												//更新站点数据到当前数据
												UpdataStationToNow();
												//保存当前站点数据
												SetRouteData(HmiRouteNum);
												//退出添加模式
												HmiRoutemode=	0;
											}
											else
											//取消
											if(HmiRouteEnter==2)
											{
												HmiRouteEnter = 0;
												//站点数减一
												HmiStationNum--;
												//站点号等于站点数
												HmiStationSerialNum = HmiStationNum;
												//退出添加模式
												HmiRoutemode=	0;
											}
											osdelay_ms(10);
										}
									}
									//插入站点
									if(HmiRoutemode==3)
									{
										//站点数加一
										HmiStationNum ++;
										//站点号为零时加一
										if(HmiStationNum==0)
											HmiStationSerialNum = 1;
										
										//地标号清零
										keynumber = 0;		
										
										ClearStationToHmi();										

										while(HmiRoutemode==3)
										{
											//如果读到地标，更新到显示器
											if(keynumber!=0)
											{
												HmiRfidNum = keynumber;//刷新地标号
											}												
											
											//确定
											if(HmiRouteEnter==1)
											{
												HmiRouteEnter = 0;
												
												//站点信息向后移动一个位置，并插入当前站点信息
												for(i=HmiStationNum;i>=HmiStationSerialNum;i--)
												{
													for(j=0;j<StaiionInfor;j++)
													{
														NowRouteInfor[i][j] = NowRouteInfor[i-1][j];
													}
												}
												
												//更新站点信息到当前
												UpdataStationToNow();
												
												//保存路径信息
												SetRouteData(HmiRouteNum);

												//退出添加模式
												HmiRoutemode=	0;
											}
											else
											//取消
											if(HmiRouteEnter==2)
											{
												HmiRouteEnter = 0;
												//站点数减一
												HmiStationNum--;
												//站点号为1时置零
												if(HmiStationSerialNum==1)
													HmiStationSerialNum = 0;
												//退出添加模式
												HmiRoutemode=	0;
											}

											osdelay_ms(10);
										}

									}
									//更改站点
									if(HmiRoutemode==4)
									{ 
										keynumber = 0;
										while(HmiRoutemode==4)
										{
											//如果读到地标，更新到显示器
											if(keynumber!=0)
											{
												HmiRfidNum = keynumber;//刷新地标号
											}			
											
											//确定
											if(HmiRouteEnter==1)
											{
												HmiRouteEnter = 0;
												//更新站点数据到当前数据
												UpdataStationToNow();
												//保存当前站点数据
												SetRouteData(HmiRouteNum);
												//退出添加模式
												HmiRoutemode=	0;
											}
											else
											//取消
											if(HmiRouteEnter==2)
											{
												HmiRouteEnter = 0;
												//更新到界面
												UpdataStationToHmi();
												//退出添加模式
												HmiRoutemode=	0;
											}
											osdelay_ms(10);
										}
									}
								
									//删除站点
									if(HmiRoutemode==5)
									{
										if(HmiStationNum>0)
										{
											//将后面所数据向前移动一位
											if((HmiStationNum>0)&&((HmiStationNum)!=HmiStationSerialNum))
											{
												//站点信息向前移动一个位置
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
											//保存路径信息
											SetRouteData(HmiRouteNum);
											
											//更新界面
											UpdataStationToHmi();
										}	
										HmiRoutemode = 0;
									}
									
									//查询站点
									if(HmiRoutemode==0)
									{
										//当路径站点数大于0，并且序号为0时，设置序号为1，并更新显示内容
										if((HmiStationNum>0)&&(HmiStationSerialNum==0))
										{
											HmiStationSerialNum = 1;
											//更新到界面
											UpdataStationToHmi();
										}
										else
										if(HmiStationNum==0)
										{
											HmiStationSerialNum = 0;
										}
										
										//路径号变化时，更新界面
										if(HmiRouteNumFlag != HmiRouteNum)
										{
											HmiRouteNumFlag = HmiRouteNum;
											//获取路径信息
											GetRouteData(HmiRouteNum);
											if(HmiStationNum>0)
												HmiStationSerialNum = 1;
											//更新到界面
											UpdataStationToHmi();
										}
										
										//上一个
										if(HmiStationLast == 1)
										{
											HmiStationLast = 0;
											if(HmiStationSerialNum>1)
												HmiStationSerialNum--;
											else
												HmiStationSerialNum = HmiStationNum;
										}
										//下一个
										if(HmiStationNext == 2)
										{
											HmiStationNext = 0;
											if(HmiStationSerialNum<HmiStationNum)
													HmiStationSerialNum++;
												else
													if(HmiStationSerialNum!=0)
														HmiStationSerialNum = 1;
										}
										
										if(HmiStationNum==0)		//没有站点
										{
											//清除站点信息
											ClearStationToHmi();
										}
										else
										{
											//更新站点信息
											UpdataStationToHmi();
										}
									}
									osdelay_ms(10);
								}
						}break;
			case 26://叉臂磁导航数据调试
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
									
									W25QXX_Write_16(&SystemParameter[60],60,17);			//将当前屏幕参数写入到flash中
							}
						}break;				
			case LiuChengGuiHuaJieMian://流程设置
			case FuZhiLiuChengTanChuJieMian:
			case QueDingChaRuLiuChengJieMian:
			case QueDingShanChuLiuChengJieMian:
						{
								while(HmiScreenSetGet==LiuChengGuiHuaJieMian||HmiScreenSetGet==FuZhiLiuChengTanChuJieMian||HmiScreenSetGet==QueDingChaRuLiuChengJieMian||HmiScreenSetGet==QueDingShanChuLiuChengJieMian)
								{ 
									//查看模式
									if(HmiProcessMode==0)
									{
										//当前流程步数大于0，并且界面序号为0时，设置序号为1，并更新显示内容
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
										
										//流程号变化时，更新界面
										if(HmiProcessNumFlag != HmiProcessNum)
										{
											HmiProcessNumFlag = HmiProcessNum;
											GetProcessData();
										}
										
										if(HmiProcessLast==1)//上一个
										{
											HmiProcessLast = 0;
											if(HmiProcessSerialNum>1)
												HmiProcessSerialNum--;
											else
												HmiProcessSerialNum = HmiStepNum;
										}
										else
											if(HmiProcessNext==2)//下一个
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
									
									//复制流程
									if(HmiScreenSetGet==FuZhiLiuChengTanChuJieMian)
									{
										//初始化别复制流程为1
										HmiProcessCopiedNum = 1;
										while(HmiScreenSetGet==FuZhiLiuChengTanChuJieMian)
										{
											//被复制流程号为零时置1
											if(HmiProcessCopiedNum==0)
												HmiProcessCopiedNum=1;	
											if(HmiProcessCopiedNum > ProcessNum)
												HmiProcessCopiedNum=1;	
											
											//输入的被复制流程号变化时更新
											if(HmiProcessCopiedNumTemp!=HmiProcessCopiedNum)
												HmiProcessCopiedCount = GetProcessStepNum(HmiProcessCopiedNum);
											
											//确定复制
											if(HmiProcessMode==1)
											{
												//读取被复制信息到当前
												GetProcessDataFrom(HmiProcessCopiedNum);
												//保存被复制信息
												SetProcessData();	
												
												//设置当前序号为1
												if(HmiStepNum!=0)
													HmiProcessSerialNum = 1;
											
												//退出复制模式
												HmiProcessMode = 0;
											}
											osdelay_ms(10);
										}
									}
									
									//添加流程
									if(HmiProcessMode==2)
									{
										//流程步数加一
										HmiStepNum++;
										//序号等于流程数
										HmiProcessSerialNum = HmiStepNum;
										
										ClearStepToHmi();

										while(HmiProcessMode==2)
										{
											switch(HmiProcessAction)
											{
												case 0://单次执行
													break;
												case 1://顺序执行到
													if(HmiProcessStopNum<=HmiProcessStartNum)
													{
														if(HmiProcessStartNum==ProcessNum)
															HmiProcessStopNum=HmiProcessStartNum;
														else
															HmiProcessStopNum=HmiProcessStartNum+1;
													}
													break;
												case 2://倒序执行
													if(HmiProcessStopNum>=HmiProcessStartNum)
													{
														if(HmiProcessStartNum==1)
															HmiProcessStopNum=HmiProcessStartNum;
														else
															HmiProcessStopNum=HmiProcessStartNum-1;
													}
													break;
												case 3://循环执行
													if(HmiProcessStopNum==0)
													{
															HmiProcessStopNum=1;
													}
													break;
												default:break;
											}
											
											//确定
											if(HmiProcessEnter==1)
											{
												HmiProcessEnter = 0;
												//保存并更新数据
												SetProcessData();
												
												//退出添加模式
												HmiProcessMode = 0;
											}
											//取消
											else if(HmiProcessEnter==2) 
											{
												HmiProcessEnter = 0;
												
												//流程步数减一
												HmiStepNum--;
												//序号等于流程数
												HmiProcessSerialNum = HmiStepNum;
												
												//退出添加模式
												HmiProcessMode = 0;
											}
											osdelay_ms(10);
										}
									}
									
									
									//插入流程
									if(HmiProcessMode==3)
									{
										//流程步数加一
										HmiStepNum++;
										//序号为零时加一
										if(HmiProcessSerialNum==0)
											HmiProcessSerialNum = 1;
										
										ClearStepToHmi();
										
										while(HmiProcessMode==3)
										{
											switch(HmiProcessAction)
											{
												case 0://单次执行
													break;
												case 1://顺序执行到
													if(HmiProcessStopNum<=HmiProcessStartNum)
													{
														if(HmiProcessStartNum==ProcessNum)
															HmiProcessStopNum=HmiProcessStartNum;
														else
															HmiProcessStopNum=HmiProcessStartNum+1;
													}
													break;
												case 2://倒序执行
													if(HmiProcessStopNum>=HmiProcessStartNum)
													{
														if(HmiProcessStartNum==1)
															HmiProcessStopNum=HmiProcessStartNum;
														else
															HmiProcessStopNum=HmiProcessStartNum-1;
													}
													break;
												case 3://循环执行
													if(HmiProcessStopNum==0)
													{
															HmiProcessStopNum=1;
													}
													break;
												default:break;
											}
											
											//确定
											if(HmiProcessEnter==1)
											{
												HmiProcessEnter = 0;
												
												//保存并更新数据
												InsertProcessData();
												
												//退出插入模式
												HmiProcessMode = 0;
											}
											//取消
											else if(HmiProcessEnter==2) 
											{
												HmiProcessEnter = 0;
												
												//流程步数减一
												HmiStepNum--;
												//序号为1时减一
												if(HmiProcessSerialNum==1)
													HmiProcessSerialNum = 0;
												
												//退出添加模式
												HmiProcessMode = 0;
											}
											osdelay_ms(10);
										}
									}									
									
									//更改流程
									if(HmiProcessMode==4)
									{
										while(HmiProcessMode==4)
										{
											switch(HmiProcessAction)
											{
												case 0://单次执行
													break;
												case 1://顺序执行到
													if(HmiProcessStopNum<=HmiProcessStartNum)
													{
														if(HmiProcessStartNum==ProcessNum)
															HmiProcessStopNum=HmiProcessStartNum;
														else
															HmiProcessStopNum=HmiProcessStartNum+1;
													}
													break;
												case 2://倒序执行
													if(HmiProcessStopNum>=HmiProcessStartNum)
													{
														if(HmiProcessStartNum==1)
															HmiProcessStopNum=HmiProcessStartNum;
														else
															HmiProcessStopNum=HmiProcessStartNum-1;
													}
													break;
												case 3://循环执行
													if(HmiProcessStopNum==0)
													{
															HmiProcessStopNum=1;
													}
													break;
												default:break;
											}
											
											//确定
											if(HmiProcessEnter==1)
											{
												HmiProcessEnter = 0;
												//保存并更新数据
												SetProcessData();
												
												//退出更改模式
												HmiProcessMode = 0;
											}
											//取消
											else if(HmiProcessEnter==2) 
											{
												HmiProcessEnter = 0;

												//退出添加模式
												HmiProcessMode = 0;
											}
											osdelay_ms(10);
										}
									}									
									
									//删除流程
									if(HmiProcessMode==5)
									{
										DeleteProcessData();
										//退出删除模式
										HmiProcessMode = 0;
									}
									
									osdelay_ms(10);
								}
						}break;
			case LiuChengSheZhiJieMian: 
							{		
								//如果路径号为零，则置一
								if(HmiProcessNum==0)
								{
									HmiProcessNum = 1;
								}
							}
							break;
			case ZhiXingLuJingJieMian: //执行路径
							{		
								while(HmiScreenSetGet==ZhiXingLuJingJieMian)
								{
									if(ZhiXingLuJingQueDing==1)
									{
										//保存路径号
										SetOneParameterToSystem(HmiRouteNum,24);
										SystemParameter[26] = HmiTask;
										//保存任务号
										SetOneParameterToSystem(HmiTask,26);
										ZhiXingLuJingQueDing = 0;
										
										//加载自动界面信息
										HmiAutoReload();
										
										HmiTask = 1;
										
										FX_flag=1;//方向切换到前进

										//跳转到自动界面
										HmiScreenSetGet = ZiDongJieMian;
									}
									osdelay_ms(10);
								}
							}
							break;
			case ZhiXingLiuChengJieMian: //执行流程
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
			case ZiDongJieMian: //自动界面
							{		
								while(HmiScreenSetGet==ZiDongJieMian)
								{
									if(PLC_OutPut[4]==1)						//屏幕的手动按键按下时
									{
										Shou_Dong();		//切到手动程序
									}
									else if(PLC_OutPut[5]==1)				//屏幕的自动按键按下时
									{
										Zi_Dong();			//切到自动程序
									}
									if(Mode_flag == 1)
									{
											if(PLC_OutPut[11]==1)			//启动
											{
												Qi_Dong();
											}
											if(PLC_OutPut[12]==1)		 	//停止
											{
												Ting_Zhi();
											}
									}
									osdelay_ms(10);
								}		
							}
							break;	
			case QuXiaoRenWuJieMian: //取消任务
							{		
								while(HmiScreenSetGet==QuXiaoRenWuJieMian)
								{
									if(QuXiaoRenWuQueDing==1)
									{
										QuXiaoRenWuQueDing = 0;
										
										HmiTask = 0;
										
										//任务状态为空闲
										HmiTaskState = 0;
										
										//停车
										Ting_Zhi();
										
										//清除开门信号
										PLC2_Data[22]=1;//(1,弹起开门按钮，10，按下开门按钮)
										
										//切换方向标识为前进
										FX_flag=1;
										
										//清除请求进入
										PLC2_Data[32] = 0;
										//清除设备内信号
										PLC2_Data[38] = 0;	
										PLC2_Data[39] = 0;	
										PLC2_Data[40] = 0;	
										PLC2_Data[41] = 0;	
										
										//跳转界面，返回之前界面
										if(lastscreenNum!=0)
										{
											HmiScreenSetGet = lastscreenNum;
											lastscreenNum = 0;
										}
										else
											HmiScreenSetGet = 16;

										//删除任务
										OSTaskDel((OS_TCB*)&Task5_TaskTCB,&err);
										//重新创建任务
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
							
			case 48://开发者输入密码弹出窗口
						{
							//清除错误提示
							PLC_Data[104] = 0;
							while(HmiScreenSetGet==48)
							{
								//确定按钮按下
								if(PLC_Data[105]==1)
								{
									//密码正确,跳转到开发界面
									if(PLC_Data[103]==41320)
									{
										//提示密码正确
										PLC_Data[104] = 1;
										osdelay_s(1);
										HmiScreenSetGet = 8;
									}		
									else
									{
										//清除错误提示
										PLC_Data[104] = 0;
										osdelay_ms(200);
										//再次显示提示密码错误
										PLC_Data[104] = 2;
									}
									PLC_Data[105]=0;
								}
								osdelay_ms(20);
							}
						}
							break;
			case 47://首页
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
			case 49://空托盘搬运
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
							//执行流程
							ActiveProcess();
						}
						osdelay_ms(20);
					}
				}
				break;
			case 50://卸货入库
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
							//执行流程
							ActiveProcess();
						}
						osdelay_ms(20);
					}
				}
				break;
			case 51://搬运到三楼
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
							//执行流程
							ActiveProcess();
						}
						osdelay_ms(20);
					}
				}
				break;
			case 52://搬运到一楼
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
							//执行流程
							ActiveProcess();
						}
						osdelay_ms(20);
					}
				}
				break;
			case 53://粉碎间转运
				{
					HmiProcessNum = 25;
					while(HmiScreenSetGet==53)
					{
						if(PLC_Data[119]==1)
						{
							PLC_Data[119]=0;
							lastscreenNum = 53;
							//执行流程
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



//喂狗任务
void Task7_task(void *p_arg)
{
	p_arg = p_arg;
	while(1)
	{	
		//喂狗
		IWDG_Feed();
		osdelay_ms(100);
	}	

}


//数据通过170M无线发送至调度系统
void Task8_task(void *p_arg)
{
	u16 num=0;
	p_arg = p_arg;
	
	while(1)
	{
		PLC2_Data[0]=HmiRfidNum;				//地标上传
		PLC2_Data[17]=HmiNextRfidNum; //下一个地标
		
		PLC2_Data[1]=PLC_Data[3];	//将磁导航1数据发送到调度系统显示				
		PLC2_Data[2]=PLC_Data[4];	//将磁导航2数据发送到调度系统显示				
		PLC2_Data[3]=PLC_Data[5];	//将磁导航3数据发送到调度系统显示			
		PLC2_Data[9]=speed;	//速度实时显示于调度系统
		
		
		PLC2_Data[10]=CBBZ2;	//叉臂红外避障2（左叉臂）
		PLC2_Data[11]=CBBZ1;	//叉臂红外避障1（右叉臂）
		PLC2_Data[12]=CBJC2;	//叉臂货物到位红外检测2（左叉臂）
		PLC2_Data[13]=CBJC1;	//叉臂货物到位红外检测1（右叉臂）
		PLC2_Data[14]=QBZ2F;	//红外避障2	:远避障（前避障）
		PLC2_Data[15]=QBZ2N;	//红外避障2	:近避障（前避障）
		PLC2_Data[16]=JXBZ;		//机械避障
		
		PLC2_Data[28]=HmiRouteNum;//当前叉车的路径号
		
		PLC2_Data[29]=HmiProcessNum;//当前叉车的流程号

		//车的运行状态更新在调度系统
		PLC2_Data[4]=QD_flag;
		
		//手动、自动运行模式上传
		PLC2_Data[8]=Mode_flag;
		
		//启动
		if(PLC2_Data[30]==55)
		{
			Qi_Dong();
			PLC2_Data[30]=0;
		}
		
		//停止
		if(PLC2_Data[31]==55)
		{
			Ting_Zhi();
			PLC2_Data[31]=0;
		}		
		
		//出轨故障更新在调度系统
		if(FX_flag==1&&QD_flag==0&&front_cdh16.Num==0)			//前进时出轨则上传有故障
		{
			PLC2_Data[5]=1;//有故障置1
		}
		else if(FX_flag==1&&QD_flag==0&&front_cdh16.Num!=0) //前进时不出轨则上传无故障
		{
			PLC2_Data[5]=0;//无故障清0
		}
		
		if(FX_flag==2&&QD_flag==0&&backl_cdh8.Num==0)				//后退左时出轨则上传有故障
		{
			PLC2_Data[6]=1;//有故障置1
		}
		else if(FX_flag==2&&QD_flag==0&&backl_cdh8.Num!=0)	//后退左时不出轨则上传无故障
		{
			PLC2_Data[6]=0;//无故障清0
		}
		
		if(FX_flag==3&&QD_flag==0&&backr_cdh8.Num==0)				//后退右时出轨则上传有故障
		{
			PLC2_Data[7]=1;//有故障置1
		}
		else if(FX_flag==3&&QD_flag==0&&backr_cdh8.Num!=0)	//后退右时不出轨则上传无故障
		{
			PLC2_Data[7]=0;//无故障清0
		}

		if(Mode_flag==0&&((PLC2_Data[5]+PLC2_Data[6]+PLC2_Data[7])!=0))
		{
			PLC2_Data[5]=0;//无故障清0
			PLC2_Data[6]=0;//无故障清0
			PLC2_Data[7]=0;//无故障清0
		}
		
		//100*20ms清除一次在线状态
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



//红外避障、传感器等安全保护任务 、面板上的停止
void Task9_task(void *p_arg)
{
	//单独前进远红外、近红外、同时检测红外，同时不检测红外的标志
	u8 qbz_yflag=0,qbz_jflag=0,qbz_flag=0,t_flag=0;
	//为消除从一种避障状态切为另一种时的作用
	u8 qbz_yflag1=0,qbz_jflag1=0,qbz_flag1=0;
	u8 hbz_flag=0;//后退方向的避障开启时一旦触发时的执行动作的限制
	u8 jxbz_flag=0;//机械避障的避障开启时一旦触发时的执行动作的限制
	u8 last_mbtz=0;//面板停止上次的状态
	
	p_arg = p_arg;

	while(1)
	{
		if(Mode_flag==1)												//在自动模式下才有可能进行避障检测
		{		
			if(last_mbtz==1&&MBTZ==0&&QD_flag==1) //在行走状态、面板停止按下时
			{
				Ting_Zhi();
				//任务状态
				HmiTaskState = 2;
			}	
			last_mbtz=MBTZ;		
			
			if(qj_flag==1)												//前进时检测前进方向的红外避障
			{
				if(JXBZ==1)//机械避障触发时
				{
					if(jxbz_flag==0)
					{
						bztingzhi();
						//任务状态
						HmiTaskState = 9;
						jxbz_flag=1;
						yuyin_flag=15;
					}
				}
				else			//机械避障未触发时
				{
					if(jxbz_flag==1)
					{
						bzqianjin();
						//任务状态
						HmiTaskState = 5;
						jxbz_flag=0;
						yuyin_flag=16;
					}
				}
				
				if(QBZ_Jflag==0&&QBZ_Yflag==1)//近开远关的时候
				{
					qbz_yflag=0,qbz_flag=0,t_flag=0;
					
					qbz_yflag1=0,qbz_flag1=0;
					
					if(qbz_jflag1==0)
					{
						bzqianjin();
						//任务状态
						HmiTaskState = 5;
						qbz_jflag1=1;
					}
					switch(QBZ2N) //近红外
					{
						case 0://触发时
									{
										if(qbz_jflag==0)//从不触发到触发时只执行一次
										{
											bztingzhi();
											//任务状态
											HmiTaskState = 2;
											qbz_jflag=1;
											yuyin_flag=15;
										}
									}break;
						case 1://不触发时
									{
										if(qbz_jflag==1)//从触发到不触发时只执行一次
										{
											bzqianjin();
											//任务状态
											HmiTaskState = 5;
											qbz_jflag=0;
											yuyin_flag=16;
										}
									}break;
					}
				}
				if(QBZ_Jflag==1&&QBZ_Yflag==0)//近关远开的时候
				{
					qbz_jflag=0,qbz_flag=0,t_flag=0;
					
					qbz_jflag1=0,qbz_flag1=0;
					
					if(qbz_yflag1==0)
					{
						bzqianjin();
						//任务状态
						HmiTaskState = 5;
						qbz_yflag1=1;
					}
					switch(QBZ2F)//远红外
					{
						case 0://触发时
									{
										if(qbz_yflag==0)//从不触发到触发时只执行一次
										{
											bztingzhi();
											//任务状态
											HmiTaskState = 2;
											qbz_yflag=1;
											yuyin_flag=15;
										}
									}break;
						case 1://不触发时
									{
										if(qbz_yflag==1)//从触发到不触发时只执行一次
										{
											bzqianjin();
											//任务状态
											HmiTaskState = 5;
											qbz_yflag=0;
											yuyin_flag=16;
										}
									}break;
					}
				}
				if(QBZ_Jflag==0&&QBZ_Yflag==0)//都开启的时候
				{
					qbz_yflag=0,qbz_jflag=0,t_flag=0;
					
					qbz_yflag1=0,qbz_jflag1=0;
					
					if(qbz_flag1==0)
					{
						bzqianjin();
						//任务状态
						HmiTaskState = 5;
						qbz_flag1=1;
					}
					switch(QBZ2N & QBZ2F) //远近与如果有一个为0则为触发
					{
						case 0://触发时
									{
										if(qbz_flag==0)//从不触发到触发时只执行一次
										{
											bztingzhi();
											//任务状态
											HmiTaskState = 2;
											qbz_flag=1;
											yuyin_flag=15;
										}
									}break;
						case 1://不触发时
									{
										if(qbz_flag==1)//从触发到不触发时只执行一次
										{
											bzqianjin();
											//任务状态
											HmiTaskState = 5;
											qbz_flag=0;
											yuyin_flag=16;
										}
									}break;
					}
				}
				if(QBZ_Jflag==1&&QBZ_Yflag==1)//都关闭的时候
				{
					if(t_flag==0)
					{
						bzqianjin();
						//任务状态
						HmiTaskState = 5;
						t_flag=1;
					}
					qbz_yflag=0,qbz_jflag=0,qbz_flag=0;
				}
			}
			else if(htz_flag==1||hty_flag==1)			//后退时检测后退方向的红外避障
			{
				if(HBZ_flag==0)//当叉臂避障打开时再对叉臂避障传感器进行检测并执行相应的动作
				{
					if(CBBZ1==0||CBBZ2==0)//叉臂避障任意一个触发时
					{
						if(hbz_flag==0)
						{
							bztingzhi();	
							//任务状态
						  HmiTaskState = 7;							
							hbz_flag=1;
							yuyin_flag=15;
						}
					}
					else	//两个叉臂避障传感器都不触发时
					{
						if(hbz_flag==1)
						{
							bzhoutui();
							//任务状态
							HmiTaskState = 5;
							hbz_flag=0;
							yuyin_flag=16;
						}
					}
				}
			}
			else 																	//当既不是前进又不是后退时则清除标志
			{
				qbz_yflag=0,qbz_jflag=0,qbz_flag=0;
				hbz_flag=0;
			}
		}
		osdelay_ms(20);
	}
	
}



//警示灯闪烁任务  ：通过控制Police_flag的0、1状态来控制警示灯闪烁与否
void Task10_task(void *p_arg)
{
	p_arg = p_arg;

	while(1)
	{	
		Police_flag=PLC_OutPut[17];
		if(Police_flag==0&&(PLC_Data[97]==0))//如果警示灯闪烁打开,并且在线时则闪烁
		{
			Police_led(900);
		}
		else				//否则灭灯
		{
			Police_LED=1;
		}
		osdelay_ms(20);
	}	

}



//复位单片机任务
void Task11_task(void *p_arg)
{
	u8 restnum=0;		//复位时间计数
	p_arg = p_arg;

	while(1)
	{	
		restnum=0;
		while(MBTZ==0&&restnum!=25) //长按即复位单片机
		{
			osdelay_ms(100);
			restnum ++;
		}
		if(restnum==25)							//长按即复位单片机
		{
			yuyin_flag=18;
			HmiScreenSetGet=8;						//屏幕回到首页
			osdelay_s(1);
			NVIC_SystemReset();	
		}
		osdelay_ms(20);
	}	

}


//磁导航计数
void Task12_task(void *p_arg)
{
	while(1)
	{	
		if(Mode_flag==1)//自动模式下才检测突变
		{
			//3:前，4:左,5:右		
			//前磁导航的突变计数累加值
			CDH3_data=PLC_Data[3];
			if(lastCDH3_data!=0x0000&&CDH3_data==0x0000)
			{
				osdelay_ms(50);//延时消抖
				if(CDH3_data==0x0000)
				{
					if(ture_numF<=100)
					{
						ture_numF++;
					}					
				}
			}
			lastCDH3_data=CDH3_data;
			
			//左叉臂的突变计数累加值
			CDH4_data=PLC_Data[4];
			if(lastCDH4_data!=0x00&&CDH4_data==0x00)
			{
				osdelay_ms(50);//延时消抖
				if(CDH4_data==0x0000)
				{
					if(ture_numL<=100)
					{
						ture_numL++;
					}
				}
			}
			lastCDH4_data=CDH4_data;
			
			//右叉臂的突变计数累加值
			CDH5_data=PLC_Data[5];
			if(lastCDH5_data!=0x00&&CDH5_data==0x00)
			{
				osdelay_ms(50);//延时消抖
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
	u8 h,m,s;		//复位时间计数
	p_arg = p_arg;

	while(1)
	{	
		//等待开始任务
		while(HmiTask==0)
		{
			osdelay_ms(10);
		}
		//开始计时
		h = 0;m = 0;s = 0;
		PLC_Data[102] = h;
		PLC_Data[100] = m;
		PLC_Data[101] = s;
		
		while(HmiTask!=0)
		{
			//手动不计时
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
			
			//更新到界面
			PLC_Data[102] = h;
			PLC_Data[100] = m;
			PLC_Data[101] = s;
		}
	}	

}




