#include "abstractcreature.h"


namespace core::creatures {


AbstractCreature::AbstractCreature(std::string name)
    :_name{name}
{

}
AbstractCreature::~AbstractCreature() {

}

std::string AbstractCreature::name() const {
   return _name;
}

char AbstractCreature::displayCharacter() const {}

}
