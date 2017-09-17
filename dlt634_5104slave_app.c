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
** File name:               DLT634_5104_link.c
** Descriptions:            The application of DLT634.5104_2002
**
** -----------------------------------------------------------------------------
** Created by:              Mr.Sun
** Created date:            2017.7.11
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
#include "stdbool.h"
#include "dlt634_5104slave_app.h"
#include "dlt634_5104slave_disk.h"

/* PRIVATE VARIABLES ----------------------------------------------------------*/
#pragma pack(push,1)
typedef struct 
{
    BYTE Milliseconds_L;   // D7-D0
    BYTE Milliseconds_H;   // D7-D0
    BYTE Minutes;                    // D5-D0
    BYTE Hours;                        // D4-D0
    BYTE DayofWeekMonth;        // WEEK(D7-D5)MONTH(D4-D0)
    BYTE Months;                        // D3-D0
    BYTE Years;                        // D6-D0
}_DLT634_5104SLAVE_CP56Time2a_t;

typedef struct 
{
    struct STATUS
    {
        BYTE Length;
        union 
        {
            BYTE priority;    
            BYTE Lock_ID;
        }symbol;
    }status;

    struct HEAD
    {
        BYTE TypeID;     
        BYTE VSQ;  
        BYTE COT_L;
        BYTE COT_H;
        BYTE PubAddr_L;
        BYTE PubAddr_H;
    }Head;

    union 
    {
        BYTE buff[256-sizeof(struct STATUS)-sizeof(struct HEAD)];
        
        struct 
        {
            BYTE InfoAddr_L;
            BYTE InfoAddr_M;
            BYTE InfoAddr_H;
            BYTE QOI; 
        }C_100;

        struct 
        {
            BYTE InfoAddr_L;
            BYTE InfoAddr_M;
            BYTE InfoAddr_H;    
            _DLT634_5104SLAVE_CP56Time2a_t CP56Time2a;
        }C_103;

        struct 
        {
            BYTE InfoAddr_L;
            BYTE InfoAddr_M;
            BYTE InfoAddr_H;    
            BYTE QRP; 
        }C_105;

        struct 
        {
            BYTE InfoAddr_L;
            BYTE InfoAddr_M;
            BYTE InfoAddr_H;    
            BYTE COI; 
        }C_70;

        struct 
        {
            BYTE InfoAddr_L;
            BYTE InfoAddr_M;
            BYTE InfoAddr_H;
            BYTE FBP_L;
            BYTE FBP_H;                
        }C_104;

        union 
        {
            struct 
            {
                struct 
                {
                    BYTE InfoAddr_L;
                    BYTE InfoAddr_M;
                    BYTE InfoAddr_H;    
                    BYTE Value; 
                }Array[(256-sizeof(struct STATUS)-sizeof(struct HEAD))/4];
            }SQ0;
            struct 
            {
                BYTE InfoAddr_L;
                BYTE InfoAddr_M;
                BYTE InfoAddr_H;
                struct 
                {
                    BYTE Value; 
                }Array[(256-sizeof(struct STATUS)-sizeof(struct HEAD)-3)/1];
            }SQ1;
        }C_1;

        union 
        {
            struct 
            {
                struct 
                {
                    BYTE InfoAddr_L;
                    BYTE InfoAddr_M;
                    BYTE InfoAddr_H;    
                    BYTE Value; 
                }Array[(256-sizeof(struct STATUS)-sizeof(struct HEAD))/4];
            }SQ0;
            struct 
            {
                BYTE InfoAddr_L;
                BYTE InfoAddr_M; 
                BYTE InfoAddr_H;    
                struct 
                {
                    BYTE Value; 
                }Array[(256-sizeof(struct STATUS)-sizeof(struct HEAD)-3)/1];
            }SQ1;
        }C_3;

        union 
        {
            struct 
            {
                struct 
                {
                    BYTE InfoAddr_L;
                    BYTE InfoAddr_M;
                    BYTE InfoAddr_H;
                    BYTE Value; 
                    _DLT634_5104SLAVE_CP56Time2a_t CP56Time2a;
                }Array[(256-sizeof(struct STATUS)-sizeof(struct HEAD))/11];
            }SQ0;
            struct 
            {
                BYTE InfoAddr_L;
                BYTE InfoAddr_M;
                BYTE InfoAddr_H;    
                struct 
                {
                    BYTE Value; 
                    _DLT634_5104SLAVE_CP56Time2a_t CP56Time2a;
                }Array[(256-sizeof(struct STATUS)-sizeof(struct HEAD)-3)/8];
            }SQ1;
        }C_30;

        union 
        {
            struct 
            {
                struct 
                {
                    BYTE InfoAddr_L;
                    BYTE InfoAddr_M;
                    BYTE InfoAddr_H;    
                    BYTE Value; 
                    _DLT634_5104SLAVE_CP56Time2a_t CP56Time2a;
                }Array[(256-sizeof(struct STATUS)-sizeof(struct HEAD))/11];
            }SQ0;
            struct 
            {
                BYTE InfoAddr_L;
                BYTE InfoAddr_M;
                BYTE InfoAddr_H;    
                struct 
                {
                    BYTE Value; 
                    _DLT634_5104SLAVE_CP56Time2a_t CP56Time2a;
                }Array[(256-sizeof(struct STATUS)-sizeof(struct HEAD)-3)/8];
            }SQ1;
        }C_31;

        union 
        {
            struct 
            {
                struct 
                {
                    BYTE InfoAddr_L;
                    BYTE InfoAddr_M;
                    BYTE InfoAddr_H;
                    WORD Value;
                    BYTE QDS;
                }Array[(256-sizeof(struct STATUS)-sizeof(struct HEAD))/8];
            }SQ0;
            struct 
            {
                BYTE InfoAddr_L;
                BYTE InfoAddr_M;
                BYTE InfoAddr_H;    
                struct 
                {
                    WORD Value;                                    
                    BYTE QDS;
                }Array[(256-sizeof(struct STATUS)-sizeof(struct HEAD)-3)/5];
            }SQ1;
        }C_9;

        union 
        {
            struct 
            {
                struct 
                {
                    BYTE InfoAddr_L;
                    BYTE InfoAddr_M;
                    BYTE InfoAddr_H;
                    WORD Value;
                    BYTE QDS;
                }Array[(256-sizeof(struct STATUS)-sizeof(struct HEAD))/8];
            }SQ0;
            struct 
            {
                BYTE InfoAddr_L;
                BYTE InfoAddr_M;
                BYTE InfoAddr_H;
                struct 
                {
                    WORD Value;
                    BYTE QDS;
                }Array[(256-sizeof(struct STATUS)-sizeof(struct HEAD)-3)/5];
            }SQ1;
        }C_11;

        union 
        {
            struct 
            {
                struct 
                {
                    BYTE InfoAddr_L;
                    BYTE InfoAddr_M;
                    BYTE InfoAddr_H;
                    DWORD Value;    
                    BYTE QDS;
                }Array[(256-sizeof(struct STATUS)-sizeof(struct HEAD))/8];
            }SQ0;

            struct 
            {
                BYTE InfoAddr_L;
                BYTE InfoAddr_M;
                BYTE InfoAddr_H;
                struct 
                {
                    DWORD Value;    
                    BYTE QDS;
                }Array[(256-sizeof(struct STATUS)-sizeof(struct HEAD)-3)/5];
            }SQ1;
        }C_13;

        struct 
        {
            BYTE InfoAddr_L;
            BYTE InfoAddr_M;
            BYTE InfoAddr_H;
            BYTE SCO_L;
            BYTE SCO_H;
        }C_45;    

        struct 
        {
            BYTE InfoAddr_L;
            BYTE InfoAddr_M;
            BYTE InfoAddr_H;    
            BYTE DCO_L;
            BYTE DCO_H;
        }C_46;    

        struct 
        {
            BYTE Array[(256-sizeof(struct STATUS)-sizeof(struct HEAD))]; 
        }C_42;

        struct 
        {
            BYTE InfoAddr_L;
            BYTE InfoAddr_M;
            BYTE InfoAddr_H;    
            BYTE SN_L;
            BYTE SN_H;
        }C_200;

        union 
        {
            struct 
            {
                BYTE InfoAddr_L;
                BYTE InfoAddr_M;
                BYTE InfoAddr_H;
            }Down;

            struct 
            {
                BYTE InfoAddr_L;
                BYTE InfoAddr_M;
                BYTE InfoAddr_H;    
                BYTE SN1_L;
                BYTE SN1_H;
                BYTE SN2_L;
                BYTE SN2_H;
                BYTE SN3_L;
                BYTE SN3_H;
            }Up;
        }C_201;

        union 
        {
            struct 
            {
                BYTE SN1_L;
                BYTE SN1_H;
                WORD Array[(256-sizeof(struct STATUS)-sizeof(struct HEAD)-2)/4];        
            }Down;

            struct 
            {
                BYTE SN_L;
                BYTE SN_H;    
                BYTE PI_L;
                BYTE PI_H;
                struct 
                {
                    BYTE InfoAddr_L;
                    BYTE InfoAddr_M;
                    BYTE InfoAddr_H;
                    BYTE Tag;
                    BYTE Len;
                    DWORD Value;    
                }Array[(256-sizeof(struct STATUS)-sizeof(struct HEAD)-4)/9];
            }Up;
        }C_202;

        union 
        {
            BYTE SN_L;
            BYTE SN_H;    
            BYTE PI_L;
            BYTE PI_H;
            struct 
            {
                BYTE InfoAddr_L;
                BYTE InfoAddr_M;
                BYTE InfoAddr_H;
                BYTE Tag;
                BYTE Len;
                DWORD Value;    
            }Array[(256-sizeof(struct STATUS)-sizeof(struct HEAD)-4)/9];
        }C_203;

        struct 
        {
            BYTE Array[(256-sizeof(struct STATUS)-sizeof(struct HEAD))]; 
        }C_210;
    }Data;
}DLT634_5104SLAVE_PASDU;

 struct DLT634_5104SLAVE_PASDU_104
{
         struct PASDUHead_104
        {   
                BYTE    TypeID; // ���ͱ�ʶ
                BYTE    VSQ;    // �ɱ�ṹ�޶���
             
