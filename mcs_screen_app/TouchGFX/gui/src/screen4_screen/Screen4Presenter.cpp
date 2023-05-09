#include <gui/screen4_screen/Screen4View.hpp>
#include <gui/screen4_screen/Screen4Presenter.hpp>

#include "main.h"

Screen4Presenter::Screen4Presenter(Screen4View& v)
    : view(v)
{

}

void Screen4Presenter::activate()
{

}

void Screen4Presenter::deactivate()
{

}

void Screen4Presenter::car_config_brake_min_update_value(uint32_t value)
{
	view.car_config_brake_min_update_value(value);
}

void Screen4Presenter::car_config_brake_max_update_value(uint32_t value)
{
	view.car_config_brake_max_update_value(value);
}

void Screen4Presenter::car_config_brake_rel_update_value(uint32_t value)
{
	view.car_config_brake_rel_update_value(value);
}

void Screen4Presenter::car_config_brake_rel_accepted_value(uint32_t value)
{
	view.car_config_brake_rel_accepted_value(value);
}

void Screen4Presenter::car_config_throttle_min_update_value(uint32_t value)
{
	view.car_config_throttle_min_update_value(value);
}

void Screen4Presenter::car_config_throttle_max_update_value(uint32_t value)
{
	view.car_config_throttle_max_update_value(value);
}

void Screen4Presenter::car_config_throttle_rel_update_value(uint32_t value)
{
	view.car_config_throttle_rel_update_value(value);
}

void Screen4Presenter::car_config_throttle_rel_accepted_value(uint32_t value)
{
	view.car_config_throttle_rel_accepted_value(value);
}

void Screen4Presenter::car_config_select_stationary_mode_value(uint32_t value)
{
	view.car_config_select_stationary_mode_value(value);
}

void Screen4Presenter::car_config_select_driving_mode_value(uint32_t value)
{
	view.car_config_select_driving_mode_value(value);
}

void Screen4Presenter::car_config_select_repeat_calibration_value(uint32_t value)
{
	view.car_config_select_repeat_calibration_value(value);
}

void Screen4Presenter::car_config_dashboard_reset_value(uint32_t value)
{
	view.car_config_dashboard_reset_value(value);
}
