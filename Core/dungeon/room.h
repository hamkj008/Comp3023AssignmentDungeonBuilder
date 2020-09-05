#ifndef ROOM_H
#define ROOM_H

class Item;
class AbstractCreature;

#include <string>

namespace core::dungeon {


class Room
{
public:
    Room();
//    Room(int &id);

//    virtual std::string description() const;
//    virtual std::string display();
//    virtual int id() const;
//    virtual Item item();
//    virtual void setItem(Item newItem);
//    virtual AbstractCreature creature();
//    virtual void setCreature(AbstractCreature newCreature);

private:
    int _id;
};
}
#endif // ROOM_H