                // ����ԭ��
                WORD COT;

                // Ӧ�÷������ݵ�Ԫ������ַ
                WORD PubAddr;

                // ��Ϣ�����ַ
                WORD InfoAddr;

        }Head;
    BYTE Data[DLT634_5104SLAVE_ASDUSIZE - sizeof(struct PASDUHead_104)];
};

 struct DLT634_5104SLAVE_SendData
{
        BYTE TxLen;
        BYTE TxData[DLT634_5104SLAVE_ASDUSIZE];    
};  
        
/* �鴦��ṹ -----------------------------------------------------------------*/ 
struct DLT634_5104SLAVE_APPINFO
{    
    BYTE Connect; // ��������״̬    

    BYTE  YXTypeID;           // ң�����ͱ�ʶ
    BYTE  YCTypeID;           // ң�����ͱ�ʶ    
    WORD  CurSData;           // δ��ȷ�ϵ�I֡���ݻ�����λ�ñ�ʶ

      BYTE  RxdBuf[2*DLT634_5104SLAVE_APDUSIZE]; // ���ջ�����
    BYTE  TxdBuf[2*DLT634_5104SLAVE_APDUSIZE]; // ���ͻ�����    

      DWORD  Data1Flag; 
    DWORD  AllDataFlag; // ����״̬��־
    DWORD  AppNextFlag; // �������ݱ�־

      BYTE TxLen;     

      struct DLT634_5104SLAVE_PASDU_104 TxMsg;  // Ӧ�ò㷢������ָ��
    struct DLT634_5104SLAVE_PASDU_104 *RxMsg; // Ӧ�ò��������ָ��         
    
        struct DLT634_5104SLAVE_SendData SData[DLT634_5104SLAVE_K]; // δ��ȷ�ϵ�I֡����    
    
        struct PGroupTrn
        {        
                WORD InfoAddr;
                BYTE TypeID;
                BYTE COT;
                BYTE GroupNo;
        }GroupTrn;// ���鴦��ṹ��
    
      DLT634_5104SLAVE_PASDU *StoreDATA1IN;              // �����ͻ�����1��������ָ��
      DLT634_5104SLAVE_PASDU *StoreDATA1OUT;             // �����ͻ�����1�����ݳ�ָ��
    DLT634_5104SLAVE_PASDU StoreDATA1Buf[DLT634_5104SLAVE_STOREDATA1NUM];         // 1�����ݴ����ͻ�����
      DLT634_5104SLAVE_PASDU *StoreDATA2IN;              // �����ͻ�����1��������ָ��
      DLT634_5104SLAVE_PASDU *StoreDATA2OUT;             // �����ͻ�����1�����ݳ�ָ��
      DLT634_5104SLAVE_PASDU StoreDATA2Buf[DLT634_5104SLAVE_STOREDATA1NUM];         // 2�����ݴ����ͻ�����
      DLT634_5104SLAVE_PASDU ST_Temp;              // �洢���ݴ���
    
      DLT634_5104SLAVE_PASDU TX_Temp;              //�������ݴ���
      DLT634_5104SLAVE_PASDU RX_Temp;              //�������ݴ���      
};

struct DLT634_5104SLAVE_PAPCI
{
    BYTE    StartCode;
    BYTE    Length;
    WORD NS;
    WORD NR;
};

struct DLT634_5104SLAVE_LINKINFO
{
    BYTE Connect; // ��������״̬
      BYTE DataType[DLT634_5104SLAVE_K]; // �����������ͣ�I��ʽ֡
    BYTE StopSendFlag; //ֹͣ���ͱ�־(δ��ȷ�ϵ�I��ʽ֡�ﵽK����ֹͣ����)        

      BYTE RxdBuf[2*DLT634_5104SLAVE_APDUSIZE]; // ���ջ�����
    BYTE TxdBuf[2*DLT634_5104SLAVE_APDUSIZE]; // ���ͻ�����        
  
    WORD NR; // ���հ�����
    WORD NS; // ���Ͱ�����
      WORD NRACK; // �ϴ�ȷ�ϵĽ������к�
  
    WORD PeerNoAckNum; // �Է�δ����ȷ�ϵ�I��ʽ֡��Ŀ      
    
      WORD RxdHead; // �������ݵ�ͷָ��
    WORD RxdTail;        
    WORD RxdLength;
    
    WORD FrameHead; // ��֡ʱ����ͷ�ڷ��ͻ�������λ��
    WORD TxdHead;
    WORD TxdTail;
    
      // ��������
    WORD Tick0;
    WORD Tick1;
    WORD Tick2;
    WORD Tick3;

        DWORD  ClockCounter;  // �����������ڿ���
        
        enum DLRXDSTATUS
        {
                RXDSTART = 0,                                   // Ѱ����ʼ��־״̬
                RXDHEAD,                                       // Ѱ�ұ���ͷ
                RXDCONTINUE                                  // ���պ�������
        }RxdStatus;// ����״̬
            
        struct PTick
        {
            WORD TValue0;    
            WORD TValue1[DLT634_5104SLAVE_K];
            WORD TValue2;
            WORD TValue3;
            BYTE    Flag; // ��λʹ��
            BYTE    FlagBak; // ����
        }Tick;
                
};
#pragma pack(pop)

/* PUBLIC VARIABLES ----------------------------------------------------------*/
struct DLT634_5104SLAVE_PAD DLT634_5104Slave_Pad[DLT634_5104SLAVE_VOLUMES]; // DL/T634_5101��Լ����
struct DLT634_5104SLAVE_LINKINFO DLT104SlaveLink[DLT634_5104SLAVE_VOLUMES]; // ��·�����
struct DLT634_5104SLAVE_APPINFO DLT104SlaveApp[DLT634_5104SLAVE_VOLUMES];

/* PRIVATE FUNCTION PROTOTYPES -----------------------------------------------*/
/* -----------------------------------------------------------------------------
** ��������: SetTimer
** ��������: ������ʱ����
** �䡡  ��: No:��ʱ����.
** �䡡  ��: ��
** ȫ�ֱ���: ��
** ����ģ��: ��
** ����  ��: Mr.Sun
** �ա�  ��: 2017.07.11
** -----------------------------------------------------------------------------
** �� �� ��: 
** �޸�����:
** �ա�  ��: 
** ---------------------------------------------------------------------------*/
static void DLT634_5104_SLAVE_SetTimer(BYTE pdrv, BYTE No)
{
    BYTE    i = 0;
    
    switch (No)
    {
        case 0:
            DLT104SlaveLink[pdrv].Tick.TValue0 = 0;
            DLT104SlaveLink[pdrv].Tick.Flag |= DLT634_5104SLAVE_T0FLAG;
            break;
            
        case 1:
            for (i = 0; i < DLT634_5104SLAVE_K; i++)
            {
                DLT104SlaveLink[pdrv].Tick.TValue1[i] = 0;
            }
            DLT104SlaveLink[pdrv].Tick.Flag |= DLT634_5104SLAVE_T1FLAG;            
            break;
            
        case 2:
            DLT104SlaveLink[pdrv].Tick.TValue2 = 0;
            DLT104SlaveLink[pdrv].Tick.Flag |= DLT634_5104SLAVE_T2FLAG;            
            break;
            
        case 3:
            DLT104SlaveLink[pdrv].Tick.TValue3 = 0;
            DLT104SlaveLink[pdrv].Tick.Flag |= DLT634_5104SLAVE_T3FLAG;            
            break;
        
        default:
            break;
    }
}

/* -----------------------------------------------------------------------------
** ��������: KillTimer
** ��������: ֹͣ��ʱ����
** �䡡  ��: No:��ʱ����.
** �䡡  ��: ��
** ȫ�ֱ���: ��
** ����ģ��: ��
** ����  ��: Mr.Lee
** �ա�  ��: 2016.10.25
** -----------------------------------------------------------------------------
** �� �� ��: 
** �޸�����:
** �ա�  ��: 
** ---------------------------------------------------------------------------*/
static void DLT634_5104_SLAVE_KillTimer(BYTE pdrv, BYTE No)
{
    switch (No)
    {
        case 0:
            DLT104SlaveLink[pdrv].Tick.Flag &= (~DLT634_5104SLAVE_T0FLAG);
            break;
            
        case 1:
            DLT104SlaveLink[pdrv].Tick.Flag &= (~DLT634_5104SLAVE_T1FLAG);
            break;
            
        case 2:
            DLT104SlaveLink[pdrv].Tick.Flag &= (~DLT634_5104SLAVE_T2FLAG);            
            break;
            
        case 3:
            DLT104SlaveLink[pdrv].Tick.Flag &= (~DLT634_5104SLAVE_T3FLAG);            
            break;
            
        default:
            break;
    }
}

/* -----------------------------------------------------------------------------
** ��������: DLT634_5104_SLAVE_BackupProcess
** ��������: δ��ȷ��I֡���ݴ���
** �䡡  ��: pdrv: �豸ID
**           LastNoAckNum: �ϴ�δȷ�ϵ�����
**           NowNoAckNum: ����δȷ�ϵ�����
** �䡡  ��: ��
** ȫ�ֱ���: ��
** ����ģ��: ��
** ����  ��: Mr.Sun
** �ա�  ��: 2017.07.20
** -----------------------------------------------------------------------------
** �� �� ��:                                              
** �޸�����:
** �ա�  ��: 
** ---------------------------------------------------------------------------*/
void DLT634_5104_SLAVE_BackupProcess(BYTE pdrv, WORD LastNoAckNum, WORD NowNoAckNum)
{
      WORD num;
      struct DLT634_5104SLAVE_APPINFO *pMsg;
       
        pMsg = &DLT104SlaveApp[pdrv];     
      num = LastNoAckNum - NowNoAckNum; // ���α�ȷ�ϵ�����
    memcpy(&pMsg[pdrv].SData, &pMsg[pdrv].SData[num], sizeof(struct DLT634_5104SLAVE_SendData) * NowNoAckNum); 
      pMsg[pdrv].CurSData -= num;
}

