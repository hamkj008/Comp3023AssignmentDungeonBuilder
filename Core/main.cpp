#include <iostream>
#include "Core/menuinterface.h"

/**
 * @brief main
 * @return
 */
int main()
{
    core::MenuInterface menu{std::cout, std::cin};
    menu.displayWelcome("Kieran Hambledon", "Dungeon Builder");

    menu.run();


    return 0;
}
