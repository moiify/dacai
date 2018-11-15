/**
 **************************************************************************************************
 * @file        gui_fun.h
 * @author
 * @version    v0.1.0
 * @date        
 * @brief
 **************************************************************************************************
 * @attention
 *
 **************************************************************************************************
 */
#ifndef _GUI_FUN_H_
#define _GUI_FUN_H_

/**
 * @addtogroup    XXX 
 * @{ 
 */

/**
 * @addtogroup    gui_fun_Modules 
 * @{  
 */

/**
 * @defgroup      gui_fun_Exported_Macros 
 * @{  
 */
#define FIRMWARE_VER 921          // 保持此固件版本号与真实屏幕一致，确保新增功能可用
#define CRC16_ENABLE 0            // 如果需要CRC16校验功能，修改此宏为1(此时需要在VisualTFT工程中配CRC校验)
#define CMD_MAX_SIZE 300           // 单条指令大小，根据需要调整，尽量设置大一些
#define QUEUE_MAX_SIZE 512        // 指令接收缓冲区大小，根据需要调整，尽量设置大一些


#define TEXTVALUESCREENID   2
#define TEXT1_VALUCONTROLCID 4
#define TEXT2_VALUCONTROLCID 7
#define TEXT3_VALUCONTROLCID 8
#define TEXT4_VALUCONTROLCID 18
#define EQUIP_ID_VALUEID 22    
#define Frame1_VALUCONTROLCID 19
#define GIF1_VALUCONTROLCID 20     

    
#define FINGERMANAGESCREENID 4
#define FINGER_NAME_VALUCONTROLCID 3
#define FINGER_ID_VALUCONTROLCID 4    
     
#define CONFIGSCREENID 3
     
#define RECORDSCREENID 7
#define RECORDCONTROLID 1 
#define ADDCONTROLID 11 
#define DELLTECONTROLID 12 
#define EMPTYCONTROLID 13 
/**
 * @}
 */

/**
 * @defgroup      gui_fun_Exported_Constants
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      gui_fun_Exported_Types 
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      gui_fun_Exported_Variables 
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      gui_fun_Exported_Functions 
 * @{  
 */
void GUI_CON_SetCallBack();
void GUI_Update(void);
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
