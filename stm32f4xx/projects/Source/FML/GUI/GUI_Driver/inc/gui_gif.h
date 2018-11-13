/**
 **************************************************************************************************
 * @file        gui_gif.h
 * @author
 * @version    v0.1.0
 * @date        
 * @brief
 **************************************************************************************************
 * @attention
 *
 **************************************************************************************************
 */
#ifndef _GUI_GIF_H_
#define _GUI_GIF_H_

/**
 * @addtogroup    XXX 
 * @{ 
 */

/**
 * @addtogroup    gui_gif_Modules 
 * @{  
 */

/**
 * @defgroup      gui_gif_Exported_Macros 
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      gui_gif_Exported_Constants
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      gui_gif_Exported_Types 
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      gui_gif_Exported_Variables 
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      gui_gif_Exported_Functions 
 * @{  
 */
void GUI_GIF_Show(uint16_t x,uint16_t y,uint16_t flashimage_id,uint8_t enable,uint8_t playnum);
void GUI_GIF_Start(uint16_t screen_id,uint16_t control_id);
void GUI_GIF_Stop(uint16_t screen_id,uint16_t control_id);
void GUI_GIF_Pause(uint16_t screen_id,uint16_t control_id);
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
