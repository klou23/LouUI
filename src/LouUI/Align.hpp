/**
 * @file Align.hpp
 * @brief Enum with object alignment options
 * @author Kevin Lou
 * @date November 18, 2021
 *
 * @copyright Copyright (c) 2021 Kevin Lou
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

#ifndef LOUUI_ALIGN_HPP
#define LOUUI_ALIGN_HPP

namespace LouUI{
    /**
     * @enum Align
     * @brief Different alignment options for aligning objects with one another
     */
    enum Align{
        CENTER,
        IN_TOP_LEFT,
        IN_TOP_MID,
        IN_TOP_RIGHT,
        IN_BOTTOM_LEFT,
        IN_BOTTOM_MID,
        IN_BOTTOM_RIGHT,
        IN_LEFT_MID,
        IN_RIGHT_MID,
        OUT_TOP_LEFT,
        OUT_TOP_MID,
        OUT_TOP_RIGHT,
        OUT_BOTTOM_LEFT,
        OUT_BOTTOM_MID,
        OUT_BOTTOM_RIGHT,
        OUT_LEFT_TOP,
        OUT_LEFT_MID,
        OUT_LEFT_BOTTOM,
        OUT_RIGHT_TOP,
        OUT_RIGHT_MID,
        OUT_RIGHT_BOTTOM,
    };
}

#endif //LOUUI_ALIGN_HPP
