#include "basicdungeonlevelbuilder.h"


namespace core::dungeon::basic {

BasicDungeonLevelBuilder::BasicDungeonLevelBuilder()
    : _db{}
{

}

void BasicDungeonLevelBuilder::buildDungeonLevel(std::string name, int width, int height) {
   _db = std::make_shared<DungeonLevel>(name, width, height);

   int numberOfRooms = _db->numberOfRooms();
   int i{1};

   while(i < numberOfRooms) {
    Room room = buildRoom(i);
    _db->addRoom(room);
    i++;
   }



}

Room BasicDungeonLevelBuilder::buildRoom(int &id) {
     int roomID{1};
     std::shared_ptr<core::dungeon::Room> room = std::make_shared<core::dungeon::Room>(roomID);


     room->setItem();
     room->setCreature();

     return *room;
}

void BasicDungeonLevelBuilder::buildDoorway(Room origin, Room destination, Room::Direction direction, MoveConstraints constraints) {

}

void BasicDungeonLevelBuilder::buildEntrance(Room room, Room::Direction direction) {

}

void BasicDungeonLevelBuilder::buildExit(Room room, Room::Direction direction) {

}

void BasicDungeonLevelBuilder::buildItem(Room) {

}

void BasicDungeonLevelBuilder::buildCreature(Room) {

}

DungeonLevel BasicDungeonLevelBuilder::getDungeonLevel() {
    return _db;
}

}
