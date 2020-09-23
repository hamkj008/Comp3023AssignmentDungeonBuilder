#include "opendoorway.h"


namespace core::dungeon::common {


OpenDoorway::OpenDoorway()
    : _description{"Open Doorway"},
      _character{},
      _passage{true}
{

}

std::string OpenDoorway::description() const {
    return _description;
}

char OpenDoorway::displayCharacter() {
    if(this->getDirection() == Room::Direction::North) {
        _character = 'v';
    }
    else if(this->getDirection() == Room::Direction::South) {
        _character = '^';
    }
    else if(this->getDirection() == Room::Direction::West) {
        _character = '<';
    }
    else if(this->getDirection() == Room::Direction::East) {
        _character = '>';
    }
    return _character;
}

bool OpenDoorway::isPassage() const {
    return _passage;

}
bool OpenDoorway::isEntrance() {
    return false;
}

bool OpenDoorway::isExit() {
    return false;
}
}
