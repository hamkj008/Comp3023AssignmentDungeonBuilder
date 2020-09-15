#include "roomedge.h"


namespace core::dungeon {


RoomEdge::RoomEdge()
    : _description{"Room Edge"},
      _direction{}
{

}
RoomEdge::~RoomEdge() {

}

std::string RoomEdge::description() const{
    return _description;
}

char RoomEdge::displayCharacter() const {

}

bool RoomEdge::isPassage() const {
    return true;
}


void RoomEdge::setDirection(Room::Direction direction) {
    _direction = direction;
}

Room::Direction RoomEdge::getDirection() const {
    return _direction;
}
}
