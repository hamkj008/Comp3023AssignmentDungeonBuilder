#include "roomedge.h"
#include <iostream>

namespace core::dungeon {


RoomEdge::RoomEdge()
    : _direction{}
{
}
RoomEdge::~RoomEdge() {
}


void RoomEdge::setDirection(Room::Direction direction) {
    _direction = direction;
}

Room::Direction RoomEdge::getDirection() const {
    return _direction;
}

}
