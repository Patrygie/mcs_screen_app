#include <gui/screen4_screen/Screen4View.hpp>

#include "BitmapDatabase.hpp"

Screen4View::Screen4View()
{

}

void Screen4View::setupScreen()
{
    Screen4ViewBase::setupScreen();
}

void Screen4View::tearDownScreen()
{
    Screen4ViewBase::tearDownScreen();
}

void Screen4View::car_config_brake_min_update_value(uint32_t value)
{
	img_brake_min_ok.setBitmap(Bitmap(BITMAP_CAR_COFIG_2A_ID));

	Unicode::snprintf(ta_brake_min_valueBuffer, TA_BRAKE_MIN_VALUE_SIZE, "%d", value);
	ta_brake_min_value.resizeToCurrentTextWithAlignment();

	ta_brake_min_set.setAlpha(255);
	c_brake_min.invalidate();

	img_brake_max_ok.setBitmap(Bitmap(BITMAP_CAR_COFIG_2B_ID));
	img_brake_max_ok.setAlpha(255);
	img_brake_max_ok.invalidate();
}

void Screen4View::car_config_brake_max_update_value(uint32_t value)
{
	img_brake_max_ok.setBitmap(Bitmap(BITMAP_CAR_COFIG_2A_ID));

	Unicode::snprintf(ta_brake_max_valueBuffer, TA_BRAKE_MAX_VALUE_SIZE, "%d", value);
	ta_brake_max_value.resizeToCurrentTextWithAlignment();

	ta_brake_max_set.setAlpha(255);
	c_brake_max.invalidate();

	img_brake_release_ok.setBitmap(Bitmap(BITMAP_CAR_COFIG_2B_ID));
	img_brake_release_ok.setAlpha(255);
	img_brake_release_ok.invalidate();
}