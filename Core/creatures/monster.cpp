#include "monster.h"


namespace core::creatures {


Monster::Monster(std::string name)
    : AbstractCreature(name),
      _displayCharacter{'M'}
{

}

Monster::~Monster() {
}

AbstractCreature* Monster::clone() const {
    return new Monster(*this);
}


char Monster::displayCharacter() const {
    return _displayCharacter;
}

}
