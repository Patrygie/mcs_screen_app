#ifndef MODELLISTENER_HPP
#define MODELLISTENER_HPP

#include <gui/model/Model.hpp>
#include "main.h"

class ModelListener
{
public:
    ModelListener() : model(0) {}
    
    virtual ~ModelListener() {}

    void bind(Model* m)
    {
        model = m;
    }

    virtual void can_status_mcs_scrn_update_value(uint32_t value){};
    virtual void can_status_mcs_main_update_value(uint32_t value){};
    virtual void can_status_mcs_hv_update_value(uint32_t value){};
    virtual void can_status_mcs_lv_update_value(uint32_t value){};
    virtual void can_status_mcs_front_sens_update_value(uint32_t value){};
    virtual void can_status_mcs_rear_ec_update_value(uint32_t value){};
    virtual void can_status_mcs_l_motor_driver_update_value(uint32_t value){};
    virtual void can_status_mcs_r_motor_driver_update_value(uint32_t value){};
    virtual void can_status_mcs_ams_update_value(uint32_t value){};

    virtual void car_config_brake_min_update_value(uint32_t value){};
    virtual void car_config_brake_max_update_value(uint32_t value){};
    virtual void car_config_brake_rel_update_value(uint32_t value){};
    virtual void car_config_brake_rel_accepted_value(uint32_t value){};
    virtual void car_config_throttle_min_update_value(uint32_t value){};
    virtual void car_config_throttle_max_update_value(uint32_t value){};
    virtual void car_config_throttle_rel_update_value(uint32_t value){};
    virtual void car_config_throttle_rel_accepted_value(uint32_t value){};
    virtual void car_config_select_stationary_mode_value(uint32_t value){};
    virtual void car_config_select_driving_mode_value(uint32_t value){};
    virtual void car_config_select_repeat_calibration_value(uint32_t value){};
    virtual void car_config_dashboard_reset_value(uint32_t value){};

    virtual void p2d_update_value(uint32_t value){};
    virtual void ts_update_value(uint32_t value){};
    virtual void map_update_value(uint32_t value){};
    virtual void tc_update_value(uint32_t value){};
    virtual void speed_update_value(uint32_t value){};
    virtual void diff_update_value(uint32_t value){};
    virtual void tsac_update_value(uint32_t value){};
    virtual void leng_update_value(uint32_t value){};
    virtual void linv_update_value(uint32_t value){};
    virtual void bat_update_value(uint32_t value){};
    virtual void rinv_update_value(uint32_t value){};
    virtual void reng_update_value(uint32_t value){};
    virtual void err_update_value(uint32_t value){};
    virtual void hv_update_value(uint32_t value){};
    virtual void low_update_value(uint32_t value){};
    virtual void drive_throttle_update_value(uint32_t value){};
    virtual void drive_select_map_update_value(uint32_t){};
    virtual void drive_select_tc_update_value(uint32_t){};
    virtual void drive_select_diff_update_value(uint32_t){};
    virtual void drive_select_tsac_update_value(uint32_t){};

protected:
    Model* model;
};

#endif // MODELLISTENER_HPP
