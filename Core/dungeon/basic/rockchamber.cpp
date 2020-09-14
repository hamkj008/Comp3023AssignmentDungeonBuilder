#include <iostream>
#include "rockchamber.h"


namespace core::dungeon::basic {


RockChamber::RockChamber(int &id)
    : Room(id),
      _description{"A dark and empty chamber. (Rock Chamber)"}

{
    std::cout << "in RockChamber constructor" << std::endl;
}

std::string RockChamber::description() const {
    return _description;
}


}
