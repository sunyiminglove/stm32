	//ִ��վ�㶯��
void StationAction(u16 num)
{
//	next_keynumber=NowRouteInfor[StationNumber][5];
//	//��յر�
//	keynumber=0;

//	while(keynumber==0||keynumber!=NowRouteInfor[StationNumber][5])	//ɨ���ر꣬��Ŀ��ֵ�Ļ�������while
//	{		
//		osdelay_ms(20);			
//	}
//	
//	StationNumber++;
//	if(StationNumber==RouteStationNum[HmiRouteNum-1])
//	{
//		StationNumber=0;	
//		speed=PLC_Data[6];							//��ʼ���ٶ�ֵ
//	}
//	next_keynumber=NowRouteInfor[StationNumber][5];
//	
//	
//	
	
		HmiStationSerialNum++;
	//��յر�
	keynumber=0;
	//�ȴ��ر�
//					while(keynumber==0||keynumber!=NowRouteInfor[i][5])	
//					{		
//						osdelay_ms(20);			
//					
	HmiNextRfidNum = NowRouteInfor[num][5];
	osdelay_s(3);	

	//�������Զ�
	while(QD_flag != 1 || Mode_flag != 1)
	{
		osdelay_ms(20);	
	}

	keynumber = HmiNextRfidNum;
	HmiRfidNum = keynumber;
					
	
//	switch(NowRouteInfor[num][4])//�ٶȵ�λ�ж�
//	{
//		case 0:	break;//�����ϴ���Ϣ
//		case 1://����
//		{
//			speek("1��");
//			speed=PLC_Data[18];
//			PWM_val(TIM4,2,speed);					//�趨�ٶ�PWM��ֵ����
//			osdelay_ms(SPEEKTIME);
//		}break;					
//		case 2://����
//		{
//			speek("2��");
//			speed=PLC_Data[19];
//			PWM_val(TIM4,2,speed);					//�趨�ٶ�PWM��ֵ����
//			osdelay_ms(SPEEKTIME);
//		}break;				
//		case 3://����
//		{
//			speek("3��");
//			speed=PLC_Data[20];
//			PWM_val(TIM4,2,speed);					//�趨�ٶ�PWM��ֵ����						osdelay_ms(SPEEKTIME);						
//		}break;					
//	}
//	switch(NowRouteInfor[num][10])//AGV�Ե��ݵ�ʹ�����
//	{
//		case 0:	break;//���ݲ�ʹ��
//		case 1://AGVȥһ¥
//		{
//			AGV_QuYiLou();
//		}break;				
//		case 2://AGVȥ��¥
//		{
//			AGV_QuSanLou();
//		}break;	
//	}
//	switch(NowRouteInfor[num][6])//ֹͣ��ǰ���������󡢺����ҡ�����������	
//	{
//		case 0:	break;//�����ϴ���Ϣ
//		case 1://ֹͣ
//		case 2://ǰ��
//		case 3://������
//		case 4://������
//		case 6://����
//		case 7://����						
//		{
//			Ting_Zhi();
//			osdelay_ms(SPEEKTIME);
//		}break;	
//		case 5:break;//ͨ��				
//	}			
//	switch(NowRouteInfor[num][2])//�ֲ��ж�
//	{
//		case 0:	break;//�����ϴ���Ϣ
//		case 1://��ֲ�
//		{
//			Zuo_Fen();
//			osdelay_ms(SPEEKTIME);						
//		}break;	
//		case 2://�ҷֲ�
//		{
//			You_Fen();
//			osdelay_ms(SPEEKTIME);						
//		}break;			
//	}
//	switch(NowRouteInfor[num][3])//��������ж�
//	{
//		case 0:	break;//�����ϴ���Ϣ
//		case 1://�������
//		{
//			Cha_Sheng();	
//		}break;	
//		case 2://����½�
//		{
//			Cha_Jiang();
//		}break;			
//									
//	}
//	switch(NowRouteInfor[num][0])//Զ���⿪���ж�
//	{
//		case 0:	break;//�����ϴ���Ϣ
//		case 1://Զ���⿪
//		{
//			QBZ_Yflag=0;
//			speek("Զ��");	
//			osdelay_ms(SPEEKTIME);						
//		}break;					
//		case 2://Զ�����
//		{
//			QBZ_Yflag=1;
//			speek("Զ��");
//			osdelay_ms(SPEEKTIME);						
//		}break;							
//	}				
//	switch(NowRouteInfor[num][1])//�����⿪���ж�
//	{
//		case 0:	break;//�����ϴ���Ϣ
//		case 1://�����⿪
//		{
//			QBZ_Jflag=0;
//			speek("����");
//			osdelay_ms(SPEEKTIME);						
//		}break;					
//		case 2://�������
//		{
//			QBZ_Jflag=1;
//			speek("����");
//			osdelay_ms(SPEEKTIME);						
//		}break;								
//	}
//	switch(NowRouteInfor[num][6])//����ִ�����ж�	
//	{
//		case 0:	break;//�����ϴ���Ϣ
//		case 1: break;//ֹͣ
//		case 2://ǰ��
//		{
//			Qian_Jin();
//			osdelay_ms(SPEEKTIME);
//			Qi_Dong();
//			osdelay_ms(SPEEKTIME);
//		}break;	
//		case 3://������
//		{
//			Hou_Zuo();
//			osdelay_ms(SPEEKTIME);
//			Qi_Dong();
//			osdelay_ms(SPEEKTIME);
//		}break;
//		case 4://������
//		{
//			Hou_You();
//			osdelay_ms(SPEEKTIME);
//			Qi_Dong();
//			osdelay_ms(SPEEKTIME);
//		}break;
//		case 6://����
//		{
//		  Xuan_Zhuang_Ci_Shu = NowRouteInfor[num][9];
//			last_flag=FX_flag;
//			Zuo_Xuan();
//			osdelay_ms(SPEEKTIME);
//			QD_flag=1;
//		}break;
//		case 7://����
//		{
//			Xuan_Zhuang_Ci_Shu = NowRouteInfor[num][9];
//			last_flag=FX_flag;
//			You_Xuan();
//			osdelay_ms(SPEEKTIME);
//			QD_flag=1;
//		}break;
//	}
}
	

