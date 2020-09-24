#include "item.h"
#include <iostream>

using namespace std;

namespace core::items {


Item::Item(std::string &name) :
    _name{name},
    _displayCharacter{'L'}
{

}
Item::~Item() {
    std::cout << "Item object deleted" << std::endl;
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