/* -----------------------------------------------------------------------------
** ��������: PeerNoAckNumProcess
** ��������: ����Է�ȷ�ϡ�
** �䡡  ��: PeerNR:�������к�.
** �䡡  ��: ��
** ȫ�ֱ���: ��
** ����ģ��: ��
** ����  ��: Mr.Lee
** �ա�  ��: 2016.10.25
** -----------------------------------------------------------------------------
** �� �� ��: 
** �޸�����:
** �ա�  ��: 
** ---------------------------------------------------------------------------*/
static BYTE DLT634_5104_SLAVE_PeerNoAckNumProcess(BYTE pdrv, WORD PeerNR)
{
    WORD i = 0;
    WORD tmp = 0, num = 0;
    
    if (PeerNR <= DLT104SlaveLink[pdrv].NS)
    {
        num = DLT104SlaveLink[pdrv].NS - PeerNR;
    }
    else
    {
        num = 32767 + DLT104SlaveLink[pdrv].NS - PeerNR;          
    }
    
    if (num > DLT104SlaveLink[pdrv].PeerNoAckNum)
    {
        return (FALSE);
    }

    for (i = 0, tmp = 0; i < DLT104SlaveLink[pdrv].PeerNoAckNum - num; i++)
    {
        if (DLT104SlaveLink[pdrv].DataType[i])
        {
            tmp++;
        }
    }

        DLT634_5104_SLAVE_BackupProcess(pdrv, DLT104SlaveLink[pdrv].PeerNoAckNum, num); // δ��ȷ��I֡���ݴ���
    
    for (i = 0; i < num; i++)
    {
        DLT104SlaveLink[pdrv].Tick.TValue1[i] = DLT104SlaveLink[pdrv].Tick.TValue1[num+i];
        DLT104SlaveLink[pdrv].DataType[i] = DLT104SlaveLink[pdrv].DataType[num+i];
    }
    
    for (i = num; i < DLT634_5104SLAVE_K; i++)
    {
        DLT104SlaveLink[pdrv].Tick.TValue1[i] = 0;
        DLT104SlaveLink[pdrv].DataType[i] = FALSE;
    }
    
    DLT104SlaveLink[pdrv].PeerNoAckNum = num;    
    
    return (TRUE);
}

static BYTE DLT634_5104_SLAVE_StoreIN(BYTE pdrv, DLT634_5104SLAVE_PASDU *buf)
{        
    DLT634_5104SLAVE_PASDU *temp;
    DLT634_5104SLAVE_PASDU tempbuf;
    
    if(buf->status.symbol.priority<DLT634_5104SLAVE_M_FT_NA_P)
    {
        temp = DLT104SlaveApp[pdrv].StoreDATA1IN;
        if(++temp >= DLT104SlaveApp[pdrv].StoreDATA1Buf + DLT634_5104SLAVE_STOREDATA1NUM)
        {
            temp = DLT104SlaveApp[pdrv].StoreDATA1Buf;
        }
        
        if(temp == DLT104SlaveApp[pdrv].StoreDATA1OUT)
        {
            return(FALSE);
        }
    
        temp = DLT104SlaveApp[pdrv].StoreDATA1OUT;
        while(temp != DLT104SlaveApp[pdrv].StoreDATA1IN)
        {
            if(((temp->status.symbol.priority > buf->status.symbol.priority)||(temp->status.symbol.priority == 0))&&(temp != DLT104SlaveApp[pdrv].StoreDATA1OUT))
            {
                memcpy(&tempbuf,temp,sizeof(DLT634_5104SLAVE_PASDU));
                memcpy(temp,buf,sizeof(DLT634_5104SLAVE_PASDU));
                memcpy(buf,&tempbuf,sizeof(DLT634_5104SLAVE_PASDU));
            }
            if(++temp >= DLT104SlaveApp[pdrv].StoreDATA1Buf + DLT634_5104SLAVE_STOREDATA1NUM)
            {
                temp = DLT104SlaveApp[pdrv].StoreDATA1Buf;
            }
        }
        
        memcpy(temp,buf,sizeof(DLT634_5104SLAVE_PASDU));    
        if(++DLT104SlaveApp[pdrv].StoreDATA1IN >= DLT104SlaveApp[pdrv].StoreDATA1Buf + DLT634_5104SLAVE_STOREDATA1NUM)
        {
            DLT104SlaveApp[pdrv].StoreDATA1IN = DLT104SlaveApp[pdrv].StoreDATA1Buf;
        }
    }
    else
    {
        temp = DLT104SlaveApp[pdrv].StoreDATA2IN;
        if(++temp >= DLT104SlaveApp[pdrv].StoreDATA2Buf + DLT634_5104SLAVE_STOREDATA2NUM)
        {
            temp = DLT104SlaveApp[pdrv].StoreDATA2Buf;
        }
        
        if(temp == DLT104SlaveApp[pdrv].StoreDATA2OUT)
        {
            return(FALSE);
        }
        
        temp = DLT104SlaveApp[pdrv].StoreDATA2OUT;
        while(temp != DLT104SlaveApp[pdrv].StoreDATA2IN)
        {
            if(((temp->status.symbol.priority > buf->status.symbol.priority)||(temp->status.symbol.priority == 0))&&(temp != DLT104SlaveApp[pdrv].StoreDATA2OUT))
            {
                memcpy(&tempbuf,temp,sizeof(DLT634_5104SLAVE_PASDU));
                memcpy(temp,buf,sizeof(DLT634_5104SLAVE_PASDU));
                memcpy(buf,&tempbuf,sizeof(DLT634_5104SLAVE_PASDU));
            }
            if(++temp >= DLT104SlaveApp[pdrv].StoreDATA2Buf + DLT634_5104SLAVE_STOREDATA2NUM)
            {
                temp = DLT104SlaveApp[pdrv].StoreDATA2Buf;
            }
        }
        
        memcpy(temp,buf,sizeof(DLT634_5104SLAVE_PASDU));
        if(++DLT104SlaveApp[pdrv].StoreDATA2IN >= DLT104SlaveApp[pdrv].StoreDATA2Buf + DLT634_5104SLAVE_STOREDATA2NUM)
        {
            DLT104SlaveApp[pdrv].StoreDATA2IN = DLT104SlaveApp[pdrv].StoreDATA2Buf;
        }
    }
    return(TRUE);
}

/* -----------------------------------------------------------------------------
** ��������: DLT634_5104_AppInitReset
** ��������: Ӧ�ò����ݳ�ʼ����λ.
** �䡡  ��: ��
** �䡡  ��: ��
** ȫ�ֱ���: ��
** ����ģ��: ��
** ����  ��: Mr.Lee
** �ա�  ��: 2016.10.25
** -----------------------------------------------------------------------------
** �� �� ��: 
** �޸�����:
** �ա�  ��: 
** ---------------------------------------------------------------------------*/
BYTE DLT634_5104_AppInitReset(BYTE pdrv)
{
    DLT104SlaveApp[pdrv].AllDataFlag = FALSE;
    DLT104SlaveApp[pdrv].AppNextFlag = FALSE;    
    
    // Link
    DLT104SlaveLink[pdrv].Connect = FALSE;
    DLT104SlaveLink[pdrv].NR = 0;
    DLT104SlaveLink[pdrv].NS = 0;
    DLT104SlaveLink[pdrv].PeerNoAckNum = 0;
    DLT104SlaveLink[pdrv].FrameHead = 0;
    DLT104SlaveLink[pdrv].TxdHead = 0;
    DLT104SlaveLink[pdrv].TxdTail = 0;
        
        memset(DLT104SlaveLink[pdrv].TxdBuf, 0, sizeof(DLT104SlaveLink[pdrv].RxdBuf)); // ��ս��ջ�����
        memset(DLT104SlaveLink[pdrv].RxdBuf, 0, sizeof(DLT104SlaveLink[pdrv].TxdBuf)); // ��շ��ͻ�����
    
        DLT104SlaveApp[pdrv].StoreDATA1IN = DLT104SlaveApp[pdrv].StoreDATA1Buf;
        DLT104SlaveApp[pdrv].StoreDATA1OUT = DLT104SlaveApp[pdrv].StoreDATA1Buf;
        memset(DLT104SlaveApp[pdrv].StoreDATA1Buf,0,sizeof(DLT104SlaveApp[pdrv].StoreDATA1Buf));
        DLT104SlaveApp[pdrv].StoreDATA2IN = DLT104SlaveApp[pdrv].StoreDATA2Buf;
        DLT104SlaveApp[pdrv].StoreDATA2OUT = DLT104SlaveApp[pdrv].StoreDATA2Buf;
        memset(DLT104SlaveApp[pdrv].StoreDATA2Buf,0,sizeof(DLT104SlaveApp[pdrv].StoreDATA2Buf));
    
        return (TRUE);
}

