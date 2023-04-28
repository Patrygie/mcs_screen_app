#ifndef SCREEN3PRESENTER_HPP
#define SCREEN3PRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class Screen3View;

class Screen3Presenter : public touchgfx::Presenter, public ModelListener
{
public:
    Screen3Presenter(Screen3View& v);

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

    virtual ~Screen3Presenter() {};

    void can_status_mcs_scrn_update_value(uint32_t value) override;
    void can_status_mcs_main_update_value(uint32_t value) override;
    void can_status_mcs_hv_update_value(uint32_t value) override;
    void can_status_mcs_lv_update_value(uint32_t value) override;
    void can_status_mcs_front_sens_update_value(uint32_t value) override;
    void can_status_mcs_rear_ec_update_value(uint32_t value) override;
    void can_status_mcs_l_motor_driver_update_value(uint32_t value) override;
    void can_status_mcs_r_motor_driver_update_value(uint32_t value) override;
    void can_status_mcs_ams_update_value(uint32_t value) override;

private:
    Screen3Presenter();

    Screen3View& view;
};

#endif // SCREEN3PRESENTER_HPP
