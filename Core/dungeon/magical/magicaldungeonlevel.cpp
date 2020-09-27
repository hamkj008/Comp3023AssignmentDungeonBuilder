#include "magicaldungeonlevel.h"
#include <sstream>

namespace core::dungeon::magical {


MagicalDungeonLevel::MagicalDungeonLevel(std::string &name, int &width, int &height)
    : DungeonLevel(name, width, height),
      _type{"Magic Cave"}
{

}

std::string MagicalDungeonLevel::description() const {
    std::stringstream stringstream;
    stringstream << "\n" << _name <<
    "\nSize: " << _width << " x " << _height <<
    "\nType: " << _type << std::endl;

    std::string description{stringstream.str()};

    return description;
}


}
