/**
 * @file Button.cpp
 * @brief Button class for non-toggleable buttons
 * @details Implementation file for the Button class, which displays a
 * non-toggleable button on the screen and will execute an action when pressed
 * @author Kevin Lou
 * @date November 25, 2021
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

#include "Button.hpp"
#include "../../include/display/lv_objx/lv_btn.h"

lv_btn_state_t LouUI::Button::convertState(LouUI::Button::State s) {
    if(s == RELEASED) return LV_BTN_STATE_REL;
    else if(s == PRESSED) return LV_BTN_STATE_PR;
    else if(s == INACTIVE) return LV_BTN_STATE_INA;
    return LV_BTN_STATE_INA;
}

LouUI::Button::Button(lv_obj_t *parent) {
    obj = lv_btn_create(parent, nullptr);

    releasedStyle = (lv_style_t *)(malloc(sizeof(lv_style_t)));
    lv_style_copy(releasedStyle, &lv_style_btn_rel);
    pressedStyle = (lv_style_t *)(malloc(sizeof(lv_style_t)));
    lv_style_copy(pressedStyle, &lv_style_btn_pr);
    inactiveStyle = (lv_style_t *)(malloc(sizeof(lv_style_t)));
    lv_style_copy(inactiveStyle, &lv_style_btn_ina);

    lv_btn_set_style(obj, LV_BTN_STYLE_REL, releasedStyle);
    lv_btn_set_style(obj, LV_BTN_STYLE_PR, pressedStyle);
    lv_btn_set_style(obj, LV_BTN_STYLE_INA, inactiveStyle);
}

LouUI::Button::Button(lv_obj_t *parent, LouUI::Button b) {
    obj = lv_btn_create(parent, b.getObj());

    releasedStyle = lv_btn_get_style(obj, LV_BTN_STYLE_REL);
    pressedStyle = lv_btn_get_style(obj, LV_BTN_STYLE_PR);
    inactiveStyle = lv_btn_get_style(obj, LV_BTN_STYLE_INA);
}

lv_obj_t *LouUI::Button::getObj() const {
    return obj;
}

lv_style_t *LouUI::Button::getReleasedStyle() const {
    return releasedStyle;
}

lv_style_t *LouUI::Button::getPressedStyle() const {
    return pressedStyle;
}

lv_style_t *LouUI::Button::getInactiveStyle() const {
    return inactiveStyle;
}

LouUI::Button *LouUI::Button::setWidth(int width) {
    lv_obj_set_width(obj, width);
    return this;
}

LouUI::Button *LouUI::Button::setHeight(int height) {
    lv_obj_set_height(obj, height);
    return this;
}

LouUI::Button *LouUI::Button::setSize(int width, int height) {
    lv_obj_set_size(obj, width, height);
    return this;
}

LouUI::Button *LouUI::Button::setX(int x) {
    lv_obj_set_x(obj, x);
    return this;
}

LouUI::Button *LouUI::Button::setY(int y) {
    lv_obj_set_y(obj, y);
    return this;
}

LouUI::Button *LouUI::Button::setPosition(int x, int y) {
    lv_obj_set_pos(obj, x, y);
    return this;
}

LouUI::Button *LouUI::Button::align(lv_obj_t *ref, LouUI::Align alignType) {
    lv_obj_align(obj, ref, alignType, 0, 0);
    return this;
}

LouUI::Button *
LouUI::Button::align(lv_obj_t *ref, LouUI::Align alignType, int xShift,
                     int yShift) {
    lv_obj_align(obj, ref, alignType, xShift, yShift);
    return this;
}

LouUI::Button *LouUI::Button::setState(LouUI::Button::State s) {
    lv_btn_set_state(obj, convertState(s));
    return this;
}

LouUI::Button *LouUI::Button::setAction(LouUI::Button::Action a) {
    lv_btn_set_action(obj, LV_BTN_ACTION_CLICK, a);
    return this;
}

LouUI::Button *
LouUI::Button::setMainColor(LouUI::Color c, LouUI::Button::State s) {
    switch(s){
        case RELEASED:
            releasedStyle->body.main_color = c.toLvColor();
            break;
        case PRESSED:
            pressedStyle->body.main_color = c.toLvColor();
            break;
        case INACTIVE:
            inactiveStyle->body.main_color = c.toLvColor();
            break;
        case ALL:
            releasedStyle->body.main_color = c.toLvColor();
            pressedStyle->body.main_color = c.toLvColor();
            inactiveStyle->body.main_color = c.toLvColor();
            break;
    }
    lv_obj_refresh_style(obj);
    return this;
}

LouUI::Button *
LouUI::Button::setGradientColor(LouUI::Color c, LouUI::Button::State s) {
    switch(s){
        case RELEASED:
            releasedStyle->body.grad_color = c.toLvColor();
            break;
        case PRESSED:
            pressedStyle->body.grad_color = c.toLvColor();
            break;
        case INACTIVE:
            inactiveStyle->body.grad_color = c.toLvColor();
            break;
        case ALL:
            releasedStyle->body.grad_color = c.toLvColor();
            pressedStyle->body.grad_color = c.toLvColor();
            inactiveStyle->body.grad_color = c.toLvColor();
            break;
    }
    lv_obj_refresh_style(obj);
    return this;
}

LouUI::Button *LouUI::Button::setRadius(int r, LouUI::Button::State s) {
    switch(s){
        case RELEASED:
            releasedStyle->body.radius = r;
            break;
        case PRESSED:
            pressedStyle->body.radius = r;
            break;
        case INACTIVE:
            inactiveStyle->body.radius = r;
            break;
        case ALL:
            releasedStyle->body.radius = r;
            pressedStyle->body.radius = r;
            inactiveStyle->body.radius = r;
            break;
    }
    lv_obj_refresh_style(obj);
    return this;
}

LouUI::Button *LouUI::Button::setOpacity(int o, LouUI::Button::State s) {
    switch(s){
        case RELEASED:
            releasedStyle->body.opa = o;
            break;
        case PRESSED:
            pressedStyle->body.opa = o;
            break;
        case INACTIVE:
            inactiveStyle->body.opa = o;
            break;
        case ALL:
            releasedStyle->body.opa = o;
            pressedStyle->body.opa = o;
            inactiveStyle->body.opa = o;
            break;
    }
    lv_obj_refresh_style(obj);
    return this;
}

LouUI::Button *
LouUI::Button::setBorderColor(LouUI::Color c, LouUI::Button::State s) {
    switch(s){
        case RELEASED:
            releasedStyle->body.border.color = c.toLvColor();
            break;
        case PRESSED:
            pressedStyle->body.border.color = c.toLvColor();
            break;
        case INACTIVE:
            inactiveStyle->body.border.color = c.toLvColor();
            break;
        case ALL:
            releasedStyle->body.border.color = c.toLvColor();
            pressedStyle->body.border.color = c.toLvColor();
            inactiveStyle->body.border.color = c.toLvColor();
            break;
    }
    lv_obj_refresh_style(obj);
    return this;
}

LouUI::Button *LouUI::Button::setBorderWidth(int w, LouUI::Button::State s) {
    switch(s){
        case RELEASED:
            releasedStyle->body.border.width = w;
            break;
        case PRESSED:
            pressedStyle->body.border.width = w;
            break;
        case INACTIVE:
            inactiveStyle->body.border.width = w;
            break;
        case ALL:
            releasedStyle->body.border.width = w;
            pressedStyle->body.border.width = w;
            inactiveStyle->body.border.width = w;
            break;
    }
    lv_obj_refresh_style(obj);
    return this;
}

LouUI::Button *LouUI::Button::setBorderOpacity(int o, LouUI::Button::State s) {
    switch(s){
        case RELEASED:
            releasedStyle->body.border.opa = o;
            break;
        case PRESSED:
            pressedStyle->body.border.opa = o;
            break;
        case INACTIVE:
            inactiveStyle->body.border.opa = o;
            break;
        case ALL:
            releasedStyle->body.border.opa = o;
            pressedStyle->body.border.opa = o;
            inactiveStyle->body.border.opa = o;
            break;
    }
    lv_obj_refresh_style(obj);
    return this;
}

LouUI::Button *
LouUI::Button::setShadowColor(LouUI::Color c, LouUI::Button::State s) {
    switch(s){
        case RELEASED:
            releasedStyle->body.shadow.color = c.toLvColor();
            break;
        case PRESSED:
            pressedStyle->body.shadow.color = c.toLvColor();
            break;
        case INACTIVE:
            inactiveStyle->body.shadow.color = c.toLvColor();
            break;
        case ALL:
            releasedStyle->body.shadow.color = c.toLvColor();
            pressedStyle->body.shadow.color = c.toLvColor();
            inactiveStyle->body.shadow.color = c.toLvColor();
            break;
    }
    lv_obj_refresh_style(obj);
    return this;
}

LouUI::Button *LouUI::Button::setShadowWidth(int w, LouUI::Button::State s) {
    switch(s){
        case RELEASED:
            releasedStyle->body.shadow.width = w;
            break;
        case PRESSED:
            pressedStyle->body.shadow.width = w;
            break;
        case INACTIVE:
            inactiveStyle->body.shadow.width = w;
            break;
        case ALL:
            releasedStyle->body.shadow.width = w;
            pressedStyle->body.shadow.width = w;
            inactiveStyle->body.shadow.width = w;
            break;
    }
    lv_obj_refresh_style(obj);
    return this;
}

LouUI::Button *LouUI::Button::setInnerPadding(int i, LouUI::Button::State s) {
    switch(s){
        case RELEASED:
            releasedStyle->body.padding.inner = i;
            break;
        case PRESSED:
            pressedStyle->body.padding.inner = i;
            break;
        case INACTIVE:
            inactiveStyle->body.padding.inner = i;
            break;
        case ALL:
            releasedStyle->body.padding.inner = i;
            pressedStyle->body.padding.inner = i;
            inactiveStyle->body.padding.inner = i;
            break;
    }
    lv_obj_refresh_style(obj);
    return this;
}

LouUI::Button *
LouUI::Button::setHorizontalPadding(int h, LouUI::Button::State s) {
    switch(s){
        case RELEASED:
            releasedStyle->body.padding.hor = h;
            break;
        case PRESSED:
            pressedStyle->body.padding.hor = h;
            break;
        case INACTIVE:
            inactiveStyle->body.padding.hor = h;
            break;
        case ALL:
            releasedStyle->body.padding.hor = h;
            pressedStyle->body.padding.hor = h;
            inactiveStyle->body.padding.hor = h;
            break;
    }
    lv_obj_refresh_style(obj);
    return this;
}

LouUI::Button
*LouUI::Button::setVerticalPadding(int v, LouUI::Button::State s) {
    switch(s){
        case RELEASED:
            releasedStyle->body.padding.ver = v;
            break;
        case PRESSED:
            pressedStyle->body.padding.ver = v;
            break;
        case INACTIVE:
            inactiveStyle->body.padding.ver = v;
            break;
        case ALL:
            releasedStyle->body.padding.ver = v;
            pressedStyle->body.padding.ver = v;
            inactiveStyle->body.padding.ver = v;
            break;
    }
    lv_obj_refresh_style(obj);
    return this;
}

LouUI::Button *
LouUI::Button::setOutsidePadding(int h, int v, LouUI::Button::State s) {
    setHorizontalPadding(h, s);
    setVerticalPadding(h, s);
    return this;
}

LouUI::Button *
LouUI::Button::setPadding(int h, int v, int i, LouUI::Button::State s) {
    setHorizontalPadding(h, s);
    setVerticalPadding(h, s);
    setInnerPadding(i, s);
    return this;
}

