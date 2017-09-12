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
** File name:               DLT634_5101_app.c
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


/* INCLUDE FILES -------------------------------------------------------------*/
#include "dlt634_5101master_app.h"
#include "dlt634_5101master_disk.h"

/* PRIVATE VARIABLES ----------------------------------------------------------*/
#pragma pack(push,1)
typedef struct 
{
    uint8_t Milliseconds_L;   // D7-D0
    uint8_t Milliseconds_H;   // D7-D0
    uint8_t Minutes;					// D5-D0
    uint8_t Hours;						// D4-D0
    uint8_t DayofWeekMonth;		// WEEK(D7-D5)MONTH(D4-D0)
    uint8_t Months;						// D3-D0
    uint8_t Years;						// D6-D0
}_DLT634_5101MASTER_CP56Time2a_t;

typedef struct 
{
    struct STATUS
    {
        uint8_t Length;
        union
        {
            uint8_t priority;	
            uint8_t Lock_ID;
        }symbol;
    }status;

    struct HEAD
    {
        uint8_t TypeID;     
        uint8_t VSQ;  
        uint8_t COT_L;
        uint8_t COT_H;
        uint8_t PubAddr_L;
        uint8_t PubAddr_H;
    }Head;

    union
    {
        uint8_t	buff[256-sizeof(struct STATUS)-sizeof(struct HEAD)];
        
        struct
        {
            uint8_t InfoAddr_L;
            uint8_t InfoAddr_H;
            uint8_t QOI; 
        }C_100;

        struct
        {
            uint8_t InfoAddr_L;
            uint8_t InfoAddr_H;	
            _DLT634_5101MASTER_CP56Time2a_t CP56Time2a;
        }C_103;

        struct
        {
            uint8_t InfoAddr_L;
            uint8_t InfoAddr_H;	
            uint8_t QRP; 
        }C_105;

        struct
        {
            uint8_t InfoAddr_L;
            uint8_t InfoAddr_H;	
            uint8_t COI; 
        }C_70;

        struct
        {
            uint8_t InfoAddr_L;
            uint8_t InfoAddr_H;
            uint8_t FBP_L;
            uint8_t FBP_H;				
        }C_104;

        union
        {
            struct
            {
                struct
                {
                    uint8_t InfoAddr_L;
                    uint8_t InfoAddr_H;	
                    uint8_t Value; 
                }Array[(256-sizeof(struct STATUS)-sizeof(struct HEAD))/3];
            }SQ0;

            struct
            {
                uint8_t InfoAddr_L;
                uint8_t InfoAddr_H;
                struct
                {
                    uint8_t Value; 
                }Array[(256-sizeof(struct STATUS)-sizeof(struct HEAD)-2)/1];
            }SQ1;
        }C_1;

        union
        {
            struct
            {
                struct
                {
                    uint8_t InfoAddr_L;
                    uint8_t InfoAddr_H;	
                    uint8_t Value; 
                }Array[(256-sizeof(struct STATUS)-sizeof(struct HEAD))/3];
            }SQ0;

            struct
            {
                uint8_t InfoAddr_L;
                uint8_t InfoAddr_H;	
                struct
                {
                    uint8_t Value; 
                }Array[(256-sizeof(struct STATUS)-sizeof(struct HEAD)-2)/1];
            }SQ1;
        }C_3;

        union
        {
            struct
            {
                struct
                {
                    uint8_t InfoAddr_L;
                    uint8_t InfoAddr_H;
                    uint8_t Value; 
                    _DLT634_5101MASTER_CP56Time2a_t CP56Time2a;
                }Array[(256-sizeof(struct STATUS)-sizeof(struct HEAD))/10];
            }SQ0;

            struct
            {
                uint8_t InfoAddr_L;
                uint8_t InfoAddr_H;	
                struct
                {
                    uint8_t Value; 
                    _DLT634_5101MASTER_CP56Time2a_t CP56Time2a;
                }Array[(256-sizeof(struct STATUS)-sizeof(struct HEAD)-2)/8];
            }SQ1;
        }C_30;

        union
        {
            struct
            {
                struct
                {
                    uint8_t InfoAddr_L;
                    uint8_t InfoAddr_H;	
                    uint8_t Value; 
                    _DLT634_5101MASTER_CP56Time2a_t CP56Time2a;
                }Array[(256-sizeof(struct STATUS)-sizeof(struct HEAD))/10];
            }SQ0;

            struct
            {
                uint8_t InfoAddr_L;
                uint8_t InfoAddr_H;	
                struct
                {
                    uint8_t Value; 
                    _DLT634_5101MASTER_CP56Time2a_t CP56Time2a;
                }Array[(256-sizeof(struct STATUS)-sizeof(struct HEAD)-2)/8];
            }SQ1;
        }C_31;

        union
        {
            struct
            {
                struct
                {
                    uint8_t InfoAddr_L;
                    uint8_t InfoAddr_H;
                    uint32_t Value;
                    uint8_t QDS;
                }Array[(256-sizeof(struct STATUS)-sizeof(struct HEAD))/7];
            }SQ0;

            struct
            {
                uint8_t InfoAddr_L;
                uint8_t InfoAddr_H;	
                struct
                {
                    uint32_t Value;									
                    uint8_t QDS;
                }Array[(256-sizeof(struct STATUS)-sizeof(struct HEAD)-2)/5];
            }SQ1;
        }C_9;

        union
        {
            struct
            {
                struct
                {
                    uint8_t InfoAddr_L;
                    uint8_t InfoAddr_H;
                    uint32_t Value;
                    uint8_t QDS;
                }Array[(256-sizeof(struct STATUS)-sizeof(struct HEAD))/7];
            }SQ0;

            struct
            {
                uint8_t InfoAddr_L;
                uint8_t InfoAddr_H;
                struct
                {
                    uint32_t Value_L;
                    uint8_t QDS;
                }Array[(256-sizeof(struct STATUS)-sizeof(struct HEAD)-2)/5];
            }SQ1;
        }C_11;

        union
        {
            struct
            {
                struct
                {
                    uint8_t InfoAddr_L;
                    uint8_t InfoAddr_H;
                    uint32_t Value;	
                    uint8_t QDS;
                }Array[(256-sizeof(struct STATUS)-sizeof(struct HEAD))/7];
            }SQ0;

            struct
            {
                uint8_t InfoAddr_L;
                uint8_t InfoAddr_H;
                struct
                {
                    uint32_t Value;	
                    uint8_t QDS;
                }Array[(256-sizeof(struct STATUS)-sizeof(struct HEAD)-2)/5];
            }SQ1;
        }C_13;

        struct
        {
            uint8_t InfoAddr_L;
            uint8_t InfoAddr_H;
            uint8_t SCO_L;
            uint8_t SCO_H;
        }C_45;	

        struct
        {
            uint8_t InfoAddr_L;
            uint8_t InfoAddr_H;	
            uint8_t DCO_L;
            uint8_t DCO_H;
        }C_46;	

        struct
        {
            uint8_t Array[(256-sizeof(struct STATUS)-sizeof(struct HEAD))]; 
        }C_42;

        struct
        {
            uint8_t InfoAddr_L;
            uint8_t InfoAddr_H;	
            uint8_t SN_L;
            uint8_t SN_H;
        }C_200;

        union
        {
            struct
            {
                uint8_t InfoAddr_L;
                uint8_t InfoAddr_H;
            }Down;

            struct
            {
                uint8_t InfoAddr_L;
                uint8_t InfoAddr_H;	
                uint8_t SN1_L;
                uint8_t SN1_H;
                uint8_t SN2_L;
                uint8_t SN2_H;
                uint8_t SN3_L;
                uint8_t SN3_H;
            }Up;
        }C_201;

        union
        {
            struct
            {
                uint8_t SN1_L;
                uint8_t SN1_H;
                uint32_t Array[(256-sizeof(struct STATUS)-sizeof(struct HEAD)-2)/4];		
            }Down;

            struct
            {
                uint8_t SN_L;
                uint8_t SN_H;	
                uint8_t PI_L;
                uint8_t PI_H;
                struct
                {
                    uint8_t InfoAddr_L;
                    uint8_t InfoAddr_H;
                    uint8_t Tag;
                    uint8_t Len;
                    uint32_t Value;	
                }Array[(256-sizeof(struct STATUS)-sizeof(struct HEAD)-4)/8];
            }Up;
        }C_202;

        union
        {
            uint8_t SN_L;
            uint8_t SN_H;	
            uint8_t PI_L;
            uint8_t PI_H;
            struct
            {
                uint8_t InfoAddr_L;
                uint8_t InfoAddr_H;
                uint8_t Tag;
                uint8_t Len;
                uint32_t Value;	
            }Array[(256-sizeof(struct STATUS)-sizeof(struct HEAD)-4)/8];
        }C_203;

        struct
        {
            uint8_t Array[(256-sizeof(struct STATUS)-sizeof(struct HEAD)-4)/1];
        }C_210;
    }Data;
}DLT634_5101MASTER_PASDU;

