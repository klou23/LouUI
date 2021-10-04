/**
 * @file Label.cpp
 * @brief Label class that is used to represent text labels
 * @details Implementation file for the Label class, which is a type of
 * Component that displays a text string. It is a type of lvgl object
 * @author Kevin Lou
 * @date September 23, 2021
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

#include "Label.hpp"

#include <utility>


LouUI::Label::Label(std::string name) : Component(std::move(name)) {

}

LouUI::Label::Label(std::string name, lv_obj_t *parent) :
        Component(std::move(name), parent) {

}

LouUI::Label::Label(std::string name, lv_obj_t *parent, int x, int y) :
        Component(std::move(name), parent, x, y) {

}

LouUI::Label::Label(std::string name, lv_obj_t *parent, int x, int y, int width,
                    int height) :
        Component(std::move(name), parent, x, y, width, height) {

}

LouUI::Label::Label(std::string name, std::string text) : Component(std::move(name)),
                    text(std::move(text)){

}

LouUI::Label::Label(std::string name, lv_obj_t *parent, std::string text) :
        Component(std::move(name), parent), text(std::move(text)){

}

LouUI::Label::Label(std::string name, lv_obj_t *parent, int x, int y,
                    std::string text) : Component(std::move(name), parent, x, y),
                    text(std::move(text)){

}

LouUI::Label::Label(std::string name, lv_obj_t *parent, int x, int y, int width,
                    int height, std::string text) :
        Component(std::move(name), parent, x, y, width, height), text(std::move(text)){

}
