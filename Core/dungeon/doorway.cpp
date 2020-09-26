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
