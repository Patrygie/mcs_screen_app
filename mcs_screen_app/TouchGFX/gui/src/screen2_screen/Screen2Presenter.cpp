#include <gui/screen2_screen/Screen2View.hpp>
#include <gui/screen2_screen/Screen2Presenter.hpp>

#include "main.h"

Screen2Presenter::Screen2Presenter(Screen2View& v)
    : view(v)
{

}

void Screen2Presenter::activate()
{

}

void Screen2Presenter::deactivate()
{

}

void Screen2Presenter::map_update_value(uint32_t value)		//funkcja dodana
{
	view.map_update_value(value);
}

void Screen2Presenter::tc_update_value(uint32_t value)
{
	view.tc_update_value(value);
}

void Screen2Presenter::speed_update_value(uint32_t value)
{
	view.speed_update_value(value);
}

void Screen2Presenter::diff_update_value(uint32_t value)
{
	view.diff_update_value(value);
}

void Screen2Presenter::tsac_update_value(uint32_t value)
{
	view.tsac_update_value(value);
}

void Screen2Presenter::leng_update_value(uint32_t value)
{
	view.leng_update_value(value);
}

void Screen2Presenter::linv_update_value(uint32_t value)
{
	view.linv_update_value(value);
}

void Screen2Presenter::bat_update_value(uint32_t value)
{
	view.bat_update_value(value);
}

void Screen2Presenter::rinv_update_value(uint32_t value)
{
	view.rinv_update_value(value);
}

void Screen2Presenter::reng_update_value(uint32_t value)
{
	view.reng_update_value(value);
}

void Screen2Presenter::err_update_value(uint32_t value)
{
	view.err_update_value(value);
}

void Screen2Presenter::hv_update_value(uint32_t value)
{
	view.hv_update_value(value);
}

void Screen2Presenter::low_update_value(uint32_t value)
{
	view.low_update_value(value);
}

void Screen2Presenter::p2d_update_value(uint32_t value)
{
	view.p2d_update_value(value);
}

void Screen2Presenter::ts_update_value(uint32_t value)
{
	view.ts_update_value(value);
}

void Screen2Presenter::gas_update_value(uint32_t value)
{
	view.gas_update_value(value);
}
