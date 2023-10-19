#include <gui/screen2_screen/Screen2View.hpp>

#include "BitmapDatabase.hpp"

Screen2View::Screen2View()
{

}

void Screen2View::setupScreen()
{
    Screen2ViewBase::setupScreen();
}

void Screen2View::tearDownScreen()
{
    Screen2ViewBase::tearDownScreen();
}

void Screen2View::map_update_value(uint32_t value)
{
	ta_map_value.invalidate();

	switch(value)
	{
	case 1:
		Unicode::snprintf(ta_map_valueBuffer, TA_MAP_VALUE_SIZE, "SP");
		break;
	case 2:
		Unicode::snprintf(ta_map_valueBuffer, TA_MAP_VALUE_SIZE, "AX");
		break;
	case 3:
		Unicode::snprintf(ta_map_valueBuffer, TA_MAP_VALUE_SIZE, "EN");
		break;
	case 4:
		Unicode::snprintf(ta_map_valueBuffer, TA_MAP_VALUE_SIZE, "ACC");
		break;
	}

	ta_map_value.resizeToCurrentTextWithAlignment();
	ta_map_value.centerX();
	ta_map_value.invalidate();
}

void Screen2View::tc_update_value(uint32_t value)
{
	ta_tc_value.invalidate();
	Unicode::snprintf(ta_tc_valueBuffer, TA_TC_VALUE_SIZE, "%d", value);
	ta_tc_value.resizeToCurrentTextWithAlignment();
	ta_tc_value.centerX();
	ta_tc_value.invalidate();
}

void Screen2View::speed_update_value(uint32_t value)
{
	Unicode::snprintf(ta_speed_valueBuffer, TA_SPEED_VALUE_SIZE, "%d", value);
	ta_speed_value.resizeToCurrentTextWithAlignment();
	ta_speed_value.centerX();
	c_speed.invalidate();
}

void Screen2View::diff_update_value(uint32_t value)
{
	ta_diff_value.invalidate();
	Unicode::snprintf(ta_diff_valueBuffer, TA_DIFF_VALUE_SIZE, "%d", value);
	ta_diff_value.resizeToCurrentTextWithAlignment();
	ta_diff_value.centerX();
	ta_diff_value.invalidate();
}

void Screen2View::tsac_update_value(uint32_t value)
{
	ta_tsac_value.invalidate();
	Unicode::snprintf(ta_tsac_valueBuffer, TA_TSAC_VALUE_SIZE, "%d", value);
	ta_tsac_value.resizeToCurrentTextWithAlignment();
	ta_tsac_value.centerX();
	ta_tsac_value.invalidate();
}

void Screen2View::leng_update_value(uint32_t value)
{
	Unicode::snprintf(ta_leng_valueBuffer, TA_LENG_VALUE_SIZE, "%d", value);
	ta_leng_value.resizeToCurrentTextWithAlignment();
	ta_leng_value.centerX();

	if(value <= 255-10)
	{
		img_leng.setBitmap(Bitmap(BITMAP_DRIVE_3_ID));
		img_leng.invalidate();
	}

	else if(value <= 255-5 && value > 255-10)
	{
		img_leng.setBitmap(Bitmap(BITMAP_DRIVE_3_YELLOW_ID));
		img_leng.invalidate();
	}

	else if(value > 255-5)
	{
		img_leng.setBitmap(Bitmap(BITMAP_DRIVE_3_RED_ID));
		img_leng.invalidate();
	}

	c_leng.invalidate();
}

void Screen2View::linv_update_value(uint32_t value)
{
	Unicode::snprintf(ta_linv_valueBuffer, TA_LINV_VALUE_SIZE, "%d", value);
	ta_linv_value.resizeToCurrentTextWithAlignment();
	ta_linv_value.centerX();

	if(value <= 255-10)
	{
		img_linv.setBitmap(Bitmap(BITMAP_DRIVE_3_ID));
		img_linv.invalidate();
	}

	else if(value <= 255-5 && value > 255-10)
	{
		img_linv.setBitmap(Bitmap(BITMAP_DRIVE_3_YELLOW_ID));
		img_linv.invalidate();
	}

	else if(value > 255-5)
	{
		img_linv.setBitmap(Bitmap(BITMAP_DRIVE_3_RED_ID));
		img_linv.invalidate();
	}

	c_linv.invalidate();
}

void Screen2View::bat_update_value(uint32_t value)
{
	Unicode::snprintf(ta_bat_valueBuffer, TA_BAT_VALUE_SIZE, "%d", value);
	ta_bat_value.resizeToCurrentTextWithAlignment();
	ta_bat_value.centerX();
	c_bat.invalidate();
}

void Screen2View::rinv_update_value(uint32_t value)
{
	Unicode::snprintf(ta_rinv_valueBuffer, TA_RINV_VALUE_SIZE, "%d", value);
	ta_rinv_value.resizeToCurrentTextWithAlignment();
	ta_rinv_value.centerX();

	if(value <= 255-10)
	{
		img_rinv.setBitmap(Bitmap(BITMAP_DRIVE_3_ID));
		img_rinv.invalidate();
	}

	else if(value <= 255-5 && value > 255-10)
	{
		img_rinv.setBitmap(Bitmap(BITMAP_DRIVE_3_YELLOW_ID));
		img_rinv.invalidate();
	}

	else if(value > 255-5)
	{
		img_rinv.setBitmap(Bitmap(BITMAP_DRIVE_3_RED_ID));
		img_rinv.invalidate();
	}

	c_rinv.invalidate();
}

