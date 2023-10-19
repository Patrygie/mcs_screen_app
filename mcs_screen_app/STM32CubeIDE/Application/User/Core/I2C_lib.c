/*
 * I2C_lib.c
 *
 *  Created on: Oct 3, 2023
 *      Author: Patryk Giepert
 */

// Implementation

#include "cmsis_os.h"
#include "queue.h"
#include "I2C_lib.h"

uint8_t RxData[9];
uint8_t first_received = 0;
uint8_t rxcount = 0;

extern osMessageQueueId_t queue_model_handle;

Message_t message = {};

// End implementation

// Own variables

extern uint8_t screen_page;

// End own variables

// Write messages definitions

WriteMessage_t WriteMessage[MESSAGES_NUMBER] =
{
	{
		.RxID = NextPage_ID,
		.ReactionHandler = NextPage,
		.Data1 = &RxData[RxData1],
	},

// Can status dash
	{
		.RxID = StatusMain_ID,
		.ReactionHandler = CanStatus,
		.Data1 = &RxData[RxData1],
	},

// Car config dash
	{
		.RxID = BrakeMin_ID,
		.ReactionHandler = CarConfig_BrakeMinValueHandler,
		.Data1 = &RxData[RxData1],
		.Data2 = &RxData[RxData2],
	},

	{
		.RxID = BrakeMax_ID,
		.ReactionHandler = CarConfig_BrakeMaxValueHandler,
		.Data1 = &RxData[RxData1],
		.Data2 = &RxData[RxData2],
	},

	{
		.RxID = BrakeRel_ID,
		.ReactionHandler = CarConfig_BrakeRelValueHandler,
		.Data1 = &RxData[RxData1],
	},

	{
		.RxID = BrakeRelOk_ID,
		.ReactionHandler = CarConfig_BrakeRelValueConfirmedHandler,
		.Data1 = &RxData[RxData1],
	},

	{
		.RxID = ThrottleMin_ID,
		.ReactionHandler = CarConfig_ThrottleMinValueHandler,
		.Data1 = &RxData[RxData1],
		.Data2 = &RxData[RxData2],
	},

	{
		.RxID = ThrottleMax_ID,
		.ReactionHandler = CarConfig_ThrottleMaxValueHandler,
		.Data1 = &RxData[RxData1],
		.Data2 = &RxData[RxData2],
	},

	{
		.RxID = ThrottleRel_ID,
		.ReactionHandler = CarConfig_ThrottleRelValueHandler,
		.Data1 = &RxData[RxData1],
	},

	{
		.RxID = ThrottleRelOk_ID,
		.ReactionHandler = CarConfig_ThrottleRelValueConfirmedHandler,
		.Data1 = &RxData[RxData1],
		.Data2 = &RxData[RxData2],
	},

	{
		.RxID = StationaryMode_ID,
		.ReactionHandler = CarConfig_SelectStationaryModeHandler,
	},

	{
		.RxID = DrivingMode_ID,
		.ReactionHandler = CarConfig_SelectDrivingModeHandler,
	},

	{
		.RxID = RepeatCallibration_ID,
		.ReactionHandler = CarConfig_SelectRepeatModeHandler,
	},

	{
		.RxID = DashReset_ID,
		.ReactionHandler = CarConfig_ResetDashboardHandler,
	},

// Drive dash
	{
		.RxID = I2C_DriveMapTcDiffTsacValue_ID,
		.ReactionHandler = Drive_MapTcDiffTsacValueHandler,
		.Data1 = &RxData[RxData1],
		.Data2 = &RxData[RxData2],
		.Data3 = &RxData[RxData3],
		.Data4 = &RxData[RxData4],
	},

	{
		.RxID = P2D_ID,
		.ReactionHandler = Drive_P2DHandler,
		.Data1 = &RxData[RxData1],
	},

	{
		.RxID = TS_ID,
		.ReactionHandler = Drive_TSHandler,
		.Data1 = &RxData[RxData1],
	},

	{
		.RxID = SelectMAP_ID,
		.ReactionHandler = Drive_SelectMAPHandler,
		.Data1 = &RxData[RxData1],
	},

	{
		.RxID = SelectTC_ID,
		.ReactionHandler = Drive_SelectTCHandler,
		.Data1 = &RxData[RxData1],
	},

	{
		.RxID = SelectDIFF_ID,
		.ReactionHandler = Drive_SelectDIFFHandler,
		.Data1 = &RxData[RxData1],
	},

	{
		.RxID = SelectTSAC_ID,
		.ReactionHandler = Drive_SelectTSACHandler,
		.Data1 = &RxData[RxData1],
	},

	{
		.RxID = MAP_ID,
		.ReactionHandler = Drive_UpdateMAPHandler,
		.Data1 = &RxData[RxData1],
	},

	{
		.RxID = TC_ID,
		.ReactionHandler = Drive_UpdateTCHandler,
		.Data1 = &RxData[RxData1],
	},

	{
		.RxID = DIFF_ID,
		.ReactionHandler = Drive_UpdateDIFFHandler,
		.Data1 = &RxData[RxData1],
	},

	{
		.RxID = TSAC_ID,
		.ReactionHandler = Drive_UpdateTSACHandler,
		.Data1 = &RxData[RxData1],
	},

	{
		.RxID = SPEED_ID,
		.ReactionHandler = Drive_UpdateSpeedThrottleHandler,
		.Data1 = &RxData[RxData1],
		.Data2 = &RxData[RxData2],
	},

	{
		.RxID = LENG_ID,
		.ReactionHandler = Drive_UpdateLengLinvRinvRengHandler,
		.Data1 = &RxData[RxData1],
		.Data2 = &RxData[RxData2],
		.Data3 = &RxData[RxData3],
		.Data4 = &RxData[RxData4],
	},

	{
		.RxID = BAT_ID,
		.ReactionHandler = Drive_UpdateBatHvLowHandler,
		.Data1 = &RxData[RxData1],
		.Data2 = &RxData[RxData2],
		.Data3 = &RxData[RxData3],
	},

	{
		.RxID = ERR_ID,
		.ReactionHandler = Drive_ErrorHandler,
		.Data1 = &RxData[RxData1],
	},
};

