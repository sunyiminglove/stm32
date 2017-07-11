#ifndef __BAOHU_H
#define __BAOHU_H
#include "sys.h"


#define QBZ2N 		PFin(10)	 //红外避障	:近避障（前避障）
#define QBZ2F 		PFin(14)	 //红外避障	:远避障（前避障）

#define MBTZ 			PFin(4)	 	 //面板停止  叉车控制面板上的停止按钮（红色）
#define JXBZ 			PFin(6)	 	 //机械避障

#define CBBZ1 		PFin(8)	   //叉臂红外避障1（右叉臂）
#define CBBZ2			PFin(9)	 	 //叉臂红外避障2（左叉臂）
#define CBJC1 		PFin(5)	 	 //叉臂货物到位红外检测1（右叉臂）
#define CBJC2 		PFin(7)	 	 //叉臂货物到位红外检测2（左叉臂）


void BAOHU_Init(void);	//保护端口初始化

#endif