void Screen2View::reng_update_value(uint32_t value)
{
	Unicode::snprintf(ta_reng_valueBuffer, TA_RENG_VALUE_SIZE, "%d", value);
	ta_reng_value.resizeToCurrentTextWithAlignment();
	ta_reng_value.centerX();

	if(value <= 255-10)
	{
		img_reng.setBitmap(Bitmap(BITMAP_DRIVE_3_ID));
		img_reng.invalidate();
	}

	else if(value <= 255-5 && value > 255-10)
	{
		img_reng.setBitmap(Bitmap(BITMAP_DRIVE_3_YELLOW_ID));
		img_reng.invalidate();
	}

	else if(value > 255-5)
	{
		img_reng.setBitmap(Bitmap(BITMAP_DRIVE_3_RED_ID));
		img_reng.invalidate();
	}

	c_reng.invalidate();
}

void Screen2View::err_update_value(uint32_t value)
{
	Unicode::snprintf(ta_err_valueBuffer, TA_ERR_VALUE_SIZE, "%d", value);
	ta_err_value.resizeToCurrentTextWithAlignment();
	ta_err_value.centerX();
	c_err.invalidate();
}

void Screen2View::hv_update_value(uint32_t value)
{
	Unicode::snprintf(ta_hv_valueBuffer, TA_HV_VALUE_SIZE,"%d%", value);
	ta_hv_value.invalidate();

	ip_hv_visual.setValue(value / 10);
	ip_hv_visual.invalidate();
}

void Screen2View::low_update_value(uint32_t value)
{
	Unicode::snprintf(ta_low_valueBuffer, TA_LOW_VALUE_SIZE, "%d", value);
	ta_low_value.resizeToCurrentTextWithAlignment();
	ta_low_value.centerX();

	if(value > 255*0.3)
	{
		img_low.setBitmap(Bitmap(BITMAP_DRIVE_3_ID));
		img_low.invalidate();
	}

	else if(value <= 255*0.3 && value > 255*0.1)
	{
		img_low.setBitmap(Bitmap(BITMAP_DRIVE_3_YELLOW_ID));
		img_low.invalidate();
	}

	else if(value <= 255*0.1)
	{
		img_low.setBitmap(Bitmap(BITMAP_DRIVE_3_RED_ID));
		img_low.invalidate();
	}

	c_low.invalidate();
}

void Screen2View::p2d_update_value(uint32_t value)
{
	if(value == 1)
	{
		img_p2d.setBitmap(Bitmap(BITMAP_DRIVE_10A_GREEN_ID));
		img_p2d.invalidate();
	}
}

void Screen2View::ts_update_value(uint32_t value)
{
	if(value == 1)
	{
		img_ts.setBitmap(Bitmap(BITMAP_DRIVE_10A_GREEN_ID));
		img_ts.invalidate();
	}
}

void Screen2View::drive_throttle_update_value(uint32_t value)
{
	ip_gas_visual.setValue(value);
	ip_gas_visual.invalidate();
}

void Screen2View::drive_select_map_update_value(uint32_t value)
{
	if(value == 1)
	{
		img_map.setBitmap(Bitmap(BITMAP_DRIVE_1_BLUE_ID));
		img_map.invalidate();
		img_tc.setBitmap(Bitmap(BITMAP_DRIVE_1_ID));
		img_tc.invalidate();
		img_tsac.setBitmap(Bitmap(BITMAP_DRIVE_1_ID));
		img_tsac.invalidate();
		img_diff.setBitmap(Bitmap(BITMAP_DRIVE_1_ID));
		img_diff.invalidate();
	}
	else
	{
		img_map.setBitmap(Bitmap(BITMAP_DRIVE_1_ID));
		img_map.invalidate();
	}
}

void Screen2View::drive_select_tc_update_value(uint32_t value)
{
	if(value == 1)
	{
		img_tc.setBitmap(Bitmap(BITMAP_DRIVE_1_BLUE_ID));
		img_tc.invalidate();
		img_map.setBitmap(Bitmap(BITMAP_DRIVE_1_ID));
		img_map.invalidate();
		img_diff.setBitmap(Bitmap(BITMAP_DRIVE_1_ID));
		img_diff.invalidate();
		img_tsac.setBitmap(Bitmap(BITMAP_DRIVE_1_ID));
		img_tsac.invalidate();
	}
	else
	{
		img_tc.setBitmap(Bitmap(BITMAP_DRIVE_1_ID));
		img_tc.invalidate();
	}
}

void Screen2View::drive_select_diff_update_value(uint32_t value)
{
	if(value == 1)
	{
		img_diff.setBitmap(Bitmap(BITMAP_DRIVE_1_BLUE_ID));
		img_diff.invalidate();
		img_tc.setBitmap(Bitmap(BITMAP_DRIVE_1_ID));
		img_tc.invalidate();
		img_tsac.setBitmap(Bitmap(BITMAP_DRIVE_1_ID));
		img_tsac.invalidate();
		img_map.setBitmap(Bitmap(BITMAP_DRIVE_1_ID));
		img_map.invalidate();
	}
	else
	{
		img_diff.setBitmap(Bitmap(BITMAP_DRIVE_1_ID));
		img_diff.invalidate();
	}
}

void Screen2View::drive_select_tsac_update_value(uint32_t value)
{
	if(value == 1)
	{
		img_tsac.setBitmap(Bitmap(BITMAP_DRIVE_1_BLUE_ID));
		img_tsac.invalidate();
		img_diff.setBitmap(Bitmap(BITMAP_DRIVE_1_ID));
		img_diff.invalidate();
		img_map.setBitmap(Bitmap(BITMAP_DRIVE_1_ID));
		img_map.invalidate();
		img_tc.setBitmap(Bitmap(BITMAP_DRIVE_1_ID));
		img_tc.invalidate();
	}
	else
	{
		img_tsac.setBitmap(Bitmap(BITMAP_DRIVE_1_ID));
		img_tsac.invalidate();
	}
}
