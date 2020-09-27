#ifndef BASICDUNGEONLEVELBUILDER_H
#define BASICDUNGEONLEVELBUILDER_H

#include "Core/dungeon/dungeonlevelbuilder.h"
#include "Core/dungeon/basic/basicdungeonlevel.h"
#include "Core/items/item.h"

namespace core::dungeon::basic {

/**
 * @brief The BasicDungeonLevelBuilder class
 * Builds the level according to the blueprint for basic dungeons
 */
class BasicDungeonLevelBuilder : public DungeonLevelBuilder
{
public:
    BasicDungeonLevelBuilder();


    virtual void buildDungeonLevel(std::string name, int width, int height) override;

    /**
     * @brief buildRoom
     * @param id
     * @return the room
     * Selects the type of room and creates a room object.
     */
    virtual std::shared_ptr<Room> buildRoom(int id) override;
    virtual void buildDoorway(std::shared_ptr<Room> &origin, std::shared_ptr<Room> &destination, Room::Direction direction, MoveConstraints constraints) override;
    virtual void buildEntrance(std::shared_ptr<Room> &room, Room::Direction direction) override;
    virtual void buildExit(std::shared_ptr<Room> &room, Room::Direction direction) override;


    /**
     * @brief buildItem
     * @param room. The room to place the item in
     * Chooses a random item from the basic dungeon item list and places it in the room.
     */
    virtual void buildItem(std::shared_ptr<Room> &room) override;

    /**
     * @brief buildCreature
     * @param room. The room to place the creature in.
     * @param isBoss. Selects whether creature is a Boss.
     * Chooses a random creature from the basic dungeon creature list and places it in the room.
     */
    virtual void buildCreature(std::shared_ptr<Room> &room, bool isBoss) override;


private:
    std::vector<std::shared_ptr<core::items::Item>> _basicItemList;
    std::vector<std::shared_ptr<core::creatures::AbstractCreature>> _basicCreatureList;

};
}
#endif // BASICDUNGEONLEVELBUILDER_H