/* -----------------------------------------------------------------------------
** ��������: DLT634_5104_SLAVE_AppProcess
** ��������: Ӧ�ò����ݴ���
** �䡡  ��: struct DLT634_5104SLAVE_AppMsg* Msg��Ӧ�ò���Ϣ�ṹ.
** �䡡  ��: ��
** ȫ�ֱ���: ��
** ����ģ��: ��
** ����  ��: Mr.Lee
** �ա�  ��: 2016.10.25
** -----------------------------------------------------------------------------
** �� �� ��: 
** �޸�����:
** �ա�  ��: 
** ---------------------------------------------------------------------------*/
void DLT634_5104_SLAVE_AppProcess(BYTE pdrv, struct DLT634_5104SLAVE_AppMsg* Msg)
{    
      DLT104SlaveApp[pdrv].TxLen = 0;
    DLT104SlaveApp[pdrv].RxMsg = (struct DLT634_5104SLAVE_PASDU_104*)Msg->pData;
//  ���ｫ104����תΪ02��104����    
      memset((BYTE *)&DLT104SlaveApp[pdrv].RX_Temp,0,sizeof(DLT634_5104SLAVE_PASDU));
      memcpy((BYTE *)&DLT104SlaveApp[pdrv].RX_Temp.Head,Msg->pData, Msg->Len);
        DLT104SlaveApp[pdrv].RX_Temp.status.Length = Msg->Len + sizeof(DLT104SlaveApp[pdrv].RX_Temp.status);

      switch (Msg->Cmd)
        {
            case DLT634_5104SLAVE_LINK_CALLDATA:
                
            switch (DLT104SlaveApp[pdrv].RxMsg->Head.TypeID) // �������ͱ�ʶ����
            {
                case DLT634_5104SLAVE_C_SC_NA_1:    // <45>����ң������
                case DLT634_5104SLAVE_C_SC_NB_1:    // <46>˫��ң������
                    DLT634_5104_SLAVE_HandleCtrlProcess(pdrv, (BYTE *)&DLT104SlaveApp[pdrv].RX_Temp);
                    break;                        
                        
                case DLT634_5104SLAVE_C_IC_NA_1:    // <100>���ٻ�������ٻ�
                                    DLT104SlaveApp[pdrv].Data1Flag |= DLT634_5104SLAVE_CALLALLDATA;
                                    DLT104SlaveApp[pdrv].AllDataFlag = 0;
                    break;
                        
                case DLT634_5104SLAVE_C_CI_NA_1:    // <101>������ٻ�������ٻ�
                    //ReadDDProcess(pdrv);
                    break;
                        
                case DLT634_5104SLAVE_C_CS_NA_1:    // <103>��������
                    DLT634_5104_SLAVE_SYNProcess(pdrv, (BYTE *)&DLT104SlaveApp[pdrv].RX_Temp);
                    break;
                        
                case DLT634_5104SLAVE_C_RP_NA_1:    // <105>��λ��������
                    //ResetProcess(pdrv);
                    break;                        
                        
                case DLT634_5104SLAVE_C_TS_NA_1:    // <104>��������
                    DLT104SlaveApp[pdrv].RX_Temp.status.symbol.priority = DLT634_5104SLAVE_C_TS_NA_P;
                    DLT104SlaveApp[pdrv].RX_Temp.Head.COT_L = DLT634_5104SLAVE_COT_ACTCON;
                    DLT634_5104_SLAVE_StoreIN(pdrv,&DLT104SlaveApp[pdrv].RX_Temp);                                
//                    TestReply(pdrv);
                    break;   
                
                case DLT634_5104SLAVE_C_SR_NA_1: // <200>�л���ֵ��
                case DLT634_5104SLAVE_C_RR_NA_1: // <201>����ֵ����
                case DLT634_5104SLAVE_C_RS_NA_1: // <202>�������Ͷ�ֵ
                case DLT634_5104SLAVE_C_WS_NA_1: // <203>д�����Ͷ�ֵ    
                            DLT634_5104_SLAVE_FixedParaProcess(pdrv,(BYTE *)&DLT104SlaveApp[pdrv].RX_Temp);            
                    break;
                
                case DLT634_5104SLAVE_F_FR_NA_1: // <210>�ļ�����
                    DLT634_5104_SLAVE_FileHandleProcess(pdrv,(BYTE *)&DLT104SlaveApp[pdrv].RX_Temp);
//                    FUNC_F_FR_NA_1_ID210(pdrv);
                    break;
                                
                case DLT634_5104SLAVE_F_SR_NA_1: // <211>�������
                      
                    break;
                                
                default:    // ���ͱ�ʶ�д����֧��
                    break;
            }
            break;
                
        case DLT634_5104SLAVE_LINK_APPCON:
            break;    

        case DLT634_5104SLAVE_LINK_WORK:
            DLT104SlaveApp[pdrv].Connect = TRUE; // �յ�STSRTDT��
            break;
                
        case DLT634_5104SLAVE_LINK_NOWORK:
            DLT634_5104_AppInitReset(pdrv);
            DLT104SlaveApp[pdrv].Connect = FALSE;
            break;
        
        default:
            break; 
        }                  
}

/* -----------------------------------------------------------------------------
** ��������: StopDTOper
** ��������: ֹͣ���ݴ��䣬�ر�TCP���ӡ�
** �䡡  ��: ��
** �䡡  ��: ��
** ȫ�ֱ���: ��
** ����ģ��: ��
** ����  ��: Mr.Lee
** �ա�  ��: 2016.10.25
** -----------------------------------------------------------------------------
** �� �� ��: 
** �޸�����:
** �ա�  ��: 
** ---------------------------------------------------------------------------*/
static void DLT634_5104_SLAVE_StopDTOper(BYTE pdrv)
{
      struct DLT634_5104SLAVE_AppMsg    msg;
    
    msg.Cmd = DLT634_5104SLAVE_LINK_NOWORK;
    msg.ConNum = 0;
    msg.pData = NULL;
    msg.Len = 0;
    DLT634_5104_SLAVE_AppProcess(pdrv, &msg);    
    
    DLT634_5104_SLAVE_StopLink(pdrv);
    DLT104SlaveLink[pdrv].Connect = FALSE;    // ����·���ӱ�־
}

/* -----------------------------------------------------------------------------
** ��������: DLT634_5104_WriteDataToMISI
** ��������: �������ݵ�MISI��
** �䡡  ��: ��
** �䡡  ��: ��
** ȫ�ֱ���: ��
** ����ģ��: ��
** ����  ��: Mr.Lee
** �ա�  ��: 2016.10.25
** -----------------------------------------------------------------------------
** �� �� ��: 
** �޸�����:
** �ա�  ��: 
** ---------------------------------------------------------------------------*/
void DLT634_5104_SLAVE_WriteDataToMISI(BYTE pdrv)
{
    WORD count = 0, num = 0;
    
    if (DLT104SlaveLink[pdrv].TxdHead >= DLT104SlaveLink[pdrv].TxdTail)
    {
        return ;
    }
    
    num = DLT104SlaveLink[pdrv].TxdTail - DLT104SlaveLink[pdrv].TxdHead;
    
    // д���ݿ⺯��
    count = DLT634_5104_SLAVE_WriteData(pdrv,(BYTE *)&DLT104SlaveLink[pdrv].TxdBuf[DLT104SlaveLink[pdrv].TxdHead], num);
        DLT104SlaveLink[pdrv].TxdHead += count;
    
        if (DLT104SlaveLink[pdrv].TxdHead >= DLT104SlaveLink[pdrv].TxdTail)
    {
        DLT104SlaveLink[pdrv].TxdTail = 0;
        DLT104SlaveLink[pdrv].TxdHead = 0;
    }
}

/* -----------------------------------------------------------------------------
** ��������: S104SendCtrlFrame
** ��������: ������·���������ݣ�����S��U��ʽ��
** �䡡  ��: ctrl������������.
** �䡡  ��: ��
** ȫ�ֱ���: ��
** ����ģ��: ��
** ����  ��: Mr.Lee
** �ա�  ��: 2016.10.25
** -----------------------------------------------------------------------------
** �� �� ��: 
** �޸�����:
** �ա�  ��: 
** ---------------------------------------------------------------------------*/
static void DLT634_5104_SLAVE_S104SendCtrlFrame(BYTE pdrv, BYTE ctrl)
{
    struct DLT634_5104SLAVE_PAPCI *pFrame;
    
    pFrame = (struct DLT634_5104SLAVE_PAPCI*)&DLT104SlaveLink[pdrv].TxdBuf[DLT104SlaveLink[pdrv].TxdHead];
    
    pFrame->StartCode = DLT634_5104SLAVE_STARTCODE68;
    pFrame->Length = 0x04;
    pFrame->NS = ctrl;
    if (ctrl == DLT634_5104SLAVE_S_FRAME)
    {
              DLT104SlaveLink[pdrv].NRACK = DLT104SlaveLink[pdrv].NR;
        pFrame->NR = DLT104SlaveLink[pdrv].NR << 1;
        
        DLT634_5104_SLAVE_KillTimer(pdrv, 2);
    }
    else
    {
        pFrame->NR = 0x00;
            
        DLT634_5104_SLAVE_SetTimer(pdrv, 3);
            
        if (ctrl == DLT634_5104SLAVE_U_TESTFRACT)
        {
            DLT634_5104_SLAVE_SetTimer(pdrv, 1); // U������Ӧ��t1ʱ���ڵõ�ȷ��
                        DLT104SlaveLink[pdrv].PeerNoAckNum++;
        }
    }
    
    DLT104SlaveLink[pdrv].TxdTail += 0x06;
    
    // ����                                        
    DLT634_5104_SLAVE_WriteDataToMISI(pdrv);
}

/* -----------------------------------------------------------------------------
** ��������: DecodeSFrame
** ��������: ����S��ʽ֡���ݡ�
** �䡡  ��: ��
** �䡡  ��: ��
** ȫ�ֱ���: ��
** ����ģ��: ��
** ����  ��: Mr.Lee
** �ա�  ��: 2016.10.25
** -----------------------------------------------------------------------------
** �� �� ��: 
** �޸�����:
** �ա�  ��: 
** ---------------------------------------------------------------------------*/
static void DLT634_5104_SLAVE_DecodeSFrame(BYTE pdrv)
{
    WORD tmp = 0;
    struct DLT634_5104SLAVE_PAPCI *pAPCI;
    struct DLT634_5104SLAVE_AppMsg    msg;
    
    pAPCI = (struct DLT634_5104SLAVE_PAPCI*)DLT104SlaveLink[pdrv].RxdBuf;
    
    if (!DLT104SlaveLink[pdrv].Connect)
    {
        return;
    }
    
    tmp = DLT104SlaveLink[pdrv].PeerNoAckNum;
    if (!DLT634_5104_SLAVE_PeerNoAckNumProcess(pdrv, pAPCI->NR >> 1))
    {
        return;
    }
    DLT104SlaveLink[pdrv].StopSendFlag = FALSE;
        
    msg.Cmd = DLT634_5104SLAVE_LINK_APPCON; // �����������  ԭ����Ӧ����LINK_NOWORK������
    msg.ConNum = tmp - DLT104SlaveLink[pdrv].PeerNoAckNum;
    msg.pData = NULL;
    msg.Len = 0;
    DLT634_5104_SLAVE_AppProcess(pdrv, &msg);
}

