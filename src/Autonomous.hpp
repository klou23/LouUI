#ifndef LOUUI_AUTONOMOUS_HPP
#define LOUUI_AUTONOMOUS_HPP

#include <string>

/**Autonomous Enums**/
enum AutonColor{
    NONE,
    RED,
    BLUE
};

/**Autonomous Variables**/
extern AutonColor autonColor;
extern int autonNumber;

/**Autonomous Descriptions**/
extern std::string noAutonDescription;
extern std::string auton1Description;
extern std::string auton2Description;
extern std::string progDescription;

#endif //LOUUI_AUTONOMOUS_HPP
