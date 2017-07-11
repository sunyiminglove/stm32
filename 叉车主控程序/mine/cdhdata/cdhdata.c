#include "CDHdata.h"

void CDH_Init(void)
{
 
	GPIO_InitTypeDef  GPIO_InitStructure;
	
	//ǰ�����ŵ����Ķ˿ڳ�ʼ��
 	
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOC|RCC_AHB1Periph_GPIOE|RCC_AHB1Periph_GPIOF|RCC_AHB1Periph_GPIOG, ENABLE);
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_13;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;//��ͨ����ģʽ
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;//100MHz
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;//����
  GPIO_Init(GPIOC, &GPIO_InitStructure);//��ʼ��
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2 | GPIO_Pin_3 | GPIO_Pin_4 | GPIO_Pin_5| GPIO_Pin_6;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;//��ͨ����ģʽ
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;//100MHz
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;//����
  GPIO_Init(GPIOE, &GPIO_InitStructure);//��ʼ��
	
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1 |GPIO_Pin_2 | GPIO_Pin_3 | GPIO_Pin_4 | GPIO_Pin_5| GPIO_Pin_6|GPIO_Pin_7 | GPIO_Pin_8 | GPIO_Pin_9; //KEY0 KEY1 KEY2��Ӧ����
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;//��ͨ����ģʽ
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;//100M
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;//����
  GPIO_Init(GPIOF, &GPIO_InitStructure);//

	//�������ŵ����Ķ˿ڳ�ʼ��
//	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA|RCC_AHB1Periph_GPIOC|RCC_AHB1Periph_GPIOF, ENABLE);
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4 | GPIO_Pin_5| GPIO_Pin_6|GPIO_Pin_7;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;//��ͨ����ģʽ
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;//100MHz
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;//����
  GPIO_Init(GPIOA, &GPIO_InitStructure);//��ʼ��
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0|GPIO_Pin_4| GPIO_Pin_5;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;//��ͨ����ģʽ
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;//100MHz
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;//����
  GPIO_Init(GPIOC, &GPIO_InitStructure);//��ʼ��
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10; //KEY0 KEY1 KEY2��Ӧ����
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;//��ͨ����ģʽ
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;//100M
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;//����
  GPIO_Init(GPIOF, &GPIO_InitStructure);//
	
	//���ĸ��ŵ����Ķ˿ڳ�ʼ��
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB|RCC_AHB1Periph_GPIOF|RCC_AHB1Periph_GPIOG, ENABLE);
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1 ;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;//��ͨ����ģʽ
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;//100MHz
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;//����
  GPIO_Init(GPIOB, &GPIO_InitStructure);//��ʼ��
	
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_11 |GPIO_Pin_12 | GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_15; //KEY0 KEY1 KEY2��Ӧ����
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;//��ͨ����ģʽ
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;//100M
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;//����
  GPIO_Init(GPIOF, &GPIO_InitStructure);//
	
	GPIO_InitStructure.GPIO_Pin =GPIO_Pin_0;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;//��ͨ����ģʽ
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;//100MHz
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;//����
  GPIO_Init(GPIOG, &GPIO_InitStructure);//��ʼ��
	
}

/*
//�����16λ�Ĵŵ����øú����ɼ���ǰ�ŵ����ɼ�����ԭʼ����(�ŵ���ת��֮��)
u16 CDH_read16_datan(void)
{
	u16 n=0;
		n<<=1;
		n=n|PFin(9);
		n<<=1;
		n=n|PFin(8);
		n<<=1;
		n=n|PFin(7);
		n<<=1;
		n=n|PFin(6);
		n<<=1;
		n=n|PFin(5);
		n<<=1;
		n=n|PFin(4);
		n<<=1;
		n=n|PFin(3);
		n<<=1;
		n=n|PFin(2);
	
		n<<=1;
		n=n|PFin(1);
		n<<=1;
		n=n|PFin(0);
		n<<=1;
		n=n|PCin(13);
		n<<=1;
		n=n|PEin(6);
		n<<=1;
		n=n|PEin(5);
		n<<=1;
		n=n|PEin(4);
		n<<=1;
		n=n|PEin(3);
		n<<=1;
		n=n|PEin(2);
	
	return n;
}



*/
//�����16λ�Ĵŵ����øú����ɼ���ǰ�ŵ����ɼ�����ԭʼ����
u16 CDH_read16_datan(void)
{
	u16 n=0;
		
			n<<=1;
			n=n|PEin(2);
			n<<=1;
			n=n|PEin(3);
			n<<=1;
			n=n|PEin(4);
			n<<=1;
			n=n|PEin(5);
			n<<=1;
			n=n|PEin(6);
			n<<=1;
			n=n|PCin(13);
			n<<=1;
			n=n|PFin(0);
			n<<=1;
			n=n|PFin(1);
			
			n<<=1;
			n=n|PFin(2);
			n<<=1;
			n=n|PFin(3);
			n<<=1;
			n=n|PFin(4);
			n<<=1;
			n=n|PFin(5);
			n<<=1;
			n=n|PFin(6);
			n<<=1;
			n=n|PFin(7);
			n<<=1;
			n=n|PFin(8);
			n<<=1;
			n=n|PFin(9);
			
	
	return n;
}

