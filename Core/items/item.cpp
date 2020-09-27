#include "item.h"
#include <iostream>


namespace core::items {


Item::Item(std::string &name) :
    _name{name},
    _displayCharacter{'L'}
{

}
Item::~Item()
{

}

std::string Item::name() const {
    return _name;
}

char Item::displayCharacter() const {
    return _displayCharacter;
}

std::ostream& Item::operator <<(std::ostream &display) {
    return display << "There is a " << name() << " to pick up.";
}
}
