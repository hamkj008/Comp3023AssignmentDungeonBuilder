#ifndef BASICDUNGEONLEVELBUILDER_H
#define BASICDUNGEONLEVELBUILDER_H

#include "Core/dungeon/dungeonlevelbuilder.h"

namespace core::dungeon::basic {

class BasicDungeonLevelBuilder : public DungeonLevelBuilder
{
public:

    BasicDungeonLevelBuilder();

    virtual void buildDungeonLevel(std::string name, int width, int height) override;
    virtual std::shared_ptr<Room> buildRoom(int &id) override;
    virtual void buildDoorway(Room* origin, Room* destination, Room::Direction direction, MoveConstraints constraints) override;
    virtual void buildEntrance(Room* room, Room::Direction direction) override;
    virtual void buildExit(Room* room, Room::Direction direction) override;
    virtual void buildItem(Room*) override;
    virtual void buildCreature(Room*) override;
    virtual DungeonLevel getDungeonLevel() override;

private:
    std::shared_ptr<DungeonLevel> _db;
};
}
#endif // BASICDUNGEONLEVELBUILDER_H
