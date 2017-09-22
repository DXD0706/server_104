/*
** ------------------------------- Copyright (c) -------------------------------                                     
**
**                           http://www.sojoline.com
**
** note:    Copyright SOJO. ALL RIGHTS RESERVED.
**          This software is provided under license and contains proprietary and
**          confidential material which is the property of Company Name tech. 
**    
** -------------------------------- File Info ----------------------------------
** File name:               DLT634_5101_disk_uart6.c
** Descriptions:            The application of DLT634.5101_2002
**
** -----------------------------------------------------------------------------
** Created by:              Mr.J
** Created date:            2017.5.16
** System:                  Protocol Software System
** Version:                 V3.01
** Descriptions:            The original version
**
** -----------------------------------------------------------------------------
** Modified by:             
** Modified date:           
** Version:                 
** Descriptions:            
**
** ---------------------------------------------------------------------------*/

//#if APP_TASK_DLT634_5101_SLAVE_CFG

#include "dlt634_5101slave_app.h"
#include "dlt634_5101slave_disk.h"
#include "data_cache.h"
#include "types.h"

static int s_masterSPfd;

/* PRIVATE FUNCTION PROTOTYPES -----------------------------------------------*/

/* PUBLIC FUNCTION PROTOTYPES -----------------------------------------------*/
int getMasterSPfd()
{
    return s_masterSPfd;
}

void setMasterSPfd(int serialfd)
{
    s_masterSPfd = serialfd;
}
/* -----------------------------------------------------------------------------
** ��������: DLT634_5101_SLAVE_ReadData
** ��������: ������
** �䡡  ��: pdrv���豸���
**           pbuf����������ָ��
**           count��������
** �䡡  ��: ��
** ȫ�ֱ���: 
** ����ģ��: Readx  ��ײ������
** ����  ��: Mr.J
** �ա�  ��: 2017.8.3
** -----------------------------------------------------------------------------
** �� �� ��: 
** �޸�����:
** �ա�  ��: 
** ---------------------------------------------------------------------------*/
uint16_t DLT634_5101_SLAVE_ReadData(uint8_t pdrv, uint8_t *pbuf, uint16_t count)
{ 
	uint16_t len = 0;  
	
	switch(pdrv)
	{
		case 0:
			len = Readx(pbuf, count, DLT634_5101Slave_Pad[pdrv].Port);
			break;
		default:
			break;
	}
	return(len);
}

/* -----------------------------------------------------------------------------
** ��������: DLT634_5101_SLAVE_WriteData
** ��������: д����
** �䡡  ��: pdrv���豸���
**           pbuf����������ָ��
**           count��д����
** �䡡  ��: ��
** ȫ�ֱ���: 
** ����ģ��: WriteX  ��ײ�д����
** ����  ��: Mr.J
** �ա�  ��: 2017.8.3
** -----------------------------------------------------------------------------
** �� �� ��: 
** �޸�����:
** �ա�  ��: 
** ---------------------------------------------------------------------------*/
uint16_t DLT634_5101_SLAVE_WriteData(uint8_t pdrv, uint8_t *pbuf, uint16_t count)
{ 
	uint16_t len = 0; 
	
	switch(pdrv)
	{
		case 0:
			len = WriteX(pbuf,count,DLT634_5101Slave_Pad[pdrv].Port);
			break;
		default:
			break;
	}
	return(len);
}

