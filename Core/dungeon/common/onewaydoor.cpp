#include "onewaydoor.h"
#include <sstream>

namespace core::dungeon::common {


OneWayDoor::OneWayDoor(bool entrance, bool exit)
    : _description{"One-Way Door"},
      _character{},
      _passage{false},
      _entrance{entrance},
      _exit{exit}
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
            _character = '>';
        }
        else if(this->getDirection() == Room::Direction::East) {
            _character = '<';
        }
    }
    return _character;
}

void OneWayDoor::setPassage(bool passage) {
    if(_entrance == true or _exit == true) {
        _passage = false;
    }
    else {
        _passage = passage;
    }
}

bool OneWayDoor::isPassage() const {
    return _passage;

}
bool OneWayDoor::isEntrance() const {
    return _entrance;
}

bool OneWayDoor::isExit() const {
    return _exit;
}

std::ostream& OneWayDoor::operator <<(std::ostream &display) {
    if(_entrance == true) {
        return display << "the entrance to the dungeon level.";
    }
    else if(_exit == true) {
        return display << "the exit from the dungeon level.";
    }
    else {
        return display << "a " << description() << " from another chamber";
    }
}

}
