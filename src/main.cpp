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
LouUI::ToggleButton* leftButton = nullptr;
LouUI::ToggleButton* rightButton = nullptr;
LouUI::ToggleButton* progButton = nullptr;
LouUI::ToggleButton* auton1Button = nullptr;
LouUI::ToggleButton* auton2Button = nullptr;
LouUI::ToggleButton* auton3Button = nullptr;
LouUI::ToggleButton* auton4Button = nullptr;
LouUI::Label* leftButtonLabel = nullptr;
LouUI::Label* rightButtonLabel = nullptr;
LouUI::Label* progButtonLabel = nullptr;
LouUI::Label* auton1ButtonLabel = nullptr;
LouUI::Label* auton2ButtonLabel = nullptr;
LouUI::Label* auton3ButtonLabel = nullptr;
LouUI::Label* auton4ButtonLabel = nullptr;
LouUI::Label* autonDescription = nullptr;

LouUI::Chart* chart = nullptr;

/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize() {

    display.addScreen("Auton Selector");
    display.addScreen("Chart");

    //create components
    leftButton = (new LouUI::ToggleButton(display.getScreen("Auton Selector")))
            ->setPosition(27, 0)
            ->setSize(120, 40)
            ->setMainColor(LouUI::Color(140,140,140), LouUI::ToggleButton::ALL_PRESSED)
            ->setGradientColor(LouUI::Color(140,140,140), LouUI::ToggleButton::ALL_PRESSED)
            ->setMainColor(LouUI::Color(125, 125, 125), LouUI::ToggleButton::ALL_RELEASED)
            ->setGradientColor(LouUI::Color(125, 125, 125), LouUI::ToggleButton::ALL_RELEASED)
            ->setBorderColor(LouUI::Color("WHITE"), LouUI::ToggleButton::ALL)
            ->setBorderOpacity(255, LouUI::ToggleButton::ALL)
            ->setBorderWidth(5, LouUI::ToggleButton::ALL_TOGGLED)
            ->setBorderWidth(0, LouUI::ToggleButton::ALL_UNTOGGLED);
    rightButton = (new LouUI::ToggleButton(display.getScreen("Auton Selector"), *leftButton))
            ->align(leftButton->getObj(), LouUI::OUT_RIGHT_MID, 20, 0);
    progButton = (new LouUI::ToggleButton(display.getScreen("Auton Selector")))
            ->setSize(120, 40)
            ->setMainColor(LouUI::Color(0,140,0), LouUI::ToggleButton::ALL_PRESSED)
            ->setGradientColor(LouUI::Color(0,140,0), LouUI::ToggleButton::ALL_PRESSED)
            ->setMainColor(LouUI::Color(0, 125, 0), LouUI::ToggleButton::ALL_RELEASED)
            ->setGradientColor(LouUI::Color(0, 125, 0), LouUI::ToggleButton::ALL_RELEASED)
            ->setBorderColor(LouUI::Color("WHITE"), LouUI::ToggleButton::ALL)
            ->setBorderOpacity(255, LouUI::ToggleButton::ALL)
            ->setBorderWidth(5, LouUI::ToggleButton::ALL_TOGGLED)
            ->setBorderWidth(0, LouUI::ToggleButton::ALL_UNTOGGLED)
            ->align(rightButton->getObj(), LouUI::OUT_RIGHT_MID, 20, 0);

    auton1Button = (new LouUI::ToggleButton(display.getScreen("Auton Selector"), *leftButton))
            ->setPosition(5, 60)
            ->setSize(100, 40);
    auton2Button = (new LouUI::ToggleButton(display.getScreen("Auton Selector"), *auton1Button))
            ->align(auton1Button->getObj(), LouUI::OUT_RIGHT_MID, 10, 0);
    auton3Button = (new LouUI::ToggleButton(display.getScreen("Auton Selector"), *auton1Button))
            ->align(auton2Button->getObj(), LouUI::OUT_RIGHT_MID, 10, 0);
    auton4Button = (new LouUI::ToggleButton(display.getScreen("Auton Selector"), *auton1Button))
            ->align(auton3Button->getObj(), LouUI::OUT_RIGHT_MID, 10, 0);

    leftButtonLabel = (new LouUI::Label(leftButton->getObj()))
            ->setText("LEFT");
    rightButtonLabel = (new LouUI::Label(rightButton->getObj()))
            ->setText("RIGHT");
    progButtonLabel = (new LouUI::Label(progButton->getObj()))
            ->setText("PROG");
    auton1ButtonLabel = (new LouUI::Label(auton1Button->getObj()))
            ->setText("1");
    auton2ButtonLabel = (new LouUI::Label(auton2Button->getObj()))
            ->setText("2");
    auton3ButtonLabel = (new LouUI::Label(auton3Button->getObj()))
            ->setText("3");
    auton4ButtonLabel = (new LouUI::Label(auton4Button->getObj()))
            ->setText("4");

    leftButton->setAction(selectLeft);
    rightButton->setAction(selectRight);
    progButton->setAction(selectProg);

    auton1Button->setAction(selectAuton1);
    auton2Button->setAction(selectAuton2);
    auton3Button->setAction(selectAuton3);
    auton4Button->setAction(selectAuton4);

    autonDescription = (new LouUI::Label(display.getScreen("Auton Selector")))
            ->setTextAlign(LouUI::Label::LEFT)
            ->setLongMode(LouUI::Label::BREAK)
            ->setWidth(440)
            ->align(display.getScreen("Auton Selector"), LouUI::CENTER, 0, 55)
            ->setText(Autonomous::noAutonDescription);

    chart = (new LouUI::Chart(display.getScreen("Chart")))
            ->setSize(400, 160)
            ->align(display.getScreen("Chart"), LouUI::Align::CENTER)
            ->setPointCount(300);
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

    int add = 3;
    int val = 0;

    while(true){
        pros::delay(10);
        val += add;
        if(val > 99) add = -3;
        if(val < 1) add = 3;
//        chart->addData(val);
    }

}