//app
/* -----------------------------------------------------------------------------
** ��������: DLT634_5101_SLAVE_C_IC
** ��������: ����
** �䡡  ��: pdrv���豸���
**           pbuf����������ָ��
** �䡡  ��: ��
** ȫ�ֱ���: 
** ����ģ��: DBSend  ���͸������豸����
** ����  ��: Mr.J
** �ա�  ��: 2017.8.3
** -----------------------------------------------------------------------------
** �� �� ��: 
** �޸�����:
** �ա�  ��: 
** ---------------------------------------------------------------------------*/
//LENTH/Lock_ID/TypeID/VSQ/COT_L/COT_H/PubAddr_L/PubAddr_H/InfoAddr_L/InfoAddr_H/QOI
void DLT634_5101_SLAVE_C_IC(uint8_t pdrv, uint8_t *pbuf)//����
{ 
	switch(pdrv)
	{
		case 0:
            pbuf[1] = (DLT634_5101Slave_Pad[pdrv].Port<<4)|USART1_ID; //send to 101master serial device ,MASTER_101_DEV0;
			DBSend(pbuf);
			break;
		default:
			break;
	}
}
/* -----------------------------------------------------------------------------
** ��������: DLT634_5101_SLAVE_C_SC
** ��������: ң��
** �䡡  ��: pdrv���豸���
**           pbuf����������ָ��
** �䡡  ��: ��
** ȫ�ֱ���: 
** ����ģ��: DBSend  ���͸������豸����
** ����  ��: Mr.J
** �ա�  ��: 2017.8.3
** -----------------------------------------------------------------------------
** �� �� ��: 
** �޸�����:
** �ա�  ��: 
** ---------------------------------------------------------------------------*/
//LENTH/Lock_ID/TypeID/VSQ/COT_L/COT_H/PubAddr_L/PubAddr_H/InfoAddr_L/InfoAddr_H/SCO_L/SCO_H
//LENTH/Lock_ID/TypeID/VSQ/COT_L/COT_H/PubAddr_L/PubAddr_H/InfoAddr_L/InfoAddr_H/DCO_L/DCO_H
void DLT634_5101_SLAVE_C_SC(uint8_t pdrv, uint8_t *pbuf)//ң��
{ 
	switch(pdrv)
	{
		case 0:
            pbuf[1] = (DLT634_5101Slave_Pad[pdrv].Port<<4)|USART1_ID;//MASTER_101_DEV0;
			DBSend(pbuf);
			break;
		default:
			break;
	}
}

/* -----------------------------------------------------------------------------
** ��������: DLT634_5101_SLAVE_C_CS
** ��������: ��ʱ
** �䡡  ��: pdrv���豸���
**           pbuf����������ָ��
** �䡡  ��: ��
** ȫ�ֱ���: 
** ����ģ��: DBSend  ���͸������豸����
** ����  ��: Mr.J
** �ա�  ��: 2017.8.3
** -----------------------------------------------------------------------------
** �� �� ��: 
** �޸�����:
** �ա�  ��: 
** ---------------------------------------------------------------------------*/
//LENTH/Lock_ID/TypeID/VSQ/COT_L/COT_H/PubAddr_L/PubAddr_H/InfoAddr_L/InfoAddr_H/CP56Time2a
void DLT634_5101_SLAVE_C_CS(uint8_t pdrv, uint8_t *pbuf)//��ʱ
{ 
	switch(pdrv)
	{
		case 0:
            pbuf[1] = (DLT634_5101Slave_Pad[pdrv].Port<<4)|USART1_ID;//MASTER_101_DEV0;
			DBSend(pbuf);
			break;
		default:
			break;
	}
}

