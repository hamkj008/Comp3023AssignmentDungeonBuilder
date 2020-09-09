#include <iostream>
#include "quartzchamber.h"


namespace core::dungeon::basic {


QuartzChamber::QuartzChamber(int unsigned id)
    : Room(id),
    _description{"A chamber that glitters like a thousand stars in the torchlight. (Quartz Chamber)"}
{
    std::cout << "in quartzChamber constructor" << std::endl;
}

std::string QuartzChamber::description() const {
    return _description;
}


}