/* -----------------------------------------------------------------------------
** ��������: DecodeUFrame
** ��������: ����U��ʽ֡���ݡ�
** �䡡  ��: ��
** �䡡  ��: ��
** ȫ�ֱ���: ��
** ����ģ��: ��
** ����  ��: Mr.Lee
** �ա�  ��: 2016.10.25
** -----------------------------------------------------------------------------
** �� �� ��: 
** �޸�����:
** �ա�  ��: 
** ---------------------------------------------------------------------------*/
static void DLT634_5104_SLAVE_DecodeUFrame(BYTE pdrv)
{
      struct DLT634_5104SLAVE_PAPCI *pAPCI;
    struct DLT634_5104SLAVE_AppMsg    msg;
            
    pAPCI = (struct DLT634_5104SLAVE_PAPCI*)DLT104SlaveLink[pdrv].RxdBuf;
    
    switch (pAPCI->NS & 0xFF)
    {
        case DLT634_5104SLAVE_U_STARTDTACT:
            // �Ƿ��ʼ��
            DLT104SlaveLink[pdrv].Tick.Flag = DLT104SlaveLink[pdrv].Tick.FlagBak;
            
                    DLT634_5104_SLAVE_S104SendCtrlFrame(pdrv, DLT634_5104SLAVE_U_STARTDTCON);  
                    DLT104SlaveLink[pdrv].Connect = TRUE; 
        
            msg.Cmd = DLT634_5104SLAVE_LINK_WORK;
            msg.ConNum = 0;
            msg.pData = NULL;
            msg.Len = 0;
            DLT634_5104_SLAVE_AppProcess(pdrv, &msg);                    
            break;
            
        case DLT634_5104SLAVE_U_STARTDTCON: // �ն� Ӧ�ò����յ�������
            break;
    
        case DLT634_5104SLAVE_U_STOPDTACT:
            DLT104SlaveLink[pdrv].Tick.FlagBak = DLT104SlaveLink[pdrv].Tick.Flag;
            DLT104SlaveLink[pdrv].Tick.Flag = 0;
                    /*�ظ�ֹͣȷ��֮ǰ��Կ���վδȷ�ϱ��Ľ���ȷ�ϣ�������վ����δȷ�ϱ��� ��ȴ�ȷ��*/
            if (DLT104SlaveLink[pdrv].NR > DLT104SlaveLink[pdrv].NRACK)
                        {
                            DLT634_5104_SLAVE_S104SendCtrlFrame(pdrv, DLT634_5104SLAVE_S_FRAME); // �յ���վU_STOPDTACT����
                        }
                        else
                        {
                            DLT634_5104_SLAVE_S104SendCtrlFrame(pdrv, DLT634_5104SLAVE_U_STOPDTCON);
                
                              msg.Cmd = DLT634_5104SLAVE_LINK_NOWORK;
                msg.ConNum = 0;
                msg.pData = NULL;
                msg.Len = 0;
                DLT634_5104_SLAVE_AppProcess(pdrv, &msg);                                    
                        }
            break;
    
        case DLT634_5104SLAVE_U_STOPDTCON: // �ն� Ӧ�ò����յ�������
            break;
    
        case DLT634_5104SLAVE_U_TESTFRACT:
            DLT634_5104_SLAVE_S104SendCtrlFrame(pdrv, DLT634_5104SLAVE_U_TESTFRCON);
                 
                    break;
    
        case DLT634_5104SLAVE_U_TESTFRCON:
                    /*�յ�����ȷ�Ϻ� Ӧ��t1, ��ʱt1Ӧ��ֻ�в��Լ�ʱ*/
                        
            break;
            
        default:
            break;
    }
}

/* -----------------------------------------------------------------------------
** ��������: DecodeIFrame
** ��������: ����I��ʽ֡���ݡ�
** �䡡  ��: ��
** �䡡  ��: ��
** ȫ�ֱ���: ��
** ����ģ��: ��
** ����  ��: Mr.Lee
** �ա�  ��: 2016.10.25
** -----------------------------------------------------------------------------
** �� �� ��: 
** �޸�����:
** �ա�  ��: 
** ---------------------------------------------------------------------------*/
static void DLT634_5104_SLAVE_DecodeIFrame(BYTE pdrv)
{
    WORD tmp = 0;
    struct DLT634_5104SLAVE_AppMsg msg;
    struct DLT634_5104SLAVE_PAPCI *pAPCI;
    
    pAPCI = (struct DLT634_5104SLAVE_PAPCI*)DLT104SlaveLink[pdrv].RxdBuf;
    
    if (!DLT104SlaveLink[pdrv].Connect)
    {
        return;
    }
    
    tmp = DLT104SlaveLink[pdrv].PeerNoAckNum;
    if (!DLT634_5104_SLAVE_PeerNoAckNumProcess(pdrv, pAPCI->NR >> 1))
    {
        DLT634_5104_SLAVE_StopDTOper(pdrv);
        return;
    }

    if (DLT104SlaveLink[pdrv].NR == 32767)
    {
        DLT104SlaveLink[pdrv].NR = 0;
    }
    else
    {
        DLT104SlaveLink[pdrv].NR++;
    }

    DLT104SlaveLink[pdrv].StopSendFlag = FALSE; // ��ֹͣ���ͱ�־
        
    DLT634_5104_SLAVE_KillTimer(pdrv, 1);
    DLT634_5104_SLAVE_SetTimer(pdrv, 2);
    DLT634_5104_SLAVE_SetTimer(pdrv, 3);
    
    msg.Cmd = DLT634_5104SLAVE_LINK_CALLDATA;
    msg.ConNum = tmp - DLT104SlaveLink[pdrv].PeerNoAckNum;
    msg.pData = &DLT104SlaveLink[pdrv].RxdBuf[6];
    msg.Len = pAPCI->Length - 4;
    
    DLT634_5104_SLAVE_AppProcess(pdrv, &msg);
}

/* -----------------------------------------------------------------------------
** ��������: SearchValidFrame
** ��������: ������Ч֡
** �䡡  ��: ��
** �䡡  ��: ��
** ȫ�ֱ���: ��
** ����ģ��: ��
** ����  ��: Mr.Sun
** �ա�  ��: 2017.07.12
** -----------------------------------------------------------------------------
** �� �� ��: 
** �޸�����:
** �ա�  ��: 
** ---------------------------------------------------------------------------*/
static void DLT634_5104_SLAVE_SearchValidFrame(BYTE pdrv)
{
      BYTE stop = FALSE;
    struct DLT634_5104SLAVE_PAPCI *pAPCI;
    
    while ((DLT104SlaveLink[pdrv].RxdHead < DLT104SlaveLink[pdrv].RxdTail) && (!stop))
    {
        if (DLT104SlaveLink[pdrv].RxdStatus == RXDSTART)
        {
            if (DLT104SlaveLink[pdrv].RxdBuf[DLT104SlaveLink[pdrv].RxdHead] != DLT634_5104SLAVE_STARTCODE68)
            {
                DLT104SlaveLink[pdrv].RxdHead++;
                continue;
            }
            
            // �ҵ���������õĻ���������
            if (DLT104SlaveLink[pdrv].RxdTail > DLT104SlaveLink[pdrv].RxdHead)
            {
                DLT104SlaveLink[pdrv].RxdLength = DLT104SlaveLink[pdrv].RxdTail - DLT104SlaveLink[pdrv].RxdHead;
                memcpy (DLT104SlaveLink[pdrv].RxdBuf, &DLT104SlaveLink[pdrv].RxdBuf[DLT104SlaveLink[pdrv].RxdHead], DLT104SlaveLink[pdrv].RxdLength);
                DLT104SlaveLink[pdrv].RxdHead = 0;
                DLT104SlaveLink[pdrv].RxdTail = DLT104SlaveLink[pdrv].RxdLength;
            }

            DLT104SlaveLink[pdrv].RxdStatus = RXDHEAD;
        }
            
        if (DLT104SlaveLink[pdrv].RxdStatus == RXDHEAD)
        {
            pAPCI = (struct DLT634_5104SLAVE_PAPCI*)DLT104SlaveLink[pdrv].RxdBuf;
            if (DLT104SlaveLink[pdrv].RxdLength >= sizeof (struct DLT634_5104SLAVE_PAPCI))
            {
                switch (pAPCI->NS & DLT634_5104SLAVE_U_FRAME)
                {
                    case DLT634_5104SLAVE_S_FRAME:
                        if (pAPCI->Length == 4)
                        {
                            DLT634_5104_SLAVE_KillTimer(pdrv, 1);
                            DLT634_5104_SLAVE_SetTimer(pdrv, 3);
                            DLT634_5104_SLAVE_DecodeSFrame(pdrv);
                        }
                        break;
                
                    case DLT634_5104SLAVE_U_FRAME:
                        if (pAPCI->Length == 4)
                        {
                            DLT634_5104_SLAVE_KillTimer(pdrv, 1);
                            DLT634_5104_SLAVE_SetTimer(pdrv, 3);
                            DLT634_5104_SLAVE_DecodeUFrame(pdrv);
                        }
                        break;
                        
                    default:
                        if ((DLT104SlaveLink[pdrv].RxdLength >= (pAPCI->Length + 2)))
                        {
                            DLT634_5104_SLAVE_DecodeIFrame(pdrv);
                        }
                        else
                        {
                            stop = TRUE;
                        }
                        break;
                }
            }
            else
            {
                stop = TRUE;
            }
            
            if (!stop)
            {
                DLT104SlaveLink[pdrv].RxdStatus = RXDCONTINUE;
            }
        }
            
        if (DLT104SlaveLink[pdrv].RxdStatus == RXDCONTINUE)
        {
            DLT104SlaveLink[pdrv].RxdLength = DLT104SlaveLink[pdrv].RxdTail - (pAPCI->Length + 2);
            memcpy (DLT104SlaveLink[pdrv].RxdBuf, &DLT104SlaveLink[pdrv].RxdBuf[pAPCI->Length + 2], DLT104SlaveLink[pdrv].RxdLength);
            DLT104SlaveLink[pdrv].RxdHead = 0;
            DLT104SlaveLink[pdrv].RxdTail = DLT104SlaveLink[pdrv].RxdLength;
            DLT104SlaveLink[pdrv].RxdStatus = RXDSTART;
        
            if (DLT104SlaveLink[pdrv].RxdTail > DLT104SlaveLink[pdrv].RxdHead)
            {
                stop = TRUE;
            }
        }    
    }
}