/* -----------------------------------------------------------------------------
** ��������: DLT634_5101_SLAVE_C_SR
** ��������: ��ֵ����
** �䡡  ��: pdrv���豸���
**           pbuf����������ָ��
** �䡡  ��: ��
** ȫ�ֱ���: 
** ����ģ��: DBSend  ���͸������豸����
** ����  ��: Mr.J
** �ա�  ��: 2017.8.3
** -----------------------------------------------------------------------------
** �� �� ��: 
** �޸�����:
** �ա�  ��: 
** ---------------------------------------------------------------------------*/
//LENTH/Lock_ID/TypeID/VSQ/COT_L/COT_H/PubAddr_L/PubAddr_H/InfoAddr_L/InfoAddr_H/SN_L/SN_H
//LENTH/Lock_ID/TypeID/VSQ/COT_L/COT_H/PubAddr_L/PubAddr_H/InfoAddr_L/InfoAddr_H
//LENTH/Lock_ID/TypeID/VSQ/COT_L/COT_H/PubAddr_L/PubAddr_H/InfoAddr_L/InfoAddr_H/SN1_L/SN1_H/SN2_L/SN2_H/SN3_L/SN3_H
//LENTH/Lock_ID/TypeID/VSQ/COT_L/COT_H/PubAddr_L/PubAddr_H/InfoAddr_L/InfoAddr_H/SN1_L/SN1_H/Array
//LENTH/Lock_ID/TypeID/VSQ/COT_L/COT_H/PubAddr_L/PubAddr_H/InfoAddr_L/InfoAddr_H/SN_L/SN_H/PI_L/PI_H//Array(InfoAddr_L/InfoAddr_H/Tag/Len/Value)
void DLT634_5101_SLAVE_C_SR(uint8_t pdrv, uint8_t *pbuf)//��ֵ����
{ 
//	switch(pdrv)
//	{
//		case 0:
//			pbuf[1] = (DLT634_5101Slave_Pad[pdrv].Port<<4)|MASTER_101_DEV0;
//			DBSend(pbuf);
//			break;
//		default:
//			break;
//	}
}

/* -----------------------------------------------------------------------------
** ��������: DLT634_5101_SLAVE_F_FR
** ��������: �ļ���д
** �䡡  ��: pdrv���豸���
**           pbuf����������ָ��
** �䡡  ��: ��
** ȫ�ֱ���: 
** ����ģ��: DBSend  ���͸������豸����
** ����  ��: Mr.J
** �ա�  ��: 2017.8.3
** -----------------------------------------------------------------------------
** �� �� ��: 
** �޸�����:
** �ա�  ��: 
** ---------------------------------------------------------------------------*/
//LENTH/Lock_ID/TypeID/VSQ/COT_L/COT_H/PubAddr_L/PubAddr_H/InfoAddr_L/InfoAddr_H/sty/Array
void DLT634_5101_SLAVE_F_FR(uint8_t pdrv, uint8_t *pbuf)//�ļ���д
{ 
//	switch(pdrv)
//	{
//		case 0:
//			if(pbuf[11]>=7)//д�ļ�
//			{
//				pbuf[1] = (DLT634_5101Slave_Pad[pdrv].Port<<4)|MASTER_101_DEV0;
//				DBSend(pbuf);
//			}
//			else//���ļ�
//			{
//				pbuf[1] = (DLT634_5101Slave_Pad[pdrv].Port<<4)|STORAGE_DEV0;
//				DBSend(pbuf);
//			}
//			break;
//		default:
//			break;
//	}
}

/* -----------------------------------------------------------------------------
** ��������: DLT634_5101_SLAVE_F_SR
** ��������: �������
** �䡡  ��: pdrv���豸���
**           pbuf����������ָ��
** �䡡  ��: ��
** ȫ�ֱ���: 
** ����ģ��: DBSend  ���͸������豸����
** ����  ��: Mr.J
** �ա�  ��: 2017.8.3
** -----------------------------------------------------------------------------
** �� �� ��: 
** �޸�����:
** �ա�  ��: 
** ---------------------------------------------------------------------------*/
//LENTH/Lock_ID/TypeID/VSQ/COT_L/COT_H/PubAddr_L/PubAddr_H/InfoAddr_L/InfoAddr_H/CTYPE
void DLT634_5101_SLAVE_F_SR(uint8_t pdrv, uint8_t *pbuf)//�������
{ 
//	switch(pdrv)
//	{
//		case 0:
//			pbuf[1] = (DLT634_5101Slave_Pad[pdrv].Port<<4)|MASTER_101_DEV0;
//			DBSend(pbuf);
//			break;
//		default:
//			break;
//	}
}

