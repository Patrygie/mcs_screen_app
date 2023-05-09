#ifndef SCREEN4PRESENTER_HPP
#define SCREEN4PRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class Screen4View;

class Screen4Presenter : public touchgfx::Presenter, public ModelListener
{
public:
    Screen4Presenter(Screen4View& v);

    /**
     * The activate function is called automatically when this screen is "switched in"
     * (ie. made active). Initialization logic can be placed here.
     */
    virtual void activate();

    /**
     * The deactivate function is called automatically when this screen is "switched out"
     * (ie. made inactive). Teardown functionality can be placed here.
     */
    virtual void deactivate();

    virtual ~Screen4Presenter() {};

    void car_config_brake_min_update_value(uint32_t value) override;
    void car_config_brake_max_update_value(uint32_t value) override;
    void car_config_brake_rel_update_value(uint32_t value) override;
    void car_config_brake_rel_accepted_value(uint32_t value) override;
    void car_config_throttle_min_update_value(uint32_t value) override;
    void car_config_throttle_max_update_value(uint32_t value) override;
    void car_config_throttle_rel_update_value(uint32_t value) override;
    void car_config_throttle_rel_accepted_value(uint32_t value) override;
    void car_config_select_stationary_mode_value(uint32_t value) override;
    void car_config_select_driving_mode_value(uint32_t value) override;
    void car_config_select_repeat_calibration_value(uint32_t value) override;
    void car_config_dashboard_reset_value(uint32_t value) override;

private:
    Screen4Presenter();

    Screen4View& view;
};

#endif // SCREEN4PRESENTER_HPP
