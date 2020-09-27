#include <iostream>
#include "Core/menuinterface.h"

/**
 * @brief main. Executes the application
 * @return 0 if exited successfully.
 */
int main()
{
    core::MenuInterface menu{std::cout, std::cin};
    menu.displayWelcome("Kieran Hambledon", "Dungeon Builder");

    menu.run();


    return 0;
}
