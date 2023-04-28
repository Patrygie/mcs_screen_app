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
