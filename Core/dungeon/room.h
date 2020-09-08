#ifndef ROOM_H
#define ROOM_H

#include "Core/creatures/abstractcreature.h"
#include "Core/items/item.h"
#include "Core/dungeon/roomedge.h"
#include <array>
#include <string>
#include <memory>

class RoomEdge;

namespace core::dungeon {


class Room
{
public:
    Room(int &id);


    enum Direction : unsigned {
        North,
        South,
        East,
        West
    };

    virtual std::string description() const;

    std::array<std::string, 5> display();

    int id() const;

    virtual core::items::Item item() const;
    virtual void setItem(core::items::Item newItem);
    virtual core::creatures::AbstractCreature creature();
    virtual void setCreature(core::creatures::AbstractCreature newCreature);


private:
    int _id;
    RoomEdge _northEdge;
    RoomEdge _southEdge;
    RoomEdge _eastEdge;
    RoomEdge _westEdge;
};


}
#endif // ROOM_H
