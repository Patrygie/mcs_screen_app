/*
 * backend.c
 *
 *  Created on: 7 sty 2023
 *      Author: patry
 */

#include "main.h"
#include "cmsis_os.h"
#include "queue.h"

extern I2C_HandleTypeDef hi2c1;

osMessageQueueId_t queue_model_handle;
const osMessageQueueAttr_t queue_model_attr = {.name = "queue_model"};

void backend(void* argument)
{
	queue_model_handle = osMessageQueueNew(12, sizeof(Message_t), &queue_model_attr); //było 8

	uint8_t can_status_value = 0;
	uint8_t I2cData2B[2] = {0, 0};
	uint16_t I2cDataSize2B = 2;
	uint8_t I2cData8B[8] = {0, 0, 0, 0, 0, 0, 0, 0};
	uint16_t I2cDataSize8B = 8;
	uint8_t I2cData3B[3] = {0, 0, 0};
	uint16_t I2cDataSize3B = 3;
	uint16_t Value16Bit = 0;

	uint8_t screen_page = 1;

	osDelay(1000 / portTICK_PERIOD_MS); //delay dla wyświetlenia loga koła

//	uint8_t I2C_test[2] = {0xEE, 1};

	while(1)
	{
		if(screen_page == 1)
		{
			while(I2cData2B[I2C_MSG_ID] != I2C_DASHBOARD_GO_TO_NEXT_PAGE)
			{
				if(HAL_I2C_Slave_Receive(&hi2c1, I2cData2B, I2cDataSize2B, HAL_MAX_DELAY) == HAL_OK);
			}

			I2cData2B[I2C_MSG_ID] = 0;
			screen_page++;
		}

		else if(screen_page == 2)
		{
			Message_t message = {
					.ID = MSG_ID_SCREEN3
			};
			osMessageQueuePut(queue_model_handle, &message, 0U, 0U);

			while(I2cData8B[I2C_MSG_ID] != I2C_DASHBOARD_GO_TO_NEXT_PAGE)
//			while(I2cData2B[I2C_MSG_ID] != I2C_DASHBOARD_GO_TO_NEXT_PAGE)
			{
				if(HAL_I2C_Slave_Receive(&hi2c1, I2cData8B, I2cDataSize8B, HAL_MAX_DELAY) == HAL_OK)
//				if(HAL_I2C_Slave_Receive(&hi2c1, I2cData2B, I2cDataSize2B, HAL_MAX_DELAY) == HAL_OK)
				{
					if(I2cData8B[I2C_MSG_ID] == I2C_CAN_STATUS_MAIN_OK_ID)
//					if(I2cData2B[I2C_MSG_ID] == I2C_CAN_STATUS_MAIN_OK_ID)
					{
						for(uint8_t i = 0; i < 8; i++)
						{
							if(I2cData8B[I2C_MSG_VALUE1] & (1 << i) )
//							if(I2cData2B[I2C_MSG_VALUE1] & (1 << i) )
							{
								can_status_value = 1;
							}
							else
							{
								can_status_value = 0;
							}
							Message_t message = {
									.ID = I2C_CAN_STATUS_MAIN_OK_ID + i,
									.value = can_status_value
							};
							osMessageQueuePut(queue_model_handle, &message, 0U, 0U);
						}
					}
				}
			}
//			I2cData2B[I2C_MSG_ID] = 0;
//			I2cData2B[I2C_MSG_VALUE1] = 0;
			I2cData8B[I2C_MSG_ID] = 0;
			screen_page++;
		}

		else if(screen_page == 3)
		{
			Message_t message = {
						.ID = MSG_ID_SCREEN4
			};
			osMessageQueuePut(queue_model_handle, &message, 0U, 0U);

			while(I2cData3B[I2C_MSG_ID] != I2C_DASHBOARD_GO_TO_NEXT_PAGE)
			{
				Value16Bit = 0;
				I2cData3B[I2C_MSG_ID] = 0;
				I2cData3B[I2C_MSG_VALUE1] = 0;
				I2cData3B[I2C_MSG_VALUE2] = 0;

				if(HAL_I2C_Slave_Receive(&hi2c1, I2cData3B, I2cDataSize3B, HAL_MAX_DELAY) == HAL_OK)
				{
					Value16Bit |= (I2cData3B[I2C_MSG_VALUE2] << 8) | (I2cData3B[I2C_MSG_VALUE1]);

					Message_t message = {
								.ID = I2cData3B[I2C_MSG_ID],
								.value = Value16Bit
					};
					osMessageQueuePut(queue_model_handle, &message, 0U, 0U);
				}
			}
			Value16Bit = 0;
			I2cData3B[I2C_MSG_ID] = 0;
			I2cData3B[I2C_MSG_VALUE1] = 0;
			I2cData3B[I2C_MSG_VALUE2] = 0;
			screen_page++;
		}

		else if(screen_page == 4)
		{
			Message_t message = {
							.ID = MSG_ID_SCREEN2
			};
			osMessageQueuePut(queue_model_handle, &message, 0U, 0U);

			while(I2cData8B[I2C_MSG_ID] != I2C_DASHBOARD_GO_TO_NEXT_PAGE)
			{
			//było while
				if(HAL_I2C_Slave_Receive(&hi2c1, I2cData8B, I2cDataSize8B, HAL_MAX_DELAY) == HAL_OK)
				{
					for(uint8_t i = 0; i < 4; i++)
					{
						Message_t message = {
									.ID = I2cData8B[I2C_MSG_ID+2*i],
									.value = I2cData8B[I2C_MSG_VALUE1+2*i]
						};
						if(message.ID == 0) break;
						osMessageQueuePut(queue_model_handle, &message, 0U, 0U);
					}
				}
			}

			screen_page = 2;

			I2cData2B[I2C_MSG_ID] = 0;
			I2cData2B[I2C_MSG_VALUE1] = 0;

			I2cData8B[I2C_MSG_ID] = 0;
			I2cData8B[I2C_MSG_VALUE1] = 0;
			I2cData8B[I2C_MSG_VALUE2] = 0;
			I2cData8B[I2C_MSG_VALUE3] = 0;
			I2cData8B[I2C_MSG_VALUE4] = 0;
			I2cData8B[I2C_MSG_VALUE5] = 0;
			I2cData8B[I2C_MSG_VALUE6] = 0;
			I2cData8B[I2C_MSG_VALUE7] = 0;
		}
	}
}


