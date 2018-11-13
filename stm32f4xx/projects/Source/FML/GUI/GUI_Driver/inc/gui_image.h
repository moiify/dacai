/**
 **************************************************************************************************
 * @file        gui_image.h
 * @author
 * @version    v0.1.0
 * @date        
 * @brief
 **************************************************************************************************
 * @attention
 *
 **************************************************************************************************
 */
#ifndef _GUI_IMAGE_H_
#define _GUI_IMAGE_H_

/**
 * @addtogroup    XXX 
 * @{ 
 */

/**
 * @addtogroup    gui_image_Modules 
 * @{  
 */

/**
 * @defgroup      gui_image_Exported_Macros 
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      gui_image_Exported_Constants
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      gui_image_Exported_Types 
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      gui_image_Exported_Variables 
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      gui_image_Exported_Functions 
 * @{  
 */
void GUI_IMAGE_ShowFull(uint16_t image_id,uint8_t masken);
void GUI_IMAGE_Show(uint16_t x,uint16_t y,uint16_t image_id,uint8_t masken);
void GUI_IMAGE_CutShow(uint16_t x,uint16_t y,uint16_t image_id,uint16_t image_x,uint16_t image_y,uint16_t image_l, uint16_t image_w,uint8_t masken);
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
