#ifndef LOUUI_UIVARS_HPP
#define LOUUI_UIVARS_HPP

#include "LouUI/Display.hpp"
#include "LouUI/Label.hpp"
#include "LouUI/Button.hpp"
#include "LouUI/ToggleButton.hpp"
#include "LouUI/DropDownMenu.hpp"
#include "LouUI/Chart.hpp"

/**
 * UI objects
 */
extern LouUI::Display display;
extern LouUI::ToggleButton* leftButton;
extern LouUI::ToggleButton* rightButton;
extern LouUI::ToggleButton* progButton;
extern LouUI::ToggleButton* auton1Button;
extern LouUI::ToggleButton* auton2Button;
extern LouUI::ToggleButton* auton3Button;
extern LouUI::ToggleButton* auton4Button;
extern LouUI::Label* leftButtonLabel;
extern LouUI::Label* rightButtonLabel;
extern LouUI::Label* progButtonLabel;
extern LouUI::Label* auton1ButtonLabel;
extern LouUI::Label* auton2ButtonLabel;
extern LouUI::Label* auton3ButtonLabel;
extern LouUI::Label* auton4ButtonLabel;
extern LouUI::Label* autonDescription;

extern LouUI::Chart* chart;

#endif //LOUUI_UIVARS_HPP


