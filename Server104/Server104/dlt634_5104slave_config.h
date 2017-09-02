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
** File name:               dlt634_5104slave_config.h
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
#ifndef	_DLT634_5104SLAVE_CONFIG_H_
#define _DLT634_5104SLAVE_CONFIG_H_


/* PUBLIC VARIABLE -----------------------------------------------------------*/
#define  DLT634_5104SLAVE_VOLUMES	 2   // �豸����
/* Number of volumes (logical drives) to be used.*/
#define  DLT634_5104SLAVE_STOREDATA1NUM	10
#define  DLT634_5104SLAVE_STOREDATA2NUM	10

//LINK_FLAG
// EVENT
#define  DLT634_5104SLAVE_DLFLAG                     0x00000020
#define  DLT634_5104SLAVE_APPFLAG                    0x00000040
#define  DLT634_5104SLAVE_APPTIMEFLAG                0x00000080
#define  DLT634_5104SLAVE_SCHEDULE                   0x00000002
#define  DLT634_5104SLAVE_NEXTFRAME                  0x00000001
#define  DLT634_5104SLAVE_SENDOVER                   0x00000004

/* Ӧ�ò��ض����� */ 
#undef    DLT634_5104SLAVE_COTByte	                                // ���崫��ԭ���ֽ��� 
#undef    DLT634_5104SLAVE_PUBADDRBYTE							                // ���幫����ַ�ֽ���
#define   DLT634_5104SLAVE_BROADCASTADDR	                0xFFFF
#define   DLT634_5104SLAVE_INFOADDR3BYTE

//1������״̬
#define  DLT634_5104SLAVE_HAVEINITEND                0x00000001
#define	 DLT634_5104SLAVE_HAVECOS	                  0x00000002
#define  DLT634_5104SLAVE_HAVESOE	                  0x00000004
#define  DLT634_5104SLAVE_HAVEFA	                    0x00000008
#define  DLT634_5104SLAVE_HAVEYK                     0x00000010
#define  DLT634_5104SLAVE_FNextYK                    0x00000020
#define  DLT634_5104SLAVE_CALLALLDATA                0x00000040
#define  DLT634_5104SLAVE_FNextALLDATA               0x00000080
#define  DLT634_5104SLAVE_FNextCounter               0x00000100
#define  DLT634_5104SLAVE_APP_SYN                    0x00000200
#define  DLT634_5104SLAVE_APP_DD                     0x00000400
#define  DLT634_5104SLAVE_CallTimeDelay              0x00000800
#define  DLT634_5104SLAVE_CallReadData	              0x00001000
#define  DLT634_5104SLAVE_FreezeDD                   0x00002000
#define  DLT634_5104SLAVE_CallParaSet                0x00004000
#define  DLT634_5104SLAVE_CallReset                  0x00008000
#define  DLT634_5104SLAVE_CallSetNVA                 0x00010000
#define  DLT634_5104SLAVE_CallTest                   0x00020000
#define  DLT634_5104SLAVE_HaveNVA	                  0x00040000
#define  DLT634_5104SLAVE_PARADZOPERATE              0x00080000
#define  DLT634_5104SLAVE_PARADZREAD 	              0x00400000 // �������Ͷ�ֵ
#define  DLT634_5104SLAVE_HaveHisDD                  0x00800000
#define  DLT634_5104SLAVE_HAVEEVENT                  0x01000000
#define  DLT634_5104SLAVE_UpgradeReply               0x02000000
//������Լ����
/* Define Parameter ----------------------------------------------------------*/
#define  DLT634_5104SLAVE_ASDUSIZE                   249
#define  DLT634_5104SLAVE_LPDUSIZE	                 (255)	  // ��·�㷢�ͱ��ĵ���󳤶�   
#define  DLT634_5104SLAVE_APDUSIZE	                  253       // Ӧ�ò��շ�����������󳤶� 
#define  DLT634_5104SLAVE_FRAMEBUFSIZE	              256       // ��·����ջ���������󳤶�

