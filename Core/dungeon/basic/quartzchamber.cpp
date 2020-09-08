#include <iostream>
#include "quartzchamber.h"

using namespace std;


namespace core::dungeon::basic {


QuartzChamber::QuartzChamber(int &id)
    : Room(id) {

    std::cout << "in quartzChamber constructor" << std::endl;
}

std::string QuartzChamber::description() const {
    return "A chamber that glitters like a thousand stars in the torchlight. (Quartz Chamber)";
}


}