/* PUBLIC FUNCTION PROTOTYPES ------------------------------------------------*/

BYTE DLT634_5104_SLAVE_Reply(BYTE pdrv, BYTE *pbuf) //�ظ�
{ 
        BYTE res;
      memcpy(&DLT104SlaveApp[pdrv].ST_Temp, pbuf, DLT634_5104SLAVE_LPDUSIZE);
        switch (DLT104SlaveApp[pdrv].ST_Temp.Head.TypeID)
      {
              //���Ʒ��������Ϣ
              case DLT634_5104SLAVE_C_SC_NA_1: // ����ң������
              case DLT634_5104SLAVE_C_SC_NB_1: // ˫��ң������
                     DLT104SlaveApp[pdrv].ST_Temp.status.symbol.priority = DLT634_5104SLAVE_C_SC_NA_P;
                    res = DLT634_5104_SLAVE_StoreIN(pdrv,&DLT104SlaveApp[pdrv].ST_Temp);
                      break;

              case DLT634_5104SLAVE_C_CS_NA_1: // ��ʱ����
                    DLT104SlaveApp[pdrv].ST_Temp.status.symbol.priority = DLT634_5104SLAVE_C_CS_NA_P;
                    res = DLT634_5104_SLAVE_StoreIN(pdrv,&DLT104SlaveApp[pdrv].ST_Temp);
                    break;

              case DLT634_5104SLAVE_C_RP_NA_1: // ��λ��������
                      break;
            
              case DLT634_5104SLAVE_C_RR_NA_1: // ����ֵ����
              case DLT634_5104SLAVE_C_RS_NA_1: // �������Ͷ�ֵ����
                    DLT104SlaveApp[pdrv].ST_Temp.status.symbol.priority = DLT634_5104SLAVE_C_IC_NA_P;
                    res = DLT634_5104_SLAVE_StoreIN(pdrv,&DLT104SlaveApp[pdrv].ST_Temp);
                      break;
            
              case DLT634_5104SLAVE_C_SR_NA_1: // �л���ֵ��
              case DLT634_5104SLAVE_C_WS_NA_1: // д�����Ͷ�ֵ����
                    DLT104SlaveApp[pdrv].ST_Temp.status.symbol.priority = DLT634_5104SLAVE_C_SC_NA_P;
                    res = DLT634_5104_SLAVE_StoreIN(pdrv,&DLT104SlaveApp[pdrv].ST_Temp);
                      break;

              case DLT634_5104SLAVE_F_FR_NA_1: // �ļ�����
                    DLT104SlaveApp[pdrv].ST_Temp.status.symbol.priority = DLT634_5104SLAVE_F_FW_NA_P;
                    res = DLT634_5104_SLAVE_StoreIN(pdrv,&DLT104SlaveApp[pdrv].ST_Temp);
                      break;

              case DLT634_5104SLAVE_F_SR_NA_1: // �������
                      break;            

              default: // ���ͱ�ʶ�д����֧��
                      break;
      }
        return(res);
}

/* -----------------------------------------------------------------------------
** ��������: AllDataConfReply
** ��������: ���ٻ�ȷ��
** �䡡  ��: ��
** �䡡  ��: ��
** ȫ�ֱ���: ��
** ����ģ��: ��
** ����  ��: Mr.Sun
** �ա�  ��: 2017.07.13
** -----------------------------------------------------------------------------
** �� �� ��: 
** �޸�����:
** �ա�  ��: 
** ---------------------------------------------------------------------------*/
static void DLT634_5104_SLAVE_AllDataConfReply(BYTE pdrv)
{
        DLT104SlaveApp[pdrv].TX_Temp.status.Length = sizeof(DLT104SlaveApp[pdrv].TX_Temp.status) + sizeof(DLT104SlaveApp[pdrv].TX_Temp.Head) + sizeof(DLT104SlaveApp[pdrv].TX_Temp.Data.C_100);
        DLT104SlaveApp[pdrv].TX_Temp.status.symbol.priority = DLT634_5104SLAVE_C_IC_NA_PF;
        DLT104SlaveApp[pdrv].TX_Temp.Head.TypeID = DLT634_5104SLAVE_C_IC_NA_1; 
        DLT104SlaveApp[pdrv].TX_Temp.Head.VSQ = 1;
        DLT104SlaveApp[pdrv].TX_Temp.Head.COT_L = DLT634_5104SLAVE_COT_ACTCON;
        DLT104SlaveApp[pdrv].TX_Temp.Head.PubAddr_H = (BYTE)((DLT634_5104Slave_Pad[pdrv].PubAddress>>8)&0xff);
        DLT104SlaveApp[pdrv].TX_Temp.Head.PubAddr_L = (BYTE)(DLT634_5104Slave_Pad[pdrv].PubAddress&0xff);
        DLT104SlaveApp[pdrv].TX_Temp.Data.C_100.InfoAddr_L = 0;  
        DLT104SlaveApp[pdrv].TX_Temp.Data.C_100.QOI = 20;  
}

/* -----------------------------------------------------------------------------
** ��������: AllDataEndReply
** ��������: ���ٻ�����
** �䡡  ��: ��
** �䡡  ��: ��
** ȫ�ֱ���: ��
** ����ģ��: ��
** ����  ��: Mr.Sun
** �ա�  ��: 2017.07.13
** -----------------------------------------------------------------------------
** �� �� ��: 
** �޸�����:
** �ա�  ��: 
** ---------------------------------------------------------------------------*/
static void DLT634_5104_SLAVE_AllDataEndReply(BYTE pdrv)
{
        DLT104SlaveApp[pdrv].TX_Temp.status.Length = sizeof(DLT104SlaveApp[pdrv].TX_Temp.status) + sizeof(DLT104SlaveApp[pdrv].TX_Temp.Head) + sizeof(DLT104SlaveApp[pdrv].TX_Temp.Data.C_100);
        DLT104SlaveApp[pdrv].TX_Temp.status.symbol.priority = DLT634_5104SLAVE_C_IC_NA_PF;
        DLT104SlaveApp[pdrv].TX_Temp.Head.TypeID = DLT634_5104SLAVE_C_IC_NA_1;
        DLT104SlaveApp[pdrv].TX_Temp.Head.VSQ = 1;
        DLT104SlaveApp[pdrv].TX_Temp.Head.COT_L = DLT634_5104SLAVE_COT_ACCTTERM;
        DLT104SlaveApp[pdrv].TX_Temp.Head.PubAddr_H = (BYTE)((DLT634_5104Slave_Pad[pdrv].PubAddress>>8)&0xff);
        DLT104SlaveApp[pdrv].TX_Temp.Head.PubAddr_L = (BYTE)(DLT634_5104Slave_Pad[pdrv].PubAddress&0xff);
        DLT104SlaveApp[pdrv].TX_Temp.Data.C_100.QOI = 20;    
}

/* -----------------------------------------------------------------------------
** ��������: DLT634_5104_SLAVE_LinkSendProcess
** ��������: ��·�㷢�ʹ���
** �䡡  ��: BYTE* pData������������ʼ��ַ.
**           BYTE Len   ���������ݳ���
** �䡡  ��: ��
** ȫ�ֱ���: ��
** ����ģ��: ��
** ����  ��: Mr.Lee
** �ա�  ��: 2016.10.25
** -----------------------------------------------------------------------------
** �� �� ��: 
** �޸�����:
** �ա�  ��: 
** ---------------------------------------------------------------------------*/
void DLT634_5104_SLAVE_LinkSendProcess(BYTE pdrv, BYTE* pData, BYTE Len)
{
    struct DLT634_5104SLAVE_PAPCI *pFrame;
    
    pFrame = (struct DLT634_5104SLAVE_PAPCI*)&DLT104SlaveLink[pdrv].TxdBuf[DLT104SlaveLink[pdrv].TxdHead];
    
    if (Len == 0 || DLT104SlaveLink[pdrv].StopSendFlag)
    {
        return;
    }
    DLT104SlaveLink[pdrv].NRACK = DLT104SlaveLink[pdrv].NR;
        
    pFrame->StartCode = DLT634_5104SLAVE_STARTCODE68;
    pFrame->Length = Len + 0x04;
    pFrame->NS = DLT104SlaveLink[pdrv].NS << 1;
    pFrame->NR = DLT104SlaveLink[pdrv].NR << 1;
    memcpy((BYTE*)(pFrame+1), pData, Len);
    DLT104SlaveLink[pdrv].TxdTail += Len + 0x06;        

    DLT104SlaveLink[pdrv].DataType[DLT104SlaveLink[pdrv].PeerNoAckNum] = TRUE;
    DLT104SlaveLink[pdrv].PeerNoAckNum++;
    DLT104SlaveLink[pdrv].NS++;
        
        if (DLT104SlaveLink[pdrv].PeerNoAckNum >= DLT634_5104SLAVE_K) // δ��ȷ�ϵ�I֡�����ﵽK��ʱ  ֹͣ����
        {
            DLT104SlaveLink[pdrv].StopSendFlag = TRUE;
        }
    // ����
    DLT634_5104_SLAVE_KillTimer(pdrv, 2);
    DLT634_5104_SLAVE_SetTimer(pdrv, 3);
    DLT634_5104_SLAVE_WriteDataToMISI(pdrv);
    DLT634_5104_SLAVE_SetTimer(pdrv, 1); //         
        
}

