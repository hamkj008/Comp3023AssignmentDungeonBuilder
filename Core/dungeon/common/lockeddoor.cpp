#include "lockeddoor.h"
#include <iostream>

namespace core::dungeon::common {


LockedDoor::LockedDoor()
    : _description{"Locked Door"},
      _character{'@'},
      _passage{false}
{

}

std::string LockedDoor::description() const {
    return _description;
}

char LockedDoor::displayCharacter() {
    return _character;
}

void LockedDoor::setPassage(bool passage) {
    _passage = passage;
}

bool LockedDoor::isPassage() const {
    return _passage;
}


std::ostream& LockedDoor::operator <<(std::ostream &display) {
    return display << "a " << description() << " to another chamber";
}
}
