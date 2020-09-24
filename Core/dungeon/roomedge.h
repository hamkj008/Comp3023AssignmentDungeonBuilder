#ifndef ROOMEDGE_H
#define ROOMEDGE_H

#include <string>
#include "Core/dungeon/room.h"


class Room;
namespace core::dungeon {

class RoomEdge
{
public:
    RoomEdge();
    virtual ~RoomEdge();

    virtual std::string description() const = 0;
    virtual char displayCharacter() = 0;
    virtual bool isPassage() const = 0;


    virtual void setDirection(Room::Direction direction);
    virtual Room::Direction getDirection() const;

    virtual std::ostream& operator <<(std::ostream &display);

private:
    Room::Direction _direction;
};
}
#endif // ROOMEDGE_H
