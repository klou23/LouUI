#include "Chart.hpp"
#include <cstdlib>
#include "../../include/display/lv_core/lv_obj.h"
#include "../../include/display/lv_objx/lv_chart.h"

lv_obj_t *LouUI::Chart::getObj() const {
    return obj;
}

lv_style_t *LouUI::Chart::getStyle() const {
    return style;
}

LouUI::Chart *LouUI::Chart::addData(int16_t value) {
    lv_chart_set_next(obj, data, value);
    return this;
}

LouUI::Chart::Chart(lv_obj_t *parent) {
    obj = lv_chart_create(parent, nullptr);
    data = lv_chart_add_series(obj, LV_COLOR_RED);
    style = (lv_style_t *)(std::malloc(sizeof(lv_style_t)));
    lv_style_copy(style, &lv_style_plain);
    lv_chart_set_style(obj, style);
}

LouUI::Chart::Chart(lv_obj_t *parent, LouUI::Chart c) {
    obj = lv_chart_create(parent, c.getObj());
    data = lv_chart_add_series(obj, LV_COLOR_RED);
    style = lv_chart_get_style(obj);
}

LouUI::Chart *LouUI::Chart::setPointCount(int points) {
    lv_chart_set_point_count(obj, points);
    return this;
}

LouUI::Chart *LouUI::Chart::setSize(int width, int height) {
    lv_obj_set_size(obj, width, height);
    return this;
}

LouUI::Chart *LouUI::Chart::align(lv_obj_t *ref, Align alignType) {
    lv_obj_align(obj, ref, alignType, 0, 0);
    return this;
}