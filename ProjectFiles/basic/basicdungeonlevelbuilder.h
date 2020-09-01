#ifndef BASICDUNGEONLEVELBUILDER_H
#define BASICDUNGEONLEVELBUILDER_H

#include <string>
#include "dungeonlevelbuilder.h"


class BasicDungeonLevelBuilder : public DungeonLevelBuilder
{
public:
    BasicDungeonLevelBuilder();


    void buildDungeonLevel(std::string name, int width, int height) override;
    Room buildRoom(int id) override;
    void buildDoorway(Room origin, Room destination, Direction direction, MoveConstraints constraints) override;
    void buildEntrance(Room room, Direction direction) override;
    void buildExit(Room room, Direction direction) override;
    void buildItem(Room) override;
    void buildCreature(Room) override;
    DungeonLevel getDungeonLevel() override;

};

#endif // BASICDUNGEONLEVELBUILDER_H