/* -----------------------------------------------------------------------------
** ��������: DLT634_5101_SLAVE_H_SOE
** ��������: �ж��Ƿ���soe
** �䡡  ��: pdrv���豸���
** �䡡  ��: ��
** ȫ�ֱ���: 
** ����ģ��: DBCheck_SOE  �ж��Ƿ���SOE
** ����  ��: Mr.J
** �ա�  ��: 2017.8.3
** -----------------------------------------------------------------------------
** �� �� ��: 
** �޸�����:
** �ա�  ��: 
** ---------------------------------------------------------------------------*/
uint8_t DLT634_5101_SLAVE_H_SOE(uint8_t pdrv)//�ж��Ƿ���soe
{ 
	switch(pdrv)
	{
		case 0:
			return(DBCheck_SOE(DLT634_5101Slave_Pad[pdrv].Port));
		default:
			break;
	}
	return(FALSE);
}

/* -----------------------------------------------------------------------------
** ��������: DLT634_5101_SLAVE_R_SOE
** ��������: ��soe
** �䡡  ��: pdrv���豸���
**         : pbuf������ָ��
** �䡡  ��: ��
** ȫ�ֱ���: 
** ����ģ��: DBRead_SOE  ��SOE
** ����  ��: Mr.J
** �ա�  ��: 2017.8.3
** -----------------------------------------------------------------------------
** �� �� ��: 
** �޸�����:
** �ա�  ��: 
** ---------------------------------------------------------------------------*/
//LENTH/Lock_ID/TypeID/VSQ/COT_L/COT_H/PubAddr_L/PubAddr_H/Array(InfoAddr_L/InfoAddr_H/Value/CP56Time2a)
void DLT634_5101_SLAVE_R_SOE(uint8_t pdrv, uint8_t *pbuf)//��soe
{ 
	switch(pdrv)
	{
		case 0:
			DBRead_SOE(DLT634_5101Slave_Pad[pdrv].Port,pbuf);
			break;
		default:
			break;
	}
}

/* -----------------------------------------------------------------------------
** ��������: DLT634_5101_SLAVE_H_NVA
** ��������: �ж��Ƿ���NVA
** �䡡  ��: pdrv���豸���
** �䡡  ��: ��
** ȫ�ֱ���: 
** ����ģ��: DBCheck_NVA  �ж��Ƿ���NVA
** ����  ��: Mr.J
** �ա�  ��: 2017.8.3
** -----------------------------------------------------------------------------
** �� �� ��: 
** �޸�����:
** �ա�  ��: 
** ---------------------------------------------------------------------------*/
uint8_t DLT634_5101_SLAVE_H_NVA(uint8_t pdrv)//�ж��Ƿ���NVA
{ 
	switch(pdrv)
	{
		case 0:
			return(DBCheck_NVA(DLT634_5101Slave_Pad[pdrv].Port));
		default:
			break;
	}
	return(FALSE);
}

/* -----------------------------------------------------------------------------
** ��������: DLT634_5101_SLAVE_R_NVA
** ��������: ��NVA
** �䡡  ��: pdrv���豸���
**         : pbuf������ָ��
** �䡡  ��: ��
** ȫ�ֱ���: 
** ����ģ��: DBRead_NVA  ���仯ң��
** ����  ��: Mr.J
** �ա�  ��: 2017.8.3
** -----------------------------------------------------------------------------
** �� �� ��: 
** �޸�����:
** �ա�  ��: 
** ---------------------------------------------------------------------------*/
//LENTH/Lock_ID/TypeID/VSQ/COT_L/COT_H/PubAddr_L/PubAddr_H/Array(InfoAddr_L/InfoAddr_H/Value/QDS)
void DLT634_5101_SLAVE_R_NVA(uint8_t pdrv, uint8_t *pbuf)//��NVA
{ 
	switch(pdrv)
	{
		case 0:
			DBRead_NVA(DLT634_5101Slave_Pad[pdrv].Port,pbuf);
			break;
		default:
			break;
	}
}

