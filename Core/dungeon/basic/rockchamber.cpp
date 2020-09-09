#include <iostream>
#include "rockchamber.h"

using namespace std;


namespace core::dungeon::basic {


RockChamber::RockChamber(int unsigned &id)
    : Room(id),
      _description{"A dark and empty chamber. (Rock Chamber)"}

{
    std::cout << "in RockChamber constructor" << std::endl;
}

std::string RockChamber::description() const {
    return _description;
}


}
