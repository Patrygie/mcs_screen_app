#include <gui/model/Model.hpp>
#include <gui/model/ModelListener.hpp>

#include "main.h"
#include "cmsis_os.h"
#include "queue.h"	//dodane

extern osMessageQueueId_t queue_model_handle;


Model::Model() : modelListener(0)
{

}

void Model::tick()
{
	Message_t message;

	if(osMessageQueueGet(queue_model_handle, &message, NULL, 0U) == osOK)
	{
		switch(message.ID)
		{
		case 0x05:
			modelListener->map_update_value(message.value);
			break;
		case 0x04:
			modelListener->tc_update_value(message.value);
			break;
		case 0x03:
			modelListener->speed_update_value(message.value);
			break;
		case 0x06:
			modelListener->diff_update_value(message.value);
			break;
		case 0x07:
			modelListener->tsac_update_value(message.value);
			break;
		case 0x08:
			modelListener->leng_update_value(message.value);
			break;
		case 0x09:
			modelListener->linv_update_value(message.value);
			break;
		case 0xA:
			modelListener->bat_update_value(message.value);
			break;
		case 0xB:
			modelListener->rinv_update_value(message.value);
			break;
		case 0xC:
			modelListener->reng_update_value(message.value);
			break;
		case 0xD:
			modelListener->err_update_value(message.value);
			break;
		case 0xE:
			modelListener->hv_update_value(message.value);
			break;
		case 0xF:
			modelListener->low_update_value(message.value);
			break;
		}
	}
}