/* -----------------------------------------------------------------------------
** ��������: DLT634_5101_SLAVE_H_FEvent
** ��������: �ж��Ƿ���FEvent
** �䡡  ��: pdrv���豸���
** �䡡  ��: ��
** ȫ�ֱ���: 
** ����ģ��: DBCheck_FEvent  �ж��Ƿ��й����¼�
** ����  ��: Mr.J
** �ա�  ��: 2017.8.3
** -----------------------------------------------------------------------------
** �� �� ��: 
** �޸�����:
** �ա�  ��: 
** ---------------------------------------------------------------------------*/
uint8_t DLT634_5101_SLAVE_H_FEvent(uint8_t pdrv)//�ж��Ƿ���FEvent
{ 
//	switch(pdrv)
//	{
//		case 0:
//			return(DBCheck_FEvent(DLT634_5101Slave_Pad[pdrv].Port));
//		default:
//			break;
//	}
//	return(FALSE);
}

/* -----------------------------------------------------------------------------
** ��������: DLT634_5101_SLAVE_R_FEvent
** ��������: ��FEvent
** �䡡  ��: pdrv���豸���
**         : pbuf������ָ��
** �䡡  ��: ��
** ȫ�ֱ���: 
** ����ģ��: DBRead_FEvent  �������¼�
** ����  ��: Mr.J
** �ա�  ��: 2017.8.3
** -----------------------------------------------------------------------------
** �� �� ��: 
** �޸�����:
** �ա�  ��: 
** ---------------------------------------------------------------------------*/
//LENTH/Lock_ID/TypeID/VSQ/COT_L/COT_H/PubAddr_L/PubAddr_H/Array
void DLT634_5101_SLAVE_R_FEvent(uint8_t pdrv, uint8_t *pbuf)//��FEvent
{ 
//	switch(pdrv)
//	{
//		case 0:
//			DBRead_FEvent(DLT634_5101Slave_Pad[pdrv].Port,pbuf);
//			break;
//		default:
//			break;
//	}
}

/* -----------------------------------------------------------------------------
** ��������: DLT634_5101_SLAVE_R_YXDATA
** ��������: ��YXDATA
** �䡡  ��: pdrv���豸���
**         : addr���׵�ַ
**         : num������
**         : pbuf������ָ��
** �䡡  ��: ��
** ȫ�ֱ���: 
** ����ģ��: DBRead_YX  ��ң��
** ����  ��: Mr.J
** �ա�  ��: 2017.8.3
** -----------------------------------------------------------------------------
** �� �� ��: 
** �޸�����:
** �ա�  ��: 
** ---------------------------------------------------------------------------*/
//LENTH/Lock_ID/TypeID/VSQ/COT_L/COT_H/PubAddr_L/PubAddr_H/InfoAddr_L/InfoAddr_H/Array(Value)
void DLT634_5101_SLAVE_R_YXDATA(uint8_t pdrv,uint16_t addr,uint16_t num, uint8_t *pbuf)//��YXDATA
{ 
	switch(pdrv)
	{
		case 0:
			DBRead_YX(addr,num,pbuf);
			break;
		default:
			break;
	}
}

/* -----------------------------------------------------------------------------
** ��������: DLT634_5101_SLAVE_R_YCDATA
** ��������: ��YCDATA
** �䡡  ��: pdrv���豸���
**         : addr���׵�ַ
**         : num������
**         : pbuf������ָ��
** �䡡  ��: ��
** ȫ�ֱ���: 
** ����ģ��: DBRead_YC  ��ң��
** ����  ��: Mr.J
** �ա�  ��: 2017.8.3
** -----------------------------------------------------------------------------
** �� �� ��: 
** �޸�����:
** �ա�  ��: 
** ---------------------------------------------------------------------------*/
//LENTH/Lock_ID/TypeID/VSQ/COT_L/COT_H/PubAddr_L/PubAddr_H/InfoAddr_L/InfoAddr_H/Array(Value)
void DLT634_5101_SLAVE_R_YCDATA(uint8_t pdrv,uint16_t addr,uint16_t num, uint8_t *pbuf)//��YCDATA
{ 
	switch(pdrv)
	{
		case 0:
			DBRead_YC(addr,num,pbuf);
			break;
		default:
			break;
	}
}

