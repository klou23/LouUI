/**
 * @file Display.cpp
 * @brief Display class
 * @details Implementation file for the display class, that will contain all
 * the screens. It acts like a lvgl tabview.
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

#include "Display.hpp"


LouUI::Display::Display() {
    //sets the UI theme
    lv_theme_t *theme = lv_theme_alien_init(200, NULL);
    lv_theme_set_current(theme);

    //initialize the tabview
    tabView = lv_tabview_create(lv_scr_act(), NULL);
}

lv_obj_t *LouUI::Display::getTabView() const {
    return tabView;
}

void LouUI::Display::setTabView(lv_obj_t *tabView) {
    Display::tabView = tabView;
}

void LouUI::Display::addScreen(std::string name) {
    auto *newScreen = new Screen(lv_tabview_add_tab(tabView, name.c_str()));
    newScreen->setName(name);
    screens.push_back(newScreen);
}

void LouUI::Display::addScreens(const std::vector<std::string> &names) {
    for (const auto &name: names) {
        addScreen(name);
    }
}

int LouUI::Display::getScreenCount() {
    return screens.size();
}

LouUI::Screen *LouUI::Display::getScreen(const std::string &name) {
    for (auto screen: screens) {
        if (screen->getName() == name) return screen;
    }
    return nullptr;
}

