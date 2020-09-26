#include "basicdungeonlevel.h"
#include <sstream>

namespace core::dungeon::basic {


BasicDungeonLevel::BasicDungeonLevel(std::string &name, int &width, int &height)
    : DungeonLevel(name, width, height),
      _type{"Dark Cave (Basic Dungeon)"}
{

}

std::string BasicDungeonLevel::description() const {
    std::stringstream ss;
    ss << "\n" << _name <<
    "\nSize: " << _width << " x " << _height <<
    "\nType: " << _type << std::endl;

    std::string description{ss.str()};

    return description;
}

}
