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
#include "Color.hpp"

#include <unordered_map>

namespace LouUI {
    class Chart {

    private:
        lv_obj_t *obj;
        lv_style_t *style;
        std::unordered_map<std::string, lv_chart_series_t*> data;

    public:

        /**
         * Creates a new Chart
         * @param parent The object the chart is created in
         */
        explicit Chart(lv_obj_t *parent);

        /**
         * Creates a new Chart as a copy of another Chart
         * @param parent The object the chart is created in
         * @param c The chart from which the copy is made
         */
        Chart(lv_obj_t *parent, Chart c);

        /**
         * Getter for obj
         */
        lv_obj_t *getObj() const;

        /**
         * Getter for style
         */
        lv_style_t *getStyle() const;

        /**
         * Add a new series to the chart
         * @param name desired series name
         * @param c color for the series
         */
        Chart *addSeries(std::string name, LouUI::Color c);

        /**
         * Getter for a specific series
         * @param name name of the series to get
         */
        lv_chart_series_t *getSeries(std::string name);

        /**
         * Add a data point to a series
         * @param series series name
         * @param value data point value
         */
        Chart *addData(std::string series, int16_t value);

        /**
         * Set the amount of points for the chart. Affects all series in the
         * chart
         */
        Chart *setPointCount(int points);

        /**
         * Sets the dimensions of the chart
         */
        Chart *setSize(int width, int height);

        /**
         * Aligns the chart to another object
         * @param ref object to align to
         * @param alignType type of alignment
         */
        Chart *align(lv_obj_t *ref, Align alignType);

        /**
         * Sets the bounds of the chart (y-values)
         */
        Chart *setRange(int min, int max);
    };
}


#endif //LOUUI_CHART_HPP
