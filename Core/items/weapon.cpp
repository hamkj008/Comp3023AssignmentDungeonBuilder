#include "weapon.h"
#include <memory>

namespace core::items {


Weapon::Weapon(std::string name)
    : _name{name} {
}

Weapon::~Weapon() {
}

Item* Weapon::clone() {
    return new Weapon(*this);
}

std::string Weapon::name() const {
    return _name;
}

char Weapon::displayCharacter() const {
    return _character;
}
}
