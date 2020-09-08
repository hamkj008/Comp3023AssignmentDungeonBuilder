#include <iostream>
#include "rockchamber.h"

using namespace std;


namespace core::dungeon::basic {


RockChamber::RockChamber(int id)
    : Room(id)

{
    std::cout << "in RockChamber constructor" << std::endl;
}

std::string RockChamber::description() const {
    return "A dark and empty chamber. (Rock Chamber)";
}


}
