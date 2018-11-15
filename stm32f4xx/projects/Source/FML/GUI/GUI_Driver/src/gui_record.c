/**
 **************************************************************************************************
 * @file        gui_datarecord.c
 * @author
 * @version   v0.1.0
 * @date        
 * @brief
 **************************************************************************************************
 * @attention
 *
 **************************************************************************************************
 */
#include "gui_base.h"
#include "gui_record.h"

/**
 * @addtogroup    XXX 
 * @{  
 */

/**
 * @addtogroup    gui_datarecord_Modules 
 * @{  
 */

/**
 * @defgroup      gui_datarecord_IO_Defines 
 * @brief         
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      gui_datarecord_Macros_Defines 
 * @brief         
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      gui_datarecord_Constants_Defines 
 * @brief         
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      gui_datarecord_Private_Types
 * @brief         
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      gui_datarecord_Private_Variables 
 * @brief         
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      gui_datarecord_Public_Variables 
 * @brief         
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      gui_datarecord_Private_FunctionPrototypes 
 * @brief         
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      gui_datarecord_Functions 
 * @brief         
 * @{  
 */
/*! 
*  \brief     记录控件-触发警告
*  \param  screen_id 画面ID
*  \param  control_id 控件ID
*  \param  value 告警值
*  \param  time 告警产生的时间，为0时使用屏幕内部时间
*/
void GUI_Record_SetEvent(uint16_t screen_id,uint16_t control_id,uint16_t value,uint8_t *time)
{
    uint8_t i  = 0;

    GUI_SendHeadCMD();
    BSP_LCD_WriteByte(0xB1);
    BSP_LCD_WriteByte(0x50);
    BSP_LCD_SendUint16(screen_id);
    BSP_LCD_SendUint16(control_id);
    BSP_LCD_SendUint16(value);

    if(time)
    {
        for(i=0;i<7;++i)
            BSP_LCD_WriteByte(time[i]);
    }

    GUI_SendEndCMD();
}
/*! 
*  \brief     记录控件-解除警告
*  \param  screen_id 画面ID
*  \param  control_id 控件ID
*  \param  value 告警值
*  \param  time 告警解除的时间，为0时使用屏幕内部时间
*/
void GUI_Record_ResetEvent(uint16_t screen_id,uint16_t control_id,uint16_t value,uint8_t *time)
{
    uint8_t i  = 0;

    GUI_SendHeadCMD();
    BSP_LCD_WriteByte(0xB1);
    BSP_LCD_WriteByte(0x51);
    BSP_LCD_SendUint16(screen_id);
    BSP_LCD_SendUint16(control_id);
    BSP_LCD_SendUint16(value);

    if(time)
    {
        for(i=0;i<7;++i)
            BSP_LCD_WriteByte(time[i]);
    }

    GUI_SendEndCMD();
}
/*! 
*  \brief    记录控件- 添加常规记录
*  \param  screen_id 画面ID
*  \param  control_id 控件ID
*  \param  record 一条记录(字符串)，子项通过分号隔开，例如：第一项;第二项;第三项;
*/
void GUI_Record_Add(uint16_t screen_id,uint16_t control_id,uint8_t *record)
{
    GUI_SendHeadCMD();
    BSP_LCD_WriteByte(0xB1);
    BSP_LCD_WriteByte(0x52);
    BSP_LCD_SendUint16(screen_id);
    BSP_LCD_SendUint16(control_id);
    BSP_LCD_SendStrings(record);

    GUI_SendEndCMD();
}
/*! 
*  \brief     记录控件-删除某条常规记录
*  \param  screen_id 画面ID
*  \param  control_id 控件ID
*/
void GUI_Record_Delete(uint16_t screen_id,uint16_t control_id,uint16_t position_id)
{
    GUI_SendHeadCMD();
    BSP_LCD_WriteByte(0xB1);
    BSP_LCD_WriteByte(0x58);
    BSP_LCD_SendUint16(screen_id);
    BSP_LCD_SendUint16(control_id);
    BSP_LCD_SendUint16(position_id);    
    GUI_SendEndCMD();
}
/*! 
*  \brief     记录控件-清除记录数据
*  \param  screen_id 画面ID
*  \param  control_id 控件ID
*/
void GUI_Record_Clear(uint16_t screen_id,uint16_t control_id)
{
    GUI_SendHeadCMD();
    BSP_LCD_WriteByte(0xB1);
    BSP_LCD_WriteByte(0x53);
    BSP_LCD_SendUint16(screen_id);
    BSP_LCD_SendUint16(control_id);
    GUI_SendEndCMD();
}
/*! 
*  \brief     记录控件-设置记录显示偏移
*  \param  screen_id 画面ID
*  \param  control_id 控件ID
*  \param  offset 显示偏移，滚动条位置
*/
void GUI_Record_SetOffset(uint16_t screen_id,uint16_t control_id,uint16_t offset)
{
    GUI_SendHeadCMD();
    BSP_LCD_WriteByte(0xB1);
    BSP_LCD_WriteByte(0x54);
    BSP_LCD_SendUint16(screen_id);
    BSP_LCD_SendUint16(control_id);
    BSP_LCD_SendUint16(offset);
    GUI_SendEndCMD();
}
/*! 
*  \brief     记录控件-获取当前记录数目
*  \param  screen_id 画面ID
*  \param  control_id 控件ID
*/
void GUI_Record_GetCount(uint16_t screen_id,uint16_t control_id)
{
    GUI_SendHeadCMD();
    BSP_LCD_WriteByte(0xB1);
    BSP_LCD_WriteByte(0x55);
    BSP_LCD_SendUint16(screen_id);
    BSP_LCD_SendUint16(control_id);
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

