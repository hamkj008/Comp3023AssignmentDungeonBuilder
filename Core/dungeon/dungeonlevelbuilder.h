#ifndef DUNGEONLEVELBUILDER_H
#define DUNGEONLEVELBUILDER_H

#include "dungeonlevel.h"
#include <string>


namespace core::dungeon {

class DungeonLevelBuilder
{
public:
    DungeonLevelBuilder();


    virtual void buildDungeonLevel(std::string name, int width, int height);
    virtual Room buildRoom(int &id);
//    virtual void buildDoorway(Room origin, Room destination, Direction direction, MoveConstraints constraints);
//    virtual void buildEntrance(Room room, Direction direction);
//    virtual void buildExit(Room room, Direction direction);
    virtual void buildItem(Room);
    virtual void buildCreature(Room);
    virtual DungeonLevel getDungeonLevel();

};
}

#endif // DUNGEONLEVELBUILDER_H
