/**
 **************************************************************************************************
 * @file        gui_conf.h
 * @author
 * @version    v0.1.0
 * @date        
 * @brief
 **************************************************************************************************
 * @attention
 *
 **************************************************************************************************
 */
#ifndef _GUI_CONF_H_
#define _GUI_CONF_H_
#include "self_def.h"
#include "bsp_lcd.h"
/**
 * @addtogroup    XXX 
 * @{ 
 */

/**
 * @addtogroup    gui_conf_Modules 
 * @{  
 */
     
#include "gui_batch.h"
#include "gui_button.h"
#include "gui_controlproperty.h"
#include "gui_curve.h"
//#include "gui_flash.h"
#include "gui_general.h"
#include "gui_gif.h"
//#include "gui_graphics.h"
#include "gui_historygraph.h"
#include "gui_icon.h"
#include "gui_image.h"
#include "gui_menu.h"
#include "gui_meter.h"
//#include "gui_music.h"
//#include "gui_QR.h"
#include "gui_record.h"
#include "gui_rtc.h"
//#include "gui_sdcard.h"
#include "gui_slider.h"
#include "gui_text.h"
#include "gui_timer.h"

     
/**
 * @defgroup      gui_conf_Exported_Macros 
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
     
/**
 * @}
 */

/**
 * @defgroup      gui_conf_Exported_Constants
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      gui_conf_Exported_Types 
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      gui_conf_Exported_Variables 
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      gui_conf_Exported_Functions 
 * @{  
 */
void GUI_SendHeadCMD();
void GUI_SendEndCMD();
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
