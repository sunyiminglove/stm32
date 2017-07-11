#ifndef __CONTROL_H
#define __CONTROL_H
#include "sys.h"

#define SPEED_min 500//设定速度的最小限值

extern u8 Mode_flag;				//1:自动运行模式 0：手动控制模式
extern u8 FX_flag;					//1:前进	2:后退左	3:后退右
extern u8 QD_flag;					//启动标志 0:停止 1:启动
extern u8 FC_flag;					//0:中分叉 1:左分叉 2：右分叉
extern u8 yuyin_flag;
extern u8 road_mode;
extern u16 speed;


//上层的行走方向控制函数
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
