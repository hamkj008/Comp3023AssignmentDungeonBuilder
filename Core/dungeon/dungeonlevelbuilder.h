#ifndef DUNGEONLEVELBUILDER_H
#define DUNGEONLEVELBUILDER_H

#include <string>
#include "dungeonlevel.h"
//#include "Core/dungeon/doorway.h"


namespace core::dungeon {


class DungeonLevelBuilder
{
public:
    DungeonLevelBuilder();
    virtual ~DungeonLevelBuilder();

    enum class MoveConstraints : unsigned
    {
        None = 0,
        OriginImpassable = 1,
        DestinationImpassable = 2,
        OriginLocked = 4,
        DestinationLocked = 8
    };

    virtual void buildDungeonLevel(std::string name, int width, int height);

    virtual std::shared_ptr<Room> buildRoom(int id);

    virtual void buildDoorway(std::shared_ptr<Room> &origin, std::shared_ptr<Room> &destination, Room::Direction direction, MoveConstraints constraints);
    virtual void buildEntrance(std::shared_ptr<Room> &room, Room::Direction direction);
    virtual void buildExit(std::shared_ptr<Room> &room, Room::Direction direction);

    virtual void buildItem(std::shared_ptr<Room> &room);
    virtual void buildCreature(std::shared_ptr<Room> &room, bool isBoss);

    virtual DungeonLevel* getDungeonLevel();

protected:
    DungeonLevel *_dungeonLevel;

};

}

#endif // DUNGEONLEVELBUILDER_H
