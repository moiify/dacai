/**
 **************************************************************************************************
 * @file        gui_label.c
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
#include "gui_label.h"

/**
 * @addtogroup    XXX 
 * @{  
 */

/**
 * @addtogroup    gui_label_Modules 
 * @{  
 */

/**
 * @defgroup      gui_label_IO_Defines 
 * @brief         
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      gui_label_Macros_Defines 
 * @brief         
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      gui_label_Constants_Defines 
 * @brief         
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      gui_label_Private_Types
 * @brief         
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      gui_label_Private_Variables 
 * @brief         
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      gui_label_Public_Variables 
 * @brief         
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      gui_label_Private_FunctionPrototypes 
 * @brief         
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      gui_label_Functions 
 * @brief         
 * @{  
 */
/*! 
*  \brief  �������ּ��
*  \param  x_w ������
*  \param  y_w ������
*/
void GUI_LABEL_SetSpace(uint8_t x_w, uint8_t y_w)
{
    GUI_SendHeadCMD();
    BSP_LCD_WriteByte(0x43);
    BSP_LCD_WriteByte(x_w);
    BSP_LCD_WriteByte(y_w);
    GUI_SendEndCMD();
}
/*! 
*  \brief  ����������ʾ����
*  \param  enable �Ƿ���������
*  \param  width ���
*  \param  height �߶�
*/
void GUI_LABEL_SetFontRegion(uint8_t enable,uint16_t width,uint16_t height)
{
    GUI_SendHeadCMD();
    BSP_LCD_WriteByte(0x45);
    BSP_LCD_WriteByte(enable);
    BSP_LCD_SendUint16(width);
    BSP_LCD_SendUint16(height);
    GUI_SendEndCMD();
}
/*! 
*  \brief  ���ù���ɫ
*  \param  fillcolor_dwon ��ɫ�½�
*  \param  fillcolor_up ��ɫ�Ͻ�
*/
void GUI_LABEL_SetFilterColor(uint16_t fillcolor_dwon, uint16_t fillcolor_up)
{
    GUI_SendHeadCMD();
    BSP_LCD_WriteByte(0x44);
    BSP_LCD_SendUint16(fillcolor_dwon);
    BSP_LCD_SendUint16(fillcolor_up);
    GUI_SendEndCMD();
}

/*! 
*  \brief  ���ù���ɫ
*  \param  x λ��X����
*  \param  y λ��Y����
*  \param  back ��ɫ�Ͻ�
*  \param  font ����
*  \param  strings �ַ�������
*/
void GUI_LABEL_DisFilter(uint16_t x, uint16_t y,uint8_t back,uint8_t font,uint8_t *strings )
{
    GUI_SendHeadCMD();
    BSP_LCD_WriteByte(0x20);
    BSP_LCD_SendUint16(x);
    BSP_LCD_SendUint16(y);
    BSP_LCD_WriteByte(back);
    BSP_LCD_WriteByte(font);
    BSP_LCD_SendStrings(strings);
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

