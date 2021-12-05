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
#include "LouUI/Button.hpp"
#include "Autonomous.hpp"
#include "UIFuncs.hpp"

LouUI::Display display;
LouUI::ToggleButton* redButton = nullptr;
LouUI::ToggleButton* blueButton = nullptr;
LouUI::Label* redButtonLabel = nullptr;
LouUI::Label* blueButtonLabel = nullptr;
LouUI::DropDownMenu* autonSelectMenu = nullptr;
LouUI::Label* autonDescription = nullptr;

/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize() {

    display.addScreen("Auton Selector");

    redButton = (new LouUI::ToggleButton(display.getScreen("Auton Selector")))
            ->setPosition(10, 0)
            ->setSize(100, 50)
            ->setMainColor(LouUI::Color("RED"), LouUI::ToggleButton::ALL)
            ->setGradientColor(LouUI::Color("RED"), LouUI::ToggleButton::ALL)
            ->setBorderColor(LouUI::Color("WHITE"), LouUI::ToggleButton::ALL)
            ->setBorderOpacity(255, LouUI::ToggleButton::ALL)
            ->setBorderWidth(0, LouUI::ToggleButton::ALL_UNTOGGLED)
            ->setBorderWidth(5, LouUI::ToggleButton::ALL_TOGGLED)
            ->setAction(selectRed);
    redButtonLabel = (new LouUI::Label(redButton->getObj()))
            ->setText("RED")
            ->setFont(30);

    blueButton = (new LouUI::ToggleButton(display.getScreen("Auton Selector")))
            ->setSize(100, 50)
            ->align(redButton->getObj(), LouUI::OUT_RIGHT_MID, 15, 0)
            ->setMainColor(LouUI::Color("BLUE"), LouUI::ToggleButton::ALL)
            ->setGradientColor(LouUI::Color("BLUE"), LouUI::ToggleButton::ALL)
            ->setBorderColor(LouUI::Color("WHITE"), LouUI::ToggleButton::ALL)
            ->setBorderOpacity(255, LouUI::ToggleButton::ALL)
            ->setBorderWidth(0, LouUI::ToggleButton::ALL_UNTOGGLED)
            ->setBorderWidth(5, LouUI::ToggleButton::ALL_TOGGLED)
            ->setAction(selectBlue);
    blueButtonLabel = (new LouUI::Label(blueButton->getObj()))
            ->setText("BLUE");

    autonDescription = (new LouUI::Label(display.getScreen("Auton Selector")))
            ->setTextAlign(LouUI::Label::LEFT)
            ->setLongMode(LouUI::Label::BREAK)
            ->setWidth(440)
            ->align(display.getScreen("Auton Selector"), LouUI::CENTER, 0, 20)
            ->setText(noAutonDescription);

    autonSelectMenu = (new LouUI::DropDownMenu(display.getScreen("Auton Selector")))
            ->setOptions(std::vector<std::string>({
                                                          "        ---      ",
                                                          "Auton1",
                                                          "Auton2",
                                                          "Prog"
                                                  }))
            ->align(blueButton->getObj(), LouUI::OUT_RIGHT_MID, 15, 0)
            ->setAction(selectAuton);
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