u8 CDH_read_datan(u8 CDH_num)//��ȡ�ŵ�����ԭʼ�����ݵĿ������
{
	u8 n=0;
	switch(CDH_num)
	{
		case 1:
					n<<=1;
					n=n|PEin(3);
					n<<=1;
					n=n|PEin(2);
					n<<=1;
					n=n|PEin(5);
					n<<=1;
					n=n|PEin(4);
					n<<=1;
					n=n|PCin(13);
					n<<=1;
					n=n|PEin(6);
					n<<=1;
					n=n|PFin(1);
					n<<=1;
					n=n|PFin(0);
					break;
		case 2:
					n<<=1;
					n=n|PFin(3);
					n<<=1;
					n=n|PFin(2);
					n<<=1;
					n=n|PFin(5);
					n<<=1;
					n=n|PFin(4);
					n<<=1;
					n=n|PFin(7);
					n<<=1;
					n=n|PFin(6);
					n<<=1;
					n=n|PFin(9);
					n<<=1;
					n=n|PFin(8);
					break;
		case 3:
					n<<=1;
					n=n|PCin(0);
					n<<=1;
					n=n|PFin(10);
					n<<=1;
					n=n|PAin(5);
					n<<=1;
					n=n|PAin(4);
					n<<=1;
					n=n|PAin(7);
					n<<=1;
					n=n|PAin(6);
					n<<=1;
					n=n|PCin(5);
					n<<=1;
					n=n|PCin(4);
					break;
		case 4:
					n<<=1;
					n=n|PBin(1);
					n<<=1;
					n=n|PBin(0);
					n<<=1;
					n=n|PFin(12);
					n<<=1;
					n=n|PFin(11);
					n<<=1;
					n=n|PFin(14);
					n<<=1;
					n=n|PFin(13);
					n<<=1;
					n=n|PGin(0);
					n<<=1;
					n=n|PFin(15);
					break;
	}
	return n;
}
u8 n=0,a=0;
u8 CDH_read_dataa(u8 CDH_num)//���ŵ�����ԭʼ���ݽ��зּ�����
{
	switch(CDH_num)
	{
		case 1:
					n<<=1;
					n=n|PEin(3);
					n<<=1;
					n=n|PEin(2);
					n<<=1;
					n=n|PEin(5);
					n<<=1;
					n=n|PEin(4);
					n<<=1;
					n=n|PCin(13);
					n<<=1;
					n=n|PEin(6);
					n<<=1;
					n=n|PFin(1);
					n<<=1;
					n=n|PFin(0);
					switch(n)
					{
						//case 0xff: a=0; break;
						case 0xfe: a=1; break;
						case 0xfc: a=2; break;
						case 0xf8: a=3; break;
						case 0xf0: a=4; break;
						case 0xe0: a=5; break;
						case 0xe1: a=6; break;
						case 0xc1: a=7; break;
						
						case 0xc3: a=8; break;
						case 0x83: a=9; break;
						case 0x87: a=10;break;
						case 0x07: a=11;break;
						case 0x0f: a=12;break;
						case 0x1f: a=13;break;
						case 0x3f: a=14;break;
						case 0x7f: a=15;break;
						
						//default :	 a=0; break;
		
					}
					break;
		case 2:
					n<<=1;
					n=n|PFin(3);
					n<<=1;
					n=n|PFin(2);
					n<<=1;
					n=n|PFin(5);
					n<<=1;
					n=n|PFin(4);
					n<<=1;
					n=n|PFin(7);
					n<<=1;
					n=n|PFin(6);
					n<<=1;
					n=n|PFin(9);
					n<<=1;
					n=n|PFin(8);
					
					switch(n)
					{
						//case 0xff: a=0; break;
						case 0xfe: a=1; break;
						case 0xfc: a=2; break;
						case 0xf8: a=3; break;
						case 0xf0: a=4; break;
						case 0xe0: a=5; break;
						case 0xe1: a=6; break;
						case 0xc1: a=7; break;
						
						case 0xc3: a=8; break;
						case 0x83: a=9; break;
						case 0x87: a=10;break;
						case 0x07: a=11;break;
						case 0x0f: a=12;break;
						case 0x1f: a=13;break;
						case 0x3f: a=14;break;
						case 0x7f: a=15;break;
						
						//default :	 a=0; break;
					}
					break;
		case 3:
					n<<=1;
					n=n|PCin(0);
					n<<=1;
					n=n|PFin(10);
					n<<=1;
					n=n|PAin(5);
					n<<=1;
					n=n|PAin(4);
					n<<=1;
					n=n|PAin(7);
					n<<=1;
					n=n|PAin(6);
					n<<=1;
					n=n|PCin(5);
					n<<=1;
					n=n|PCin(4);
				
					switch(n)
					{
						//case 0xff: a=0; break;
						case 0xfe: a=1; break;
						case 0xfc: a=2; break;
						case 0xf8: a=3; break;
						case 0xf0: a=4; break;
						case 0xe0: a=5; break;
						case 0xe1: a=6; break;
						case 0xc1: a=7; break;
						
						case 0xc3: a=8; break;
						case 0x83: a=9; break;
						case 0x87: a=10;break;
						case 0x07: a=11;break;
						case 0x0f: a=12;break;
						case 0x1f: a=13;break;
						case 0x3f: a=14;break;
						case 0x7f: a=15;break;
						
						//default :	 a=0; break;
					}
					break;
		case 4:
					n<<=1;
					n=n|PBin(1);
					n<<=1;
					n=n|PBin(0);
					n<<=1;
					n=n|PFin(12);
					n<<=1;
					n=n|PFin(11);
					n<<=1;
					n=n|PFin(14);
					n<<=1;
					n=n|PFin(13);
					n<<=1;
					n=n|PGin(0);
					n<<=1;
					n=n|PFin(15);
		
					switch(n)
					{
						//case 0xff: a=0; break;
						case 0xfe: a=1; break;
						case 0xfc: a=2; break;
						case 0xf8: a=3; break;
						case 0xf0: a=4; break;
						case 0xe0: a=5; break;
						case 0xe1: a=6; break;
						case 0xc1: a=7; break;
						
						case 0xc3: a=8; break;
						case 0x83: a=9; break;
						case 0x87: a=10;break;
						case 0x07: a=11;break;
						case 0x0f: a=12;break;
						case 0x1f: a=13;break;
						case 0x3f: a=14;break;
						case 0x7f: a=15;break;
						
					//	default :	 a=0; break;
						
					}
					break;
	}		
	return a;
}


