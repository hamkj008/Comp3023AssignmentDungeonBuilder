#include "monster.h"


namespace core::creatures {


Monster::Monster(std::string name)
    : AbstractCreature(name),
      _displayCharacter{'M'}
{

}


std::shared_ptr<AbstractCreature> Monster::clone() const {
    return std::make_shared<Monster>(*this);
}


char Monster::displayCharacter() const {
    return _displayCharacter;
}

}
