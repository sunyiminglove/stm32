#include "control.h" 
#include "delay.h"
#include "pid.h"
#include "can.h"
#include "pwm.h"
#include "Modbus_slave.h"
#include "xf.h"	 
#include "route.h"	 

//�ϲ�����߷�����ƺ�����ʼ
void Zi_Dong(void)
{
	Mode_flag = 1;			//�е��Զ�����
	yuyin_flag=1;
	HmiScreenControlMode = Mode_flag;
}
void Shou_Dong(void)
{
	QD_flag=0;					//�е��ֶ�ǰ�ȷ���ֹͣ
	Mode_flag = 0;			//�е��ֶ�����
	yuyin_flag=2;
	HmiScreenControlMode = Mode_flag;
	HmiScreenRunState = 0;
}
void Qian_Jin(void)
{
	FX_flag=1;					//�����ϵ�ǰ����ťȷ�����Ʋ泵����ʻ�����־FX_flag
	yuyin_flag=3;
	HmiScreenRunState = 1;
}
void Hou_Zuo(void)
{
	FX_flag=2;					//�����ϵĺ�����ťȷ�����Ʋ泵����ʻ�����־FX_flag
	yuyin_flag=4;
	HmiScreenRunState = 1;
}
void Hou_You(void)
{
	FX_flag=3;					//�����ϵĺ����Ұ�ťȷ�����Ʋ泵����ʻ�����־FX_flag
	yuyin_flag=5;
	HmiScreenRunState = 1;
}
void Ting_Zhi(void)
{
	QD_flag=0;					//������־��0
	yuyin_flag=6;
	
	HmiScreenRunState = 0;
}
void Qi_Dong(void)
{
	//���û�����񣬵�����ʾ����
//	if(HmiTask==0)
//	{
//		HmiScreenSetGet = QiDongTiShiJieMian;
//	}
//	else
//	{
		QD_flag=1;				//������־��1
		PID.SumError=0;   //���ٴ������ǽ�PID��I������
		PID1.SumError=0;
		yuyin_flag=7;
		Ruan_Qi(SPEED_min,0);	//�趨�ٶ�PWM��ֵ����
//		PWM_val(TIM4,2,speed);//��������ʱ����Ļ�趨�ٶ��ٸ�ֵ������
		//����״̬Ϊ��������
		HmiTaskState = 5;
		HmiScreenRunState = 1;
//	}
}
void Zuo_Fen(void)
{
	FC_flag=1;				//�ֲ��־
	yuyin_flag=8;

}
void Zhong_Fen(void)
{
	FC_flag=0;				//�ֲ��־
	yuyin_flag=9;
}
void You_Fen(void)
{
	FC_flag=2;				//�ֲ��־
	yuyin_flag=10;

}
void Cha_Sheng(void)//CAN���Ƽ̵������ϵļ̵��������
{
	u8 ms;
	u8 s;
	
	CBX=1;					//�رղ���½��ļ̵���
	osdelay_ms(50);
	CBS=0;					//�򿪲�������ļ̵���
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
void Cha_Jiang(void)//CAN���Ƽ̵������ϵļ̵��������
{
	CBS=1;					//�رղ�������ļ̵���			
	osdelay_ms(50);
	CBX=0;					//�򿪲���½��ļ̵���
	yuyin_flag=12;
	osdelay_s(2);
	CBX=1;

}

//�ٶ�PWM��ֵ�жϺ���
//speed_min1������趨�ٶ�С�ڸ�����ֱ�ӽ��ٶ�ֵ��ֵ��PWM
//speed_zhi�� �����ٶ�ֵ
void Ruan_Qi(u16 speed_min1,u16 speed_zhi)
{	
		if(speed_zhi>speed_min1)		 //������
		{
			PWM_val(TIM4,2,speed_min1);
			osdelay_ms(20);
			PWM_val(TIM4,2,speed_zhi);
		}
		else												 //�ٶȵ�ʱֱ�Ӹ�ֵ
		{	
			PWM_val(TIM4,2,speed_zhi);//��������ʱ����Ļ�趨�ٶ��ٸ�ֵ������	
		}
}




