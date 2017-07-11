#include "pid.h"
#include "Modbus_slave.h"
#include "math.h"


u8 cdh_num=0;
u8 mmm_flag=0,mmm_flag1=0,mmm_flag2=0;
struct Agv_Pid PID,PID1,PID4;
/***********************************************/
//PID变量初始化
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

//叉臂PID
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
//位置式PID计算
//公式:U(k) = Kp*[E(n)] + Ki*SumError + Kd*[E(n)-E(n-1)]
//参数说明:Error = E(n) 
/*******************************************************/
int PosPIDCalc(u8 NextTarget,u8 num)
{
	int Error1;
	int Out;
	switch(num)
	{
		case 1:
				{
					PID.Error = PID.SetTarget - NextTarget;			//E(n)当前偏差E(n)	
					
					PID.SumError +=PID.Error;										//SumError比例
					
					if(PID.SumError>1000.0)											//缓解积分饱和情况
					{
						PID.SumError=1000.0;
					}
					if(PID.SumError<-1000.0)
					{
						PID.SumError=-1000.0;
					}
				
					Error1 = PID.Error - PID.LastError;					//[E(n)-E(n-1)]微分

					PID.LastError = PID.Error;									//更新偏差值
					
//					PLC_Data[12]=PID.SumError;								//显示积分项在屏上的电量框

					Out = (int)(PID.Kp*PID.Error + (PID.Ki/1000.0)*PID.SumError + PID.Kd*Error1);
					
//					PLC_Data[13]=PID.Kp*PID.Error;							//显示P向总共
//					PLC_Data[14]=(PID.Ki/1000.0)*PID.SumError;	//显示I向总共
//					PLC_Data[15]=PID.Kd*Error1;               	//显示D向总共
					
				}break;
		case 2:
				{
					PID1.Error = PID1.SetTarget - NextTarget;		//E(n)当前偏差E(n)	
					
					PID1.SumError +=PID1.Error;									//SumError比例
					
					if(PID1.SumError>1000.0)										//缓解积分饱和情况
					{
						PID1.SumError=1000.0;
					}
					if(PID1.SumError<-1000.0)
					{
						PID1.SumError=-1000.0;
					}
					
					Error1 = PID1.Error - PID1.LastError;				//[E(n)-E(n-1)]微分

					PID1.LastError = PID1.Error;								//更新偏差值
					
					PLC_Data[12]=PID.SumError;									//显示积分项在屏上的电量框

					Out = (int)(PID1.Kp*PID1.Error + (PID1.Ki/1000.0)*PID1.SumError + PID1.Kd*Error1);

//					PLC_Data[13]=PID.Kp*PID.Error;							//显示P向总共
//					PLC_Data[14]=(PID.Ki/1000.0)*PID.SumError;	//显示I向总共
//					PLC_Data[15]=PID.Kd*Error1;									//显示D向总共
					
					
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
						case 4://最边上4个点
									{
										if(cdh_num<=3)
										{
											Out=(int)(PLC_Data[12]*PLC_Data[75]/100.0);//从外面点变到这种状态
										}
										else if(cdh_num>3&&cdh_num<=8)
										{
											Out=(int)(PLC_Data[12]*PLC_Data[63]/100.0);//0.20//从中间点变到这种状态
											mmm_flag=1;
										}
										
									}break;
						case 5:
									{
										mmm_flag1=1;
										if(mmm_flag==1)								//两边到这个情况时
										{
											Out=(int)(PLC_Data[12]*PLC_Data[67]/100.0);//回正
										}
										else
										{
											Out=(int)(PLC_Data[12]*PLC_Data[64]/100.0);
										}//
									}break;
						case 6:
									{
										
										if(mmm_flag==1||mmm_flag1==1)								//两边到这个情况时
										{
											Out=(int)(PLC_Data[12]*PLC_Data[67]/100.0);//回正
										}
										else 
										{
											Out=(int)(PLC_Data[12]*PLC_Data[65]/100.0);//
										}
									}break;
						case 7:
									{
										if(mmm_flag==1||mmm_flag1==1)								//两边到这个情况时
										{
											Out=(int)(PLC_Data[12]*PLC_Data[67]/100.0);//回正
										}
										else 
										{
											Out=(int)(PLC_Data[12]*PLC_Data[66]/100.0);//
										}
									}break;
						case 8://最中间的四个点的情况
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
						case 12://最边上4个点
									{
										if(cdh_num<=12&&cdh_num>8)
										{	
											Out=(int)(PLC_Data[12]*PLC_Data[71]/100.0);//1.80//从中间点变到这种状态
											mmm_flag=1;
										}
										else if(cdh_num>=13)
										{
											Out=(int)(PLC_Data[12]*PLC_Data[76]/100.0);//从外面点变到这种状态
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
					if(Out>PLC_Data[12])//将多余的部分转换为舵机PWM限定只内
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
		case 4://叉臂pid
				{
					PID4.Error = PID4.SetTarget - NextTarget;			//E(n)当前偏差E(n)	
					
					PID4.SumError +=PID4.Error;										//SumError比例
					
					if(PID4.SumError>1000.0)											//缓解积分饱和情况
					{
						PID4.SumError=1000.0;
					}
					if(PID4.SumError<-1000.0)
					{
						PID4.SumError=-1000.0;
					}
				
					Error1 = PID4.Error - PID4.LastError;					//[E(n)-E(n-1)]微分

					PID4.LastError = PID4.Error;									//更新偏差值
					
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
//增量式PID计算
//公式:U(k+1)- u(K)=Kp*(E(n)-E(n-1)) + Ki*E(n) + Kd*(E(n)-2E(n-1)+E(n-2))
//参数说明:Error = E(n) 设置与实际的偏差量
/***********************************************/
int IncPIDCalc(u8 NextTarget)
{
	int Uk1;
	
	PID.Error = PID.SetTarget - NextTarget;		//E(n)
	Uk1 = PID.Kp*(PID.Error - PID.LastError) + PID.Ki*PID.Error + PID.Kd*(PID.Error - 2*PID.LastError+PID.PrevError);
	PID.PrevError = PID.LastError;			//更新误差值
	PID.LastError = PID.Error;	
	return(Uk1);
}