// End write messages definitions

// Receiving messages implementation

void init_i2c_interrupts(I2C_HandleTypeDef* hi2c)
{
	if (HAL_I2C_EnableListen_IT(hi2c) != HAL_OK)
	{
		  Error_Handler();
	}
}

void HAL_I2C_ListenCpltCallback(I2C_HandleTypeDef *hi2c)
{
	HAL_I2C_EnableListen_IT(hi2c);
}

void ProcessData()
{
	for(uint8_t i = 0; i < MESSAGES_NUMBER; ++i)
	{
		if(RxData[RxRegID] == WriteMessage[i].RxID)
		{
			WriteMessage[i].ReactionHandler();
		}
	}
}

void HAL_I2C_AddrCallback(I2C_HandleTypeDef *hi2c, uint8_t TransferDirection, uint16_t AddrMatchCode)
{
	if (TransferDirection == I2C_DIRECTION_TRANSMIT)
	{
		if (!first_received)
		{
			rxcount=0;
			// Receive only first Byte
			HAL_I2C_Slave_Seq_Receive_IT(hi2c, RxData+rxcount, 1, I2C_FIRST_FRAME);
		}
	}
	else
	{
		Error_Handler();
	}
}

void HAL_I2C_SlaveRxCpltCallback(I2C_HandleTypeDef *hi2c)
{
	if (!first_received)
	{
		++rxcount;
		first_received=1;
		HAL_I2C_Slave_Seq_Receive_IT(hi2c, RxData+rxcount, RxData[RxSize], I2C_LAST_FRAME);
	}
	else
	{
		first_received=0;
		ProcessData();
	}
}

void HAL_I2C_ErrorCallback(I2C_HandleTypeDef *hi2c)
{
	HAL_I2C_EnableListen_IT(hi2c);
}

// End receiving messages implementation


// I2C handlers

void NextPage(void)
{
	HAL_GPIO_TogglePin(internal_led_GPIO_Port, internal_led_Pin);

	switch(*WriteMessage[PageControl].Data1)
	{
	case 2:
		message.ID = Screen3_ID;
		break;
	case 3:
		message.ID = Screen4_ID;
		break;
	case 4:
		message.ID = Screen2_ID;
		break;
	}

	osMessageQueuePut(queue_model_handle, &message, 0U, 0U);
}

