#ifndef SCREEN3VIEW_HPP
#define SCREEN3VIEW_HPP

#include <gui_generated/screen3_screen/Screen3ViewBase.hpp>
#include <gui/screen3_screen/Screen3Presenter.hpp>

class Screen3View : public Screen3ViewBase
{
public:
    Screen3View();
    virtual ~Screen3View() {}
    virtual void setupScreen();
    virtual void tearDownScreen();

    void btn_update_value(uint32_t value);
    void can_status_mcs_main_update_value(uint32_t value);
    void can_status_mcs_hv_update_value(uint32_t value);

protected:
};

#endif // SCREEN3VIEW_HPP
