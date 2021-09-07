/**
 * @file Screen.hpp
 * @brief Screen class that works like a tab in the display
 * @details Header file for the screen class, that will contain all of the UI
 * contents. It acts like a lvgl page.
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

#ifndef LOUUI_SCREEN_HPP
#define LOUUI_SCREEN_HPP

#include <string>
#include <vector>
#include "main.h"
#include "Component.hpp"
#include "../include/display/lv_core/lv_obj.h"


namespace LouUI {
    class Screen {
    private:
        lv_obj_t *page;
        std::string name;
        std::vector<Component> components;
    public:
        Screen(lv_obj_t *page);

        lv_obj_t *getPage() const;

        void setPage(lv_obj_t *page);

        const std::string &getName() const;

        void setName(const std::string &name);
    };
}


#endif //LOUUI_SCREEN_HPP