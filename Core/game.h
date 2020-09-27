#ifndef GAME_H
#define GAME_H

#include <string>
#include <random>
#include <ctime>

#include "dungeon/dungeonlevelbuilder.h"
#include "Core/dungeon/doorway.h"


namespace core {

/**
 * @brief The Game class.
 * The Game class provides the main functinality of the Dungeon Builder.
 * It tells the builders how to build the levels, as well as displaying the completed level.
 */
class Game {

public:
    ~Game();
    Game(Game &other) = delete;
    Game operator =(Game &other) = delete;

    /**
     * @brief instance
     * @return a Game instance.
     * The Singleton returns this instance of the game and is the only way to access a Game object.
     */
    static Game* instance();

    /**
     * @brief setDungeonType
     * @param choice
     * Sets the Dungeon type to be either Basic or Magical depending on the selection.
     */
    void setDungeonType(char choice);

    /**
     * @brief createExampleLevel
     * A previously defined level for example purposes.
     */
    void createExampleLevel();

    /**
     * @brief createRandomLevel
     * @param name
     * @param width
     * @param height
     * A customised and random dungeon level to keep things interesting.
     */
    void createRandomLevel(std::string &name, int &width, int &height);

    /**
     * @brief displayLevel
     * @param display
     * Displays the completed level to the user.
     */
    void displayLevel(std::ostream &display);

    /**
     * @brief randomDouble
     * @return a random double.
     * Generates a random floating point number from 0 - 1.0
     */
    double randomDouble();

    /**
     * @brief getBuilder
     * @return the Dungeon Level Builder
     */
    core::dungeon::DungeonLevelBuilder* getBuilder();

    /**
     * @brief createDoor
     * @param door
     * Helper method to decide the door type frequency.
     */
    void createDoor(std::shared_ptr<core::dungeon::Doorway> &door);

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