typedef struct 
{
//link	
    enum
	{
        RXDSTART = 0,	          // Ѱ����ʼ��־״̬
        RXDHEAD,	              // Ѱ�ұ���ͷ
        RXDCONTINUE             // ���պ�������
	}RxdStatus;           			// ����״̬
	
	uint16_t TxdHead;	      				// ���ͻ�����ͷָ��
	uint16_t TxdTail;	     					// ���ͻ�����βָ��
	uint8_t TxdBuf[_DLT634_5101MASTER_LPDUSIZE];     	// ���ͻ�����
	
	uint16_t RxdHead;	      				// ����������ͷָ��
    uint16_t RxdTail;       				// ����������βָ��
	uint16_t RxdLength;     				// ����һ֡���ݳ���
	uint8_t RxdBuf[_DLT634_5101MASTER_LPDUSIZE];			// ���ջ�����
	
	uint16_t TxdTail_Pri;
	uint8_t TxdBuf_Pri[_DLT634_5101MASTER_LPDUSIZE]; // ���ͻ��������ݴ淢�͵����ݣ��ط�ʱ��
	
//app
	uint8_t Devid;	  								//�����豸id
	uint32_t TimeOutTick_Devid; 			//�豸ռ�ü�ʱ��
	
	DLT634_5101MASTER_PASDU *StoreDATA1IN;              //�����ͻ�����1��������ָ��
	DLT634_5101MASTER_PASDU *StoreDATA1OUT;             //�����ͻ�����1�����ݳ�ָ��
	DLT634_5101MASTER_PASDU StoreDATA1Buf[_DLT634_5101MASTER_STOREDATA1NUM];     	// 1�����ݴ����ͻ�����
	DLT634_5101MASTER_PASDU ST_Temp;              //�洢���ݴ���
	
	DLT634_5101MASTER_PASDU TX_Temp;              //�������ݴ���
	DLT634_5101MASTER_PASDU RX_Temp;              //�������ݴ���
	
	uint32_t LinkFlag;              //�ظ���·���ݱ�־
	uint32_t Data1Flag;             //Ӧ�����ݱ�־
	
	uint32_t ClockCounter;  				//�����������ڿ���
	uint32_t TimeOutTick_Pri; 			//��ʱ���ļ�ʱ��
	uint32_t RetryCount;						//��ʱ������
	
	uint32_t TimeOutTick_AskSta; 			//�ٻ���·���ļ�ʱ��
	uint32_t TimeOutTick_AllData; 			//ȫ���ݽ��ļ�ʱ��
	uint32_t TimeOutTick_LinkTest; 			//����֡���ļ�ʱ��
	uint32_t TimeOutTick_LinkIdle; 			//��·���м�ʱ��
	
	uint8_t SendConCode;	  // ���͵Ŀ�����FCBλ��¼

}DLT634_5101MASTER_APPINFO;
#pragma pack(pop)
/* PUBLIC VARIABLES ----------------------------------------------------------*/
DLT634_5101MASTER_PAD      DLT634_5101Master_Pad[_DLT634_5101MASTER_VOLUMES];
DLT634_5101MASTER_APPINFO  DLT634_5101Master_App[_DLT634_5101MASTER_VOLUMES];

/* PRIVATE FUNCTION PROTOTYPES -----------------------------------------------*/


/* PUBLIC FUNCTION PROTOTYPES -----------------------------------------------*/
/* -----------------------------------------------------------------------------
** ��������: DLT634_5101_MASTER_CKS
** ��������: ����CKS
** �䡡  ��: pdrv���豸���
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
static uint8_t DLT634_5101_MASTER_CKS(uint8_t pdrv ,uint8_t *pBuf)
{
    uint16_t sum = 0;
    uint16_t j =0;
    uint8_t *p = 0;
    uint8_t i = 0;

    if (*(pBuf) == _DLT634_5101MASTER_STARTCODE10)
    {
        for (j = 0; j < (DLT634_5101Master_Pad[pdrv].LinkAddrSize + 1); j++)
        {
            sum += *(pBuf + 1 + j);
        }
    }
    else if(*(pBuf) == _DLT634_5101MASTER_STARTCODE68)
    {
        p = pBuf+4;
        i = *(pBuf+1);

        while (i--)
        {
            sum += (*p++);
        }
    }

    return (uint8_t)(sum&0xff);
}

/* -----------------------------------------------------------------------------
** ��������: DLT634_5101_MASTER_CheckFram68Valid
** ��������: �ɱ�֡���ļ��
** �䡡  ��: pdrv���豸���
** �䡡  ��: ��
** ȫ�ֱ���: DLT634_5101Master_App[pdrv]�����в����ṹ��
**         : DLT634_5101Master_Pad[pdrv]���趨�����ṹ��
** ����ģ��: DLT634_5101_MASTER_CKS ����CKS
** ����  ��: Mr.J
** �ա�  ��: 2017.8.3
** -----------------------------------------------------------------------------
** �� �� ��: 
** �޸�����:
** �ա�  ��: 
** ---------------------------------------------------------------------------*/
static uint8_t DLT634_5101_MASTER_CheckFram68Valid(uint8_t pdrv)
{
    uint8_t *pBuf = 0;
    
    pBuf = (DLT634_5101Master_App[pdrv].RxdBuf + DLT634_5101Master_App[pdrv].RxdHead);

	  // ��ͷУ��
    if ((pBuf[0] != pBuf[3]) || (pBuf[1] != pBuf[2]))
    {
        return(0);
    }

	  // ������ַУ��
    if (DLT634_5101Master_Pad[pdrv].LinkAddrSize == 1)
    {
        if ((pBuf[5] != DLT634_5101Master_Pad[pdrv].SourceAddr) && (pBuf[5] != 0xff))
        {
            return(0);
        }
    }
    else
    {
        if (((pBuf[5]|(pBuf[6]<<8)) != DLT634_5101Master_Pad[pdrv].SourceAddr) && ((pBuf[5]|(pBuf[6]<<8)) != 0xffff))
        {
            return (0);
        }
    }
    
    return (1);
}

/* -----------------------------------------------------------------------------
** ��������: DLT634_5101_MASTER_CheckFram10Valid
** ��������: �̶�֡���ļ��
** �䡡  ��: pdrv���豸���
** �䡡  ��: ��
** ȫ�ֱ���: DLT634_5101Master_App[pdrv]�����в����ṹ��
**         : DLT634_5101Master_Pad[pdrv]���趨�����ṹ��
** ����ģ��: DLT634_5101_MASTER_CKS ����CKS
** ����  ��: Mr.J
** �ա�  ��: 2017.8.3
** -----------------------------------------------------------------------------
** �� �� ��: 
** �޸�����:
** �ա�  ��: 
** ---------------------------------------------------------------------------*/
static uint8_t DLT634_5101_MASTER_CheckFram10Valid(uint8_t pdrv)
{
    uint8_t *pBuf = 0;
    uint16_t addr = 0;

    pBuf = &DLT634_5101Master_App[pdrv].RxdBuf[DLT634_5101Master_App[pdrv].RxdHead];

	  // �̶�֡�����ݵ�У��ͼ��
    if (pBuf[2+DLT634_5101Master_Pad[pdrv].LinkAddrSize] != (DLT634_5101_MASTER_CKS(pdrv, pBuf)&0xFF))	
    {
        return (0);
    }

	  // �̶�֡�����ݵĽ���֡���
    if (pBuf[3+DLT634_5101Master_Pad[pdrv].LinkAddrSize] != _DLT634_5101MASTER_ENDCODE)
    {
        return (0);
    }

	  // �̶�֡���ݹ�����ַ���
    if (DLT634_5101Master_Pad[pdrv].LinkAddrSize == 1)
    {
        addr = pBuf[2];
    }
    else
    {
        addr = pBuf[2] | ((pBuf[3]<<8));
    }
		
    if (addr != DLT634_5101Master_Pad[pdrv].SourceAddr)
    {
        return (0);
    }
    
    return (1);
}

/* -----------------------------------------------------------------------------
** ��������: DLT634_5101_MASTER_DecodeFrame10
** ��������: �̶�֡���Ľ���
** �䡡  ��: pdrv���豸���
** �䡡  ��: ��
** ȫ�ֱ���: DLT634_5101Master_App[pdrv]�����в����ṹ��
**         : DLT634_5101Master_Pad[pdrv]���趨�����ṹ��
** ����ģ��: 
** ����  ��: Mr.J
** �ա�  ��: 2017.8.3
** -----------------------------------------------------------------------------
** �� �� ��: 
** �޸�����:
** �ա�  ��: 
** ---------------------------------------------------------------------------*/
static void DLT634_5101_MASTER_DecodeFrame10(uint8_t pdrv)
{
    uint8_t stop = 0;
    uint8_t control = 0;

    control = DLT634_5101Master_App[pdrv].RxdBuf[1];
    DLT634_5101Master_App[pdrv].TimeOutTick_LinkTest = DLT634_5101Master_Pad[pdrv].LinkTestValue;
    if (control & _DLT634_5101MASTER_PRM) // ��վ��Ϊ�Ӷ�վ������վ������
    {
        switch (control & _DLT634_5101MASTER_FUNCODE)
        {
            case _DLT634_5101MASTER_M_FUN9: // �ٻ���·״̬
                DLT634_5101Master_App[pdrv].TimeOutTick_AskSta = DLT634_5101Master_Pad[pdrv].AskStaOutValue;
                DLT634_5101Master_App[pdrv].LinkFlag = 0;
                DLT634_5101Master_App[pdrv].LinkFlag |= _DLT634_5101MASTER_REQSTATUS;
                /* ���Ա��������ʵĹ��̣����콨����· */ 
                while (((DLT634_5101Master_App[pdrv].RxdTail - DLT634_5101Master_App[pdrv].RxdHead) >= DLT634_5101Master_Pad[pdrv].FixFrmLength) && (stop == 0)) // �յ��ٻ���·״̬����ʱ�����������ͬ���
                {
                    if (memcmp(DLT634_5101Master_App[pdrv].RxdBuf, DLT634_5101Master_App[pdrv].RxdBuf + DLT634_5101Master_App[pdrv].RxdHead, DLT634_5101Master_Pad[pdrv].FixFrmLength) == 0)
                    {
                        DLT634_5101Master_App[pdrv].RxdHead += DLT634_5101Master_Pad[pdrv].FixFrmLength;
                    }
                    else
                    {
                        stop = 1;
                    }
                }
                break;

            case _DLT634_5101MASTER_M_FUN0: // ��λ��·
                DLT634_5101Master_App[pdrv].LinkFlag |= _DLT634_5101MASTER_RECONFIRM;
                DLT634_5101Master_App[pdrv].SendConCode = 0x20;
                DLT634_5101Master_App[pdrv].StoreDATA1IN = DLT634_5101Master_App[pdrv].StoreDATA1Buf;
                DLT634_5101Master_App[pdrv].StoreDATA1OUT = DLT634_5101Master_App[pdrv].StoreDATA1Buf;
                memset(DLT634_5101Master_App[pdrv].StoreDATA1Buf,0,sizeof(DLT634_5101Master_App[pdrv].StoreDATA1Buf));
                break;
            default:
                break;
        }
        return;
    }
    else // Prm=0 ƽ��ģʽ��վ��Ϊ����վ���յ���վ�����
    {
        switch (control & _DLT634_5101MASTER_FUNCODE)
        {
            case _DLT634_5101MASTER_S_FUN0:	// ȷ��
                DLT634_5101Master_App[pdrv].LinkFlag |= _DLT634_5101MASTER_SENDABLE;
                DLT634_5101Master_App[pdrv].TimeOutTick_Pri = 0; // ��·�����ݾͿ��Բ��ط�
                break;

            case _DLT634_5101MASTER_S_FUN11: // Ӧ����·
                DLT634_5101Master_App[pdrv].TimeOutTick_Pri = 0; // ��·�����ݾͿ��Բ��ط�
                DLT634_5101Master_App[pdrv].LinkFlag |= _DLT634_5101MASTER_ASKRELINK;
                break;

            default:
                break;
        }
    }
}

