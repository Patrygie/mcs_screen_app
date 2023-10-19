#include <gui/model/Model.hpp>
#include <gui/model/ModelListener.hpp>

#include <gui/common/FrontendApplication.hpp>

#include "main.h"
#include "cmsis_os.h"
#include "queue.h"

extern osMessageQueueId_t queue_model_handle;
FrontendApplication* App3;
FrontendApplication* App4;
FrontendApplication* App;

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
		case Screen3_ID:
			App3 = static_cast<FrontendApplication*>(Application::getInstance());
			App3->goto_screen3();
			break;

		case StatusScrn_ID:
			modelListener->can_status_mcs_scrn_update_value(message.value);
			break;
		case StatusMain_ID:
			modelListener->can_status_mcs_main_update_value(message.value);
			break;
		case StatusHv_ID:
			modelListener->can_status_mcs_hv_update_value(message.value);
			break;
		case StatusLv_ID:
			modelListener->can_status_mcs_lv_update_value(message.value);
			break;
		case StatusFrontSens_ID:
			modelListener->can_status_mcs_front_sens_update_value(message.value);
			break;
		case StatusRearEC_ID:
			modelListener->can_status_mcs_rear_ec_update_value(message.value);
			break;
		case StatusLMD_ID:
			modelListener->can_status_mcs_l_motor_driver_update_value(message.value);
			break;
		case StatusRMD_ID:
			modelListener->can_status_mcs_r_motor_driver_update_value(message.value);
			break;
		case StatusAms_ID:
			modelListener->can_status_mcs_ams_update_value(message.value);
			break;

		case Screen4_ID:
			App4 = static_cast<FrontendApplication*>(Application::getInstance());
			App4->goto_screen4();
			break;


		case BrakeMin_ID:
			modelListener->car_config_brake_min_update_value(message.value);
			break;
		case BrakeMax_ID:
			modelListener->car_config_brake_max_update_value(message.value);
			break;
		case BrakeRel_ID:
			modelListener->car_config_brake_rel_update_value(message.value);
			break;
		case BrakeRelOk_ID:
			modelListener->car_config_brake_rel_accepted_value(message.value);
			break;
		case ThrottleMin_ID:
			modelListener->car_config_throttle_min_update_value(message.value);
			break;
		case ThrottleMax_ID:
			modelListener->car_config_throttle_max_update_value(message.value);
			break;
		case ThrottleRel_ID:
			modelListener->car_config_throttle_rel_update_value(message.value);
			break;
		case ThrottleRelOk_ID:
			modelListener->car_config_throttle_rel_accepted_value(message.value);
			break;
		case StationaryMode_ID:
			modelListener->car_config_select_stationary_mode_value(message.value);
			break;
		case DrivingMode_ID:
			modelListener->car_config_select_driving_mode_value(message.value);
			break;
		case RepeatCallibration_ID:
			modelListener->car_config_select_repeat_calibration_value(message.value);
			break;
		case DashReset_ID:
			modelListener->car_config_dashboard_reset_value(message.value);
			break;


		case Screen2_ID:
			App = static_cast<FrontendApplication*>(Application::getInstance());
			App->goto_screen2();
			break;

		case P2D_ID:
			modelListener->p2d_update_value(message.value);
			break;
		case TS_ID:
			modelListener->ts_update_value(message.value);
			break;
		case MAP_ID:
			modelListener->map_update_value(message.value);
			break;
		case TC_ID:
			modelListener->tc_update_value(message.value);
			break;
		case SPEED_ID:
			modelListener->speed_update_value(message.value);
			break;
		case DIFF_ID:
			modelListener->diff_update_value(message.value);
			break;
		case TSAC_ID:
			modelListener->tsac_update_value(message.value);
			break;
		case LENG_ID:
			modelListener->leng_update_value(message.value);
			break;
		case LINV_ID:
			modelListener->linv_update_value(message.value);
			break;
		case BAT_ID:
			modelListener->bat_update_value(message.value);
			break;
		case RINV_ID:
			modelListener->rinv_update_value(message.value);
			break;
		case RENG_ID:
			modelListener->reng_update_value(message.value);
			break;
		case ERR_ID:
			modelListener->err_update_value(message.value);
			break;
		case HV_ID:
			modelListener->hv_update_value(message.value);
			break;
		case LOW_ID:
			modelListener->low_update_value(message.value);
			break;
		case THROTTLE_ID:
			modelListener->drive_throttle_update_value(message.value);
			break;
		case SelectMAP_ID:
			modelListener->drive_select_map_update_value(message.value);
			break;
		case SelectTC_ID:
			modelListener->drive_select_tc_update_value(message.value);
			break;
		case SelectDIFF_ID:
			modelListener->drive_select_diff_update_value(message.value);
			break;
		case SelectTSAC_ID:
			modelListener->drive_select_tsac_update_value(message.value);
			break;
		}
	}
}
