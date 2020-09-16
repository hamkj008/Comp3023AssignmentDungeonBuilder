#include "abstractcreature.h"


namespace core::creatures {


AbstractCreature::AbstractCreature(std::string name)
    :_name{name}, _boss{false}
{

}
AbstractCreature::~AbstractCreature() {
}

std::string AbstractCreature::name() const {
   return _name;
}

char AbstractCreature::displayCharacter() const {
    return ' ';
}
void AbstractCreature::setBoss(bool isBoss) {
    _boss = isBoss;
}
bool AbstractCreature::isBoss() {
    return _boss;
}
}
