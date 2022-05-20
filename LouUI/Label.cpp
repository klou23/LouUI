/**
 * @file Label.cpp
 * @brief Label class used to represent text labels
 * @details Implementation file for the Label class, which displays a string
 * of text on the screen
 * @author Kevin Lou
 * @date November 18, 2021
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
#include <string>
#include "Color.hpp"
#include "../../include/display/lvgl.h"
#include "../../include/display/lv_objx/lv_label.h"

LouUI::Label::Label(lv_obj_t *parent) : c("WHITE"){
    obj = lv_label_create(parent, nullptr);
    lv_label_set_recolor(obj, true);

    style = (lv_style_t *)(malloc(sizeof(lv_style_t)));
    lv_style_copy(style, &lv_style_pretty_color);

    lv_label_set_style(obj, style);

}

LouUI::Label::Label(lv_obj_t *parent, LouUI::Label l) : c("WHITE"){
    obj = lv_label_create(parent, l.getObj());
    style = lv_label_get_style(obj);
}

lv_obj_t *LouUI::Label::getObj() const {
    return obj;
}

const LouUI::Color &LouUI::Label::getC() const {
    return c;
}

lv_style_t *LouUI::Label::getStyle() const {
    return style;
}

LouUI::Label *LouUI::Label::setColor(LouUI::Color c) {
    this->c = c;
    std::string text = c.hexString() + " " + text;
    lv_label_set_text(obj, text.c_str());
    return this;
}

LouUI::Label *LouUI::Label::setWidth(int width) {
    lv_obj_set_width(obj, width);
    return this;
}

LouUI::Label *LouUI::Label::setX(int x) {
    lv_obj_set_x(obj, x);
    return this;
}

LouUI::Label *LouUI::Label::setY(int y) {
    lv_obj_set_y(obj, y);
    return this;
}

LouUI::Label *LouUI::Label::setPosition(int x, int y) {
    lv_obj_set_pos(obj, x, y);
    return this;
}

LouUI::Label *LouUI::Label::align(lv_obj_t *ref, Align alignType) {
    lv_obj_align(obj, ref, alignType, 0, 0);
    return this;
}

LouUI::Label *
LouUI::Label::align(lv_obj_t *ref, Align alignType, int xShift, int
yShift) {
    lv_obj_align(obj, ref, alignType, xShift, yShift);
    return this;
}

LouUI::Label *LouUI::Label::setText(std::string text) {
    this->text = text;
    text = c.hexString() + " " + text;
    lv_label_set_text(obj, text.c_str());
    return this;
}

LouUI::Label *LouUI::Label::setLongMode(LongMode m) {
    lv_label_set_long_mode(obj, m);
    return this;
}

LouUI::Label *LouUI::Label::setTextAlign(TextAlign a) {
    lv_label_set_align(obj, a);
    return this;
}

LouUI::Label *LouUI::Label::setFont(int size, bool mono) {
    lv_font_t *f;
//    if(mono){
//        if(size == 10) f = &pros_font_dejavu_mono_10;
//        else if(size == 20) f = &pros_font_dejavu_mono_20;
//        else if(size == 30) f = &pros_font_dejavu_mono_30;
//        else if(size == 40) f = &pros_font_dejavu_mono_40;
//    }else{
//        if(size == 10) f = &lv_font_dejavu_10;
//        else if(size == 20) f = &lv_font_dejavu_20;
//        else if(size == 30) f = &lv_font_dejavu_30;
//        else if(size == 40) f = &lv_font_dejavu_40;
//    }

//    if(size == 10) f = &lv_font_dejavu_10;
//    else if(size == 20) f = &lv_font_dejavu_20;
//    else if(size == 30) f = &lv_font_dejavu_30;
//    else if(size == 40) f = &lv_font_dejavu_40;

    f = &dejavu_20;

    style->text.font = f;
    lv_obj_refresh_style(obj);
    return this;
}

LouUI::Label *LouUI::Label::setOpacity(int opacity) {
    if(0 <= opacity && opacity <= 255) style->text.opa = opacity;
    lv_obj_refresh_style(obj);
    return this;
}



