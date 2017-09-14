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
** File name:               DLT634_5101_master_disk.c
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

#include <sys/time.h>
#include <signal.h>
#include "dlt634_5101master_disk.h"
#include "dlt634_5101master_app.h"
#include "data_cache.h"

/* PRIVATE VARIABLES ----------------------------------------------------------*/
/* PUBLIC VARIABLES ----------------------------------------------------------*/
static int s_serialfd;

/* PRIVATE FUNCTION PROTOTYPES -----------------------------------------------*/

/* PUBLIC FUNCTION PROTOTYPES -----------------------------------------------*/
int getSerialFd()
{
    return s_serialfd;
}

void setSerialFd(int serialfd)
{
    s_serialfd = serialfd;
}

/* -----------------------------------------------------------------------------
** ��������: DLT634_5101_MASTER_ReadData
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
uint16_t DLT634_5101_MASTER_ReadData(uint8_t pdrv, uint8_t *pbuf, uint16_t count)
{ 
	uint16_t len = 0;  
	
	switch(pdrv)
	{
		case 0:
			len = Readx(pbuf, count, DLT634_5101Master_Pad[pdrv].Port);
			break;
		default:
			break;
	}
	return(len);
}

/* -----------------------------------------------------------------------------
** ��������: DLT634_5101_MASTER_WriteData
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
uint16_t DLT634_5101_MASTER_WriteData(uint8_t pdrv, uint8_t *pbuf, uint16_t count)
{ 
	uint16_t len = 0; 
	
	switch(pdrv)
	{
		case 0:
			len = WriteX(pbuf,count,DLT634_5101Master_Pad[pdrv].Port);
			break;
		default:
			break;
	}
	return(len);
}

//app
/* -----------------------------------------------------------------------------
** ��������: DLT634_5101_MASTER_C_SC
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
void DLT634_5101_MASTER_C_SC(uint8_t pdrv, uint8_t *pbuf)//ң��
{ 
//	switch(pdrv)
//	{
//		case 0:
//			pbuf[1] = (DLT634_5101Master_Pad[pdrv].Port<<4)|(pbuf[1]>>4);
//			DBSend(pbuf);
//			break;
//		default:
//			break;
//	}
}

/* -----------------------------------------------------------------------------
** ��������: DLT634_5101_MASTER_C_CS
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
void DLT634_5101_MASTER_C_CS(uint8_t pdrv, uint8_t *pbuf)//��ʱ
{ 
//	switch(pdrv)
//	{
//		case 0:
//			pbuf[1] = (DLT634_5101Master_Pad[pdrv].Port<<4)|(pbuf[1]>>4);
//			DBSend(pbuf);
//			break;
//		default:
//			break;
//	}
}

/* -----------------------------------------------------------------------------
** ��������: DLT634_5101_MASTER_C_SR
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
void DLT634_5101_MASTER_C_SR(uint8_t pdrv, uint8_t *pbuf)//��ֵ����
{ 
//	switch(pdrv)
//	{
//		case 0:
//			pbuf[1] = (DLT634_5101Master_Pad[pdrv].Port<<4)|(pbuf[1]>>4);
//			DBSend(pbuf);
//			break;
//		default:
//			break;
//	}
}

/* -----------------------------------------------------------------------------
** ��������: DLT634_5101_MASTER_W_YXDATA
** ��������: дYXDATA
** �䡡  ��: pdrv���豸���
**         : pbuf������ָ��
** �䡡  ��: ��
** ȫ�ֱ���: 
** ����ģ��: DBWrite_YX  дYXDATA
** ����  ��: Mr.J
** �ա�  ��: 2017.8.3
** -----------------------------------------------------------------------------
** �� �� ��: 
** �޸�����:
** �ա�  ��: 
** ---------------------------------------------------------------------------*/
//LENTH/Lock_ID/TypeID/VSQ/COT_L/COT_H/PubAddr_L/PubAddr_H/InfoAddr_L/InfoAddr_H/Array(Value)
void DLT634_5101_MASTER_W_YXDATA(uint8_t pdrv, uint8_t *pbuf)//дYXDATA
{ 
    switch(pdrv)
    {
        case 0:
            pbuf[1] = (DLT634_5101Master_Pad[pdrv].Port<<4)|NULL_ID;//TRANSIT_DEV0;
            DBWrite_YX(pbuf);
            break;
        default:
            break;
    }
}

