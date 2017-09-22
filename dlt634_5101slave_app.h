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
** File name:               dlt634_5101slave_app.h
** Descriptions:            The application layer of DL/T634.5101_2002
**
** -----------------------------------------------------------------------------
** Created by:              Mr.Lee
** Created date:            2015.10.25
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
#ifndef	_DLT634_5101SLAVE_APP_H_
#define _DLT634_5101SLAVE_APP_H_

#ifdef __cplusplus
extern "C"{
#endif

/* INCLUDE FILES -------------------------------------------------------------*/
#include <stdint.h>
#include "dlt634_5101slave_config.h"

#ifndef  FALSE
#define  FALSE     0
#define  TRUE      !FALSE
#endif

/* PUBLIC VARIABLE -----------------------------------------------------------*/

typedef struct 
{
	uint8_t Port;            //�˿�
	uint8_t BalanMode;	    	// 1ƽ�⣬0��ƽ��
	uint8_t IEC_DIR;         // �ն�0x80,��վ0x00
	
	uint8_t SourceAddr;	    // Դ��ַ����������ַ
	
	uint8_t LinkAddrSize;   //��·��ַ����
	uint8_t ASDUCotSize;    //����ԭ�򳤶�
	
	uint8_t ASDUAddr;       //ASDU��ַ
	uint8_t ASDUAddrSize;    //ASDU��ַ����
	uint8_t FixFrmLength;		//�̶�֡����
	
	uint32_t ClockTimers;		//���ó�������������ִ��һ�Σ�������������
	uint32_t TimeOutValue;		//��ʱ�ط����
	uint32_t AskStaOutValue; //��·������
	
	uint16_t YX_AllNum;       //ң������
	uint16_t YX_FIRSTADDR;    //ң���׵�ַ
	uint16_t YX_FrameNum;			//ң��ÿ������
	uint16_t YC_AllNum;				//ң������
	uint16_t YC_FIRSTADDR;    //ң���׵�ַ
	uint16_t YC_FrameNum;			//ң��ÿ������
	
}DLT634_5101SLAVE_PAD;

extern DLT634_5101SLAVE_PAD      DLT634_5101Slave_Pad[_DLT634_5101SLAVE_VOLUMES];

/* PUBLIC FUNCTION DECLARATION -----------------------------------------------*/
extern uint8_t DLT634_5101_SLAVE_REPLY(uint8_t pdrv, uint8_t *pbuf);
extern void DLT634_5101_SLAVE_Clock(uint8_t pdrv);

#ifdef __cplusplus
}
#endif

#endif /* END _DLT634_5101_APP_H_ */
    

/* END OF FILE ---------------------------------------------------------------*/


