#include <iostream>
#include <memory>
#include <array>

#include "Core/menuinterface.h"
#include "Core/dungeon/common/onewaydoor.h"

int main()
{
    core::MenuInterface menu{std::cout, std::cin};
    menu.displayWelcome("Kieran Hambledon", "Dungeon Builder");

    menu.run();


    return 0;
}
