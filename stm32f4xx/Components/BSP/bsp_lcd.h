/**
 **************************************************************************************************
 * @file        bsp_lcd.h
 * @author
 * @version    v0.1.0
 * @date        
 * @brief
 **************************************************************************************************
 * @attention
 *
 **************************************************************************************************
 */
#ifndef _BSP_LCD_H_
#define _BSP_LCD_H_

/**
 * @addtogroup    XXX 
 * @{ 
 */

/**
 * @addtogroup    bsp_lcd_Modules 
 * @{  
 */

/**
 * @defgroup      bsp_lcd_Exported_Macros 
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      bsp_lcd_Exported_Constants
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      bsp_lcd_Exported_Types 
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      bsp_lcd_Exported_Variables 
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      bsp_lcd_Exported_Functions 
 * @{  
 */
void BSP_LCD_WriteBytes(uint8_t* pBuf,uint16_t length);
void BSP_LCD_WriteByte(uint8_t c);
void BSP_LCD_SendStrings(uint8_t *str);
void BSP_LCD_SendUint8(uint8_t value);
void BSP_LCD_SendUint16(uint16_t value);
void BSP_LCD_SendUint32(uint32_t value);
void BSP_LCD_SendUint16N(uint16_t *pData,uint16_t count);
void BSP_LCD_SendUint8N(uint8_t *pData,uint16_t count);
/**
 * @}
 */

/**
 * @}
 */

/**
 * @}
 */
#endif
