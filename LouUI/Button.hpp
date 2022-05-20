/**
 * @file Button.hpp
 * @brief Button class for non-toggleable buttons
 * @details Header file for the Button class, which displays a
 * non-toggleable button on the screen and will execute an action when pressed
 * @author Kevin Lou
 * @date November 25, 2021
 *
 * @copyright Copyright (c) 2021 Kevin Lou
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

#ifndef LOUUI_BUTTON_HPP
#define LOUUI_BUTTON_HPP

#include "../../include/display/lvgl.h"
#include "Color.hpp"
#include "Align.hpp"

namespace LouUI {
    /**
     * @class Button
     * @brief Class for adding buttons to the screen
     * @details
     * A button is the LouUI object to add non-toggleable buttons to the screen
     * @subsection usage Usage
     * 
     */
    class Button {
    public:

        using Action = lv_action_t;

        enum State{
            RELEASED,
            PRESSED,
            INACTIVE,
            ALL
        };

    private:
        lv_obj_t *obj;
        lv_style_t *releasedStyle;
        lv_style_t *pressedStyle;
        lv_style_t *inactiveStyle;

        lv_btn_state_t convertState(State s);

    public:

        /**
         * Creates a new button
         * @param parent The object the button is created in
         */
        explicit Button(lv_obj_t *parent);

        /**
         * Creates a new button as a copy of another button
         * @param parent The object the button is created in
         * @param b The button from which the copy is made
         */
        Button(lv_obj_t *parent, Button b);

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
         * Getter for inactiveStyle
         */
        lv_style_t *getInactiveStyle() const;

        /**
         * Sets the width of the button
         */
        Button* setWidth(int width);

        /**
         * Sets the height of the button
         */
        Button* setHeight(int height);

        /**
         * Sets the size of the button
         */
        Button* setSize(int width, int height);

        /**
         * Sets the x position of the button
         */
        Button* setX(int x);

        /**
         * Sets the y position of the button
         */
        Button* setY(int y);

        /**
         * Sets the position of the button
         */
        Button* setPosition(int x, int y);

        /**
         * Aligns the button to another object
         * @param ref object to align to
         * @param alignType type of alignment
         */
        Button* align(lv_obj_t *ref, Align alignType);

        /**
         * Aligns the button to another object
         * @param ref object to align to
         * @param alignType type of alignment
         * @param xShift pixels to shift in the x-direction
         * @param yShift pixels to shift in the y-direction
         */
        Button* align(lv_obj_t *ref, Align alignType, int xShift, int yShift);

        /**
         * Manually set the state of the button
         */
        Button* setState(State s);

        /**
         * Sets an action to execute when the button is clicked
         * @param a The function to be executed. The function must meet the
         * following requirements:
         * - Return type: lv_res_t
         * - Single parameter: lv_obj_t *
         * - Returns LV_RES_OK
         */
        Button* setAction(Action a);

        /**
         * Sets the main color of the button
         * @param s The button state to be modified. Use ALL to set for all
         * states.
         */
        Button* setMainColor(LouUI::Color c, State s);

        /**
         * Sets the gradient(secondary) color of the button
         * @param s The button state to be modified. Use ALL to set for all
         * states.
         */
        Button* setGradientColor(LouUI::Color c, State s);

        /**
         * Sets the radius of the button
         * @param s The button state to be modified. Use ALL to set for all
         * states.
         */
        Button* setRadius(int r, State s);

        /**
         * Sets the opacity of the button
         * @param s The button state to be modified. Use ALL to set for all
         * states.
         */
        Button* setOpacity(int o, State s);

        /**
         * Sets the border color of the button
         * @param s The button state to be modified. Use ALL to set for all
         * states.
         */
        Button* setBorderColor(LouUI::Color c, State s);

        /**
         * Sets the border weight of the button
         * @param s The button state to be modified. Use ALL to set for all
         * states.
         */
        Button* setBorderWidth(int w, State s);

        /**
         * Sets the border opacity of the button
         * @param s The button state to be modified. Use ALL to set for all
         * states.
         */
        Button* setBorderOpacity(int o, State s);

        /**
         * Sets the shadow color of the button
         * @param s The button state to be modified. Use ALL to set for all
         * states.
         */
        Button* setShadowColor(LouUI::Color c, State s);

        /**
         * Sets the shadow width of the button
         * @param s The button state to be modified. Use ALL to set for all
         * states.
         */
        Button* setShadowWidth(int w, State s);

        /**
         * Sets the inner padding of the button
         * @param s The button state to be modified. Use ALL to set for all
         * states.
         */
        Button* setInnerPadding(int i, State s);

        /**
         * Sets the horizontal padding of the button
         * @param s The button state to be modified. Use ALL to set for all
         * states.
         */
        Button* setHorizontalPadding(int h, State s);

        /**
         * Sets the vertical padding of the button
         * @param s The button state to be modified. Use ALL to set for all
         * states.
         */
        Button* setVerticalPadding(int v, State s);

        /**
         * Sets the outside(horizontal and vertical) padding of the button
         * @param s The button state to be modified. Use ALL to set for all
         * states.
         */
        Button* setOutsidePadding(int h, int v, State s);

        /**
         * Sets all the padding properties (horizontal, vertical, and inner)
         * of the button
         * @param s The button state to be modified. Use ALL to set for all
         * states.
         */
        Button* setPadding(int h, int v, int i, State s);

    };
}


#endif //LOUUI_BUTTON_HPP
