#include "weapon.h"
#include <memory>

namespace core::items {


Weapon::Weapon(std::string name)
    : Item(name) {
}


std::shared_ptr<Item> Weapon::clone() {
    return std::make_shared<Weapon>(*this);
}


}
