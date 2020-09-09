#include <iostream>

#include "room.h"
#include "Core/dungeon/roomedge.h"
#include <memory>

namespace core::dungeon {

Room::Room(int unsigned &id)
    : _id{id},
      _northEdge{}
{

}
Room::~Room() {

}

std::array<std::string, 5> Room::display() {

    std::array<std::string, 5> roomDisplay{};

    roomDisplay[0] = "+---------+";
    roomDisplay[1] = "|         |";
    roomDisplay[2] = "|         |";
    roomDisplay[3] = "|         |";
    roomDisplay[4] = "+---------+";

    return roomDisplay;
}



core::items::Item* Room::item() const {
    return &_item;
}


void Room::setItem(core::items::Item &newItem) {
    _item = newItem;
}

core::creatures::AbstractCreature* Room::creature() {

    return &_creature;
}

void Room::setCreature(core::creatures::AbstractCreature &newCreature) {
    _creature = newCreature;
}

}