/* -----------------------------------------------------------------------------
** ��������: DLT634_5101_MASTER_StoreIN
** ��������: ���ͻ�������ջ
** �䡡  ��: pdrv���豸���
** �䡡  ��: ��
** ȫ�ֱ���: DLT634_5101Master_App[pdrv]�����в����ṹ��
**         : DLT634_5101Master_Pad[pdrv]���趨�����ṹ��
** ����ģ��: 
** ����  ��: Mr.J
** �ա�  ��: 2017.8.3
** -----------------------------------------------------------------------------
** �� �� ��: 
** �޸�����:
** �ա�  ��: 
** ---------------------------------------------------------------------------*/
static uint8_t DLT634_5101_MASTER_StoreIN(uint8_t pdrv,DLT634_5101MASTER_PASDU *buf)
{	
	DLT634_5101MASTER_PASDU *temp;
	
	temp = DLT634_5101Master_App[pdrv].StoreDATA1IN;
	if(++temp >= DLT634_5101Master_App[pdrv].StoreDATA1Buf + _DLT634_5101MASTER_STOREDATA1NUM)
	{
		temp = DLT634_5101Master_App[pdrv].StoreDATA1Buf;
	}
	
	if(temp == DLT634_5101Master_App[pdrv].StoreDATA1OUT)
	{
		return(FALSE);
	}
	
	memcpy(DLT634_5101Master_App[pdrv].StoreDATA1IN,buf,sizeof(DLT634_5101MASTER_PASDU));	

	if(++DLT634_5101Master_App[pdrv].StoreDATA1IN >= DLT634_5101Master_App[pdrv].StoreDATA1Buf + _DLT634_5101MASTER_STOREDATA1NUM)
	{
		DLT634_5101Master_App[pdrv].StoreDATA1IN = DLT634_5101Master_App[pdrv].StoreDATA1Buf;
	}
		
	return(TRUE);
}

/* -----------------------------------------------------------------------------
** ��������: DLT634_5101_MASTER_AppProcess
** ��������: Ӧ�ô�����
** �䡡  ��: pdrv���豸���
** �䡡  ��: ��
** ȫ�ֱ���: DLT634_5101Master_App[pdrv]�����в����ṹ��
**         : DLT634_5101Master_Pad[pdrv]���趨�����ṹ��
** ����ģ��: DLT634_5101_MASTER_C_SC  �������豸����ң��
**         : DLT634_5101_MASTER_C_CS  �������豸���Ͷ�ֵ
**         : DLT634_5101_MASTER_W_YXDATA  дYXDATA
**         : DLT634_5101_MASTER_W_SOE  дSOE
**         : DLT634_5101_MASTER_W_YCDATA  дYCDATA
**         : DLT634_5101_MASTER_W_FEvent  дFEvent
**         : DLT634_5101_MASTER_StoreIN  ���ͻ�������ջ 
**         : DLT634_5101_MASTER_F_FR  �������豸�����ļ�����
**         : DLT634_5101_MASTER_F_SR  �������豸�����������
** ����  ��: Mr.J
** �ա�  ��: 2017.8.3
** -----------------------------------------------------------------------------
** �� �� ��: 
** �޸�����:
** �ա�  ��: 
** ---------------------------------------------------------------------------*/
static void DLT634_5101_MASTER_AppProcess(uint8_t pdrv,uint8_t Control)
{		
    //�����02�汨�ģ����ڿ��ƺʹ���
    memset((uint8_t *)&DLT634_5101Master_App[pdrv].RX_Temp,0,sizeof(DLT634_5101MASTER_PASDU));
    DLT634_5101Master_App[pdrv].RX_Temp.status.Length = DLT634_5101Master_App[pdrv].RxdBuf[1] -1 -DLT634_5101Master_Pad[pdrv].LinkAddrSize;
    memcpy((uint8_t *)&DLT634_5101Master_App[pdrv].RX_Temp.Head.TypeID,&DLT634_5101Master_App[pdrv].RxdBuf[5+DLT634_5101Master_Pad[pdrv].LinkAddrSize],DLT634_5101Master_App[pdrv].RX_Temp.status.Length);
    if(DLT634_5101Master_Pad[pdrv].ASDUCotSize == 1)
    {
        DLT634_5101Master_App[pdrv].RX_Temp.Head.COT_H = 0;
        memcpy((uint8_t *)&DLT634_5101Master_App[pdrv].RX_Temp.Head.PubAddr_L,&DLT634_5101Master_App[pdrv].RxdBuf[5+DLT634_5101Master_Pad[pdrv].LinkAddrSize+2+DLT634_5101Master_Pad[pdrv].ASDUCotSize]
        ,DLT634_5101Master_App[pdrv].RX_Temp.status.Length-2-DLT634_5101Master_Pad[pdrv].ASDUCotSize);	
        DLT634_5101Master_App[pdrv].RX_Temp.status.Length = DLT634_5101Master_App[pdrv].RX_Temp.status.Length - DLT634_5101Master_Pad[pdrv].ASDUCotSize + 2;
    }
    if(DLT634_5101Master_Pad[pdrv].ASDUAddrSize == 1)
    {
        DLT634_5101Master_App[pdrv].RX_Temp.Head.PubAddr_H = 0;
        memcpy((uint8_t *)&DLT634_5101Master_App[pdrv].RX_Temp.Data.buff[0],&DLT634_5101Master_App[pdrv].RxdBuf[5+DLT634_5101Master_Pad[pdrv].LinkAddrSize+2+DLT634_5101Master_Pad[pdrv].ASDUCotSize+DLT634_5101Master_Pad[pdrv].ASDUAddrSize]
        ,DLT634_5101Master_App[pdrv].RX_Temp.status.Length-2-DLT634_5101Master_Pad[pdrv].ASDUCotSize-DLT634_5101Master_Pad[pdrv].ASDUAddrSize);	
        DLT634_5101Master_App[pdrv].RX_Temp.status.Length = DLT634_5101Master_App[pdrv].RX_Temp.status.Length - DLT634_5101Master_Pad[pdrv].ASDUAddrSize + 2;		
    }
    DLT634_5101Master_App[pdrv].RX_Temp.status.Length += sizeof(DLT634_5101Master_App[pdrv].RX_Temp.status);
    
    if (Control & _DLT634_5101MASTER_PRM) // ��վ��Ϊ�Ӷ�վ������վ��·���ġ�
    {
        switch (DLT634_5101Master_App[pdrv].RX_Temp.Head.TypeID)
        {
            //���Ʒ��������Ϣ
            case _DLT634_5101MASTER_C_SC_NA_1: // ����ң������
            case _DLT634_5101MASTER_C_SC_NB_1: // ˫��ң������
                DLT634_5101Master_App[pdrv].RX_Temp.status.symbol.Lock_ID = DLT634_5101Master_App[pdrv].Devid;
                DLT634_5101_MASTER_C_SC(pdrv,(uint8_t *)&DLT634_5101Master_App[pdrv].RX_Temp);
                break;

            //���ӷ����ϵͳ����
            case _DLT634_5101MASTER_M_EI_NA_1:// ��ʼ������
                DLT634_5101Master_App[pdrv].LinkFlag |= _DLT634_5101MASTER_INITEND;
                DLT634_5101Master_App[pdrv].LinkFlag |= _DLT634_5101MASTER_SENDABLE;
                DLT634_5101Master_App[pdrv].Data1Flag |= _DLT634_5101MASTER_CALLALLDATA;
                DLT634_5101Master_App[pdrv].Data1Flag |= _DLT634_5101MASTER_READTIME;
                DLT634_5101Master_App[pdrv].TimeOutTick_Devid = DLT634_5101Master_Pad[pdrv].DevidValue;
                break;
            
            //���Ʒ���������Ϣ
            case _DLT634_5101MASTER_C_SR_NA_1: // �л���ֵ��
            case _DLT634_5101MASTER_C_RR_NA_1: // ����ֵ����
            case _DLT634_5101MASTER_C_RS_NA_1: // �������Ͷ�ֵ����
            case _DLT634_5101MASTER_C_WS_NA_1: // д�����Ͷ�ֵ����
                DLT634_5101Master_App[pdrv].RX_Temp.status.symbol.Lock_ID = DLT634_5101Master_App[pdrv].Devid;
                DLT634_5101_MASTER_C_SR(pdrv, (uint8_t *)&DLT634_5101Master_App[pdrv].RX_Temp);
                break;
        
            case _DLT634_5101MASTER_C_IC_NA_1: // ���ٻ�������ٻ�
                DLT634_5101Master_App[pdrv].TimeOutTick_AllData = DLT634_5101Master_Pad[pdrv].AllDataOutValue;
                break;

            case _DLT634_5101MASTER_C_CI_NA_1: // ������ٻ�������ٻ�
                break;
            
            case _DLT634_5101MASTER_M_SP_NA_1: //������Ϣ
            case _DLT634_5101MASTER_M_DP_NA_1: //˫����Ϣ
                DLT634_5101_MASTER_W_YXDATA(pdrv, (uint8_t *)&DLT634_5101Master_App[pdrv].RX_Temp);
                break;
            
            case _DLT634_5101MASTER_M_SP_TB_1: //��ʱ�굥����Ϣ
            case _DLT634_5101MASTER_M_DP_TB_1: //��ʱ��˫����Ϣ
                DLT634_5101_MASTER_W_SOE(pdrv, (uint8_t *)&DLT634_5101Master_App[pdrv].RX_Temp);
                break;
            
            case _DLT634_5101MASTER_M_ME_NA_1: //����ֵ����һ��ֵ
            case _DLT634_5101MASTER_M_ME_NB_1: //����ֵ����Ȼ�ֵ
            case _DLT634_5101MASTER_M_ME_NC_1: //����ֵ���̸�����
                DLT634_5101_MASTER_W_YCDATA(pdrv, (uint8_t *)&DLT634_5101Master_App[pdrv].RX_Temp);
                break;
            
            case _DLT634_5101MASTER_M_FT_NA_1: //�����¼�
                DLT634_5101_MASTER_W_FEvent(pdrv, (uint8_t *)&DLT634_5101Master_App[pdrv].RX_Temp);
                break;

            case _DLT634_5101MASTER_C_CS_NA_1: // ��ʱ����
                DLT634_5101Master_App[pdrv].RX_Temp.status.symbol.Lock_ID = DLT634_5101Master_App[pdrv].Devid;
                DLT634_5101_MASTER_C_CS(pdrv, (uint8_t *)&DLT634_5101Master_App[pdrv].RX_Temp);
                break;

            case _DLT634_5101MASTER_C_TS_NA_1: // ��������
                if(DLT634_5101Master_App[pdrv].RX_Temp.Head.COT_L == _DLT634_5101MASTER_COT_ACT)
                {
                    DLT634_5101Master_App[pdrv].RX_Temp.Head.COT_L = _DLT634_5101MASTER_COT_ACTCON;
                    DLT634_5101_MASTER_StoreIN(pdrv,&DLT634_5101Master_App[pdrv].RX_Temp);
                }
                break;

            case _DLT634_5101MASTER_C_RP_NA_1: // ��λ��������
                break;

            case _DLT634_5101MASTER_F_FR_NA_1: // �ļ�����
                DLT634_5101Master_App[pdrv].RX_Temp.status.symbol.Lock_ID = DLT634_5101Master_App[pdrv].Devid;
                DLT634_5101_MASTER_F_FR(pdrv, (uint8_t *)&DLT634_5101Master_App[pdrv].RX_Temp);
                break;

            case _DLT634_5101MASTER_F_SR_NA_1: // �������
                DLT634_5101Master_App[pdrv].RX_Temp.status.symbol.Lock_ID = DLT634_5101Master_App[pdrv].Devid;
                DLT634_5101_MASTER_F_SR(pdrv, (uint8_t *)&DLT634_5101Master_App[pdrv].RX_Temp);
                break;			

            default: // ���ͱ�ʶ�д����֧��
                break;
        }
    }
    else  // Prm=0����վ��Ϊ����վ������վ��·����,��ظ�����
    {
    }
}

