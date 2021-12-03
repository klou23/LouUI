/**
 * @file main.cpp
 * @brief The main file
 * @details Contains the competition functions
 * @author Kevin Lou
 * @date September 2, 2021
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

#include "main.h"
#include "UIVars.hpp"
#include "Button.hpp"

LouUI::Display display;
LouUI::Button* b = nullptr;

/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize() {
    display.addScreen("Screen1");
    display.addScreen("Screen2");

    static LouUI::Label l(display.getScreen("Screen1"));
    l.setText("Label");

//    static lv_obj_t* l = nullptr;
//    l = lv_label_create(display.getScreen("Screen1"), nullptr);
//    static lv_style_t* style = (lv_style_t *)(malloc(sizeof(lv_style_t)));
//    lv_style_copy(style, &lv_style_plain_color);
//    lv_label_set_style(l, style);
//    lv_label_set_text(l, "hello world");

    b = (new LouUI::Button(display.getScreen("Screen1")))
            ->setMainColor(LouUI::Color("BLUE"), LouUI::Button::ALL)
            ->setGradientColor(LouUI::Color("BLUE"), LouUI::Button::ALL)
            ->setMainColor(LouUI::Color("RED"), LouUI::Button::PRESSED)
            ->setGradientColor(LouUI::Color("RED"), LouUI::Button::PRESSED)
            ->setPosition(200, 50);

    static LouUI::Label* bl = (new LouUI::Label(b->getObj()))
            ->setText("Button");

//    label1 = (new LouUI::Label(display.getScreen("Screen1")))
//            ->setText("Label1")->setPosition(20, 20);

//    static lv_obj_t* label = lv_label_create(display.getScreen("Screen1"),
//                                             nullptr);
//    lv_label_set_text(label, "Label2");

}

/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled() {}

/**
 * Runs after initialize(), and before autonomous when connected to the Field
 * Management System or the VEX Competition Switch. This is intended for
 * competition-specific initialization routines, such as an autonomous selector
 * on the LCD.
 *
 * This task will exit when the robot is enabled and autonomous or opcontrol
 * starts.
 */
void competition_initialize() {}

/**
 * Runs the user autonomous code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the autonomous
 * mode. Alternatively, this function may be called in initialize or opcontrol
 * for non-competition testing purposes.
 *
 * If the robot is disabled or communications is lost, the autonomous task
 * will be stopped. Re-enabling the robot will restart the task, not re-start it
 * from where it left off.
 */
void autonomous() {}

/**
 * Runs the operator control code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the operator
 * control mode.
 *
 * If no competition control is connected, this function will run immediately
 * following initialize().
 *
 * If the robot is disabled or communications is lost, the
 * operator control task will be stopped. Re-enabling the robot will restart the
 * task, not resume it from where it left off.
 */
void opcontrol() {

}
