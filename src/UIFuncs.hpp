#ifndef LOUUI_UIFUNCS_HPP
#define LOUUI_UIFUNCS_HPP

#include "../include/api.h"
#include "UIVars.hpp"

void setAuton(){
    if(progButton->isToggled()){
        auton1Button->setState(LouUI::ToggleButton::RELEASED);
        auton2Button->setState(LouUI::ToggleButton::RELEASED);
        auton3Button->setState(LouUI::ToggleButton::RELEASED);
        auton4Button->setState(LouUI::ToggleButton::RELEASED);
        Autonomous::autonSide = Autonomous::PROG;
        Autonomous::autonNumber = 0;
        autonDescription->setText(Autonomous::progDescription);
        return;
    }

    if(leftButton->isToggled()) Autonomous::autonSide = Autonomous::LEFT;
    else if(rightButton->isToggled()) Autonomous::autonSide = Autonomous::RIGHT;
    else Autonomous::autonSide = Autonomous::NONE;

    if(auton1Button->isToggled()) Autonomous::autonNumber = 1;
    else if(auton2Button->isToggled()) Autonomous::autonNumber = 2;
    else if(auton3Button->isToggled()) Autonomous::autonNumber = 3;
    else if(auton4Button->isToggled()) Autonomous::autonNumber = 4;
    else Autonomous::autonNumber = 0;

    if(Autonomous::autonSide == Autonomous::NONE){
        autonDescription->setText(Autonomous::noAutonDescription);
    }else if(Autonomous::autonSide == Autonomous::LEFT){
        switch (Autonomous::autonNumber) {
            case 1:
                autonDescription->setText(Autonomous::left1Description);
                break;
            case 2:
                autonDescription->setText(Autonomous::left2Description);
                break;
            case 3:
                autonDescription->setText(Autonomous::left3Description);
                break;
            case 4:
                autonDescription->setText(Autonomous::left4Description);
                break;
            default:
                autonDescription->setText(Autonomous::noAutonDescription);
        }
    }else if(Autonomous::autonSide == Autonomous::RIGHT){
        switch (Autonomous::autonNumber) {
            case 1:
                autonDescription->setText(Autonomous::right1Description);
                break;
            case 2:
                autonDescription->setText(Autonomous::right2Description);
                break;
            case 3:
                autonDescription->setText(Autonomous::right3Description);
                break;
            case 4:
                autonDescription->setText(Autonomous::right4Description);
                break;
            default:
                autonDescription->setText(Autonomous::noAutonDescription);
        }
    }
}

lv_res_t selectLeft(lv_obj_t *obj){
    rightButton->setState(LouUI::ToggleButton::RELEASED);
    progButton->setState(LouUI::ToggleButton::RELEASED);
    setAuton();
    return LV_RES_OK;
}

lv_res_t selectRight(lv_obj_t *obj){
    leftButton->setState(LouUI::ToggleButton::RELEASED);
    progButton->setState(LouUI::ToggleButton::RELEASED);
    setAuton();
    return LV_RES_OK;
}

lv_res_t selectProg(lv_obj_t *obj){
    leftButton->setState(LouUI::ToggleButton::RELEASED);
    rightButton->setState(LouUI::ToggleButton::RELEASED);
    setAuton();
    return LV_RES_OK;
}

lv_res_t selectAuton1(lv_obj_t *obj){
    auton2Button->setState(LouUI::ToggleButton::RELEASED);
    auton3Button->setState(LouUI::ToggleButton::RELEASED);
    auton4Button->setState(LouUI::ToggleButton::RELEASED);
    setAuton();
    return LV_RES_OK;
}

lv_res_t selectAuton2(lv_obj_t *obj){
    auton1Button->setState(LouUI::ToggleButton::RELEASED);
    auton3Button->setState(LouUI::ToggleButton::RELEASED);
    auton4Button->setState(LouUI::ToggleButton::RELEASED);
    setAuton();
    return LV_RES_OK;
}

lv_res_t selectAuton3(lv_obj_t *obj){
    auton1Button->setState(LouUI::ToggleButton::RELEASED);
    auton2Button->setState(LouUI::ToggleButton::RELEASED);
    auton4Button->setState(LouUI::ToggleButton::RELEASED);
    setAuton();
    return LV_RES_OK;
}

lv_res_t selectAuton4(lv_obj_t *obj){
    auton1Button->setState(LouUI::ToggleButton::RELEASED);
    auton2Button->setState(LouUI::ToggleButton::RELEASED);
    auton3Button->setState(LouUI::ToggleButton::RELEASED);
    setAuton();
    return LV_RES_OK;
}


#endif //LOUUI_UIFUNCS_HPP
