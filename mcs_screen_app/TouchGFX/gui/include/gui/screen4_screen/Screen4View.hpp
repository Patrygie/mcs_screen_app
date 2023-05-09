#ifndef SCREEN4VIEW_HPP
#define SCREEN4VIEW_HPP

#include <gui_generated/screen4_screen/Screen4ViewBase.hpp>
#include <gui/screen4_screen/Screen4Presenter.hpp>

class Screen4View : public Screen4ViewBase
{
public:
    Screen4View();
    virtual ~Screen4View() {}
    virtual void setupScreen();
    virtual void tearDownScreen();

    void car_config_brake_min_update_value(uint32_t value);
    void car_config_brake_max_update_value(uint32_t value);
    void car_config_brake_rel_update_value(uint32_t value);
    void car_config_brake_rel_accepted_value(uint32_t value);
    void car_config_throttle_min_update_value(uint32_t value);
    void car_config_throttle_max_update_value(uint32_t value);
    void car_config_throttle_rel_update_value(uint32_t value);
    void car_config_throttle_rel_accepted_value(uint32_t value);
    void car_config_select_stationary_mode_value(uint32_t value);
    void car_config_select_driving_mode_value(uint32_t value);
    void car_config_select_repeat_calibration_value(uint32_t value);
    void car_config_dashboard_reset_value(uint32_t value);

protected:
};

#endif // SCREEN4VIEW_HPP
