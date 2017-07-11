	//执行站点动作
void StationAction(u16 num)
{
//	next_keynumber=NowRouteInfor[StationNumber][5];
//	//清空地标
//	keynumber=0;

//	while(keynumber==0||keynumber!=NowRouteInfor[StationNumber][5])	//扫到地标，是目标值的话则跳出while
//	{		
//		osdelay_ms(20);			
//	}
//	
//	StationNumber++;
//	if(StationNumber==RouteStationNum[HmiRouteNum-1])
//	{
//		StationNumber=0;	
//		speed=PLC_Data[6];							//初始化速度值
//	}
//	next_keynumber=NowRouteInfor[StationNumber][5];
//	
//	
//	
	
		HmiStationSerialNum++;
	//清空地标
	keynumber=0;
	//等待地标
//					while(keynumber==0||keynumber!=NowRouteInfor[i][5])	
//					{		
//						osdelay_ms(20);			
//					
	HmiNextRfidNum = NowRouteInfor[num][5];
	osdelay_s(3);	

	//启动，自动
	while(QD_flag != 1 || Mode_flag != 1)
	{
		osdelay_ms(20);	
	}

	keynumber = HmiNextRfidNum;
	HmiRfidNum = keynumber;
					
	
//	switch(NowRouteInfor[num][4])//速度档位判断
//	{
//		case 0:	break;//保持上次信息
//		case 1://低速
//		{
//			speek("1挡");
//			speed=PLC_Data[18];
//			PWM_val(TIM4,2,speed);					//设定速度PWM赋值给车
//			osdelay_ms(SPEEKTIME);
//		}break;					
//		case 2://中速
//		{
//			speek("2挡");
//			speed=PLC_Data[19];
//			PWM_val(TIM4,2,speed);					//设定速度PWM赋值给车
//			osdelay_ms(SPEEKTIME);
//		}break;				
//		case 3://高速
//		{
//			speek("3挡");
//			speed=PLC_Data[20];
//			PWM_val(TIM4,2,speed);					//设定速度PWM赋值给车						osdelay_ms(SPEEKTIME);						
//		}break;					
//	}
//	switch(NowRouteInfor[num][10])//AGV对电梯的使用情况
//	{
//		case 0:	break;//电梯不使用
//		case 1://AGV去一楼
//		{
//			AGV_QuYiLou();
//		}break;				
//		case 2://AGV去三楼
//		{
//			AGV_QuSanLou();
//		}break;	
//	}
//	switch(NowRouteInfor[num][6])//停止、前进、后退左、后退右、左旋、右旋	
//	{
//		case 0:	break;//保持上次信息
//		case 1://停止
//		case 2://前进
//		case 3://后退左
//		case 4://后退右
//		case 6://左旋
//		case 7://右旋						
//		{
//			Ting_Zhi();
//			osdelay_ms(SPEEKTIME);
//		}break;	
//		case 5:break;//通过				
//	}			
//	switch(NowRouteInfor[num][2])//分叉判断
//	{
//		case 0:	break;//保持上次信息
//		case 1://左分叉
//		{
//			Zuo_Fen();
//			osdelay_ms(SPEEKTIME);						
//		}break;	
//		case 2://右分叉
//		{
//			You_Fen();
//			osdelay_ms(SPEEKTIME);						
//		}break;			
//	}
//	switch(NowRouteInfor[num][3])//叉臂上下判断
//	{
//		case 0:	break;//保持上次信息
//		case 1://叉臂上升
//		{
//			Cha_Sheng();	
//		}break;	
//		case 2://叉臂下降
//		{
//			Cha_Jiang();
//		}break;			
//									
//	}
//	switch(NowRouteInfor[num][0])//远红外开关判断
//	{
//		case 0:	break;//保持上次信息
//		case 1://远红外开
//		{
//			QBZ_Yflag=0;
//			speek("远开");	
//			osdelay_ms(SPEEKTIME);						
//		}break;					
//		case 2://远红外关
//		{
//			QBZ_Yflag=1;
//			speek("远关");
//			osdelay_ms(SPEEKTIME);						
//		}break;							
//	}				
//	switch(NowRouteInfor[num][1])//近红外开关判断
//	{
//		case 0:	break;//保持上次信息
//		case 1://近红外开
//		{
//			QBZ_Jflag=0;
//			speek("近开");
//			osdelay_ms(SPEEKTIME);						
//		}break;					
//		case 2://近红外关
//		{
//			QBZ_Jflag=1;
//			speek("近关");
//			osdelay_ms(SPEEKTIME);						
//		}break;								
//	}
//	switch(NowRouteInfor[num][6])//动作执行再判断	
//	{
//		case 0:	break;//保持上次信息
//		case 1: break;//停止
//		case 2://前进
//		{
//			Qian_Jin();
//			osdelay_ms(SPEEKTIME);
//			Qi_Dong();
//			osdelay_ms(SPEEKTIME);
//		}break;	
//		case 3://后退左
//		{
//			Hou_Zuo();
//			osdelay_ms(SPEEKTIME);
//			Qi_Dong();
//			osdelay_ms(SPEEKTIME);
//		}break;
//		case 4://后退右
//		{
//			Hou_You();
//			osdelay_ms(SPEEKTIME);
//			Qi_Dong();
//			osdelay_ms(SPEEKTIME);
//		}break;
//		case 6://左旋
//		{
//		  Xuan_Zhuang_Ci_Shu = NowRouteInfor[num][9];
//			last_flag=FX_flag;
//			Zuo_Xuan();
//			osdelay_ms(SPEEKTIME);
//			QD_flag=1;
//		}break;
//		case 7://右旋
//		{
//			Xuan_Zhuang_Ci_Shu = NowRouteInfor[num][9];
//			last_flag=FX_flag;
//			You_Xuan();
//			osdelay_ms(SPEEKTIME);
//			QD_flag=1;
//		}break;
//	}
}
	

