#include "opendoorway.h"
#include <iostream>

namespace core::dungeon::common {


OpenDoorway::OpenDoorway()
    : _description{"Open Doorway"},
      _character{},
      _passage{false}
{

}

std::string OpenDoorway::description() const {
    return _description;
}

char OpenDoorway::displayCharacter() {
    if(this->getDirection() == Room::Direction::North) {
        _character = '^';
    }
    else if(this->getDirection() == Room::Direction::South) {
        _character = 'v';
    }
    else if(this->getDirection() == Room::Direction::West) {
        _character = '<';
    }
    else if(this->getDirection() == Room::Direction::East) {
        _character = '>';
    }
    return _character;
}

void OpenDoorway::setPassage(bool passage) {
    _passage = passage;
}

bool OpenDoorway::isPassage() const {
    return _passage;
}

std::ostream& OpenDoorway::operator <<(std::ostream &display) {
    return display << "an " << description() << " to another chamber";
}
}
