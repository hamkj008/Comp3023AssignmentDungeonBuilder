#include <iostream>
#include "Core/dungeon/magical/enchantedlibrary.h"
#include "Core/dungeon/magical/magicwall.h"


namespace core::dungeon::magical {


EnchantedLibrary::EnchantedLibrary(int &id)
    : Room(id),
    _description{"A thousand floating books. (Enchanted Library)"}
{
    std::cout << "in Enchanted Library constructor" << std::endl;

    _northEdge = std::make_shared<MagicWall>();
    _northEdge->setDirection(Room::Direction::North);
    _southEdge = std::make_shared<MagicWall>();
    _southEdge->setDirection(Room::Direction::South);
    _eastEdge = std::make_shared<MagicWall>();
    _eastEdge->setDirection(Room::Direction::East);
    _westEdge = std::make_shared<MagicWall>();
    _westEdge->setDirection(Room::Direction::West);
}

std::string EnchantedLibrary::description() const {
    return _description;
}


}
