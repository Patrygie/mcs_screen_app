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
		case MAP_I2C_ID:
			modelListener->map_update_value(message.value);
			break;
		case TC_I2C_ID:
			modelListener->tc_update_value(message.value);
			break;
		case SPEED_I2C_ID:
			modelListener->speed_update_value(message.value);
			break;
		case DIFF_I2C_ID:
			modelListener->diff_update_value(message.value);
			break;
		case TSAC_I2C_ID:
			modelListener->tsac_update_value(message.value);
			break;
		case LENG_I2C_ID:
			modelListener->leng_update_value(message.value);
			break;
		case LINV_I2C_ID:
			modelListener->linv_update_value(message.value);
			break;
		case BAT_I2C_ID:
			modelListener->bat_update_value(message.value);
			break;
		case RINV_I2C_ID:
			modelListener->rinv_update_value(message.value);
			break;
		case RENG_I2C_ID:
			modelListener->reng_update_value(message.value);
			break;
		case ERR_I2C_ID:
			modelListener->err_update_value(message.value);
			break;
		case HV_I2C_ID:
			modelListener->hv_update_value(message.value);
			break;
		case LOW_I2C_ID:
			modelListener->low_update_value(message.value);
			break;
		case P2D_I2C_ID:
			modelListener->p2d_update_value(message.value);
			break;
		case TS_I2C_ID:
			modelListener->ts_update_value(message.value);
			break;
		}
	}
}
