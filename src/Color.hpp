/**
 * @file Color.hpp
 * @brief Color class used to represent colors
 * @details Header file for the Color class, which is used to
 * represent an RGB color
 * @author Kevin Lou
 * @date October 25, 2021
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

#ifndef LOUUI_COLOR_HPP
#define LOUUI_COLOR_HPP

#include <string>
#include "../include/display/lvgl.h"

namespace LouUI {
    class Color {
    private:

        int r;
        int g;
        int b;

    public:

        Color(std::string color);

        Color(int r, int g, int b);

        int getR() const;

        void setR(int r);

        int getG() const;

        void setG(int g);

        int getB() const;

        void setB(int b);

        std::string hexString() const;

        lv_color_t toLvColor();
    };
}


#endif //LOUUI_COLOR_HPP