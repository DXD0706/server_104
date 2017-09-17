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
** File name:               dlt634_5104slave_link.h
** Descriptions:            The application layer of DL/T634.5104_2002
**
** -----------------------------------------------------------------------------
** Created by:              Mr.Sun
** Created date:            2017.07.11
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
#ifndef    _DLT634_5104SLAVE_LINK_H_
#define _DLT634_5104SLAVE_LINK_H_

#ifdef __cplusplus
extern "C"{
#endif


/* INCLUDE FILES -------------------------------------------------------------*/
#include "integer.h"
#include "dlt634_5104slave_config.h"

#ifndef  FALSE
#define  FALSE     0
#define  TRUE      !FALSE
#endif

/* PUBLIC VARIABLE -----------------------------------------------------------*/

/* DEFINE --------------------------------------------------------------------*/

/* ��·�����״̬ */

/* Struct  -------------------------------------------------------------------*/
struct DLT634_5104SLAVE_AppMsg
{
    unsigned short Cmd;
    unsigned short ConNum;
    unsigned char Len;
    unsigned char* pData;
};

struct DLT634_5104SLAVE_PAD
{
    unsigned char   Port;            //�˿�
    
    unsigned char   CotSize;      // ����ԭ���ֽڳ���
    unsigned char   PubAddrSize;  // ��·������ַ�ֽڳ���
    unsigned char   LinkAddrSize; // ��·��ַռ���ֽ�  
    unsigned char   InfoAddrSize; // ��Ϣ���ַ�ֽڳ���

    unsigned short  YCNum;        // ң��������
    unsigned short  YXNum;        // ң��������
    unsigned short  YKNum;        // ң��������
    unsigned short  DDNum;        // ���������

    unsigned short  LinkAddress;  // ��·��ַ,��·��ַ���빫����ַ��ͬ
    unsigned short  PubAddress;   // ������ַ��������·��ַ��ͬ������ͬһ��·�ϵ��豸(��վ)��ַ

    unsigned short  YX_AllNum;    // ң������
    unsigned short  YX_FirstAddr; // ң���׵�ַ
    unsigned short  YX_FrameNum;    // ң��ÿ������
    unsigned short  YC_AllNum;        // ң������
    unsigned short  YC_FirstAddr; // ң���׵�ַ
    unsigned short  YC_FrameNum;  // ң��ÿ������
    
    unsigned short  TickValue[4]; // IEC104 4����ʱʱ��
    unsigned long   ClockTimers;  // ���ó�������������ִ��һ�Σ�������������
};
/* PUBLIC VARIABLES ----------------------------------------------------------*/
extern struct DLT634_5104SLAVE_PAD DLT634_5104Slave_Pad[DLT634_5104SLAVE_VOLUMES]; // DL/T634_5101��Լ����

/* PUBLIC FUNCTION DECLARATION -----------------------------------------------*/
extern void DLT634_5104_SLAVE_Clock(BYTE port);
extern BYTE DLT634_5104_SLAVE_AppInit(BYTE port);
extern void DLT634_5104_SLAVE_ParaInit(BYTE port);
extern BYTE DLT634_5104_SLAVE_Reply(BYTE pdrv, BYTE *pbuf);

#ifdef __cplusplus
}
#endif

#endif /* END _DLT634_5104SLAVE_LINK_H_*/

/* END OF FILE ---------------------------------------------------------------*/


