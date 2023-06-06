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
	queue_model_handle = osMessageQueueNew(8, sizeof(Message_t), &queue_model_attr);

	uint8_t I2cData2B[2];
	uint16_t I2cDataSize2B = 2;
	uint8_t I2cData8B[8];
	uint16_t I2cDataSize8B = 8;

//	uint8_t wartosc_pokazowa = 0;

	uint8_t screen_page = 0;
	uint8_t test_value = 0;

	osDelay(1000 / portTICK_PERIOD_MS);

	while(1)
	{

//		if(HAL_I2C_Slave_Receive(&hi2c1, I2cData2B, I2cDataSize2B, HAL_MAX_DELAY) == HAL_OK);
//		//if(HAL_I2C_Slave_Receive_IT(&hi2c1, I2cData2B, I2cDataSize2B) == HAL_OK);
//
////		wartosc_pokazowa++;
////		if(wartosc_pokazowa > 100)
////		{
////			wartosc_pokazowa = 0;
////		}
////		I2cData2B[1] = wartosc_pokazowa;
//
//		Message_t message = {
//				.ID = I2cData2B[0]/*MSG_ID_UPDATE_VALUE*/,
//				.value = I2cData2B[1]/*value*/
//		};
//
//		osMessageQueuePut(queue_model_handle, &message, 0U, 0U);
//
//		//osDelay(5/*500 / portTICK_PERIOD_MS /10*/);



////////////////////////////////////////////////

		if(screen_page == 0)
		{
			while(I2cData2B[I2C_MSG_ID] != I2C_DASHBOARD_GO_TO_NEXT_PAGE)
			{
				if(HAL_I2C_Slave_Receive(&hi2c1, I2cData2B, I2cDataSize2B, HAL_MAX_DELAY) == HAL_OK);

				if(I2cData2B[I2C_MSG_ID] == I2C_DASHBOARD_GO_TO_NEXT_PAGE)
				{
					Message_t message = {
							.ID = MSG_ID_SCREEN3
					};
					osMessageQueuePut(queue_model_handle, &message, 0U, 0U);
				}
			}
			screen_page++;
			I2cData2B[I2C_MSG_ID] = 0;
		}

		else if(screen_page == 1)
		{
//			while(I2cData2B[I2C_MSG_ID] != I2C_DASHBOARD_GO_TO_NEXT_PAGE)
			while(I2cData8B[I2C_MSG_ID] != I2C_DASHBOARD_GO_TO_NEXT_PAGE)
			{
				if(HAL_I2C_Slave_Receive(&hi2c1, I2cData8B, I2cDataSize8B, HAL_MAX_DELAY) == HAL_OK)
				{
					for(uint8_t i = 0; i < 4; i++)
					{
						Message_t message = {
									.ID = I2cData8B[I2C_MSG_ID+2*i],
									.value = I2cData8B[I2C_MSG_VALUE1+2*i]
						};
						osMessageQueuePut(queue_model_handle, &message, 0U, 0U);
					}
				}

//				if(HAL_I2C_Slave_Receive(&hi2c1, I2cData2B, I2cDataSize2B, HAL_MAX_DELAY) == HAL_OK);
//
//				Message_t message = {
//							.ID = I2cData2B[I2C_MSG_ID],
//							.value = I2cData2B[I2C_MSG_VALUE1]
//						};
//				osMessageQueuePut(queue_model_handle, &message, 0U, 0U);
			}
			I2cData8B[I2C_MSG_ID] = 0;
//			I2cData2B[I2C_MSG_ID] = 0;
			screen_page++;
		}

		else if(screen_page == 2)
		{
			Message_t message = {
						.ID = MSG_ID_SCREEN4
			};
			osMessageQueuePut(queue_model_handle, &message, 0U, 0U);

			uint8_t I2cData3B[3];
			uint16_t Value16Bit = 0;
			uint16_t I2cDataSize3B = 3;

			while(I2cData3B[I2C_MSG_ID] != I2C_DASHBOARD_GO_TO_NEXT_PAGE)
			{
				Value16Bit = 0;
				I2cData3B[I2C_MSG_ID] = 0;
				I2cData3B[I2C_MSG_VALUE1] = 0;
				I2cData3B[I2C_MSG_VALUE2] = 0;

				if(HAL_I2C_Slave_Receive(&hi2c1, I2cData3B, I2cDataSize3B, HAL_MAX_DELAY) == HAL_OK);

				Value16Bit |= (I2cData3B[I2C_MSG_VALUE2] << 8) | (I2cData3B[I2C_MSG_VALUE1]);

				Message_t message = {
							.ID = I2cData3B[I2C_MSG_ID],
							.value = Value16Bit
//							.value = I2cData2B[I2C_MSG_VALUE1]
						};
				osMessageQueuePut(queue_model_handle, &message, 0U, 0U);
			}

			screen_page++;
		}

		else if(screen_page == 3)
		{
			Message_t message = {
						.ID = MSG_ID_SCREEN2
			};
			osMessageQueuePut(queue_model_handle, &message, 0U, 0U);
			screen_page++;
		}

		else if(screen_page == 4)
		{
			if(HAL_I2C_Slave_Receive(&hi2c1, I2cData8B, I2cDataSize8B, HAL_MAX_DELAY) == HAL_OK)
			{
				for(uint8_t i = 0; i < 4; i++)
				{
					Message_t message = {
								.ID = I2cData8B[I2C_MSG_ID+2*i],
								.value = I2cData8B[I2C_MSG_VALUE1+2*i]
					};
					osMessageQueuePut(queue_model_handle, &message, 0U, 0U);
				}
			}
//			if(HAL_I2C_Slave_Receive(&hi2c1, I2cData2B, I2cDataSize2B, HAL_MAX_DELAY) == HAL_OK); to było git
//					if(HAL_I2C_Slave_Receive_IT(&hi2c1, I2cData2B, I2cDataSize2B) == HAL_OK);

//			osDelay(100 / portTICK_PERIOD_MS);


//			Message_t message = {
//					.ID = I2cData2B[I2C_MSG_ID],/*HV_I2C_ID,*/    to bylo git
//					.value = I2cData2B[I2C_MSG_VALUE1]/*test_value*/
//			};





//			test_value++;
//			if(test_value >= 100)
//			{
//				test_value = 0;
//			}

//			osMessageQueuePut(queue_model_handle, &message, 0U, 0U); to bylo git

//			message.ID = MSG_ID_GAS;
//			osMessageQueuePut(queue_model_handle, &message, 0U, 0U);
		}
	}


}


