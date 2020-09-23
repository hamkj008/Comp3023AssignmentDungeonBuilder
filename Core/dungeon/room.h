#ifndef ROOM_H
#define ROOM_H

#include <vector>
#include <array>
#include <string>
#include <memory>
#include "Core/creatures/abstractcreature.h"
#include "Core/items/item.h"



namespace core::dungeon {

class RoomEdge;
class Doorway;

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

    void setEdge(Direction direction, std::shared_ptr<RoomEdge> &roomEdge);


protected:
    std::array<std::shared_ptr<RoomEdge>, 9> _northEdge;
    std::array<std::shared_ptr<RoomEdge>, 9> _southEdge;
    std::array<std::shared_ptr<RoomEdge>, 3> _eastEdge;
    std::array<std::shared_ptr<RoomEdge>, 3> _westEdge;


private:
    int _id;
    std::string _description;

    std::array<std::string, 5> _roomDisplay;

    std::shared_ptr<core::creatures::AbstractCreature> _creature;
    std::shared_ptr<core::items::Item> _item;


};


}
#endif // ROOM_H
