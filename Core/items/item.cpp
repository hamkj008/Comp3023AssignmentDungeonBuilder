#include "item.h"
#include <iostream>

using namespace std;

namespace core::items {


Item::Item(std::string &name) :
    _name{name}
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

}
