#include "monster.h"


namespace core::creatures {


Monster::Monster(std::string name)
    : _name{name} {
}

Monster::~Monster() {
}

AbstractCreature* Monster::clone() const {
    return new Monster(*this);
}

std::string Monster::name() const {
    return _name;
}

char Monster::displayCharacter() const {
    return _character;
}

}