/* -----------------------------------------------------------------------------
** ��������: DLT634_5101_MASTER_DecodeFrame68
** ��������: �����ɱ�֡�屨��
** �䡡  ��: pdrv���豸���
** �䡡  ��: ��
** ȫ�ֱ���: DLT634_5101Master_App[pdrv]�����в����ṹ��
**           DLT634_5101Master_Pad[pdrv]���趨�����ṹ��
** ����ģ��: DLT634_5101_MASTER_AppProcess  Ӧ�ô�����
** ����  ��: Mr.J
** �ա�  ��: 2017.8.3
** -----------------------------------------------------------------------------
** �� �� ��: 
** �޸�����:
** �ա�  ��: 
** ---------------------------------------------------------------------------*/
static void DLT634_5101_MASTER_DecodeFrame68(uint8_t pdrv)
{
    uint8_t control;
    
    control = DLT634_5101Master_App[pdrv].RxdBuf[4];

    DLT634_5101Master_App[pdrv].TimeOutTick_LinkTest = DLT634_5101Master_Pad[pdrv].LinkTestValue;
    DLT634_5101Master_App[pdrv].LinkFlag |= _DLT634_5101MASTER_RECONFIRM;
    DLT634_5101_MASTER_AppProcess(pdrv,control);
}

/* -----------------------------------------------------------------------------
** ��������: DLT634_5101_MASTER_SearchValidFrame
** ��������: ���ݴ�����
** �䡡  ��: pdrv���豸���
** �䡡  ��: ��
** ȫ�ֱ���: DLT634_5101Master_App[pdrv]�����в����ṹ��
**           DLT634_5101Master_Pad[pdrv]���趨�����ṹ��
** ����ģ��: DLT634_5101_MASTER_CheckFram68Valid  ���ɱ�֡����
**         : DLT634_5101_MASTER_CheckFram10Valid  ���̶�֡����
**         : DLT634_5101_MASTER_DecodeFrame68  �����ɱ��屨��
**         : DLT634_5101_MASTER_DecodeFrame10  �����̶��屨��
** ����  ��: Mr.J
** �ա�  ��: 2017.8.3
** -----------------------------------------------------------------------------
** �� �� ��: 
** �޸�����:
** �ա�  ��: 
** ---------------------------------------------------------------------------*/
static void DLT634_5101_MASTER_SearchValidFrame(uint8_t pdrv)
{
    uint8_t stop = 0;
    uint8_t length = 0;
    
    while ((DLT634_5101Master_App[pdrv].RxdHead < DLT634_5101Master_App[pdrv].RxdTail) && (!stop))
    {
        if (DLT634_5101Master_App[pdrv].RxdStatus == RXDSTART)
        {
            while ((DLT634_5101Master_App[pdrv].RxdBuf[DLT634_5101Master_App[pdrv].RxdHead] != _DLT634_5101MASTER_STARTCODE10)
                    && (DLT634_5101Master_App[pdrv].RxdBuf[DLT634_5101Master_App[pdrv].RxdHead] != _DLT634_5101MASTER_STARTCODE68)
                    && (DLT634_5101Master_App[pdrv].RxdHead < DLT634_5101Master_App[pdrv].RxdTail))
            {
                DLT634_5101Master_App[pdrv].RxdHead++;
            }

            if (DLT634_5101Master_App[pdrv].RxdHead < DLT634_5101Master_App[pdrv].RxdTail) // �ҵ������ַ������������뻺�������롣
            {
                DLT634_5101Master_App[pdrv].RxdStatus = RXDHEAD;
                if (DLT634_5101Master_App[pdrv].RxdHead != 0)
                {
                    memcpy(DLT634_5101Master_App[pdrv].RxdBuf,DLT634_5101Master_App[pdrv].RxdBuf+DLT634_5101Master_App[pdrv].RxdHead,DLT634_5101Master_App[pdrv].RxdTail-DLT634_5101Master_App[pdrv].RxdHead);
                    DLT634_5101Master_App[pdrv].RxdTail -= DLT634_5101Master_App[pdrv].RxdHead;
                    DLT634_5101Master_App[pdrv].RxdHead = 0;
                }
            }
        }
        
        DLT634_5101Master_App[pdrv].RxdLength = DLT634_5101Master_App[pdrv].RxdTail - DLT634_5101Master_App[pdrv].RxdHead;
        if (DLT634_5101Master_App[pdrv].RxdStatus == RXDHEAD) // ���Ĺ�һ֡����
        {
            switch (DLT634_5101Master_App[pdrv].RxdBuf[DLT634_5101Master_App[pdrv].RxdHead])
            {
                case _DLT634_5101MASTER_STARTCODE68:
                    if (DLT634_5101Master_App[pdrv].RxdLength >= 5+DLT634_5101Master_Pad[pdrv].LinkAddrSize) // �����ַ�����·��ַ��6�ֽڡ�
                    {
                        if (!DLT634_5101_MASTER_CheckFram68Valid(pdrv)) // �ж��Ƿ���ͷ
                        {
                            DLT634_5101Master_App[pdrv].RxdHead++;
                            DLT634_5101Master_App[pdrv].RxdStatus = RXDSTART;
                        }
                        else
                        {
                            DLT634_5101Master_App[pdrv].RxdStatus = RXDCONTINUE;
                        }
                    }
                    else
                    {
                        stop = 1;
                    }
                    break;
                    
                case _DLT634_5101MASTER_STARTCODE10:
                    if (DLT634_5101Master_App[pdrv].RxdLength >= 4 + DLT634_5101Master_Pad[pdrv].LinkAddrSize)
                    {
                        if (!DLT634_5101_MASTER_CheckFram10Valid(pdrv))
                        {
                            DLT634_5101Master_App[pdrv].RxdHead++;
                            DLT634_5101Master_App[pdrv].RxdStatus = RXDSTART;
                        }
                        else
                        {
                            DLT634_5101Master_App[pdrv].RxdStatus = RXDCONTINUE;
                        }
                    }
                    else
                    {
                        stop = 1;
                    }
                    break;
            }
        }
        if (DLT634_5101Master_App[pdrv].RxdStatus == RXDCONTINUE)
        {
            switch (DLT634_5101Master_App[pdrv].RxdBuf[DLT634_5101Master_App[pdrv].RxdHead])
            {
            case _DLT634_5101MASTER_STARTCODE68:
                length = DLT634_5101Master_App[pdrv].RxdBuf[DLT634_5101Master_App[pdrv].RxdHead+1];
                if (DLT634_5101Master_App[pdrv].RxdLength >= length+6) // ������ȫ�����д���
                {
                    if ((DLT634_5101Master_App[pdrv].RxdBuf[DLT634_5101Master_App[pdrv].RxdHead+length+4] == (DLT634_5101_MASTER_CKS(pdrv, DLT634_5101Master_App[pdrv].RxdBuf+DLT634_5101Master_App[pdrv].RxdHead)&0xFF))//У����ȷ
                            && (DLT634_5101Master_App[pdrv].RxdBuf[DLT634_5101Master_App[pdrv].RxdHead+length+4+1] == _DLT634_5101MASTER_ENDCODE)) // ��������ȷ
 					          {
                        if ( DLT634_5101Master_App[pdrv].RxdHead > 0 )
                        {
                            memcpy(DLT634_5101Master_App[pdrv].RxdBuf,DLT634_5101Master_App[pdrv].RxdBuf+DLT634_5101Master_App[pdrv].RxdHead,DLT634_5101Master_App[pdrv].RxdTail-DLT634_5101Master_App[pdrv].RxdHead);//�����뻺��������
                            DLT634_5101Master_App[pdrv].RxdTail -= DLT634_5101Master_App[pdrv].RxdHead;
                            DLT634_5101Master_App[pdrv].RxdHead = 0;
                        }
												/* ͷָ����Ƶ����ĺ� */
                        DLT634_5101Master_App[pdrv].RxdHead += (DLT634_5101Master_App[pdrv].RxdBuf[1]+6);
                        DLT634_5101Master_App[pdrv].RxdStatus = RXDSTART;

                        DLT634_5101_MASTER_DecodeFrame68(pdrv);
                    }
                    else
                    {
                        DLT634_5101Master_App[pdrv].RxdHead += 6;
                        DLT634_5101Master_App[pdrv].RxdStatus = RXDSTART;
                    }
                }
                else // ����δ��ȫ�������������ȴ����ݡ�
                {
                    stop = 1;
                }
                break;
                
            case _DLT634_5101MASTER_STARTCODE10:
                if (DLT634_5101Master_App[pdrv].RxdHead > 0)
                {
                    memcpy(DLT634_5101Master_App[pdrv].RxdBuf,DLT634_5101Master_App[pdrv].RxdBuf+DLT634_5101Master_App[pdrv].RxdHead,DLT634_5101Master_App[pdrv].RxdTail-DLT634_5101Master_App[pdrv].RxdHead);
                    DLT634_5101Master_App[pdrv].RxdTail -= DLT634_5101Master_App[pdrv].RxdHead;
                    DLT634_5101Master_App[pdrv].RxdHead = 0;
                }
                DLT634_5101Master_App[pdrv].RxdHead += 4 + DLT634_5101Master_Pad[pdrv].LinkAddrSize;
                DLT634_5101Master_App[pdrv].RxdStatus = RXDSTART;
			
                DLT634_5101_MASTER_DecodeFrame10(pdrv);
                break;
            }
        }
    }
}

