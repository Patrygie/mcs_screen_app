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

	while(1)
	{
		if(HAL_I2C_Slave_Receive(&hi2c1, data_buffer, data_size, HAL_MAX_DELAY) == HAL_OK);
		//if(HAL_I2C_Slave_Receive_IT(&hi2c1, data_buffer, data_size) == HAL_OK);

		Message_t message = {
				.ID = data_buffer[0]/*MSG_ID_UPDATE_VALUE*/,
				.value = data_buffer[1]/*value*/
		};

		osMessageQueuePut(queue_model_handle, &message, 0U, 0U);

		//osDelay(5/*500 / portTICK_PERIOD_MS /10*/);
	}
}


