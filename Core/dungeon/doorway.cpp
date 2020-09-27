#include "doorway.h"


namespace core::dungeon {


Doorway::Doorway()
    : _description{}
{

}
Doorway::~Doorway()
{

}

void Doorway::connect(std::shared_ptr<Doorway> &opposite) {
    if(this->getDirection() == Room::Direction::South) {
        opposite->setDirection(Room::Direction::North);
    }
    else if(this->getDirection() == Room::Direction::East) {
        opposite->setDirection(Room::Direction::West);
    }

    this->setPassage(true);
    opposite->setPassage(true);
}

bool Doorway::isEntrance() const{
    return false;
}
bool Doorway::isExit() const{
    return false;
}

}
