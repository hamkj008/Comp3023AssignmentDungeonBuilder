#include "dungeonlevelbuilder.h"


namespace core::dungeon {

DungeonLevelBuilder::DungeonLevelBuilder()
{
//    buildDungeonLevel();
}


void DungeonLevelBuilder::buildDungeonLevel(std::string name, int width, int height) {

}

Room DungeonLevelBuilder::buildRoom(int &id) {

}
void DungeonLevelBuilder::buildDoorway(Room origin, Room destination, Room::Direction direction, MoveConstraints constraints) {

}
void DungeonLevelBuilder::buildEntrance(Room room, Room::Direction direction) {

}
void DungeonLevelBuilder::buildExit(Room room, Room::Direction direction) {

}
void DungeonLevelBuilder::buildItem(Room) {

}
void DungeonLevelBuilder::buildCreature(Room) {

}
DungeonLevel DungeonLevelBuilder::getDungeonLevel() {

}

}
