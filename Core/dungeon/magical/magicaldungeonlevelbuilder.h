#ifndef MAGICALDUNGEONLEVELBUILDER_H
#define MAGICALDUNGEONLEVELBUILDER_H

#include <string>
#include "Core/dungeon/dungeonlevelbuilder.h"


namespace core::dungeon::magical {


class MagicalDungeonLevelBuilder : public DungeonLevelBuilder
{
public:
    MagicalDungeonLevelBuilder();


    virtual void buildDungeonLevel(std::string name, int width, int height) override;
    virtual Room buildRoom(int &id) override;
//    virtual void buildDoorway(Room origin, Room destination, Direction direction, MoveConstraints constraints) override;
//    virtual void buildEntrance(Room room, Direction direction) override;
//    virtual void buildExit(Room room, Direction direction) override;
    virtual void buildItem(Room) override;
    virtual void buildCreature(Room) override;
    virtual DungeonLevel getDungeonLevel() override;


};
}
#endif // MAGICALDUNGEONLEVELBUILDER_H