/**
 **************************************************************************************************
 * @file        gui_dev_api.h
 * @author
 * @version    v0.1.0
 * @date        
 * @brief
 **************************************************************************************************
 * @attention
 *
 **************************************************************************************************
 */
#ifndef _GUI_DEV_API_H_
#define _GUI_DEV_API_H_

/**
 * @addtogroup    XXX 
 * @{ 
 */

/**
 * @addtogroup    gui_dev_api_Modules 
 * @{  
 */

/**
 * @defgroup      gui_dev_api_Exported_Macros 
 * @{  
 */
#define FIRMWARE_VER 921          // 保持此固件版本号与真实屏幕一致，确保新增功能可用
#define CRC16_ENABLE 0            // 如果需要CRC16校验功能，修改此宏为1(此时需要在VisualTFT工程中配CRC校验)
#define CMD_MAX_SIZE 64           // 单条指令大小，根据需要调整，尽量设置大一些
#define QUEUE_MAX_SIZE 512        // 指令接收缓冲区大小，根据需要调整，尽量设置大一些

#define TEXTVALUESCREENID   2
#define TEXT1_VALUCONTROLCID 4
#define TEXT2_VALUCONTROLCID 7
#define TEXT3_VALUCONTROLCID 8

#define FINGERMANAGESCREENID 3
     
#define CONFIGSCREENID 4

/**
 * @}
 */

/**
 * @defgroup      gui_dev_api_Exported_Constants
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      gui_dev_api_Exported_Types 
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      gui_dev_api_Exported_Variables 
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      gui_dev_api_Exported_Functions 
 * @{  
 */
void GUI_HandShake();
void GUI_SetBackLight(uint8_t light_level);
void GUI_SetBuzzer(uint8_t time);
void GUI_SetFtColor(uint16_t color);
void GUI_SetBkColor(uint16_t color);

void GUI_TEXT_SetText(uint16_t screen_id,uint16_t control_id,uint8_t *str);
void GUI_TEXT_SetInt32(uint16_t screen_id,uint16_t control_id,uint32_t value,uint8_t sign,uint8_t fill_zero);
void GUI_TEXT_SetFloat(uint16_t screen_id,uint16_t control_id,float value,uint8_t precision,uint8_t show_zeros);
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
