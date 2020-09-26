#include "rockwall.h"
#include <sstream>

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
    return false;
}

std::ostream& RockWall::operator <<(std::ostream &display) {
    return display << "a " << description();
}
}
