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
#include "Fonts.hpp"


LouUI::Display::Display() {
    //sets the UI theme
    lv_theme_t *theme = lv_theme_alien_init(200, NULL);
    lv_theme_set_current(theme);

    initFonts();

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
    if(screens.count(name)) return;
    auto *newScreen = lv_tabview_add_tab(tabView, name.c_str());
    screens[name] = newScreen;
}

void LouUI::Display::addScreens(const std::vector<std::string> &names) {
    for (const auto &name: names) {
        addScreen(name);
    }
}

int LouUI::Display::getScreenCount() {
    return screens.size();
}

lv_obj_t *LouUI::Display::getScreen(const std::string &name) {
    if(screens.count(name)) return screens[name];
    return nullptr;
}

void LouUI::Display::initFonts() {
    //add symbols
//    lv_font_add(&symbols_20, &dejavu_20);
//    lv_font_add(&dejavu_20, &symbols_20);

    //sets the default fonts
    lv_style_scr.text.font = &dejavu_20;
    lv_style_transp.text.font = &dejavu_20;
    lv_style_transp_tight.text.font = &dejavu_20;
    lv_style_transp_fit.text.font = &dejavu_20;
    lv_style_plain.text.font = &dejavu_20;
    lv_style_plain_color.text.font = &dejavu_20;
    lv_style_pretty.text.font = &dejavu_20;
    lv_style_pretty_color.text.font = &dejavu_20;
    lv_style_btn_rel.text.font = &dejavu_20;
    lv_style_btn_pr.text.font = &dejavu_20;
    lv_style_btn_tgl_rel.text.font = &dejavu_20;
    lv_style_btn_tgl_pr.text.font = &dejavu_20;
    lv_style_btn_ina.text.font = &dejavu_20;
}

