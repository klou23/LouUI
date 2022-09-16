/**
 * @file Gauge.cpp
 * @brief Gauge class used to display data in the form of a gauge
 * @details
 * @author Kevin Lou
 * @date June 19, 2022
 *
 * Copyright (c) 2022 Kevin Lou
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

#include "Gauge.hpp"
#include "../../include/display/lv_core/lv_obj.h"
#include "../../include/display/lv_objx/lv_gauge.h"

lv_obj_t *LouUI::Gauge::getObj() const {
    return obj;
}

lv_style_t *LouUI::Gauge::getStyle() const {
    return style;
}

LouUI::Gauge::Gauge(lv_obj_t *parent) {
    obj = lv_gauge_create(parent, nullptr);
    style = (lv_style_t *)(std::malloc(sizeof(lv_style_t)));
    lv_style_copy(style, &lv_style_pretty_color);
    needles[0] = LV_COLOR_RED;
}

LouUI::Gauge::Gauge(lv_obj_t *parent, LouUI::Gauge g) {
    obj = lv_gauge_create(parent, g.getObj());
    style = lv_gauge_get_style(obj);
}

LouUI::Gauge *LouUI::Gauge::setScale(int angle, int lineCnt, int labelCnt) {
    lv_gauge_set_scale(obj, angle, lineCnt, labelCnt);
    return this;
}

LouUI::Gauge *LouUI::Gauge::setRange(int min, int max) {
    lv_gauge_set_range(obj, min, max);
    return this;
}

LouUI::Gauge *LouUI::Gauge::setCriticalValue(int value) {
    lv_gauge_set_critical_value(obj, value);
    return this;
}

LouUI::Gauge *LouUI::Gauge::setStartColor(LouUI::Color c) {
    style->body.main_color = c.toLvColor();
    return this;
}

LouUI::Gauge *LouUI::Gauge::setEndColor(LouUI::Color c) {
    style->body.grad_color = c.toLvColor();
    return this;
}

LouUI::Gauge *LouUI::Gauge::setLineLength(int length) {
    style->body.padding.hor = length;
    return this;
}

LouUI::Gauge *LouUI::Gauge::setLabelPadding(int padding) {
    style->body.padding.inner = padding;
    return this;
}

LouUI::Gauge *LouUI::Gauge::setCenterRadius(int radius) {
    style->body.radius = radius;
    return this;
}

LouUI::Gauge *LouUI::Gauge::setLineWidth(int width) {
    style->line.width = width;
    return this;
}

LouUI::Gauge *LouUI::Gauge::setCriticalColor(LouUI::Color c) {
    style->line.color = c.toLvColor();
    return this;
}

LouUI::Gauge *LouUI::Gauge::setSize(int width, int height) {
    lv_obj_set_size(obj, width, height);
    return this;
}

LouUI::Gauge *LouUI::Gauge::align(lv_obj_t *ref, LouUI::Align alignType) {
    lv_obj_align(obj, ref, alignType, 0, 0);
    return this;
}

LouUI::Gauge *LouUI::Gauge::align(lv_obj_t *ref, LouUI::Align alignType, int xShift, int yShift) {
    lv_obj_align(obj, ref, alignType, xShift, yShift);
    return this;
}