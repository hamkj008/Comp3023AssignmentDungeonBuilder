#ifndef GAME_H
#define GAME_H

#include "dungeon/dungeonlevelbuilder.h"
class DungeonLevelBuilder;

#include <string>


namespace core {

class Game {

public:
//    ~Game();
//    Game(Game &other) = delete;
    Game operator =(Game &other) = delete;

    static Game instance();


    void setDungeonType(core::dungeon::DungeonLevelBuilder);
    void createExampleLevel();
    void createRandomLevel(std::string &name, int &width, int &height);
    void displayLevel();
    double randomDouble();


private:
    Game();


    static Game _theInstance;

};
}

#endif // GAME_H
