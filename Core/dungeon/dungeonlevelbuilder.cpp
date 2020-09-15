#include "dungeonlevelbuilder.h"


namespace core::dungeon {

DungeonLevelBuilder::DungeonLevelBuilder()

{

}
void DungeonLevelBuilder::buildDungeonLevel(std::string name, int width, int height) {

}

// Room type chosen randomly
std::shared_ptr<Room> DungeonLevelBuilder::buildRoom(int &id) {

}

void DungeonLevelBuilder::buildDoorway(std::shared_ptr<Room> &origin,
    std::shared_ptr<Room> &destination, Room::Direction direction, MoveConstraints constraints) {

}

void DungeonLevelBuilder::buildEntrance(std::shared_ptr<Room> &room, Room::Direction direction) {

}
void DungeonLevelBuilder::buildExit(std::shared_ptr<Room> &room, Room::Direction direction) {

}


void DungeonLevelBuilder::buildItem(std::shared_ptr<Room> &room) {

}
void DungeonLevelBuilder::buildCreature(std::shared_ptr<Room> &room) {

}
DungeonLevel DungeonLevelBuilder::getDungeonLevel() {

}

}

