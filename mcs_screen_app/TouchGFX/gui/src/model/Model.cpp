#include <gui/model/Model.hpp>
#include <gui/model/ModelListener.hpp>

#include <gui/common/FrontendApplication.hpp>

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
	/*było if zamiast while*/
	while(osMessageQueueGet(queue_model_handle, &message, NULL, 0U) == osOK)
	{
		switch(message.ID)
		{
		case MSG_ID_SCREEN3:
			FrontendApplication* App3;
			App3 = static_cast<FrontendApplication*>(Application::getInstance());
			App3->goto_screen3();
			break;

		case I2C_CAN_STATUS_SCRN_OK_ID:
			modelListener->can_status_mcs_scrn_update_value(message.value);
			break;
		case I2C_CAN_STATUS_MAIN_OK_ID:
			modelListener->can_status_mcs_main_update_value(message.value);
			break;
		case I2C_CAN_STATUS_HV_OK_ID:
			modelListener->can_status_mcs_hv_update_value(message.value);
			break;
		case I2C_CAN_STATUS_LV_OK_ID:
			modelListener->can_status_mcs_lv_update_value(message.value);
			break;
		case I2C_CAN_STATUS_FRONT_SENS_OK_ID:
			modelListener->can_status_mcs_front_sens_update_value(message.value);
			break;
		case I2C_CAN_STATUS_REAR_EC_OK_ID:
			modelListener->can_status_mcs_rear_ec_update_value(message.value);
			break;
		case I2C_CAN_STATUS_L_MOTOR_DRIVER_OK_ID:
			modelListener->can_status_mcs_l_motor_driver_update_value(message.value);
			break;
		case I2C_CAN_STATUS_R_MOTOR_DRIVER_OK_ID:
			modelListener->can_status_mcs_r_motor_driver_update_value(message.value);
			break;
		case I2C_CAN_STATUS_AMS_OK_ID:
			modelListener->can_status_mcs_ams_update_value(message.value);
			break;

		case MSG_ID_SCREEN4:
			FrontendApplication* App4;
			App4 = static_cast<FrontendApplication*>(Application::getInstance());
			App4->goto_screen4();
			break;


		case I2C_CAR_CONFIG_BRAKE_MIN_VALUE_ID:
			modelListener->car_config_brake_min_update_value(message.value);
			break;
		case I2C_CAR_CONFIG_BRAKE_MAX_VALUE_ID:
			modelListener->car_config_brake_max_update_value(message.value);
			break;
		case I2C_CAR_CONFIG_BRAKE_REL_VALUE_ID:
			modelListener->car_config_brake_rel_update_value(message.value);
			break;
		case I2C_CAR_CONFIG_BRAKE_REL_ACCEPTED:
			modelListener->car_config_brake_rel_accepted_value(message.value);
			break;
		case I2C_CAR_CONFIG_THROTTLE_MIN_VALUE_ID:
			modelListener->car_config_throttle_min_update_value(message.value);
			break;
		case I2C_CAR_CONFIG_THROTTLE_MAX_VALUE_ID:
			modelListener->car_config_throttle_max_update_value(message.value);
			break;
		case I2C_CAR_CONFIG_THROTTLE_REL_VALUE_ID:
			modelListener->car_config_throttle_rel_update_value(message.value);
			break;
		case I2C_CAR_CONFIG_THROTTLE_REL_ACCEPTED:
			modelListener->car_config_throttle_rel_accepted_value(message.value);
			break;
		case I2C_CAR_CONFIG_SELECT_STATIONARY_MODE:
			modelListener->car_config_select_stationary_mode_value(message.value);
			break;
		case I2C_CAR_CONFIG_SELECT_DRIVING_MODE:
			modelListener->car_config_select_driving_mode_value(message.value);
			break;
		case I2C_CAR_CONFIG_SELECT_REPEAT_CALIBRATION:
			modelListener->car_config_select_repeat_calibration_value(message.value);
			break;
		case I2C_CAR_CONFIG_DASHBOARD_RESET_ID:
			modelListener->car_config_dashboard_reset_value(message.value);
			break;


		case MSG_ID_SCREEN2:
			FrontendApplication* App;
			App = static_cast<FrontendApplication*>(Application::getInstance());
			App->goto_screen2();
			break;



		case MSG_ID_GAS:
			modelListener->gas_update_value(message.value);
			break;



		case I2C_DRIVE_MAP_ID:
			modelListener->map_update_value(message.value);
			break;
		case I2C_DRIVE_TC_ID:
			modelListener->tc_update_value(message.value);
			break;
		case I2C_DRIVE_SPEED_ID:
			modelListener->speed_update_value(message.value);
			break;
		case I2C_DRIVE_DIFF_ID:
			modelListener->diff_update_value(message.value);
			break;
		case I2C_DRIVE_TSAC_ID:
			modelListener->tsac_update_value(message.value);
			break;
		case I2C_DRIVE_LENG_ID:
			modelListener->leng_update_value(message.value);
			break;
		case I2C_DRIVE_LINV_ID:
			modelListener->linv_update_value(message.value);
			break;
		case I2C_DRIVE_BAT_ID:
			modelListener->bat_update_value(message.value);
			break;
		case I2C_DRIVE_RINV_ID:
			modelListener->rinv_update_value(message.value);
			break;
		case I2C_DRIVE_RENG_ID:
			modelListener->reng_update_value(message.value);
			break;
		case I2C_DRIVE_ERR_ID:
			modelListener->err_update_value(message.value);
			break;
		case I2C_DRIVE_HV_ID:
			modelListener->hv_update_value(message.value);
			break;
		case I2C_DRIVE_LOW_ID:
			modelListener->low_update_value(message.value);
			break;
		case I2C_DRIVE_P2D_ID:
			modelListener->p2d_update_value(message.value);
			break;
		case I2C_DRIVE_TS_ID:
			modelListener->ts_update_value(message.value);
			break;
		case I2C_DRIVE_SELECT_MAP_ID:
			modelListener->drive_select_map_update_value(message.value);
			break;
		case I2C_DRIVE_SELECT_TC_ID:
			modelListener->drive_select_tc_update_value(message.value);
			break;
		case I2C_DRIVE_SELECT_DIFF_ID:
			modelListener->drive_select_diff_update_value(message.value);
			break;
		case I2C_DRIVE_SELECT_TSAC_ID:
			modelListener->drive_select_tsac_update_value(message.value);
			break;
		}
	}
}
