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
#define FIRMWARE_VER 921          // ���ִ˹̼��汾������ʵ��Ļһ�£�ȷ���������ܿ���
#define CRC16_ENABLE 0            // �����ҪCRC16У�鹦�ܣ��޸Ĵ˺�Ϊ1(��ʱ��Ҫ��VisualTFT��������CRCУ��)
#define CMD_MAX_SIZE 300           // ����ָ���С��������Ҫ�������������ô�һЩ
#define QUEUE_MAX_SIZE 512        // ָ����ջ�������С��������Ҫ�������������ô�һЩ


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
