#ifndef MAGICALDUNGEONLEVELBUILDER_H
#define MAGICALDUNGEONLEVELBUILDER_H

#include <string>
#include "Core/dungeon/dungeonlevelbuilder.h"


namespace core::dungeon::magical {

/**
 * @brief The MagicalDungeonLevelBuilder class
 * Builds the level according to the blueprint for magical dungeons
 */
class MagicalDungeonLevelBuilder : public DungeonLevelBuilder
{
public:
    MagicalDungeonLevelBuilder();


    /**
     * @brief buildDungeonLevel
     * @param name
     * @param width
     * @param height
     * Builds a dungeon level object that then builds and adds the rooms selected by width and height.
     * Enforces the maximum amount of rooms as 16.
     */
    virtual void buildDungeonLevel(std::string name, int width, int height) override;

    /**
     * @brief buildRoom
     * @param id
     * @return the built room
     * Selects the type of room and creates a room object.
     */
    virtual std::shared_ptr<Room> buildRoom(int id) override;


    virtual void buildDoorway(std::shared_ptr<Room> &origin, std::shared_ptr<Room> &destination, Room::Direction direction, MoveConstraints constraints) override;

    /**
     * @brief buildEntrance
     * @param room
     * @param direction
     * Creates the Entrance to the dungeon level
     */
    virtual void buildEntrance(std::shared_ptr<Room> &room, Room::Direction direction) override;

    /**
     * @brief buildExit
     * @param room
     * @param direction
     * Creates the Exit from the dungeon level
     */
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

private:
    std::vector<std::shared_ptr<core::items::Item>> _magicItemList;
    std::vector<std::shared_ptr<core::creatures::AbstractCreature>> _magicCreatureList;

};
}
#endif // MAGICALDUNGEONLEVELBUILDER_H
