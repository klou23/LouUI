/**
 * @file Color.cpp
 * @brief Color class used to represent colors
 * @details Implementation file for the Color class, which is used to
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

#include "Color.hpp"

LouUI::Color::Color(std::string color){
    if(color == "BLACK") {
        r = 0;
        g = 0;
        b = 0;
    }else if(color == "RED") {
        r = 255;
        g = 0;
        b = 0;
    }else if(color == "GREEN") {
        r = 0;
        g = 255;
        b = 0;
    }else if(color == "BLUE") {
        r = 0;
        g = 0;
        b = 255;
    }else if(color == "FUCHSIA") {
        r = 255;
        g = 0;
        b = 255;
    }else if(color == "WHITE") {
        r = 255;
        g = 255;
        b = 255;
    }else if(color == "YELLOW") {
        r = 255;
        g = 255;
        b = 0;
    }else if(color == "PURPLE") {
        r = 128;
        g = 0;
        b = 128;
    }else if(color == "MAROON") {
        r = 128;
        g = 0;
        b = 0;
    }else if(color == "OLIVE") {
        r = 128;
        g = 128;
        b = 0;
    }else {
        r = (color[1] <= '9') ? (color[1] - '0') : ((color[1] - 'A') + 10);
        g = (color[3] <= '9') ? (color[3] - '0') : ((color[3] - 'A') + 10);
        b = (color[5] <= '9') ? (color[5] - '0') : ((color[5] - 'A') + 10);
        r += ((color[0] <= '9') ? (color[0] - '0') : ((color[0] - 'A') + 10)) *
             16;
        g += ((color[2] <= '9') ? (color[2] - '0') : ((color[2] - 'A') + 10)) *
             16;
        b += ((color[4] <= '9') ? (color[4] - '0') : ((color[4] - 'A') + 10)) *
             16;
    }
}

LouUI::Color::Color(int r, int g, int b) : r(r), g(g), b(b) {}

int LouUI::Color::getR() const {
    return r;
}

void LouUI::Color::setR(int r) {
    Color::r = r;
}

int LouUI::Color::getG() const {
    return g;
}

void LouUI::Color::setG(int g) {
    Color::g = g;
}

int LouUI::Color::getB() const {
    return b;
}

void LouUI::Color::setB(int b) {
    Color::b = b;
}

std::string LouUI::Color::hexString() const {
    std::string returnVal = "#";

    if(r/16 > 9) returnVal += (char) ('A' + (r/16)-10);
    else returnVal += (char) ('0' + r/16);

    if(r%16 > 9) returnVal += (char) ('A' + (r%16)-10);
    else returnVal += (char) ('0' + r%16);

    if(g/16 > 9) returnVal += (char) ('A' + (g/16)-10);
    else returnVal += (char) ('0' + g/16);

    if(g%16 > 9) returnVal += (char) ('A' + (g%16)-10);
    else returnVal += (char) ('0' + g%16);

    if(b/16 > 9) returnVal += (char) ('A' + (b/16)-10);
    else returnVal += (char) ('0' + b/16);

    if(b%16 > 9) returnVal += (char) ('A' + (b%16)-10);
    else returnVal += (char) ('0' + b%16);

    return returnVal;
}

lv_color_t LouUI::Color::toLvColor() {
    return LV_COLOR_MAKE((uint8_t)r, (uint8_t)g, (uint8_t)b);
}


