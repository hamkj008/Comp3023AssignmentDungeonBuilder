#include "weapon.h"
#include <memory>

namespace core::items {


Weapon::Weapon(std::string name)
    : Item(name) {
}

Weapon::~Weapon() {
}

Item* Weapon::clone() {
    return new Weapon(*this);
}


}
