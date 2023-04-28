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

	uint8_t data_buffer[2];
	uint16_t data_size = 2;

//	uint8_t wartosc_pokazowa = 0;

	uint8_t screen_page = 0;
	uint8_t test_value = 0;

	osDelay(1000 / portTICK_PERIOD_MS);

	while(1)
	{

//		if(HAL_I2C_Slave_Receive(&hi2c1, data_buffer, data_size, HAL_MAX_DELAY) == HAL_OK);
//		//if(HAL_I2C_Slave_Receive_IT(&hi2c1, data_buffer, data_size) == HAL_OK);
//
////		wartosc_pokazowa++;
////		if(wartosc_pokazowa > 100)
////		{
////			wartosc_pokazowa = 0;
////		}
////		data_buffer[1] = wartosc_pokazowa;
//
//		Message_t message = {
//				.ID = data_buffer[0]/*MSG_ID_UPDATE_VALUE*/,
//				.value = data_buffer[1]/*value*/
//		};
//
//		osMessageQueuePut(queue_model_handle, &message, 0U, 0U);
//
//		//osDelay(5/*500 / portTICK_PERIOD_MS /10*/);



////////////////////////////////////////////////

		if(screen_page == 0)
		{
			while(data_buffer[0] != I2C_CHANGE_SCRN_TO_1)
			{
				if(HAL_I2C_Slave_Receive(&hi2c1, data_buffer, data_size, HAL_MAX_DELAY) == HAL_OK);

				if(data_buffer[0] == I2C_CHANGE_SCRN_TO_1)
				{
					Message_t message = {
							.ID = MSG_ID_SCREEN3
					};
					osMessageQueuePut(queue_model_handle, &message, 0U, 0U);
				}
			}
			screen_page++;
		}

		else if(screen_page == 1)
		{
			while(data_buffer[0] != I2C_PLUS_ID)
			{
				if(HAL_I2C_Slave_Receive(&hi2c1, data_buffer, data_size, HAL_MAX_DELAY) == HAL_OK);

				Message_t message = {
							.ID = data_buffer[0],
							.value = data_buffer[1]
						};
				osMessageQueuePut(queue_model_handle, &message, 0U, 0U);
			}
			data_buffer[0] = 0;
			screen_page++;
		}

		else if(screen_page == 2)
		{
			Message_t message = {
						.ID = MSG_ID_SCREEN4
			};
			osMessageQueuePut(queue_model_handle, &message, 0U, 0U);

			uint8_t CAN_3bytes_data[3];
			uint16_t combined_value = 0;

//			while(data_buffer[0] != I2C_PLUS_ID)
			while(CAN_3bytes_data[0] != I2C_PLUS_ID)
			{

				combined_value = 0;
				CAN_3bytes_data[0] = 0;
				CAN_3bytes_data[1] = 0;
				CAN_3bytes_data[2] = 0;
				if(HAL_I2C_Slave_Receive(&hi2c1, CAN_3bytes_data, /*data_size*/3, HAL_MAX_DELAY) == HAL_OK);

				combined_value |= (CAN_3bytes_data[2] << 8) | (CAN_3bytes_data[1]);

				Message_t message = {
							.ID = CAN_3bytes_data[0],
							.value = combined_value
//							.value = data_buffer[1]
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
			if(HAL_I2C_Slave_Receive(&hi2c1, data_buffer, data_size, HAL_MAX_DELAY) == HAL_OK);
//					if(HAL_I2C_Slave_Receive_IT(&hi2c1, data_buffer, data_size) == HAL_OK);

//			osDelay(100 / portTICK_PERIOD_MS);

			Message_t message = {
					.ID = data_buffer[0],/*HV_I2C_ID,*/
					.value = data_buffer[1]/*test_value*/
			};

//			test_value++;
//			if(test_value >= 100)
//			{
//				test_value = 0;
//			}

			osMessageQueuePut(queue_model_handle, &message, 0U, 0U);

//			message.ID = MSG_ID_GAS;
//			osMessageQueuePut(queue_model_handle, &message, 0U, 0U);
		}
	}


}


