#include "blockeddoorway.h"
#include <iostream>

namespace core::dungeon::common {


BlockedDoorway::BlockedDoorway()
    : _description{"Blocked Doorway"},
      _character{'X'},
      _passage{false}
{

}

std::string BlockedDoorway::description() const {
    return _description;
}

char BlockedDoorway::displayCharacter() {
    return _character;
}

void BlockedDoorway::setPassage(bool passage) {
    _passage = passage;
}

bool BlockedDoorway::isPassage() const {
    return _passage;
}


std::ostream& BlockedDoorway::operator <<(std::ostream &display) {
    return display << "a " << description() << " to another chamber";
}
}
