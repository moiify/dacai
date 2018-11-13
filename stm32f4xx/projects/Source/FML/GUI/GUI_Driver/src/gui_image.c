/**
 **************************************************************************************************
 * @file        gui_image.c
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
#include "gui_image.h"

/**
 * @addtogroup    XXX 
 * @{  
 */

/**
 * @addtogroup    gui_image_Modules 
 * @{  
 */

/**
 * @defgroup      gui_image_IO_Defines 
 * @brief         
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      gui_image_Macros_Defines 
 * @brief         
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      gui_image_Constants_Defines 
 * @brief         
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      gui_image_Private_Types
 * @brief         
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      gui_image_Private_Variables 
 * @brief         
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      gui_image_Public_Variables 
 * @brief         
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      gui_image_Private_FunctionPrototypes 
 * @brief         
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      gui_image_Functions 
 * @brief         
 * @{  
 */
/*! 
*  \brief      ��ʾȫ��ͼƬ
*  \param  image_id ͼƬ����
*  \param  masken �Ƿ�����͸������
*/
void GUI_IMAGE_ShowFull(uint16_t image_id,uint8_t masken)
{
    GUI_SendHeadCMD();
    BSP_LCD_WriteByte(0x31);
    BSP_LCD_SendUint16(image_id);
    BSP_LCD_WriteByte(masken);
    GUI_SendEndCMD();
}
/*! 
*  \brief      ָ��λ����ʾͼƬ
*  \param  x λ��X����
*  \param  y λ��Y����
*  \param  image_id ͼƬ����
*  \param  masken �Ƿ�����͸������
*/
void GUI_IMAGE_Show(uint16_t x,uint16_t y,uint16_t image_id,uint8_t masken)
{
    GUI_SendHeadCMD();
    BSP_LCD_WriteByte(0x32);
    BSP_LCD_SendUint16(x);
    BSP_LCD_SendUint16(y);
    BSP_LCD_SendUint16(image_id);
    BSP_LCD_WriteByte(masken);
    GUI_SendEndCMD();
}
/*! 
*  \brief      ��ʾ�ü�ͼƬ
*  \param  x λ��X����
*  \param  y λ��Y����
*  \param  image_id ͼƬ����
*  \param  image_x ͼƬ�ü�λ��X����
*  \param  image_y ͼƬ�ü�λ��Y����
*  \param  image_l ͼƬ�ü�����
*  \param  image_w ͼƬ�ü��߶�
*  \param  masken �Ƿ�����͸������
*/
void GUI_IMAGE_CutShow(uint16_t x,uint16_t y,uint16_t image_id,uint16_t image_x,uint16_t image_y,uint16_t image_l, uint16_t image_w,uint8_t masken)
{
    GUI_SendHeadCMD();
    BSP_LCD_WriteByte(0x33);
    BSP_LCD_SendUint16(x);
    BSP_LCD_SendUint16(y);
    BSP_LCD_SendUint16(image_id);
    BSP_LCD_SendUint16(image_x);
    BSP_LCD_SendUint16(image_y);
    BSP_LCD_SendUint16(image_l);
    BSP_LCD_SendUint16(image_w);
    BSP_LCD_WriteByte(masken);
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

