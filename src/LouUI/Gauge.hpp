/**
 * @file Gauge.hpp
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

#ifndef LOUUI_GAUGE_HPP
#define LOUUI_GAUGE_HPP

#include "Align.hpp"
#include "../../include/display/lv_core/lv_obj.h"
#include "../../include/display/lv_objx/lv_gauge.h"
#include "Color.hpp"

namespace LouUI {
    class Gauge {

    private:
        lv_obj_t *obj;
        lv_style_t *style;
        lv_color_t needles[1];

    public:

        explicit Gauge(lv_obj_t *parent);

        Gauge(lv_obj_t *parent, Gauge g);

        lv_obj_t *getObj() const;

        lv_style_t *getStyle() const;

        Gauge *setScale(int angle, int lineCnt, int labelCnt);

        Gauge *setRange(int min, int max);

        Gauge *setCriticalValue(int value);

        Gauge *setStartColor(LouUI::Color c);

        Gauge *setEndColor(LouUI::Color c);

        Gauge *setLineLength(int length);

        Gauge *setLabelPadding(int padding);

        Gauge *setCenterRadius(int radius);

        Gauge *setLineWidth(int width);

        Gauge *setCriticalColor(LouUI::Color c);

        Gauge *setSize(int width, int height);

        Gauge *align(lv_obj_t *ref, Align alignType);

        Gauge *align(lv_obj_t *ref, Align alignType, int xShift, int yShift);
    };
}


#endif //LOUUI_GAUGE_HPP
