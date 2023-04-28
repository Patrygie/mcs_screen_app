/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#ifndef SCREEN4VIEWBASE_HPP
#define SCREEN4VIEWBASE_HPP

#include <gui/common/FrontendApplication.hpp>
#include <mvp/View.hpp>
#include <gui/screen4_screen/Screen4Presenter.hpp>
#include <touchgfx/widgets/Box.hpp>
#include <touchgfx/widgets/Image.hpp>
#include <touchgfx/widgets/TextArea.hpp>
#include <touchgfx/containers/Container.hpp>
#include <touchgfx/widgets/TextAreaWithWildcard.hpp>

class Screen4ViewBase : public touchgfx::View<Screen4Presenter>
{
public:
    Screen4ViewBase();
    virtual ~Screen4ViewBase();
    virtual void setupScreen();

protected:
    FrontendApplication& application() {
        return *static_cast<FrontendApplication*>(touchgfx::Application::getInstance());
    }

    /*
     * Member Declarations
     */
    touchgfx::Box __background;
    touchgfx::Box car_config_background;
    touchgfx::Image img_car_config;
    touchgfx::TextArea ta_car_config_title;
    touchgfx::Image img_driving_mode;
    touchgfx::Image img_stationary_mode;
    touchgfx::Image img_repeat_calibration;
    touchgfx::TextArea ta_stationary_mode;
    touchgfx::TextArea ta_driving_mode;
    touchgfx::TextArea ta_repeat_calibration;
    touchgfx::Container c_brake_min;
    touchgfx::TextArea ta_brake_min_set;
    touchgfx::TextAreaWithOneWildcard ta_brake_min_value;
    touchgfx::Image img_brake_min_ok;
    touchgfx::TextArea ta_brake_min_title;
    touchgfx::Container c_brake_max;
    touchgfx::Image img_brake_max_ok;
    touchgfx::TextArea ta_brake_max;
    touchgfx::TextAreaWithOneWildcard ta_brake_max_value;
    touchgfx::TextArea ta_brake_max_set;
    touchgfx::Container c_brake_release;
    touchgfx::TextArea ta_brake_release;
    touchgfx::Image img_brake_release_ok;
    touchgfx::TextAreaWithOneWildcard ta_brake_release_value;
    touchgfx::TextArea ta_brake_release_checked;
    touchgfx::Container c_throttle_min;
    touchgfx::Image img_throttle_min_ok;
    touchgfx::TextArea ta_throttle_min;
    touchgfx::TextAreaWithOneWildcard ta_throttle_min_value;
    touchgfx::TextArea ta_throttle_min_set;
    touchgfx::Container c_throttle_max;
    touchgfx::Image img_throttle_max_ok;
    touchgfx::TextArea ta_throttle_max;
    touchgfx::TextAreaWithOneWildcard ta_throttle_max_value;
    touchgfx::TextArea ta_throttle_max_set;
    touchgfx::Container c_throttle_release;
    touchgfx::Image img_throttle_release_ok;
    touchgfx::TextArea ta_throttle_release;
    touchgfx::TextAreaWithOneWildcard ta_throttle_release_value;
    touchgfx::TextArea ta_throttle_release_checked;

    /*
     * Wildcard Buffers
     */
    static const uint16_t TA_BRAKE_MIN_VALUE_SIZE = 10;
    touchgfx::Unicode::UnicodeChar ta_brake_min_valueBuffer[TA_BRAKE_MIN_VALUE_SIZE];
    static const uint16_t TA_BRAKE_MAX_VALUE_SIZE = 10;
    touchgfx::Unicode::UnicodeChar ta_brake_max_valueBuffer[TA_BRAKE_MAX_VALUE_SIZE];
    static const uint16_t TA_BRAKE_RELEASE_VALUE_SIZE = 10;
    touchgfx::Unicode::UnicodeChar ta_brake_release_valueBuffer[TA_BRAKE_RELEASE_VALUE_SIZE];
    static const uint16_t TA_THROTTLE_MIN_VALUE_SIZE = 10;
    touchgfx::Unicode::UnicodeChar ta_throttle_min_valueBuffer[TA_THROTTLE_MIN_VALUE_SIZE];
    static const uint16_t TA_THROTTLE_MAX_VALUE_SIZE = 10;
    touchgfx::Unicode::UnicodeChar ta_throttle_max_valueBuffer[TA_THROTTLE_MAX_VALUE_SIZE];
    static const uint16_t TA_THROTTLE_RELEASE_VALUE_SIZE = 10;
    touchgfx::Unicode::UnicodeChar ta_throttle_release_valueBuffer[TA_THROTTLE_RELEASE_VALUE_SIZE];

private:

};

#endif // SCREEN4VIEWBASE_HPP