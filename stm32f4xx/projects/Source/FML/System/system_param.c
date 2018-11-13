/**
 **************************************************************************************************
 * @file        system_param.c
 * @author
 * @version
 * @date        
 * @brief
 **************************************************************************************************
 * @attention
 *              存储原理:
 *              CDB_Inflash_Param_Init调用一次会自动分配一个扇区保存参数，同时要指定实际存储数据大小，
 *              SystemParam_xxx操作只提供了一个handle id参数，在对应的函数内部会根据ID读写相关的配置变量，如
 *              果需要新增参数存储在不同的扇区，需要多次调用CDB_Inflash_Param_Init，同时handle id务必要不同，
 *              并在SystemParam_xxx中增加对应的handle id操作。
 *              实际使用时，每个handle id都有一个全局的参数结构体变量，读取时，保存的参数会更新该变量。保存时
 *              直接修改该变量的值，然后调用对应handle id的保存函数即可。
 **************************************************************************************************
 */
#include "env_var.h"
#include "self_def.h"
#include "system_info.h"
#include "crc.h"
#include "clog.h"
#include "stm32_bsp_conf.h"
#include "system_param.h"
/**
 * @addtogroup    XXX 
* @{  
 */

/**
 * @addtogroup    system_param_Modules 
 * @{  
 */

/**
 * @defgroup      system_param_IO_Defines 
 * @brief         
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      system_param_Macros_Defines 
 * @brief         
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      system_param_Constants_Defines 
 * @brief         
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      system_param_Private_Types
 * @brief         
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      system_param_Private_Variables 
 * @brief         
 * @{  
 */
/**
 * @}
 */

/**
 * @defgroup      system_param_Public_Variables 
 * @brief         
 * @{  
 */
/**
 * @}
 */

/**
 * @defgroup      system_param_Private_FunctionPrototypes 
 * @brief         
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      system_param_Functions 
 * @brief         
 * @{  
 */
int16_t SystemParam_Init(void)
{   
    g_SystemInfo.Equip_Info[0].pre=5031;
    g_SystemInfo.Equip_Info[0].tem=2092;
    g_SystemInfo.Equip_Info[0].water=343;
    g_SystemInfo.Equip_Info[0].run_state=1;
    g_SystemInfo.Equip_Info[1].pre=4134;
    g_SystemInfo.Equip_Info[1].tem=2125;
    g_SystemInfo.Equip_Info[1].water=76; 
    g_SystemInfo.Equip_Info[1].run_state=0;
    g_SystemInfo.Equip_Info[2].pre=7587;
    g_SystemInfo.Equip_Info[2].tem=1878;
    g_SystemInfo.Equip_Info[2].water=119;
    g_SystemInfo.Equip_Info[2].run_state=1;    
    return 0;
}

//int16_t SystemParam_Read(void)
//{
//    uint8_t i = 0;
//    BSP_FLASH_ReadBytes(FLASH_PARAM_START_ADDR,(uint8_t*)&g_SystemInfo,sizeof(g_SystemInfo));
//    if (CRC16_Modbus((uint8_t*)&g_SystemInfo,sizeof(g_SystemInfo)) == 0)
//    {
//        
//    }
//    else
//    {
//        BSP_FLASH_ReadBytes(FLASH_PARAM_BACK_START_ADDR,(uint8_t*)&g_SystemInfo,sizeof(g_SystemInfo));
//        if (CRC16_Modbus((uint8_t*)&g_SystemInfo,sizeof(g_SystemInfo)) == 0)
//        {
//            
//
//         }
//        else
//        {
//            for (i=0;i<8;i++)
//            {
//			}
//            INFO("[system]->[param]->read error then init \r\n");
//            return -1;
//        }
//    }
//
//    INFO("[system]->[param]->read ok\r\n");
//    return 0;
//}
//
//void SystemParam_Save(void)
//{
//    g_SystemInfo.crc = CRC16_Modbus((uint8_t*)&g_SystemInfo, sizeof(g_SystemInfo) - sizeof(g_SystemInfo.crc));
//    BSP_FLASH_EraseSector(FLASH_PARAM_START_ADDR);
//    BSP_FLASH_WriteBytes(FLASH_PARAM_START_ADDR,(uint8_t*)&g_SystemInfo,sizeof(g_SystemInfo));
//    BSP_FLASH_EraseSector(FLASH_PARAM_BACK_START_ADDR);
//    BSP_FLASH_WriteBytes(FLASH_PARAM_BACK_START_ADDR,(uint8_t*)&g_SystemInfo,sizeof(g_SystemInfo));
//
//    INFO("[system]->[param]->save\r\n");
//}
//
//void SystemParam_Reset(void)
//{
//    SystemParam_Save();
//    INFO("[system]->[param]->reset ok \r\n");
//}
//
//void SystemParam_Apply(void)
//{
//
//    INFO("[system]->[param]->apply ok\r\n");
//
//}
/**
 * @}
 */

/**
 * @}
 */

/**
 * @}
 */

