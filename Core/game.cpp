#include <iostream>
#include <memory>

#include "game.h"
#include "Core/dungeon/dungeonlevelbuilder.h"
#include "Core/dungeon/basic/basicdungeonlevelbuilder.h"
#include "Core/dungeon/magical/magicaldungeonlevelbuilder.h"
#include "Core/dungeon/room.h"


namespace core {


Game::Game()
{
    std::cout << "game created" << std::endl;
}

Game::~Game() {
    std::cout << "game destroyed" << std::endl;
}


Game* Game::instance() {

    static Game *_theInstance = new Game();

    return _theInstance;
}



void Game::setDungeonType(char choice) {
    if(choice == 'b') {
        _DB = std::make_shared<core::dungeon::basic::BasicDungeonLevelBuilder>();
    }
    else if(choice == 'm') {
        _DB = std::make_shared<core::dungeon::magical::MagicalDungeonLevelBuilder>();
    }
}


void Game::createExampleLevel(){
    _DB = std::make_shared<core::dungeon::basic::BasicDungeonLevelBuilder>();

    _DB->buildDungeonLevel("Example Level", 3, 3);

    std::shared_ptr<core::dungeon::Room> room3 = _DB->getDungeonLevel()->retrieveRoom(3);
    _DB->buildCreature(room3, false);
    _DB->buildItem(room3);

    std::shared_ptr<core::dungeon::Room> room5 = _DB->getDungeonLevel()->retrieveRoom(5);
    _DB->buildCreature(room5, false);
    _DB->buildItem(room5);

    std::shared_ptr<core::dungeon::Room> room7 = _DB->getDungeonLevel()->retrieveRoom(7);
    _DB->buildItem(room7);

    std::shared_ptr<core::dungeon::Room> room9 = _DB->getDungeonLevel()->retrieveRoom(9);
    _DB->buildCreature(room9, true);

}

void Game::createRandomLevel(std::string &name, int &width, int &height) {
    _DB->buildDungeonLevel(name, width, height);

    int max = _DB->getDungeonLevel()->numberOfRooms();
    int min = 0;

    double creaturePopChance = Game::instance()->randomDouble();
    int creatureNum = creaturePopChance * ((max + 1) - min) + min;
    std::cout << "number of creatures " << creatureNum << std::endl;

    double itemPopChance = Game::instance()->randomDouble();
    int itemNum = itemPopChance * ((max + 1) - min) + min;
    std::cout << "number of items " << itemNum << std::endl;

    while(creatureNum != 0) {
        double creatureChance = Game::instance()->randomDouble();
        int randomRoom = creatureChance * ((max + 1) - min) + min;
        std::cout << "random range " << randomRoom << std::endl;

        std::shared_ptr<core::dungeon::Room> creatureRoom = _DB->getDungeonLevel()->retrieveRoom(randomRoom);
        if(creatureRoom->creature() != nullptr) {
            _DB->buildCreature(creatureRoom, false);
            creatureNum--;
        }
    }
    while(itemNum != 0) {
        double itemChance = Game::instance()->randomDouble();
        int randomRoom = itemChance * ((max + 1) - min) + min;
        std::cout << "random range " << randomRoom << std::endl;

        std::shared_ptr<core::dungeon::Room> itemRoom = _DB->getDungeonLevel()->retrieveRoom(randomRoom);
        if(itemRoom->item() != nullptr) {
            _DB->buildItem(itemRoom);
            itemNum--;
        }
    }
}

void Game::displayLevel(std::ostream &display) {
    std::vector<std::string> dungeonStrings = _DB->getDungeonLevel()->display();


    std::cout << "before dungeonDisplay" << std::endl;
    for(std::string s : dungeonStrings) {
        display << s << "\n";
    }
    std::cout << "after dungeonDisplay" << std::endl;
}

double Game::randomDouble() {
    return _realDistribution(_randomGenerator);
}

}
