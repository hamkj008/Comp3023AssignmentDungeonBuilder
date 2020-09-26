#ifndef GAME_H
#define GAME_H

#include <string>
#include <random>
#include <ctime>

#include "dungeon/dungeonlevelbuilder.h"



namespace core {

class Game {

public:
    ~Game();
    Game(Game &other) = delete;
    Game operator =(Game &other) = delete;

    static Game* instance();

    void setDungeonType(char choice);
    void createExampleLevel();
    void createRandomLevel(std::string &name, int &width, int &height);
    void displayLevel(std::ostream &display);
    double randomDouble();
    core::dungeon::DungeonLevelBuilder* getBuilder();

    std::ostream& operator <<(std::ostream &display);

private:
    Game();

    static Game *_theInstance;
    core::dungeon::DungeonLevelBuilder *_DB;

    std::mt19937 _randomGenerator{uint32_t(time(nullptr))}; //!< Mersenne Twister random number generator seeded by current time
    std::uniform_real_distribution<double> _realDistribution{0.0, 1.0}; //!< For random numbers between 0.0 & 1.0
};
}

#endif // GAME_H
