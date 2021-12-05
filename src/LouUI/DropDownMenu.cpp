/**
 * @file DropDownMenu.cpp
 * @brief DropDownMenu class for drop-down selection menus
 * @details Implementation file for the DropDownMenu class, which displays a
 * single-selection drop-down menu on the screen and can return which value
 * is currently selected
 * @author Kevin Lou
 * @date December 3, 2021
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

#include "DropDownMenu.hpp"
#include "../../include/display/lv_objx/lv_ddlist.h"
#include "../../include/display/lvgl.h"

LouUI::DropDownMenu::DropDownMenu(lv_obj_t *parent) {
    obj = lv_ddlist_create(parent, nullptr);

    backgroundStyle = (lv_style_t *)(malloc(sizeof(lv_style_t)));
    lv_style_copy(backgroundStyle, &lv_style_pretty);
    backgroundStyle->text.font = &lv_font_dejavu_20;
    selectedStyle = (lv_style_t *)(malloc(sizeof(lv_style_t)));
    lv_style_copy(selectedStyle, &lv_style_plain_color);
    scrollbarStyle = (lv_style_t *)(malloc(sizeof(lv_style_t)));
    lv_style_copy(scrollbarStyle, &lv_style_plain_color);

    lv_ddlist_set_style(obj, LV_DDLIST_STYLE_BG, backgroundStyle);
    lv_ddlist_set_style(obj, LV_DDLIST_STYLE_SEL, selectedStyle);
    lv_ddlist_set_style(obj, LV_DDLIST_STYLE_SB, scrollbarStyle);

    lv_ddlist_set_draw_arrow(obj, true);
}

LouUI::DropDownMenu::DropDownMenu(lv_obj_t *parent, DropDownMenu d) {
    obj = lv_ddlist_create(parent, d.getObj());

    backgroundStyle = lv_ddlist_get_style(obj, LV_DDLIST_STYLE_BG);
    selectedStyle = lv_ddlist_get_style(obj, LV_DDLIST_STYLE_SEL);
    scrollbarStyle = lv_ddlist_get_style(obj, LV_DDLIST_STYLE_SB);

//    arrow = lv_label_create(parent, nullptr);
//    lv_label_set_text(arrow, SYMBOL_DOWN);

}

lv_obj_t *LouUI::DropDownMenu::getObj() const {
    return obj;
}

lv_style_t *LouUI::DropDownMenu::getBackgroundStyle() const {
    return backgroundStyle;
}

lv_style_t *LouUI::DropDownMenu::getSelectedStyle() const {
    return selectedStyle;
}

lv_style_t *LouUI::DropDownMenu::getScrollbarStyle() const {
    return scrollbarStyle;
}

const std::vector<std::string> &LouUI::DropDownMenu::getOptions() const {
    return options;
}

LouUI::DropDownMenu *LouUI::DropDownMenu::setX(int x) {
    lv_obj_set_x(obj, x);
    return this;
}

LouUI::DropDownMenu *LouUI::DropDownMenu::setY(int y) {
    lv_obj_set_y(obj, y);
    return this;
}

LouUI::DropDownMenu *LouUI::DropDownMenu::setPosition(int x, int y) {
    lv_obj_set_pos(obj, x, y);
    return this;
}

LouUI::DropDownMenu *LouUI::DropDownMenu::align(lv_obj_t *ref,
                                                Align alignType) {
    lv_obj_align(obj, ref, alignType, 0, 0);
    return this;
}

LouUI::DropDownMenu *
LouUI::DropDownMenu::align(lv_obj_t *ref, Align alignType,
                           int xShift, int yShift) {
    lv_obj_align(obj, ref, alignType, xShift, yShift);
    return this;
}

LouUI::DropDownMenu *
LouUI::DropDownMenu::setOptions(std::vector<std::string> options) {
    this->options = options;
    std::string str = "";
    for(int i = 0; i < options.size()-1; i++){
        str += options[i];
        str += "    \n";
    }
    str += options[options.size()-1] + "    ";
    lv_ddlist_set_options(obj, str.c_str());
    return this;
}

LouUI::DropDownMenu *
LouUI::DropDownMenu::setState(DropDownMenu::State s, bool animate) {
    if(s == OPEN){
        lv_ddlist_open(obj, animate);
    }else if(s == CLOSE){
        lv_ddlist_close(obj, animate);
    }
    return this;
}

std::string LouUI::DropDownMenu::getSelected() {
    return options[lv_ddlist_get_selected(obj)];
}

LouUI::DropDownMenu *
LouUI::DropDownMenu::setAction(LouUI::DropDownMenu::Action a) {
    lv_ddlist_set_action(obj, a);
    return this;
}

