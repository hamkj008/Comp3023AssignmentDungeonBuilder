#include "magicaldungeonlevelbuilder.h"


namespace core::dungeon::magical {


void MagicalDungeonLevelBuilder::buildDungeonLevel(std::string name, int width, int height) {

}

std::shared_ptr<Room> MagicalDungeonLevelBuilder::buildRoom(int &id) {

}

void MagicalDungeonLevelBuilder::buildDoorway(std::shared_ptr<Room> &origin,
     std::shared_ptr<Room> &destination, Room::Direction direction, MoveConstraints constraints) {

}

void MagicalDungeonLevelBuilder::buildEntrance(std::shared_ptr<Room> &room, Room::Direction direction) {

}

void MagicalDungeonLevelBuilder::buildExit(std::shared_ptr<Room> &room, Room::Direction direction) {

}

void MagicalDungeonLevelBuilder::buildItem(std::shared_ptr<Room> &room) {

}

void MagicalDungeonLevelBuilder::buildCreature(std::shared_ptr<Room> &room) {

}

DungeonLevel MagicalDungeonLevelBuilder::getDungeonLevel() {

}

}
