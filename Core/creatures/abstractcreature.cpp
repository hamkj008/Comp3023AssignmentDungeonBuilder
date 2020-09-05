#include "abstractcreature.h"


namespace core::creatures {


AbstractCreature::AbstractCreature(std::string name)
    : _name{name}
{
}


std::string AbstractCreature::name(){
   return _name;
}

char AbstractCreature::displayCharacter() {
    char character{};
    return character;
}

}
