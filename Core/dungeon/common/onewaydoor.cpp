#include "onewaydoor.h"


namespace core::dungeon::common {


OneWayDoor::OneWayDoor()
    : _description{"One-Way Door"},
      _character{'<'},
      _passage{true}
{

}

std::string OneWayDoor::description() const {
    return _description;
}

char OneWayDoor::displayCharacter() const {
    return _character;
}

bool OneWayDoor::isPassage() const {
    return _passage;

}

}
