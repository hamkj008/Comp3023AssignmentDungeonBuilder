#include "magicaldungeonlevel.h"
#include <sstream>

namespace core::dungeon::magical {


MagicalDungeonLevel::MagicalDungeonLevel(std::string name, int width, int height)
    : DungeonLevel(name, width, height),
      _type{"Magic Cave"}
{

}

std::string MagicalDungeonLevel::description() const {
    std::stringstream ss;
    ss << _name <<
          "Size: " << _width << " x " << _height <<
          "Type: " << _type;

    std::string description{ss.str()};

    return description;
}


}
