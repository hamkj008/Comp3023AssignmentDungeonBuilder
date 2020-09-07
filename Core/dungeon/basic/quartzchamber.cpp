#include <iostream>
#include "quartzchamber.h"

using namespace std;


namespace core::dungeon::basic {


QuartzChamber::QuartzChamber()
{
    std::cout << "in quartzChamber constructor" << std::endl;
}

std::string QuartzChamber::description() const {
    return "A chamber that glitters like a thousand stars in the torchlight. (Quartz Chamber)";
}

std::string display() {

}

int QuartzChamber::id() const {
}

core::items::Item QuartzChamber::item() const {

}

void QuartzChamber::setItem(core::items::Item newItem) {

}
core::creatures::AbstractCreature QuartzChamber::creature() {

}

void QuartzChamber::setCreature(core::creatures::AbstractCreature newCreature) {

}

}
