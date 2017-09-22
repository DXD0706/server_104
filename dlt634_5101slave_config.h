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
** File name:               dlt634_5101slave_config.h
** Descriptions:            The application layer of DL/T634.5101_2002
**
** -----------------------------------------------------------------------------
** Created by:              Mr.j
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
#ifndef	_DLT634_5101SLAVE_CONFIG_H_
#define _DLT634_5101SLAVE_CONFIG_H_


/* PUBLIC VARIABLE -----------------------------------------------------------*/
enum
{
    DLT634_5101SLAVE_DISK0 = 0,
    _DLT634_5101SLAVE_VOLUMES
};
/* Number of volumes (logical drives) to be used.*/
#define _DLT634_5101SLAVE_LPDUSIZE  256
#define _DLT634_5101SLAVE_STOREDATA1NUM	10
#define _DLT634_5101SLAVE_STOREDATA2NUM	20

#define  _DLT634_5101SLAVE_NUMOF_MAXRETRY                0x03 // Ĭ��DL/T634.5101_2002��Լ��·����������Ӵ���

//LINK_FLAG
#define  _DLT634_5101SLAVE_REQSTATUS                  0x00000001
#define  _DLT634_5101SLAVE_RECONFIRM                  0x00000002
#define  _DLT634_5101SLAVE_ASKSTATUS                  0x00000004
#define  _DLT634_5101SLAVE_ASKRELINK                  0x00000008

#define  _DLT634_5101SLAVE_SENDABLE                  	0x00100000// ƽ��
#define  _DLT634_5101SLAVE_REDATA1                  	0x00400000// ��ƽ��
#define  _DLT634_5101SLAVE_REDATA2                  	0x00800000// ��ƽ��

#define  _DLT634_5101SLAVE_FIRST_ALL_CALLSTART       	0x10000000
#define  _DLT634_5101SLAVE_FIRST_ALL_CALLEND        	0x20000000
#define  _DLT634_5101SLAVE_FIRST_RlaConCode         	0x40000000
#define  _DLT634_5101SLAVE_INITEND                  	0x80000000

//1������״�
#define  _DLT634_5101SLAVE_HAVESTDATA1                0x00000001
#define  _DLT634_5101SLAVE_HAVEINITEND                0x00000002
#define  _DLT634_5101SLAVE_HAVERESET                  0x00000004
#define  _DLT634_5101SLAVE_CALLALLDATA                0x00000010
#define  _DLT634_5101SLAVE_HAVESOE                    0x00000020

/*************************************************************************************************************************************/
//DL/T634.5101_2002��Լ

/* ��·��֡���δ�***************************************************************/
#define  _DLT634_5101SLAVE_STARTCODE10	                     0x10	// ��ʼ��
#define  _DLT634_5101SLAVE_STARTCODE68	                     0x68	// ��ʼ��
#define  _DLT634_5101SLAVE_ENDCODE                           0x16	// ��ֹ��

/* ��·���������************************************************************/
//ǰ4λ
#define  _DLT634_5101SLAVE_FUNCODE                       0x0F // ������
#define  _DLT634_5101SLAVE_FCV                           0x10 // ֡������Чλ 
#define  _DLT634_5101SLAVE_DFC                           0x10 // ����������
#define  _DLT634_5101SLAVE_FCB                           0x20 // ֡����λ
#define  _DLT634_5101SLAVE_ACD                           0x20 // Ҫ�����λ 
#define  _DLT634_5101SLAVE_PRM                           0x40 // ��������λ
#define  _DLT634_5101SLAVE_DIR                           0x80 // ���䷽��λ

//��·����վ����վ���书���붨��
#define   _DLT634_5101SLAVE_M_FUN0             	0           // ��λԶ����·
#define   _DLT634_5101SLAVE_M_FUN2              2           // ������·���� 
#define   _DLT634_5101SLAVE_M_FUN3              3	          // ����ȷ������
#define   _DLT634_5101SLAVE_M_FUN4             	4	          // ���Ͳ�ȷ������
#define   _DLT634_5101SLAVE_M_FUN8              8	          // ������Ӧȷ������״̬
#define   _DLT634_5101SLAVE_M_FUN9             	9	          // �ٻ���·״̬
#define   _DLT634_5101SLAVE_M_FUN10             10	        // �ٻ�1���û����� 
#define   _DLT634_5101SLAVE_M_FUN11             11          // �ٻ�2���û�����

//*��·����վ����վ���书���붨�� 
#define   _DLT634_5101SLAVE_S_FUN0              0            // ȷ��
#define   _DLT634_5101SLAVE_S_FUN1              1            // ȷ����·æδ���ձ���
#define   _DLT634_5101SLAVE_S_FUN8              8            // ��������Ӧ����֡
#define   _DLT634_5101SLAVE_S_FUN9              9            // �����ٻ�������
#define   _DLT634_5101SLAVE_S_FUN11             11           // ��Ӧ��·״̬��ش�����֡
 
