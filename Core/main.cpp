#include <iostream>
#include <memory>

#include "Core/game.h"
#include "Core/menuinterface.h"
#include "Core/dungeon/basic/quartzchamber.h"
#include "Core/creatures/abstractcreature.h"
#include "Core/creatures/monster.h"
#include "Core/items/weapon.h"

//class QuartzChamber;
//class RockChamber;
//class Room;
//class Weapon;
class AbstractCreature;
class Monster;

using namespace std;


int main()
{

    core::MenuInterface menu{std::cout, std::cin};
    menu.displayWelcome("Kieran Hambledon", "Dungeon Builder");

    menu.run();

    core::creatures::Monster m{"bob"};
    m.name();
    m.displayCharacter();

    core::dungeon::basic::QuartzChamber q{};

    core::items::Weapon w = new Weapon("Sword");
    delete w;
    std::unique_ptr<Game> game = std::make_unique<Game>();
    std::cout << q.description() << std::endl;


    return 0;
}
