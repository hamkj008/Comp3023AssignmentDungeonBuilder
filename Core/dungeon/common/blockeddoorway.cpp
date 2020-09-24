#include "blockeddoorway.h"
#include <sstream>

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

bool BlockedDoorway::isPassage() const {
    return _passage;

}
bool BlockedDoorway::isEntrance() {
    return false;
}

bool BlockedDoorway::isExit() {
    return false;
}

std::ostream& BlockedDoorway::operator <<(std::ostream &display) {
    return display << "a " << description() << " to another chamber";
}
}
