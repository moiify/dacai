/**
 **************************************************************************************************
 * @file        bsp_lcd.c
 * @author
 * @version   v0.1.0
 * @date        
 * @brief
 **************************************************************************************************
 * @attention
 *
 **************************************************************************************************
 */
#include "stm32f4xx_bsp_usart.h"
#include "bsp_lcd.h"

/**
 * @addtogroup    XXX 
 * @{  
 */

/**
 * @addtogroup    bsp_lcd_Modules 
 * @{  
 */

/**
 * @defgroup      bsp_lcd_IO_Defines 
 * @brief         
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      bsp_lcd_Macros_Defines 
 * @brief         
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      bsp_lcd_Constants_Defines 
 * @brief         
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      bsp_lcd_Private_Types
 * @brief         
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      bsp_lcd_Private_Variables 
 * @brief         
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      bsp_lcd_Public_Variables 
 * @brief         
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      bsp_lcd_Private_FunctionPrototypes 
 * @brief         
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      bsp_lcd_Functions 
 * @brief         
 * @{  
 */

void BSP_LCD_WriteBytes(uint8_t* pBuf,uint16_t length)
{   
    BSP_USART_WriteBytes(BSP_USART1,pBuf,length);
}

void BSP_LCD_WriteByte(uint8_t c)
{
    BSP_USART_WriteByte(BSP_USART1,c);
}

void BSP_LCD_SendStrings(uint8_t *str)
{
    while(*str)
    {
        BSP_LCD_WriteByte(*str);
        str++;
    }
}

void BSP_LCD_SendUint8(uint8_t value)
{
    BSP_LCD_WriteByte(value);
}

void BSP_LCD_SendUint16(uint16_t value)
{
    BSP_LCD_WriteByte(value>>8);
    BSP_LCD_WriteByte(value&0xff);
}

void BSP_LCD_SendUint32(uint32_t value)
{
    BSP_LCD_SendUint16(value>>16);
    BSP_LCD_SendUint16(value&0xffff);
}

void BSP_LCD_SendUint16N(uint16_t *pData,uint16_t count)
{
    uint16_t i=0;
    for (i=0;i<count;++i)
    {
        BSP_LCD_SendUint16(pData[i]);
    }
}

void BSP_LCD_SendUint8N(uint8_t *pData,uint16_t count)
{
    uint16_t i=0;
    for (i=0;i<count;++i)
    {
        BSP_LCD_SendUint8(pData[i]);
    }
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

