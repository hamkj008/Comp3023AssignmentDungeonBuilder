#ifndef ROOMEDGE_H
#define ROOMEDGE_H

#include <string>
#include "Core/dungeon/room.h"


class Room;

namespace core::dungeon {

/**
 * @brief The RoomEdge class
 * The RoomEdge base class parents wall and door types,
 * that make up the four edges of each Room.
 */
class RoomEdge
{
public:
    RoomEdge();
    virtual ~RoomEdge();

    virtual std::string description() const = 0;
    virtual char displayCharacter() = 0;
    virtual bool isPassage() const = 0;


    /**
     * @brief setDirection
     * @param direction
     * Sets the direction that each Room edge faces.
     */
    virtual void setDirection(Room::Direction direction);

    /**
     * @brief getDirection
     * @return the direction that the edge is facing
     */
    virtual Room::Direction getDirection() const;


    /**
     * @brief operator <<
     * @param display
     * @return std::ostream&
     * Abstract method for derived classes to override.
     */
    virtual std::ostream& operator <<(std::ostream &display) = 0;

private:
    Room::Direction _direction;
};
}
#endif // ROOMEDGE_H