/* -----------------------------------------------------------------------------
** ��������: ReadAllDataProcess
** ��������: ���ٻ��������
** �䡡  ��: ��
** �䡡  ��: ��
** ȫ�ֱ���: ��
** ����ģ��: ��
** ����  ��: Mr.Sun
** �ա�  ��: 2017.07.13
** -----------------------------------------------------------------------------
** �� �� ��: 
** �޸�����:
** �ա�  ��: 
** ---------------------------------------------------------------------------*/
void ReadAllDataProcess(BYTE pdrv)
{
      static BYTE group;
      static BYTE YX_group;
      static BYTE YC_group;
    
      switch (DLT104SlaveApp[pdrv].AllDataFlag)
      {
              case 0:
                      DLT634_5104_SLAVE_AllDataConfReply(pdrv);
                      group = 0;
                      YX_group = (DLT634_5104Slave_Pad[pdrv].YX_AllNum % DLT634_5104Slave_Pad[pdrv].YX_FrameNum) ? \
                                 (DLT634_5104Slave_Pad[pdrv].YX_AllNum / DLT634_5104Slave_Pad[pdrv].YX_FrameNum + 1) : (DLT634_5104Slave_Pad[pdrv].YX_AllNum/DLT634_5104Slave_Pad[pdrv].YX_FrameNum);
                      YC_group = (DLT634_5104Slave_Pad[pdrv].YC_AllNum % DLT634_5104Slave_Pad[pdrv].YC_FrameNum) ? \
                                     (DLT634_5104Slave_Pad[pdrv].YC_AllNum / DLT634_5104Slave_Pad[pdrv].YC_FrameNum + 1) : (DLT634_5104Slave_Pad[pdrv].YC_AllNum/DLT634_5104Slave_Pad[pdrv].YC_FrameNum);
                      DLT104SlaveApp[pdrv].AllDataFlag = 1;
                     break;
              case 1:
                      if (DLT634_5104Slave_Pad[pdrv].YX_AllNum / DLT634_5104Slave_Pad[pdrv].YX_FrameNum > group)
                      {
                            DLT634_5104_SLAVE_ReadYxData(pdrv ,DLT634_5104Slave_Pad[pdrv].YX_FrameNum*group + DLT634_5104Slave_Pad[pdrv].YX_FirstAddr, \
                                                    DLT634_5104Slave_Pad[pdrv].YX_FrameNum, 
                                                    (BYTE *)&DLT104SlaveApp[pdrv].TX_Temp);
                      }
                      else
                      {
                            DLT634_5104_SLAVE_ReadYxData(pdrv, DLT634_5104Slave_Pad[pdrv].YX_FrameNum*group + DLT634_5104Slave_Pad[pdrv].YX_FirstAddr, \
                                                   DLT634_5104Slave_Pad[pdrv].YX_AllNum - group * DLT634_5104Slave_Pad[pdrv].YX_FrameNum, \
                                                    (BYTE *)&DLT104SlaveApp[pdrv].TX_Temp);
                      }
                      if (++group >= YX_group)
                      {      
                             DLT104SlaveApp[pdrv].AllDataFlag = 2;
                            group = 0;
                      }
                    break;
              case 2:
                      if (DLT634_5104Slave_Pad[pdrv].YC_AllNum/DLT634_5104Slave_Pad[pdrv].YC_FrameNum > group)
                      {
                            DLT634_5104_SLAVE_ReadYcData(pdrv, DLT634_5104Slave_Pad[pdrv].YC_FrameNum*group + DLT634_5104Slave_Pad[pdrv].YC_FirstAddr, \
                                                   DLT634_5104Slave_Pad[pdrv].YC_FrameNum, \
                                                    (BYTE *)&DLT104SlaveApp[pdrv].TX_Temp);
                      }
                      else
                      {
                             DLT634_5104_SLAVE_ReadYcData(pdrv ,DLT634_5104Slave_Pad[pdrv].YC_FrameNum*group + DLT634_5104Slave_Pad[pdrv].YC_FirstAddr, \
                                                 DLT634_5104Slave_Pad[pdrv].YC_AllNum - group * DLT634_5104Slave_Pad[pdrv].YC_FrameNum, \
                                                    (BYTE *)&DLT104SlaveApp[pdrv].TX_Temp);
                      }
                
                      if (++group >= YC_group)
                      {
                            DLT104SlaveApp[pdrv].AllDataFlag = 3;
                            group = 0;
                      }
                    break;
              case 3:
                      DLT634_5104_SLAVE_AllDataEndReply(pdrv);
                      DLT104SlaveApp[pdrv].Data1Flag &= (~DLT634_5104SLAVE_CALLALLDATA);
                     break;
              default:
                    break;    
    }   
}

/* -----------------------------------------------------------------------------
** ��������: ReadData1Process
** ��������: ����һ������
** �䡡  ��: ��
** �䡡  ��: ��
** ȫ�ֱ���: ��
** ����ģ��: ��
** ����  ��: Mr.Sun
** �ա�  ��: 2017.07.13
** -----------------------------------------------------------------------------
** �� �� ��: 
** �޸�����:
** �ա�  ��: 
** ---------------------------------------------------------------------------*/
void ReadData1Process(BYTE pdrv)
{
        if ((DLT634_5104_SLAVE_H_SOE(pdrv))&&
            ((DLT104SlaveApp[pdrv].StoreDATA1IN->status.symbol.priority > DLT634_5104SLAVE_M_SP_TB_P)||
            (DLT104SlaveApp[pdrv].StoreDATA1IN->status.symbol.priority == 0))) 
        {
            DLT634_5104_SLAVE_R_SOE(pdrv,(BYTE *)&DLT104SlaveApp[pdrv].TX_Temp);
            DLT104SlaveApp[pdrv].Data1Flag &= (~DLT634_5104SLAVE_HAVESOE);
            return;
        }
        
    if (DLT104SlaveApp[pdrv].Data1Flag & DLT634_5104SLAVE_CALLALLDATA)
        {
            ReadAllDataProcess(pdrv);
              return;
        }

        if (DLT104SlaveApp[pdrv].StoreDATA1OUT != DLT104SlaveApp[pdrv].StoreDATA1IN)
        {
              memcpy((BYTE *)&DLT104SlaveApp[pdrv].TX_Temp, (BYTE *)DLT104SlaveApp[pdrv].StoreDATA1OUT, DLT104SlaveApp[pdrv].StoreDATA1OUT->status.Length);
              memset((BYTE *)DLT104SlaveApp[pdrv].StoreDATA1OUT,0,sizeof(DLT634_5104SLAVE_PASDU));
              if (++DLT104SlaveApp[pdrv].StoreDATA1OUT >= DLT104SlaveApp[pdrv].StoreDATA1Buf + DLT634_5104SLAVE_STOREDATA1NUM)
              {
                    DLT104SlaveApp[pdrv].StoreDATA1OUT = DLT104SlaveApp[pdrv].StoreDATA1Buf;
              }
              return;
        }        
}

/* -----------------------------------------------------------------------------
** ��������: ReadData2Process
** ��������: ����һ������
** �䡡  ��: ��
** �䡡  ��: ��
** ȫ�ֱ���: ��
** ����ģ��: ��
** ����  ��: Mr.Sun
** �ա�  ��: 2017.07.13
** -----------------------------------------------------------------------------
** �� �� ��: 
** �޸�����:
** �ա�  ��: 
** ---------------------------------------------------------------------------*/
void ReadData2Process(BYTE pdrv)
{
        if ((DLT634_5104_SLAVE_H_NVA(pdrv))&&
            ((DLT104SlaveApp[pdrv].StoreDATA2IN->status.symbol.priority > DLT634_5104SLAVE_M_ME_NC_P)||
            (DLT104SlaveApp[pdrv].StoreDATA2IN->status.symbol.priority == 0))) 
        {
            DLT634_5104_SLAVE_R_NVA(pdrv,(BYTE *)&DLT104SlaveApp[pdrv].TX_Temp);
            return;
        }
        
        if ((DLT634_5104_SLAVE_H_FEvent(pdrv))&&
            ((DLT104SlaveApp[pdrv].StoreDATA2IN->status.symbol.priority > DLT634_5104SLAVE_M_FT_NA_P)||
            (DLT104SlaveApp[pdrv].StoreDATA2IN->status.symbol.priority == 0))) 
        {
            DLT634_5104_SLAVE_R_FEvent(pdrv,(BYTE *)&DLT104SlaveApp[pdrv].TX_Temp);
            return;
        }

        if (DLT104SlaveApp[pdrv].StoreDATA2OUT != DLT104SlaveApp[pdrv].StoreDATA2IN)
        {
              memcpy((BYTE *)&DLT104SlaveApp[pdrv].TX_Temp, (BYTE *)DLT104SlaveApp[pdrv].StoreDATA2OUT, DLT104SlaveApp[pdrv].StoreDATA2OUT->status.Length);
              memset((BYTE *)DLT104SlaveApp[pdrv].StoreDATA2OUT,0,sizeof(DLT634_5104SLAVE_PASDU));
              if (++DLT104SlaveApp[pdrv].StoreDATA2OUT >= DLT104SlaveApp[pdrv].StoreDATA2Buf + DLT634_5104SLAVE_STOREDATA2NUM)
              {
                    DLT104SlaveApp[pdrv].StoreDATA2OUT = DLT104SlaveApp[pdrv].StoreDATA2Buf;
              }
              return;
        }    
}

