#include "basicdungeonlevel.h"
#include <sstream>

namespace core::dungeon::basic {


BasicDungeonLevel::BasicDungeonLevel(std::string name, int width, int height)
    : _name{name}, _width{width}, _height{height},
      _type{"Dark Cave (Basic Dungeon)"}
{

}

std::string BasicDungeonLevel::description() const {
    std::stringstream ss;
    ss << _name <<
          "Size: " << _width << " x " << _height <<
          "Type: " << _type;

    std::string description{ss.str()};

    return description;
}

}
