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
#include "gui_conf.h"
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
*  \brief     开始保存控件数值到FLASH
*  \param  version 数据版本号，可任意指定，高16位为主版本号，低16位为次版本号
*  \param  address 数据在用户存储区的存放地址，注意防止地址重叠、冲突
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
*  \brief     保存某个控件的数值到FLASH
*  \param  screen_id 画面ID
*  \param  control_id 控件ID
*/
void GUI_Flash_SaveControl(uint16_t screen_id,uint16_t control_id)
{
    BSP_LCD_SendUint16(screen_id);
    BSP_LCD_SendUint16(control_id);
}
/*! 
*  \brief     保存某个控件的数值到FLASH
*  \param  screen_id 画面ID
*  \param  control_id 控件ID
*/
void GUI_Flas_hEndSaveControl()
{
    GUI_SendEndCMD();
}
/*! 
*  \brief     从FLASH中恢复控件数据
*  \param  version 数据版本号，主版本号必须与存储时一致，否则会加载失败
*  \param  address 数据在用户存储区的存放地址
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
*  \brief  写数据到串口屏用户存储区
*  \param  startAddress 起始地址
*  \param  length 字节数
*  \param  _data 待写入的数据
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
*  \brief  从串口屏用户存储区读取数据
*  \param  startAddress 起始地址
*  \param  length 字节数
*/
void GUI_ReadUserFlash(uint32_t startAddress,uint16_t length)
{
    GUI_SendHeadCMD();
    BSP_LCD_WriteByte(0x88);
    BSP_LCD_SendUint32(startAddress);
    BSP_LCD_SendUint16(length);
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

