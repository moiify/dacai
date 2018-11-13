/**
 **************************************************************************************************
 * @file        gui_curve.c
 * @author
 * @version   v0.1.0
 * @date        
 * @brief
 **************************************************************************************************
 * @attention
 *
 **************************************************************************************************
 */
#include "gui_conf.h"
#include "gui_curve.h"

/**
 * @addtogroup    XXX 
 * @{  
 */

/**
 * @addtogroup    gui_curve_Modules 
 * @{  
 */

/**
 * @defgroup      gui_curve_IO_Defines 
 * @brief         
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      gui_curve_Macros_Defines 
 * @brief         
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      gui_curve_Constants_Defines 
 * @brief         
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      gui_curve_Private_Types
 * @brief         
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      gui_curve_Private_Variables 
 * @brief         
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      gui_curve_Public_Variables 
 * @brief         
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      gui_curve_Private_FunctionPrototypes 
 * @brief         
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      gui_curve_Functions 
 * @brief         
 * @{  
 */
/*! 
*  \brief     曲线控件-添加通道
*  \param  screen_id 画面ID
*  \param  control_id 控件ID
*  \param  channel 通道号
*  \param  color 颜色
*/
void GUI_GraphChannel_Add(uint16_t screen_id,uint16_t control_id,uint8_t channel,uint16_t color)
{
    GUI_SendHeadCMD();
    BSP_LCD_WriteByte(0xB1);
    BSP_LCD_WriteByte(0x30);
    BSP_LCD_SendUint16(screen_id);
    BSP_LCD_SendUint16(control_id);
    BSP_LCD_WriteByte(channel);
    BSP_LCD_SendUint16(color);
    GUI_SendEndCMD();
}
/*! 
*  \brief     曲线控件-删除通道
*  \param  screen_id 画面ID
*  \param  control_id 控件ID
*  \param  channel 通道号
*/
void GUI_GraphChannel_Del(uint16_t screen_id,uint16_t control_id,uint8_t channel)
{
    GUI_SendHeadCMD();
    BSP_LCD_WriteByte(0xB1);
    BSP_LCD_WriteByte(0x31);
    BSP_LCD_SendUint16(screen_id);
    BSP_LCD_SendUint16(control_id);
    BSP_LCD_WriteByte(channel);
    GUI_SendEndCMD();
}
/*! 
*  \brief     曲线控件-添加数据
*  \param  screen_id 画面ID
*  \param  control_id 控件ID
*  \param  channel 通道号
*  \param  pData 曲线数据
*  \param  nDataLen 数据个数
*/
void GUI_GraphChannel_DataAdd(uint16_t screen_id,uint16_t control_id,uint8_t channel,uint8_t *pData,uint16_t nDataLen)
{
    GUI_SendHeadCMD();
    BSP_LCD_WriteByte(0xB1);
    BSP_LCD_WriteByte(0x32);
    BSP_LCD_SendUint16(screen_id);
    BSP_LCD_SendUint16(control_id);
    BSP_LCD_WriteByte(channel);
    BSP_LCD_SendUint16(nDataLen);
    BSP_LCD_SendUint8N(pData,nDataLen);
    GUI_SendEndCMD();
}
/*! 
*  \brief     曲线控件-清除数据
*  \param  screen_id 画面ID
*  \param  control_id 控件ID
*  \param  channel 通道号 
*/
void GUI_GraphChannel_DataClear(uint16_t screen_id,uint16_t control_id,uint8_t channel)
{
    GUI_SendHeadCMD();
    BSP_LCD_WriteByte(0xB1);
    BSP_LCD_WriteByte(0x33);
    BSP_LCD_SendUint16(screen_id);
    BSP_LCD_SendUint16(control_id);
    BSP_LCD_WriteByte(channel);
    GUI_SendEndCMD();
}
/*! 
*  \brief     曲线控件-设置视图窗口
*  \param  screen_id 画面ID
*  \param  control_id 控件ID
*  \param  x_offset 水平偏移
*  \param  x_mul 水平缩放系数
*  \param  y_offset 垂直偏移
*  \param  y_mul 垂直缩放系数
*/
void GUI_GraphSetViewport(uint16_t screen_id,uint16_t control_id,short int x_offset,uint16_t x_mul,short int y_offset,uint16_t y_mul)
{
    GUI_SendHeadCMD();
    BSP_LCD_WriteByte(0xB1);
    BSP_LCD_WriteByte(0x34);
    BSP_LCD_SendUint16(screen_id);
    BSP_LCD_SendUint16(control_id);
    BSP_LCD_SendUint16(x_offset);
    BSP_LCD_SendUint16(x_mul);
    BSP_LCD_SendUint16(y_offset);
    BSP_LCD_SendUint16(y_mul);
    GUI_SendEndCMD();
}
/**
 * @}
 */

/**
 * @}
 */

/**
 * @}
 */

