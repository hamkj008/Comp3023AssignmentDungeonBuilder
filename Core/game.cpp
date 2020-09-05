#include "game.h"
#include <iostream>

using namespace std;


namespace core {


Game::Game() {
    std::cout << "game created" << endl;
}


Game Game::_theInstance{};


Game Game::instance() {
    return _theInstance;
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

}

}
