/**
 **************************************************************************************************
 * @file        gui_flash.c
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
#include "gui_flash.h"
/**
 * @addtogroup    XXX 
 * @{  
 */

/**
 * @addtogroup    gui_flash_Modules 
 * @{  
 */

/**
 * @defgroup      gui_flash_IO_Defines 
 * @brief         
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      gui_flash_Macros_Defines 
 * @brief         
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      gui_flash_Constants_Defines 
 * @brief         
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      gui_flash_Private_Types
 * @brief         
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      gui_flash_Private_Variables 
 * @brief         
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      gui_flash_Public_Variables 
 * @brief         
 * @{  
 */
void (*GUI_FLASHW_CallBack)(uint8_t status);
void (*GUI_FLASHR_CallBack)(uint8_t status,uint8_t *data,uint16_t length);
/**
 * @}
 */

/**
 * @defgroup      gui_flash_Private_FunctionPrototypes 
 * @brief         
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      gui_flash_Functions 
 * @brief         
 * @{  
 */
/*! 
*  \brief     ��ʼ����ؼ���ֵ��FLASH
*  \param  version ���ݰ汾�ţ�������ָ������16λΪ���汾�ţ���16λΪ�ΰ汾��
*  \param  address �������û��洢���Ĵ�ŵ�ַ��ע���ֹ��ַ�ص�����ͻ
*/
void GUI_Flash_BeginSaveControl(uint32_t version,uint32_t address)
{
    GUI_SendHeadCMD();
    BSP_LCD_WriteByte(0xB1);
    BSP_LCD_WriteByte(0xAA);
    BSP_LCD_SendUint32(version);
    BSP_LCD_SendUint32(address);
}

/*! 
*  \brief     ����ĳ���ؼ�����ֵ��FLASH
*  \param  screen_id ����ID
*  \param  control_id �ؼ�ID
*/
void GUI_Flash_SaveControl(uint16_t screen_id,uint16_t control_id)
{
    BSP_LCD_SendUint16(screen_id);
    BSP_LCD_SendUint16(control_id);
}
/*! 
*  \brief     ����ĳ���ؼ�����ֵ��FLASH
*  \param  screen_id ����ID
*  \param  control_id �ؼ�ID
*/
void GUI_Flas_hEndSaveControl()
{
    GUI_SendEndCMD();
}
/*! 
*  \brief     ��FLASH�лָ��ؼ�����
*  \param  version ���ݰ汾�ţ����汾�ű�����洢ʱһ�£���������ʧ��
*  \param  address �������û��洢���Ĵ�ŵ�ַ
*/
void GUI_Flash_RestoreControl(uint32_t version,uint32_t address)
{
    GUI_SendHeadCMD();
    BSP_LCD_WriteByte(0xB1);
    BSP_LCD_WriteByte(0xAB);
    BSP_LCD_SendUint32(version);
    BSP_LCD_SendUint32(address);
    GUI_SendEndCMD();
}

/*! 
*  \brief  д���ݵ��������û��洢��
*  \param  startAddress ��ʼ��ַ
*  \param  length �ֽ���
*  \param  _data ��д�������
*/
void GUI_WriteUserFlash(uint32_t startAddress,uint16_t length,uint8_t *_data)
{
    GUI_SendHeadCMD();
    BSP_LCD_WriteByte(0x87);
    BSP_LCD_SendUint32(startAddress);
    BSP_LCD_SendUint8N(_data,length);
    GUI_SendEndCMD();
}
/*! 
*  \brief  �Ӵ������û��洢����ȡ����
*  \param  startAddress ��ʼ��ַ
*  \param  length �ֽ���
*/
void GUI_ReadUserFlash(uint32_t startAddress,uint16_t length)
{
    GUI_SendHeadCMD();
    BSP_LCD_WriteByte(0x88);
    BSP_LCD_SendUint32(startAddress);
    BSP_LCD_SendUint16(length);
    GUI_SendEndCMD();
}

void GUI_SetFlashWCallback(void (*recv)(uint8_t status))
{
    GUI_FLASHW_CallBack=recv;
}
void GUI_SetFlashRCallback(void (*recv)(uint8_t status,uint8_t *data,uint16_t length))
{
    GUI_FLASHR_CallBack=recv;
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

