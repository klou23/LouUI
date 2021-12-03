/**
 * @file ToggleButton.cpp
 * @brief ToggleButton class for toggleable buttons
 * @details Implementation file for the ToggleButton class, which displays a
 * toggleable button on the screen and can return whether or not the button
 * is currently toggled.
 * @author Kevin Lou
 * @date November 26, 2021
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

#include "ToggleButton.hpp"
#include "../include/display/lv_objx/lv_btn.h"
#include <vector>

lv_btn_state_t LouUI::ToggleButton::convertState(LouUI::ToggleButton::State s) {
    if(s == RELEASED) return LV_BTN_STATE_REL;
    else if(s == PRESSED) return LV_BTN_STATE_PR;
    else if(s == TOGGLED_RELEASED) return LV_BTN_STATE_TGL_REL;
    else if(s == TOGGLED_PRESSED) return LV_BTN_STATE_TGL_PR;
    else if(s == INACTIVE) return LV_BTN_STATE_INA;
    return LV_BTN_STATE_INA;
}

LouUI::ToggleButton::ToggleButton(lv_obj_t *parent) {
    obj = lv_btn_create(parent, nullptr);
    lv_btn_set_toggle(obj, true);

    releasedStyle = (lv_style_t *)(malloc(sizeof(lv_style_t)));
    lv_style_copy(releasedStyle, &lv_style_plain);
    pressedStyle = (lv_style_t *)(malloc(sizeof(lv_style_t)));
    lv_style_copy(pressedStyle, &lv_style_plain);
    toggledReleasedStyle = (lv_style_t *)(malloc(sizeof(lv_style_t)));
    lv_style_copy(toggledReleasedStyle, &lv_style_plain);
    toggledPressedStyle = (lv_style_t *)(malloc(sizeof(lv_style_t)));
    lv_style_copy(toggledPressedStyle, &lv_style_plain);
    inactiveStyle = (lv_style_t *)(malloc(sizeof(lv_style_t)));
    lv_style_copy(inactiveStyle, &lv_style_plain);

    lv_btn_set_style(obj, LV_BTN_STYLE_REL, releasedStyle);
    lv_btn_set_style(obj, LV_BTN_STYLE_PR, pressedStyle);
    lv_btn_set_style(obj, LV_BTN_STYLE_TGL_REL, toggledReleasedStyle);
    lv_btn_set_style(obj, LV_BTN_STYLE_TGL_PR, toggledPressedStyle);
    lv_btn_set_style(obj, LV_BTN_STYLE_INA, inactiveStyle);
}

LouUI::ToggleButton::ToggleButton(lv_obj_t *parent, LouUI::ToggleButton b) {
    obj = lv_btn_create(parent, b.getObj());

    releasedStyle = lv_btn_get_style(obj, LV_BTN_STYLE_REL);
    pressedStyle = lv_btn_get_style(obj, LV_BTN_STYLE_PR);
    toggledReleasedStyle = lv_btn_get_style(obj, LV_BTN_STYLE_TGL_REL);
    toggledPressedStyle = lv_btn_get_style(obj, LV_BTN_STYLE_TGL_PR);
    inactiveStyle = lv_btn_get_style(obj, LV_BTN_STYLE_INA);
}

lv_obj_t *LouUI::ToggleButton::getObj() const {
    return obj;
}

lv_style_t *LouUI::ToggleButton::getReleasedStyle() const {
    return releasedStyle;
}

lv_style_t *LouUI::ToggleButton::getPressedStyle() const {
    return pressedStyle;
}

lv_style_t *LouUI::ToggleButton::getToggledReleasedStyle() const {
    return toggledReleasedStyle;
}

lv_style_t *LouUI::ToggleButton::getToggledPressedStyle() const {
    return toggledPressedStyle;
}

lv_style_t *LouUI::ToggleButton::getInactiveStyle() const {
    return inactiveStyle;
}

bool LouUI::ToggleButton::isToggled() {
    lv_btn_state_t s = lv_btn_get_state(obj);
    return s == LV_BTN_STATE_TGL_REL || s == LV_BTN_STATE_TGL_PR;
}

LouUI::ToggleButton *LouUI::ToggleButton::setWidth(int width) {
    lv_obj_set_width(obj, width);
    return this;
}

LouUI::ToggleButton *LouUI::ToggleButton::setHeight(int height) {
    lv_obj_set_height(obj, height);
    return this;
}

LouUI::ToggleButton *LouUI::ToggleButton::setSize(int width, int height) {
    lv_obj_set_size(obj, width, height);
    return this;
}

LouUI::ToggleButton *LouUI::ToggleButton::setX(int x) {
    lv_obj_set_x(obj, x);
    return this;
}

LouUI::ToggleButton *LouUI::ToggleButton::setY(int y) {
    lv_obj_set_y(obj, y);
    return this;
}

LouUI::ToggleButton *LouUI::ToggleButton::setPosition(int x, int y) {
    lv_obj_set_pos(obj, x, y);
    return this;
}

LouUI::ToggleButton *
LouUI::ToggleButton::align(lv_obj_t *ref, LouUI::Align alignType) {
    lv_obj_align(obj, ref, alignType, 0, 0);
    return this;
}

LouUI::ToggleButton *
LouUI::ToggleButton::align(lv_obj_t *ref, LouUI::Align alignType, int xShift,
                     int yShift) {
    lv_obj_align(obj, ref, alignType, xShift, yShift);
    return this;
}

LouUI::ToggleButton *
LouUI::ToggleButton::setState(LouUI::ToggleButton::State s) {
    lv_btn_set_state(obj, convertState(s));
    return this;
}

LouUI::ToggleButton *
LouUI::ToggleButton::setMainColor(LouUI::Color c,
                                  LouUI::ToggleButton::State s) {
    switch(s){
        case RELEASED:
            releasedStyle->body.main_color = c.toLvColor();
            break;
        case PRESSED:
            pressedStyle->body.main_color = c.toLvColor();
            break;
        case TOGGLED_RELEASED:
            toggledReleasedStyle->body.main_color = c.toLvColor();
            break;
        case TOGGLED_PRESSED:
            toggledPressedStyle->body.main_color = c.toLvColor();
            break;
        case INACTIVE:
            inactiveStyle->body.main_color = c.toLvColor();
            break;
        case ALL_RELEASED:
            releasedStyle->body.main_color = c.toLvColor();
            toggledReleasedStyle->body.main_color = c.toLvColor();
            break;
        case ALL_PRESSED:
            pressedStyle->body.main_color = c.toLvColor();
            toggledPressedStyle->body.main_color = c.toLvColor();
            break;
        case ALL_UNTOGGLED:
            releasedStyle->body.main_color = c.toLvColor();
            pressedStyle->body.main_color = c.toLvColor();
            break;
        case ALL_TOGGLED:
            toggledReleasedStyle->body.main_color = c.toLvColor();
            toggledPressedStyle->body.main_color = c.toLvColor();
            break;
        case ALL:
            releasedStyle->body.main_color = c.toLvColor();
            pressedStyle->body.main_color = c.toLvColor();
            toggledReleasedStyle->body.main_color = c.toLvColor();
            toggledPressedStyle->body.main_color = c.toLvColor();
            inactiveStyle->body.main_color = c.toLvColor();
            break;
    }
    lv_obj_refresh_style(obj);
    return this;
}

LouUI::ToggleButton *
LouUI::ToggleButton::setGradientColor(LouUI::Color c,
                                      LouUI::ToggleButton::State s) {
    switch(s){
        case RELEASED:
            releasedStyle->body.grad_color = c.toLvColor();
            break;
        case PRESSED:
            pressedStyle->body.grad_color = c.toLvColor();
            break;
        case TOGGLED_RELEASED:
            toggledReleasedStyle->body.grad_color = c.toLvColor();
            break;
        case TOGGLED_PRESSED:
            toggledPressedStyle->body.grad_color = c.toLvColor();
            break;
        case INACTIVE:
            inactiveStyle->body.grad_color = c.toLvColor();
            break;
        case ALL_RELEASED:
            releasedStyle->body.grad_color = c.toLvColor();
            toggledReleasedStyle->body.grad_color = c.toLvColor();
            break;
        case ALL_PRESSED:
            pressedStyle->body.grad_color = c.toLvColor();
            toggledPressedStyle->body.grad_color = c.toLvColor();
            break;
        case ALL_UNTOGGLED:
            releasedStyle->body.grad_color = c.toLvColor();
            pressedStyle->body.grad_color = c.toLvColor();
            break;
        case ALL_TOGGLED:
            toggledReleasedStyle->body.grad_color = c.toLvColor();
            toggledPressedStyle->body.grad_color = c.toLvColor();
            break;
        case ALL:
            releasedStyle->body.grad_color = c.toLvColor();
            pressedStyle->body.grad_color = c.toLvColor();
            toggledReleasedStyle->body.grad_color = c.toLvColor();
            toggledPressedStyle->body.grad_color = c.toLvColor();
            inactiveStyle->body.grad_color = c.toLvColor();
            break;
    }
    lv_obj_refresh_style(obj);
    return this;
}

LouUI::ToggleButton *
LouUI::ToggleButton::setRadius(int r, LouUI::ToggleButton::State s) {
    switch(s){
        case RELEASED:
            releasedStyle->body.radius = r;
            break;
        case PRESSED:
            pressedStyle->body.radius = r;
            break;
        case TOGGLED_RELEASED:
            toggledReleasedStyle->body.radius = r;
            break;
        case TOGGLED_PRESSED:
            toggledPressedStyle->body.radius = r;
            break;
        case INACTIVE:
            inactiveStyle->body.radius = r;
            break;
        case ALL_RELEASED:
            releasedStyle->body.radius = r;
            toggledReleasedStyle->body.radius = r;
            break;
        case ALL_PRESSED:
            pressedStyle->body.radius = r;
            toggledPressedStyle->body.radius = r;
            break;
        case ALL_UNTOGGLED:
            releasedStyle->body.radius = r;
            pressedStyle->body.radius = r;
            break;
        case ALL_TOGGLED:
            toggledReleasedStyle->body.radius = r;
            toggledPressedStyle->body.radius = r;
            break;
        case ALL:
            releasedStyle->body.radius = r;
            pressedStyle->body.radius = r;
            toggledReleasedStyle->body.radius = r;
            toggledPressedStyle->body.radius = r;
            inactiveStyle->body.radius = r;
            break;
    }
    lv_obj_refresh_style(obj);
    return this;
}

LouUI::ToggleButton *
LouUI::ToggleButton::setOpacity(int o, LouUI::ToggleButton::State s) {
    switch(s){
        case RELEASED:
            releasedStyle->body.opa = o;
            break;
        case PRESSED:
            pressedStyle->body.opa = o;
            break;
        case TOGGLED_RELEASED:
            toggledReleasedStyle->body.opa = o;
            break;
        case TOGGLED_PRESSED:
            toggledPressedStyle->body.opa = o;
            break;
        case INACTIVE:
            inactiveStyle->body.opa = o;
            break;
        case ALL_RELEASED:
            releasedStyle->body.opa = o;
            toggledReleasedStyle->body.opa = o;
            break;
        case ALL_PRESSED:
            pressedStyle->body.opa = o;
            toggledPressedStyle->body.opa = o;
            break;
        case ALL_UNTOGGLED:
            releasedStyle->body.opa = o;
            pressedStyle->body.opa = o;
            break;
        case ALL_TOGGLED:
            toggledReleasedStyle->body.opa = o;
            toggledPressedStyle->body.opa = o;
            break;
        case ALL:
            releasedStyle->body.opa = o;
            pressedStyle->body.opa = o;
            toggledReleasedStyle->body.opa = o;
            toggledPressedStyle->body.opa = o;
            inactiveStyle->body.opa = o;
            break;
    }
    lv_obj_refresh_style(obj);
    return this;
}

LouUI::ToggleButton *
LouUI::ToggleButton::setBorderColor(LouUI::Color c,
                                    LouUI::ToggleButton::State s) {
    switch(s){
        case RELEASED:
            releasedStyle->body.border.color = c.toLvColor();
            break;
        case PRESSED:
            pressedStyle->body.border.color = c.toLvColor();
            break;
        case TOGGLED_RELEASED:
            toggledReleasedStyle->body.border.color = c.toLvColor();
            break;
        case TOGGLED_PRESSED:
            toggledPressedStyle->body.border.color = c.toLvColor();
            break;
        case INACTIVE:
            inactiveStyle->body.border.color = c.toLvColor();
            break;
        case ALL_RELEASED:
            releasedStyle->body.border.color = c.toLvColor();
            toggledReleasedStyle->body.border.color = c.toLvColor();
            break;
        case ALL_PRESSED:
            pressedStyle->body.border.color = c.toLvColor();
            toggledPressedStyle->body.border.color = c.toLvColor();
            break;
        case ALL_UNTOGGLED:
            releasedStyle->body.border.color = c.toLvColor();
            pressedStyle->body.border.color = c.toLvColor();
            break;
        case ALL_TOGGLED:
            toggledReleasedStyle->body.border.color = c.toLvColor();
            toggledPressedStyle->body.border.color = c.toLvColor();
            break;
        case ALL:
            releasedStyle->body.border.color = c.toLvColor();
            pressedStyle->body.border.color = c.toLvColor();
            toggledReleasedStyle->body.border.color = c.toLvColor();
            toggledPressedStyle->body.border.color = c.toLvColor();
            inactiveStyle->body.border.color = c.toLvColor();
            break;
    }
    lv_obj_refresh_style(obj);
    return this;
}

LouUI::ToggleButton *
LouUI::ToggleButton::setBorderWidth(int w, LouUI::ToggleButton::State s) {
    switch(s){
        case RELEASED:
            releasedStyle->body.border.width = w;
            break;
        case PRESSED:
            pressedStyle->body.border.width = w;
            break;
        case TOGGLED_RELEASED:
            toggledReleasedStyle->body.border.width = w;
            break;
        case TOGGLED_PRESSED:
            toggledPressedStyle->body.border.width = w;
            break;
        case INACTIVE:
            inactiveStyle->body.border.width = w;
            break;
        case ALL_RELEASED:
            releasedStyle->body.border.width = w;
            toggledReleasedStyle->body.border.width = w;
            break;
        case ALL_PRESSED:
            pressedStyle->body.border.width = w;
            toggledPressedStyle->body.border.width = w;
            break;
        case ALL_UNTOGGLED:
            releasedStyle->body.border.width = w;
            pressedStyle->body.border.width = w;
            break;
        case ALL_TOGGLED:
            toggledReleasedStyle->body.border.width = w;
            toggledPressedStyle->body.border.width = w;
            break;
        case ALL:
            releasedStyle->body.border.width = w;
            pressedStyle->body.border.width = w;
            toggledReleasedStyle->body.border.width = w;
            toggledPressedStyle->body.border.width = w;
            inactiveStyle->body.border.width = w;
            break;
    }
    lv_obj_refresh_style(obj);
    return this;
}

LouUI::ToggleButton *
LouUI::ToggleButton::setBorderOpacity(int o, LouUI::ToggleButton::State s) {
    switch(s){
        case RELEASED:
            releasedStyle->body.border.opa = o;
            break;
        case PRESSED:
            pressedStyle->body.border.opa = o;
            break;
        case TOGGLED_RELEASED:
            toggledReleasedStyle->body.border.opa = o;
            break;
        case TOGGLED_PRESSED:
            toggledPressedStyle->body.border.opa = o;
            break;
        case INACTIVE:
            inactiveStyle->body.border.opa = o;
            break;
        case ALL_RELEASED:
            releasedStyle->body.border.opa = o;
            toggledReleasedStyle->body.border.opa = o;
            break;
        case ALL_PRESSED:
            pressedStyle->body.border.opa = o;
            toggledPressedStyle->body.border.opa = o;
            break;
        case ALL_UNTOGGLED:
            releasedStyle->body.border.opa = o;
            pressedStyle->body.border.opa = o;
            break;
        case ALL_TOGGLED:
            toggledReleasedStyle->body.border.opa = o;
            toggledPressedStyle->body.border.opa = o;
            break;
        case ALL:
            releasedStyle->body.border.opa = o;
            pressedStyle->body.border.opa = o;
            toggledReleasedStyle->body.border.opa = o;
            toggledPressedStyle->body.border.opa = o;
            inactiveStyle->body.border.opa = o;
            break;
    }
    lv_obj_refresh_style(obj);
    return this;
}

LouUI::ToggleButton *LouUI::ToggleButton::setShadowColor(LouUI::Color c,
                                                         LouUI::ToggleButton::State s) {
    switch(s){
        case RELEASED:
            releasedStyle->body.shadow.color = c.toLvColor();
            break;
        case PRESSED:
            pressedStyle->body.shadow.color = c.toLvColor();
            break;
        case TOGGLED_RELEASED:
            toggledReleasedStyle->body.shadow.color = c.toLvColor();
            break;
        case TOGGLED_PRESSED:
            toggledPressedStyle->body.shadow.color = c.toLvColor();
            break;
        case INACTIVE:
            inactiveStyle->body.shadow.color = c.toLvColor();
            break;
        case ALL_RELEASED:
            releasedStyle->body.shadow.color = c.toLvColor();
            toggledReleasedStyle->body.shadow.color = c.toLvColor();
            break;
        case ALL_PRESSED:
            pressedStyle->body.shadow.color = c.toLvColor();
            toggledPressedStyle->body.shadow.color = c.toLvColor();
            break;
        case ALL_UNTOGGLED:
            releasedStyle->body.shadow.color = c.toLvColor();
            pressedStyle->body.shadow.color = c.toLvColor();
            break;
        case ALL_TOGGLED:
            toggledReleasedStyle->body.shadow.color = c.toLvColor();
            toggledPressedStyle->body.shadow.color = c.toLvColor();
            break;
        case ALL:
            releasedStyle->body.shadow.color = c.toLvColor();
            pressedStyle->body.shadow.color = c.toLvColor();
            toggledReleasedStyle->body.shadow.color = c.toLvColor();
            toggledPressedStyle->body.shadow.color = c.toLvColor();
            inactiveStyle->body.shadow.color = c.toLvColor();
            break;
    }
    lv_obj_refresh_style(obj);
    return this;
}

LouUI::ToggleButton *
LouUI::ToggleButton::setShadowWidth(int w, LouUI::ToggleButton::State s) {
    switch(s){
        case RELEASED:
            releasedStyle->body.shadow.width = w;
            break;
        case PRESSED:
            pressedStyle->body.shadow.width = w;
            break;
        case TOGGLED_RELEASED:
            toggledReleasedStyle->body.shadow.width = w;
            break;
        case TOGGLED_PRESSED:
            toggledPressedStyle->body.shadow.width = w;
            break;
        case INACTIVE:
            inactiveStyle->body.shadow.width = w;
            break;
        case ALL_RELEASED:
            releasedStyle->body.shadow.width = w;
            toggledReleasedStyle->body.shadow.width = w;
            break;
        case ALL_PRESSED:
            pressedStyle->body.shadow.width = w;
            toggledPressedStyle->body.shadow.width = w;
            break;
        case ALL_UNTOGGLED:
            releasedStyle->body.shadow.width = w;
            pressedStyle->body.shadow.width = w;
            break;
        case ALL_TOGGLED:
            toggledReleasedStyle->body.shadow.width = w;
            toggledPressedStyle->body.shadow.width = w;
            break;
        case ALL:
            releasedStyle->body.shadow.width = w;
            pressedStyle->body.shadow.width = w;
            toggledReleasedStyle->body.shadow.width = w;
            toggledPressedStyle->body.shadow.width = w;
            inactiveStyle->body.shadow.width = w;
            break;
    }
    lv_obj_refresh_style(obj);
    return this;
}

LouUI::ToggleButton *
LouUI::ToggleButton::setInnerPadding(int i, LouUI::ToggleButton::State s) {
    switch(s){
        case RELEASED:
            releasedStyle->body.padding.inner = i;
            break;
        case PRESSED:
            pressedStyle->body.padding.inner = i;
            break;
        case TOGGLED_RELEASED:
            toggledReleasedStyle->body.padding.inner = i;
            break;
        case TOGGLED_PRESSED:
            toggledPressedStyle->body.padding.inner = i;
            break;
        case INACTIVE:
            inactiveStyle->body.padding.inner = i;
            break;
        case ALL_RELEASED:
            releasedStyle->body.padding.inner = i;
            toggledReleasedStyle->body.padding.inner = i;
            break;
        case ALL_PRESSED:
            pressedStyle->body.padding.inner = i;
            toggledPressedStyle->body.padding.inner = i;
            break;
        case ALL_UNTOGGLED:
            releasedStyle->body.padding.inner = i;
            pressedStyle->body.padding.inner = i;
            break;
        case ALL_TOGGLED:
            toggledReleasedStyle->body.padding.inner = i;
            toggledPressedStyle->body.padding.inner = i;
            break;
        case ALL:
            releasedStyle->body.padding.inner = i;
            pressedStyle->body.padding.inner = i;
            toggledReleasedStyle->body.padding.inner = i;
            toggledPressedStyle->body.padding.inner = i;
            inactiveStyle->body.padding.inner = i;
            break;
    }
    lv_obj_refresh_style(obj);
    return this;
}

LouUI::ToggleButton *
LouUI::ToggleButton::setHorizontalPadding(int h, LouUI::ToggleButton::State s) {
    switch(s){
        case RELEASED:
            releasedStyle->body.padding.hor = h;
            break;
        case PRESSED:
            pressedStyle->body.padding.hor = h;
            break;
        case TOGGLED_RELEASED:
            toggledReleasedStyle->body.padding.hor = h;
            break;
        case TOGGLED_PRESSED:
            toggledPressedStyle->body.padding.hor = h;
            break;
        case INACTIVE:
            inactiveStyle->body.padding.hor = h;
            break;
        case ALL_RELEASED:
            releasedStyle->body.padding.hor = h;
            toggledReleasedStyle->body.padding.hor = h;
            break;
        case ALL_PRESSED:
            pressedStyle->body.padding.hor = h;
            toggledPressedStyle->body.padding.hor = h;
            break;
        case ALL_UNTOGGLED:
            releasedStyle->body.padding.hor = h;
            pressedStyle->body.padding.hor = h;
            break;
        case ALL_TOGGLED:
            toggledReleasedStyle->body.padding.hor = h;
            toggledPressedStyle->body.padding.hor = h;
            break;
        case ALL:
            releasedStyle->body.padding.hor = h;
            pressedStyle->body.padding.hor = h;
            toggledReleasedStyle->body.padding.hor = h;
            toggledPressedStyle->body.padding.hor = h;
            inactiveStyle->body.padding.hor = h;
            break;
    }
    lv_obj_refresh_style(obj);
    return this;
}

LouUI::ToggleButton *
LouUI::ToggleButton::setVerticalPadding(int v, LouUI::ToggleButton::State s) {
    switch(s){
        case RELEASED:
            releasedStyle->body.padding.ver = v;
            break;
        case PRESSED:
            pressedStyle->body.padding.ver = v;
            break;
        case TOGGLED_RELEASED:
            toggledReleasedStyle->body.padding.ver = v;
            break;
        case TOGGLED_PRESSED:
            toggledPressedStyle->body.padding.ver = v;
            break;
        case INACTIVE:
            inactiveStyle->body.padding.ver = v;
            break;
        case ALL_RELEASED:
            releasedStyle->body.padding.ver = v;
            toggledReleasedStyle->body.padding.ver = v;
            break;
        case ALL_PRESSED:
            pressedStyle->body.padding.ver = v;
            toggledPressedStyle->body.padding.ver = v;
            break;
        case ALL_UNTOGGLED:
            releasedStyle->body.padding.ver = v;
            pressedStyle->body.padding.ver = v;
            break;
        case ALL_TOGGLED:
            toggledReleasedStyle->body.padding.ver = v;
            toggledPressedStyle->body.padding.ver = v;
            break;
        case ALL:
            releasedStyle->body.padding.ver = v;
            pressedStyle->body.padding.ver = v;
            toggledReleasedStyle->body.padding.ver = v;
            toggledPressedStyle->body.padding.ver = v;
            inactiveStyle->body.padding.ver = v;
            break;
    }
    lv_obj_refresh_style(obj);
    return this;
}

LouUI::ToggleButton *
LouUI::ToggleButton::setOutsidePadding(int h, int v,
                                       LouUI::ToggleButton::State s) {
    setHorizontalPadding(h, s);
    setVerticalPadding(v, s);
    return this;
}

LouUI::ToggleButton *
LouUI::ToggleButton::setPadding(int h, int v, int i,
                                LouUI::ToggleButton::State s) {
    setHorizontalPadding(h, s);
    setVerticalPadding(v, s);
    setInnerPadding(i, s);
    return this;
}

