/**
 **************************************************************************************************
 * @file        gui_conf.c
 * @author
 * @version   v0.1.0
 * @date        
 * @brief
 **************************************************************************************************
 * @attention
 *
 **************************************************************************************************
 */

#include "self_def.h"
#include "bsp_lcd.h"
#include "gui_conf.h"


/**
 * @addtogroup    XXX 
 * @{  
 */

/**
 * @addtogroup    gui_conf_Modules 
 * @{  
 */

/**
 * @defgroup      gui_conf_IO_Defines 
 * @brief         
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      gui_conf_Macros_Defines 
 * @brief         
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      gui_conf_Constants_Defines 
 * @brief         
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      gui_conf_Private_Types
 * @brief         
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      gui_conf_Private_Variables 
 * @brief         
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      gui_conf_Public_Variables 
 * @brief         
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      gui_conf_Private_FunctionPrototypes 
 * @brief         
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      gui_conf_Functions 
 * @brief         
 * @{  
 */
#if(CRC16_ENABLE)

#else

void GUI_SendHeadCMD()
{   
    BSP_LCD_WriteByte(0XEE);
}
void GUI_SendEndCMD()
{   
    uint8_t buf[]={0xff,0xfc,0xff,0xff};
    BSP_LCD_WriteBytes(buf,4);
}

#endif

/**
 * @}
 */

/**
 * @}
 */

/**
 * @}
 */
