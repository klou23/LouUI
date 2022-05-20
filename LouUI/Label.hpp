/**
 * @file Label.hpp
 * @brief Label class used to represent text labels
 * @details Header file for the Label class, which displays a string
 * of text on the screen
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

#ifndef LOUUI_LABEL_HPP
#define LOUUI_LABEL_HPP

#include <string>
#include "Color.hpp"
#include "Align.hpp"
#include "../../include/display/lvgl.h"
#include "../../include/display/lv_objx/lv_label.h"
#include "Fonts.hpp"

namespace LouUI {

    /**
     * @class Label
     * @brief Displays strings on text on the screen
     * @details
     * A Label is the UI component to show simple text strings on the screen.
     * @subsection usage Usage
     * @subsubsection settingText Setting Text
     * The text in the label can be set with the setText(std::string text) method.
     * This will automatically allocate memory for the string to be copied into.
     * Therefore, you don't need to keep the string you in scope;
     * local variables are fine.
     *
     * @subsubsection newline Newlines
     * Newlines can be created using the newline character: <code>\\n</code>.
     * For example: <code>"line1\nline2\n\nline4"</code>
     *
     * @subsection properties Properties
     *
     * @subsubsection longModes Long Modes
     * If the label contains lines that are wider than the label's width, there
     * are several different #LongMode options that allow for changing the
     * formatting of these lines. You can change between these long modes using
     * the setLongMode(LongMode m) method.
     *
     * @subsubsection textAlign Text Align
     * There are three different #TextAlign options. You can change the current
     * text align option using the setTextAlign(TextAlign a) method.
     *
     * @subsubsection textColor Text Color
     * The label text color can be changed to any LouUI::Color. This can be done
     * using the setColor(Color c) method.
     * The opacity of the label can also be changed using the setOpacity(int opacity)
     * method.
     *
     * @subsubsection font Font
     * The label's font size and font type (monospaced or variable-width) can be
     * changed using the setFont(int size, bool mono) method.
     *
     * @subsubsection position Position
     * The label's location consists of an x and y coordinate. These coordinates
     * can be set individually using the setX(int x) and setY(int y) methods, or
     * at the same time using the setPosition(int x, int y) method.
     *
     * The label can also be aligned to another UI object with the
     * align(lv_obj_t *ref, Align alignType) or
     * align(lv_obj_t * ref, Align alignType, int xShift, int yShift) method.
     *
     * @subsubsection size Size
     * The width of the label can be set with the setWidth(int width) method. If
     * the label's long mode is EXPAND, the label's width may end up being greater
     * than this set value.
     * The height of the label is automatically decided based on the text displayed
     * by the label.
     */

    class Label {

    public:
        /**
         * @enum LongMode
         * @brief Different ways of dealing with lines that are too long
         */
        enum LongMode{
            /**Expands the label size to the text size (Default)*/
            EXPAND,
            /**Wrap the lines and expand the label height*/
            BREAK,
            /**Scroll the label text back and forth*/
            SCROLL,
            /**Keep the label size, replace overflowing text with dots*/
            DOT,
            /**Keep the size and roll the text circularly*/
            ROLL,
            /**Keep the label size and crop out overflowing text*/
            CROP,
        };

        /**
         * @enum TextAlign
         * @brief Different text alignment options
         */
        enum TextAlign{
            /**Left Align (Default)**/
            LEFT,
            /**Center Align**/
            CENTER,
            /**Right Align*/
            RIGHT,
        };

    private:
        lv_obj_t *obj;
        std::string text;
        Color c;
        lv_style_t *style;

    public:

        /**
         * Creates a new Label
         * @param parent The object the label is created in
         */
        explicit Label(lv_obj_t *parent);

        /**
         * Creates a new label as a copy of another label
         * @param parent The object the label is created in
         * @param l The label from which the copy is made
         */
        Label(lv_obj_t *parent, Label l);

        /**
         * Getter for obj
         */
        lv_obj_t *getObj() const;

        /**
         * Getter for c
         */
        const Color &getC() const;

        /**
         * Getter for style
         */
        lv_style_t *getStyle() const;

        /**
         * Sets the color of the label
         */
        Label* setColor(Color c);

        /**
         * Sets the width of the label
         */
        Label* setWidth(int width);

        /**
         * Sets the x position of the label
         */
        Label* setX(int x);

        /**
         * Sets the y position of the label
         */
        Label* setY(int y);

        /**
         * Sets the position of the label
         */
        Label* setPosition(int x, int y);

        /**
         * Aligns the label to another object
         * @param ref object to align to
         * @param alignType type of alignment
         */
        Label* align(lv_obj_t *ref, Align alignType);

        /**
         * Aligns the label to another object
         * @param ref object to align to
         * @param alignType type of alignment
         * @param xShift pixels to shift in the x-direction
         * @param yShift pixels to shift in the y-direction
         */
        Label* align(lv_obj_t *ref, Align alignType, int xShift,
                     int yShift);

        /**
         * Sets the text of the label
         */
        Label* setText(std::string text);

        /**
         * Sets the long mode of the label, which determines behavior when
         * the text in the label is too long
         */
        Label* setLongMode(LongMode m);

        /**
         * Sets the text alignment within the label
         */
        Label* setTextAlign(TextAlign a);

        /**
         * Sets the font of the label
         * @param size font size. This can be: 10, 20, 30, or 40
         * @param mono whether or not the font is mono
         */
        Label* setFont(int size, bool mono = false);

        /**
         * Sets the opacity of the label
         * @param opacity label opacity. This should be between 0 and 225
         */
        Label* setOpacity(int opacity);

    };
}


#endif //LOUUI_LABEL_HPP