/* -----------------------------------------------------------------------------
** ��������: DLT634_5101_MASTER_ReadMISIData
** ��������: ��ȡ����
** �䡡  ��: pdrv���豸���
** �䡡  ��: ��
** ȫ�ֱ���: DLT634_5101Master_App[pdrv]�����в����ṹ��
**           DLT634_5101Master_Pad[pdrv]���趨�����ṹ��
** ����ģ��: DLT634_5101_MASTER_ReadData  ��ȡ����
**         : DLT634_5101_MASTER_SearchValidFrame  ���ݴ�����
** ����  ��: Mr.J
** �ա�  ��: 2017.8.3
** -----------------------------------------------------------------------------
** �� �� ��: 
** �޸�����:
** �ա�  ��: 
** ---------------------------------------------------------------------------*/
static void DLT634_5101_MASTER_ReadMISIData(uint8_t pdrv)
{
    uint16_t count = 0;
    
    if (DLT634_5101Master_App[pdrv].RxdHead < DLT634_5101Master_App[pdrv].RxdTail) // ���ջ�����������δ���������
    {
        if (DLT634_5101Master_App[pdrv].RxdHead != 0)
        {
            memcpy(DLT634_5101Master_App[pdrv].RxdBuf, DLT634_5101Master_App[pdrv].RxdBuf+DLT634_5101Master_App[pdrv].RxdHead, DLT634_5101Master_App[pdrv].RxdTail-DLT634_5101Master_App[pdrv].RxdHead);//��δ����������Ƶ�������ͷ
            DLT634_5101Master_App[pdrv].RxdTail -= DLT634_5101Master_App[pdrv].RxdHead;
            DLT634_5101Master_App[pdrv].RxdHead = 0;
        }
    }
    else
    {
        DLT634_5101Master_App[pdrv].RxdHead = 0;
		    DLT634_5101Master_App[pdrv].RxdTail = 0;
    }
    
    count = DLT634_5101_MASTER_ReadData(pdrv,(uint8_t *)&DLT634_5101Master_App[pdrv].RxdBuf[DLT634_5101Master_App[pdrv].RxdTail], _DLT634_5101MASTER_LPDUSIZE);
    if (count > 0)
    {
        DLT634_5101Master_App[pdrv].RxdTail += count;
        DLT634_5101_MASTER_SearchValidFrame(pdrv);
    }
}

/* -----------------------------------------------------------------------------
** ��������: DLT634_5101_MASTER_WriteDataToMISI
** ��������: ���ͺ���
** �䡡  ��: pdrv���豸���
** �䡡  ��: ��
** ȫ�ֱ���: DLT634_5101Master_App[pdrv]�����в����ṹ��
**           DLT634_5101Master_Pad[pdrv]���趨�����ṹ��
** ����ģ��: DLT634_5101_MASTER_WriteData  ���ͺ���
** ����  ��: Mr.J
** �ա�  ��: 2017.8.3
** -----------------------------------------------------------------------------
** �� �� ��: 
** �޸�����:
** �ա�  ��: 
** ---------------------------------------------------------------------------*/
static uint8_t DLT634_5101_MASTER_WriteDataToMISI(uint8_t pdrv)
{
    uint16_t SendLen = 0;
   
    SendLen = DLT634_5101_MASTER_WriteData(pdrv ,DLT634_5101Master_App[pdrv].TxdBuf + DLT634_5101Master_App[pdrv].TxdHead, DLT634_5101Master_App[pdrv].TxdTail - DLT634_5101Master_App[pdrv].TxdHead);

  	DLT634_5101Master_App[pdrv].TimeOutTick_LinkIdle = DLT634_5101Master_Pad[pdrv].LinkIdleValue;
	
    DLT634_5101Master_App[pdrv].TxdHead += SendLen;
    if (DLT634_5101Master_App[pdrv].TxdHead >= DLT634_5101Master_App[pdrv].TxdTail) // �ô����������Ѿ�����
    {
        DLT634_5101Master_App[pdrv].TxdHead = 0;
        DLT634_5101Master_App[pdrv].TxdTail = 0;
        return (TRUE);
    }
    else
    {
        return (FALSE);
    }
}

/* -----------------------------------------------------------------------------
** ��������: DLT634_5101_MASTER_SlaveFrame10Packet
** ��������: �̶�֡�Ӷ�վ���
** �䡡  ��: pdrv���豸���
**         : Function  ������
** �䡡  ��: ��
** ȫ�ֱ���: DLT634_5101Master_App[pdrv]�����в����ṹ��
**           DLT634_5101Master_Pad[pdrv]���趨�����ṹ��
** ����ģ��: DLT634_5101_MASTER_CKS  ����CKS
** ����  ��: Mr.J
** �ա�  ��: 2017.8.3
** -----------------------------------------------------------------------------
** �� �� ��: 
** �޸�����:
** �ա�  ��: 
** ---------------------------------------------------------------------------*/
static void DLT634_5101_MASTER_SlaveFrame10Packet(uint8_t pdrv, uint8_t Function)
{
    uint8_t *pBuf;
    uint8_t i = 0;
									
    pBuf = DLT634_5101Master_App[pdrv].TxdBuf + DLT634_5101Master_App[pdrv].TxdTail;
    pBuf[0] = _DLT634_5101MASTER_STARTCODE10;
    pBuf[1] = Function&0x0f;
    pBuf[1] |= DLT634_5101Master_Pad[pdrv].IEC_DIR; // ��վ����վ����

    for (i=0; i<DLT634_5101Master_Pad[pdrv].LinkAddrSize; i++)
    {
        pBuf[2+i] = (DLT634_5101Master_Pad[pdrv].SourceAddr>>(8*i)) & 0xff;
    }

    pBuf[2+DLT634_5101Master_Pad[pdrv].LinkAddrSize] = DLT634_5101_MASTER_CKS(pdrv, pBuf);
    pBuf[3+DLT634_5101Master_Pad[pdrv].LinkAddrSize] = _DLT634_5101MASTER_ENDCODE;
    DLT634_5101Master_App[pdrv].TxdTail += DLT634_5101Master_Pad[pdrv].FixFrmLength;//�ƶ�����βָ��
}

/* -----------------------------------------------------------------------------
** ��������: DLT634_5101_MASTER_MasterFrame10Packet
** ��������: �̶�֡����վ���
** �䡡  ��: pdrv���豸���
**         : Function  ������
** �䡡  ��: ��
** ȫ�ֱ���: DLT634_5101Master_App[pdrv]�����в����ṹ��
**           DLT634_5101Master_Pad[pdrv]���趨�����ṹ��
** ����ģ��: DLT634_5101_MASTER_CKS  ����CKS
** ����  ��: Mr.J
** �ա�  ��: 2017.8.3
** -----------------------------------------------------------------------------
** �� �� ��: 
** �޸�����:
** �ա�  ��: 
** ---------------------------------------------------------------------------*/
static void DLT634_5101_MASTER_MasterFrame10Packet(uint8_t pdrv, uint8_t Function)
{
    uint8_t *pBuf;
    uint8_t i = 0;

    pBuf = DLT634_5101Master_App[pdrv].TxdBuf + DLT634_5101Master_App[pdrv].TxdTail;
    pBuf[0] = _DLT634_5101MASTER_STARTCODE10;
    pBuf[1] = Function&0x0f;
    pBuf[1] |= _DLT634_5101MASTER_PRM;
    pBuf[1] |= DLT634_5101Master_Pad[pdrv].IEC_DIR; // ��վ����վ����

    for (i=0; i<DLT634_5101Master_Pad[pdrv].LinkAddrSize; i++)
    {
        pBuf[2+i] = (DLT634_5101Master_Pad[pdrv].SourceAddr>>(8*i)) & 0xff;
    }

    pBuf[2+DLT634_5101Master_Pad[pdrv].LinkAddrSize] = DLT634_5101_MASTER_CKS(pdrv, pBuf);
    pBuf[3+DLT634_5101Master_Pad[pdrv].LinkAddrSize] = _DLT634_5101MASTER_ENDCODE;
    DLT634_5101Master_App[pdrv].TxdTail += DLT634_5101Master_Pad[pdrv].FixFrmLength;//�ƶ�����βָ��

    memcpy(DLT634_5101Master_App[pdrv].TxdBuf_Pri, pBuf, DLT634_5101Master_Pad[pdrv].FixFrmLength); // ���������ݱ��浽����վ�ط�������
    DLT634_5101Master_App[pdrv].TxdTail_Pri = DLT634_5101Master_Pad[pdrv].FixFrmLength;
}

