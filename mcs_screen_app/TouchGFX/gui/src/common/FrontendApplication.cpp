#include <gui/common/FrontendApplication.hpp>

#include <gui/common/FrontendHeap.hpp>
#include <gui/screen2_screen/Screen2View.hpp>
#include <gui/screen2_screen/Screen2Presenter.hpp>
#include <gui/screen3_screen/Screen3View.hpp>
#include <gui/screen3_screen/Screen3Presenter.hpp>
#include <gui/screen4_screen/Screen4View.hpp>
#include <gui/screen4_screen/Screen4Presenter.hpp>
#include <touchgfx/transitions/NoTransition.hpp>

FrontendApplication::FrontendApplication(Model& m, FrontendHeap& heap)
    : FrontendApplicationBase(m, heap)
{

}

void FrontendApplication::goto_screen2_impl(){
	touchgfx::makeTransition<Screen2View, Screen2Presenter, touchgfx::NoTransition, Model>(&currentScreen, &currentPresenter, frontendHeap, &currentTransition, &model);
}

void FrontendApplication::goto_screen2(){
	customTransitionCallback = touchgfx::Callback<FrontendApplication>(this, &FrontendApplication::goto_screen2_impl);


	pendingScreenTransitionCallback = &customTransitionCallback;
}




void FrontendApplication::goto_screen3_impl(){
	touchgfx::makeTransition<Screen3View, Screen3Presenter, touchgfx::NoTransition, Model>(&currentScreen, &currentPresenter, frontendHeap, &currentTransition, &model);
}

void FrontendApplication::goto_screen3(){
	customTransitionCallback3 = touchgfx::Callback<FrontendApplication>(this, &FrontendApplication::goto_screen3_impl);

	pendingScreenTransitionCallback = &customTransitionCallback3;
}



void FrontendApplication::goto_screen4_impl(){
	touchgfx::makeTransition<Screen4View, Screen4Presenter, touchgfx::NoTransition, Model>(&currentScreen, &currentPresenter, frontendHeap, &currentTransition, &model);
}

void FrontendApplication::goto_screen4(){
	customTransitionCallback4 = touchgfx::Callback<FrontendApplication>(this, &FrontendApplication::goto_screen4_impl);

	pendingScreenTransitionCallback = &customTransitionCallback4;
}