void CanStatus(void)
{
	HAL_GPIO_TogglePin(internal_led_GPIO_Port, internal_led_Pin);

	uint8_t can_status_value = 0;

	for(uint8_t i = 0; i < 8; ++i)
	{
		if(*WriteMessage[CanStatus_v].Data1 & (1 << i) )
		{
			can_status_value = 1;
		}
		else
		{
			can_status_value = 0;
		}

		message.ID = StatusMain_ID + i;
		message.value = can_status_value;

		osMessageQueuePut(queue_model_handle, &message, 0U, 0U);
	}
}

void CarConfig_BrakeMinValueHandler(void)
{
	HAL_GPIO_TogglePin(internal_led_GPIO_Port, internal_led_Pin);

	message.ID = WriteMessage[BrakeMin].RxID;
	message.value |= ((*WriteMessage[BrakeMin].Data2) << 8) | *WriteMessage[BrakeMin].Data1;
	osMessageQueuePut(queue_model_handle, &message, 0U, 0U);
}

void CarConfig_BrakeMaxValueHandler(void)
{
	HAL_GPIO_TogglePin(internal_led_GPIO_Port, internal_led_Pin);

	message.ID = WriteMessage[BrakeMax].RxID;
	message.value |= ((*WriteMessage[BrakeMax].Data2) << 8) | *WriteMessage[BrakeMax].Data1;
	osMessageQueuePut(queue_model_handle, &message, 0U, 0U);
}

void CarConfig_BrakeRelValueHandler(void)
{
	HAL_GPIO_TogglePin(internal_led_GPIO_Port, internal_led_Pin);

	message.ID = WriteMessage[BrakeRelease_v].RxID;
	message.value = *WriteMessage[BrakeRelease_v].Data1;
	osMessageQueuePut(queue_model_handle, &message, 0U, 0U);
}

void CarConfig_BrakeRelValueConfirmedHandler(void)
{
	HAL_GPIO_TogglePin(internal_led_GPIO_Port, internal_led_Pin);

	message.ID = WriteMessage[BrakeRelease].RxID;
	message.value = *WriteMessage[BrakeRelease].Data1;
	osMessageQueuePut(queue_model_handle, &message, 0U, 0U);
}

void CarConfig_ThrottleMinValueHandler(void)
{
	HAL_GPIO_TogglePin(internal_led_GPIO_Port, internal_led_Pin);

	message.ID = WriteMessage[ThrottleMin].RxID;
	message.value |= ((*WriteMessage[ThrottleMin].Data2) << 8) | *WriteMessage[ThrottleMin].Data1;
	osMessageQueuePut(queue_model_handle, &message, 0U, 0U);
}

void CarConfig_ThrottleMaxValueHandler(void)
{
	HAL_GPIO_TogglePin(internal_led_GPIO_Port, internal_led_Pin);

	message.ID = WriteMessage[ThrottleMax].RxID;
	message.value |= ((*WriteMessage[ThrottleMax].Data2) << 8) | *WriteMessage[ThrottleMax].Data1;
	osMessageQueuePut(queue_model_handle, &message, 0U, 0U);
}

void CarConfig_ThrottleRelValueHandler(void)
{
	HAL_GPIO_TogglePin(internal_led_GPIO_Port, internal_led_Pin);

	message.ID = WriteMessage[ThrottleRelease_v].RxID;
	message.value = *WriteMessage[ThrottleRelease_v].Data1;
	osMessageQueuePut(queue_model_handle, &message, 0U, 0U);
}

void CarConfig_ThrottleRelValueConfirmedHandler(void)
{
	HAL_GPIO_TogglePin(internal_led_GPIO_Port, internal_led_Pin);

	message.ID = WriteMessage[ThrottleRelease].RxID;
	message.value = *WriteMessage[ThrottleRelease].Data1;
	osMessageQueuePut(queue_model_handle, &message, 0U, 0U);

	message.ID = *WriteMessage[ThrottleRelease].Data2;
	osMessageQueuePut(queue_model_handle, &message, 0U, 0U);
}

