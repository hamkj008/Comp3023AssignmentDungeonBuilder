#include "magicwall.h"


namespace core::dungeon::magical {


MagicWall::MagicWall()
{

}

std::string MagicWall::description() const {
    return "Magicwall";
}

char MagicWall::displayCharacter() const{
    return 'c';
}

}
