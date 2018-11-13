/**
 **************************************************************************************************
 * @file        gui_batch.c
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
#include "gui_batch.h"

/**
 * @addtogroup    XXX 
 * @{  
 */

/**
 * @addtogroup    gui_batch_Modules 
 * @{  
 */

/**
 * @defgroup      gui_batch_IO_Defines 
 * @brief         
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      gui_batch_Macros_Defines 
 * @brief         
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      gui_batch_Constants_Defines 
 * @brief         
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      gui_batch_Private_Types
 * @brief         
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      gui_batch_Private_Variables 
 * @brief         
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      gui_batch_Public_Variables 
 * @brief         
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      gui_batch_Private_FunctionPrototypes 
 * @brief         
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      gui_batch_Functions 
 * @brief         
 * @{  
 */
/*! 
*  \brief     开始批量更新
*  \param  screen_id 画面ID
*/
void GUI_BatchBegin(uint16_t screen_id)
{
    GUI_SendHeadCMD();
    BSP_LCD_WriteByte(0xB1);
    BSP_LCD_WriteByte(0x12);
    BSP_LCD_SendUint16(screen_id);
}
/*! 
*  \brief     批量更新按钮控件
*  \param  control_id 控件ID
*  \param  value 数值
*/
void GUI_BatchSetButtonValue(uint16_t control_id,uint8_t state)
{
    BSP_LCD_SendUint16(control_id);
    BSP_LCD_SendUint16(1);
}
/*! 
*  \brief     批量更新进度条控件
*  \param  control_id 控件ID
*  \param  value 数值
*/
void GUI_BatchSetProgressValue(uint16_t control_id,uint32_t value)
{
    BSP_LCD_SendUint16(control_id);
    BSP_LCD_SendUint16(4);
    BSP_LCD_SendUint32(value);
}

/*! 
*  \brief     批量更新滑动条控件
*  \param  control_id 控件ID
*  \param  value 数值
*/
void GUI_BatchSetSliderValue(uint16_t control_id,uint32_t value)
{
    BSP_LCD_SendUint16(control_id);
    BSP_LCD_SendUint16(4);
    BSP_LCD_SendUint32(value);
}
/*! 
*  \brief     批量更新仪表控件
*  \param  control_id 控件ID
*  \param  value 数值
*/
void GUI_BatchSetMeterValue(uint16_t control_id,uint32_t value)
{
    BSP_LCD_SendUint16(control_id);
    BSP_LCD_SendUint16(4);
    BSP_LCD_SendUint32(value);
}

/*! 
*  \brief  批量更新文本控件
*  \param  control_id 控件ID
*  \param  strings 字符串
*/
void GUI_BatchSetText(uint16_t control_id,uint8_t *strings)
{   
    uint32_t len;
    uint8_t *p = strings;
    while(*strings)
    {
        strings++;
    }

    len=(strings-p);
    BSP_LCD_SendUint16(control_id);
    BSP_LCD_SendUint16(len);
    BSP_LCD_SendStrings(strings);
}
/*! 
*  \brief     批量更新动画\图标控件
*  \param  control_id 控件ID
*  \param  frame_id 帧ID
*/
void GUI_BatchSetFrame(uint16_t control_id,uint16_t frame_id)
{
    BSP_LCD_SendUint16(control_id);
    BSP_LCD_SendUint16(2);
    BSP_LCD_SendUint16(frame_id);
}
/*! 
*  \brief     批量设置控件可见
*  \param  control_id 控件ID
*  \param  visible 帧ID
*/
void GUI_BatchSetVisible(uint16_t control_id,uint8_t visible)
{
    BSP_LCD_SendUint16(control_id);
    BSP_LCD_WriteByte(1);
    BSP_LCD_WriteByte(visible);
}
/*! 
*  \brief     批量设置控件使能
*  \param  control_id 控件ID
*  \param  enable 帧ID
*/
void GUI_BatchSetEnable(uint16_t control_id,uint8_t enable)
{
    BSP_LCD_SendUint16(control_id);
    BSP_LCD_WriteByte(2);
    BSP_LCD_WriteByte(enable);
}
/*! 
*  \brief    结束批量更新
*/
void GUI_BatchEnd()
{
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

