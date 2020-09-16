#ifndef ROOM_H
#define ROOM_H

#include "Core/creatures/abstractcreature.h"
#include "Core/items/item.h"
#include <array>
#include <string>
#include <memory>




namespace core::dungeon {

class RoomEdge;

class Room
{
public:
    Room(int id);
    virtual ~Room();


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


private:
    int _id;
    std::string _description;

    std::array<std::string, 5> _roomDisplay;

    std::shared_ptr<core::creatures::AbstractCreature> _creature;
    std::shared_ptr<core::items::Item> _item;

    std::shared_ptr<RoomEdge> _northEdge;
    std::shared_ptr<RoomEdge> _southEdge;
    std::shared_ptr<RoomEdge> _eastEdge;
    std::shared_ptr<RoomEdge> _westEdge;
};


}
#endif // ROOM_H
