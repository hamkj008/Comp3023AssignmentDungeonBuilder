#ifndef BASICDUNGEONLEVELBUILDER_H
#define BASICDUNGEONLEVELBUILDER_H

#include "Core/dungeon/dungeonlevelbuilder.h"
#include <string>


namespace core::dungeon::basic {

class BasicDungeonLevelBuilder : public DungeonLevelBuilder
{
public:
    BasicDungeonLevelBuilder();


    void buildDungeonLevel(std::string name, int width, int height) override;
    Room buildRoom(int &id) override;
    void buildDoorway(Room origin, Room destination, Room::Direction direction, MoveConstraints constraints) override;
    void buildEntrance(Room room, Room::Direction direction) override;
    void buildExit(Room room, Room::Direction direction) override;
    void buildItem(Room) override;
    void buildCreature(Room) override;
    DungeonLevel getDungeonLevel() override;

};
}
#endif // BASICDUNGEONLEVELBUILDER_H
