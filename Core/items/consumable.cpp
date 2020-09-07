#include "consumable.h"

namespace core::items {


Consumable::Consumable(std::string name)
    : _name{name}
{

}
Consumable::~Consumable(){
}

Item* Consumable::clone() {
    return new Consumable(*this);
}

std::string Consumable::name() const {
    return _name;
}

char Consumable::displayCharacter() const {
    return _character;
}

}
