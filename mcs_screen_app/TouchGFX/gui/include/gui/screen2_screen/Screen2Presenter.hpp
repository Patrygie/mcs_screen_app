#ifndef SCREEN2PRESENTER_HPP
#define SCREEN2PRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class Screen2View;

class Screen2Presenter : public touchgfx::Presenter, public ModelListener
{
public:
    Screen2Presenter(Screen2View& v);

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

    virtual ~Screen2Presenter() {};

    void p2d_update_value(uint32_t value) override;
    void ts_update_value(uint32_t value) override;
    void map_update_value(uint32_t value) override;
    void tc_update_value(uint32_t value) override;
    void speed_update_value(uint32_t value) override;
    void diff_update_value(uint32_t value) override;
    void tsac_update_value(uint32_t value) override;
    void leng_update_value(uint32_t value) override;
    void linv_update_value(uint32_t value) override;
    void bat_update_value(uint32_t value) override;
    void rinv_update_value(uint32_t value) override;
    void reng_update_value(uint32_t value) override;
    void err_update_value(uint32_t value) override;
    void hv_update_value(uint32_t value) override;
    void low_update_value(uint32_t value) override;
    void drive_throttle_update_value(uint32_t value) override;
    void drive_select_map_update_value(uint32_t value) override;
    void drive_select_tc_update_value(uint32_t value) override;
    void drive_select_diff_update_value(uint32_t value) override;
    void drive_select_tsac_update_value(uint32_t value) override;

private:
    Screen2Presenter();

    Screen2View& view;
};

#endif // SCREEN2PRESENTER_HPP
