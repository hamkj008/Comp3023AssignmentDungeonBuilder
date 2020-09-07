#ifndef ROOM_H
#define ROOM_H

class Item;
class AbstractCreature;

#include "Core/creatures/abstractcreature.h"
#include "Core/items/item.h"



namespace core::dungeon {


class Room
{
public:
    Room();
    Room(int &id);


    enum Direction : unsigned {
        North,
        South,
        East,
        West
    };

    virtual std::string description() const = 0;
    virtual std::string display();
    virtual int id() const;
    virtual core::items::Item item() const;
    virtual void setItem(core::items::Item newItem);
    virtual core::creatures::AbstractCreature creature();
    virtual void setCreature(core::creatures::AbstractCreature newCreature);





private:
    int _id;
};


}
#endif // ROOM_H