/* -----------------------------------------------------------------------------
** ��������: DLT634_5101_MASTER_Link10Process
** ��������: �̶�֡���ʹ���
** �䡡  ��: pdrv���豸���
** �䡡  ��: ��
** ȫ�ֱ���: DLT634_5101Master_App[pdrv]�����в����ṹ��
**           DLT634_5101Master_Pad[pdrv]���趨�����ṹ��
** ����ģ��: DLT634_5101_MASTER_WriteDataToMISI  ���ͺ���
**           DLT634_5101_MASTER_SlaveFrame10Packet  �̶�֡�Ӷ�վ���
**           DLT634_5101_MASTER_MasterFrame10Packet  �̶�֡����վ���
** ����  ��: Mr.J
** �ա�  ��: 2017.8.3
** -----------------------------------------------------------------------------
** �� �� ��: 
** �޸�����:
** �ա�  ��: 
** ---------------------------------------------------------------------------*/
static void DLT634_5101_MASTER_Link10Process(uint8_t pdrv)
{ 
	if(DLT634_5101Master_App[pdrv].LinkFlag&_DLT634_5101MASTER_REQSTATUS)
	{
		DLT634_5101_MASTER_SlaveFrame10Packet(pdrv, _DLT634_5101MASTER_S_FUN11);
		DLT634_5101_MASTER_WriteDataToMISI(pdrv);
		DLT634_5101Master_App[pdrv].LinkFlag &= (~_DLT634_5101MASTER_REQSTATUS);
		return;
	}
	
	if(DLT634_5101Master_App[pdrv].LinkFlag&_DLT634_5101MASTER_RECONFIRM)
	{
		DLT634_5101_MASTER_SlaveFrame10Packet(pdrv, _DLT634_5101MASTER_S_FUN0);
		DLT634_5101_MASTER_WriteDataToMISI(pdrv);
		DLT634_5101Master_App[pdrv].LinkFlag &= (~_DLT634_5101MASTER_RECONFIRM);
		return;
	}
	
	if((DLT634_5101Master_App[pdrv].LinkFlag&_DLT634_5101MASTER_ASKSTATUS)&&(!(DLT634_5101Master_App[pdrv].LinkFlag&_DLT634_5101MASTER_INITEND)))
	{
		DLT634_5101_MASTER_MasterFrame10Packet(pdrv, _DLT634_5101MASTER_M_FUN9);
		DLT634_5101_MASTER_WriteDataToMISI(pdrv);
		DLT634_5101Master_App[pdrv].LinkFlag &= (~_DLT634_5101MASTER_ASKSTATUS);
		DLT634_5101Master_App[pdrv].TimeOutTick_AskSta = DLT634_5101Master_Pad[pdrv].AskStaOutValue;
		return;
	}
	
	if(DLT634_5101Master_App[pdrv].LinkFlag&_DLT634_5101MASTER_ASKRELINK)
	{
		DLT634_5101_MASTER_MasterFrame10Packet(pdrv, _DLT634_5101MASTER_M_FUN0);
		DLT634_5101_MASTER_WriteDataToMISI(pdrv);
		DLT634_5101Master_App[pdrv].LinkFlag &= (~_DLT634_5101MASTER_ASKRELINK);
		return;
	}	
}

/* -----------------------------------------------------------------------------
** ��������: DLT634_5101_MASTER_ReadAllDataProcess
** ��������: ����
** �䡡  ��: pdrv���豸���
** �䡡  ��: ��
** ȫ�ֱ���: DLT634_5101Slave_App[pdrv]�����в����ṹ��
**           DLT634_5101Slave_Pad[pdrv]���趨�����ṹ��
** ����ģ��: 
** ����  ��: Mr.J
** �ա�  ��: 2017.8.3
** -----------------------------------------------------------------------------
** �� �� ��: 
** �޸�����:
** �ա�  ��: 
** ---------------------------------------------------------------------------*/
static void DLT634_5101_MASTER_ReadAllDataProcess(uint8_t pdrv)
{
    DLT634_5101Master_App[pdrv].TX_Temp.status.Length = sizeof(DLT634_5101Master_App[pdrv].TX_Temp.status) + sizeof(DLT634_5101Master_App[pdrv].TX_Temp.Head) + sizeof(DLT634_5101Master_App[pdrv].TX_Temp.Data.C_100);
    DLT634_5101Master_App[pdrv].TX_Temp.Head.TypeID = _DLT634_5101MASTER_C_IC_NA_1;
    DLT634_5101Master_App[pdrv].TX_Temp.Head.VSQ = 1;
    DLT634_5101Master_App[pdrv].TX_Temp.Head.COT_L = _DLT634_5101MASTER_COT_ACT;
    DLT634_5101Master_App[pdrv].TX_Temp.Head.PubAddr_H = (uint8_t)((DLT634_5101Master_Pad[pdrv].ASDUAddr>>8)&0xff);
    DLT634_5101Master_App[pdrv].TX_Temp.Head.PubAddr_L = (uint8_t)(DLT634_5101Master_Pad[pdrv].ASDUAddr&0xff);
    DLT634_5101Master_App[pdrv].TX_Temp.Data.C_100.QOI = 20;
}

/* -----------------------------------------------------------------------------
** ��������: DLT634_5101_MASTER_LinkTestProcess
** ��������: ��·����
** �䡡  ��: pdrv���豸���
** �䡡  ��: ��
** ȫ�ֱ���: DLT634_5101Slave_App[pdrv]�����в����ṹ��
**           DLT634_5101Slave_Pad[pdrv]���趨�����ṹ��
** ����ģ��: 
** ����  ��: Mr.J
** �ա�  ��: 2017.8.3
** -----------------------------------------------------------------------------
** �� �� ��: 
** �޸�����:
** �ա�  ��: 
** ---------------------------------------------------------------------------*/
static void DLT634_5101_MASTER_LinkTestProcess(uint8_t pdrv)
{
    DLT634_5101Master_App[pdrv].TX_Temp.status.Length = sizeof(DLT634_5101Master_App[pdrv].TX_Temp.status) + sizeof(DLT634_5101Master_App[pdrv].TX_Temp.Head) + sizeof(DLT634_5101Master_App[pdrv].TX_Temp.Data.C_104);
    DLT634_5101Master_App[pdrv].TX_Temp.Head.TypeID = _DLT634_5101MASTER_C_TS_NA_1;
    DLT634_5101Master_App[pdrv].TX_Temp.Head.VSQ = 1;
    DLT634_5101Master_App[pdrv].TX_Temp.Head.COT_L = _DLT634_5101MASTER_COT_ACT;
    DLT634_5101Master_App[pdrv].TX_Temp.Head.PubAddr_H = (uint8_t)((DLT634_5101Master_Pad[pdrv].ASDUAddr>>8)&0xff);
    DLT634_5101Master_App[pdrv].TX_Temp.Head.PubAddr_L = (uint8_t)(DLT634_5101Master_Pad[pdrv].ASDUAddr&0xff);
    DLT634_5101Master_App[pdrv].TX_Temp.Data.C_104.FBP_L = 0x55;
    DLT634_5101Master_App[pdrv].TX_Temp.Data.C_104.FBP_H = 0xaa;
}

/* -----------------------------------------------------------------------------
** ��������: DLT634_5101_MASTER_ReadTime
** ��������: ��ʱ
** �䡡  ��: pdrv���豸���
** �䡡  ��: ��
** ȫ�ֱ���: DLT634_5101Slave_App[pdrv]�����в����ṹ��
**           DLT634_5101Slave_Pad[pdrv]���趨�����ṹ��
** ����ģ��: 
** ����  ��: Mr.J
** �ա�  ��: 2017.8.3
** -----------------------------------------------------------------------------
** �� �� ��: 
** �޸�����:
** �ա�  ��: 
** ---------------------------------------------------------------------------*/
static void DLT634_5101_MASTER_ReadTime(uint8_t pdrv)
{
    DLT634_5101Master_App[pdrv].TX_Temp.status.Length = sizeof(DLT634_5101Master_App[pdrv].TX_Temp.status) + sizeof(DLT634_5101Master_App[pdrv].TX_Temp.Head) + sizeof(DLT634_5101Master_App[pdrv].TX_Temp.Data.C_103);
    DLT634_5101Master_App[pdrv].TX_Temp.Head.TypeID = _DLT634_5101MASTER_C_CS_NA_1;
    DLT634_5101Master_App[pdrv].TX_Temp.Head.VSQ = 1;
    DLT634_5101Master_App[pdrv].TX_Temp.Head.COT_L = _DLT634_5101MASTER_COT_REQ;
    DLT634_5101Master_App[pdrv].TX_Temp.Head.PubAddr_H = (uint8_t)((DLT634_5101Master_Pad[pdrv].ASDUAddr>>8)&0xff);
    DLT634_5101Master_App[pdrv].TX_Temp.Head.PubAddr_L = (uint8_t)(DLT634_5101Master_Pad[pdrv].ASDUAddr&0xff);
    DLT634_5101Master_App[pdrv].Devid = 0;
}

