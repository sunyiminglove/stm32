#ifndef __CONTROL_H
#define __CONTROL_H
#include "sys.h"

#define SPEED_min 500//�趨�ٶȵ���С��ֵ

extern u8 Mode_flag;				//1:�Զ�����ģʽ 0���ֶ�����ģʽ
extern u8 FX_flag;					//1:ǰ��	2:������	3:������
extern u8 QD_flag;					//������־ 0:ֹͣ 1:����
extern u8 FC_flag;					//0:�зֲ� 1:��ֲ� 2���ҷֲ�
extern u8 yuyin_flag;
extern u8 road_mode;
extern u16 speed;


//�ϲ�����߷�����ƺ���
void Zi_Dong(void);
void Shou_Dong(void);
void Qian_Jin(void);
void Hou_Zuo(void);
void Hou_You(void);
//void Zuo_Xuan(void);
//void You_Xuan(void);
void Ting_Zhi(void);
void Qi_Dong(void);
void Zuo_Fen(void);
void Zhong_Fen(void);
void You_Fen(void);
void Cha_Sheng(void);
void Cha_Jiang(void);

void Ruan_Qi(u16 speed_min,u16 speed_zhi);

#endif
