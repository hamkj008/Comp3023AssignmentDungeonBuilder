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
    virtual std::shared_ptr<Room> buildRoom(int id) override;
    virtual void buildDoorway(std::shared_ptr<Room> &origin, std::shared_ptr<Room> &destination, Room::Direction direction, MoveConstraints constraints) override;
    virtual void buildEntrance(std::shared_ptr<Room> &room, Room::Direction direction) override;
    virtual void buildExit(std::shared_ptr<Room> &room, Room::Direction direction) override;

    /**
     * @brief buildItem
     * @param room. The room to place the item.
     * Chooses a random item from the magic dungeon item list and places it in the room.
     */
    virtual void buildItem(std::shared_ptr<Room> &room) override;

    /**
     * @brief buildCreature
     * @param room. The room to place the creature
     * @param isBoss. Selects whether creature is a Boss.
     * Chooses a random creature from the magic dungeon creature list and places it in the room.
     *
     */
    virtual void buildCreature(std::shared_ptr<Room> &room, bool isBoss) override;

    std::vector<std::shared_ptr<core::items::Item>> _magicItemList;
    std::vector<std::shared_ptr<core::creatures::AbstractCreature>> _magicCreatureList;

};
}
#endif // MAGICALDUNGEONLEVELBUILDER_H
