#include <iostream>
#include "rockchamber.h"
#include "Core/dungeon/basic/rockwall.h"

namespace core::dungeon::basic {


RockChamber::RockChamber(int &id)
    : Room(id),
      _description{"A dark and empty chamber. (Rock Chamber)"}
{
    std::cout << "in RockChamber constructor" << std::endl;

    for(std::size_t i{0}; i < _northEdge.size(); ++i) {
        std::shared_ptr<RoomEdge> wall = std::make_shared<core::dungeon::basic::RockWall>();
        setEdge(Room::Direction::North, wall);
    }
    for(std::size_t i{0}; i < _eastEdge.size(); ++i) {
        std::shared_ptr<RoomEdge> wall = std::make_shared<core::dungeon::basic::RockWall>();
        setEdge(Room::Direction::East, wall);
    }
    for(std::size_t i{0}; i < _westEdge.size(); ++i) {
        std::shared_ptr<RoomEdge> wall = std::make_shared<core::dungeon::basic::RockWall>();
        setEdge(Room::Direction::West, wall);
    }
    for(std::size_t i{0}; i < _southEdge.size(); ++i) {
        std::shared_ptr<RoomEdge> wall = std::make_shared<core::dungeon::basic::RockWall>();
        setEdge(Room::Direction::South, wall);
    }
}

std::string RockChamber::description() const {
    return _description;
}


}
