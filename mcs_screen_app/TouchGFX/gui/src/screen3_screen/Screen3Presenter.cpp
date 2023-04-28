#include <gui/screen3_screen/Screen3View.hpp>
#include <gui/screen3_screen/Screen3Presenter.hpp>

#include "main.h"

Screen3Presenter::Screen3Presenter(Screen3View& v)
    : view(v)
{

}

void Screen3Presenter::activate()
{

}

void Screen3Presenter::deactivate()
{

}

void Screen3Presenter::can_status_mcs_scrn_update_value(uint32_t value)
{
	view.can_status_mcs_scrn_update_value(value);
}

void Screen3Presenter::can_status_mcs_main_update_value(uint32_t value)
{
	view.can_status_mcs_main_update_value(value);
}

void Screen3Presenter::can_status_mcs_hv_update_value(uint32_t value)
{
	view.can_status_mcs_hv_update_value(value);
}

void Screen3Presenter::can_status_mcs_lv_update_value(uint32_t value)
{
	view.can_status_mcs_lv_update_value(value);
}

void Screen3Presenter::can_status_mcs_front_sens_update_value(uint32_t value)
{
	view.can_status_mcs_front_sens_update_value(value);
}

void Screen3Presenter::can_status_mcs_rear_ec_update_value(uint32_t value)
{
	view.can_status_mcs_rear_ec_update_value(value);
}

void Screen3Presenter::can_status_mcs_l_motor_driver_update_value(uint32_t value)
{
	view.can_status_mcs_l_motor_driver_update_value(value);
}

void Screen3Presenter::can_status_mcs_r_motor_driver_update_value(uint32_t value)
{
	view.can_status_mcs_r_motor_driver_update_value(value);
}

void Screen3Presenter::can_status_mcs_ams_update_value(uint32_t value)
{
	view.can_status_mcs_ams_update_value(value);
}

