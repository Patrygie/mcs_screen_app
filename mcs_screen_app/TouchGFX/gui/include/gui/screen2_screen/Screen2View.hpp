#ifndef SCREEN2VIEW_HPP
#define SCREEN2VIEW_HPP

#include <gui_generated/screen2_screen/Screen2ViewBase.hpp>
#include <gui/screen2_screen/Screen2Presenter.hpp>

class Screen2View : public Screen2ViewBase
{
public:
    Screen2View();
    virtual ~Screen2View() {}
    virtual void setupScreen();
    virtual void tearDownScreen();

    void p2d_update_value(uint32_t value);
    void ts_update_value(uint32_t value);
    void map_update_value(uint32_t value);	//dodane
    void tc_update_value(uint32_t value);
    void speed_update_value(uint32_t value);
    void diff_update_value(uint32_t value);
    void tsac_update_value(uint32_t value);
    void leng_update_value(uint32_t value);
    void linv_update_value(uint32_t value);
    void bat_update_value(uint32_t value);
    void rinv_update_value(uint32_t value);
    void reng_update_value(uint32_t value);
    void err_update_value(uint32_t value);
    void hv_update_value(uint32_t value);
    void low_update_value(uint32_t value);
    void drive_throttle_update_value(uint32_t value);
    void drive_select_map_update_value(uint32_t value);
    void drive_select_tc_update_value(uint32_t value);
    void drive_select_diff_update_value(uint32_t value);
    void drive_select_tsac_update_value(uint32_t value);

protected:
};

#endif // SCREEN2VIEW_HPP
