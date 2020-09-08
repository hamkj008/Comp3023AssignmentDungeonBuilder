#include "wall.h"

namespace core::dungeon {


Wall::Wall()
    : _passage{false}
{

}

std::string Wall::description() const {
    return "Wall";
}

char Wall::displayCharacter() const {
    return '-';

}

bool Wall::isPassage() const {
   return _passage;
}

}
