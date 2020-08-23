#ifndef GAME_H
#define GAME_H

#include <string>
#include "dungeonlevelbuilder.h"


class Game
{


public:
    static void instance();

    void setDungeonType(DungeonLevelBuilder);
    void createExampleLevel();
    void createRandomLevel(std::string name, int width, int height);
    void displayLevel();
    double randomDouble();


private:
    Game();

    static void theInstance();

};

#endif // GAME_H
