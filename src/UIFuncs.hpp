#ifndef LOUUI_UIFUNCS_HPP
#define LOUUI_UIFUNCS_HPP

#include "../include/api.h"
#include "UIVars.hpp"

void setAutonDescription(){
    if(autonSelectMenu->getSelected() == "        ---      " ||
       !blueButton->isToggled() && !redButton->isToggled()){
        autonDescription->setText(noAutonDescription);
    }else if(autonSelectMenu->getSelected() == "Auton1"){
        autonDescription->setText(auton1Description);
    }else if(autonSelectMenu->getSelected() == "Auton2"){
        autonDescription->setText(auton2Description);
    }else{
        autonDescription->setText(progDescription);
    }
}

lv_res_t selectBlue(lv_obj_t *obj){
    redButton->setState(LouUI::ToggleButton::RELEASED);
    setAutonDescription();
    return LV_RES_OK;
}

lv_res_t selectRed(lv_obj_t *obj){
    blueButton->setState(LouUI::ToggleButton::RELEASED);
    setAutonDescription();
    return LV_RES_OK;
}

lv_res_t selectAuton(lv_obj_t *obj){
    setAutonDescription();
    return LV_RES_OK;
}

#endif //LOUUI_UIFUNCS_HPP
