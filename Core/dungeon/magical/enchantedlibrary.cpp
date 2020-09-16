#include <iostream>
#include "Core/dungeon/magical/enchantedlibrary.h"


namespace core::dungeon::magical {


EnchantedLibrary::EnchantedLibrary(int &id)
    : Room(id),
    _description{"A thousand floating books. (Enchanted Library)"}
{
    std::cout << "in Enchanted Library constructor" << std::endl;
}

std::string EnchantedLibrary::description() const {
    return _description;
}


}
