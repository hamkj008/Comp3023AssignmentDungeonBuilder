#ifndef MAGICALDUNGEONLEVEL_H
#define MAGICALDUNGEONLEVEL_H

#include "Core/dungeon/dungeonlevel.h"

#include <string>


namespace core::dungeon::magical {


class MagicalDungeonLevel : public DungeonLevel
{
public:
    MagicalDungeonLevel(std::string name, int width, int height);


    virtual std::string description() const override;


private:
    std::string _name;
    int _width;
    int _height;
    std::string _type;

};
}

#endif // MAGICALDUNGEONLEVEL_H
