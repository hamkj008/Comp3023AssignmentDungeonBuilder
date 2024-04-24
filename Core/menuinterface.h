#ifndef MENUINTERFACE_H
#define MENUINTERFACE_H

#include <string>
#include <iostream>
#include <sstream>

namespace core {

/**
 * @brief The MenuInterface class.
 * The Menu Interface class engages with the user and is responsible for optaining user input,
 * as well as displaying the game options.
 */
class MenuInterface {

    public:
        MenuInterface(std::ostream &display, std::istream &input);


        /**
         * @brief displayWelcome
         * @param author
         * @param title
         * Displays the welcome screen and developer information.
         */
        void displayWelcome(std::string author, std::string title);


        /**
         * @brief run
         * The function that runs the game.
         */
        void run();


        /**
         * @brief mainMenu
         * The mainMenu displays the main options, letting the user start the game with either an example dungeon
         * or random dungeon, or quit the game.
         */
        void mainMenu();


        /**
         * @brief MenuInterface::randomDungeonMenu
         * randomDungeonMenu displays the choices available to create a customised and randomly generated dungeon level.
         */
        void randomDungeonMenu();


        /**
         * @brief MenuInterface::dungeonViewMenu
         * The dungeonViewMenu lets the user view the created dungeon level. They can also choose
         * any room in the level to be described before viewing the whole level.
         */
        void dungeonViewMenu();


        /**
         * @brief MenuInterface::dungeonExploreMenu
         * The dungeonExploreMenu lets the user choose any room in the dungeon level to be described to them
         * after the level has been viewed.
         */
        void dungeonExploreMenu();



    private:
        std::ostream *_display;
        std::istream *_input;

    };
}

#endif // MENUINTERFACE_H
