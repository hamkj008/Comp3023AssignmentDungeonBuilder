#include "consumable.h"

namespace core::items {


Consumable::Consumable(std::string name)
    : Item(name)
{

}
Consumable::~Consumable(){
}

Item* Consumable::clone() {
    return new Consumable(*this);
}


}
