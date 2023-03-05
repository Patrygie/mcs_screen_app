/******************************************************************************
* Copyright (c) 2018(-2022) STMicroelectronics.
* All rights reserved.
*
* This file is part of the TouchGFX 4.21.0 distribution.
*
* This software is licensed under terms that can be found in the LICENSE file in
* the root directory of this software component.
* If no LICENSE file comes with this software, it is provided AS-IS.
*
*******************************************************************************/

/**
 * @file touchgfx/UIEventListener.hpp
 *
 * Declares the touchgfx::ClickEvent, touchgfx::DragEvent, touchgfx::GestureEvent and
 * touchgfx::UIEventListener classes.
 */
#ifndef TOUCHGFX_UIEVENTLISTENER_HPP
#define TOUCHGFX_UIEVENTLISTENER_HPP

#include <touchgfx/events/ClickEvent.hpp>
#include <touchgfx/events/DragEvent.hpp>
#include <touchgfx/events/GestureEvent.hpp>
#include <touchgfx/hal/Types.hpp>

namespace touchgfx
{
/**
 * This class declares a handler interface for user interface events, i.e. events generated by
 * the users interaction with the device. With the exception of the system timer tick,
 * all other system events, which are not related to the user interface device
 * peripherals (display, keys etc.) are not part of this interface.
 */
class UIEventListener
{
public:
    /**
     * This handler is invoked when a mouse click or display touch event has been detected
     * by the system.
     *
     * @param  event The event data.
     */
    virtual void handleClickEvent(const ClickEvent& event)
    {
        (void)event; // Unused variable
    }

    /**
     * This handler is invoked when a drag event has been detected by the system.
     *
     * @param  event The event data.
     */
    virtual void handleDragEvent(const DragEvent& event)
    {
        (void)event; // Unused variable
    }

    /**
     * This handler is invoked when a gesture event has been detected by the system.
     *
     * @param  event The event data.
     */
    virtual void handleGestureEvent(const GestureEvent& event)
    {
        (void)event; // Unused variable
    }

    /**
     * This handler is invoked when a key (or button) event has been detected by the system.
     *
     * @param  c The key or button pressed.
     */
    virtual void handleKeyEvent(uint8_t c)
    {
        (void)c; // Unused variable
    }

    /**
     * This handler is invoked when a system tick event has been generated. The system tick
     * period is configured in the HAL.
     */
    virtual void handleTickEvent()
    {
    }

    /** This handler is invoked when a change screen event is pending. */
    virtual void handlePendingScreenTransition()
    {
    }

    /** Finalizes an instance of the UIEventListener class. */
    virtual ~UIEventListener()
    {
    }
};

} // namespace touchgfx

#endif // TOUCHGFX_UIEVENTLISTENER_HPP