/*************************************************************************************************************************************/
//DL/T634.5104_2002��Լ
/* IEC104��ʱ��ʱ�� -----------------------------------------------------------*/ 
/* t0: ��վ�˺���վ���ն��豸����һ��TCP���ӵ��������ʱ�䣬��վ�˺���վ���ն��豸֮
 *     ���TCP������ʵ�������п��ܾ������йرպ��ؽ����ⷢ��������4�������
 *     (1) ��վ�˺���վ���ն��豸֮���I��ʽ���ĳ��ֶ�ʧ��������߷���U��ʽ���ĵò�
 *         ��Ӧ��ʱ��˫�����������ر�TCP���ӣ�Ȼ��������½������ӣ�
 *     (2) ��վϵͳ�����������������վ���½���TCP���ӣ�
 *     (3) ��վ���豸�ն�ͨ���������Իָ������������󣬽��������ӣ�
 *     (4) ��վ���豸�ն��յ���վ�˵�RESET_PROCESS(��λԶ���ն�)�źź󣬽��ر�����
 *         �����³�ʼ����Ȼ���������ӣ�ÿ�ν�������ʱ����վ���ն��豸������socket��
 *         listen()����������������վ�˵���socket��connect()�����������ӣ������t0
 *         ʱ����δ�ܳɹ��������ӣ��������緢�����ϣ���վ��Ӧ����������Ա����������Ϣ��
 * t1: ���ͷ�����һ��I��ʽ���ĺ󣬱�����t1ʱ���ڵõ����շ����Ͽɣ������ͷ���ΪTCP
 *     ���ӳ������Ⲣ���½������ӣ�
 * t2: ���շ��ڽ��յ�I��ʽ���ĺ�������t2ʱ��δ���յ��µ�I��ʽ���ģ���������ͷ�
 *     ����S��ʽ����֡���Ѿ����յ���I��ʽ���Ľ����Ͽɣ�t2����С��t1��t2 < t1����
 * t3: ���ȶˡ���վ���ն�ÿ����һ֡I֡��S֡����U֡�����´�����ʱ��t3������t3δ���յ�
 *     �κα��ģ�����Է����Ͳ�����·֡��t3Ҫ����t1��t2 > t1����
 *
 * ע�����г�ʱֵ�����Χ��1��255s�� 
 * Ĭ�������:
 *            t0 = 30s
 *            t1 = 15s
 *            t2 = 5s
 *            t3 = 10s
 * ---------------------------------------------------------------------------*/
#define  DLT634_5104SLAVE_T0                                30
#define  DLT634_5104SLAVE_T1                                15 // No Ack CloseTCP
#define  DLT634_5104SLAVE_T2                                5  // Send S
#define  DLT634_5104SLAVE_T3                                100 // Send Test U

/* �������ݶ��� --------------------------------------------------------------*/
// PTick
#define  DLT634_5104SLAVE_T0FLAG		                 0x0001
#define  DLT634_5104SLAVE_T1FLAG		                 0x0002
#define  DLT634_5104SLAVE_T2FLAG		                 0x0004
#define  DLT634_5104SLAVE_T3FLAG		                 0x0008

/* -----------------------------------------------------------------------------
 * IEC60870-5-104�涨��������K��W��
 * K: ȡֵ��ΧΪ1��32767����ʾ���ͷ���K��I��ʽ����δ�õ��Է���ȷ��ʱ����ֹͣ���ݴ��͡�
 * W: ȡֵ��ΧΪ1��32767����ʾ���շ�����ڽ�����W��I��ʽ���ĺ�Ӧ�÷����Ͽɡ�
 * IEC60870-5-104�涨K��W��Ĭ��ֵ�ֱ�Ϊ12��APDU��8��APDU��
 * ---------------------------------------------------------------------------*/
#define  DLT634_5104SLAVE_K                                 12
#define  DLT634_5104SLAVE_W                                 8
/* ��·��֡���δ�***************************************************************/
#define  DLT634_5104SLAVE_STARTCODE68	                     0x68	// ��ʼ��

