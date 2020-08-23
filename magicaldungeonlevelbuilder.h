#ifndef MAGICALDUNGEONLEVELBUILDER_H
#define MAGICALDUNGEONLEVELBUILDER_H

#include <string>
#include "dungeonlevelbuilder.h"


class MagicalDungeonLevelBuilder : public DungeonLevelBuilder
{
public:
    MagicalDungeonLevelBuilder();


    void buildDungeonLevel(std::string name, int width, int height) override;
    void buildRoom(int id) override;
    void buildDoorway() override;
    void buildEntrance() override;
    void buildExit() override;
    void buildItem() override;
    void buildCreature() override;
    void getDungeonLevel() override;


};

#endif // MAGICALDUNGEONLEVELBUILDER_H
