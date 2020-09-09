#include <iostream>
#include <memory>

#include "game.h"
#include "Core/dungeon/basic/basicdungeonlevelbuilder.h"



namespace core {


Game::Game()
{
    std::cout << "game created" << std::endl;
}

Game::~Game() {
    std::cout << "game destroyed" << std::endl;
}


Game* Game::instance() {

    if(_theInstance == NULL) {
        std::unique_ptr<Game> _theInstance = std::make_unique<Game>();
    }

    return _theInstance;
}



void Game::setDungeonType(core::dungeon::DungeonLevelBuilder) {

}


void Game::createExampleLevel(){
    std::unique_ptr<core::dungeon::basic::BasicDungeonLevelBuilder> basicDB
            = std::make_unique<core::dungeon::basic::BasicDungeonLevelBuilder>();

    basicDB->buildDungeonLevel("Example Level", 3, 3);
    basicDB->getDungeonLevel();

}

void Game::createRandomLevel(std::string &name, int &width, int &height) {

    std::unique_ptr<core::dungeon::basic::BasicDungeonLevelBuilder>
            basicDB = std::make_unique<core::dungeon::basic::BasicDungeonLevelBuilder>();

    basicDB->buildDungeonLevel(name, width, height);
    basicDB->getDungeonLevel();

}
void Game::displayLevel() {

}

double Game::randomDouble() {
    return _realDistribution(_randomGenerator);
}

}
