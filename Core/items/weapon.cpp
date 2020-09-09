#include "weapon.h"
#include <memory>

namespace core::items {


Weapon::Weapon(std::string name)
    : Item(name) {
}


Item* Weapon::clone() {
    return new Weapon(*this);
}


}
