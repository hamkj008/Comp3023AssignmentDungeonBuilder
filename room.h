#ifndef ROOM_H
#define ROOM_H

#include <string>
#include "dungeonlevel.h"
#include "item.h"
#include "abstractcreature.h"


class Room : public DungeonLevel
{
public:
    Room(int id);

    std::string description() override;
    std::string display() override;
    int id();
    Item item();
    void setItem(Item newItem);
    AbstractCreature creature();
    void setCreature(AbstractCreature newCreature);


};

#endif // ROOM_H
