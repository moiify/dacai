/**
 **************************************************************************************************
 * @file        gui_slider.c
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
#include "gui_slider.h"

/**
 * @addtogroup    XXX 
 * @{  
 */

/**
 * @addtogroup    gui_slider_Modules 
 * @{  
 */

/**
 * @defgroup      gui_slider_IO_Defines 
 * @brief         
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      gui_slider_Macros_Defines 
 * @brief         
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      gui_slider_Constants_Defines 
 * @brief         
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      gui_slider_Private_Types
 * @brief         
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      gui_slider_Private_Variables 
 * @brief         
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      gui_slider_Public_Variables 
 * @brief         
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      gui_slider_Private_FunctionPrototypes 
 * @brief         
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      gui_slider_Functions 
 * @brief         
 * @{  
 */
/*! 
*  \brief      ���û�����
*  \param  screen_id ����ID
*  \param  control_id �ؼ�ID
*  \param  value ��ֵ
*/

void GUI_Slider_SetValue(uint16_t screen_id,uint16_t control_id,uint32_t value)
{
    GUI_SendHeadCMD();
    BSP_LCD_WriteByte(0xB1);
    BSP_LCD_WriteByte(0x10);
    BSP_LCD_SendUint16(screen_id);
    BSP_LCD_SendUint16(control_id);
    BSP_LCD_SendUint32(value);
    GUI_SendEndCMD();
}
/*! 
*  \brief      ���ý���ֵ
*  \param  screen_id ����ID
*  \param  control_id �ؼ�ID
*  \param  value ��ֵ
*/
void GUI_SetProgressValue(uint16_t screen_id,uint16_t control_id,uint32_t value)
{
    GUI_SendHeadCMD();
    BSP_LCD_WriteByte(0xB1);
    BSP_LCD_WriteByte(0x10);
    BSP_LCD_SendUint16(screen_id);
    BSP_LCD_SendUint16(control_id);
    BSP_LCD_SendUint32(value);
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

