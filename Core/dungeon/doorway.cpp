#include "doorway.h"


namespace core::dungeon {


Doorway::Doorway()
    : _description{}
{

}
Doorway::~Doorway() {
}

void Doorway::connect(Doorway &opposite) {

}

bool Doorway::isEntrance() {
    bool entrance{true};
    return entrance;
}

bool Doorway::isExit() {
    bool exit{true};
    return exit;
}

}
