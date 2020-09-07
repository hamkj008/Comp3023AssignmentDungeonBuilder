#include <iostream>

#include "game.h"


using namespace std;


namespace core {


Game::Game() {
    std::cout << "game created" << endl;
}

Game::~Game() {
    std::cout << "game destroyed" << endl;
}


Game Game::instance() {
    if(_theInstance == NULL) {
        _theInstance = new Game();
    }
    return *_theInstance;
}



void Game::setDungeonType(core::dungeon::DungeonLevelBuilder) {

}


void Game::createExampleLevel(){

}

void Game::createRandomLevel(std::string &name, int &width, int &height) {

}
void Game::displayLevel() {

}

double Game::randomDouble() {
    return _realDistribution(_randomGenerator);
}

}