//�������ĵ������������������ҵ�CDH_read_dataa�������ܣ�
Fencha_struct front_cdh16,backl_cdh8,backr_cdh8;//����һ��Fencha_struct���͵�ȫ�ֱ���
Fencha_struct findtemp={0,0,0,0,0,0};//�����������еĽṹ�����鶨��

//16λ�ŵ������ݴ�����
//dst:�ŵ�����ԭʼ16���Ƶ�16λ��
//num:����ʱ�����������������1~15��
//dir:�ֲ淽��1����ֲ棬2���ҷֲ�
//����ֵ��Fencha_struct�ṹ��
Fencha_struct FindSpace(u16 dst,u8 num,u8 dir)
{
	u16 i=0,dirr=dir;
	u16 p=~dst,numr=0,numl=0;
	Fencha_struct find;
	AA:	
	find.zeroNum = 0;
	find.zeroContinue = 0;
	find.Num = 0;
	find.Distance = 0;
	find.Error = 0;
	//������Ч��ĸ���
	for(i=0;i<16;i++)
	{
		if((p>>i)&0x0001)
		{
			find.Num++;
		}
	}
	//�ж��ұ�0�ĸ���
	for(i=0;i<16;i++)
	{
		if(((p>>i)&0x0001)==0)
		{
			numr++;
		}
		else
		{
			i=16;//ֱ���˳�
		}
	}
	
	//�ж����0�ĸ���
	for(i=0;i<16;i++)
	{
		if(((p<<i)&0x8000)==0)
		{
			numl++;
		}
		else
		{
			i=16;//ֱ���˳�
		}
	}		
	//����0�ĸ�����������0���ֵ�λ��
	for(i=numr;i<(16-numl);i++)
	{
		if(((p>>i)&0x0001)==0)
		{
			find.zeroLoctaion[find.zeroNum]=i;
			find.zeroNum++;
		}
	}
		
	//�ж϶ϵ��Ƿ�����
	if(find.zeroNum>0)
	{
		find.zeroContinue = 1;
		if(find.zeroNum>1)
		{
			for(i = 0;i<(find.zeroNum-1);i++)
			{
				if(find.zeroLoctaion[i+1]-find.zeroLoctaion[i]==1)
				{
					continue;
				}
				else
				{
					find.zeroContinue++;
				}
			}
		}
	}
	//������Ч���������λ�õľ���
	if(find.Num==0)//û�ҵ���Ч�㣬���뷵��0
		find.Error = 1;
	else
	{
//		if((findtemp.zeroNum==0)&&(find.zeroNum>4)&&(findtemp.Num>0))
//		{
//				if(find.zeroLoctaion[find.zeroNum/2]>=9)
//					dirr = 2;
//				else
//					dirr = 1;
//		}
		if(find.zeroNum>0)//�жϵ㣬����0
		{
			if(find.zeroContinue==1)//һ���ֲ�
			{
				if(dirr==2)//�ҷֲ�
				{
					for(i=numr;i<16;i++)
					{
						if((p>>i)&0x0001)
						{
							p = p&(~(0x0001<<i));
						}
						else
						{
							i = 16;
						}
					}
					goto AA;
				}
				else if(dirr==1)//��ֲ�
				{
					for(i=numl;i<16;i++)
					{
						if((p<<i)&0x8000)
						{
							p = p&(~(0x8000>>i));
						}
						else
						{
							i = 16;
						}
					}
					goto AA;
				}
				else
				{
					find.Error = 1;
				}
			}
			
		}
		else//�������
		{
			if(find.Num<=num)
			{
				find.Distance = numl - numr + 16;
			}
			else
			{
				find.Error = 1;
			}
		}
	}
	
	findtemp = find;
	return find;

}
//8λ�ŵ������ݴ�����
//dst:�ŵ�����ԭʼ16���Ƶ�8λ��
//num:����ʱ�����������������1~7��
//dir:�ֲ淽��1����ֲ棬2���ҷֲ�
//����ֵ��Fencha_struct�ṹ��

