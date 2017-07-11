#ifndef __ROUTE_H
#define __ROUTE_H
#include "sys.h"
#include "Modbus_slave.h"
#include "w25qxx.h"
//////////////////flash�ڴ����//////////////////////////////////////////////////////////////////

//�����ʵ���������ø����洢�����
//ϵͳ����
#define SystemParaNum 101  //ϵͳ��Ϣ����������0�����ж�flash�Ƿ񱻳�ʼ��������״̬�Ƿ�����
extern u16 SystemParameter[SystemParaNum];//ϵͳ����

//·��: ��500��·����ÿ��·��100��վ�㣬ÿ��վ��20����Ϣ��ÿ����Ϣ2���ֽ�
#define RouteNum 500  //·������
#define StationNum 100 //ÿ��·������վ����
#define StaiionInfor 20 //ÿ��վ�������Ϣ��

#define RouteStationNumAdress(n) SystemParaNum+n-1  //ÿ��·������վ������Ϣ��ַ
#define NowRouteInforAdress(n)       RouteStationNumAdress(RouteNum)+1+StationNum*StaiionInfor*(n-1)  //��ǰ·����Ϣ��ַ
#define NowStationInforAdress(m,n)    NowRouteInforAdress(m)+StaiionInfor*(n)//��ǰ·������ǰվ����Ϣ��ַ
extern u16 RouteStationNum[RouteNum]; 		//ÿ��·������վ����
extern u16 NowRouteInfor[StationNum][StaiionInfor];   //��ǰ·����Ϣ
//extern u16 StationInfor[StaiionInfor];          //����վ����Ϣ       

//����: ��500�����̣�ÿ������100����ÿ��5����Ϣ��ÿ����Ϣ2���ֽ�
#define ProcessNum 500  //��������
#define StepNum 100 //ÿ�����̰�������
#define StepInfor 5 //ÿ��������Ϣ��

#define ProcessStepNumAdress(n)   NowRouteInforAdress(RouteNum+1)+n  //ÿ�����̰���������Ϣ��ַ
#define NowProcessInforAdress(n)  ProcessStepNumAdress(ProcessNum)+1+StepNum*StepInfor*(n-1)  //��ǰ������Ϣ��ַ
#define NowStepInforAdress(m,n)  NowProcessInforAdress(m)+StepInfor*(n)  //��ǰ���̡���ǰ������Ϣ��ַ
extern u16 ProcessStepNum[ProcessNum]; 		   //ÿ�����̰�������
extern u16 NowProcessInfor[StepNum][StepInfor];  //��ǰ������Ϣ
//extern u16 NowStepInfor[StepInfor];              //����������Ϣ

extern u16 HmiProcessNumFlag; //��һ�����̺ţ��ж����̱仯��
extern u16 HmiRouteNumFlag; //��һ��·���ţ��ж�·���仯��
extern u16 HmiRouteCopiedNumTemp;//������·������ʱ����
extern u16 HmiProcessCopiedNumTemp;//���������̺���ʱ����


//////////////////////////��������ַӳ���/////////////////////////////////////////////////////////////////////

#define HmiScreenSetGet                 PLC_Data[32]   //���û�ȡ�����������
#define FuZhiLuJingTanChuJieMian        34   //·�����Ƶ�������  
#define ZhiXingLuJingJieMian            42   //ִ��·������
#define ZhiXingLiuChengJieMian          43   //ִ�����̽���
#define ZiDongJieMian                   44   //�Զ�����


#define LiuChengGuiHuaJieMian           35   //���̹滮����
#define LiuChengSheZhiJieMian           40   //��������

#define FuZhiLiuChengTanChuJieMian      36   //�������̵�������
#define QueDingChaRuLiuChengJieMian     37   //ȷ���������̽���
#define QueDingShanChuLiuChengJieMian   38   //ȷ��ɾ�����̽���
#define QuXiaoRenWuJieMian              45   //ȡ���������

#define QiDongTiShiJieMian              46   //������ʾ����

#define HmiScreenControlMode PLC_Data[95]   //����ģʽ
#define HmiScreenRunState    PLC_Data[96]   //����״̬  ������ֹͣ
#define HmiCarLocation       PLC_Data[38]   //AGV��ǰλ��


//ϵͳ����
#define HmiDianTiDiBiao1    PLC_Data[56]  //һ¥������ݵĵر�
#define HmiDianTiDiBiao3    PLC_Data[57]  //��¥������ݵĵر�
#define HmiChuDianTiDiBiao  PLC_Data[58]  //�����ݵر�


#define HmiRfidNum           HmiRoadData5 //�ر��

