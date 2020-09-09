#include <iostream>
#include <memory>
#include <array>

#include "Core/game.h"
#include "Core/menuinterface.h"
#include "Core/dungeon/basic/quartzchamber.h"
#include "Core/creatures/abstractcreature.h"
#include "Core/creatures/monster.h"
#include "Core/items/weapon.h"
#include "Core/dungeon/dungeonlevel.h"

int main()
{
    core::MenuInterface menu{std::cout, std::cin};
    menu.displayWelcome("Kieran Hambledon", "Dungeon Builder");

    menu.run();






    core::creatures::Monster m{"bob"};
    m.name();
    m.displayCharacter();

    // Polymorph base container for derived object
    core::creatures::AbstractCreature *creature = &m;

    creature->displayCharacter();
    core::dungeon::basic::QuartzChamber *q{};

    core::items::Weapon *w = new core::items::Weapon("Sword");
    delete w;

    core::Game game = core::Game::instance();

    core::dungeon::DungeonLevel* dl = new core::dungeon::DungeonLevel("basic", 3, 3);

    return 0;
}
