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
#define PTR2U16(PTR) (((uint16_t)(PTR) & 0x00ff) << 8) | (((uint16_t)(PTR) & 0xff00) >> 8)  //�ӻ�����ȡ16λ���� С��
#define PTR2U32(PTR) ((((uint8_t *)(PTR))[0]<<24)|(((uint8_t *)(PTR))[1]<<16)|(((uint8_t *)(PTR))[2]<<8)|((uint8_t *)(PTR))[3])  //�ӻ�����ȡ32λ���� С��
 
//    (uint_32)((((uint_32)(x) & 0xff000000) >> 24) | \
//              (((uint_32)(x) & 0x00ff0000) >> 8) | \
//              (((uint_32)(x) & 0x0000ff00) << 8) | \
//              (((uint_32)(x) & 0x000000ff) << 24) \
//             )
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
enum CtrlType
{
    kCtrlUnknown=0x0,
    kCtrlButton=0x10,                     //��ť
    kCtrlText,                            //�ı�
    kCtrlProgress,                        //������
    kCtrlSlider,                          //������
    kCtrlMeter,                            //�Ǳ�
    kCtrlDropList,                        //�����б�
    kCtrlAnimation,                       //����
    kCtrlRTC,                             //ʱ����ʾ
    kCtrlGraph,                           //����ͼ�ؼ�
    kCtrlTable,                           //���ؼ�
    kCtrlMenu,                            //�˵��ؼ�
    kCtrlSelector,                        //ѡ��ؼ�
    kCtrlQRCode,                          //��ά��
};
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
}CTRL_MSG_t,*PCTRL_MSG_t;

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
