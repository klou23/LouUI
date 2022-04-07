#ifndef LOUUI_AUTONOMOUS_HPP
#define LOUUI_AUTONOMOUS_HPP

#include <string>

namespace Autonomous{
    enum AutonSide{
        LEFT,
        RIGHT,
        PROG,
        NONE
    };

    extern AutonSide autonSide;
    extern int autonNumber;

    extern std::string noAutonDescription;

    extern std::string progDescription;

    extern std::string left1Description;
    extern std::string left2Description;
    extern std::string left3Description;
    extern std::string left4Description;

    extern std::string right1Description;
    extern std::string right2Description;
    extern std::string right3Description;
    extern std::string right4Description;

}

#endif //LOUUI_AUTONOMOUS_HPP