/* -----------------------------------------------------------------------------
** ��������: DLT634_5101_MASTER_Data1Process
** ��������: 1�����ݷ��ʹ�����
** �䡡  ��: pdrv���豸���
** �䡡  ��: ��
** ȫ�ֱ���: DLT634_5101Master_App[pdrv]�����в����ṹ��
**           DLT634_5101Master_Pad[pdrv]���趨�����ṹ��
** ����ģ��: DLT634_5101_MASTER_ReadAllDataProcess  ���ٺ���
**           DLT634_5101_MASTER_ReadTime  ��ʱ
**           DLT634_5101_SLAVE_R_SOE  SOE��ȡ����
**           DLT634_5101_MASTER_LinkTestProcess  ��������
** ����  ��: Mr.J
** �ա�  ��: 2017.8.3
** -----------------------------------------------------------------------------
** �� �� ��: 
** �޸�����:
** �ա�  ��: 
** ---------------------------------------------------------------------------*/
static void DLT634_5101_MASTER_Data1Process(uint8_t pdrv)
{ 
    if(DLT634_5101Master_App[pdrv].StoreDATA1OUT != DLT634_5101Master_App[pdrv].StoreDATA1IN)
    {
        memcpy((uint8_t *)&DLT634_5101Master_App[pdrv].TX_Temp, (uint8_t *)DLT634_5101Master_App[pdrv].StoreDATA1OUT, DLT634_5101Master_App[pdrv].StoreDATA1OUT->status.Length);
        memset((uint8_t *)DLT634_5101Master_App[pdrv].StoreDATA1OUT,0,sizeof(DLT634_5101MASTER_PASDU));
        if(++DLT634_5101Master_App[pdrv].StoreDATA1OUT >= DLT634_5101Master_App[pdrv].StoreDATA1Buf + _DLT634_5101MASTER_STOREDATA1NUM)
        {
            DLT634_5101Master_App[pdrv].StoreDATA1OUT = DLT634_5101Master_App[pdrv].StoreDATA1Buf;
        }
        return;
    }		
		
	  if (DLT634_5101Master_App[pdrv].Data1Flag & _DLT634_5101MASTER_CALLALLDATA) // �ٻ�ȫ����
    {
        DLT634_5101_MASTER_ReadAllDataProcess(pdrv);
				DLT634_5101Master_App[pdrv].Data1Flag &= (~_DLT634_5101MASTER_CALLALLDATA);
        return;
    }
		
		if ((DLT634_5101Master_App[pdrv].Data1Flag & _DLT634_5101MASTER_READTIME)&&(DLT634_5101Master_App[pdrv].TimeOutTick_Devid == 0)) // ��ʱ
    {
        DLT634_5101_MASTER_ReadTime(pdrv);
				DLT634_5101Master_App[pdrv].Data1Flag &= (~_DLT634_5101MASTER_READTIME);
        return;
    }

	  if (DLT634_5101Master_App[pdrv].Data1Flag & _DLT634_5101MASTER_LINKTEST) // ��������
    {
        DLT634_5101_MASTER_LinkTestProcess(pdrv);
				DLT634_5101Master_App[pdrv].Data1Flag &= (~_DLT634_5101MASTER_LINKTEST);
        return;
    }		
}

/* -----------------------------------------------------------------------------
** ��������: DLT634_5101_MASTER_MasterFrame68Packet
** ��������: �ɱ�֡����վ���ݴ��
** �䡡  ��: pdrv���豸���
** �䡡  ��: ��
** ȫ�ֱ���: DLT634_5101Master_App[pdrv]�����в����ṹ��
**           DLT634_5101Master_Pad[pdrv]���趨�����ṹ��
** ����ģ��: DLT634_5101_MASTER_CKS  ����CKS
** ����  ��: Mr.J
** �ա�  ��: 2017.8.3
** -----------------------------------------------------------------------------
** �� �� ��: 
** �޸�����:
** �ա�  ��: 
** ---------------------------------------------------------------------------*/
static void DLT634_5101_MASTER_MasterFrame68Packet(uint8_t pdrv, uint8_t Function)
{
    uint16_t length = 0;
    uint16_t i = 0;
    uint8_t *pBuf;
    uint8_t ptemp[256];
    
    pBuf = DLT634_5101Master_App[pdrv].TxdBuf + DLT634_5101Master_App[pdrv].TxdTail;

    pBuf[0] = pBuf[3] = _DLT634_5101MASTER_STARTCODE68;
    pBuf[1] = pBuf[2] = DLT634_5101Master_App[pdrv].TX_Temp.status.Length - sizeof(DLT634_5101Master_App[pdrv].TX_Temp.status)+ 1 + 2;
    pBuf[4] = Function&0x0f;
    if(DLT634_5101Master_App[pdrv].SendConCode&_DLT634_5101MASTER_FCB)
    {DLT634_5101Master_App[pdrv].SendConCode = 0;}
    else
    {DLT634_5101Master_App[pdrv].SendConCode = _DLT634_5101MASTER_FCB;}
    pBuf[4] |= _DLT634_5101MASTER_FCV;
    pBuf[4] |= DLT634_5101Master_App[pdrv].SendConCode;
    pBuf[4] |= _DLT634_5101MASTER_PRM;

    for (i = 0; i < 2; i++)
    {
        pBuf[5+i] = ((DLT634_5101Master_Pad[pdrv].SourceAddr >> (8*i)) & 0xff);
    }
		
    memcpy(&pBuf[5+2], &DLT634_5101Master_App[pdrv].TX_Temp.Head, DLT634_5101Master_App[pdrv].TX_Temp.status.Length - sizeof(DLT634_5101Master_App[pdrv].TX_Temp.status));
			
    for (i = 0; i < 2; i++)
    {
        pBuf[11+i] = ((DLT634_5101Master_Pad[pdrv].ASDUAddr >> (8*i)) & 0xff);
    }
		
    length = 6 + pBuf[2]; // ȫ�����ĳ���	
    memcpy(&ptemp,pBuf,length);
    if(DLT634_5101Master_Pad[pdrv].LinkAddrSize == 1)
    {
        length--;
        memcpy(&pBuf[6],&ptemp[7],length-3);	
    }
    if(DLT634_5101Master_Pad[pdrv].ASDUCotSize == 1)
    {
        length--;
        memcpy(&pBuf[9],&ptemp[11],length-7);	
    }
    if(DLT634_5101Master_Pad[pdrv].ASDUAddrSize == 1)
    {
        length--;
        memcpy(&pBuf[10],&ptemp[13],length-9);	
    }
    pBuf[length-2] = DLT634_5101_MASTER_CKS(pdrv, pBuf)&0xFF;
    pBuf[length-1] = _DLT634_5101MASTER_ENDCODE;
    DLT634_5101Master_App[pdrv].TxdTail += length;

    memcpy(DLT634_5101Master_App[pdrv].TxdBuf_Pri, pBuf, length);
    DLT634_5101Master_App[pdrv].TxdTail_Pri = length;
}

/* -----------------------------------------------------------------------------
** ��������: DLT634_5101_MASTER_Link68Process
** ��������: �ɱ�֡���ͺ���
** �䡡  ��: pdrv���豸���
** �䡡  ��: ��
** ȫ�ֱ���: DLT634_5101Master_App[pdrv]�����в����ṹ��
**           DLT634_5101Master_Pad[pdrv]���趨�����ṹ��
** ����ģ��: DLT634_5101_MASTER_MasterFrame68Packet  �ɱ�֡����վ���
**           DLT634_5101_MASTER_WriteDataToMISI  ���ݷ��ͺ���
** ����  ��: Mr.J
** �ա�  ��: 2017.8.3
** -----------------------------------------------------------------------------
** �� �� ��: 
** �޸�����:
** �ա�  ��: 
** ---------------------------------------------------------------------------*/
static void DLT634_5101_MASTER_Link68Process(uint8_t pdrv)
{
    if(DLT634_5101Master_App[pdrv].TX_Temp.status.Length)
    {
        DLT634_5101_MASTER_MasterFrame68Packet(pdrv, _DLT634_5101MASTER_M_FUN3);
        DLT634_5101_MASTER_WriteDataToMISI(pdrv);
        DLT634_5101Master_App[pdrv].TimeOutTick_Pri = DLT634_5101Master_Pad[pdrv].TimeOutValue;
        DLT634_5101Master_App[pdrv].RetryCount  = _DLT634_5101MASTER_NUMOF_MAXRETRY;
        DLT634_5101Master_App[pdrv].LinkFlag &= (~_DLT634_5101MASTER_SENDABLE);
        memset((uint8_t *)&DLT634_5101Master_App[pdrv].TX_Temp,0,sizeof(DLT634_5101MASTER_PASDU));
    }
}

/* -----------------------------------------------------------------------------
** ��������: DLT634_5101_MASTER_SendProcess
** ��������: ���ʹ�����
** �䡡  ��: pdrv���豸���
** �䡡  ��: ��
** ȫ�ֱ���: DLT634_5101Master_App[pdrv]�����в����ṹ��
**           DLT634_5101Master_Pad[pdrv]���趨�����ṹ��
** ����ģ��: DLT634_5101_MASTER_Link10Process  �̶�֡�������ݺ���
**           DLT634_5101_MASTER_Data1Process  1�����ݷ������ݺ���
**           DLT634_5101_MASTER_Link68Process  �ɱ�֡���ͺ���
** ����  ��: Mr.J
** �ա�  ��: 2017.8.3
** -----------------------------------------------------------------------------
** �� �� ��: 
** �޸�����:
** �ա�  ��: 
** ---------------------------------------------------------------------------*/
static void DLT634_5101_MASTER_SendProcess(uint8_t pdrv)
{   	
    if(DLT634_5101Master_App[pdrv].LinkFlag&0x000000ff)
    {
        DLT634_5101_MASTER_Link10Process(pdrv);
        return;
    }
    

    if((DLT634_5101Master_App[pdrv].LinkFlag&_DLT634_5101MASTER_SENDABLE)&&(DLT634_5101Master_App[pdrv].LinkFlag&_DLT634_5101MASTER_INITEND))
    {
        DLT634_5101_MASTER_Data1Process(pdrv);
        DLT634_5101_MASTER_Link68Process(pdrv);
        return;
    }
}

