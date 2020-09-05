#ifndef MAGICALDUNGEONLEVEL_H
#define MAGICALDUNGEONLEVEL_H

#include "Core/dungeon/dungeonlevel.h"

#include <string>


namespace core::dungeon::magical {


class MagicalDungeonLevel : public DungeonLevel
{
public:
    MagicalDungeonLevel();


    std::string description() override;

};
}

#endif // MAGICALDUNGEONLEVEL_H