//ִ������
void Task5_task(void *p_arg)
{	
	u16 i,j,k;
	p_arg = p_arg;

	while(1)
	{
		if(Mode_flag == 1)
		{
			//ִ��·��
			if(HmiTask==1)
			{
				HmiStationSerialNum = 0;
				//������ѡ·����ִ����Ӧ����
				for(i=0;i<HmiStationNum;i++)
				{
					StationAction(i);
				}
			}
			else
				//ִ������
				if(HmiTask == 2)
				{
					HmiProcessSerialNum = 0;
					for(i=0;i<HmiStepNum;i++)
					{
						HmiProcessSerialNum++;
						switch(NowProcessInfor[i][1])
						{
							case 0://����ִ��
								//����·����
								HmiRouteNum = NowProcessInfor[i][0];
							  //��ȡ·������վ����
								GetRouteStationNum(HmiRouteNum);
								//��ȡ��ǰ·����Ϣ
								GetRouteData(HmiRouteNum);

  							HmiStationSerialNum = 0;
								//������ѡ·����ִ����Ӧ����
								for(j=0;j<HmiStationNum;j++)
								{
									StationAction(j);
								}
								break;
							case 1://˳��ִ��
								for(k=NowProcessInfor[i][0];k<=NowProcessInfor[i][2];k++)
								{
									//����·����
									HmiRouteNum = k;
									//��ȡ·������վ����
									GetRouteStationNum(HmiRouteNum);
									//��ȡ��ǰ·����Ϣ
									GetRouteData(HmiRouteNum);
									
									HmiStationSerialNum = 0;
									//������ѡ·����ִ����Ӧ����
									for(j=0;j<HmiStationNum;j++)
									{
										StationAction(j);
									}
								}
								break;
							case 2://����ִ��
								for(k=NowProcessInfor[i][0];k>=NowProcessInfor[i][2];k--)
								{
									//����·����
									HmiRouteNum = k;
									//��ȡ·������վ����
									GetRouteStationNum(HmiRouteNum);
									//��ȡ��ǰ·����Ϣ
									GetRouteData(HmiRouteNum);
  
									HmiStationSerialNum = 0;
 									//������ѡ·����ִ����Ӧ����
									for(j=0;j<HmiStationNum;j++)
									{
										StationAction(j);
									}
								}
								break;
							case 3://ѭ��ִ��
								//����·����
								HmiRouteNum = NowProcessInfor[i][0];
							  //��ȡ·������վ����
								GetRouteStationNum(HmiRouteNum);
								//��ȡ��ǰ·����Ϣ
								GetRouteData(HmiRouteNum);
								for(k=0;k<NowProcessInfor[i][2];k++)
								{
    							HmiStationSerialNum = 0;
									//������ѡ·����ִ����Ӧ����
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
			case 9: //�ֶ����ƽ���Ĳ���
						{						
							/***************��������ʱ������Ļ�ϵİ�����ʼ*************/	
									if(PLC_OutPut[4]==1)						//��Ļ���ֶ���������ʱ
									{
										Shou_Dong();		//�е��ֶ�����
									}
									else if(PLC_OutPut[5]==1)				//��Ļ���Զ���������ʱ
									{
										Zi_Dong();			//�е��Զ�����
									}
									else if(PLC_OutPut[9]==1)				//���������ť����ʱ
									{
										Cha_Sheng();
									} 
									else if(PLC_OutPut[10]==1)			//����½���ť����ʱ
									{
										Cha_Jiang();
									}
									else if(PLC_OutPut[13]==1)			//��ֲ水ť����ʱ
									{
										Zuo_Fen();
									}
									else if(PLC_OutPut[14]==1)			//�ҷֲ水ť����ʱ
									{
										You_Fen();
									}		
							/***************��������ʱ������Ļ�ϵİ�������*************/
							/*********�泵��ʻ�����ȷ����ʼ***********/	
									if(Mode_flag == 1)
									{
											if(PLC_OutPut[11]==1)			//����
											{
												Qi_Dong();
											}
											if(PLC_OutPut[12]==1)		 	//ֹͣ
											{
												Ting_Zhi();
											}
											else if(PLC_OutPut[6]==1)	//�����ϵ�ǰ����ťȷ�����Ʋ泵����ʻ�����־FX_flag
											{
												Qian_Jin();
											}
											else if(PLC_OutPut[7]==1) //�����ϵĺ�����ťȷ�����Ʋ泵����ʻ�����־FX_flag
											{
												Hou_Zuo();
											}
											else if(PLC_OutPut[8]==1) //�����ϵĺ����Ұ�ťȷ�����Ʋ泵����ʻ�����־FX_flag
											{
												Hou_You();
											}	
											else if(PLC_OutPut[15]==1)//ȥһ¥·��
											{
												yuyin_flag=19;
												HmiRouteNum=5;
											}
									}
							/*********�泵��ʻ�����ȷ������***********/
								
						}break;
			case 11://ϵͳ�������棬�ٶȵĵ�λ����
						{
								if(low_speed!=PLC_Data[18]||middle_speed!= PLC_Data[19]||high_speed!= PLC_Data[20])
								{
										low_speed 	= PLC_Data[18];	 //һ���ٶ� 
										middle_speed= PLC_Data[19];  //�����ٶ�
										high_speed	= PLC_Data[20];  //�����ٶ�
											
										SystemParameter[18]=PLC_Data[18];
										SystemParameter[19]=PLC_Data[19];
										SystemParameter[20]=PLC_Data[20];
										
										W25QXX_Write_16(SystemParameter,0,SystemParaNum);			//����ǰ��Ļ����д�뵽flash��
								}
								if(SystemParameter[52]!=PLC_Data[52])	//���Ÿı�ʱ
								{
										STATIONNUM_170M = PLC_Data[52]+1;
										SystemParameter[52]=PLC_Data[52];
										W25QXX_Write_16(SystemParameter,0,SystemParaNum);			//����ǰ��Ļ����д�뵽flash��
								}			
						}break;
			case 13://������������״̬���µ���Ļ��
						{
							PLC_OutPut[25]=CBBZ2;	//��ۺ������2�����ۣ�
							PLC_OutPut[26]=CBJC2; //��ۻ��ﵽλ������2�����ۣ�
							PLC_OutPut[27]=CBBZ1; //��ۺ������1���Ҳ�ۣ�
							PLC_OutPut[28]=CBJC1; //��ۻ��ﵽλ������1���Ҳ�ۣ�
							PLC_OutPut[29]=QBZ2N; //�������2	:�����ϣ�ǰ���ϣ�
							PLC_OutPut[30]=QBZ2F; //�������2	:Զ���ϣ�ǰ���ϣ�
							PLC_OutPut[46]=JXBZ;  //��е����
						}break;
			case 14://���ݵ��Խ���(�ڳ��϶Ե��ݵ�һ�н��вٿغ���ʾ����״̬)
						{
								if(PLC_OutPut[31]==1)//��¥�����ť
								{
									PLC2_Data[18]=0;
								}
								else if(PLC_OutPut[32]==1)//һ¥�����ť
								{
									PLC2_Data[19]=0;
								}
								else if(PLC_OutPut[33]==1)//3��ť
								{
									PLC2_Data[20]=0;
								}
								else if(PLC_OutPut[34]==1)//1��ť
								{
									PLC2_Data[21]=0;
								}
								else if(PLC_OutPut[35]==1)//����
								{
									PLC2_Data[22]=0;
								}
								else if(PLC_OutPut[36]==1)//����
								{
									PLC2_Data[23]=0;
								}
								PLC_OutPut[37]=PLC2_Data[24];//��¥ƽ�㣨��������¥��
								PLC_OutPut[38]=PLC2_Data[25];//һ¥ƽ�㣨������һ¥��
								PLC_OutPut[39]=PLC2_Data[26];//��¥��״̬����/�أ�
								PLC_OutPut[40]=PLC2_Data[27];//һ¥��״̬����/�أ�
						}break;
			case 15://���ݲ��Դ���ִ��
						{
							/*********����Ļ�ϲ��������ı�ʱ��¼������flash��ʼ********/
								if(time!=PLC_Data[11]||PID.Kp != PLC_Data[8]||PID.Ki != PLC_Data[9]||PID.Kd != PLC_Data[10]||PID1.Kp != PLC_Data[13]||PID1.Ki != PLC_Data[14]||PID1.Kd != PLC_Data[15]||PLC_Data[1]!=PLC_Data[6])
								{
									time=PLC_Data[11];										//����ǰ����PID��������
																												
									PID.Kp = PLC_Data[8];		              //������Ļ��PID����kp
									PID.Ki = PLC_Data[9];                 //������Ļ��PID����ki
									PID.Kd = PLC_Data[10];                //������Ļ��PID����kd
																												
									PID1.Kp = PLC_Data[13];	              //������Ļ��PID1����kp
									PID1.Ki = PLC_Data[14];               //������Ļ��PID1����ki
									PID1.Kd = PLC_Data[15];               //������Ļ��PID1����kd
								
									speed=PLC_Data[1]=PLC_Data[6];							//������Ļ���ٶ���ʾֵ
									PWM_val(TIM4,2,speed);					//�趨�ٶ�PWM��ֵ����
									
									SystemParameter[11]=PLC_Data[11];
									SystemParameter[8] = PLC_Data[8];
									SystemParameter[9] = PLC_Data[9];
									SystemParameter[10]=PLC_Data[10];
									SystemParameter[13]=PLC_Data[13];
									SystemParameter[14]=PLC_Data[14];
									SystemParameter[15]=PLC_Data[15];
									SystemParameter[6] = PLC_Data[6];
									
									
									W25QXX_Write_16(SystemParameter,0,90);			//����ǰ��Ļ����д�뵽flash��
								}
							/*********����Ļ�ϲ��������ı�ʱ��¼������flash����********/
						}break;
			case 23:
						{
							//���·����Ϊ�㣬����һ
							if(HmiRouteNum==0)
							{
								HmiRouteNum = 1;
							}
						}break;
			case 19: 
			case 24: 
			case 25://·������
						{	
								while(HmiScreenSetGet==19||HmiScreenSetGet==24||HmiScreenSetGet==25||HmiScreenSetGet==FuZhiLuJingTanChuJieMian)
								{  
									//����·��
									while(HmiScreenSetGet==FuZhiLuJingTanChuJieMian)//���ڸ���·������
									{
										//������·����Ϊ��ʱ��1
										if(HmiRouteCopiedNum==0)
											HmiRouteCopiedNum=1;	
										
										//����ı��������̺ű仯ʱ����
										if(HmiRouteCopiedNumTemp!=HmiRouteCopiedNum)
											HmiRouteCopiedCount = GetRouteStationNum(HmiRouteCopiedNum);
										
										
										//ȷ������
										if(HmiRoutemode==1)
										{
											//��ȡ��������Ϣ����ǰ
											GetRouteData(HmiRouteCopiedNum);
											
											//���沢���±�������Ϣ
											SetRouteData(HmiRouteNum);	
											
											UpdataStationToHmi();
											
											//���õ�ǰվ��Ϊ1
											if(HmiStationNum!=0)
												HmiStationSerialNum = 1;
											
											//�˳�����ģʽ
											HmiRoutemode=0;
										}
										osdelay_ms(10);
									}

									//���վ��
									if(HmiRoutemode==2)
									{ 
										//վ������һ
										HmiStationNum ++;
										//վ��ŵ���վ����
										HmiStationSerialNum = HmiStationNum;
										
										//�ر������
										keynumber = 0;		
										
										ClearStationToHmi();	
										
										while(HmiRoutemode==2)
										{
											//��������ر꣬���µ���ʾ��
											if(keynumber!=0)
											{
												HmiRfidNum = keynumber;//ˢ�µر��
											}			
											
											//ȷ��
											if(HmiRouteEnter==1)
											{
												HmiRouteEnter = 0;
												//����վ�����ݵ���ǰ����
												UpdataStationToNow();
												//���浱ǰվ������
												SetRouteData(HmiRouteNum);
												//�˳����ģʽ
												HmiRoutemode=	0;
											}
											else
											//ȡ��
											if(HmiRouteEnter==2)
											{
												HmiRouteEnter = 0;
												//վ������һ
												HmiStationNum--;
												//վ��ŵ���վ����
												HmiStationSerialNum = HmiStationNum;
												//�˳����ģʽ
												HmiRoutemode=	0;
											}
											osdelay_ms(10);
										}
									}
									//����վ��
									if(HmiRoutemode==3)
									{
										//վ������һ
										HmiStationNum ++;
										//վ���Ϊ��ʱ��һ
										if(HmiStationNum==0)
											HmiStationSerialNum = 1;
										
										//�ر������
										keynumber = 0;		
										
										ClearStationToHmi();										

										while(HmiRoutemode==3)
										{
											//��������ر꣬���µ���ʾ��
											if(keynumber!=0)
											{
												HmiRfidNum = keynumber;//ˢ�µر��
											}												
											
											//ȷ��
											if(HmiRouteEnter==1)
											{
												HmiRouteEnter = 0;
												
												//վ����Ϣ����ƶ�һ��λ�ã������뵱ǰվ����Ϣ
												for(i=HmiStationNum;i>=HmiStationSerialNum;i--)
												{
													for(j=0;j<StaiionInfor;j++)
													{
														NowRouteInfor[i][j] = NowRouteInfor[i-1][j];
													}
												}
												
												//����վ����Ϣ����ǰ
												UpdataStationToNow();
												
												//����·����Ϣ
												SetRouteData(HmiRouteNum);

												//�˳����ģʽ
												HmiRoutemode=	0;
											}
											else
											//ȡ��
											if(HmiRouteEnter==2)
											{
												HmiRouteEnter = 0;
												//վ������һ
												HmiStationNum--;
												//վ���Ϊ1ʱ����
												if(HmiStationSerialNum==1)
													HmiStationSerialNum = 0;
												//�˳����ģʽ
												HmiRoutemode=	0;
											}

											osdelay_ms(10);
										}

									}
									//����վ��
									if(HmiRoutemode==4)
									{
										while(HmiRoutemode==4)
										{
											//��������ر꣬���µ���ʾ��
											if(keynumber!=0)
											{
												HmiRfidNum = keynumber;//ˢ�µر��
											}			
											
											//ȷ��
											if(HmiRouteEnter==1)
											{
												HmiRouteEnter = 0;
												//����վ�����ݵ���ǰ����
												UpdataStationToNow();
												//���浱ǰվ������
												SetRouteData(HmiRouteNum);
												//�˳����ģʽ
												HmiRoutemode=	0;
											}
											else
											//ȡ��
											if(HmiRouteEnter==2)
											{
												HmiRouteEnter = 0;
												//վ������һ
												HmiStationNum--;
												//վ��ŵ���վ����
												HmiStationSerialNum = HmiStationNum;
												//�˳����ģʽ
												HmiRoutemode=	0;
											}
											osdelay_ms(10);
										}
									}
								
									//ɾ��վ��
									if(HmiRoutemode==5)
									{
										if(HmiStationNum>0)
										{
											//��������������ǰ�ƶ�һλ
											if((HmiStationNum>0)&&((HmiStationNum)!=HmiStationSerialNum))
											{
												//վ����Ϣ��ǰ�ƶ�һ��λ��
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
											
											//����·����Ϣ
											SetRouteData(HmiRouteNum);
											
											//���½���
											UpdataStationToHmi();
										}	
										HmiRoutemode = 0;
									}
									
									//��ѯվ��
									if(HmiRoutemode==0)
									{
										//��·��վ��������0���������Ϊ0ʱ���������Ϊ1����������ʾ����
										if((HmiStationNum>0)&&(HmiStationSerialNum==0))
										{
											HmiStationSerialNum = 1;
											//���µ�����
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
										
										//·���ű仯ʱ�����½���
										if(HmiRouteNumFlag != HmiRouteNum)
										{
											HmiRouteNumFlag = HmiRouteNum;
											//��ȡ·����Ϣ
											GetRouteData(HmiRouteNum);
											//���µ�����
											UpdataStationToHmi();
										}
										
										//��һ��
										if(HmiStationLast == 1)
										{
											HmiStationLast = 0;
											if(HmiStationSerialNum>1)
												HmiStationSerialNum--;
											else
												HmiStationSerialNum = HmiStationNum;
 											UpdataStationToHmi();
										}
										//��һ��
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
										
										if(HmiStationNum==0)		//û��վ��
										{
											//���վ����Ϣ
											ClearStationToHmi();
										}
										else
										{
											//����վ����Ϣ
											UpdataStationToHmi();
										}
									}
									osdelay_ms(10);
								}
						}break;
			case 26://��۴ŵ������ݵ���
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
									
									W25QXX_Write_16(&SystemParameter[60],60,17);			//����ǰ��Ļ����д�뵽flash��
							}
						}break;				
			case LiuChengGuiHuaJieMian://��������
			case FuZhiLiuChengTanChuJieMian:
			case QueDingChaRuLiuChengJieMian:
			case QueDingShanChuLiuChengJieMian:
						{
								while(HmiScreenSetGet==LiuChengGuiHuaJieMian||HmiScreenSetGet==FuZhiLiuChengTanChuJieMian||HmiScreenSetGet==QueDingChaRuLiuChengJieMian||HmiScreenSetGet==QueDingShanChuLiuChengJieMian)
								{ 
									//�鿴ģʽ
									if(HmiProcessMode==0)
									{
										//��ǰ���̲�������0�����ҽ������Ϊ0ʱ���������Ϊ1����������ʾ����
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
										
										//���̺ű仯ʱ�����½���
										if(HmiProcessNumFlag != HmiProcessNum)
										{
											HmiProcessNumFlag = HmiProcessNum;
											GetProcessData();
										}
										
										if(HmiProcessLast==1)//��һ��
										{
											HmiProcessLast = 0;
											if(HmiProcessSerialNum>1)
												HmiProcessSerialNum--;
											else
												HmiProcessSerialNum = HmiStepNum;
 											UpdataProcessToHmi();
										}
										else
											if(HmiProcessNext==2)//��һ��
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
									//��������
									if(HmiScreenSetGet==FuZhiLiuChengTanChuJieMian)
									{
										while(HmiScreenSetGet==FuZhiLiuChengTanChuJieMian)
										{
											//���������̺�Ϊ��ʱ��1
											if(HmiProcessCopiedNum==0)
												HmiProcessCopiedNum=1;	
											//����ı��������̺ű仯ʱ����
											if(HmiProcessCopiedNumTemp!=HmiProcessCopiedNum)
												HmiProcessCopiedCount = GetProcessStepNum(HmiProcessCopiedNum);
											
											//ȷ������
											if(HmiProcessMode==1)
											{
												//��ȡ��������Ϣ����ǰ
												GetProcessDataFrom(HmiProcessCopiedNum);
												//���汻������Ϣ
												SetProcessData();	
												
												//���õ�ǰ���Ϊ1
												if(HmiStepNum!=0)
													HmiProcessSerialNum = 1;
											
												//�˳�����ģʽ
												HmiProcessMode = 0;
											}
											osdelay_ms(10);
										}
									}
									//�������
									if(HmiProcessMode==2)
									{
										//���̲�����һ
										HmiStepNum++;
										//��ŵ���������
										HmiProcessSerialNum = HmiStepNum;
										
										//��ʼ·����Ĭ��Ϊ0����1
										if(HmiProcessStartNum==0)
											HmiProcessStartNum = 1;
										
										while(HmiProcessMode==2)
										{
											switch(HmiProcessAction)
											{
												case 0://����ִ��
													break;
												case 1://˳��ִ�е�
													if(HmiProcessStopNum<=HmiProcessStartNum)
													{
														if(HmiProcessStartNum==ProcessNum)
															HmiProcessStopNum=HmiProcessStartNum;
														else
															HmiProcessStopNum=HmiProcessStartNum+1;
													}
													break;
												case 2://����ִ��
													if(HmiProcessStopNum>=HmiProcessStartNum)
													{
														if(HmiProcessStartNum==1)
															HmiProcessStopNum=HmiProcessStartNum;
														else
															HmiProcessStopNum=HmiProcessStartNum-1;
													}
													break;
												case 3://ѭ��ִ��
													if(HmiProcessStopNum==0)
													{
															HmiProcessStopNum=1;
													}
													break;
												default:break;
											}
											
											//ȷ��
											if(HmiProcessEnter==1)
											{
												HmiProcessEnter = 0;
												//���沢��������
												SetProcessData();
												
												//�˳����ģʽ
												HmiProcessMode = 0;
											}
											//ȡ��
											else if(HmiProcessEnter==2) 
											{
												HmiProcessEnter = 0;
												
												//���̲�����һ
												HmiStepNum--;
												//��ŵ���������
												HmiProcessSerialNum = HmiStepNum;
												
												//�˳����ģʽ
												HmiProcessMode = 0;
											}
											osdelay_ms(10);
										}
									}
									
									//��������
									if(HmiProcessMode==3)
									{
										//���̲�����һ
										HmiStepNum++;
										//���Ϊ��ʱ��һ
										if(HmiProcessSerialNum==0)
											HmiProcessSerialNum = 1;
										
										//��ʼ·����Ĭ��Ϊ0����1
										if(HmiProcessStartNum==0)
											HmiProcessStartNum = 1;
										
										while(HmiProcessMode==3)
										{
											switch(HmiProcessAction)
											{
												case 0://����ִ��
													break;
												case 1://˳��ִ�е�
													if(HmiProcessStopNum<=HmiProcessStartNum)
													{
														if(HmiProcessStartNum==ProcessNum)
															HmiProcessStopNum=HmiProcessStartNum;
														else
															HmiProcessStopNum=HmiProcessStartNum+1;
													}
													break;
												case 2://����ִ��
													if(HmiProcessStopNum>=HmiProcessStartNum)
													{
														if(HmiProcessStartNum==1)
															HmiProcessStopNum=HmiProcessStartNum;
														else
															HmiProcessStopNum=HmiProcessStartNum-1;
													}
													break;
												case 3://ѭ��ִ��
													if(HmiProcessStopNum==0)
													{
															HmiProcessStopNum=1;
													}
													break;
												default:break;
											}
											
											//ȷ��
											if(HmiProcessEnter==1)
											{
												HmiProcessEnter = 0;
												
												//���沢��������
												InsertProcessData();
												
												//�˳�����ģʽ
												HmiProcessMode = 0;
											}
											//ȡ��
											else if(HmiProcessEnter==2) 
											{
												HmiProcessEnter = 0;
												
												//���̲�����һ
												HmiStepNum--;
												//���Ϊ1ʱ��һ
												if(HmiProcessSerialNum==1)
													HmiProcessSerialNum = 0;
												
												//�˳����ģʽ
												HmiProcessMode = 0;
											}
											osdelay_ms(10);
										}
									}									
									//��������
									if(HmiProcessMode==4)
									{
										while(HmiProcessMode==4)
										{
											switch(HmiProcessAction)
											{
												case 0://����ִ��
													break;
												case 1://˳��ִ�е�
													if(HmiProcessStopNum<=HmiProcessStartNum)
													{
														if(HmiProcessStartNum==ProcessNum)
															HmiProcessStopNum=HmiProcessStartNum;
														else
															HmiProcessStopNum=HmiProcessStartNum+1;
													}
													break;
												case 2://����ִ��
													if(HmiProcessStopNum>=HmiProcessStartNum)
													{
														if(HmiProcessStartNum==1)
															HmiProcessStopNum=HmiProcessStartNum;
														else
															HmiProcessStopNum=HmiProcessStartNum-1;
													}
													break;
												case 3://ѭ��ִ��
													if(HmiProcessStopNum==0)
													{
															HmiProcessStopNum=1;
													}
													break;
												default:break;
											}
											
											//ȷ��
											if(HmiProcessEnter==1)
											{
												HmiProcessEnter = 0;
												//���沢��������
												SetProcessData();
												
												//�˳�����ģʽ
												HmiProcessMode = 0;
											}
											//ȡ��
											else if(HmiProcessEnter==2) 
											{
												HmiProcessEnter = 0;

												//�˳����ģʽ
												HmiProcessMode = 0;
											}
											osdelay_ms(10);
										}
									}									
									//ɾ������
									if(HmiProcessMode==5)
									{
										DeleteProcessData();
										//�˳�ɾ��ģʽ
										HmiProcessMode = 0;
									}
								}
						}break;
			case LiuChengSheZhiJieMian: 
							{		
								//���·����Ϊ�㣬����һ
								if(HmiProcessNum==0)
								{
									HmiProcessNum = 1;
								}
							}
							break;
			case ZhiXingLuJingJieMian: //ִ��·��
							{		
								while(HmiScreenSetGet==ZhiXingLuJingJieMian)
								{
									if(ZhiXingLuJingQueDing==1)
									{
										//����·����
										SetOneParameterToSystem(HmiRouteNum,24);
										HmiTask = 1;
										SystemParameter[26] = HmiTask;
										//���������
										SetOneParameterToSystem(HmiTask,26);
										ZhiXingLuJingQueDing = 0;
									}
									osdelay_ms(10);
								}
							}
							break;
			case 43: //ִ������
							{		
								while(HmiScreenSetGet==43)
								{
									if(ZhiXingLiuChengQueDing==1)
									{
										//�������̺�
										SetOneParameterToSystem(HmiProcessNum,25);
										HmiTask = 2;
										SystemParameter[26] = HmiTask;
										//���������
										SetOneParameterToSystem(HmiTask,26);
										ZhiXingLiuChengQueDing = 0;
										
										//����״̬Ϊ��������
										HmiTaskState = 5;
									}
									osdelay_ms(10);
								}							
							}
							break;			
			case 44: //�Զ�����
							{		
								Zi_Dong();	//�е��Զ�����
								while(HmiScreenSetGet==44)
								{
									if(PLC_OutPut[4]==1)						//��Ļ���ֶ���������ʱ
									{
										Shou_Dong();		//�е��ֶ�����
									}
									else if(PLC_OutPut[5]==1)				//��Ļ���Զ���������ʱ
									{
										Zi_Dong();			//�е��Զ�����
									}
									if(Mode_flag == 1)
									{
											if(PLC_OutPut[11]==1)			//����
											{
												Qi_Dong();
											}
											if(PLC_OutPut[12]==1)		 	//ֹͣ
											{
												Ting_Zhi();
											}
									}
									osdelay_ms(10);
								}		
							}
							break;	
			case QuXiaoRenWuJieMian: //ȡ������
							{		
								while(HmiScreenSetGet==QuXiaoRenWuJieMian)
								{
									if(QuXiaoRenWuQueDing==1)
									{
										QuXiaoRenWuQueDing = 0;
										
										HmiTask = 0;
										
										//����״̬Ϊ����
										HmiTaskState = 0;
										
										//ͣ��
										Ting_Zhi();
										
										//ɾ������
										OSTaskDel((OS_TCB*)&Task5_TaskTCB,&err);
										//���´�������
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