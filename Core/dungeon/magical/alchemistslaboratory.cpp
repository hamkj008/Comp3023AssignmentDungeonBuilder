#include <iostream>
#include "Core/dungeon/magical/alchemistslaboratory.h"


namespace core::dungeon::magical {


AlchemistsLaboratory::AlchemistsLaboratory(int &id)
    : Room(id),
    _description{"Bubbling liquids and eye of newt. (Alchemists Laboratory)"}
{
    std::cout << "in Alchemists Laboratory constructor" << std::endl;
}

std::string AlchemistsLaboratory::description() const {
    return _description;
}


}
