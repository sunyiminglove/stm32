#ifndef __PID_H
#define __PID_H
#include "sys.h"
/***********************************************/
//PID结构体定义
/***********************************************/
struct Agv_Pid
{
	int SetTarget;
	int SumError;
	int Error;							//Error[n]
	int LastError;					//Error[n-1]
	int PrevError;					//Error[n-2]
	double Kp;
	double Ki;
	double Kd;
};
extern u8 cdh_num;
extern u8 mmm_flag,mmm_flag1;
extern struct  Agv_Pid PID,PID1,PID4;


void PID_Init(void);
void PID1_Init(void);
void PID4_Init(void);
int PosPIDCalc(u8 NextTarget,u8 num);
int IncPIDCalc(u8 NextTemper);



#endif
