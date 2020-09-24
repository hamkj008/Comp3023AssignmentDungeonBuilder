#include "lockeddoor.h"
#include <sstream>

namespace core::dungeon::common {


LockedDoor::LockedDoor()
    : _description{"Locked Door"},
      _character{'@'},
      _passage{true}
{

}

std::string LockedDoor::description() const {
    return _description;
}

char LockedDoor::displayCharacter() {
    return _character;
}

bool LockedDoor::isPassage() const {
    return _passage;

}
bool LockedDoor::isEntrance() {
    return false;
}

bool LockedDoor::isExit() {
    return false;
}

std::ostream& LockedDoor::operator <<(std::ostream &display) {
    return display << "a " << description() << " to another chamber";
}
}
