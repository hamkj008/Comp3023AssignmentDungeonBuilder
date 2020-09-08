#ifndef BASICDUNGEONLEVEL_H
#define BASICDUNGEONLEVEL_H

#include "Core/dungeon/dungeonlevel.h"


namespace core::dungeon::basic {


class BasicDungeonLevel : public DungeonLevel
{
public:
    BasicDungeonLevel();


    std::string description() override;

};
}
#endif // BASICDUNGEONLEVEL_H