//执行任务
void Task5_task(void *p_arg)
{	
	u16 i,j,k;
	p_arg = p_arg;

	while(1)
	{
		if(Mode_flag == 1)
		{
			//执行路径
			if(HmiTask==1)
			{
				HmiStationSerialNum = 0;
				//根据所选路径，执行相应动作
				for(i=0;i<HmiStationNum;i++)
				{
					StationAction(i);
				}
			}
			else
				//执行流程
				if(HmiTask == 2)
				{
					HmiProcessSerialNum = 0;
					for(i=0;i<HmiStepNum;i++)
					{
						HmiProcessSerialNum++;
						switch(NowProcessInfor[i][1])
						{
							case 0://单次执行
								//更新路径号
								HmiRouteNum = NowProcessInfor[i][0];
							  //获取路径包含站点数
								GetRouteStationNum(HmiRouteNum);
								//获取当前路径信息
								GetRouteData(HmiRouteNum);

  							HmiStationSerialNum = 0;
								//根据所选路径，执行相应动作
								for(j=0;j<HmiStationNum;j++)
								{
									StationAction(j);
								}
								break;
							case 1://顺序执行
								for(k=NowProcessInfor[i][0];k<=NowProcessInfor[i][2];k++)
								{
									//更新路径号
									HmiRouteNum = k;
									//获取路径包含站点数
									GetRouteStationNum(HmiRouteNum);
									//获取当前路径信息
									GetRouteData(HmiRouteNum);
									
									HmiStationSerialNum = 0;
									//根据所选路径，执行相应动作
									for(j=0;j<HmiStationNum;j++)
									{
										StationAction(j);
									}
								}
								break;
							case 2://倒序执行
								for(k=NowProcessInfor[i][0];k>=NowProcessInfor[i][2];k--)
								{
									//更新路径号
									HmiRouteNum = k;
									//获取路径包含站点数
									GetRouteStationNum(HmiRouteNum);
									//获取当前路径信息
									GetRouteData(HmiRouteNum);
  
									HmiStationSerialNum = 0;
 									//根据所选路径，执行相应动作
									for(j=0;j<HmiStationNum;j++)
									{
										StationAction(j);
									}
								}
								break;
							case 3://循环执行
								//更新路径号
								HmiRouteNum = NowProcessInfor[i][0];
							  //获取路径包含站点数
								GetRouteStationNum(HmiRouteNum);
								//获取当前路径信息
								GetRouteData(HmiRouteNum);
								for(k=0;k<NowProcessInfor[i][2];k++)
								{
    							HmiStationSerialNum = 0;
									//根据所选路径，执行相应动作
									for(j=0;j<HmiStationNum;j++)
									{
										StationAction(j);
									}
								}
								break;
							default:break;
						}
					}
				}		
		}
		osdelay_ms(10);
	}
}

	
	
	
	while(1)
	{	 	
		switch(HmiScreenSetGet)
		{
			case 9: //手动控制界面的操作
						{						
							/***************正常运行时检索屏幕上的按键开始*************/	
									if(PLC_OutPut[4]==1)						//屏幕的手动按键按下时
									{
										Shou_Dong();		//切到手动程序
									}
									else if(PLC_OutPut[5]==1)				//屏幕的自动按键按下时
									{
										Zi_Dong();			//切到自动程序
									}
									else if(PLC_OutPut[9]==1)				//叉臂上升按钮按下时
									{
										Cha_Sheng();
									} 
									else if(PLC_OutPut[10]==1)			//叉臂下降按钮按下时
									{
										Cha_Jiang();
									}
									else if(PLC_OutPut[13]==1)			//左分叉按钮按下时
									{
										Zuo_Fen();
									}
									else if(PLC_OutPut[14]==1)			//右分叉按钮按下时
									{
										You_Fen();
									}		
							/***************正常运行时检索屏幕上的按键结束*************/
							/*********叉车行驶方向的确定开始***********/	
									if(Mode_flag == 1)
									{
											if(PLC_OutPut[11]==1)			//启动
											{
												Qi_Dong();
											}
											if(PLC_OutPut[12]==1)		 	//停止
											{
												Ting_Zhi();
											}
											else if(PLC_OutPut[6]==1)	//由屏上的前进按钮确定控制叉车的行驶方向标志FX_flag
											{
												Qian_Jin();
											}
											else if(PLC_OutPut[7]==1) //由屏上的后退左按钮确定控制叉车的行驶方向标志FX_flag
											{
												Hou_Zuo();
											}
											else if(PLC_OutPut[8]==1) //由屏上的后退右按钮确定控制叉车的行驶方向标志FX_flag
											{
												Hou_You();
											}	
											else if(PLC_OutPut[15]==1)//去一楼路径
											{
												yuyin_flag=19;
												HmiRouteNum=5;
											}
									}
							/*********叉车行驶方向的确定结束***********/
								
						}break;
			case 11://系统参数界面，速度的档位设置
						{
								if(low_speed!=PLC_Data[18]||middle_speed!= PLC_Data[19]||high_speed!= PLC_Data[20])
								{
										low_speed 	= PLC_Data[18];	 //一档速度 
										middle_speed= PLC_Data[19];  //二档速度
										high_speed	= PLC_Data[20];  //三档速度
											
										SystemParameter[18]=PLC_Data[18];
										SystemParameter[19]=PLC_Data[19];
										SystemParameter[20]=PLC_Data[20];
										
										W25QXX_Write_16(SystemParameter,0,SystemParaNum);			//将当前屏幕参数写入到flash中
								}
								if(SystemParameter[52]!=PLC_Data[52])	//车号改变时
								{
										STATIONNUM_170M = PLC_Data[52]+1;
										SystemParameter[52]=PLC_Data[52];
										W25QXX_Write_16(SystemParameter,0,SystemParaNum);			//将当前屏幕参数写入到flash中
								}			
						}break;
			case 13://各个传感器的状态更新到屏幕上
						{
							PLC_OutPut[25]=CBBZ2;	//叉臂红外避障2（左叉臂）
							PLC_OutPut[26]=CBJC2; //叉臂货物到位红外检测2（左叉臂）
							PLC_OutPut[27]=CBBZ1; //叉臂红外避障1（右叉臂）
							PLC_OutPut[28]=CBJC1; //叉臂货物到位红外检测1（右叉臂）
							PLC_OutPut[29]=QBZ2N; //红外避障2	:近避障（前避障）
							PLC_OutPut[30]=QBZ2F; //红外避障2	:远避障（前避障）
							PLC_OutPut[46]=JXBZ;  //机械避障
						}break;
			case 14://电梯调试界面(在车上对电梯的一切进行操控和显示电梯状态)
						{
								if(PLC_OutPut[31]==1)//三楼外呼按钮
								{
									PLC2_Data[18]=0;
								}
								else if(PLC_OutPut[32]==1)//一楼外呼按钮
								{
									PLC2_Data[19]=0;
								}
								else if(PLC_OutPut[33]==1)//3按钮
								{
									PLC2_Data[20]=0;
								}
								else if(PLC_OutPut[34]==1)//1按钮
								{
									PLC2_Data[21]=0;
								}
								else if(PLC_OutPut[35]==1)//开门
								{
									PLC2_Data[22]=0;
								}
								else if(PLC_OutPut[36]==1)//关门
								{
									PLC2_Data[23]=0;
								}
								PLC_OutPut[37]=PLC2_Data[24];//三楼平层（电梯在三楼）
								PLC_OutPut[38]=PLC2_Data[25];//一楼平层（电梯在一楼）
								PLC_OutPut[39]=PLC2_Data[26];//三楼门状态（开/关）
								PLC_OutPut[40]=PLC2_Data[27];//一楼门状态（开/关）
						}break;
			case 15://数据测试窗口执行
						{
							/*********当屏幕上参数发生改变时记录参数到flash开始********/
								if(time!=PLC_Data[11]||PID.Kp != PLC_Data[8]||PID.Ki != PLC_Data[9]||PID.Kd != PLC_Data[10]||PID1.Kp != PLC_Data[13]||PID1.Ki != PLC_Data[14]||PID1.Kd != PLC_Data[15]||PLC_Data[1]!=PLC_Data[6])
								{
									time=PLC_Data[11];										//测试前进的PID控制周期
																												
									PID.Kp = PLC_Data[8];		              //更新屏幕的PID参数kp
									PID.Ki = PLC_Data[9];                 //更新屏幕的PID参数ki
									PID.Kd = PLC_Data[10];                //更新屏幕的PID参数kd
																												
									PID1.Kp = PLC_Data[13];	              //更新屏幕的PID1参数kp
									PID1.Ki = PLC_Data[14];               //更新屏幕的PID1参数ki
									PID1.Kd = PLC_Data[15];               //更新屏幕的PID1参数kd
								
									speed=PLC_Data[1]=PLC_Data[6];							//更新屏幕的速度显示值
									PWM_val(TIM4,2,speed);					//设定速度PWM赋值给车
									
									SystemParameter[11]=PLC_Data[11];
									SystemParameter[8] = PLC_Data[8];
									SystemParameter[9] = PLC_Data[9];
									SystemParameter[10]=PLC_Data[10];
									SystemParameter[13]=PLC_Data[13];
									SystemParameter[14]=PLC_Data[14];
									SystemParameter[15]=PLC_Data[15];
									SystemParameter[6] = PLC_Data[6];
									
									
									W25QXX_Write_16(SystemParameter,0,90);			//将当前屏幕参数写入到flash中
								}
							/*********当屏幕上参数发生改变时记录参数到flash结束********/
						}break;
			case 23:
						{
							//如果路径号为零，则置一
							if(HmiRouteNum==0)
							{
								HmiRouteNum = 1;
							}
						}break;
			case 19: 
			case 24: 
			case 25://路径设置
						{	
								while(HmiScreenSetGet==19||HmiScreenSetGet==24||HmiScreenSetGet==25||HmiScreenSetGet==FuZhiLuJingTanChuJieMian)
								{  
									//复制路径
									while(HmiScreenSetGet==FuZhiLuJingTanChuJieMian)//处于复制路径界面
									{
										//被复制路径号为零时置1
										if(HmiRouteCopiedNum==0)
											HmiRouteCopiedNum=1;	
										
										//输入的被复制流程号变化时更新
										if(HmiRouteCopiedNumTemp!=HmiRouteCopiedNum)
											HmiRouteCopiedCount = GetRouteStationNum(HmiRouteCopiedNum);
										
										
										//确定复制
										if(HmiRoutemode==1)
										{
											//读取被复制信息到当前
											GetRouteData(HmiRouteCopiedNum);
											
											//保存并更新被复制信息
											SetRouteData(HmiRouteNum);	
											
											UpdataStationToHmi();
											
											//设置当前站点为1
											if(HmiStationNum!=0)
												HmiStationSerialNum = 1;
											
											//退出复制模式
											HmiRoutemode=0;
										}
										osdelay_ms(10);
									}

									//添加站点
									if(HmiRoutemode==2)
									{ 
										//站点数加一
										HmiStationNum ++;
										//站点号等于站点数
										HmiStationSerialNum = HmiStationNum;
										
										//地标号清零
										keynumber = 0;		
										
										ClearStationToHmi();	
										
										while(HmiRoutemode==2)
										{
											//如果读到地标，更新到显示器
											if(keynumber!=0)
											{
												HmiRfidNum = keynumber;//刷新地标号
											}			
											
											//确定
											if(HmiRouteEnter==1)
											{
												HmiRouteEnter = 0;
												//更新站点数据到当前数据
												UpdataStationToNow();
												//保存当前站点数据
												SetRouteData(HmiRouteNum);
												//退出添加模式
												HmiRoutemode=	0;
											}
											else
											//取消
											if(HmiRouteEnter==2)
											{
												HmiRouteEnter = 0;
												//站点数减一
												HmiStationNum--;
												//站点号等于站点数
												HmiStationSerialNum = HmiStationNum;
												//退出添加模式
												HmiRoutemode=	0;
											}
											osdelay_ms(10);
										}
									}
									//插入站点
									if(HmiRoutemode==3)
									{
										//站点数加一
										HmiStationNum ++;
										//站点号为零时加一
										if(HmiStationNum==0)
											HmiStationSerialNum = 1;
										
										//地标号清零
										keynumber = 0;		
										
										ClearStationToHmi();										

										while(HmiRoutemode==3)
										{
											//如果读到地标，更新到显示器
											if(keynumber!=0)
											{
												HmiRfidNum = keynumber;//刷新地标号
											}												
											
											//确定
											if(HmiRouteEnter==1)
											{
												HmiRouteEnter = 0;
												
												//站点信息向后移动一个位置，并插入当前站点信息
												for(i=HmiStationNum;i>=HmiStationSerialNum;i--)
												{
													for(j=0;j<StaiionInfor;j++)
													{
														NowRouteInfor[i][j] = NowRouteInfor[i-1][j];
													}
												}
												
												//更新站点信息到当前
												UpdataStationToNow();
												
												//保存路径信息
												SetRouteData(HmiRouteNum);

												//退出添加模式
												HmiRoutemode=	0;
											}
											else
											//取消
											if(HmiRouteEnter==2)
											{
												HmiRouteEnter = 0;
												//站点数减一
												HmiStationNum--;
												//站点号为1时置零
												if(HmiStationSerialNum==1)
													HmiStationSerialNum = 0;
												//退出添加模式
												HmiRoutemode=	0;
											}

											osdelay_ms(10);
										}

									}
									//更改站点
									if(HmiRoutemode==4)
									{
										while(HmiRoutemode==4)
										{
											//如果读到地标，更新到显示器
											if(keynumber!=0)
											{
												HmiRfidNum = keynumber;//刷新地标号
											}			
											
											//确定
											if(HmiRouteEnter==1)
											{
												HmiRouteEnter = 0;
												//更新站点数据到当前数据
												UpdataStationToNow();
												//保存当前站点数据
												SetRouteData(HmiRouteNum);
												//退出添加模式
												HmiRoutemode=	0;
											}
											else
											//取消
											if(HmiRouteEnter==2)
											{
												HmiRouteEnter = 0;
												//站点数减一
												HmiStationNum--;
												//站点号等于站点数
												HmiStationSerialNum = HmiStationNum;
												//退出添加模式
												HmiRoutemode=	0;
											}
											osdelay_ms(10);
										}
									}
								
									//删除站点
									if(HmiRoutemode==5)
									{
										if(HmiStationNum>0)
										{
											//将后面所数据向前移动一位
											if((HmiStationNum>0)&&((HmiStationNum)!=HmiStationSerialNum))
											{
												//站点信息向前移动一个位置
												for(i=HmiStationSerialNum;i<HmiStationNum;i++)
												{
													for(j=0;j<StaiionInfor;j++)
													{
														NowRouteInfor[i-1][j] = NowRouteInfor[i][j];
													}
												}
											}

											HmiStationNum--;
											if(HmiStationNum==0)
												HmiStationSerialNum = 0;
											
											//保存路径信息
											SetRouteData(HmiRouteNum);
											
											//更新界面
											UpdataStationToHmi();
										}	
										HmiRoutemode = 0;
									}
									
									//查询站点
									if(HmiRoutemode==0)
									{
										//当路径站点数大于0，并且序号为0时，设置序号为1，并更新显示内容
										if((HmiStationNum>0)&&(HmiStationSerialNum==0))
										{
											HmiStationSerialNum = 1;
											//更新到界面
											UpdataStationToHmi();
										}
										else
										if(HmiStepNum==0)
										{
											HmiProcessSerialNum = 0;
											HmiProcessStartNum = 0;
											HmiProcessStopNum = 0;
											HmiProcessAction = 0;
										}
										
										//路径号变化时，更新界面
										if(HmiRouteNumFlag != HmiRouteNum)
										{
											HmiRouteNumFlag = HmiRouteNum;
											//获取路径信息
											GetRouteData(HmiRouteNum);
											//更新到界面
											UpdataStationToHmi();
										}
										
										//上一个
										if(HmiStationLast == 1)
										{
											HmiStationLast = 0;
											if(HmiStationSerialNum>1)
												HmiStationSerialNum--;
											else
												HmiStationSerialNum = HmiStationNum;
 											UpdataStationToHmi();
										}
										//下一个
										if(HmiStationNext == 2)
										{
											HmiStationNext = 0;
											if(HmiStationSerialNum<HmiStationNum)
													HmiStationSerialNum++;
												else
													if(HmiStationSerialNum!=0)
														HmiStationSerialNum = 1;
											UpdataStationToHmi();
										}
										
										if(HmiStationNum==0)		//没有站点
										{
											//清除站点信息
											ClearStationToHmi();
										}
										else
										{
											//更新站点信息
											UpdataStationToHmi();
										}
									}
									osdelay_ms(10);
								}
						}break;
			case 26://叉臂磁导航数据调试
						{	
							if(SystemParameter[60]!=PLC_Data[60]||SystemParameter[61]!=PLC_Data[61]||SystemParameter[62]!=PLC_Data[62]||
								 SystemParameter[63]!=PLC_Data[63]||SystemParameter[64]!=PLC_Data[64]||SystemParameter[65]!=PLC_Data[65]||
								 SystemParameter[66]!=PLC_Data[66]||SystemParameter[67]!=PLC_Data[67]||SystemParameter[68]!=PLC_Data[68]||
								 SystemParameter[69]!=PLC_Data[69]||SystemParameter[70]!=PLC_Data[70]||SystemParameter[71]!=PLC_Data[71]||
								 SystemParameter[72]!=PLC_Data[72]||SystemParameter[73]!=PLC_Data[73]||SystemParameter[74]!=PLC_Data[74]||
								 SystemParameter[75]!=PLC_Data[75]||SystemParameter[76]!=PLC_Data[76])
							{	
									SystemParameter[60]	= PLC_Data[60];	 
									SystemParameter[61]	= PLC_Data[61];  
									SystemParameter[62]	= PLC_Data[62];  
									SystemParameter[63]	=	PLC_Data[63];
									SystemParameter[64]	=	PLC_Data[64];
									SystemParameter[65]	=	PLC_Data[65];
									SystemParameter[66]	= PLC_Data[66];	 
									SystemParameter[67]	= PLC_Data[67];  
									SystemParameter[68]	= PLC_Data[68];  
									SystemParameter[69]	=	PLC_Data[69];
									SystemParameter[70]	=	PLC_Data[70];
									SystemParameter[71]	=	PLC_Data[71];
									SystemParameter[72]	= PLC_Data[72];	 
									SystemParameter[73]	= PLC_Data[73];  
									SystemParameter[74]	= PLC_Data[74]; 
									SystemParameter[75]	= PLC_Data[75];  
									SystemParameter[76]	= PLC_Data[76];								
									
									W25QXX_Write_16(&SystemParameter[60],60,17);			//将当前屏幕参数写入到flash中
							}
						}break;				
			case LiuChengGuiHuaJieMian://流程设置
			case FuZhiLiuChengTanChuJieMian:
			case QueDingChaRuLiuChengJieMian:
			case QueDingShanChuLiuChengJieMian:
						{
								while(HmiScreenSetGet==LiuChengGuiHuaJieMian||HmiScreenSetGet==FuZhiLiuChengTanChuJieMian||HmiScreenSetGet==QueDingChaRuLiuChengJieMian||HmiScreenSetGet==QueDingShanChuLiuChengJieMian)
								{ 
									//查看模式
									if(HmiProcessMode==0)
									{
										//当前流程步数大于0，并且界面序号为0时，设置序号为1，并更新显示内容
										if((HmiStepNum>0)&&(HmiProcessSerialNum==0))
										{
											HmiProcessSerialNum = 1;
											GetProcessData();
										}
										else
										if(HmiStepNum==0)
										{
											HmiProcessSerialNum = 0;
											HmiProcessStartNum = 0;
											HmiProcessStopNum = 0;
											HmiProcessAction = 0;
										}
										
										//流程号变化时，更新界面
										if(HmiProcessNumFlag != HmiProcessNum)
										{
											HmiProcessNumFlag = HmiProcessNum;
											GetProcessData();
										}
										
										if(HmiProcessLast==1)//上一个
										{
											HmiProcessLast = 0;
											if(HmiProcessSerialNum>1)
												HmiProcessSerialNum--;
											else
												HmiProcessSerialNum = HmiStepNum;
 											UpdataProcessToHmi();
										}
										else
											if(HmiProcessNext==2)//下一个
											{
												HmiProcessNext = 0;
												if(HmiProcessSerialNum<HmiStepNum)
													HmiProcessSerialNum++;
												else
													if(HmiProcessSerialNum!=0)
														HmiProcessSerialNum = 1;
												UpdataProcessToHmi();
											}
										
									}									
									//复制流程
									if(HmiScreenSetGet==FuZhiLiuChengTanChuJieMian)
									{
										while(HmiScreenSetGet==FuZhiLiuChengTanChuJieMian)
										{
											//被复制流程号为零时置1
											if(HmiProcessCopiedNum==0)
												HmiProcessCopiedNum=1;	
											//输入的被复制流程号变化时更新
											if(HmiProcessCopiedNumTemp!=HmiProcessCopiedNum)
												HmiProcessCopiedCount = GetProcessStepNum(HmiProcessCopiedNum);
											
											//确定复制
											if(HmiProcessMode==1)
											{
												//读取被复制信息到当前
												GetProcessDataFrom(HmiProcessCopiedNum);
												//保存被复制信息
												SetProcessData();	
												
												//设置当前序号为1
												if(HmiStepNum!=0)
													HmiProcessSerialNum = 1;
											
												//退出复制模式
												HmiProcessMode = 0;
											}
											osdelay_ms(10);
										}
									}
									//添加流程
									if(HmiProcessMode==2)
									{
										//流程步数加一
										HmiStepNum++;
										//序号等于流程数
										HmiProcessSerialNum = HmiStepNum;
										
										//起始路径号默认为0则置1
										if(HmiProcessStartNum==0)
											HmiProcessStartNum = 1;
										
										while(HmiProcessMode==2)
										{
											switch(HmiProcessAction)
											{
												case 0://单次执行
													break;
												case 1://顺序执行到
													if(HmiProcessStopNum<=HmiProcessStartNum)
													{
														if(HmiProcessStartNum==ProcessNum)
															HmiProcessStopNum=HmiProcessStartNum;
														else
															HmiProcessStopNum=HmiProcessStartNum+1;
													}
													break;
												case 2://倒序执行
													if(HmiProcessStopNum>=HmiProcessStartNum)
													{
														if(HmiProcessStartNum==1)
															HmiProcessStopNum=HmiProcessStartNum;
														else
															HmiProcessStopNum=HmiProcessStartNum-1;
													}
													break;
												case 3://循环执行
													if(HmiProcessStopNum==0)
													{
															HmiProcessStopNum=1;
													}
													break;
												default:break;
											}
											
											//确定
											if(HmiProcessEnter==1)
											{
												HmiProcessEnter = 0;
												//保存并更新数据
												SetProcessData();
												
												//退出添加模式
												HmiProcessMode = 0;
											}
											//取消
											else if(HmiProcessEnter==2) 
											{
												HmiProcessEnter = 0;
												
												//流程步数减一
												HmiStepNum--;
												//序号等于流程数
												HmiProcessSerialNum = HmiStepNum;
												
												//退出添加模式
												HmiProcessMode = 0;
											}
											osdelay_ms(10);
										}
									}
									
									//插入流程
									if(HmiProcessMode==3)
									{
										//流程步数加一
										HmiStepNum++;
										//序号为零时加一
										if(HmiProcessSerialNum==0)
											HmiProcessSerialNum = 1;
										
										//起始路径号默认为0则置1
										if(HmiProcessStartNum==0)
											HmiProcessStartNum = 1;
										
										while(HmiProcessMode==3)
										{
											switch(HmiProcessAction)
											{
												case 0://单次执行
													break;
												case 1://顺序执行到
													if(HmiProcessStopNum<=HmiProcessStartNum)
													{
														if(HmiProcessStartNum==ProcessNum)
															HmiProcessStopNum=HmiProcessStartNum;
														else
															HmiProcessStopNum=HmiProcessStartNum+1;
													}
													break;
												case 2://倒序执行
													if(HmiProcessStopNum>=HmiProcessStartNum)
													{
														if(HmiProcessStartNum==1)
															HmiProcessStopNum=HmiProcessStartNum;
														else
															HmiProcessStopNum=HmiProcessStartNum-1;
													}
													break;
												case 3://循环执行
													if(HmiProcessStopNum==0)
													{
															HmiProcessStopNum=1;
													}
													break;
												default:break;
											}
											
											//确定
											if(HmiProcessEnter==1)
											{
												HmiProcessEnter = 0;
												
												//保存并更新数据
												InsertProcessData();
												
												//退出插入模式
												HmiProcessMode = 0;
											}
											//取消
											else if(HmiProcessEnter==2) 
											{
												HmiProcessEnter = 0;
												
												//流程步数减一
												HmiStepNum--;
												//序号为1时减一
												if(HmiProcessSerialNum==1)
													HmiProcessSerialNum = 0;
												
												//退出添加模式
												HmiProcessMode = 0;
											}
											osdelay_ms(10);
										}
									}									
									//更改流程
									if(HmiProcessMode==4)
									{
										while(HmiProcessMode==4)
										{
											switch(HmiProcessAction)
											{
												case 0://单次执行
													break;
												case 1://顺序执行到
													if(HmiProcessStopNum<=HmiProcessStartNum)
													{
														if(HmiProcessStartNum==ProcessNum)
															HmiProcessStopNum=HmiProcessStartNum;
														else
															HmiProcessStopNum=HmiProcessStartNum+1;
													}
													break;
												case 2://倒序执行
													if(HmiProcessStopNum>=HmiProcessStartNum)
													{
														if(HmiProcessStartNum==1)
															HmiProcessStopNum=HmiProcessStartNum;
														else
															HmiProcessStopNum=HmiProcessStartNum-1;
													}
													break;
												case 3://循环执行
													if(HmiProcessStopNum==0)
													{
															HmiProcessStopNum=1;
													}
													break;
												default:break;
											}
											
											//确定
											if(HmiProcessEnter==1)
											{
												HmiProcessEnter = 0;
												//保存并更新数据
												SetProcessData();
												
												//退出更改模式
												HmiProcessMode = 0;
											}
											//取消
											else if(HmiProcessEnter==2) 
											{
												HmiProcessEnter = 0;

												//退出添加模式
												HmiProcessMode = 0;
											}
											osdelay_ms(10);
										}
									}									
									//删除流程
									if(HmiProcessMode==5)
									{
										DeleteProcessData();
										//退出删除模式
										HmiProcessMode = 0;
									}
								}
						}break;
			case LiuChengSheZhiJieMian: 
							{		
								//如果路径号为零，则置一
								if(HmiProcessNum==0)
								{
									HmiProcessNum = 1;
								}
							}
							break;
			case ZhiXingLuJingJieMian: //执行路径
							{		
								while(HmiScreenSetGet==ZhiXingLuJingJieMian)
								{
									if(ZhiXingLuJingQueDing==1)
									{
										//保存路径号
										SetOneParameterToSystem(HmiRouteNum,24);
										HmiTask = 1;
										SystemParameter[26] = HmiTask;
										//保存任务号
										SetOneParameterToSystem(HmiTask,26);
										ZhiXingLuJingQueDing = 0;
									}
									osdelay_ms(10);
								}
							}
							break;
			case 43: //执行流程
							{		
								while(HmiScreenSetGet==43)
								{
									if(ZhiXingLiuChengQueDing==1)
									{
										//保存流程号
										SetOneParameterToSystem(HmiProcessNum,25);
										HmiTask = 2;
										SystemParameter[26] = HmiTask;
										//保存任务号
										SetOneParameterToSystem(HmiTask,26);
										ZhiXingLiuChengQueDing = 0;
										
										//任务状态为正在运行
										HmiTaskState = 5;
									}
									osdelay_ms(10);
								}							
							}
							break;			
			case 44: //自动界面
							{		
								Zi_Dong();	//切到自动程序
								while(HmiScreenSetGet==44)
								{
									if(PLC_OutPut[4]==1)						//屏幕的手动按键按下时
									{
										Shou_Dong();		//切到手动程序
									}
									else if(PLC_OutPut[5]==1)				//屏幕的自动按键按下时
									{
										Zi_Dong();			//切到自动程序
									}
									if(Mode_flag == 1)
									{
											if(PLC_OutPut[11]==1)			//启动
											{
												Qi_Dong();
											}
											if(PLC_OutPut[12]==1)		 	//停止
											{
												Ting_Zhi();
											}
									}
									osdelay_ms(10);
								}		
							}
							break;	
			case QuXiaoRenWuJieMian: //取消任务
							{		
								while(HmiScreenSetGet==QuXiaoRenWuJieMian)
								{
									if(QuXiaoRenWuQueDing==1)
									{
										QuXiaoRenWuQueDing = 0;
										
										HmiTask = 0;
										
										//任务状态为空闲
										HmiTaskState = 0;
										
										//停车
										Ting_Zhi();
										
										//删除任务
										OSTaskDel((OS_TCB*)&Task5_TaskTCB,&err);
										//重新创建任务
										OSTaskCreate((OS_TCB 	* )&Task5_TaskTCB,		
									  (CPU_CHAR	* )"Task5 task", 		
													 (OS_TASK_PTR )Task5_task, 			
													 (void		* )0,					
													 (OS_PRIO	  )Task5_TASK_PRIO,     	
													 (CPU_STK   * )&Task5_TASK_STK[0],	
													 (CPU_STK_SIZE)Task5_STK_SIZE/10,	
													 (CPU_STK_SIZE)Task5_STK_SIZE,		
													 (OS_MSG_QTY  )0,					
													 (OS_TICK	  )0,					
													 (void   	* )0,				
													 (OS_OPT      )OS_OPT_TASK_STK_CHK|OS_OPT_TASK_STK_CLR, 
													 (OS_ERR 	* )&err);
									}
									osdelay_ms(10);
								}							
							}
							break;
							default:break;
		}	
	
		osdelay_ms(20);
	}	