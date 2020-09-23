#include "onewaydoor.h"


namespace core::dungeon::common {


OneWayDoor::OneWayDoor(bool entrance, bool exit, bool passage)
    : _description{"One-Way Door"},
      _character{},
      _entrance{entrance},
      _exit{exit},
      _passage{passage}
{

}

std::string OneWayDoor::description() const {
    return _description;
}

char OneWayDoor::displayCharacter() {
    if(_entrance) {
        _character = 'I';
    }
    else if(_exit) {
        _character = 'O';
    }
    else {
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
    }
    return _character;
}

bool OneWayDoor::isPassage() const {
    return _passage;

}
bool OneWayDoor::isEntrance() {
    return _entrance;
}

bool OneWayDoor::isExit() {
    return _exit;
}
}