/* ��·�� --------------------------------------------------------------------*/
#define  DLT634_5104SLAVE_S_FRAME                    0x01 
#define  DLT634_5104SLAVE_U_FRAME                    0x03
#define  DLT634_5104SLAVE_U_STARTDTACT               0x07
#define  DLT634_5104SLAVE_U_STARTDTCON               0x0B
#define  DLT634_5104SLAVE_U_STOPDTACT                0x13
#define  DLT634_5104SLAVE_U_STOPDTCON                0x23
#define  DLT634_5104SLAVE_U_TESTFRACT                0x43
#define  DLT634_5104SLAVE_U_TESTFRCON                0x83

/* ��·�㵽Ӧ�ò������(WORD)Link_Command���� */ 
#define  DLT634_5104SLAVE_LINK_CALLDATA		                 1	  // I������
#define  DLT634_5104SLAVE_LINK_APPCON		                   2	  // Sȷ����
#define  DLT634_5104SLAVE_LINK_WORK		                     3
#define  DLT634_5104SLAVE_LINK_NOWORK                       4    // ��·δ����  

//��·����վ����վ���书���붨��
#define  DLT634_5104SLAVE_M_FUN0             	0           // ��λԶ����·
#define  DLT634_5104SLAVE_M_FUN2              2           // ������·���� 
#define  DLT634_5104SLAVE_M_FUN3              3	          // ����ȷ������
#define  DLT634_5104SLAVE_M_FUN4             	4	          // ���Ͳ�ȷ������
#define  DLT634_5104SLAVE_M_FUN8              8	          // ������Ӧȷ������״̬
#define  DLT634_5104SLAVE_M_FUN9             	9	          // �ٻ���·״̬
#define  DLT634_5104SLAVE_M_FUN10             10	        // �ٻ�1���û����� 
#define  DLT634_5104SLAVE_M_FUN11             11          // �ٻ�2���û�����

#define  DLT634_5104SLAVE_LINK_RESETRDL              0         // ��λԶ����·
#define  DLT634_5104SLAVE_LINK_TESTDL                2         // ������·����
#define  DLT634_5104SLAVE_LINK_SENDCON               3         // ����ȷ������
#define  DLT634_5104SLAVE_LINK_SENDNOCON             4         // ���Ͳ�ȷ������
#define  DLT634_5104SLAVE_LINK_REQACD                8         // ������Ӧȷ������״̬
#define  DLT634_5104SLAVE_LINK_REQSTATUS             9         // �ٻ���·״̬
#define  DLT634_5104SLAVE_LINK_REQDATA1              10        // �ٻ�1���û�����
#define  DLT634_5104SLAVE_LINK_REQDATA2              11        // �ٻ�2���û�����

//*��·����վ����վ���书���붨�� 
#define  DLT634_5104SLAVE_S_FUN0              0            // ȷ��
#define  DLT634_5104SLAVE_S_FUN1              1            // ȷ����·æδ���ձ���
#define  DLT634_5104SLAVE_S_FUN8              8            // ��������Ӧ����֡
#define  DLT634_5104SLAVE_S_FUN9              9            // �����ٻ�������
#define  DLT634_5104SLAVE_S_FUN11             11           // ��Ӧ��·״̬��ش�����֡


/* TI���ͱ�ʶ ********************************************************************************/ 
//���ӷ��������Ϣ
#define  DLT634_5104SLAVE_M_SP_NA_1              1            // ������Ϣ
#define  DLT634_5104SLAVE_M_DP_NA_1              3            // ˫����Ϣ
#define  DLT634_5104SLAVE_M_ME_NA_1              9            // ����ֵ����һ��ֵ
#define  DLT634_5104SLAVE_M_ME_NB_1              11           // ����ֵ����Ȼ�ֵ
#define  DLT634_5104SLAVE_M_ME_NC_1              13           // ����ֵ���̸�����
#define  DLT634_5104SLAVE_M_SP_TB_1              30           // ��ʱ��ĵ�����Ϣ
#define  DLT634_5104SLAVE_M_DP_TB_1              31           // ��ʱ���˫����Ϣ
#define  DLT634_5104SLAVE_M_FT_NA_1              42           // �����¼���Ϣ
#define  DLT634_5104SLAVE_M_IT_NB_1              206          // �ۼ������̸�����
#define  DLT634_5104SLAVE_M_IT_TC_1              207          // ��ʱ���ۼ������̸�����

