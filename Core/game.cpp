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
    : _dungeonBuilder{}
{
}

Game::~Game() {
    delete _dungeonBuilder;
}


Game* Game::instance() {

    static Game *_theInstance = new Game();

    return _theInstance;
}



void Game::setDungeonType(char choice) {
    if(_dungeonBuilder != nullptr) {
        delete _dungeonBuilder;
    }

    if(choice == 'b') {
        _dungeonBuilder = new core::dungeon::basic::BasicDungeonLevelBuilder();
    }
    else if(choice == 'm') {
        _dungeonBuilder = new core::dungeon::magical::MagicalDungeonLevelBuilder();
    }
}


void Game::createExampleLevel(){
    _dungeonBuilder->buildDungeonLevel("Example Dungeon Level", 3, 3);

    // Retrieve the rooms to add specific elements to them.
    std::shared_ptr<core::dungeon::Room> room1 = _dungeonBuilder->getDungeonLevel()->retrieveRoom(1);
    std::shared_ptr<core::dungeon::Room> room2 = _dungeonBuilder->getDungeonLevel()->retrieveRoom(2);
    std::shared_ptr<core::dungeon::Room> room3 = _dungeonBuilder->getDungeonLevel()->retrieveRoom(3);
    std::shared_ptr<core::dungeon::Room> room4 = _dungeonBuilder->getDungeonLevel()->retrieveRoom(4);
    std::shared_ptr<core::dungeon::Room> room5 = _dungeonBuilder->getDungeonLevel()->retrieveRoom(5);
    std::shared_ptr<core::dungeon::Room> room6 = _dungeonBuilder->getDungeonLevel()->retrieveRoom(6);
    std::shared_ptr<core::dungeon::Room> room7 = _dungeonBuilder->getDungeonLevel()->retrieveRoom(7);
    std::shared_ptr<core::dungeon::Room> room8 = _dungeonBuilder->getDungeonLevel()->retrieveRoom(8);
    std::shared_ptr<core::dungeon::Room> room9 = _dungeonBuilder->getDungeonLevel()->retrieveRoom(9);


    _dungeonBuilder->buildEntrance(room1, core::dungeon::Room::Direction::North);


    // Creating specific doorways and adding them to specific rooms to conform to example level design.
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

    // Connecting the passages
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


    // Add creatures and items
    _dungeonBuilder->buildCreature(room3, false);
    _dungeonBuilder->buildItem(room3);

    _dungeonBuilder->buildCreature(room5, false);
    _dungeonBuilder->buildItem(room5);

    _dungeonBuilder->buildItem(room7);

    _dungeonBuilder->buildCreature(room9, true);


    _dungeonBuilder->buildExit(room9, core::dungeon::Room::Direction::East);

}

void Game::createRandomLevel(std::string &name, int &width, int &height) {
    core::dungeon::Room::Direction direction{};

    // Build the dungeon level according to users wishes.
    _dungeonBuilder->buildDungeonLevel(name, width, height);

    // Find the maximum number of rooms
    int maxRooms = _dungeonBuilder->getDungeonLevel()->numberOfRooms();
    int roomNum = 1;

    // Cycle through the rooms to add doors and creatures.
    while(roomNum <= maxRooms) {
        std::shared_ptr<core::dungeon::Room> room = _dungeonBuilder->getDungeonLevel()->retrieveRoom(roomNum);
        std::shared_ptr<core::dungeon::Room> room2;

        // Getting ready for door placement
        std::shared_ptr<core::dungeon::Doorway> door1;
        std::shared_ptr<core::dungeon::Doorway> door2;

        // Build the entrance in the first room
        if(roomNum == 1) {
            double entranceEdgeChance = Game::instance()->randomDouble();
            if(entranceEdgeChance < 0.5) {
                direction = core::dungeon::Room::Direction::North;
            }
            else {
                direction = core::dungeon::Room::Direction::West;
            }
            _dungeonBuilder->buildEntrance(room, direction);
        }

        // Last room in the level has a boss creature and the exit.
        else if(roomNum == maxRooms) {
            double exitEdgeChance = Game::instance()->randomDouble();
            if(exitEdgeChance < 0.5) {
                direction = core::dungeon::Room::Direction::East;
            }
            else {
                direction = core::dungeon::Room::Direction::South;
            }
            _dungeonBuilder->buildExit(room, direction);
            _dungeonBuilder->buildCreature(room, true);
        }
        else {
            // Chance for creature to be placed in room
            double creatureChance = Game::instance()->randomDouble();
            if(creatureChance < 0.25) {
                if(room->creature() == nullptr) {
                    _dungeonBuilder->buildCreature(room, false);
                }
            }
            // Chance for item to be placed in room
            double itemChance = Game::instance()->randomDouble();
            if(itemChance < 0.35) {
                if(room->item() == nullptr) {
                    _dungeonBuilder->buildItem(room);
                }
            }
        }
        // Select the door type
        createDoor(door1);
        createDoor(door2);


        double doorPlacementChance = Game::instance()->randomDouble();

        // 50 % chance the door will be placed on the East side
        if(doorPlacementChance < 0.5) {
            direction = core::dungeon::Room::Direction::East;
            // If statement avoids adding doors to outside walls by going beyond the width.
            // Doorway has to be south as it cant be east.
            if((roomNum % width) == 0) {
                direction = core::dungeon::Room::Direction::South;
                // Check to not exceed bounds
                if((roomNum + width) <= maxRooms) {
                    // Build the doors for the first room
                    room->setEdge(direction, door1);
                    door1->connect(door2);

                    // Find the adjoining room and build door
                    room2 = _dungeonBuilder->getDungeonLevel()->retrieveRoom(roomNum + width);
                    room2->setEdge(door2->getDirection(), door2);
                }
            }
            else {
                // Check to not exceed bounds
                if((roomNum +1) <= maxRooms) {
                    // Build the doors for the first room
                    room->setEdge(direction, door1);
                    door1->connect(door2);

                    // Find the adjoining room and build door
                    room2 = _dungeonBuilder->getDungeonLevel()->retrieveRoom(roomNum + 1);
                    room2->setEdge(door2->getDirection(), door2);
                }
            }
        }
        // 50 % chance the door will be placed on the South side
        else {
            direction = core::dungeon::Room::Direction::South;
            // Check to not exceed bounds
            if((roomNum + width) <= maxRooms) {
                // Build the doors for the first room
                room->setEdge(direction, door1);
                door1->connect(door2);

                // Find the adjoining room and build door
                room2 = _dungeonBuilder->getDungeonLevel()->retrieveRoom(roomNum + width);
                room2->setEdge(door2->getDirection(), door2);
            }
        }
        roomNum ++;
    }
}


void Game::createDoor(std::shared_ptr<core::dungeon::Doorway> &door) {

    // Used to select the type of door that is created.
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
    // Retrieve the final display
    std::vector<std::string> dungeonStrings = _dungeonBuilder->getDungeonLevel()->display();

    // Load each display line into the display object
    for(std::string s : dungeonStrings) {
        display << s << "\n";
    }
}

double Game::randomDouble() {
    return _realDistribution(_randomGenerator);
}

core::dungeon::DungeonLevelBuilder* Game::getBuilder() {
    return _dungeonBuilder;
}

std::ostream& Game::operator <<(std::ostream &display) {
    return display << Game::instance()->_dungeonBuilder->getDungeonLevel()->description();
}

}
