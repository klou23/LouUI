/**
 * @file Label.cpp
 * @brief Label class used to represent text labels
 * @details Header file for the Label class, which displays a string
 * of text on the screen
 * @author Kevin Lou
 * @date November 18, 2021
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

#ifndef LOUUI_LABEL_HPP
#define LOUUI_LABEL_HPP

#include <string>
#include "Color.hpp"
#include "Align.hpp"
#include "../include/display/lvgl.h"
#include "../include/display/lv_objx/lv_label.h"

namespace LouUI {

    class Label {

    public:
        enum LongMode{
            EXPAND,
            BREAK,
            SCROLL,
            DOT,
            ROLL,
            CROP,
        };

        enum TextAlign{
            LEFT,
            CENTER,
            RIGHT,
        };

    private:
        lv_obj_t *obj;
        Color c;
        lv_style_t *style;

    public:

        /**
         * Creates a new Label
         * @param parent The object the label is created in
         */
        explicit Label(lv_obj_t *parent);

        /**
         * Creates a new label as a copy of another label
         * @param parent The object the label is created in
         * @param l The label from which the copy is made
         */
        Label(lv_obj_t *parent, Label l);

        /**
         * Getter for obj
         */
        lv_obj_t *getObj() const;

        /**
         * Getter for c
         */
        const Color &getC() const;

        /**
         * Getter for style
         */
        lv_style_t *getStyle() const;

        /**
         * Sets the width of the label
         */
        Label* setWidth(int width);

        /**
         * Sets the x position of the label
         */
        Label* setX(int x);

        /**
         * Sets the y position of the label
         */
        Label* setY(int y);

        /**
         * Sets the position of the label
         */
        Label* setPosition(int x, int y);

        /**
         * Aligns the label to another object
         * @param ref object to align to
         * @param alignType type of alignment
         */
        Label* align(lv_obj_t *ref, Align alignType);

        /**
         * Aligns the label to another object
         * @param ref object to align to
         * @param alignType type of alignment
         * @param xShift pixels to shift in the x-direction
         * @param yShift pixels to shift in the y-direction
         */
        Label* align(lv_obj_t *ref, Align alignType, int xShift,
                     int yShift);

        /**
         * Sets the text of the label
         */
        Label* setText(std::string text);

        /**
         * Sets the long mode of the label, which determines behavior when
         * the text in the label is too long
         */
        Label* setLongMode(LongMode m);

        /**
         * Sets the text alignment within the label
         */
        Label* setTextAlign(TextAlign a);

        /**
         * Sets the font of the label
         * @param size font size. This can be: 10, 20, 30, or 40
         * @param mono whether or not the font is mono
         */
        Label* setFont(int size, bool mono = false);

        /**
         * Sets the opacity of the label
         * @param opacity label opacity. This should be between 0 and 225
         */
        Label* setOpacity(int opacity);

    };
}


#endif //LOUUI_LABEL_HPP