void CarConfig_SelectStationaryModeHandler(void)
{
	HAL_GPIO_TogglePin(internal_led_GPIO_Port, internal_led_Pin);

	message.ID = WriteMessage[StationaryMode].RxID;
	osMessageQueuePut(queue_model_handle, &message, 0U, 0U);
}

void CarConfig_SelectDrivingModeHandler(void)
{
	HAL_GPIO_TogglePin(internal_led_GPIO_Port, internal_led_Pin);

	message.ID = WriteMessage[DriveMode].RxID;
	osMessageQueuePut(queue_model_handle, &message, 0U, 0U);
}

void CarConfig_SelectRepeatModeHandler(void)
{
	HAL_GPIO_TogglePin(internal_led_GPIO_Port, internal_led_Pin);

	message.ID = WriteMessage[RepeatMode].RxID;
	osMessageQueuePut(queue_model_handle, &message, 0U, 0U);
}

void CarConfig_ResetDashboardHandler(void)
{
	HAL_GPIO_TogglePin(internal_led_GPIO_Port, internal_led_Pin);

	message.ID = WriteMessage[ClearCarConfig].RxID;
	osMessageQueuePut(queue_model_handle, &message, 0U, 0U);
}

void Drive_MapTcDiffTsacValueHandler(void)
{
	HAL_GPIO_TogglePin(internal_led_GPIO_Port, internal_led_Pin);

	message.ID = MAP_ID;
	message.value = *WriteMessage[DriveParameters].Data1;
	osMessageQueuePut(queue_model_handle, &message, 0U, 0U);

	message.ID = TC_ID;
	message.value = *WriteMessage[DriveParameters].Data2;
	osMessageQueuePut(queue_model_handle, &message, 0U, 0U);

	message.ID = DIFF_ID;
	message.value = *WriteMessage[DriveParameters].Data3;
	osMessageQueuePut(queue_model_handle, &message, 0U, 0U);

	message.ID = TSAC_ID;
	message.value = *WriteMessage[DriveParameters].Data4;
	osMessageQueuePut(queue_model_handle, &message, 0U, 0U);
}

void Drive_P2DHandler(void)
{
	HAL_GPIO_TogglePin(internal_led_GPIO_Port, internal_led_Pin);

	message.ID = WriteMessage[P2dActivate].RxID;
	message.value = *WriteMessage[P2dActivate].Data1;
	osMessageQueuePut(queue_model_handle, &message, 0U, 0U);
}

void Drive_TSHandler(void)
{
	HAL_GPIO_TogglePin(internal_led_GPIO_Port, internal_led_Pin);

	message.ID = WriteMessage[TsActivate].RxID;
	message.value = *WriteMessage[TsActivate].Data1;
	osMessageQueuePut(queue_model_handle, &message, 0U, 0U);
}

void Drive_SelectMAPHandler(void)
{
	HAL_GPIO_TogglePin(internal_led_GPIO_Port, internal_led_Pin);

	message.ID = WriteMessage[MapSelect].RxID;
	message.value = *WriteMessage[MapSelect].Data1;
	osMessageQueuePut(queue_model_handle, &message, 0U, 0U);
}

void Drive_SelectTCHandler(void)
{
	HAL_GPIO_TogglePin(internal_led_GPIO_Port, internal_led_Pin);

	message.ID = WriteMessage[TcSelect].RxID;
	message.value = *WriteMessage[TcSelect].Data1;
	osMessageQueuePut(queue_model_handle, &message, 0U, 0U);
}

void Drive_SelectDIFFHandler(void)
{
	HAL_GPIO_TogglePin(internal_led_GPIO_Port, internal_led_Pin);

	message.ID = WriteMessage[DiffSelect].RxID;
	message.value = *WriteMessage[DiffSelect].Data1;
	osMessageQueuePut(queue_model_handle, &message, 0U, 0U);
}

void Drive_SelectTSACHandler(void)
{
	HAL_GPIO_TogglePin(internal_led_GPIO_Port, internal_led_Pin);

	message.ID = WriteMessage[TsacSelect].RxID;
	message.value = *WriteMessage[TsacSelect].Data1;
	osMessageQueuePut(queue_model_handle, &message, 0U, 0U);
}

