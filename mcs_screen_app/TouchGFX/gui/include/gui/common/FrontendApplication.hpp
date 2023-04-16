#ifndef FRONTENDAPPLICATION_HPP
#define FRONTENDAPPLICATION_HPP

#include <gui_generated/common/FrontendApplicationBase.hpp>

class FrontendHeap;

using namespace touchgfx;

class FrontendApplication : public FrontendApplicationBase
{
public:
    FrontendApplication(Model& m, FrontendHeap& heap);
    virtual ~FrontendApplication() { }

    virtual void handleTickEvent()
    {
        model.tick();
        FrontendApplicationBase::handleTickEvent();
    }

    void goto_screen2();
    void goto_screen3();

private:
    touchgfx::Callback<FrontendApplication> customTransitionCallback;
    touchgfx::Callback<FrontendApplication> customTransitionCallback3;

    void goto_screen2_impl();
    void goto_screen3_impl();
};

#endif // FRONTENDAPPLICATION_HPP
