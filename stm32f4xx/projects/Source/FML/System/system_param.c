/**
 **************************************************************************************************
 * @file        system_param.c
 * @author
 * @version
 * @date        
 * @brief
 **************************************************************************************************
 * @attention
 *              �洢ԭ��:
 *              CDB_Inflash_Param_Init����һ�λ��Զ�����һ���������������ͬʱҪָ��ʵ�ʴ洢���ݴ�С��
 *              SystemParam_xxx����ֻ�ṩ��һ��handle id�������ڶ�Ӧ�ĺ����ڲ������ID��д��ص����ñ�������
 *              ����Ҫ���������洢�ڲ�ͬ����������Ҫ��ε���CDB_Inflash_Param_Init��ͬʱhandle id���Ҫ��ͬ��
 *              ����SystemParam_xxx�����Ӷ�Ӧ��handle id������
 *              ʵ��ʹ��ʱ��ÿ��handle id����һ��ȫ�ֵĲ����ṹ���������ȡʱ������Ĳ�������¸ñ���������ʱ
 *              ֱ���޸ĸñ�����ֵ��Ȼ����ö�Ӧhandle id�ı��溯�����ɡ�
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
//        }
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
////
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

