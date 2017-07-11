#ifndef __ROUTE_H
#define __ROUTE_H
#include "sys.h"
#include "Modbus_slave.h"
#include "w25qxx.h"
//////////////////flash内存管理//////////////////////////////////////////////////////////////////

//请根据实际需求配置各个存储块参数
//系统参数
#define SystemParaNum 101  //系统信息总数，其中0用于判断flash是否被初始化，或者状态是否正常
extern u16 SystemParameter[SystemParaNum];//系统参数

//路径: 共500个路径，每个路径100个站点，每个站点20个信息，每个信息2个字节
#define RouteNum 500  //路径总数
#define StationNum 100 //每条路径包含站点数
#define StaiionInfor 20 //每个站点包含信息数

#define RouteStationNumAdress(n) SystemParaNum+n-1  //每条路径包含站点数信息地址
#define NowRouteInforAdress(n)       RouteStationNumAdress(RouteNum)+1+StationNum*StaiionInfor*(n-1)  //当前路径信息地址
#define NowStationInforAdress(m,n)    NowRouteInforAdress(m)+StaiionInfor*(n)//当前路径，当前站点信息地址
extern u16 RouteStationNum[RouteNum]; 		//每条路径包含站点数
extern u16 NowRouteInfor[StationNum][StaiionInfor];   //当前路径信息
//extern u16 StationInfor[StaiionInfor];          //单个站点信息       

//流程: 共500个流程，每个流程100步，每步5个信息，每个信息2个字节
#define ProcessNum 500  //流程总数
#define StepNum 100 //每条流程包含步数
#define StepInfor 5 //每步包含信息数

#define ProcessStepNumAdress(n)   NowRouteInforAdress(RouteNum+1)+n  //每个流程包含步数信息地址
#define NowProcessInforAdress(n)  ProcessStepNumAdress(ProcessNum)+1+StepNum*StepInfor*(n-1)  //当前流程信息地址
#define NowStepInforAdress(m,n)  NowProcessInforAdress(m)+StepInfor*(n)  //当前流程、当前步骤信息地址
extern u16 ProcessStepNum[ProcessNum]; 		   //每个流程包含步数
extern u16 NowProcessInfor[StepNum][StepInfor];  //当前流程信息
//extern u16 NowStepInfor[StepInfor];              //单个步骤信息

extern u16 HmiProcessNumFlag; //上一个流程号，判断流程变化用
extern u16 HmiRouteNumFlag; //上一个路径号，判断路径变化用
extern u16 HmiRouteCopiedNumTemp;//被复制路径号临时变量
extern u16 HmiProcessCopiedNumTemp;//被复制流程号临时变量


//////////////////////////触摸屏地址映射表/////////////////////////////////////////////////////////////////////

#define HmiScreenSetGet                 PLC_Data[32]   //设置获取触摸屏界面号
#define FuZhiLuJingTanChuJieMian        34   //路径复制弹出界面  
#define ZhiXingLuJingJieMian            42   //执行路径界面
#define ZhiXingLiuChengJieMian          43   //执行流程界面
#define ZiDongJieMian                   44   //自动界面


#define LiuChengGuiHuaJieMian           35   //流程规划界面
#define LiuChengSheZhiJieMian           40   //流程设置

#define FuZhiLiuChengTanChuJieMian      36   //复制流程弹出界面
#define QueDingChaRuLiuChengJieMian     37   //确定插入流程界面
#define QueDingShanChuLiuChengJieMian   38   //确定删除流程界面
#define QuXiaoRenWuJieMian              45   //取消任务界面

#define QiDongTiShiJieMian              46   //启动提示界面

#define HmiScreenControlMode PLC_Data[95]   //操作模式
#define HmiScreenRunState    PLC_Data[96]   //运行状态  启动，停止
#define HmiCarLocation       PLC_Data[38]   //AGV当前位置


//系统参数
#define HmiDianTiDiBiao1    PLC_Data[56]  //一楼进入电梯的地标
#define HmiDianTiDiBiao3    PLC_Data[57]  //三楼进入电梯的地标
#define HmiChuDianTiDiBiao  PLC_Data[58]  //出电梯地标


#define HmiRfidNum           HmiRoadData5 //地标号

#define HmiRoadData0         PLC_Data[25] //远程红外 默认为0 0：保持1：开2：关
#define HmiRoadData1         PLC_Data[26] //近程红外 默认为0 0：保持1：开2：关
#define HmiRoadData2         PLC_Data[30] //岔路口左分叉 0：保持1：左分叉 2：右分叉	
#define HmiRoadData3         PLC_Data[31] //叉臂下 0：保持 1：叉臂上 2：叉臂下	
#define HmiRoadData4         PLC_Data[27] //档位默认选择慢速 0：保持 1：慢速 2：中速 3：快速   	       
#define HmiRoadData5         PLC_Data[16] //地标	
#define HmiRoadData6         PLC_Data[36] //动作	0：停止	1：前进	2:后左	3：后右  4：通过
#define HmiRoadData7         PLC_Data[39] //工作区（AGV在设备工作区内）
#define HmiRoadData8         PLC_Data[44] //时间
#define HmiRoadData9         PLC_Data[34] //旋转次数
#define HmiRoadData10        PLC_Data[47] //电梯的使用与否 0:不使用1:去一楼2:去三楼 //使用电梯:叉车从一楼叉货上三楼或叉车从三楼叉货上一楼,其余为不使用电梯
#define HmiRoadData11        PLC_Data[38] //位置
#define HmiRoadData12        PLC_Data[40] //左磁导航触发
#define HmiRoadData13        PLC_Data[43] //右磁导航触发
#define HmiRoadData14        PLC_Data[45] //前磁导航触发
#define HmiRoadData15        PLC_Data[46] //左磁导航触发次数
#define HmiRoadData16        PLC_Data[48] //右磁导航触发次数
#define HmiRoadData17        PLC_Data[49] //前磁导航触发次数
#define HmiRoadData18        PLC_Data[50] //旋转后动作
#define HmiRoadData19        PLC_Data[51] //叉臂避障


