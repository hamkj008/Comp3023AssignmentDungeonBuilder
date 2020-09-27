#include <iostream>
#include "rockchamber.h"
#include "Core/dungeon/basic/rockwall.h"

namespace core::dungeon::basic {


RockChamber::RockChamber(int &id)
    : Room(id),
      _description{"A dark and empty chamber. (Rock Chamber)"}
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

std::string RockChamber::description() const {
    return _description;
}


}
