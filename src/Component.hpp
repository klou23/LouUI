/**
 * @file Component.hpp
 * @brief Component class that is used to represent all components
 * @details Header file for the component class, which will be the parent
 * class for all of the UI components. It acts similar to an lvgl object.
 * @author Kevin Lou
 * @date September 8, 2021
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

#ifndef LOUUI_COMPONENT_HPP
#define LOUUI_COMPONENT_HPP

#include <string>
#include <utility>

#include "../include/display/lvgl.h"

namespace LouUI {
    class Component {
    private:

        int x;
        int y;
        int width;
        int height;
        std::string name;
        lv_obj_t* obj;
        lv_obj_t* parent;

    public:

        Component(std::string name);

        Component(std::string name, lv_obj_t *parent);

        Component(std::string name, lv_obj_t *parent, int x, int y);

        Component(std::string name, lv_obj_t *parent, int x, int y, int width,
                  int height);

        int getX() const;

        void setX(int x);

        int getY() const;

        void setY(int y);

        int getWidth() const;

        void setWidth(int width);

        int getHeight() const;

        void setHeight(int height);

        const std::string &getName() const;

        void setName(const std::string &name);

        lv_obj_t *getObj() const;

        void setObj(lv_obj_t *obj);

        lv_obj_t *getParent() const;

        void setParent(lv_obj_t *parent);
    };
}


#endif //LOUUI_COMPONENT_HPP
