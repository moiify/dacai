/**
 **************************************************************************************************
 * @file        cshell.h
 * @author
 * @version     V1.0.0
 * @date        
 * @brief
 **************************************************************************************************
 * @attention
 *
 **************************************************************************************************
 */
#ifndef _CSHELL_H_
#define _CSHELL_H_

/**
 * @addtogroup    XXX 
 * @{ 
 */

/**
 * @addtogroup    cshell_Modules 
 * @{  
 */

/**
 * @defgroup      cshell_Exported_Macros 
 * @{  
 */
#define CSHELL_PASSWORD_ENABLE  1

/**
 * @}
 */

/**
 * @defgroup      cshell_Exported_Constants
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      cshell_Exported_Types 
 * @{  
 */
typedef struct
{
    uint8_t *Name;          /*!< �������� */
    uint8_t NameLength;     /*!< �������Ƴ��� */
    void (*get_callback)(uint8_t device_index,uint8_t param_index,uint8_t *data,uint8_t data_length); /*!< ��ȡ�����ص� */
    void (*set_callback)(uint8_t device_index,uint8_t param_index,uint8_t *data,uint8_t data_length); /*!< ���ò����ص� */
}CShellParam_t;

typedef struct
{
    uint8_t *DeviceName;        /*!< �豸���� */
    uint8_t DeviceNameLength;   /*!< �豸���Ƴ��� */
    const CShellParam_t *Params;    /*!< �����б� */
    uint8_t ParamsCount;            /*!< �����б����� */
}CShellDevice_t;
/**
 * @}
 */

/**
 * @defgroup      cshell_Exported_Variables 
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      cshell_Exported_Functions 
 * @{  
 */
void CShell_Exec(void);
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
