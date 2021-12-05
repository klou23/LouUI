/**
 * @file DropDownMenu.hpp
 * @brief DropDownMenu class for drop-down selection menus
 * @details Header file for the DropDownMenu class, which displays a
 * single-selection drop-down menu on the screen and can return which value
 * is currently selected
 * @author Kevin Lou
 * @date December 3, 2021
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

#ifndef LOUUI_DROPDOWNMENU_HPP
#define LOUUI_DROPDOWNMENU_HPP

#include "../../include/api.h"
#include "../../include/display/lv_core/lv_obj.h"
#include <vector>
#include "Align.hpp"
#include "Label.hpp"

namespace LouUI {
    class DropDownMenu {

    public:

        using Action = lv_action_t;

        enum State{
            OPEN,
            CLOSE
        };

        enum StyleType{
            BACKGROUND,
            SELECTED,
            SCROLLBAR
        };

    private:
        lv_obj_t *obj;
        lv_style_t *backgroundStyle;
        lv_style_t *selectedStyle;
        lv_style_t *scrollbarStyle;

        std::vector<std::string> options;

        void alignArrow();

    public:

        /**
         * Creates a new drop down menu
         * @param parent The object the drop down menu is created in
         */
        explicit DropDownMenu(lv_obj_t *parent);

        /**
         * Creates a new drop down menu as a copy of another drop down menu
         * @param parent The object the button is created in
         * @param d The drop down menu from which the copy is made
         */
        DropDownMenu(lv_obj_t *parent, DropDownMenu d);

        /**
         * Getter for obj
         */
        lv_obj_t *getObj() const;

        /**
         * Getter for backgroundStyle
         */
        lv_style_t *getBackgroundStyle() const;

        /**
         * Getter for pressedStyle
         */
        lv_style_t *getSelectedStyle() const;

        /**
         * Getter for scrollBarStyle
         */
        lv_style_t *getScrollbarStyle() const;

        /**
         * Getter for options
         */
        const std::vector<std::string> &getOptions() const;

        /**
         * Sets the x position
         */
        DropDownMenu* setX(int x);

        /**
         * Sets the y position
         */
        DropDownMenu* setY(int y);

        /**
         * Sets the position
         */
        DropDownMenu* setPosition(int x, int y);

        /**
         * Aligns the drop down menu to another object
         * @param ref object to align to
         * @param alignType type of alignment
         */
        DropDownMenu* align(lv_obj_t *ref, Align alignType);

        /**
         * Aligns the drop down menu to another object
         * @param ref object to align to
         * @param alignType type of alignment
         * @param xShift pixels to shift in the x-direction
         * @param yShift pixels to shift in the y-direction
         */
        DropDownMenu* align(lv_obj_t *ref, Align alignType, int xShift,
                            int yShift);

        DropDownMenu* setOptions(std::vector<std::string> options);

        /**
         * Manually sets the state of the drop down menu
         * @param animate true if state change should be animated, false
         * otherwise
         */
        DropDownMenu* setState(State s, bool animate);

        std::string getSelected();

        /**
         * Sets an action to execute when a new option is chosen
         * @param a The function to be executed. The function must meet the
         * following requirements:
         * - Return type: lv_res_t
         * - Single parameter: lv_obj_t *
         * - Returns LV_RES_OK
         */
         DropDownMenu* setAction(Action a);
    };
}


#endif //LOUUI_DROPDOWNMENU_HPP
