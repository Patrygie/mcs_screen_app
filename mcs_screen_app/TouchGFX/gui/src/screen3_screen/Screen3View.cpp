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

void Screen3View::can_status_mcs_scrn_update_value(uint32_t value)
{
	if(value == true)
	{
		img_scrn_ok.setBitmap(Bitmap(BITMAP_CAN_STATUS_2C_ID));
		img_scrn_ok.invalidate();
	}
	else if(value == false)
	{
		img_scrn_ok.setBitmap(Bitmap(BITMAP_CAN_STATUS_2B_ID));
		img_scrn_ok.invalidate();
	}
}

void Screen3View::can_status_mcs_main_update_value(uint32_t value)
{
	if(value == true)
	{
		img_main_ok.setBitmap(Bitmap(BITMAP_CAN_STATUS_2C_ID));
		img_main_ok.invalidate();
	}
	else if(value == false)
	{
		img_main_ok.setBitmap(Bitmap(BITMAP_CAN_STATUS_2B_ID));
		img_main_ok.invalidate();
	}
}

void Screen3View::can_status_mcs_hv_update_value(uint32_t value)
{
	if(value == true)
	{
		img_hv_ok.setBitmap(Bitmap(BITMAP_CAN_STATUS_2C_ID));
		img_hv_ok.invalidate();
	}
	else if(value == false)
	{
		img_hv_ok.setBitmap(Bitmap(BITMAP_CAN_STATUS_2B_ID));
		img_hv_ok.invalidate();
	}
}

void Screen3View::can_status_mcs_lv_update_value(uint32_t value)
{
	if(value == true)
	{
		img_lv_ok.setBitmap(Bitmap(BITMAP_CAN_STATUS_2C_ID));
		img_lv_ok.invalidate();
	}
	else if(value == false)
	{
		img_lv_ok.setBitmap(Bitmap(BITMAP_CAN_STATUS_2B_ID));
		img_lv_ok.invalidate();
	}
}

void Screen3View::can_status_mcs_front_sens_update_value(uint32_t value)
{
	if(value == true)
	{
		img_front_sens_ok.setBitmap(Bitmap(BITMAP_CAN_STATUS_2C_ID));
		img_front_sens_ok.invalidate();
	}
	else if(value == false)
	{
		img_front_sens_ok.setBitmap(Bitmap(BITMAP_CAN_STATUS_2B_ID));
		img_front_sens_ok.invalidate();
	}
}

void Screen3View::can_status_mcs_rear_ec_update_value(uint32_t value)
{
	if(value == true)
	{
		img_rear_ec_ok.setBitmap(Bitmap(BITMAP_CAN_STATUS_2C_ID));
		img_rear_ec_ok.invalidate();
	}
	else if(value == false)
	{
		img_rear_ec_ok.setBitmap(Bitmap(BITMAP_CAN_STATUS_2B_ID));
		img_rear_ec_ok.invalidate();
	}
}

void Screen3View::can_status_mcs_l_motor_driver_update_value(uint32_t value)
{
	if(value == true)
	{
		img_l_motor_driver_ok.setBitmap(Bitmap(BITMAP_CAN_STATUS_2C_ID));
		img_l_motor_driver_ok.invalidate();
	}
	else if(value == false)
	{
		img_l_motor_driver_ok.setBitmap(Bitmap(BITMAP_CAN_STATUS_2B_ID));
		img_l_motor_driver_ok.invalidate();
	}
}

void Screen3View::can_status_mcs_r_motor_driver_update_value(uint32_t value)
{
	if(value == true)
	{
		img_r_motor_driver_ok.setBitmap(Bitmap(BITMAP_CAN_STATUS_2C_ID));
		img_r_motor_driver_ok.invalidate();
	}
	else if(value == false)
	{
		img_r_motor_driver_ok.setBitmap(Bitmap(BITMAP_CAN_STATUS_2B_ID));
		img_r_motor_driver_ok.invalidate();
	}
}

void Screen3View::can_status_mcs_ams_update_value(uint32_t value)
{
	if(value == true)
	{
		img_ams_ok.setBitmap(Bitmap(BITMAP_CAN_STATUS_2C_ID));
		img_ams_ok.invalidate();
	}
	else if(value == false)
	{
		img_ams_ok.setBitmap(Bitmap(BITMAP_CAN_STATUS_2B_ID));
		img_ams_ok.invalidate();
	}
}
