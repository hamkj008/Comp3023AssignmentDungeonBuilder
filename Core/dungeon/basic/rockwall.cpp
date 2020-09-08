#include "rockwall.h"


namespace core::dungeon::basic {


RockWall::RockWall()
{

}

std::string RockWall::description() const {
    return "Rockwall";
}

char RockWall::displayCharacter() const{
    return 'c';
}

}
