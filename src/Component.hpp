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
        lv_obj_t *obj;
        lv_obj_t *parent;

    public:
        /**
         * Creates a new Component
         * @warning this constructor should generally should not be used as
         * it does not have a parent object
         * @param name name of the component to be created. This name should
         * be unique
         */
        explicit Component(std::string name);

        /**
         * Creates a new Component
         * @param name name of the component to be created. This name should
         * be unique
         * @param parent pointer to the parent lvgl object for this component.
         * This should not be null
         */
        Component(std::string name, lv_obj_t *parent);

        /**
         * Creates a new Component
         * @param name name of the component to be created. This name should
         * be unique
         * @param parent pointer to the parent lvgl object for this component.
         * This should not be null
         * @param x x-coordinate of the top left corner of the component
         * @param y y-coordinate of the top right corner of the component
         */
        Component(std::string name, lv_obj_t *parent, int x, int y);

        /**
         * Creates a new Component
         * @param name name of the component to be created. This name should
         * be unique
         * @param parent pointer to the parent lvgl object for this component.
         * This should not be null
         * @param x x-coordinate of the top left corner of the component
         * @param y y-coordinate of the top right corner of the component
         * @param width width of the component
         * @param height height of the component
         */
        Component(std::string name, lv_obj_t *parent, int x, int y, int width,
                  int height);

        /**
         * Getter for x
         */
        __attribute__((unused)) int getX() const;

        /**
         * Setter for x
         */
        __attribute__((unused)) void setX(int x);

        /**
         * Getter for y
         */
        __attribute__((unused)) int getY() const;

        /**
         * Setter for y
         */
        __attribute__((unused)) void setY(int y);

        /**
         * Getter for width
         */
        __attribute__((unused)) int getWidth() const;

        /**
         * Setter for width
         */
        __attribute__((unused)) void setWidth(int width);

        /**
         * Getter for height
         */
        __attribute__((unused)) int getHeight() const;

        /**
         * Setter for height
         */
        __attribute__((unused)) void setHeight(int height);

        /**
         * Getter for name
         */
        const std::string &getName() const;

        /**
         * Setter for name
         */
        __attribute__((unused)) void setName(const std::string &name);

        /**
         * Getter for obj
         */
        __attribute__((unused)) lv_obj_t *getObj() const;

        /**
         * Setter for obj
         */
        __attribute__((unused)) void setObj(lv_obj_t *obj);

        /**
         * Getter for parent
         */
        __attribute__((unused)) lv_obj_t *getParent() const;

        /**
         * Setter for parent
         */
        void setParent(lv_obj_t *parent);
    };
}


#endif //LOUUI_COMPONENT_HPP
