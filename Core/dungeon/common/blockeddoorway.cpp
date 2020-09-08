#include "blockeddoorway.h"


namespace core::dungeon::common {


BlockedDoorway::BlockedDoorway()
    : _description{"Blocked Doorway"},
      _character{'X'},
      _passage{true}
{

}

std::string BlockedDoorway::description() const {
    return _description;
}

char BlockedDoorway::displayCharacter() const {
    return _character;
}

bool BlockedDoorway::isPassage() const {
    return _passage;

}

}
