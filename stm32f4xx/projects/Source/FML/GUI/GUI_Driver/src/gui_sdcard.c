/**
 **************************************************************************************************
 * @file        gui_sdcard.c
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
#include "gui_sdcard.h"

/**
 * @addtogroup    XXX 
 * @{  
 */

/**
 * @addtogroup    gui_sdcard_Modules 
 * @{  
 */

/**
 * @defgroup      gui_sdcard_IO_Defines 
 * @brief         
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      gui_sdcard_Macros_Defines 
 * @brief         
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      gui_sdcard_Constants_Defines 
 * @brief         
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      gui_sdcard_Private_Types
 * @brief         
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      gui_sdcard_Private_Variables 
 * @brief         
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      gui_sdcard_Public_Variables 
 * @brief         
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      gui_sdcard_Private_FunctionPrototypes 
 * @brief         
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      gui_sdcard_Functions 
 * @brief         
 * @{  
 */
#if SD_FILE_EN
/*! 
*  \brief     ���SD���Ƿ����
*/
void GUI_SD_IsInsert(void)
{
    GUI_SendHeadCMD();
    BSP_LCD_WriteByte(0x36);
    BSP_LCD_WriteByte(0x01);
    GUI_SendEndCMD();
}
/*! 
*  \brief     �򿪻򴴽��ļ�
*  \param  filename �ļ�����(��ASCII����)
*  \param  mode ģʽ����ѡ���ģʽ����FA_XXXX
*/
void GUI_SD_CreateFile(uint8_t *filename,uint8_t mode)
{
    GUI_SendHeadCMD();
    BSP_LCD_WriteByte(0x36);
    BSP_LCD_WriteByte(0x05);
    BSP_LCD_WriteByte(mode);
    BSP_LCD_SendStrings(filename);
    GUI_SendEndCMD();
}
/*! 
*  \brief     �Ե�ǰʱ�䴴���ļ�������:20161015083000.txt
*  \param  ext �ļ���׺������ txt
*/
void GUI_SD_CreateFileByTime(uint8_t *ext)
{
    GUI_SendHeadCMD();
    BSP_LCD_WriteByte(0x36);
    BSP_LCD_WriteByte(0x02);
    BSP_LCD_SendStrings(ext);
    GUI_SendEndCMD();
}
/*! 
*  \brief     �ڵ�ǰ�ļ�ĩβд������
*  \param  buffer ����
*  \param  dlc ���ݳ���
*/
void GUI_SD_WriteFile(uint8_t *buffer,uint16_t dlc)
{
    GUI_SendHeadCMD();
    BSP_LCD_WriteByte(0x36);
    BSP_LCD_WriteByte(0x03);
    BSP_LCD_SendUint16(dlc);
    BSP_LCD_WriteByteN(buffer,dlc);
    GUI_SendEndCMD();
}
/*! 
*  \brief     ��ȡ��ǰ�ļ�
*  \param  offset �ļ�λ��ƫ��
*  \param  dlc ���ݳ���
*/
void GUI_SD_ReadFile(uint32_t offset,uint16_t dlc)
{
    GUI_SendHeadCMD();
    BSP_LCD_WriteByte(0x36);
    BSP_LCD_WriteByte(0x07);
    BSP_LCD_SendUint32(offset);
    BSP_LCD_SendUint16(dlc);
    GUI_SendEndCMD();
}

/*! 
*  \brief     ��ȡ��ǰ�ļ�����
*/
void GUI_SD_GetFileSize()
{
    GUI_SendHeadCMD();
    BSP_LCD_WriteByte(0x36);
    BSP_LCD_WriteByte(0x06);
    GUI_SendEndCMD();
}
/*! 
*  \brief     �رյ�ǰ�ļ�
*/
void GUI_SD_CloseFile()
{
    GUI_SendHeadCMD();
    BSP_LCD_WriteByte(0x36);
    BSP_LCD_WriteByte(0x04);
    GUI_SendEndCMD();
}

#endif//SD_FILE_EN
/**
 * @}
 */

/**
 * @}
 */

/**
 * @}
 */

