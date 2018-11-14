/**
 **************************************************************************************************
 * @file        gui_process.h
 * @author
 * @version    v0.1.0
 * @date        
 * @brief
 **************************************************************************************************
 * @attention
 *
 **************************************************************************************************
 */
#ifndef _GUI_PROCESS_H_
#define _GUI_PROCESS_H_

/**
 * @addtogroup    XXX 
 * @{ 
 */

/**
 * @addtogroup    gui_process_Modules 
 * @{  
 */

/**
 * @defgroup      gui_process_Exported_Macros 
 * @{  
 */
#define BIG2LITTLESWAP16(x) (((uint16_t)(x) & 0x00ff) << 8) | (((uint16_t)(x) & 0xff00) >> 8)  //�ӻ�����ȡ16λ���� С��
#define BIG2LITTLESWAP32(x) ((((uint32_t)(x) & 0xff000000) >> 24) | \
                                                       (((uint32_t)(x) & 0x00ff0000) >> 8) | \
                                                       (((uint32_t)(x) & 0x0000ff00) << 8) | \
                                                       (((uint32_t)(x) & 0x000000ff) << 24)) //�ӻ�����ȡ32λ���� С��

/**
 * @}
 */

/**
 * @defgroup      gui_process_Exported_Constants
 * @{  
 */
#define NOTIFY_TOUCH_PRESS         0X01  //����������֪ͨ
#define NOTIFY_TOUCH_RELEASE       0X03  //�������ɿ�֪ͨ
#define NOTIFY_WRITE_FLASH_OK      0X0C  //дFLASH�ɹ�
#define NOTIFY_WRITE_FLASH_FAILD   0X0D  //дFLASHʧ��
#define NOTIFY_READ_FLASH_OK       0X0B  //��FLASH�ɹ�
#define NOTIFY_READ_FLASH_FAILD    0X0F  //��FLASHʧ��
#define NOTIFY_MENU                0X14  //�˵��¼�֪ͨ
#define NOTIFY_TIMER               0X43  //��ʱ����ʱ֪ͨ
#define NOTIFY_CONTROL             0XB1  //�ؼ�����֪ͨ
#define NOTIFY_READ_RTC            0XF7  //��ȡRTCʱ��
#define MSG_GET_CURRENT_SCREEN     0X01  //����ID�仯֪ͨ
#define MSG_GET_DATA               0X11  //�ؼ�����֪ͨ
#define NOTIFY_HandShake           0X55  //����֪ͨ
/**
 * @}
 */

/**
 * @defgroup      gui_process_Exported_Types 
 * @{  
 */
typedef enum 
{
    kCtrlUnknown=0x0,
    kCtrlButton=0x10,                     //��ť
    kCtrlText,                            //�ı�
    kCtrlProgress,                        //������
    kCtrlSlider,                          //������
    kCtrlMeter,                            //�Ǳ�
    kCtrlDropList,                        //�����б�
    kCtrlAnimation,                       //����
    kCtrlTimer,                           //��ʱ���ؼ�
    kCtrlGraph,                           //����ͼ�ؼ�
    kCtrlTable,                           //���ؼ�
    kCtrlMenu,                            //�˵��ؼ�
    kCtrlSelector,                        //ѡ��ؼ�
    kCtrlQRCode,                          //��ά��
}CtrlType_e;

#pragma pack(1)                           //���ֽڶ���
typedef struct
{
    uint8_t    cmd_head;                    //֡ͷ

    uint8_t    cmd_type;                    //��������(UPDATE_CONTROL)    
    uint8_t    ctrl_msg;                    //CtrlMsgType-ָʾ��Ϣ������
    uint16_t   screen_id;                   //������Ϣ�Ļ���ID
    uint16_t   control_id;                  //������Ϣ�Ŀؼ�ID
    uint8_t    control_type;                //�ؼ�����

    uint8_t    param[256];                  //�ɱ䳤�Ȳ��������256���ֽ�

    uint8_t  cmd_tail[4];                   //֡β
}GUI_Dacai_Proto_t;
#pragma pack()

/**
 * @}
 */

/**
 * @defgroup      gui_process_Exported_Variables 
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      gui_process_Exported_Functions 
 * @{  
 */
void GUI_Update();
void Gui_CheckCMD_Loop_Process();
/**
 * @}
 */

/**
 * @}
 */

/**
 * @}
 */
#endif
