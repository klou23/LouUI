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

    /**
     * @class Color
     * @brief Represents an 24-bit color
     */

    class Color {
    private:
        /**
         * Red-value in the color
         */
        int r;
        /**
         * Green-value in the color
         */
        int g;
        /**
         * Blue-value in the color
         */
        int b;

    public:

        /**
         * Create a new color from a hex-value or a given color name
         * @param color Either the hex string for the color or one of the
         * following color names:
         * - BLACK
         * - RED
         * - GREEN
         * - BLUE
         * - FUCHSIA
         * - WHITE
         * - YELLOW
         * - PURPLE
         * - MAROON
         * - OLIVE
         */
        Color(std::string color);

        /**
         * Create a new color with the given R, G, and B values
         */
        Color(int r, int g, int b);

        /**
         * Getter for red
         */
        int getR() const;
        /**
         * Setter for red
         */
        void setR(int r);
        /**
         * Getter for green
         */
        int getG() const;
        /**
         * Setter for green
         */
        void setG(int g);
        /**
         * Getter for blue
         */
        int getB() const;
        /**
         * Setter for blue
         * @param b
         */
        void setB(int b);

        /**
         * Returns the hexString for the color
         */
        std::string hexString() const;

        /**
         * Returns the lvgl equivalent of the color
         */
        lv_color_t toLvColor();
    };
}


#endif //LOUUI_COLOR_HPP