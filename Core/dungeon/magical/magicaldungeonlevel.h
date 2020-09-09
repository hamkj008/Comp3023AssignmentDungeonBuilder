#ifndef MAGICALDUNGEONLEVEL_H
#define MAGICALDUNGEONLEVEL_H

#include "Core/dungeon/dungeonlevel.h"

#include <string>


namespace core::dungeon::magical {


class MagicalDungeonLevel : public DungeonLevel
{
public:
    MagicalDungeonLevel(std::string name, int width, int height);


    std::string description() override;


private:
    std::string _description;

};
}

#endif // MAGICALDUNGEONLEVEL_H
