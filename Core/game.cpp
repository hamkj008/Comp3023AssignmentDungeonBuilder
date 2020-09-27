#include <iostream>
#include <memory>

#include "game.h"
#include "Core/dungeon/dungeonlevelbuilder.h"
#include "Core/dungeon/basic/basicdungeonlevelbuilder.h"
#include "Core/dungeon/magical/magicaldungeonlevelbuilder.h"
#include "Core/dungeon/room.h"
#include "Core/dungeon/doorway.h"
#include "Core/dungeon/common/opendoorway.h"
#include "Core/dungeon/common/blockeddoorway.h"
#include "Core/dungeon/common/lockeddoor.h"
#include "Core/dungeon/roomedge.h"
#include "Core/dungeon/common/onewaydoor.h"


namespace core {


Game::Game()
    : _DB{}
{
    std::cout << "game created" << std::endl;
}

Game::~Game() {
    std::cout << "game destroyed" << std::endl;
    delete _DB;
}


Game* Game::instance() {

    static Game *_theInstance = new Game();

    return _theInstance;
}



void Game::setDungeonType(char choice) {
    if(_DB != nullptr) {
        delete _DB;
    }

    if(choice == 'b') {
        _DB = new core::dungeon::basic::BasicDungeonLevelBuilder();
    }
    else if(choice == 'm') {
        _DB = new core::dungeon::magical::MagicalDungeonLevelBuilder();
    }
}


void Game::createExampleLevel(){
    _DB->buildDungeonLevel("Example Dungeon Level", 3, 3);

    std::shared_ptr<core::dungeon::Room> room1 = _DB->getDungeonLevel()->retrieveRoom(1);
    std::shared_ptr<core::dungeon::Room> room2 = _DB->getDungeonLevel()->retrieveRoom(2);
    std::shared_ptr<core::dungeon::Room> room3 = _DB->getDungeonLevel()->retrieveRoom(3);
    std::shared_ptr<core::dungeon::Room> room4 = _DB->getDungeonLevel()->retrieveRoom(4);
    std::shared_ptr<core::dungeon::Room> room5 = _DB->getDungeonLevel()->retrieveRoom(5);
    std::shared_ptr<core::dungeon::Room> room6 = _DB->getDungeonLevel()->retrieveRoom(6);
    std::shared_ptr<core::dungeon::Room> room7 = _DB->getDungeonLevel()->retrieveRoom(7);
    std::shared_ptr<core::dungeon::Room> room8 = _DB->getDungeonLevel()->retrieveRoom(8);
    std::shared_ptr<core::dungeon::Room> room9 = _DB->getDungeonLevel()->retrieveRoom(9);

    _DB->buildEntrance(room1, core::dungeon::Room::Direction::North);


    std::shared_ptr<core::dungeon::Doorway> rm1EastDoor = std::make_shared<core::dungeon::common::OpenDoorway>();
    std::shared_ptr<core::dungeon::Doorway> rm1SouthDoor = std::make_shared<core::dungeon::common::OpenDoorway>();
    room1->setEdge(core::dungeon::Room::Direction::East, rm1EastDoor);
    room1->setEdge(core::dungeon::Room::Direction::South, rm1SouthDoor);

    std::shared_ptr<core::dungeon::Doorway> rm2WestDoor = std::make_shared<core::dungeon::common::OpenDoorway>();
    std::shared_ptr<core::dungeon::Doorway> rm2SouthDoor = std::make_shared<core::dungeon::common::OpenDoorway>();
    std::shared_ptr<core::dungeon::Doorway> rm2EastDoor = std::make_shared<core::dungeon::common::BlockedDoorway>();
    room2->setEdge(core::dungeon::Room::Direction::West, rm2WestDoor);
    room2->setEdge(core::dungeon::Room::Direction::South, rm2SouthDoor);
    room2->setEdge(core::dungeon::Room::Direction::East, rm2EastDoor);

    std::shared_ptr<core::dungeon::Doorway> rm3WestDoor = std::make_shared<core::dungeon::common::BlockedDoorway>();
    std::shared_ptr<core::dungeon::Doorway> rm3SouthDoor = std::make_shared<core::dungeon::common::OpenDoorway>();
    room3->setEdge(core::dungeon::Room::Direction::West, rm3WestDoor);
    room3->setEdge(core::dungeon::Room::Direction::South, rm3SouthDoor);

    std::shared_ptr<core::dungeon::Doorway> rm4NorthDoor = std::make_shared<core::dungeon::common::OneWayDoor>(false, false);
    std::shared_ptr<core::dungeon::Doorway> rm4EastDoor = std::make_shared<core::dungeon::common::OpenDoorway>();
    std::shared_ptr<core::dungeon::Doorway> rm4SouthDoor = std::make_shared<core::dungeon::common::BlockedDoorway>();
    room4->setEdge(core::dungeon::Room::Direction::North, rm4NorthDoor);
    room4->setEdge(core::dungeon::Room::Direction::East, rm4EastDoor);
    room4->setEdge(core::dungeon::Room::Direction::South, rm4SouthDoor);

    std::shared_ptr<core::dungeon::Doorway> rm5NorthDoor = std::make_shared<core::dungeon::common::OpenDoorway>();
    std::shared_ptr<core::dungeon::Doorway> rm5WestDoor = std::make_shared<core::dungeon::common::OneWayDoor>(false, false);
    std::shared_ptr<core::dungeon::Doorway> rm5SouthDoor = std::make_shared<core::dungeon::common::OpenDoorway>();
    std::shared_ptr<core::dungeon::Doorway> rm5EastDoor = std::make_shared<core::dungeon::common::OpenDoorway>();
    room5->setEdge(core::dungeon::Room::Direction::North, rm5NorthDoor);
    room5->setEdge(core::dungeon::Room::Direction::West, rm5WestDoor);
    room5->setEdge(core::dungeon::Room::Direction::South, rm5SouthDoor);
    room5->setEdge(core::dungeon::Room::Direction::East, rm5EastDoor);

    std::shared_ptr<core::dungeon::Doorway> rm6NorthDoor = std::make_shared<core::dungeon::common::LockedDoor>();
    std::shared_ptr<core::dungeon::Doorway> rm6WestDoor = std::make_shared<core::dungeon::common::OpenDoorway>();
    room6->setEdge(core::dungeon::Room::Direction::North, rm6NorthDoor);
    room6->setEdge(core::dungeon::Room::Direction::West, rm6WestDoor);

    std::shared_ptr<core::dungeon::Doorway> rm7NorthDoor = std::make_shared<core::dungeon::common::BlockedDoorway>();
    std::shared_ptr<core::dungeon::Doorway> rm7EastDoor = std::make_shared<core::dungeon::common::LockedDoor>();
    room7->setEdge(core::dungeon::Room::Direction::North, rm7NorthDoor);
    room7->setEdge(core::dungeon::Room::Direction::East, rm7EastDoor);

    std::shared_ptr<core::dungeon::Doorway> rm8WestDoor = std::make_shared<core::dungeon::common::LockedDoor>();
    std::shared_ptr<core::dungeon::Doorway> rm8NorthDoor = std::make_shared<core::dungeon::common::OpenDoorway>();
    std::shared_ptr<core::dungeon::Doorway> rm8EastDoor = std::make_shared<core::dungeon::common::OpenDoorway>();
    room8->setEdge(core::dungeon::Room::Direction::West, rm8WestDoor);
    room8->setEdge(core::dungeon::Room::Direction::North, rm8NorthDoor);
    room8->setEdge(core::dungeon::Room::Direction::East, rm8EastDoor);

    std::shared_ptr<core::dungeon::Doorway> rm9WestDoor = std::make_shared<core::dungeon::common::OpenDoorway>();
    room9->setEdge(core::dungeon::Room::Direction::West, rm9WestDoor);


    rm1EastDoor->connect(rm2WestDoor);
    rm1SouthDoor->connect(rm4NorthDoor);

    rm2SouthDoor->connect(rm5NorthDoor);
    rm2EastDoor->connect(rm3WestDoor);

    rm3SouthDoor->connect(rm6NorthDoor);

    rm4SouthDoor->connect(rm7NorthDoor);
    rm4EastDoor->connect(rm5WestDoor);

    rm5SouthDoor->connect(rm8NorthDoor);
    rm5EastDoor->connect(rm6WestDoor);

    rm7EastDoor->connect(rm8WestDoor);

    rm8EastDoor->connect(rm9WestDoor);


    _DB->buildCreature(room3, false);
    _DB->buildItem(room3);

    _DB->buildCreature(room5, false);
    _DB->buildItem(room5);

    _DB->buildItem(room7);

    _DB->buildCreature(room9, true);
    _DB->buildExit(room9, core::dungeon::Room::Direction::East);

}

void Game::createRandomLevel(std::string &name, int &width, int &height) {
    core::dungeon::Room::Direction direction{};
    _DB->buildDungeonLevel(name, width, height);

    int max = _DB->getDungeonLevel()->numberOfRooms();
    int roomNum = 1;

    while(roomNum <= max) {
        std::shared_ptr<core::dungeon::Room> room = _DB->getDungeonLevel()->retrieveRoom(roomNum);

        std::shared_ptr<core::dungeon::Room> room2;

        std::shared_ptr<core::dungeon::Doorway> door1;
        std::shared_ptr<core::dungeon::Doorway> door2;

        // Build the entrance
        if(roomNum == 1) {
            double directionChance = Game::instance()->randomDouble();
            if(directionChance < 0.5) {
                direction = core::dungeon::Room::Direction::North;
            }
            else {
                direction = core::dungeon::Room::Direction::West;
            }
            _DB->buildEntrance(room, direction);
        }

        // Last room in the level has a boss creature and the exit.
        else if(roomNum == max) {
            double directionChance = Game::instance()->randomDouble();
            if(directionChance < 0.5) {
                direction = core::dungeon::Room::Direction::East;
            }
            else {
                direction = core::dungeon::Room::Direction::South;
            }
            _DB->buildExit(room, direction);
            _DB->buildCreature(room, true);
        }
        else {
            // Chance for creature to be placed in room
            double creatureChance = Game::instance()->randomDouble();
            if(creatureChance < 0.4) {
                if(room->creature() == nullptr) {
                    _DB->buildCreature(room, false);
                }
            }
            // Chance for item to be placed in room
            double itemChance = Game::instance()->randomDouble();
            if(itemChance < 0.4) {
                if(room->item() == nullptr) {
                    _DB->buildItem(room);
                }
            }

            createDoor(door1);
            createDoor(door2);

            double doorPlacementChance = Game::instance()->randomDouble();

            if(doorPlacementChance < 0.5) {
                direction = core::dungeon::Room::Direction::East;
                if((roomNum % width) == 0) {

                }
                else {
                    room->setEdge(direction, door1);
                    door1->connect(door2);

                    room2 = _DB->getDungeonLevel()->retrieveRoom(roomNum + 1);
                    room2->setEdge(door2->getDirection(), door2);
                }
            }
            else {
                direction = core::dungeon::Room::Direction::South;
                if((roomNum + width) <= max) {
                    room->setEdge(direction, door1);
                    door1->connect(door2);

                    room2 = _DB->getDungeonLevel()->retrieveRoom(roomNum + width);
                    room2->setEdge(door2->getDirection(), door2);
                }
            }
        }
        roomNum ++;
    }

}

void Game::createDoor(std::shared_ptr<core::dungeon::Doorway> &door) {

    double doorTypeChance = Game::instance()->randomDouble();

    if(doorTypeChance > 0.0 and doorTypeChance < 0.4) {
        door = std::make_shared<core::dungeon::common::OpenDoorway>();
    }
    else if(doorTypeChance > 0.4 and doorTypeChance < 0.6) {
        door = std::make_shared<core::dungeon::common::LockedDoor>();
    }
    else if(doorTypeChance > 0.6 and doorTypeChance < 0.8) {
        door = std::make_shared<core::dungeon::common::BlockedDoorway>();
    }
    else if(doorTypeChance > 0.8 and doorTypeChance < 1.0) {
        door = std::make_shared<core::dungeon::common::OneWayDoor>(false, false);
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

core::dungeon::DungeonLevelBuilder* Game::getBuilder() {
    return _DB;
}

std::ostream& Game::operator <<(std::ostream &display) {
    return display << Game::instance()->_DB->getDungeonLevel()->description();
}

}
