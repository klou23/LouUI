/**
 * @file Chart.hpp
 * @brief Chart class used to create graphs
 * @details
 * @author Kevin Lou
 * @date March 8, 2022
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

#ifndef LOUUI_CHART_HPP
#define LOUUI_CHART_HPP

#include "Align.hpp"
#include "../../include/display/lv_core/lv_obj.h"
#include "../../include/display/lv_objx/lv_chart.h"

namespace LouUI {
    class Chart {

    private:
        lv_obj_t *obj;
        lv_style_t *style;
        lv_chart_series_t *data;

    public:

        explicit Chart(lv_obj_t *parent);

        Chart(lv_obj_t *parent, Chart c);

        lv_obj_t *getObj() const;

        lv_style_t *getStyle() const;

        Chart *addData(int16_t value);

        Chart *setPointCount(int points);

        Chart *setSize(int width, int height);

        Chart *align(lv_obj_t *ref, Align alignType);
    };
}


#endif //LOUUI_CHART_HPP
