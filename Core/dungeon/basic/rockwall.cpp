#include "rockwall.h"


namespace core::dungeon::basic {


RockWall::RockWall()
{

}

std::string RockWall::description() const {
    return "Rock Wall";
}

char RockWall::displayCharacter() {
    if(this->getDirection() == Room::Direction::North or this->getDirection() == Room::Direction::South) {
        return '-';
    }
    else {
        return '|';
    }
}
bool RockWall::isPassage() const {
    return true;
}
}
