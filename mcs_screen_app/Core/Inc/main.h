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

typedef struct
{
	uint8_t ID;
	uint32_t value;
}Message_t;

typedef enum
{
	RxSize =  0u,
	RxRegID = 1u,
	RxData1 = 2u,
	RxData2 = 3u,
	RxData3 = 4u,
	RxData4 = 5u,
}I2cMessageFrame;

typedef enum
{
	Screen2_ID = 0x01u,
	Screen3_ID = 0x03u,
	Screen4_ID = 0x04u,

	NextPage_ID = 		0x05u,

	StatusScrn_ID = 	0x0Au,
	StatusMain_ID = 	0x0Bu,
	StatusHv_ID = 		0x0Cu,
	StatusLv_ID = 		0x0Du,
	StatusFrontSens_ID = 0x0Eu,
	StatusRearEC_ID = 	0x0Fu,
	StatusLMD_ID = 		0x10u,
	StatusRMD_ID = 		0x11u,
	StatusAms_ID = 		0x12u,

	BrakeMin_ID = 		0x24u,
	BrakeMax_ID = 		0x26u,
	BrakeRelOk_ID = 	0x27u,
	BrakeRel_ID = 		0x28u,
	ThrottleMin_ID = 	0x2Au,
	ThrottleMax_ID = 	0x2Cu,
	ThrottleRelOk_ID = 	0x2Du,
	ThrottleRel_ID = 	0x2Eu,
	StationaryMode_ID = 0x2Fu,
	DrivingMode_ID = 	0x30u,
	RepeatCallibration_ID = 0x31u,
	DashReset_ID = 		0x32u,

	P2D_ID = 		0x38u,
	TS_ID = 		0x39u,
	MAP_ID = 		0x3Cu,
	TC_ID = 		0x3Bu,
	DIFF_ID = 		0x3Eu,
	TSAC_ID = 		0x3Fu,
	SPEED_ID = 		0x40u,
	LENG_ID = 		0x41u,
	RENG_ID = 		0x42u,
	LINV_ID = 		0x43u,
	RINV_ID = 		0x44u,
	BAT_ID = 		0x45u,
	HV_ID = 		0x46u,
	LOW_ID = 		0x47u,
	ERR_ID = 		0x48u,
	THROTTLE_ID = 	0x4Au,

	SelectMAP_ID = 	0x49u,
	SelectTC_ID = 	0x4Bu,
	SelectDIFF_ID = 0x4Cu,
	SelectTSAC_ID = 0x4Du,

	I2C_DriveMapTcDiffTsacValue_ID = 0x4Eu,
}I2cMessageID;


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
#define internal_led_Pin GPIO_PIN_1
#define internal_led_GPIO_Port GPIOI
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
