#ifndef ROOM_H
#define ROOM_H

#include <array>
#include <string>
#include <memory>
#include "Core/creatures/abstractcreature.h"
#include "Core/items/item.h"


namespace core::dungeon {

class RoomEdge;

/**
 * @brief The Room class
 * The Room class is the building block of the dungeon level.
 * Each dungeon level is composed of several Rooms, and each Room has four edges in each Direction.
 */
class Room
{
public:
    Room(int id);
    virtual ~Room();


    /**
     * @brief The Direction enum
     * The Directions that each RoomEdge will be facing in the Room
     */
    enum class Direction : unsigned {
        North,
        South,
        East,
        West
    };

    virtual std::string description() const = 0;
    std::array<std::string, 5> display();
    int id() const;


    virtual std::shared_ptr<core::items::Item> item();
    virtual void setItem(std::shared_ptr<core::items::Item> &newItem);

    virtual std::shared_ptr<core::creatures::AbstractCreature> creature();
    virtual void setCreature(std::shared_ptr<core::creatures::AbstractCreature> &newCreature);

    /**
     * @brief setEdge
     * @param direction
     * @param roomEdge
     * Sets the Rooms edge in the given direction to be the given roomEdge,
     * and also sets the direction of that Room edge to be the given direction.
     */
    virtual void setEdge(Direction direction, std::shared_ptr<RoomEdge> roomEdge);
    /**
     * @brief getEdge
     * @param direction
     * @return the RoomEdge in the given direction.
     */
    virtual std::shared_ptr<RoomEdge> getEdge(Room::Direction direction);

    /**
     * @brief operator <<
     * @param display
     * @return std::ostream&
     * Formats the contents of the room ready to be described.
     */
    std::ostream& operator <<(std::ostream &display);

// Each room has 4 edges.
protected:
    std::shared_ptr<RoomEdge> _northEdge;
    std::shared_ptr<RoomEdge> _southEdge;
    std::shared_ptr<RoomEdge> _eastEdge;
    std::shared_ptr<RoomEdge> _westEdge;

private:
    int _id;
    std::string _description;

    // Array of 5 strings representing the room, ready for display.
    std::array<std::string, 5> _roomDisplay;

    // The creature to be added.
    std::shared_ptr<core::creatures::AbstractCreature> _creature;
    // The item to be added.
    std::shared_ptr<core::items::Item> _item;

};


}
#endif // ROOM_H
