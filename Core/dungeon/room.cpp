#include <iostream>

#include "room.h"
#include "Core/dungeon/roomedge.h"
#include <memory>

namespace core::dungeon {

Room::Room(int &id)
    : _id{id},
      _northEdge{}

{
}


std::array<std::string, 5> Room::display() {
    std::unique_ptr<RoomEdge> northEdge = std::make_unique<RoomEdge>();
    northEdge->description();


}



core::items::Item Room::item() const {

}


void Room::setItem(core::items::Item newItem) {

}

core::creatures::AbstractCreature Room::creature() {

}

void Room::setCreature(core::creatures::AbstractCreature newCreature) {

}

}