Fencha_struct FindSpace1(u8 dst,u8 num,u8 dir)
{
	u8 i=0,dirr=dir;
	u8 p=~dst,numr=0,numl=0;
	Fencha_struct find;
	AA:	
	find.zeroNum = 0;
	find.zeroContinue = 0;
	find.Num = 0;
	find.Distance = 0;
	find.Error = 0;
	//������Ч��ĸ���
	for(i=0;i<8;i++)
	{
		if((p>>i)&0x01)
		{
			find.Num++;
		}
	}
	//�ж��ұ�0�ĸ���
	for(i=0;i<8;i++)
	{
		if(((p>>i)&0x01)==0)
		{
			numr++;
		}
		else
		{
			i=8;//ֱ���˳�
		}
	}
	
	//�ж����0�ĸ���
	for(i=0;i<8;i++)
	{
		if(((p<<i)&0x80)==0)
		{
			numl++;
		}
		else
		{
			i=8;//ֱ���˳�
		}
	}		
	//����0�ĸ�����������0���ֵ�λ��
	for(i=numr;i<(8-numl);i++)
	{
		if(((p>>i)&0x01)==0)
		{
			find.zeroLoctaion[find.zeroNum]=i;
			find.zeroNum++;
		}
	}
		
	//�ж϶ϵ��Ƿ�����
	if(find.zeroNum>0)
	{
		find.zeroContinue = 1;
		if(find.zeroNum>1)
		{
			for(i = 0;i<(find.zeroNum-1);i++)
			{
				if(find.zeroLoctaion[i+1]-find.zeroLoctaion[i]==1)
				{
					continue;
				}
				else
				{
					find.zeroContinue++;
				}
			}
		}
	}
	//������Ч���������λ�õľ���
	if(find.Num==0)//û�ҵ���Ч�㣬���뷵��0
		find.Error = 1;
	else
	{
//		if((findtemp.zeroNum==0)&&(find.zeroNum>4)&&(findtemp.Num>0))
//		{
//				if(find.zeroLoctaion[find.zeroNum/2]>=9)
//					dirr = 2;
//				else
//					dirr = 1;
//		}
		if(find.zeroNum>0)//�жϵ㣬����0
		{
			if(find.zeroContinue==1)//һ���ֲ�
			{
				if(dirr==2)//�ҷֲ�
				{
					for(i=numr;i<8;i++)
					{
						if((p>>i)&0x01)
						{
							p = p&(~(0x01<<i));
						}
						else
						{
							i = 8;
						}
					}
					goto AA;
				}
				else if(dirr==1)//��ֲ�
				{
					for(i=numl;i<8;i++)
					{
						if((p<<i)&0x80)
						{
							p = p&(~(0x80>>i));
						}
						else
						{
							i = 8;
						}
					}
					goto AA;
				}
				else
				{
					find.Error = 1;
				}
			}
			
		}
		else//�������
		{
			if(find.Num<=num)
			{
				find.Distance = numl - numr + 8;
			}
			else
			{
				find.Error = 1;
			}
		}
	}
	
	findtemp = find;
	return find;
}

