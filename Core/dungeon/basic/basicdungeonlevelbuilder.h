#ifndef BASICDUNGEONLEVELBUILDER_H
#define BASICDUNGEONLEVELBUILDER_H

#include "Core/dungeon/dungeonlevelbuilder.h"
#include "Core/dungeon/basic/basicdungeonlevel.h"
#include "Core/items/item.h"

namespace core::dungeon::basic {

class BasicDungeonLevelBuilder : public DungeonLevelBuilder
{
public:

    BasicDungeonLevelBuilder();

    virtual void buildDungeonLevel(std::string name, int width, int height) override;
    virtual std::shared_ptr<Room> buildRoom(int id) override;
    virtual void buildDoorway(std::shared_ptr<Room> &origin, std::shared_ptr<Room> &destination, Room::Direction direction, MoveConstraints constraints) override;
    virtual void buildEntrance(std::shared_ptr<Room> &room, Room::Direction direction) override;
    virtual void buildExit(std::shared_ptr<Room> &room, Room::Direction direction) override;
    virtual void buildItem(std::shared_ptr<Room> &room) override;
    virtual void buildCreature(std::shared_ptr<Room> &room, bool isBoss) override;


private:

    std::vector<std::shared_ptr<core::items::Item>> _basicItemList;
    std::vector<std::shared_ptr<core::creatures::AbstractCreature>> _basicCreatureList;

};
}
#endif // BASICDUNGEONLEVELBUILDER_H
