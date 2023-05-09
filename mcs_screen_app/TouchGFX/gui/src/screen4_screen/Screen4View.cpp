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
	ta_brake_min_value.setAlpha(255);

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
	ta_brake_max_value.setAlpha(255);

	ta_brake_max_set.setAlpha(255);
	c_brake_max.invalidate();

	img_brake_release_ok.setBitmap(Bitmap(BITMAP_CAR_COFIG_2B_ID));
	img_brake_release_ok.setAlpha(255);
	img_brake_release_ok.invalidate();
}

void Screen4View::car_config_brake_rel_update_value(uint32_t value)
{
	ta_brake_release_value.setAlpha(255);
	Unicode::snprintf(ta_brake_release_valueBuffer, TA_BRAKE_RELEASE_VALUE_SIZE, "%d", value);
	ta_brake_release_value.resizeToCurrentTextWithAlignment();
	c_brake_release.invalidate();
}

void Screen4View::car_config_brake_rel_accepted_value(uint32_t value)
{
	ta_brake_release_checked.setAlpha(255);
	ta_brake_release_checked.invalidate();

	img_brake_release_ok.setBitmap(Bitmap(BITMAP_CAR_COFIG_2A_ID));
	c_brake_release.invalidate();

	img_throttle_min_ok.setBitmap(Bitmap(BITMAP_CAR_COFIG_2B_ID));
	img_throttle_min_ok.setAlpha(255);
	img_throttle_min_ok.invalidate();
}

void Screen4View::car_config_throttle_min_update_value(uint32_t value)
{
	img_throttle_min_ok.setBitmap(Bitmap(BITMAP_CAR_COFIG_2A_ID));

	Unicode::snprintf(ta_throttle_min_valueBuffer, TA_THROTTLE_MIN_VALUE_SIZE, "%d", value);
	ta_throttle_min_value.resizeToCurrentTextWithAlignment();
	ta_throttle_min_value.setAlpha(255);

	ta_throttle_min_set.setAlpha(255);
	c_throttle_min.invalidate();

	img_throttle_max_ok.setBitmap(Bitmap(BITMAP_CAR_COFIG_2B_ID));
	img_throttle_max_ok.setAlpha(255);
	img_throttle_max_ok.invalidate();
}

void Screen4View::car_config_throttle_max_update_value(uint32_t value)
{
	img_throttle_max_ok.setBitmap(Bitmap(BITMAP_CAR_COFIG_2A_ID));

	Unicode::snprintf(ta_throttle_max_valueBuffer, TA_THROTTLE_MAX_VALUE_SIZE, "%d", value);
	ta_throttle_max_value.resizeToCurrentTextWithAlignment();
	ta_throttle_max_value.setAlpha(255);

	ta_throttle_max_set.setAlpha(255);
	c_throttle_max.invalidate();

	img_throttle_release_ok.setBitmap(Bitmap(BITMAP_CAR_COFIG_2B_ID));
	img_throttle_release_ok.setAlpha(255);
	img_throttle_release_ok.invalidate();
}

void Screen4View::car_config_throttle_rel_update_value(uint32_t value)
{
	ta_throttle_release_value.setAlpha(255);
	Unicode::snprintf(ta_throttle_release_valueBuffer, TA_THROTTLE_RELEASE_VALUE_SIZE, "%d", value);
	ta_throttle_release_value.resizeToCurrentTextWithAlignment();
	c_throttle_release.invalidate();
}

void Screen4View::car_config_throttle_rel_accepted_value(uint32_t value)
{
	ta_throttle_release_checked.setAlpha(255);
	ta_throttle_release_checked.invalidate();

	img_throttle_release_ok.setBitmap(Bitmap(BITMAP_CAR_COFIG_2A_ID));
	c_throttle_release.invalidate();
}

void Screen4View::car_config_select_stationary_mode_value(uint32_t value)
{
////////////////// żeby na pewno się wyświetliło ///////////////////////////
	img_throttle_release_ok.setBitmap(Bitmap(BITMAP_CAR_COFIG_2A_ID));
	ta_throttle_release_checked.setAlpha(255);
	c_throttle_release.invalidate();

//	img_brake_max_ok.setAlpha(255);
//	ta_brake_max_set.setAlpha(255);
//	ta_brake_max_value.setAlpha(255);
//	c_brake_max.invalidate();

////////////////////////////////////////////////////////////////////////////

	img_stationary_mode.setBitmap(Bitmap(BITMAP_CAR_COFIG_3B_ID));
	img_stationary_mode.invalidate();

	img_repeat_calibration.setBitmap(Bitmap(BITMAP_CAR_COFIG_3_ID));
	img_repeat_calibration.invalidate();

}

void Screen4View::car_config_select_driving_mode_value(uint32_t value)
{
	img_driving_mode.setBitmap(Bitmap(BITMAP_CAR_COFIG_3B_ID));
	img_driving_mode.invalidate();

	img_stationary_mode.setBitmap(Bitmap(BITMAP_CAR_COFIG_3_ID));
	img_stationary_mode.invalidate();
}

void Screen4View::car_config_select_repeat_calibration_value(uint32_t value)
{
	img_repeat_calibration.setBitmap(Bitmap(BITMAP_CAR_COFIG_3B_ID));
	img_repeat_calibration.invalidate();

	img_driving_mode.setBitmap(Bitmap(BITMAP_CAR_COFIG_3_ID));
	img_driving_mode.invalidate();
}

void Screen4View::car_config_dashboard_reset_value(uint32_t value)
{
	img_brake_min_ok.setBitmap(Bitmap(BITMAP_CAR_COFIG_2B_ID));
	ta_brake_min_value.setAlpha(0);
	ta_brake_min_set.setAlpha(0);
	c_brake_min.invalidate();

	img_brake_max_ok.setAlpha(0);
	ta_brake_max_value.setAlpha(0);
	ta_brake_max_set.setAlpha(0);
	c_brake_max.invalidate();

	img_brake_release_ok.setAlpha(0);
	ta_brake_release_value.setAlpha(0);
	ta_brake_release_checked.setAlpha(0);
	c_brake_release.invalidate();

	img_throttle_min_ok.setAlpha(0);
	ta_throttle_min_value.setAlpha(0);
	ta_throttle_min_set.setAlpha(0);
	c_throttle_min.invalidate();

	img_throttle_max_ok.setAlpha(0);
	ta_throttle_max_value.setAlpha(0);
	ta_throttle_max_set.setAlpha(0);
	c_throttle_max.invalidate();

	img_throttle_release_ok.setAlpha(0);
	ta_throttle_release_value.setAlpha(0);
	ta_throttle_release_checked.setAlpha(0);
	c_throttle_release.invalidate();

	img_repeat_calibration.setBitmap(Bitmap(BITMAP_CAR_COFIG_3_ID));
	img_repeat_calibration.invalidate();
}
