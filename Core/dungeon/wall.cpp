#include "wall.h"
#include <iostream>

namespace core::dungeon {


Wall::Wall()

{
//    std::cout << "Wall created" << std::endl;
}
Wall::~Wall()
{
//    std::cout << "Wall deleted" << std::endl;
}


bool Wall::isPassage() const {
    return false;
}

}
