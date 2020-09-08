#include <iostream>
#include <memory>

#include "game.h"
#include "Core/dungeon/basic/basicdungeonlevelbuilder.h"


using namespace std;


namespace core {


Game::Game() {
    std::cout << "game created" << endl;
}

Game::~Game() {
    std::cout << "game destroyed" << endl;
}


Game Game::instance() {
    std::unique_ptr<Game> game;

    if(_theInstance == NULL) {
        game = std::make_unique<Game>();
    }
    return game->instance();
}



void Game::setDungeonType(core::dungeon::DungeonLevelBuilder) {

}


void Game::createExampleLevel(){

}

void Game::createRandomLevel(std::string &name, int &width, int &height) {
    std::unique_ptr<core::dungeon::basic::BasicDungeonLevelBuilder> basicDB
            = std::make_unique<core::dungeon::basic::BasicDungeonLevelBuilder>();

    basicDB->buildDungeonLevel(name, width, height);
    basicDB->getDungeonLevel();

}
void Game::displayLevel() {

}

double Game::randomDouble() {
    return _realDistribution(_randomGenerator);
}

}
