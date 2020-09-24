#include "magicwall.h"
#include <sstream>

namespace core::dungeon::magical {


MagicWall::MagicWall()
{

}

std::string MagicWall::description() const {
    return "Magic Wall";
}

char MagicWall::displayCharacter() {
    if(this->getDirection() == Room::Direction::North or this->getDirection() == Room::Direction::South) {
        return '~';
    }
    else if(this->getDirection() == Room::Direction::East){
        return '}';
    }
    else {
        return '{';
    }
}

std::ostream& MagicWall::operator <<(std::ostream &display) {
    return display << "a " << description();
}
}
