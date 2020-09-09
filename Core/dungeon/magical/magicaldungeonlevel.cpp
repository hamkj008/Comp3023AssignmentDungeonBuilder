#include "magicaldungeonlevel.h"


namespace core::dungeon::magical {


MagicalDungeonLevel::MagicalDungeonLevel(std::string name, int width, int height)
    : DungeonLevel(name, width, height),
      _description{"Magic Cave"}
{

}

std::string MagicalDungeonLevel::description() {
    return _description;
}


}
