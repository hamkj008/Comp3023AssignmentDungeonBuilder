#ifndef BASICDUNGEONLEVEL_H
#define BASICDUNGEONLEVEL_H

#include "Core/dungeon/dungeonlevel.h"


namespace core::dungeon::basic {


class BasicDungeonLevel : public DungeonLevel
{
public:

    BasicDungeonLevel(std::string &name, int &width, int &height);


    virtual std::string description() const override;


private:
    std::string _type;

};
}
#endif // BASICDUNGEONLEVEL_H