/* -----------------------------------------------------------------------------
** ��������: DLT634_5101_MASTER_W_YCDATA
** ��������: дYCDATA
** �䡡  ��: pdrv���豸���
**         : pbuf������ָ��
** �䡡  ��: ��
** ȫ�ֱ���: 
** ����ģ��: DBWrite_YC  дYCDATA
**         : DBWrite_NVA  дNVA
** ����  ��: Mr.J
** �ա�  ��: 2017.8.3
** -----------------------------------------------------------------------------
** �� �� ��: 
** �޸�����:
** �ա�  ��: 
** ---------------------------------------------------------------------------*/
//LENTH/Lock_ID/TypeID/VSQ/COT_L/COT_H/PubAddr_L/PubAddr_H/InfoAddr_L/InfoAddr_H/Array(Value)
void DLT634_5101_MASTER_W_YCDATA(uint8_t pdrv, uint8_t *pbuf)//дYCDATA
{ 
    switch(pdrv)
    {
        case 0:
            pbuf[1] = (DLT634_5101Master_Pad[pdrv].Port<<4)|NULL_ID;
            if(pbuf[3]&0x80)//SQ==0Ϊ�仯ң��
            {DBWrite_YC(pbuf);}
            else
            {DBWrite_NVA(pbuf);}
            break;
        default:
            break;
    }
}

/* -----------------------------------------------------------------------------
** ��������: DLT634_5101_MASTER_W_SOE
** ��������: дsoe
** �䡡  ��: pdrv���豸���
**         : pbuf������ָ��
** �䡡  ��: ��
** ȫ�ֱ���: 
** ����ģ��: DBWrite_SOE  дsoe
** ����  ��: Mr.J
** �ա�  ��: 2017.8.3
** -----------------------------------------------------------------------------
** �� �� ��: 
** �޸�����:
** �ա�  ��: 
** ---------------------------------------------------------------------------*/
//LENTH/Lock_ID/TypeID/VSQ/COT_L/COT_H/PubAddr_L/PubAddr_H/Array(InfoAddr_L/InfoAddr_H/Value/CP56Time2a)
void DLT634_5101_MASTER_W_SOE(uint8_t pdrv, uint8_t *pbuf)//дsoe
{ 
    switch(pdrv)
    {
        case 0:
            pbuf[1] = (DLT634_5101Master_Pad[pdrv].Port<<4)|NULL_ID;
            DBWrite_SOE(pbuf);
            break;
        default:
            break;
    }
}

/* -----------------------------------------------------------------------------
** ��������: DLT634_5101_MASTER_W_FEvent
** ��������: дFEvent
** �䡡  ��: pdrv���豸���
**         : pbuf������ָ��
** �䡡  ��: ��
** ȫ�ֱ���: 
** ����ģ��: DBWrite_FEvent  д�����¼�
** ����  ��: Mr.J
** �ա�  ��: 2017.8.3
** -----------------------------------------------------------------------------
** �� �� ��: 
** �޸�����:
** �ա�  ��: 
** ---------------------------------------------------------------------------*/
//LENTH/Lock_ID/TypeID/VSQ/COT_L/COT_H/PubAddr_L/PubAddr_H/Array
void DLT634_5101_MASTER_W_FEvent(uint8_t pdrv, uint8_t *pbuf)//дFEvent
{
//	switch(pdrv)
//	{
//		case 0:
//			pbuf[1] = (DLT634_5101Master_Pad[pdrv].Port<<4)|TRANSIT_DEV0;
//			DBWrite_FEvent(pbuf);
//			break;
//		default:
//			break;
//	}
}

