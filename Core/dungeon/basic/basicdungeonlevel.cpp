#include "basicdungeonlevel.h"


namespace core::dungeon::basic {


BasicDungeonLevel::BasicDungeonLevel(std::string name, int width, int height)
    : DungeonLevel(name, width, height),
      _description{"Dark Cave (Basic Dungeon)"}

{

}

std::string BasicDungeonLevel::description() {
    return _description;
}

}
