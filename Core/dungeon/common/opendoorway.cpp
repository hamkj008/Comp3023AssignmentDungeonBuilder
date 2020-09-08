#include "opendoorway.h"


namespace core::dungeon::common {


OpenDoorway::OpenDoorway()
    : _description{"Open Doorway"},
      _character{'>'},
      _passage{true}
{

}

std::string OpenDoorway::description() const {
    return _description;
}

char OpenDoorway::displayCharacter() const {
    return _character;
}

bool OpenDoorway::isPassage() const {
    return _passage;

}

}