void Drive_UpdateMAPHandler(void)
{
	HAL_GPIO_TogglePin(internal_led_GPIO_Port, internal_led_Pin);

	message.ID = WriteMessage[MapUpdate].RxID;
	message.value = *WriteMessage[MapUpdate].Data1;
	osMessageQueuePut(queue_model_handle, &message, 0U, 0U);
}

void Drive_UpdateTCHandler(void)
{
	HAL_GPIO_TogglePin(internal_led_GPIO_Port, internal_led_Pin);

	message.ID = WriteMessage[TcUpdate].RxID;
	message.value = *WriteMessage[TcUpdate].Data1;
	osMessageQueuePut(queue_model_handle, &message, 0U, 0U);
}

void Drive_UpdateDIFFHandler(void)
{
	HAL_GPIO_TogglePin(internal_led_GPIO_Port, internal_led_Pin);

	message.ID = WriteMessage[DiffUpdate].RxID;
	message.value = *WriteMessage[DiffUpdate].Data1;
	osMessageQueuePut(queue_model_handle, &message, 0U, 0U);
}

void Drive_UpdateTSACHandler(void)
{
	HAL_GPIO_TogglePin(internal_led_GPIO_Port, internal_led_Pin);

	message.ID = WriteMessage[TsacUpdate].RxID;
	message.value = *WriteMessage[TsacUpdate].Data1;
	osMessageQueuePut(queue_model_handle, &message, 0U, 0U);
}

void Drive_UpdateSpeedThrottleHandler(void)
{
	HAL_GPIO_TogglePin(internal_led_GPIO_Port, internal_led_Pin);

	message.ID = WriteMessage[SpeedThrottle_v].RxID;
	message.value = *WriteMessage[SpeedThrottle_v].Data1;
	osMessageQueuePut(queue_model_handle, &message, 0U, 0U);

	message.ID = THROTTLE_ID;
	message.value = *WriteMessage[SpeedThrottle_v].Data2;
	osMessageQueuePut(queue_model_handle, &message, 0U, 0U);
}

void Drive_UpdateLengLinvRinvRengHandler(void)
{
	HAL_GPIO_TogglePin(internal_led_GPIO_Port, internal_led_Pin);

	message.ID = WriteMessage[LengLinvRinvReng_v].RxID;
	message.value = *WriteMessage[LengLinvRinvReng_v].Data1;
	osMessageQueuePut(queue_model_handle, &message, 0U, 0U);

	message.ID = LINV_ID;
	message.value = *WriteMessage[LengLinvRinvReng_v].Data2;
	osMessageQueuePut(queue_model_handle, &message, 0U, 0U);

	message.ID = RINV_ID;
	message.value = *WriteMessage[LengLinvRinvReng_v].Data3;
	osMessageQueuePut(queue_model_handle, &message, 0U, 0U);

	message.ID = RENG_ID;
	message.value = *WriteMessage[LengLinvRinvReng_v].Data4;
	osMessageQueuePut(queue_model_handle, &message, 0U, 0U);
}

void Drive_UpdateBatHvLowHandler(void)
{
	HAL_GPIO_TogglePin(internal_led_GPIO_Port, internal_led_Pin);

	message.ID = WriteMessage[BatHvLow_v].RxID;
	message.value = *WriteMessage[BatHvLow_v].Data1;
	osMessageQueuePut(queue_model_handle, &message, 0U, 0U);

	message.ID = HV_ID;
	message.value = *WriteMessage[BatHvLow_v].Data2;
	osMessageQueuePut(queue_model_handle, &message, 0U, 0U);

	message.ID = LOW_ID;
	message.value = *WriteMessage[BatHvLow_v].Data3;
	osMessageQueuePut(queue_model_handle, &message, 0U, 0U);
}

void Drive_ErrorHandler(void)
{
	HAL_GPIO_TogglePin(internal_led_GPIO_Port, internal_led_Pin);

	message.ID = WriteMessage[Error_v].RxID;
	message.value = *WriteMessage[Error_v].Data1;
	osMessageQueuePut(queue_model_handle, &message, 0U, 0U);
}

