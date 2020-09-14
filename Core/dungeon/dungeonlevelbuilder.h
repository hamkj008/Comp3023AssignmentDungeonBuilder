#ifndef DUNGEONLEVELBUILDER_H
#define DUNGEONLEVELBUILDER_H

#include "dungeonlevel.h"
#include <string>


namespace core::dungeon {


class DungeonLevelBuilder
{
public:
    DungeonLevelBuilder();


    enum class MoveConstraints : unsigned
    {
        None = 0,
        OriginImpassable = 1,
        DestinationImpassable = 2,
        OriginLocked = 4,
        DestinationLocked = 8
    };


    // this method must use bare pointer
    virtual void buildDungeonLevel(std::string name, int width, int height);

    // Room type chosen randomly
    virtual std::shared_ptr<Room> buildRoom(int &id);

    virtual void buildDoorway(Room* origin, Room* destination, Room::Direction direction, MoveConstraints constraints);

    virtual void buildEntrance(Room* room, Room::Direction direction);
    virtual void buildExit(Room* room, Room::Direction direction);


    virtual void buildItem(Room*);
    virtual void buildCreature(Room*);
    virtual DungeonLevel getDungeonLevel();

};

}

#endif // DUNGEONLEVELBUILDER_H
