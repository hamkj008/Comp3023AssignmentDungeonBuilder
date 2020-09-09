#include "magicaldungeonlevelbuilder.h"


namespace core::dungeon::magical {


void MagicalDungeonLevelBuilder::buildDungeonLevel(std::string name, int width, int height) {

}

Room MagicalDungeonLevelBuilder::buildRoom(int &id) {

}

void MagicalDungeonLevelBuilder::buildDoorway(Room origin, Room destination, Room::Direction direction, MoveConstraints constraints) {

}

void MagicalDungeonLevelBuilder::buildEntrance(Room room, Room::Direction direction) {

}

void MagicalDungeonLevelBuilder::buildExit(Room room, Room::Direction direction) {

}

void MagicalDungeonLevelBuilder::buildItem(Room) {

}

void MagicalDungeonLevelBuilder::buildCreature(Room) {

}

DungeonLevel MagicalDungeonLevelBuilder::getDungeonLevel() {

}

}
