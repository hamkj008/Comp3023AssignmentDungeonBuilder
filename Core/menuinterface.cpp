#include <string>
#include <sstream>

#include "menuinterface.h"
#include "game.h"
#include "Core/dungeon/dungeonlevelbuilder.h"
#include "Core/dungeon/basic/basicdungeonlevelbuilder.h"
#include "Core/dungeon/magical/magicaldungeonlevelbuilder.h"

namespace core {

MenuInterface::MenuInterface(std::ostream &display, std::istream &input)
    : _display{&display}, _input{&input}
{

}


void MenuInterface::displayWelcome(std::string author, std::string title){
    *_display << "\nWelcome to: " << title << "\n"
              << "\t\t" << "developed by " << author << "\n"
              << "\t COMP3023 Software Development with C++\n";
}


void MenuInterface::run() {
    std::string enter{};
    do {
        *_display << "\n*Press Enter to continue*\n";
        std::string enter{""};
        getline(*_input, enter);

    }while(enter.length() != 0);

    mainMenu();

}


void MenuInterface::mainMenu(){
    bool conditions = true;
    char selection{};
    do{
        *_display << "\nWhat would you like to do?\n"
                     "\t(g)enerate the example level\n"
                     "\t(r)andom dungeon level\n"
                     "\t(q)uit\n";

        *_input >> selection;

        switch(selection) {
            case('g'):
                conditions = true;
                *_display << "\nCreating Example Dungeon Level... \n";

                Game::instance()->createExampleLevel();

                *_display << "Dungeon Level Created! \n";

                dungeonInteractMenu();

                break;

            case('r'):
                randomDungeonMenu();
                break;

            case('q'): {
                conditions = true;
                char quit{};
                bool termsMet{true};
                do {
                    *_display << "\nAre you sure you want to quit?\n";
                    *_input >> quit;
                    switch(quit) {
                    case('n'):
                        termsMet = true;
                        run();
                        break;
                    case('y'):
                        termsMet = true;
                        *_display << "\nGoodbye!\n";
                        break;
                    default:
                        *_display << "You did not enter a valid choice. Please try again.\n";
                        termsMet = false;
                        break;
                    }
                } while(termsMet == false);
                break;
            }
            default:
                *_display << "You did not enter a valid choice. Please try again.\n";
                conditions = false;
                break;
            }
    } while(conditions == false);
}

void MenuInterface::randomDungeonMenu(){
    std::string levelName{};
    int width{};
    int height{};
    bool conditions = true;

    *_display << "\nWhat would you like to call the level? \n";
    *_input >> levelName;

    do {
        bool rowCheck;
        do {
            rowCheck = true;
            std::string size{};

            *_display << "\nHow many rows in *" << levelName << "*? \n";
            *_input >> size;

            std::stringstream ss{size};
            ss >> width;

            if(width < 1 or width >  4) {
                *_display << "\nYou have not entered a number in the valid range. Please choose between 1 - 4";
                rowCheck = false;
                ss.clear();
            }
        } while(rowCheck == false);

        bool colCheck;
        do {
            colCheck = true;
            std::string size{};

            *_display << "\nHow many columns in *" << levelName << "*? \n";
            *_input >> size;

            std::stringstream ss{size};
            ss >> height;

            if(height < 1 or height > 4) {
                *_display << "\nYou have not entered a number in the valid range. Please choose between 1 - 4";
                colCheck = false;
                ss.clear();
            }
        } while(colCheck == false);

        bool typeCheck;
        do {
            typeCheck = true;
            char type{};

            *_display << "\nWhat type of dungeon level is it? (b)asic or (m)agical\n";
            *_input >> type;

            switch(type) {
            case('b'): {
                core::dungeon::basic::BasicDungeonLevelBuilder basicDungeonBuilder{};
                Game::instance()->setDungeonType('b');
                typeCheck = true;
                conditions = false;
            }   break;
            case('m'): {
                core::dungeon::magical::MagicalDungeonLevelBuilder magicDungeonBuilder{};
                Game::instance()->setDungeonType('m');
                typeCheck = true;
                conditions = false;
            }   break;
            default:
                *_display << "You did not enter a valid choice. Please try again.\n";
                typeCheck = false;
                break;
            }
        } while(typeCheck == false);
    } while(conditions == true);

    Game::instance()->createRandomLevel(levelName, width, height);
    dungeonInteractMenu();
    Game::instance()->displayLevel(*_display);
}

void MenuInterface::dungeonInteractMenu() {
    bool conditions = true;
    char selection{};
    do {
    *_display << "\nWhat would you like to do?\n"
                 "\t(d)escribe the dungeon level\n"
                 "\t(v)iew the dungeon level\n"
                 "\t(r)eturn to the main menu\n";

    *_input >> selection;

    switch(selection) {
        case('d'):
            conditions = true;
            *_display << Game::instance()->_DB->getDungeonLevel()->description();
            break;

        case('v'):
            Game::instance()->displayLevel(*_display);
            break;

        case('r'):
            conditions = true;
            *_display << "\nReturning to main menu.\n";
            mainMenu();
            break;

        default:
            *_display << "You did not enter a valid choice. Please try again.\n";
            conditions = false;
            break;
        }
   }while(conditions == false);
    mainMenu();
}

}
