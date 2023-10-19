/*
 * backend.c
 *
 *  Created on: 7 sty 2023
 *      Author: Patryk Giepert
 */

#include "main.h"
#include "cmsis_os.h"
#include "queue.h"
#include "I2C_lib.h"

osMessageQueueId_t queue_model_handle;
const osMessageQueueAttr_t queue_model_attr = {.name = "queue_model"};

void backend(void* argument)
{
	init_i2c_interrupts(&hi2c1);

	queue_model_handle = osMessageQueueNew(17, sizeof(Message_t), &queue_model_attr);

	while(1)
	{

	}
}


