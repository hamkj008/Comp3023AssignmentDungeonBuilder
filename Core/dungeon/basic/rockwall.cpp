#include "rockwall.h"


namespace core::dungeon::basic {


RockWall::RockWall()
{

}

std::string RockWall::description() const {
    return "Rock Wall";
}

char RockWall::displayCharacter() const{
    return 'c';
}

}