#include "consumable.h"


namespace core::items {


Consumable::Consumable(std::string name)
    : Item(name)
{

}

std::shared_ptr<Item> Consumable::clone() {
    return std::make_shared<Consumable>(*this);
}


}