/* TI���ͱ�ʶ ********************************************************************************/ 
//���ӷ��������Ϣ
#define   _DLT634_5101SLAVE_M_SP_NA_1              1            // ������Ϣ
#define   _DLT634_5101SLAVE_M_DP_NA_1              3            // ˫����Ϣ
#define   _DLT634_5101SLAVE_M_ME_NA_1              9            // ����ֵ����һ��ֵ
#define   _DLT634_5101SLAVE_M_ME_NB_1              11           // ����ֵ����Ȼ�ֵ
#define   _DLT634_5101SLAVE_M_ME_NC_1              13           // ����ֵ���̸�����
#define   _DLT634_5101SLAVE_M_SP_TB_1              30           // ��ʱ��ĵ�����Ϣ
#define   _DLT634_5101SLAVE_M_DP_TB_1              31           // ��ʱ���˫����Ϣ
#define   _DLT634_5101SLAVE_M_FT_NA_1              42           // �����¼���Ϣ
#define   _DLT634_5101SLAVE_M_IT_NB_1              206          // �ۼ������̸�����
#define   _DLT634_5101SLAVE_M_IT_TC_1              207          // ��ʱ���ۼ������̸�����

//���Ʒ��������Ϣ
#define   _DLT634_5101SLAVE_C_SC_NA_1              45            // ��������
#define   _DLT634_5101SLAVE_C_SC_NB_1              46            // ˫������

//���ӷ����ϵͳ����
#define   _DLT634_5101SLAVE_M_EI_NA_1              70            // ��ʼ������

//���Ʒ����ϵͳ����
#define   _DLT634_5101SLAVE_C_IC_NA_1              100            // վ���ٻ�����
#define   _DLT634_5101SLAVE_C_CI_NA_1              101            // �������ٻ�����
#define   _DLT634_5101SLAVE_C_CS_NA_1              103            // ʱ��ͬ������
#define   _DLT634_5101SLAVE_C_TS_NA_1              104            // ��������
#define   _DLT634_5101SLAVE_C_RP_NA_1              105            // ��λ��������
#define   _DLT634_5101SLAVE_C_SR_NA_1              200            // �л���ֵ��
#define   _DLT634_5101SLAVE_C_RR_NA_1              201            // ����ֵ����
#define   _DLT634_5101SLAVE_C_RS_NA_1              202            // �������Ͷ�ֵ
#define   _DLT634_5101SLAVE_C_WS_NA_1              203            // д�����Ͷ�ֵ
#define   _DLT634_5101SLAVE_F_FR_NA_1              210            // �ļ�����
#define   _DLT634_5101SLAVE_F_SR_NA_1              211            // �������

/* COT����ԭ�� ********************************************************************************/ 
#define   _DLT634_5101SLAVE_COT_CYC              1            // ����ѭ��
#define   _DLT634_5101SLAVE_COT_BACK             2            // ����ɨ��
#define   _DLT634_5101SLAVE_COT_SPONT            3            // ͻ��
#define   _DLT634_5101SLAVE_COT_INIT             4            // ��ʼ��
#define   _DLT634_5101SLAVE_COT_REQ              5            // ���������
#define   _DLT634_5101SLAVE_COT_ACT              6            // ����
#define   _DLT634_5101SLAVE_COT_ACTCON           7            // ����ȷ��
#define   _DLT634_5101SLAVE_COT_DEACT            8            // ֹͣ����
#define   _DLT634_5101SLAVE_COT_DEACTCON         9            // ֹͣ����ȷ��
#define   _DLT634_5101SLAVE_COT_ACCTTERM         10            // ������ֹ
#define   _DLT634_5101SLAVE_COT_FILE             13            // �ļ�����
#define   _DLT634_5101SLAVE_COT_INTROGEN         20            // ��Ӧվ�ٻ�
#define   _DLT634_5101SLAVE_COT_REQCOGEN         37            // ��Ӧ�����ٻ�

/* �������ȼ� ********************************************************************************/
//1������
#define   _DLT634_5101SLAVE_M_EI_NA_P              1            // ��ʼ������
#define   _DLT634_5101SLAVE_C_IC_NA_PF             2            // վ���ٻ�����
#define   _DLT634_5101SLAVE_C_SC_NA_P              3            // ��������,��ֵ����
#define   _DLT634_5101SLAVE_M_SP_TB_P              4           // ��ʱ��ĵ�����Ϣ
#define   _DLT634_5101SLAVE_C_IC_NA_P              5            // վ���ٻ������ֵ�ٻ�

//2������
#define   _DLT634_5101SLAVE_M_FT_NA_P              0x81           // �����¼���Ϣ
#define   _DLT634_5101SLAVE_C_CS_NA_P              0x82            // ʱ��ͬ������
#define   _DLT634_5101SLAVE_C_TS_NA_P              0x83            // ��������
#define   _DLT634_5101SLAVE_M_ME_NC_P              0x84           // ����ֵ���̸�����
#define   _DLT634_5101SLAVE_C_RP_NA_P              0x85            // ��λ��������
#define   _DLT634_5101SLAVE_F_FR_NA_P              0x86            // �ļ��ٻ�
#define   _DLT634_5101SLAVE_F_FW_NA_P              0x87            // �ļ�����
#define   _DLT634_5101SLAVE_C_CI_NA_P              0x88            // �������ٻ�����

#endif /* END _DLT634_5101_APP_H_ */
    

/* END OF FILE ---------------------------------------------------------------*/