/* -----------------------------------------------------------------------------
** ��������: DLT634_5101_MASTER_LinkOnTimer
** ��������: ��·�㶨ʱ��������
** �䡡  ��: pdrv���豸���
** �䡡  ��: ��
** ȫ�ֱ���: DLT634_5101Master_App[pdrv]�����в����ṹ��
**           DLT634_5101Master_Pad[pdrv]���趨�����ṹ��
** ����ģ��: DLT634_5101_MASTER_WriteDataToMISI  �������ݺ���
** ����  ��: Mr.J
** �ա�  ��: 2017.8.3
** -----------------------------------------------------------------------------
** �� �� ��: 
** �޸�����:
** �ա�  ��: 
** ---------------------------------------------------------------------------*/
void DLT634_5101_MASTER_LinkOnTimer(uint8_t pdrv)
{
    if(DLT634_5101Master_App[pdrv].TimeOutTick_Devid)
    {DLT634_5101Master_App[pdrv].TimeOutTick_Devid--;}
		
    if (DLT634_5101Master_App[pdrv].TimeOutTick_Pri) // ��λ����
    {
        DLT634_5101Master_App[pdrv].TimeOutTick_Pri--;
        if (!DLT634_5101Master_App[pdrv].TimeOutTick_Pri)
        {
            if (!DLT634_5101Master_App[pdrv].RetryCount)
            {
                    return;
            }

            DLT634_5101Master_App[pdrv].RetryCount--;
            if (DLT634_5101Master_App[pdrv].RetryCount)
            {
                memcpy(DLT634_5101Master_App[pdrv].TxdBuf + DLT634_5101Master_App[pdrv].TxdTail, DLT634_5101Master_App[pdrv].TxdBuf_Pri, DLT634_5101Master_App[pdrv].TxdTail_Pri);
                DLT634_5101Master_App[pdrv].TxdTail += DLT634_5101Master_App[pdrv].TxdTail_Pri;

                DLT634_5101_MASTER_WriteDataToMISI(pdrv);
                DLT634_5101Master_App[pdrv].TimeOutTick_Pri = DLT634_5101Master_Pad[pdrv].TimeOutValue;
                return;
            }
            else // �����ط����������½�����·����֪ͨӦ�ò㡣
            {
                DLT634_5101Master_App[pdrv].LinkFlag = 0;
            }
        }
    }	

    if (!DLT634_5101Master_App[pdrv].TimeOutTick_LinkIdle)
    {
        DLT634_5101Master_App[pdrv].TimeOutTick_LinkIdle = DLT634_5101Master_Pad[pdrv].LinkIdleValue;
        DLT634_5101Master_App[pdrv].LinkFlag = 0;
    }
    else
    {
        DLT634_5101Master_App[pdrv].TimeOutTick_LinkIdle--;
    }
    
    if(!(DLT634_5101Master_App[pdrv].LinkFlag&_DLT634_5101MASTER_INITEND))
    {
        if (!DLT634_5101Master_App[pdrv].TimeOutTick_AskSta)
        {
            DLT634_5101Master_App[pdrv].LinkFlag |= _DLT634_5101MASTER_ASKSTATUS;
        }
        else
        {
            DLT634_5101Master_App[pdrv].TimeOutTick_AskSta--;
        }
    }
    
    if(DLT634_5101Master_App[pdrv].LinkFlag&_DLT634_5101MASTER_INITEND)
    {
        if (!DLT634_5101Master_App[pdrv].TimeOutTick_AllData)
        {
            DLT634_5101Master_App[pdrv].TimeOutTick_AllData = DLT634_5101Master_Pad[pdrv].AllDataOutValue;
            DLT634_5101Master_App[pdrv].Data1Flag |= _DLT634_5101MASTER_CALLALLDATA;
        }
        else
        {
            DLT634_5101Master_App[pdrv].TimeOutTick_AllData--;
        }
        
        if (!DLT634_5101Master_App[pdrv].TimeOutTick_LinkTest)
        {
            DLT634_5101Master_App[pdrv].TimeOutTick_LinkTest = DLT634_5101Master_Pad[pdrv].LinkTestValue;
            DLT634_5101Master_App[pdrv].Data1Flag |= _DLT634_5101MASTER_LINKTEST;
        }
        else
        {
            DLT634_5101Master_App[pdrv].TimeOutTick_LinkTest--;
        }
    }
}

/* PUBLIC FUNCTION PROTOTYPES -----------------------------------------------*/
/* -----------------------------------------------------------------------------
** ��������: DLT634_5101_MASTER_REPLY
** ��������: �����豸Ӧ����
** �䡡  ��: pdrv���豸���
** �䡡  ��: ��
** ȫ�ֱ���: DLT634_5101Master_App[pdrv]�����в����ṹ��
**         : DLT634_5101Master_Pad[pdrv]���趨�����ṹ��
** ����ģ��: DLT634_5101_MASTER_StoreIN  ���ͻ�������ջ
** ����  ��: Mr.J
** �ա�  ��: 2017.8.3
** -----------------------------------------------------------------------------
** �� �� ��: 
** �޸�����:
** �ա�  ��: 
** ---------------------------------------------------------------------------*/
uint8_t DLT634_5101_MASTER_REPLY(uint8_t pdrv, uint8_t *pbuf)//�ظ�
{ 
	uint8_t res = FALSE;
	
	memcpy(&DLT634_5101Master_App[pdrv].ST_Temp, pbuf,_DLT634_5101MASTER_LPDUSIZE);
	
	if(((DLT634_5101Master_App[pdrv].TimeOutTick_Devid == 0)||(DLT634_5101Master_App[pdrv].Devid == (DLT634_5101Master_App[pdrv].ST_Temp.status.symbol.Lock_ID))
		||(DLT634_5101Master_App[pdrv].StoreDATA1OUT == DLT634_5101Master_App[pdrv].StoreDATA1IN))&&(DLT634_5101Master_App[pdrv].LinkFlag&_DLT634_5101MASTER_INITEND))
	{
		DLT634_5101Master_App[pdrv].TimeOutTick_Devid = DLT634_5101Master_Pad[pdrv].DevidValue;
		DLT634_5101Master_App[pdrv].Devid = DLT634_5101Master_App[pdrv].ST_Temp.status.symbol.Lock_ID;
	}
	else
	{
		return(res);
	}
	
	switch (DLT634_5101Master_App[pdrv].ST_Temp.Head.TypeID)
	{
        //���Ʒ��������Ϣ
        case _DLT634_5101MASTER_C_IC_NA_1: // ����
            res = DLT634_5101_MASTER_StoreIN(pdrv,&DLT634_5101Master_App[pdrv].ST_Temp);
            break;
        
        case _DLT634_5101MASTER_C_SC_NA_1: // ����ң������
        case _DLT634_5101MASTER_C_SC_NB_1: // ˫��ң������
            res = DLT634_5101_MASTER_StoreIN(pdrv,&DLT634_5101Master_App[pdrv].ST_Temp);
            break;

        case _DLT634_5101MASTER_C_CS_NA_1: // ��ʱ����
            res = DLT634_5101_MASTER_StoreIN(pdrv,&DLT634_5101Master_App[pdrv].ST_Temp);
            break;

        case _DLT634_5101MASTER_C_RP_NA_1: // ��λ��������
            break;
        
        case _DLT634_5101MASTER_C_RR_NA_1: // ����ֵ����
        case _DLT634_5101MASTER_C_RS_NA_1: // �������Ͷ�ֵ����
            res = DLT634_5101_MASTER_StoreIN(pdrv,&DLT634_5101Master_App[pdrv].ST_Temp);
            break;
        
        case _DLT634_5101MASTER_C_SR_NA_1: // �л���ֵ��
        case _DLT634_5101MASTER_C_WS_NA_1: // д�����Ͷ�ֵ����
            res = DLT634_5101_MASTER_StoreIN(pdrv,&DLT634_5101Master_App[pdrv].ST_Temp);
            break;

        case _DLT634_5101MASTER_F_FR_NA_1: // �ļ�����
            res = DLT634_5101_MASTER_StoreIN(pdrv,&DLT634_5101Master_App[pdrv].ST_Temp);
            break;

        case _DLT634_5101MASTER_F_SR_NA_1: // �������
            res = DLT634_5101_MASTER_StoreIN(pdrv,&DLT634_5101Master_App[pdrv].ST_Temp);
            break;			

        default: // ���ͱ�ʶ�д����֧��
            break;
	}
	return(res);
}

/* -----------------------------------------------------------------------------
** ��������: DLT634_5101_MASTER_Clock
** ��������: ��ʱ������
** �䡡  ��: pdrv���豸���
** �䡡  ��: ��
** ȫ�ֱ���: DLT634_5101Master_App[pdrv]�����в����ṹ��
**           DLT634_5101Master_Pad[pdrv]���趨�����ṹ��
** ����ģ��: DLT634_5101_MASTER_ReadMISIData  ��ѯMISI���ջ�����
**           DLT634_5101_MASTER_SendProcess  ���ʹ�����
**           DLT634_5101_MASTER_LinkOnTimer  ��·�㶨ʱ��������
** ����  ��: Mr.J
** �ա�  ��: 2017.8.3
** -----------------------------------------------------------------------------
** �� �� ��: 
** �޸�����:
** �ա�  ��: 
** ---------------------------------------------------------------------------*/
void DLT634_5101_MASTER_Clock(uint8_t pdrv)
{
	DLT634_5101Master_App[pdrv].ClockCounter++;
	if (DLT634_5101Master_App[pdrv].ClockCounter >= DLT634_5101Master_Pad[pdrv].ClockTimers)
	{
        DLT634_5101Master_App[pdrv].ClockCounter = 0;
                                            
        // ��ѯMISI���ջ�����
        DLT634_5101_MASTER_ReadMISIData(pdrv);
    
        DLT634_5101_MASTER_SendProcess(pdrv);
            
        // ��·�㶨ʱ��
        DLT634_5101_MASTER_LinkOnTimer(pdrv);
	}
}