#define HmiRoadData0         PLC_Data[25] //Զ�̺��� Ĭ��Ϊ0 0������1����2����
#define HmiRoadData1         PLC_Data[26] //���̺��� Ĭ��Ϊ0 0������1����2����
#define HmiRoadData2         PLC_Data[30] //��·����ֲ� 0������1����ֲ� 2���ҷֲ�	
#define HmiRoadData3         PLC_Data[31] //����� 0������ 1������� 2�������	
#define HmiRoadData4         PLC_Data[27] //��λĬ��ѡ������ 0������ 1������ 2������ 3������   	       
#define HmiRoadData5         PLC_Data[16] //�ر�	
#define HmiRoadData6         PLC_Data[36] //����	0��ֹͣ	1��ǰ��	2:����	3������  4��ͨ��
#define HmiRoadData7         PLC_Data[39] //��������AGV���豸�������ڣ�
#define HmiRoadData8         PLC_Data[44] //ʱ��
#define HmiRoadData9         PLC_Data[34] //��ת����
#define HmiRoadData10        PLC_Data[47] //���ݵ�ʹ����� 0:��ʹ��1:ȥһ¥2:ȥ��¥ //ʹ�õ���:�泵��һ¥�������¥��泵����¥�����һ¥,����Ϊ��ʹ�õ���
#define HmiRoadData11        PLC_Data[38] //λ��
#define HmiRoadData12        PLC_Data[40] //��ŵ�������
#define HmiRoadData13        PLC_Data[43] //�Ҵŵ�������
#define HmiRoadData14        PLC_Data[45] //ǰ�ŵ�������
#define HmiRoadData15        PLC_Data[46] //��ŵ�����������
#define HmiRoadData16        PLC_Data[48] //�Ҵŵ�����������
#define HmiRoadData17        PLC_Data[49] //ǰ�ŵ�����������
#define HmiRoadData18        PLC_Data[50] //��ת����
#define HmiRoadData19        PLC_Data[51] //��۱���


#define HmiRouteNum          PLC_Data[24] //·����
#define HmiStationNum        PLC_Data[28] //վ����
#define HmiStationSerialNum  PLC_Data[29] //վ�����
#define HmiRouteEnter        PLC_Data[37] //ȷ��1��ȡ��2
#define HmiStationLast       PLC_Data[35] //��һ��1
#define HmiStationNext       PLC_Data[35] //��һ��2
#define HmiRoutemode         PLC_Data[41] //ģʽ���鿴0������1�����2������3������4��ɾ��5
#define HmiRouteCopiedNum    PLC_Data[53] //������·����
#define HmiRouteCopiedCount  PLC_Data[55] //������վ����
#define HmiNextRfidNum       PLC_Data[90] //��һ���ر�
#define ZhiXingLuJingQueDing PLC_Data[94] //ִ��·��ȷ����ť



//////���̹滮
#define HmiProcessNum          PLC_Data[77] //���̺�
#define HmiStepNum             PLC_Data[78] //���̲���
#define HmiProcessSerialNum    PLC_Data[79] //�������
#define HmiProcessStartNum     PLC_Data[80] //��ʼ·����
#define HmiProcessAction       PLC_Data[81] //���̶���
#define HmiProcessStopNum      PLC_Data[82] //ѭ���ͽ�������

#define HmiProcessEnter        PLC_Data[83] //ȷ��1��ȡ��2

#define HmiProcessLast         PLC_Data[84] //��һ��
#define HmiProcessNext         PLC_Data[84] //��һ��

#define HmiProcessMode         PLC_Data[85] //ģʽ���鿴0������1�����2������3������4��ɾ��5

#define HmiProcessCopiedNum    PLC_Data[86] //���������̺�
#define HmiProcessCopiedCount  PLC_Data[87] //���������̲���

#define HmiProcessMessage      PLC_Data[88] //���̹滮������ʾ��Ϣ

#define HmiTask                PLC_Data[89] //ִ������ ������0 ִ��·��1 ִ������2
#define HmiTaskState           PLC_Data[91] //����״̬
#define ZhiXingLiuChengQueDing PLC_Data[93] //ִ������ȷ����ť
#define QuXiaoRenWuQueDing     PLC_Data[92] //ȡ������ȷ����ť



//ϵͳ����
#define HmiDiSu        PLC_Data[18] //����
#define HmiZhongSu     PLC_Data[19] //����
#define HmiGaoSu       PLC_Data[20] //����









//---------------ϵͳ------------//
//��ϵͳ��ȡһ������ num:����λ��
extern u16 GetOneParameterFromSystem(u16 num);

//��ȡ����ϵͳ������������Ĭ������SystemParameter
extern GetAllParameterFromSystem(void);

//����һ��������ϵͳ value:����ֵ num:�������
extern void SetOneParameterToSystem(u16 value,u16 num);

//�������в�����ϵͳ ��SystemParameter��������ݴ���Flash
extern void SetAllParameterToSystem(void);

//---------------·��------------//
//��ȡ·������վ���� num:·����
extern u16 GetRouteStationNum(u16 num);

//��������·��������վ����
extern void SetAllStationNum(void);

//��ȡ·����Ϣ,num:·����
extern void GetRouteData(u16 num);

//����·����Ϣ,num:·����
extern void SetRouteData(u16 num);


//����·��վ�����ݵ�����
extern void UpdataStationToHmi(void);

//����·��վ�����ݵ���ǰ(��ǰ����)
void UpdataStationToNow(void);

//����·��վ�����ݵ�����
extern void ClearStationToHmi(void);

//---------------����------------//

//���漰�����������ݣ���ǰ������������Ϣ��
extern void	SetProcessData(void);

//��ȡ���̰�������
extern u16	GetProcessStepNum(u16 num);

//�����������̰�������
extern void SetAllStepNum(void);

//��ȡ�������������ݣ���ǰ������������Ϣ��
extern void	GetProcessData(void);

//��ȡ������ָ���������ݣ�ָ����������Ϣ��
extern void	GetProcessDataFrom(u16 num);

//�����������ݵ�����
extern void ClearStepToHmi(void);

//�����������ݵ�����
extern void UpdataProcessToHmi(void);

//���뼰�����������ݣ���ǰ������������Ϣ��
extern void	InsertProcessData(void);

//ɾ���������������ݣ���ǰ������������Ϣ��
extern void	DeleteProcessData(void);

//�Զ�������ʾ��Ϣ����
extern void HmiAutoReload(void);



#endif
