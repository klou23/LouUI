/**
 * @file Component.cpp
 * @brief Component class that is used to represent all components
 * @details Implementation file for the component class, which will be the
 * parent class for all of the UI components. It acts similar to an lvgl object.
 * @author Kevin Lou
 * @date September 8, 2021
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

#include "Component.hpp"

LouUI::Component::Component(std::string name) : name(std::move(name)) {
    x = 0;
    y = 0;
    width = 0;
    height = 0;
    obj = nullptr;
    parent = nullptr;
}

LouUI::Component::Component(std::string name, lv_obj_t *parent) :
        name(std::move(name)), parent(parent) {
    x = 0;
    y = 0;
    width = 0;
    height = 0;
    obj = nullptr;
}

LouUI::Component::Component(std::string name, lv_obj_t *parent, int x, int y) :
        name(std::move(name)), parent(parent), x(x), y(y) {
    width = 0;
    height = 0;
    obj = nullptr;
}

LouUI::Component::Component(std::string name, lv_obj_t *parent, int x,
                            int y, int width, int height) :
        name(std::move(name)), parent(parent), x(x), y(x),
        width(width), height(height) {
    obj = nullptr;
}

__attribute__((unused)) int LouUI::Component::getX() const {
    return x;
}

__attribute__((unused)) void LouUI::Component::setX(int x) {
    Component::x = x;
}

__attribute__((unused)) int LouUI::Component::getY() const {
    return y;
}

__attribute__((unused)) void LouUI::Component::setY(int y) {
    Component::y = y;
}

__attribute__((unused)) int LouUI::Component::getWidth() const {
    return width;
}

__attribute__((unused)) void LouUI::Component::setWidth(int width) {
    Component::width = width;
}

__attribute__((unused)) int LouUI::Component::getHeight() const {
    return height;
}

__attribute__((unused)) void LouUI::Component::setHeight(int height) {
    Component::height = height;
}

const std::string &LouUI::Component::getName() const {
    return name;
}

__attribute__((unused)) void LouUI::Component::setName(const std::string &name) {
    Component::name = name;
}

__attribute__((unused)) lv_obj_t *LouUI::Component::getObj() const {
    return obj;
}

__attribute__((unused)) void LouUI::Component::setObj(lv_obj_t *obj) {
    Component::obj = obj;
}

__attribute__((unused)) lv_obj_t *LouUI::Component::getParent() const {
    return parent;
}

void LouUI::Component::setParent(lv_obj_t *parent) {
    Component::parent = parent;
}

