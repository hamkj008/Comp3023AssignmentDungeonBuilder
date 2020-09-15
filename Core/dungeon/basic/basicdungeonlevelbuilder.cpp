#include "basicdungeonlevelbuilder.h"
#include "Core/dungeon/basic/rockchamber.h"
#include <iostream>

namespace core::dungeon::basic {

BasicDungeonLevelBuilder::BasicDungeonLevelBuilder()

{

}

void BasicDungeonLevelBuilder::buildDungeonLevel(std::string name, int width, int height) {
    if(width < 1) {
        width = 1;
    }
    else if(width > 4) {
        width = 4;
    }
    if(height < 1) {
        height = 1;
    }
    else if(height > 4) {
        height = 4;
    }

   _db = new DungeonLevel(name, width, height);

   int numberOfRooms = _db->numberOfRooms();
   int i{0};
   while(i < numberOfRooms) {
       std::shared_ptr<Room> room = buildRoom(i);
       _db->addRoom(room);
       std::cout << "after room" << std::endl;
//       std::shared_ptr<Room> room2 = buildRoom(i);
//       _db->addRoom(room2);
//       std::cout << "after room2" << std::endl;
       i++;
   }
   _db->display();
   std::cout << "after display" << std::endl;

}

std::shared_ptr<Room> BasicDungeonLevelBuilder::buildRoom(int &id) {
    std::shared_ptr<Room> room = std::make_shared<RockChamber>(id);
    room->display();

    return room;
}

void BasicDungeonLevelBuilder::buildDoorway(std::shared_ptr<Room> &origin, std::shared_ptr<Room> &destination, Room::Direction direction, MoveConstraints constraints) {

}

void BasicDungeonLevelBuilder::buildEntrance(std::shared_ptr<Room> &room, Room::Direction direction) {

}

void BasicDungeonLevelBuilder::buildExit(std::shared_ptr<Room> &room, Room::Direction direction) {

}

void BasicDungeonLevelBuilder::buildItem(std::shared_ptr<Room> &room) {
    room;
}

void BasicDungeonLevelBuilder::buildCreature(std::shared_ptr<Room> &room) {

}

DungeonLevel BasicDungeonLevelBuilder::getDungeonLevel() {
    return *_db;
}

}
