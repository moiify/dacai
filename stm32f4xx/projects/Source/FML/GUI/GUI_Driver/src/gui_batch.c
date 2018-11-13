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
*  \brief     ��ʼ��������
*  \param  screen_id ����ID
*/
void GUI_BatchBegin(uint16_t screen_id)
{
    GUI_SendHeadCMD();
    BSP_LCD_WriteByte(0xB1);
    BSP_LCD_WriteByte(0x12);
    BSP_LCD_SendUint16(screen_id);
}
/*! 
*  \brief     �������°�ť�ؼ�
*  \param  control_id �ؼ�ID
*  \param  value ��ֵ
*/
void GUI_BatchSetButtonValue(uint16_t control_id,uint8_t state)
{
    BSP_LCD_SendUint16(control_id);
    BSP_LCD_SendUint16(1);
}
/*! 
*  \brief     �������½������ؼ�
*  \param  control_id �ؼ�ID
*  \param  value ��ֵ
*/
void GUI_BatchSetProgressValue(uint16_t control_id,uint32_t value)
{
    BSP_LCD_SendUint16(control_id);
    BSP_LCD_SendUint16(4);
    BSP_LCD_SendUint32(value);
}

/*! 
*  \brief     �������»������ؼ�
*  \param  control_id �ؼ�ID
*  \param  value ��ֵ
*/
void GUI_BatchSetSliderValue(uint16_t control_id,uint32_t value)
{
    BSP_LCD_SendUint16(control_id);
    BSP_LCD_SendUint16(4);
    BSP_LCD_SendUint32(value);
}
/*! 
*  \brief     ���������Ǳ�ؼ�
*  \param  control_id �ؼ�ID
*  \param  value ��ֵ
*/
void GUI_BatchSetMeterValue(uint16_t control_id,uint32_t value)
{
    BSP_LCD_SendUint16(control_id);
    BSP_LCD_SendUint16(4);
    BSP_LCD_SendUint32(value);
}

/*! 
*  \brief  ���������ı��ؼ�
*  \param  control_id �ؼ�ID
*  \param  strings �ַ���
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
*  \brief     �������¶���\ͼ��ؼ�
*  \param  control_id �ؼ�ID
*  \param  frame_id ֡ID
*/
void GUI_BatchSetFrame(uint16_t control_id,uint16_t frame_id)
{
    BSP_LCD_SendUint16(control_id);
    BSP_LCD_SendUint16(2);
    BSP_LCD_SendUint16(frame_id);
}
/*! 
*  \brief     �������ÿؼ��ɼ�
*  \param  control_id �ؼ�ID
*  \param  visible ֡ID
*/
void GUI_BatchSetVisible(uint16_t control_id,uint8_t visible)
{
    BSP_LCD_SendUint16(control_id);
    BSP_LCD_WriteByte(1);
    BSP_LCD_WriteByte(visible);
}
/*! 
*  \brief     �������ÿؼ�ʹ��
*  \param  control_id �ؼ�ID
*  \param  enable ֡ID
*/
void GUI_BatchSetEnable(uint16_t control_id,uint8_t enable)
{
    BSP_LCD_SendUint16(control_id);
    BSP_LCD_WriteByte(2);
    BSP_LCD_WriteByte(enable);
}
/*! 
*  \brief    ������������
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

