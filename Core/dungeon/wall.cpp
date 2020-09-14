#include "wall.h"

namespace core::dungeon {


Wall::Wall()

{

}

std::string Wall::description() const {
    return "Wall";
}

char Wall::displayCharacter() const {
    if(this->getDirection() == Room::Direction::North or this->getDirection() == Room::Direction::South) {
        return '-';
    }
    else {
        return '|';
    }
}

bool Wall::isPassage() const {
    return false;
}

}
