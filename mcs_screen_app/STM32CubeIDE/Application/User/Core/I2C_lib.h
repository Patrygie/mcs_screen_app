/*
 * I2C_lib.h
 *
 *  Created on: Oct 3, 2023
 *      Author: Patryk Giepert
 */

#ifndef INC_I2C_LIB_H_
#define INC_I2C_LIB_H_
#include "main.h"

#define MESSAGES_NUMBER 29

extern I2C_HandleTypeDef hi2c1;

typedef void (*ReactionHandlerPtr)(void);

typedef struct
{
	uint8_t RxID;
	ReactionHandlerPtr ReactionHandler;
	uint8_t* Data1;
	uint8_t* Data2;
	uint8_t* Data3;
	uint8_t* Data4;
	uint8_t* Data5;
	uint8_t* Data6;
	uint8_t* Data7;
	uint8_t* Data8;
}WriteMessage_t;

typedef enum
{
	PageControl = 		0,
	CanStatus_v = 		1,
	BrakeMin =			2,
	BrakeMax = 			3,
	BrakeRelease_v = 	4,
	BrakeRelease =  	5,
	ThrottleMin =		6,
	ThrottleMax = 		7,
	ThrottleRelease_v = 8,
	ThrottleRelease =   9,
	StationaryMode = 	10,
	DriveMode = 		11,
	RepeatMode = 		12,
	ClearCarConfig =	13,
	DriveParameters = 	14,
	P2dActivate = 		15,
	TsActivate = 		16,
	MapSelect = 		17,
	TcSelect = 			18,
	DiffSelect = 		19,
	TsacSelect =		20,
	MapUpdate =			21,
	TcUpdate = 			22,
	DiffUpdate =		23,
	TsacUpdate = 		24,
	SpeedThrottle_v = 	25,
	LengLinvRinvReng_v = 26,
	BatHvLow_v = 		27,
	Error_v =			28,
}MessageStruct;

void init_i2c_interrupts(I2C_HandleTypeDef* hi2c);
void HAL_I2C_ListenCpltCallback(I2C_HandleTypeDef *hi2c);
void HAL_I2C_AddrCallback(I2C_HandleTypeDef *hi2c, uint8_t TransferDirection, uint16_t AddrMatchCode);
void HAL_I2C_SlaveRxCpltCallback(I2C_HandleTypeDef *hi2c);
void HAL_I2C_ErrorCallback(I2C_HandleTypeDef *hi2c);

void NextPage(void);
void CanStatus(void);

void CarConfig_BrakeMinValueHandler(void);
void CarConfig_BrakeMaxValueHandler(void);
void CarConfig_BrakeRelValueHandler(void);
void CarConfig_BrakeRelValueConfirmedHandler(void);
void CarConfig_ThrottleMinValueHandler(void);
void CarConfig_ThrottleMaxValueHandler(void);
void CarConfig_ThrottleRelValueHandler(void);
void CarConfig_ThrottleRelValueConfirmedHandler(void);
void CarConfig_SelectStationaryModeHandler(void);
void CarConfig_SelectDrivingModeHandler(void);
void CarConfig_SelectRepeatModeHandler(void);
void CarConfig_ResetDashboardHandler(void);

void Drive_MapTcDiffTsacValueHandler(void);
void Drive_P2DHandler(void);
void Drive_TSHandler(void);
void Drive_SelectMAPHandler(void);
void Drive_SelectTCHandler(void);
void Drive_SelectDIFFHandler(void);
void Drive_SelectTSACHandler(void);
void Drive_UpdateMAPHandler(void);
void Drive_UpdateTCHandler(void);
void Drive_UpdateDIFFHandler(void);
void Drive_UpdateTSACHandler(void);
void Drive_UpdateSpeedThrottleHandler(void);
void Drive_UpdateLengLinvRinvRengHandler(void);
void Drive_UpdateBatHvLowHandler(void);
void Drive_ErrorHandler(void);

#endif /* INC_I2C_LIB_H_ */
