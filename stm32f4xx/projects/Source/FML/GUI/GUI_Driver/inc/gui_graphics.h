/**
 **************************************************************************************************
 * @file        gui_graphics.h
 * @author
 * @version    v0.1.0
 * @date        
 * @brief
 **************************************************************************************************
 * @attention
 *
 **************************************************************************************************
 */
#ifndef _GUI_GRAPHICS_H_
#define _GUI_GRAPHICS_H_

/**
 * @addtogroup    XXX 
 * @{ 
 */

/**
 * @addtogroup    gui_graphics_Modules 
 * @{  
 */

/**
 * @defgroup      gui_graphics_Exported_Macros 
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      gui_graphics_Exported_Constants
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      gui_graphics_Exported_Types 
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      gui_graphics_Exported_Variables 
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      gui_graphics_Exported_Functions 
 * @{  
 */
void GUI_DrawPoint(uint16_t x,uint16_t y);
void GUI_DrawLine(uint16_t x0, uint16_t y0, uint16_t x1, uint16_t y1);
void GUI_GUI_ConSpaceDots(uint16_t x,uint16_t x_space,uint16_t *dot_y,uint16_t dot_cnt);
void GUI_GUI_FcolorConOffsetDots(uint16_t x,uint16_t y,uint16_t *dot_offset,uint16_t dot_cnt);
void GUI_GUI_BcolorConOffsetDots(uint16_t x,uint16_t y,uint8_t *dot_offset,uint16_t dot_cnt);
void GUI_SetPowerSaving(uint8_t enable, uint8_t bl_off_level, uint8_t bl_on_level, uint8_t  bl_on_time);
void GUI_Draw_FcolorConDots(uint16_t *dot,uint16_t dot_cnt);
void GUI_Draw_BcolorConDots(uint16_t *dot,uint16_t dot_cnt);
void GUI_Draw__Circle(uint16_t x, uint16_t y, uint16_t r);
void GUI_Draw_CircleFill(uint16_t x, uint16_t y, uint16_t r);
void GUI_Draw_Arc(uint16_t x,uint16_t y, uint16_t r,uint16_t sa, uint16_t ea);
void GUI_Draw_Rectangle(uint16_t x0, uint16_t y0, uint16_t x1,uint16_t y1 );
void GUI_Draw_RectangleFill(uint16_t x0, uint16_t y0, uint16_t x1,uint16_t y1 );
void GUI_Draw_Ellipse(uint16_t x0, uint16_t y0, uint16_t x1,uint16_t y1 );
void GUI_Draw_EllipseFill(uint16_t x0, uint16_t y0, uint16_t x1,uint16_t y1 );
void GUI_WriteLayer(uint8_t layer);
void GUI_DisplyLayer(uint8_t layer);
void GUI_CopyLayer(uint8_t src_layer,uint8_t dest_layer);
void GUI_ClearLayer(uint8_t layer);
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
