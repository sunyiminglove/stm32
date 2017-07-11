#include "control.h" 
#include "delay.h"
#include "pid.h"
#include "can.h"
#include "pwm.h"
#include "Modbus_slave.h"
#include "xf.h"	 
#include "route.h"	 

//上层的行走方向控制函数开始
void Zi_Dong(void)
{
	Mode_flag = 1;			//切到自动程序
	yuyin_flag=1;
	HmiScreenControlMode = Mode_flag;
}
void Shou_Dong(void)
{
	QD_flag=0;					//切到手动前先发个停止
	Mode_flag = 0;			//切到手动程序
	yuyin_flag=2;
	HmiScreenControlMode = Mode_flag;
	HmiScreenRunState = 0;
}
void Qian_Jin(void)
{
	FX_flag=1;					//由屏上的前进按钮确定控制叉车的行驶方向标志FX_flag
	yuyin_flag=3;
	HmiScreenRunState = 1;
}
void Hou_Zuo(void)
{
	FX_flag=2;					//由屏上的后退左按钮确定控制叉车的行驶方向标志FX_flag
	yuyin_flag=4;
	HmiScreenRunState = 1;
}
void Hou_You(void)
{
	FX_flag=3;					//由屏上的后退右按钮确定控制叉车的行驶方向标志FX_flag
	yuyin_flag=5;
	HmiScreenRunState = 1;
}
void Ting_Zhi(void)
{
	QD_flag=0;					//启动标志清0
	yuyin_flag=6;
	
	HmiScreenRunState = 0;
}
void Qi_Dong(void)
{
	//如果没有任务，弹出提示界面
//	if(HmiTask==0)
//	{
//		HmiScreenSetGet = QiDongTiShiJieMian;
//	}
//	else
//	{
		QD_flag=1;				//启动标志置1
		PID.SumError=0;   //当再次启动是将PID的I项清零
		PID1.SumError=0;
		yuyin_flag=7;
		Ruan_Qi(SPEED_min,0);	//设定速度PWM赋值给车
//		PWM_val(TIM4,2,speed);//当按启动时将屏幕设定速度再赋值给车。
		//任务状态为正在运行
		HmiTaskState = 5;
		HmiScreenRunState = 1;
//	}
}
void Zuo_Fen(void)
{
	FC_flag=1;				//分叉标志
	yuyin_flag=8;

}
void Zhong_Fen(void)
{
	FC_flag=0;				//分叉标志
	yuyin_flag=9;
}
void You_Fen(void)
{
	FC_flag=2;				//分叉标志
	yuyin_flag=10;

}
void Cha_Sheng(void)//CAN控制继电器板上的继电器叉臂上
{
	u8 ms;
	u8 s;
	
	CBX=1;					//关闭叉臂下降的继电器
	osdelay_ms(50);
	CBS=0;					//打开叉臂上升的继电器
	yuyin_flag=11;
	
	ms = (SystemParameter[59]%10)*100;
	s = SystemParameter[59]/10;
	if(s!=0&&s<10)
	{
		osdelay_s(s);
	}
	if(ms!=0)
	{
		osdelay_ms(ms);
	}
	CBS=1;

}
void Cha_Jiang(void)//CAN控制继电器板上的继电器叉臂下
{
	CBS=1;					//关闭叉臂上升的继电器			
	osdelay_ms(50);
	CBX=0;					//打开叉臂下降的继电器
	yuyin_flag=12;
	osdelay_s(2);
	CBX=1;

}

//速度PWM赋值判断函数
//speed_min1：如果设定速度小于改量则直接将速度值赋值给PWM
//speed_zhi： 欲赋速度值
void Ruan_Qi(u16 speed_min1,u16 speed_zhi)
{	
		if(speed_zhi>speed_min1)		 //软启动
		{
			PWM_val(TIM4,2,speed_min1);
			osdelay_ms(20);
			PWM_val(TIM4,2,speed_zhi);
		}
		else												 //速度低时直接赋值
		{	
			PWM_val(TIM4,2,speed_zhi);//当按启动时将屏幕设定速度再赋值给车。	
		}
}




