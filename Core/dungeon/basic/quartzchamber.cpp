#include "quartzchamber.h"
#include "Core/dungeon/basic/rockwall.h"

namespace core::dungeon::basic {


QuartzChamber::QuartzChamber(int &id)
    : Room(id),
    _description{"A chamber that glitters like a thousand stars in the torchlight. (Quartz Chamber)"}
{

    // Each room has Walls by default.
    _northEdge = std::make_shared<RockWall>();
    _northEdge->setDirection(Room::Direction::North);
    _southEdge = std::make_shared<RockWall>();
    _southEdge->setDirection(Room::Direction::South);
    _eastEdge = std::make_shared<RockWall>();
    _eastEdge->setDirection(Room::Direction::East);
    _westEdge = std::make_shared<RockWall>();
    _westEdge->setDirection(Room::Direction::West);
}


std::string QuartzChamber::description() const {
    return _description;
}


}