#define HmiRouteNum          PLC_Data[24] //路径号
#define HmiStationNum        PLC_Data[28] //站点数
#define HmiStationSerialNum  PLC_Data[29] //站点序号
#define HmiRouteEnter        PLC_Data[37] //确定1，取消2
#define HmiStationLast       PLC_Data[35] //上一个1
#define HmiStationNext       PLC_Data[35] //下一个2
#define HmiRoutemode         PLC_Data[41] //模式，查看0，复制1，添加2，插入3，更改4，删除5
#define HmiRouteCopiedNum    PLC_Data[53] //被复制路径号
#define HmiRouteCopiedCount  PLC_Data[55] //被复制站点数
#define HmiNextRfidNum       PLC_Data[90] //下一个地标
#define ZhiXingLuJingQueDing PLC_Data[94] //执行路径确定按钮



//////流程规划
#define HmiProcessNum          PLC_Data[77] //流程号
#define HmiStepNum             PLC_Data[78] //流程步数
#define HmiProcessSerialNum    PLC_Data[79] //流程序号
#define HmiProcessStartNum     PLC_Data[80] //开始路径号
#define HmiProcessAction       PLC_Data[81] //流程动作
#define HmiProcessStopNum      PLC_Data[82] //循环和结束数据

#define HmiProcessEnter        PLC_Data[83] //确定1，取消2

#define HmiProcessLast         PLC_Data[84] //上一个
#define HmiProcessNext         PLC_Data[84] //下一个

#define HmiProcessMode         PLC_Data[85] //模式，查看0，复制1，添加2，插入3，更改4，删除5

#define HmiProcessCopiedNum    PLC_Data[86] //被复制流程号
#define HmiProcessCopiedCount  PLC_Data[87] //被复制流程步数

#define HmiProcessMessage      PLC_Data[88] //流程规划操作提示信息

#define HmiTask                PLC_Data[89] //执行任务 无任务0 执行路径1 执行流程2
#define HmiTaskState           PLC_Data[91] //任务状态
#define ZhiXingLiuChengQueDing PLC_Data[93] //执行流程确定按钮
#define QuXiaoRenWuQueDing     PLC_Data[92] //取消任务确定按钮



//系统参数
#define HmiDiSu        PLC_Data[18] //低速
#define HmiZhongSu     PLC_Data[19] //中速
#define HmiGaoSu       PLC_Data[20] //高速









//---------------系统------------//
//从系统获取一个参数 num:参数位置
extern u16 GetOneParameterFromSystem(u16 num);

//获取所有系统参数，并存入默认数组SystemParameter
extern GetAllParameterFromSystem(void);

//设置一个参数到系统 value:参数值 num:参数序号
extern void SetOneParameterToSystem(u16 value,u16 num);

//设置所有参数到系统 将SystemParameter数组的数据存入Flash
extern void SetAllParameterToSystem(void);

//---------------路径------------//
//获取路径包含站点数 num:路径号
extern u16 GetRouteStationNum(u16 num);

//保存所有路径包含的站点数
extern void SetAllStationNum(void);

//获取路径信息,num:路径号
extern void GetRouteData(u16 num);

//保存路径信息,num:路径号
extern void SetRouteData(u16 num);


//更新路径站点数据到界面
extern void UpdataStationToHmi(void);

//更新路径站点数据到当前(当前数组)
void UpdataStationToNow(void);

//更新路径站点数据到界面
extern void ClearStationToHmi(void);

//---------------流程------------//

//保存及更新流程数据（当前操作的流程信息）
extern void	SetProcessData(void);

//获取流程包含步数
extern u16	GetProcessStepNum(u16 num);

//保存所有流程包含步数
extern void SetAllStepNum(void);

//获取及更新流程数据（当前操作的流程信息）
extern void	GetProcessData(void);

//获取及更新指定流程数据（指定的流程信息）
extern void	GetProcessDataFrom(u16 num);

//更新流程数据到界面
extern void ClearStepToHmi(void);

//更新流程数据到界面
extern void UpdataProcessToHmi(void);

//插入及更新流程数据（当前操作的流程信息）
extern void	InsertProcessData(void);

//删除及更新流程数据（当前操作的流程信息）
extern void	DeleteProcessData(void);

//自动界面显示信息重载
extern void HmiAutoReload(void);



#endif
