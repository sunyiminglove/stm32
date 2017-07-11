#include "pid.h"
#include "Modbus_slave.h"
#include "math.h"


u8 cdh_num=0;
u8 mmm_flag=0,mmm_flag1=0,mmm_flag2=0;
struct Agv_Pid PID,PID1,PID4;
/***********************************************/
//PID������ʼ��
/***********************************************/
void PID_Init(void)
{
	PID.SetTarget = 16;
	PID.SumError = 0;
	PID.Error = 0;
	PID.LastError = 0;
	PID.PrevError = 0;
	PID.Kp = 1.0;
	PID.Ki = 0.0;
	PID.Kd = 0.0;
}
void PID1_Init(void)
{
	PID1.SetTarget = 8;
	PID1.SumError = 0;
	PID1.Error = 0;
	PID1.LastError = 0;
	PID1.PrevError = 0;
	PID1.Kp = 1.0;
	PID1.Ki = 0.0;
	PID1.Kd = 0.0;
}

//���PID
void PID4_Init(void)
{
	PID4.SetTarget = 8;
	PID4.SumError = 0;
	PID4.Error = 0;
	PID4.LastError = 0;
	PID4.PrevError = 0;
	PID4.Kp = 1.0;
	PID4.Ki = 0.0;
	PID4.Kd = 0.0;
}
/******************************************************/
//λ��ʽPID����
//��ʽ:U(k) = Kp*[E(n)] + Ki*SumError + Kd*[E(n)-E(n-1)]
//����˵��:Error = E(n) 
/*******************************************************/
int PosPIDCalc(u8 NextTarget,u8 num)
{
	int Error1;
	int Out;
	switch(num)
	{
		case 1:
				{
					PID.Error = PID.SetTarget - NextTarget;			//E(n)��ǰƫ��E(n)	
					
					PID.SumError +=PID.Error;										//SumError����
					
					if(PID.SumError>1000.0)											//������ֱ������
					{
						PID.SumError=1000.0;
					}
					if(PID.SumError<-1000.0)
					{
						PID.SumError=-1000.0;
					}
				
					Error1 = PID.Error - PID.LastError;					//[E(n)-E(n-1)]΢��

					PID.LastError = PID.Error;									//����ƫ��ֵ
					
//					PLC_Data[12]=PID.SumError;								//��ʾ�����������ϵĵ�����

					Out = (int)(PID.Kp*PID.Error + (PID.Ki/1000.0)*PID.SumError + PID.Kd*Error1);
					
//					PLC_Data[13]=PID.Kp*PID.Error;							//��ʾP���ܹ�
//					PLC_Data[14]=(PID.Ki/1000.0)*PID.SumError;	//��ʾI���ܹ�
//					PLC_Data[15]=PID.Kd*Error1;               	//��ʾD���ܹ�
					
				}break;
		case 2:
				{
					PID1.Error = PID1.SetTarget - NextTarget;		//E(n)��ǰƫ��E(n)	
					
					PID1.SumError +=PID1.Error;									//SumError����
					
					if(PID1.SumError>1000.0)										//������ֱ������
					{
						PID1.SumError=1000.0;
					}
					if(PID1.SumError<-1000.0)
					{
						PID1.SumError=-1000.0;
					}
					
					Error1 = PID1.Error - PID1.LastError;				//[E(n)-E(n-1)]΢��

					PID1.LastError = PID1.Error;								//����ƫ��ֵ
					
					PLC_Data[12]=PID.SumError;									//��ʾ�����������ϵĵ�����

					Out = (int)(PID1.Kp*PID1.Error + (PID1.Ki/1000.0)*PID1.SumError + PID1.Kd*Error1);

//					PLC_Data[13]=PID.Kp*PID.Error;							//��ʾP���ܹ�
//					PLC_Data[14]=(PID.Ki/1000.0)*PID.SumError;	//��ʾI���ܹ�
//					PLC_Data[15]=PID.Kd*Error1;									//��ʾD���ܹ�
					
					
				}break;
		case 3:
				{
					switch(NextTarget)
					{
						case 1:
									{
										Out=(int)(PLC_Data[12]*PLC_Data[60]/100.0);//0.01
									}break;
						case 2:
									{
										Out=(int)(PLC_Data[12]*PLC_Data[61]/100.0);//0.02
									}break;
						case 3:
									{
										Out=(int)(PLC_Data[12]*PLC_Data[62]/100.0);//0.03
									}break;
						case 4://�����4����
									{
										if(cdh_num<=3)
										{
											Out=(int)(PLC_Data[12]*PLC_Data[75]/100.0);//�������䵽����״̬
										}
										else if(cdh_num>3&&cdh_num<=8)
										{
											Out=(int)(PLC_Data[12]*PLC_Data[63]/100.0);//0.20//���м��䵽����״̬
											mmm_flag=1;
										}
										
									}break;
						case 5:
									{
										mmm_flag1=1;
										if(mmm_flag==1)								//���ߵ�������ʱ
										{
											Out=(int)(PLC_Data[12]*PLC_Data[67]/100.0);//����
										}
										else
										{
											Out=(int)(PLC_Data[12]*PLC_Data[64]/100.0);
										}//
									}break;
						case 6:
									{
										
										if(mmm_flag==1||mmm_flag1==1)								//���ߵ�������ʱ
										{
											Out=(int)(PLC_Data[12]*PLC_Data[67]/100.0);//����
										}
										else 
										{
											Out=(int)(PLC_Data[12]*PLC_Data[65]/100.0);//
										}
									}break;
						case 7:
									{
										if(mmm_flag==1||mmm_flag1==1)								//���ߵ�������ʱ
										{
											Out=(int)(PLC_Data[12]*PLC_Data[67]/100.0);//����
										}
										else 
										{
											Out=(int)(PLC_Data[12]*PLC_Data[66]/100.0);//
										}
									}break;
						case 8://���м���ĸ�������
									{
										mmm_flag=0;
										mmm_flag1=0;
										mmm_flag2=0;
										Out=(int)(PLC_Data[12]*PLC_Data[67]/100.0);//1.00
									}break;
						case 9:
									{
										if(mmm_flag==1||mmm_flag1==1)
										{
											Out=(int)(PLC_Data[12]*PLC_Data[67]/100.0);//1.00
										}
										else 
										{
											Out=(int)(PLC_Data[12]*PLC_Data[68]/100.0);//1.05
										}
									}break;
						case 10:
									{
										
										if(mmm_flag==1||mmm_flag1==1)
										{
											Out=(int)(PLC_Data[12]*PLC_Data[67]/100.0);//1.00
										}
										else 
										{
											Out=(int)(PLC_Data[12]*PLC_Data[69]/100.0);//1.20
										}
									}break;
						case 11:
									{
										mmm_flag1=1;
										if(mmm_flag==1)
										{
											Out=(int)(PLC_Data[12]*PLC_Data[67]/100.0);//1.00
										}
										else 
										{
											Out=(int)(PLC_Data[12]*PLC_Data[70]/100.0);//1.70
										}
									
									}break;
						case 12://�����4����
									{
										if(cdh_num<=12&&cdh_num>8)
										{	
											Out=(int)(PLC_Data[12]*PLC_Data[71]/100.0);//1.80//���м��䵽����״̬
											mmm_flag=1;
										}
										else if(cdh_num>=13)
										{
											Out=(int)(PLC_Data[12]*PLC_Data[76]/100.0);//�������䵽����״̬
										}

									}break;
						case 13:
									{
										Out=(int)(PLC_Data[12]*PLC_Data[72]/100.0);//1.97
									}break;	   
						case 14:         
									{          
										Out=(int)(PLC_Data[12]*PLC_Data[73]/100.0);//1.98
									}break;	   
						case 15:         
									{          
										Out=(int)(PLC_Data[12]*PLC_Data[74]/100.0);//1.99
									}break;									
					}
					cdh_num=NextTarget;
					if(Out>PLC_Data[12])//������Ĳ���ת��Ϊ���PWM�޶�ֻ��
					{
						Out=(int)(((1000-PLC_Data[12])/(PLC_Data[12]*1.0))*Out+160);
					}
					
					if(Out<0)
					{
						Out=0;
					}
					if(Out>1000)
					{
						Out=1000;
					}
				}break;
		case 4://���pid
				{
					PID4.Error = PID4.SetTarget - NextTarget;			//E(n)��ǰƫ��E(n)	
					
					PID4.SumError +=PID4.Error;										//SumError����
					
					if(PID4.SumError>1000.0)											//������ֱ������
					{
						PID4.SumError=1000.0;
					}
					if(PID4.SumError<-1000.0)
					{
						PID4.SumError=-1000.0;
					}
				
					Error1 = PID4.Error - PID4.LastError;					//[E(n)-E(n-1)]΢��

					PID4.LastError = PID4.Error;									//����ƫ��ֵ
					
					Out = (int)(PID4.Kp*PID4.Error + (PID4.Ki/1000.0)*PID4.SumError + PID4.Kd*Error1);

					Out=PLC_Data[12]-Out;
					
					if(Out<0)
					{
						Out=0;
					}
					if(Out>1000)
					{
						Out=1000;
					}
				}break;
	}
	return(Out);
}

/***********************************************/
//����ʽPID����
//��ʽ:U(k+1)- u(K)=Kp*(E(n)-E(n-1)) + Ki*E(n) + Kd*(E(n)-2E(n-1)+E(n-2))
//����˵��:Error = E(n) ������ʵ�ʵ�ƫ����
/***********************************************/
int IncPIDCalc(u8 NextTarget)
{
	int Uk1;
	
	PID.Error = PID.SetTarget - NextTarget;		//E(n)
	Uk1 = PID.Kp*(PID.Error - PID.LastError) + PID.Ki*PID.Error + PID.Kd*(PID.Error - 2*PID.LastError+PID.PrevError);
	PID.PrevError = PID.LastError;			//�������ֵ
	PID.LastError = PID.Error;	
	return(Uk1);
}
