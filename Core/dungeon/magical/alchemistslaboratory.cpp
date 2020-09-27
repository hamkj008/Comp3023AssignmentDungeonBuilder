#include "Core/dungeon/magical/alchemistslaboratory.h"
#include "Core/dungeon/magical/magicwall.h"


namespace core::dungeon::magical {


AlchemistsLaboratory::AlchemistsLaboratory(int &id)
    : Room(id),
    _description{"Bubbling liquids and eye of newt. (Alchemists Laboratory)"}
{

    _northEdge = std::make_shared<MagicWall>();
    _northEdge->setDirection(Room::Direction::North);
    _southEdge = std::make_shared<MagicWall>();
    _southEdge->setDirection(Room::Direction::South);
    _eastEdge = std::make_shared<MagicWall>();
    _eastEdge->setDirection(Room::Direction::East);
    _westEdge = std::make_shared<MagicWall>();
    _westEdge->setDirection(Room::Direction::West);
}

std::string AlchemistsLaboratory::description() const {
    return _description;
}


}
