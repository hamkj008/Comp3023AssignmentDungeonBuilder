#include <iostream>
#include "Core/dungeon/basic/quartzchamber.h"
#include "Core/menuinterface.h"

class MenuInterface;
class QuartzChamber;
//class RockChamber;
//class Room;
//class Weapon;
using namespace std;


int main()
{

    core::MenuInterface menu{std::cout, std::cin};
    menu.displayWelcome("Kieran Hambledon", "Dungeon Builder");

    menu.run();

//    core::dungeon::basic::QuartzChamber q{12};

//    std::cout << q.description() << std::endl;
    return 0;
}
