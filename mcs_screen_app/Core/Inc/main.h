/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2020 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under Ultimate Liberty license
  * SLA0044, the "License"; You may not use this file except in compliance with
  * the License. You may obtain a copy of the License at:
  *                             www.st.com/SLA0044
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f7xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

enum I2C_MSG_ID
{
	I2C_CHANGE_SCRN_TO_1 = 0x05u,
	I2C_SCRN_OK_ID = 0x0Au,
	I2C_MAIN_OK_ID = 0x0Bu,
	I2C_HV_OK_ID = 0x0Cu,

	MSG_ID_SCREEN2 = 0x01u,
	MSG_ID_SCREEN3 = 0x03u,
	MSG_ID_GAS = 0x02u,

	I2C_PLUS_ID = 0x1Eu,


	I2C_MAP_ID = 0x3Cu,
	I2C_TC_ID = 0x4Bu,
	I2C_DIFF_ID = 0x3Eu,
	I2C_TSAC_ID = 0x3Fu,
	I2C_SPEED_ID = 0x40u,
	I2C_LENG_ID = 0x41u,
	I2C_RENG_ID = 0x42u,
	I2C_LINV_ID = 0x43u,
	I2C_RINV_ID = 0x44u,
	I2C_BAT_ID = 0x45u,
	I2C_HV_ID = 0x46u,
	I2C_LOW_ID = 0x47u,
	I2C_ERR_ID = 0x48u,
	I2C_P2D_ID = 0x49u,
	I2C_TS_ID = 0x4Au
};

typedef struct
{
	uint8_t ID;
	uint32_t value;
}Message_t;

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define VSYNC_FREQ_Pin GPIO_PIN_4
#define VSYNC_FREQ_GPIO_Port GPIOB
#define LCD_BL_CTRL_Pin GPIO_PIN_3
#define LCD_BL_CTRL_GPIO_Port GPIOK
#define LCD_DISP_Pin GPIO_PIN_12
#define LCD_DISP_GPIO_Port GPIOI
#define FRAME_RATE_Pin GPIO_PIN_7
#define FRAME_RATE_GPIO_Port GPIOC
#define RENDER_TIME_Pin GPIO_PIN_6
#define RENDER_TIME_GPIO_Port GPIOC
#define MCU_ACTIVE_Pin GPIO_PIN_6
#define MCU_ACTIVE_GPIO_Port GPIOG

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
