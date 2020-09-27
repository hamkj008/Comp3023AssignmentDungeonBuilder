#ifndef MAGICALDUNGEONLEVEL_H
#define MAGICALDUNGEONLEVEL_H

#include "Core/dungeon/dungeonlevel.h"

#include <string>


namespace core::dungeon::magical {

/**
 * @brief The MagicalDungeonLevel class
 * The concrete Dungeon Level product, produced by the Builder, for magical dungeons.
 */
class MagicalDungeonLevel : public DungeonLevel
{
public:
    MagicalDungeonLevel(std::string &name, int &width, int &height);


    /**
     * @brief description
     * @return the string description.
     * A brief desciption of the level, including name, size and type.
     */
    virtual std::string description() const override;


private:
    std::string _type;

};
}

#endif // MAGICALDUNGEONLEVEL_H
