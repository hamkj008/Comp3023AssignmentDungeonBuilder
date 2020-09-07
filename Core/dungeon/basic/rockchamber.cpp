#include <iostream>
#include "rockchamber.h"

using namespace std;


namespace core::dungeon::basic {


RockChamber::RockChamber()

{
    std::cout << "in RockChamber constructor" << std::endl;
}

std::string RockChamber::description() const {
    return "A dark and empty chamber. (Rock Chamber)";
}
std::string display() {

}

int RockChamber::id() const {
}

core::items::Item RockChamber::item() const {

}
void RockChamber::setItem(core::items::Item newItem) {

}
core::creatures::AbstractCreature RockChamber::creature() {

}

void RockChamber::setCreature(core::creatures::AbstractCreature newCreature) {

}

}