/* -----------------------------------------------------------------------------
** ��������: DLT634_5101_SLAVE_C_REPLY
** ��������: �����豸�ظ�
** �䡡  ��: drvid��Ӧ���豸���
**         : pbuf���ظ���������ָ��
** �䡡  ��: ��
** ȫ�ֱ���: 
** ����ģ��: DBSend  ���͸������豸����
** ����  ��: Mr.J
** �ա�  ��: 2017.8.3
** -----------------------------------------------------------------------------
** �� �� ��: 
** �޸�����:
** �ա�  ��: 
** ---------------------------------------------------------------------------*/
uint8_t DLT634_5101_SLAVE_C_REPLY(uint8_t drvid,uint8_t *pbuf)//�����豸�ظ�
{ 
	uint8_t res;
	switch(drvid)
	{
        case UART_ID:
			res = DLT634_5101_SLAVE_REPLY(DLT634_5101SLAVE_DISK0, pbuf); 
			break;
		default:
			break;
	}
	return(res);
}

/* -----------------------------------------------------------------------------
** ��������: DLT634_5101_SLAVE_INIT
** ��������: ���ò�����ʼ��
** �䡡  ��: ��
** �䡡  ��: ��
** ȫ�ֱ���: 
** ����ģ��: 
** ����  ��: Mr.J
** �ա�  ��: 2017.8.3
** -----------------------------------------------------------------------------
** �� �� ��: 
** �޸�����:
** �ա�  ��: 
** ---------------------------------------------------------------------------*/
void DLT634_5101_SLAVE_INIT(uint8_t pdrv)
{
	switch(pdrv)
	{
		case 0:
            DLT634_5101Slave_Pad[pdrv].Port = UART_ID;
            DLT634_5101Slave_Pad[pdrv].BalanMode = 1;
            DLT634_5101Slave_Pad[pdrv].IEC_DIR = 0x80;
            DLT634_5101Slave_Pad[pdrv].SourceAddr = 0x01;
            DLT634_5101Slave_Pad[pdrv].LinkAddrSize = 2;//1:97,2:02
            DLT634_5101Slave_Pad[pdrv].ASDUCotSize = 2;//1:97,2:02
            DLT634_5101Slave_Pad[pdrv].ASDUAddr = 0x01;
            DLT634_5101Slave_Pad[pdrv].ASDUAddrSize = 2;//1:97,2:02
            DLT634_5101Slave_Pad[pdrv].FixFrmLength = 6;//5:97,6:02
            DLT634_5101Slave_Pad[pdrv].ClockTimers = 2;
            DLT634_5101Slave_Pad[pdrv].TimeOutValue = 10;
            DLT634_5101Slave_Pad[pdrv].YX_AllNum = 10;
            DLT634_5101Slave_Pad[pdrv].YX_FIRSTADDR = 0x0001;
            DLT634_5101Slave_Pad[pdrv].YX_FrameNum = 24;
            DLT634_5101Slave_Pad[pdrv].YC_AllNum = 18;
            DLT634_5101Slave_Pad[pdrv].YC_FIRSTADDR = 0x4001;
            DLT634_5101Slave_Pad[pdrv].YC_FrameNum = 24;
            DLT634_5101Slave_Pad[pdrv].AskStaOutValue = 100;//��·����������
			break;
		default:
			break;
	}
}

/* -----------------------------------------------------------------------------
** ��������: DLT634_5101_SlaveTask
** ��������: 101��վ������
** �䡡  ��: ��
** �䡡  ��: ��
** ȫ�ֱ���: 
** ����ģ��: DLT634_5101_SLAVE_Clock  ��ʱִ�к���
** ����  ��: Mr.J
** �ա�  ��: 2017.8.3
** -----------------------------------------------------------------------------
** �� �� ��: 
** �޸�����:
** �ա�  ��: 
** ---------------------------------------------------------------------------*/
void DLT634_5101_SlaveTask()
{
	DLT634_5101_SLAVE_INIT(DLT634_5101SLAVE_DISK0);		
}

//#endif	/* END DLT634_5101_SLAVE_CFG */ 

/* END OF FILE ---------------------------------------------------------------*/