/* -----------------------------------------------------------------------------
** ��������: DLT634_5101_MASTER_F_FR
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
void DLT634_5101_MASTER_F_FR(uint8_t pdrv, uint8_t *pbuf)//�ļ���д
{ 
//	switch(pdrv)
//	{
//		case 0:
//			pbuf[1] = (DLT634_5101Master_Pad[pdrv].Port<<4)|(pbuf[1]>>4);
//			DBSend(pbuf);
//			break;
//		default:
//			break;
//	}
}

/* -----------------------------------------------------------------------------
** ��������: DLT634_5101_MASTER_F_SR
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
void DLT634_5101_MASTER_F_SR(uint8_t pdrv, uint8_t *pbuf)//�������
{ 
//	switch(pdrv)
//	{
//		case 0:
//			pbuf[1] = (DLT634_5101Master_Pad[pdrv].Port<<4)|(pbuf[1]>>4);
//			DBSend(pbuf);
//			break;
//		default:
//			break;
//	}
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
//LENTH/Lock_ID/TypeID/VSQ/COT_L/COT_H/PubAddr_L/PubAddr_H/
uint8_t DLT634_5101_MASTER_C_REPLY(uint8_t drvid,uint8_t *pbuf)//�����豸�ظ�
{
    uint8_t res;
    switch(drvid)
    {
        case USART1_ID:
            res = DLT634_5101_MASTER_REPLY(DLT634_5101MASTER_DISK0, pbuf);
            if(!res)//���ز��ɹ������ط񶨻ش�
            {
                pbuf[1] = ((pbuf[1]&0x0f)<<4)|((pbuf[1]&0xf0)>>4);
                pbuf[4] = 47;
                DBSend(pbuf);
            }
            break;
        default:
            break;
    }
    return(res);
}

/* -----------------------------------------------------------------------------
** ��������: DLT634_5101_MASTER_INIT
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
void DLT634_5101_MASTER_INIT(uint8_t pdrv)//��ʼ��
{
    switch(pdrv)
	{
        case 0:
            DLT634_5101Master_Pad[pdrv].Port = USART1_ID;
            DLT634_5101Master_Pad[pdrv].IEC_DIR = 0;
            DLT634_5101Master_Pad[pdrv].SourceAddr = 1;
            DLT634_5101Master_Pad[pdrv].LinkAddrSize = 2;//1:97,2:02
            DLT634_5101Master_Pad[pdrv].ASDUCotSize = 2;//1:97,2:02
            DLT634_5101Master_Pad[pdrv].ASDUAddr = 1;
            DLT634_5101Master_Pad[pdrv].ASDUAddrSize = 2;//1:97,2:02
            DLT634_5101Master_Pad[pdrv].FixFrmLength = 6;//5:97,6:02
            DLT634_5101Master_Pad[pdrv].ClockTimers = 1;//�������м������
            DLT634_5101Master_Pad[pdrv].TimeOutValue = 100;//�ط��������
            DLT634_5101Master_Pad[pdrv].AskStaOutValue = 100;//��·����������
            DLT634_5101Master_Pad[pdrv].AllDataOutValue = 1000;//ȫ�����ٻ��������
            DLT634_5101Master_Pad[pdrv].LinkTestValue = 300;//������·�������
            DLT634_5101Master_Pad[pdrv].LinkIdleValue = DLT634_5101Master_Pad[pdrv].LinkTestValue + 100;//��·�����Զ���λʱ�����
            DLT634_5101Master_Pad[pdrv].DevidValue = 200;//�豸ռ�ü������
            break;
        default:
            break;
	}
}

/* -----------------------------------------------------------------------------
** ��������: start
** ��������: 101����
** �䡡  ��: ��
** �䡡  ��: ��
** ȫ�ֱ���:
** ����ģ��: DLT634_5101_MASTER_Clock  ��ʱִ�к���
** ����  ��: Mrs.Ly
** �ա�  ��: 2017.9.12
** -----------------------------------------------------------------------------
** �� �� ��:
** �޸�����:
** �ա�  ��:
** ---------------------------------------------------------------------------*/
void start()
{
    DLT634_5101_MASTER_Clock(DLT634_5101MASTER_DISK0);
}

/* -----------------------------------------------------------------------------
** ��������: DLT634_5101_MasterTask
** ��������: 101��վ������
** �䡡  ��: ��
** �䡡  ��: ��
** ȫ�ֱ���: 
** ����ģ��: DLT634_5101_MASTER_Clock  ��ʱִ�к���
** ����  ��: Mr.J
** �ա�  ��: 2017.8.3
** -----------------------------------------------------------------------------
** �� �� ��: 
** �޸�����:
** �ա�  ��: 
** ---------------------------------------------------------------------------*/
void DLT634_5101_MasterTask()
{
//	OS_ERR  err;
//	uint32_t results = 0;

//	OSFlagCreate((OS_FLAG_GRP *)&DLT101MasterApp_Event, (CPU_CHAR *)"DLT101MasterPad.Event", (OS_FLAGS)0, (OS_ERR *)&err);
	
	DLT634_5101_MASTER_INIT(DLT634_5101MASTER_DISK0);

    signal(SIGALRM,start);
    struct timeval tv_interval;
    tv_interval.tv_sec = 0;
    tv_interval.tv_usec = 10000;
    struct timeval tv_value;
    tv_value.tv_sec = 0;
    tv_value.tv_usec = 10000;
    struct itimerval it;
    it.it_interval = tv_interval;
    it.it_value = tv_value;
    setitimer(ITIMER_REAL, &it ,NULL);

		 
	// ���������ѭ��
//	for (;;)
//	{
//        results = OSFlagPend((OS_FLAG_GRP *)&DLT101MasterApp_Event,
//                             (OS_FLAGS)PRTCLEVENT_MASK,
//                             (OS_TICK)0,
//                             (OS_OPT)OS_OPT_PEND_FLAG_SET_ANY + OS_OPT_PEND_FLAG_CONSUME,
//                             (CPU_TS *)0,
//                             (OS_ERR *)&err);

//        // ��ʱ��������100MS��
//        if (results & TIME100MS)
//        {
//            DLT634_5101_MASTER_Clock(DLT634_5101MASTER_DISK0);
//        }
				
//    }
}

/* END OF FILE ---------------------------------------------------------------*/

