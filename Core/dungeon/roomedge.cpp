#include "roomedge.h"
#include <iostream>

namespace core::dungeon {


RoomEdge::RoomEdge()
    : _direction{}
{
//    std::cout << "RoomEdge created" << std::endl;
}
RoomEdge::~RoomEdge() {
//    std::cout << "RoomEdge deleted" << std::endl;
}


void RoomEdge::setDirection(Room::Direction direction) {
    _direction = direction;
}

Room::Direction RoomEdge::getDirection() const {
    return _direction;
}

std::ostream& RoomEdge::operator <<(std::ostream &display) {

}
}
