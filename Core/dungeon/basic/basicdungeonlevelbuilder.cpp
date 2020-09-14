#include "basicdungeonlevelbuilder.h"
#include "Core/dungeon/basic/rockchamber.h"
#include <iostream>

namespace core::dungeon::basic {

BasicDungeonLevelBuilder::BasicDungeonLevelBuilder()

{

}

void BasicDungeonLevelBuilder::buildDungeonLevel(std::string name, int width, int height) {
   _db = std::make_shared<DungeonLevel>(name, width, height);

   int numberOfRooms = _db->numberOfRooms();
   int i{1};
//   while(i < numberOfRooms) {
    std::shared_ptr<Room> room1 = buildRoom(i);
    _db->addRoom(room1);
    std::cout << "asfter room1" << std::endl;
    std::shared_ptr<Room> room2 = buildRoom(i);
    _db->addRoom(room2);
    std::cout << "asfter room2" << std::endl;
    _db->display();
    std::cout << "asfter" << std::endl;
//    i++;
//   }

}

std::shared_ptr<Room> BasicDungeonLevelBuilder::buildRoom(int &id) {
    std::shared_ptr<Room> room = std::make_shared<RockChamber>(id);
    room->display();

    return room;
}

void BasicDungeonLevelBuilder::buildDoorway(Room* origin, Room* destination, Room::Direction direction, MoveConstraints constraints) {

}

void BasicDungeonLevelBuilder::buildEntrance(Room* room, Room::Direction direction) {

}

void BasicDungeonLevelBuilder::buildExit(Room* room, Room::Direction direction) {

}

void BasicDungeonLevelBuilder::buildItem(Room*) {

}

void BasicDungeonLevelBuilder::buildCreature(Room*) {

}

DungeonLevel BasicDungeonLevelBuilder::getDungeonLevel() {
    return *_db;
}

}
