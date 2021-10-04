/**
 * @file Screen.cpp
 * @brief Screen class that works like a tab in the display
 * @details Implementation file for the screen class, that will contain all of
 * the UI contents. It acts like a lvgl page.
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

#include "Screen.hpp"


LouUI::Screen::Screen(lv_obj_t *page) : page(page) {}

lv_obj_t *LouUI::Screen::getPage() const {
    return page;
}

void LouUI::Screen::setPage(lv_obj_t *page) {
    Screen::page = page;
}

const std::string &LouUI::Screen::getName() const {
    return name;
}

void LouUI::Screen::setName(const std::string &name) {
    Screen::name = name;
}

int LouUI::Screen::getComponentCount() {
    return components.size();
}

LouUI::Component *LouUI::Screen::getComponent(std::string name) {
    for(auto component : components){
        if(component->getName() == name) return component;
    }
    return nullptr;
}

void LouUI::Screen::addComponent(std::string name) {
    Component* component = new Component(name);
    component->setParent(page);
    components.push_back(component);
}