/* -----------------------------------------------------------------------------
** ��������: DLT634_5104_NetTest
** ��������: ��������״̬�жϡ�
** �䡡  ��: PORT_Type pdrv���ӿ�����.
** �䡡  ��: ��
** ȫ�ֱ���: ��
** ����ģ��: ��
** ����  ��: Mr.Lee
** �ա�  ��: 2016.10.25
** -----------------------------------------------------------------------------
** �� �� ��: 
** �޸�����:
** �ա�  ��: 
** ---------------------------------------------------------------------------*/
void DLT634_5104_SLAVE_NetTest(BYTE pdrv)
{
  //#if (PHY_LAN8720_CFG || PHY_ENC28J60_CFG)  
    
    if (!DLT634_5104_SLAVE_CheckLink(pdrv))//�Ƿ�����
    {            
        DLT634_5104_AppInitReset(pdrv);                
        DLT104SlaveApp[pdrv].Connect = FALSE;
              DLT104SlaveLink[pdrv].Connect = FALSE;
    }
    else if (!DLT104SlaveLink[pdrv].Connect)
    {
        // DLT634_5104_AppInitReset(pdrv);                
        DLT104SlaveLink[pdrv].Connect = TRUE;
    }
  //#endif /* END PHY_LAN8720_CFG || PHY_ENC28J60_CFG */
}

/* -----------------------------------------------------------------------------
** ��������: DLT634_5104_AppInit
** ��������: Ӧ�ò��ʼ��.
** �䡡  ��: ��
** �䡡  ��: ��
** ȫ�ֱ���: ��
** ����ģ��: ��
** ����  ��: Mr.Lee
** �ա�  ��: 2016.10.25
** -----------------------------------------------------------------------------
** �� �� ��:                                              
** �޸�����:
** �ա�  ��: 
** ---------------------------------------------------------------------------*/
BYTE DLT634_5104_SLAVE_AppInit(BYTE pdrv)
{
      memset (&DLT104SlaveApp[pdrv], 0, sizeof (struct DLT634_5104SLAVE_APPINFO));
    
      DLT104SlaveApp[pdrv].YXTypeID = DLT634_5104SLAVE_M_SP_NA_1;
    DLT104SlaveApp[pdrv].YCTypeID = DLT634_5104SLAVE_M_ME_NC_1;
      DLT634_5104_AppInitReset(pdrv);
      
      return(TRUE);
}


void DLT634_5104_SLAVE_SendProcess(BYTE pdrv)
{
    ReadData1Process(pdrv);    

        if (DLT104SlaveApp[pdrv].TX_Temp.status.Length)
        {
              DLT104SlaveApp[pdrv].TxLen = DLT104SlaveApp[pdrv].TX_Temp.status.Length - sizeof(DLT104SlaveApp[pdrv].TX_Temp.status);        
              memcpy(&DLT104SlaveApp[pdrv].TxMsg, &DLT104SlaveApp[pdrv].TX_Temp.Head, DLT104SlaveApp[pdrv].TxLen); 
       DLT634_5104_SLAVE_LinkSendProcess(pdrv, (BYTE*)&DLT104SlaveApp[pdrv].TxMsg, DLT104SlaveApp[pdrv].TxLen);        
                memset((BYTE *)&DLT104SlaveApp[pdrv].TX_Temp, 0, sizeof(DLT634_5104SLAVE_PASDU));            
        }    
    else
        {
            ReadData2Process(pdrv);
            if (DLT104SlaveApp[pdrv].TX_Temp.status.Length)
            {
                  DLT104SlaveApp[pdrv].TxLen = DLT104SlaveApp[pdrv].TX_Temp.status.Length - sizeof(DLT104SlaveApp[pdrv].TX_Temp.status);        
                  memcpy(&DLT104SlaveApp[pdrv].TxMsg, &DLT104SlaveApp[pdrv].TX_Temp.Head, DLT104SlaveApp[pdrv].TxLen); 
            DLT634_5104_SLAVE_LinkSendProcess(pdrv, (BYTE*)&DLT104SlaveApp[pdrv].TxMsg, DLT104SlaveApp[pdrv].TxLen);        
                    memset((BYTE *)&DLT104SlaveApp[pdrv].TX_Temp, 0, sizeof(DLT634_5104SLAVE_PASDU));            
            }                
        }
}

/* -----------------------------------------------------------------------------
** ��������: DLT634_5104_LinkOnTimer
** ��������: ��·�㶨ʱ����
** �䡡  ��: ��
** �䡡  ��: ��
** ȫ�ֱ���: ��
** ����ģ��: ��
** ����  ��: Mr.Lee
** �ա�  ��: 2016.10.25
** -----------------------------------------------------------------------------
** �� �� ��: 
** �޸�����:
** �ա�  ��: 
** ---------------------------------------------------------------------------*/
void DLT634_5104_SLAVE_LinkOnTimer(BYTE pdrv)
{
    BYTE    i = 0;
        
    if (DLT104SlaveLink[pdrv].Tick.Flag & DLT634_5104SLAVE_T0FLAG)
    {
        DLT104SlaveLink[pdrv].Tick.TValue0++;

        if (DLT104SlaveLink[pdrv].Tick.TValue0 > DLT634_5104Slave_Pad[pdrv].TickValue[0])
        {
            DLT634_5104_SLAVE_KillTimer(pdrv, 0);
            DLT634_5104_SLAVE_StopDTOper(pdrv);
        }
    }

    if (DLT104SlaveLink[pdrv].Tick.Flag & DLT634_5104SLAVE_T1FLAG)
    {
        for (i=0; i<DLT104SlaveLink[pdrv].PeerNoAckNum; i++)
        {
            DLT104SlaveLink[pdrv].Tick.TValue1[i]++;

            if (DLT104SlaveLink[pdrv].Tick.TValue1[i] > DLT634_5104Slave_Pad[pdrv].TickValue[1])
            {
                DLT634_5104_SLAVE_KillTimer(pdrv, 1);
                DLT634_5104_SLAVE_StopDTOper(pdrv);
            }
        }
    }
    
    if (DLT104SlaveLink[pdrv].Tick.Flag & DLT634_5104SLAVE_T2FLAG)
    {
        DLT104SlaveLink[pdrv].Tick.TValue2++;

        if ( DLT104SlaveLink[pdrv].Tick.TValue2 > DLT634_5104Slave_Pad[pdrv].TickValue[2] )
        {
            DLT634_5104_SLAVE_KillTimer(pdrv, 2);
            DLT634_5104_SLAVE_S104SendCtrlFrame(pdrv, DLT634_5104SLAVE_S_FRAME);
        }
    }
    
    if (DLT104SlaveLink[pdrv].Tick.Flag & DLT634_5104SLAVE_T3FLAG)
    {
        DLT104SlaveLink[pdrv].Tick.TValue3++;

        if (DLT104SlaveLink[pdrv].Tick.TValue3 > DLT634_5104Slave_Pad[pdrv].TickValue[3])
        {
            DLT634_5104_SLAVE_KillTimer(pdrv, 3);
            
            if (DLT104SlaveLink[pdrv].PeerNoAckNum)
            {
                DLT634_5104_SLAVE_S104SendCtrlFrame(pdrv, DLT634_5104SLAVE_U_TESTFRACT);
            }
            else if (!(DLT104SlaveLink[pdrv].Tick.Flag & DLT634_5104SLAVE_T1FLAG))
            {
                DLT634_5104_SLAVE_SetTimer(pdrv, 1);
            }
        }
    }    
}

/* -----------------------------------------------------------------------------
** ��������: DLT634_5104_SLAVE_ReadMISIData
** ��������: ����MISI���ݡ�
** �䡡  ��: PORT_Type pdrv��ͨ�Žӿ����ͣ�
**           BYTE Flag     ���Ƿ�������ݱ�־��
** �䡡  ��: ��
** ȫ�ֱ���: ��
** ����ģ��: ��
** ����  ��: Mr.Lee
** �ա�  ��: 2016.10.25
** -----------------------------------------------------------------------------
** �� �� ��: 
** �޸�����:
** �ա�  ��: 
** ---------------------------------------------------------------------------*/
void DLT634_5104_SLAVE_ReadMISIData(BYTE pdrv, BYTE Flag)
{
    WORD count = 0;
    
      /*��ȡ���ջ�����*/
    count = DLT634_5104_SLAVE_ReadData(pdrv, (BYTE *)&DLT104SlaveLink[pdrv].RxdBuf[DLT104SlaveLink[pdrv].RxdTail], DLT634_5104SLAVE_FRAMEBUFSIZE);    
    
      if (Flag)
    {
        DLT104SlaveLink[pdrv].RxdTail += count;
        DLT104SlaveLink[pdrv].RxdLength += count;
    }
    
    DLT634_5104_SLAVE_SearchValidFrame(pdrv); 
}

void DLT634_5104_SLAVE_Clock(BYTE pdrv)
{
      DLT104SlaveLink[pdrv].ClockCounter++;
      if (DLT104SlaveLink[pdrv].ClockCounter >= DLT634_5104Slave_Pad[pdrv].ClockTimers)
      {
        DLT104SlaveLink[pdrv].ClockCounter = 0;
        // ��ѯMISI���ջ�����
            
        if(!DLT104SlaveApp[pdrv].Connect) // ״̬����
        {
            DLT634_5104_SLAVE_NetTest(pdrv);
            DLT634_5104_SLAVE_ReadMISIData(pdrv, TRUE);
        }
        else
        {
        
            DLT634_5104_SLAVE_ReadMISIData(pdrv, TRUE); // ��·�����ݲ�ѯ

            DLT634_5104_SLAVE_SendProcess(pdrv);    // ��������

            DLT634_5104_SLAVE_LinkOnTimer(pdrv); // ��·�㶨ʱ��

            DLT634_5104_SLAVE_NetTest(pdrv); // �����ж�
        }                    
      }      
}



