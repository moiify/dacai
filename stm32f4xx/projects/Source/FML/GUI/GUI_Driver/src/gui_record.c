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
*  \brief     ��¼�ؼ�-��������
*  \param  screen_id ����ID
*  \param  control_id �ؼ�ID
*  \param  value �澯ֵ
*  \param  time �澯������ʱ�䣬Ϊ0ʱʹ����Ļ�ڲ�ʱ��
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
*  \brief     ��¼�ؼ�-�������
*  \param  screen_id ����ID
*  \param  control_id �ؼ�ID
*  \param  value �澯ֵ
*  \param  time �澯�����ʱ�䣬Ϊ0ʱʹ����Ļ�ڲ�ʱ��
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
*  \brief    ��¼�ؼ�- ��ӳ����¼
*  \param  screen_id ����ID
*  \param  control_id �ؼ�ID
*  \param  record һ����¼(�ַ���)������ͨ���ֺŸ��������磺��һ��;�ڶ���;������;
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
*  \brief     ��¼�ؼ�-ɾ��ĳ�������¼
*  \param  screen_id ����ID
*  \param  control_id �ؼ�ID
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
*  \brief     ��¼�ؼ�-�����¼����
*  \param  screen_id ����ID
*  \param  control_id �ؼ�ID
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
*  \brief     ��¼�ؼ�-���ü�¼��ʾƫ��
*  \param  screen_id ����ID
*  \param  control_id �ؼ�ID
*  \param  offset ��ʾƫ�ƣ�������λ��
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
*  \brief     ��¼�ؼ�-��ȡ��ǰ��¼��Ŀ
*  \param  screen_id ����ID
*  \param  control_id �ؼ�ID
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

