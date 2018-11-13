/**
 **************************************************************************************************
 * @file        gui_music.c
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
#include "gui_music.h"

/**
 * @addtogroup    XXX 
 * @{  
 */

/**
 * @addtogroup    gui_music_Modules 
 * @{  
 */

/**
 * @defgroup      gui_music_IO_Defines 
 * @brief         
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      gui_music_Macros_Defines 
 * @brief         
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      gui_music_Constants_Defines 
 * @brief         
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      gui_music_Private_Types
 * @brief         
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      gui_music_Private_Variables 
 * @brief         
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      gui_music_Public_Variables 
 * @brief         
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      gui_music_Private_FunctionPrototypes 
 * @brief         
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      gui_music_Functions 
 * @brief         
 * @{  
 */
/*! 
*  \brief   播放音乐
*  \param   buffer 十六进制的音乐路径及名字
*/
void GUI_PlayMusic(uint8_t *buffer)
{
    uint8_t i  = 0;

    GUI_SendHeadCMD();
    if(buffer)
    {
        for(i=0;i<19;++i)
            BSP_LCD_WriteByte(buffer[i]);
    }
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

