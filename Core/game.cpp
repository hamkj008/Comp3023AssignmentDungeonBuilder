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


    std::shared_ptr<core::dungeon::RoomEdge> room1door1 = std::make_shared<core::dungeon::common::OpenDoorway>();
    room1->setEdge(core::dungeon::Room::Direction::East, room1door1);
    std::shared_ptr<core::dungeon::RoomEdge> room1door2 = std::make_shared<core::dungeon::common::OpenDoorway>();
    room1->setEdge(core::dungeon::Room::Direction::South, room1door2);

    std::shared_ptr<core::dungeon::RoomEdge> room2door1 = std::make_shared<core::dungeon::common::OpenDoorway>();
    room2->setEdge(core::dungeon::Room::Direction::West, room2door1);
    std::shared_ptr<core::dungeon::RoomEdge> room2door2 = std::make_shared<core::dungeon::common::OpenDoorway>();
    room2->setEdge(core::dungeon::Room::Direction::South, room2door2);
    std::shared_ptr<core::dungeon::RoomEdge> room2door3 = std::make_shared<core::dungeon::common::BlockedDoorway>();
    room2->setEdge(core::dungeon::Room::Direction::East, room2door3);

    std::shared_ptr<core::dungeon::RoomEdge> room3door1 = std::make_shared<core::dungeon::common::BlockedDoorway>();
    room3->setEdge(core::dungeon::Room::Direction::West, room3door1);
    std::shared_ptr<core::dungeon::RoomEdge> room3door2 = std::make_shared<core::dungeon::common::OpenDoorway>();
    room3->setEdge(core::dungeon::Room::Direction::South, room3door2);

    std::shared_ptr<core::dungeon::RoomEdge> room4door1 = std::make_shared<core::dungeon::common::OneWayDoor>(false, false);
    room4->setEdge(core::dungeon::Room::Direction::North, room4door1);
    std::shared_ptr<core::dungeon::RoomEdge> room4door2 = std::make_shared<core::dungeon::common::OpenDoorway>();
    room4->setEdge(core::dungeon::Room::Direction::East, room4door2);
    std::shared_ptr<core::dungeon::RoomEdge> room4door3 = std::make_shared<core::dungeon::common::BlockedDoorway>();
    room4->setEdge(core::dungeon::Room::Direction::South, room4door3);

    std::shared_ptr<core::dungeon::RoomEdge> room5door1 = std::make_shared<core::dungeon::common::OpenDoorway>();
    room5->setEdge(core::dungeon::Room::Direction::North, room5door1);
    std::shared_ptr<core::dungeon::RoomEdge> room5door2 = std::make_shared<core::dungeon::common::OpenDoorway>();
    room5->setEdge(core::dungeon::Room::Direction::East, room5door2);
    std::shared_ptr<core::dungeon::RoomEdge> room5door3 = std::make_shared<core::dungeon::common::OpenDoorway>();
    room5->setEdge(core::dungeon::Room::Direction::South, room5door3);
    std::shared_ptr<core::dungeon::RoomEdge> room5door4 = std::make_shared<core::dungeon::common::OneWayDoor>(false, false);
    room5->setEdge(core::dungeon::Room::Direction::West, room5door4);

    std::shared_ptr<core::dungeon::RoomEdge> room6door1 = std::make_shared<core::dungeon::common::LockedDoor>();
    room6->setEdge(core::dungeon::Room::Direction::North, room6door1);
    std::shared_ptr<core::dungeon::RoomEdge> room6door2 = std::make_shared<core::dungeon::common::OpenDoorway>();
    room6->setEdge(core::dungeon::Room::Direction::West, room6door2);

    std::shared_ptr<core::dungeon::RoomEdge> room7door1 = std::make_shared<core::dungeon::common::LockedDoor>();
    room7->setEdge(core::dungeon::Room::Direction::East, room7door1);
    std::shared_ptr<core::dungeon::RoomEdge> room7door2 = std::make_shared<core::dungeon::common::BlockedDoorway>();
    room7->setEdge(core::dungeon::Room::Direction::North, room7door2);

    std::shared_ptr<core::dungeon::RoomEdge> room8door1 = std::make_shared<core::dungeon::common::OpenDoorway>();
    room8->setEdge(core::dungeon::Room::Direction::North, room8door1);
    std::shared_ptr<core::dungeon::RoomEdge> room8door2 = std::make_shared<core::dungeon::common::LockedDoor>();
    room8->setEdge(core::dungeon::Room::Direction::West, room8door2);
    std::shared_ptr<core::dungeon::RoomEdge> room8door3 = std::make_shared<core::dungeon::common::OpenDoorway>();
    room8->setEdge(core::dungeon::Room::Direction::East, room8door3);

    std::shared_ptr<core::dungeon::RoomEdge> room9door1 = std::make_shared<core::dungeon::common::OpenDoorway>();
    room9->setEdge(core::dungeon::Room::Direction::West, room9door1);


//    _DB->buildDoorway(room1, room2, core::dungeon::Room::Direction::East, core::dungeon::DungeonLevelBuilder::MoveConstraints::OriginImpassable);
//    _DB->buildDoorway(room1, room4, core::dungeon::Room::Direction::South, core::dungeon::DungeonLevelBuilder::MoveConstraints::OriginImpassable);

//    _DB->buildDoorway(room2, room3, core::dungeon::Room::Direction::East, core::dungeon::DungeonLevelBuilder::MoveConstraints::OriginImpassable);
//    _DB->buildDoorway(room2, room5, core::dungeon::Room::Direction::South, core::dungeon::DungeonLevelBuilder::MoveConstraints::OriginImpassable);

//    _DB->buildDoorway(room3, room6, core::dungeon::Room::Direction::South, core::dungeon::DungeonLevelBuilder::MoveConstraints::OriginImpassable);

//    _DB->buildDoorway(room4, room5, core::dungeon::Room::Direction::East, core::dungeon::DungeonLevelBuilder::MoveConstraints::OriginImpassable);
//    _DB->buildDoorway(room4, room7, core::dungeon::Room::Direction::South, core::dungeon::DungeonLevelBuilder::MoveConstraints::OriginImpassable);

//    _DB->buildDoorway(room5, room8, core::dungeon::Room::Direction::South, core::dungeon::DungeonLevelBuilder::MoveConstraints::OriginImpassable);
//    _DB->buildDoorway(room5, room6, core::dungeon::Room::Direction::East, core::dungeon::DungeonLevelBuilder::MoveConstraints::OriginImpassable);

//    _DB->buildDoorway(room7, room8, core::dungeon::Room::Direction::East, core::dungeon::DungeonLevelBuilder::MoveConstraints::OriginImpassable);

//    _DB->buildDoorway(room8, room9, core::dungeon::Room::Direction::East, core::dungeon::DungeonLevelBuilder::MoveConstraints::OriginImpassable);


    _DB->buildCreature(room3, false);
    _DB->buildItem(room3);

    _DB->buildCreature(room5, false);
    _DB->buildItem(room5);

    _DB->buildItem(room7);

    _DB->buildCreature(room9, true);
    _DB->buildExit(room9, core::dungeon::Room::Direction::East);

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

std::shared_ptr<core::dungeon::DungeonLevelBuilder> Game::getDungeon() {
    return _DB;
}

std::ostream& Game::operator <<(std::ostream &display) {
    return display << Game::instance()->_DB->getDungeonLevel()->description();
}

}
