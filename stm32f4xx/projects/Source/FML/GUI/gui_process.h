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
#define BIG2LITTLESWAP16(x) (((uint16_t)(x) & 0x00ff) << 8) | (((uint16_t)(x) & 0xff00) >> 8)  //从缓冲区取16位数据 小端
#define BIG2LITTLESWAP32(x) ((((uint32_t)(x) & 0xff000000) >> 24) | \
                                                       (((uint32_t)(x) & 0x00ff0000) >> 8) | \
                                                       (((uint32_t)(x) & 0x0000ff00) << 8) | \
                                                       (((uint32_t)(x) & 0x000000ff) << 24)) //从缓冲区取32位数据 小端

/**
 * @}
 */

/**
 * @defgroup      gui_process_Exported_Constants
 * @{  
 */
#define NOTIFY_TOUCH_PRESS         0X01  //触摸屏按下通知
#define NOTIFY_TOUCH_RELEASE       0X03  //触摸屏松开通知
#define NOTIFY_WRITE_FLASH_OK      0X0C  //写FLASH成功
#define NOTIFY_WRITE_FLASH_FAILD   0X0D  //写FLASH失败
#define NOTIFY_READ_FLASH_OK       0X0B  //读FLASH成功
#define NOTIFY_READ_FLASH_FAILD    0X0F  //读FLASH失败
#define NOTIFY_MENU                0X14  //菜单事件通知
#define NOTIFY_TIMER               0X43  //定时器超时通知
#define NOTIFY_CONTROL             0XB1  //控件更新通知
#define NOTIFY_READ_RTC            0XF7  //读取RTC时间
#define MSG_GET_CURRENT_SCREEN     0X01  //画面ID变化通知
#define MSG_GET_DATA               0X11  //控件数据通知
#define NOTIFY_HandShake           0X55  //握手通知
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
    kCtrlButton=0x10,                     //按钮
    kCtrlText,                            //文本
    kCtrlProgress,                        //进度条
    kCtrlSlider,                          //滑动条
    kCtrlMeter,                            //仪表
    kCtrlDropList,                        //下拉列表
    kCtrlAnimation,                       //动画
    kCtrlTimer,                           //定时器控件
    kCtrlGraph,                           //曲线图控件
    kCtrlTable,                           //表格控件
    kCtrlMenu,                            //菜单控件
    kCtrlSelector,                        //选择控件
    kCtrlQRCode,                          //二维码
}CtrlType_e;

#pragma pack(1)                           //按字节对齐
typedef struct
{
    uint8_t    cmd_head;                    //帧头

    uint8_t    cmd_type;                    //命令类型(UPDATE_CONTROL)    
    uint8_t    ctrl_msg;                    //CtrlMsgType-指示消息的类型
    uint16_t   screen_id;                   //产生消息的画面ID
    uint16_t   control_id;                  //产生消息的控件ID
    uint8_t    control_type;                //控件类型

    uint8_t    param[256];                  //可变长度参数，最多256个字节

    uint8_t  cmd_tail[4];                   //帧尾
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
