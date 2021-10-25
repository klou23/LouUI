/**
 * @file Display.hpp
 * @brief Display class
 * @details Header file for the display class, that will contain all the
 * screens. It acts like a lvgl tabview.
 * @author Kevin Lou
 * @date September 3, 2021
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

#ifndef LOUUI_DISPLAY_HPP
#define LOUUI_DISPLAY_HPP

#include <vector>

#include "../include/display/lv_core/lv_obj.h"
#include "Screen.hpp"


namespace LouUI {
    class Display {
    private:
        lv_obj_t *tabView;
        std::vector<Screen *> screens;
    public:
        /**
         * Creates a new display.
         * @warning Only one display should ever be created
         */
        Display();

        /**
         * Getter for tabview
         */
        lv_obj_t *getTabView() const;

        /**
         * Setter for tabview
         */
        void setTabView(lv_obj_t *tabView);

        /**
         * Creates a new empty screen and adds it to the display
         *
         * @param name name of the screen to be created. This name should be
         * unique
         */
        void addScreen(std::string name);

        /**
         * Creates new empty screens and adds them to the display
         *
         * @param names vector of the names of the screens to be created.
         * These names should all be unique
         */
        void addScreens(const std::vector<std::string> &names);

        /**
         * Gets the number of screens
         *
         * @return the number of screens
         */
        int getScreenCount();

        /**
         * Gets the pointer to the screen
         *
         * @param name Name of the screen to return
         * @return a pointer to the screen. Returns null if the screen does
         * not exist
         */
        Screen *getScreen(const std::string &name);
    };
}


#endif //LOUUI_DISPLAY_HPP
