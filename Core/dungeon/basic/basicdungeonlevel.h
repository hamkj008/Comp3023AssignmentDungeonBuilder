#ifndef BASICDUNGEONLEVEL_H
#define BASICDUNGEONLEVEL_H

#include "Core/dungeon/dungeonlevel.h"


namespace core::dungeon::basic {


class BasicDungeonLevel : public DungeonLevel
{
public:

    BasicDungeonLevel(std::string name, int width, int height);


    std::string description() override;


private:
    std::string _description;

};
}
#endif // BASICDUNGEONLEVEL_H
