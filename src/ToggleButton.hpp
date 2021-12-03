/**
 * @file ToggleButton.hpp
 * @brief ToggleButton class for toggleable buttons
 * @details Header file for the ToggleButton class, which displays a
 * toggleable button on the screen and can return whether or not the button
 * is currently toggled.
 * @author Kevin Lou
 * @date November 26, 2021
 *
 * Copyright (c) 2021 Kevin Lou
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#ifndef LOUUI_TOGGLEBUTTON_HPP
#define LOUUI_TOGGLEBUTTON_HPP

#include "../include/display/lvgl.h"
#include "../include/display/lv_core/lv_obj.h"
#include "Color.hpp"
#include "Align.hpp"
#include <vector>

namespace LouUI {
    class ToggleButton {
    public:
        enum State{
            RELEASED,
            PRESSED,
            TOGGLED_RELEASED,
            TOGGLED_PRESSED,
            INACTIVE,
            ALL_RELEASED,
            ALL_PRESSED,
            ALL_UNTOGGLED,
            ALL_TOGGLED,
            ALL
        };

    private:
        lv_obj_t *obj;
        lv_style_t *releasedStyle;
        lv_style_t *pressedStyle;
        lv_style_t *toggledReleasedStyle;
        lv_style_t *toggledPressedStyle;
        lv_style_t *inactiveStyle;

        lv_btn_state_t convertState(State s);

    public:

        /**
         * Creates a new button
         * @param parent The object the button is created in
         */
        explicit ToggleButton(lv_obj_t *parent);

        /**
         * Creates a new button as a copy of another button
         * @param parent The object the button is created in
         * @param b The button from which the copy is made
         */
        ToggleButton(lv_obj_t *parent, ToggleButton b);

        /**
         * Getter for obj
         */
        lv_obj_t *getObj() const;

        /**
         * Getter for releasedStyle
         */
        lv_style_t *getReleasedStyle() const;

        /**
         * Getter for pressedStyle
         */
        lv_style_t *getPressedStyle() const;

        /**
         * Getter for toggledReleasedStyle
         */
        lv_style_t *getToggledReleasedStyle() const;

        /**
         * Getter for toggledPressedStyle
         */
        lv_style_t *getToggledPressedStyle() const;

        /**
         * Getter for inactiveStyle
         */
        lv_style_t *getInactiveStyle() const;

        /**
         * Gets whether or not the button is toggled
         * @return true if toggled, false if otherwise
         */
        __attribute__((unused)) bool isToggled();

        /**
         * Sets the width of the button
         */
        ToggleButton* setWidth(int width);

        /**
         * Sets the height of the button
         */
        ToggleButton* setHeight(int height);

        /**
         * Sets the size of the button
         */
        ToggleButton* setSize(int width, int height);

        /**
         * Sets the x position of the button
         */
        ToggleButton* setX(int x);

        /**
         * Sets the y position of the button
         */
        ToggleButton* setY(int y);

        /**
         * Sets the position of the button
         */
        ToggleButton* setPosition(int x, int y);

        /**
         * Aligns the button to another object
         * @param ref object to align to
         * @param alignType type of alignment
         */
        ToggleButton* align(lv_obj_t *ref, Align alignType);

        /**
         * Aligns the button to another object
         * @param ref object to align to
         * @param alignType type of alignment
         * @param xShift pixels to shift in the x-direction
         * @param yShift pixels to shift in the y-direction
         */
        ToggleButton* align(lv_obj_t *ref, Align alignType, int xShift,
                      int yShift);

        /**
         * Manually set the state of the button
         */
        ToggleButton* setState(State s);

        /**
         * Sets the main color of the button
         * @param s The button state to be modified. Use ALL to set for all
         * states.
         */
        ToggleButton* setMainColor(LouUI::Color c, State s);

        /**
         * Sets the gradient(secondary) color of the button
         * @param s The button state to be modified. Use ALL to set for all
         * states.
         */
        ToggleButton* setGradientColor(LouUI::Color c, State s);

        /**
         * Sets the radius of the button
         * @param s The button state to be modified. Use ALL to set for all
         * states.
         */
        ToggleButton* setRadius(int r, State s);

        /**
         * Sets the opacity of the button
         * @param s The button state to be modified. Use ALL to set for all
         * states.
         */
        ToggleButton* setOpacity(int o, State s);

        /**
         * Sets the border color of the button
         * @param s The button state to be modified. Use ALL to set for all
         * states.
         */
        ToggleButton* setBorderColor(LouUI::Color c, State s);

        /**
         * Sets the border weight of the button
         * @param s The button state to be modified. Use ALL to set for all
         * states.
         */
        ToggleButton* setBorderWidth(int w, State s);

        /**
         * Sets the border opacity of the button
         * @param s The button state to be modified. Use ALL to set for all
         * states.
         */
        ToggleButton* setBorderOpacity(int o, State s);

        /**
         * Sets the shadow color of the button
         * @param s The button state to be modified. Use ALL to set for all
         * states.
         */
        ToggleButton* setShadowColor(LouUI::Color c, State s);

        /**
         * Sets the shadow width of the button
         * @param s The button state to be modified. Use ALL to set for all
         * states.
         */
        ToggleButton* setShadowWidth(int w, State s);

        /**
         * Sets the inner padding of the button
         * @param s The button state to be modified. Use ALL to set for all
         * states.
         */
        ToggleButton* setInnerPadding(int i, State s);

        /**
         * Sets the horizontal padding of the button
         * @param s The button state to be modified. Use ALL to set for all
         * states.
         */
        ToggleButton* setHorizontalPadding(int h, State s);

        /**
         * Sets the vertical padding of the button
         * @param s The button state to be modified. Use ALL to set for all
         * states.
         */
        ToggleButton* setVerticalPadding(int v, State s);

        /**
         * Sets the outside(horizontal and vertical) padding of the button
         * @param s The button state to be modified. Use ALL to set for all
         * states.
         */
        ToggleButton* setOutsidePadding(int h, int v, State s);

        /**
         * Sets all the padding properties (horizontal, vertical, and inner)
         * of the button
         * @param s The button state to be modified. Use ALL to set for all
         * states.
         */
        ToggleButton* setPadding(int h, int v, int i, State s);

    };
}


#endif //LOUUI_TOGGLEBUTTON_HPP
