#include "consumable.h"

namespace core::items {


Consumable::Consumable(std::string name)
    : Item(name)
{

}

Item* Consumable::clone() {
    return new Consumable(*this);
}


}
