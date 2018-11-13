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
#define FIRMWARE_VER 921          // ���ִ˹̼��汾������ʵ��Ļһ�£�ȷ���������ܿ���
#define CRC16_ENABLE 0            // �����ҪCRC16У�鹦�ܣ��޸Ĵ˺�Ϊ1(��ʱ��Ҫ��VisualTFT��������CRCУ��)
#define CMD_MAX_SIZE 300           // ����ָ���С��������Ҫ�������������ô�һЩ
#define QUEUE_MAX_SIZE 512        // ָ����ջ�������С��������Ҫ�������������ô�һЩ

#define TEXTVALUESCREENID   2
#define TEXT1_VALUCONTROLCID 4
#define TEXT2_VALUCONTROLCID 7
#define TEXT3_VALUCONTROLCID 8
#define TEXT4_VALUCONTROLCID 18
#define Frame1_VALUCONTROLCID 19
#define GIF1_VALUCONTROLCID 20     

    
#define FINGERMANAGESCREENID 4
#define TEXT5_VALUCONTROLCID 3
#define TEXT6_VALUCONTROLCID 4    
     
#define CONFIGSCREENID 3

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

void GUI_GetControlValue(uint16_t screen_id,uint16_t control_id);

void GUI_TEXT_SetText(uint16_t screen_id,uint16_t control_id,uint8_t *str);
void GUI_TEXT_SetInt32(uint16_t screen_id,uint16_t control_id,uint32_t value,uint8_t sign,uint8_t fill_zero);
void GUI_TEXT_SetFloat(uint16_t screen_id,uint16_t control_id,float value,uint8_t precision,uint8_t show_zeros);

void GUI_GIF_Stop(uint16_t screen_id,uint16_t control_id);
void GUI_GIF_Start(uint16_t screen_id,uint16_t control_id);
void GUI_GIF_Pause(uint16_t screen_id,uint16_t control_id);


void GUI_Animation_PlayFrame(uint16_t screen_id,uint16_t control_id,uint8_t frame_id);
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
