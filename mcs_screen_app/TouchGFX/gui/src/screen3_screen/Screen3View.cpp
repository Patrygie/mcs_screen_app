#include <gui/screen3_screen/Screen3View.hpp>

#include "BitmapDatabase.hpp"

Screen3View::Screen3View()
{

}

void Screen3View::setupScreen()
{
    Screen3ViewBase::setupScreen();
}

void Screen3View::tearDownScreen()
{
    Screen3ViewBase::tearDownScreen();
}

void Screen3View::btn_update_value(uint32_t value)
{
//	if(value == 1)
//	{
		img_scrn_ok.setBitmap(Bitmap(BITMAP_CAN_STATUS_2C_ID));
		img_scrn_ok.invalidate();
//	}
}

void Screen3View::can_status_mcs_main_update_value(uint32_t value)
{
		img_main_ok.setBitmap(Bitmap(BITMAP_CAN_STATUS_2C_ID));
		img_main_ok.invalidate();
}

void Screen3View::can_status_mcs_hv_update_value(uint32_t value)
{
		img_hv_ok.setBitmap(Bitmap(BITMAP_CAN_STATUS_2C_ID));
		img_hv_ok.invalidate();
}