//���Ʒ��������Ϣ
#define  DLT634_5104SLAVE_C_SC_NA_1              45            // ��������
#define  DLT634_5104SLAVE_C_SC_NB_1              46            // ˫������

//���ӷ����ϵͳ����
#define  DLT634_5104SLAVE_M_EI_NA_1              70            // ��ʼ������

//���Ʒ����ϵͳ����
#define  DLT634_5104SLAVE_C_IC_NA_1              100            // վ���ٻ�����
#define  DLT634_5104SLAVE_C_CI_NA_1              101            // �������ٻ�����
#define  DLT634_5104SLAVE_C_CS_NA_1              103            // ʱ��ͬ������
#define  DLT634_5104SLAVE_C_TS_NA_1              104            // ��������
#define  DLT634_5104SLAVE_C_RP_NA_1              105            // ��λ��������
#define  DLT634_5104SLAVE_C_SR_NA_1              200            // �л���ֵ��
#define  DLT634_5104SLAVE_C_RR_NA_1              201            // ����ֵ����
#define  DLT634_5104SLAVE_C_RS_NA_1              202            // �������Ͷ�ֵ
#define  DLT634_5104SLAVE_C_WS_NA_1              203            // д�����Ͷ�ֵ
#define  DLT634_5104SLAVE_F_FR_NA_1              210            // �ļ�����
#define  DLT634_5104SLAVE_F_SR_NA_1              211            // �������

/* COT����ԭ�� ********************************************************************************/ 
#define  DLT634_5104SLAVE_COT_CYC              1            // ����ѭ��
#define  DLT634_5104SLAVE_COT_BACK             2            // ����ɨ��
#define  DLT634_5104SLAVE_COT_SPONT            3            // ͻ��
#define  DLT634_5104SLAVE_COT_INIT             4            // ��ʼ��
#define  DLT634_5104SLAVE_COT_REQ              5            // ���������
#define  DLT634_5104SLAVE_COT_ACT              6            // ����
#define  DLT634_5104SLAVE_COT_ACTCON           7            // ����ȷ��
#define  DLT634_5104SLAVE_COT_DEACT            8            // ֹͣ����
#define  DLT634_5104SLAVE_COT_DEACTCON         9            // ֹͣ����ȷ��
#define  DLT634_5104SLAVE_COT_ACCTTERM         10           // ������ֹ
#define  DLT634_5104SLAVE_COT_FILE             13           // �ļ�����
#define  DLT634_5104SLAVE_COT_INTROGEN         20           // ��Ӧվ�ٻ�
#define  DLT634_5104SLAVE_COT_REQCOGEN         37           // ��Ӧ�����ٻ�

/* �������ȼ� ********************************************************************************/
//1������
#define  DLT634_5104SLAVE_M_EI_NA_P              1            // ��ʼ������
#define  DLT634_5104SLAVE_C_IC_NA_PF             2            // վ���ٻ�����
#define  DLT634_5104SLAVE_C_SC_NA_P              3            // ��������,��ֵ����
#define  DLT634_5104SLAVE_M_SP_TB_P              4           // ��ʱ��ĵ�����Ϣ
#define  DLT634_5104SLAVE_C_IC_NA_P              5            // վ���ٻ������ֵ�ٻ�

//2������
#define  DLT634_5104SLAVE_M_FT_NA_P              0x81           // �����¼���Ϣ
#define  DLT634_5104SLAVE_C_CS_NA_P              0x82            // ʱ��ͬ������
#define  DLT634_5104SLAVE_C_TS_NA_P              0x83            // ��������
#define  DLT634_5104SLAVE_M_ME_NC_P              0x84           // ����ֵ���̸�����
#define  DLT634_5104SLAVE_C_RP_NA_P              0x85            // ��λ��������
#define  DLT634_5104SLAVE_F_FR_NA_P              0x86            // �ļ��ٻ�
#define  DLT634_5104SLAVE_F_FW_NA_P              0x87            // �ļ�����
#define  DLT634_5104SLAVE_C_CI_NA_P              0x88            // �������ٻ�����


#endif /* END _DLT634_5101_APP_H_ */
    

/* END OF FILE ---------------------------------------------------------------*/
