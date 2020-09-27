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


void MenuInterface::run(){
    std::string enter{};
    do{
        _input->sync();
        *_display << "\n*Press Enter to continue*\n";
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

            Game::instance()->setDungeonType('b');
            Game::instance()->createExampleLevel();

            *_display << "Dungeon level created! \n";

            dungeonViewMenu();
            break;

        case('r'):
            randomDungeonMenu();
            break;

        case('q'): {
            conditions = true;
            char quit{};
            bool termsMet{true};
            do {
                *_display << "\n*Are you sure you want to quit? (y/n)*\n";
                *_input >> quit;
                switch(quit) {
                case('n'):
                    termsMet = true;
                    run();
                    break;
                case('y'):
                    termsMet = true;
                    *_display << "\nGoodbye!\n";
                    delete Game::instance();
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

    bool nameCheck{};
    do {
        nameCheck = true;
        *_display << "\nWhat would you like to call the level? \n";
        *_input >> levelName;
        if(levelName.length() == 0) {
            *_display << "\nYou have not entered a proper name. Level name can not be blank. Please enter a name.";
            nameCheck = false;
        }
    }while(nameCheck == false);

    bool rowCheck{};
    do {
        rowCheck = true;
        std::string rowSelect{};

        *_display << "\nHow many rows in *" << levelName << "*? \n";
        *_input >> rowSelect;

        std::stringstream stringstream{rowSelect};
        stringstream >> width;
        stringstream.str("");

        if(width < 1 or width >  4) {
            *_display << "\nYou have not entered a number in the valid range. Please choose between 1 - 4";
            rowCheck = false;
            stringstream.str("");
        }
    } while(rowCheck == false);

    bool colCheck{};
    do {
        colCheck = true;
        std::string colSelect{};

        *_display << "\nHow many columns in *" << levelName << "*? \n";
        *_input >> colSelect;

        std::stringstream stringstream{colSelect};
        stringstream >> height;
        stringstream.str("");

        if(height < 1 or height > 4) {
            *_display << "\nYou have not entered a number in the valid range. Please choose between 1 - 4";
            colCheck = false;
            stringstream.str("");
        }
    } while(colCheck == false);

    bool typeCheck{};
    do {
        typeCheck = true;
        char type{};

        *_display << "\nWhat type of dungeon level is it? (b)asic or (m)agical\n";
        *_input >> type;

        switch(type) {
        case('b'): {
            Game::instance()->setDungeonType('b');
            typeCheck = true;
        }   break;
        case('m'): {
            Game::instance()->setDungeonType('m');
            typeCheck = true;
        }   break;
        default:
            *_display << "You did not enter a valid choice. Please try again.\n";
            typeCheck = false;
            break;
        }
    } while(typeCheck == false);

    *_display << "\nCreating " << levelName << "... ";
    Game::instance()->createRandomLevel(levelName, width, height);
    *_display << "\nDungeon level created! \n";
    dungeonViewMenu();
}

void MenuInterface::dungeonViewMenu(){
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
            Game::instance()->operator<<(*_display);
            dungeonExploreMenu();
            break;

        case('v'):
            Game::instance()->displayLevel(*_display);
            dungeonExploreMenu();
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
}

void MenuInterface::dungeonExploreMenu(){
    // User input check gate.
    bool conditions = true;
    // The users selection
    char selection{};
    do {
        *_display << "\nWhat would you like to do?\n"
                     "\t(d)escribe a room\n"
                     "\t(r)eturn to the previous menu\n";

        *_input >> selection;

        switch(selection) {
        case('d'): {
            conditions = true;
            int roomNum{};
            // User input correct range check
            bool roomCheck{};
            do {
                roomCheck = true;
                std::string roomSelect{};

                *_display << "\nWhich room would you like to describe? (1-"
                          << Game::instance()->getBuilder()->getDungeonLevel()->numberOfRooms()
                          << ")\n";

                *_input >> roomSelect;

                std::stringstream stringstream{roomSelect};
                stringstream >> roomNum;

                if(roomNum < 1 or roomNum > Game::instance()->getBuilder()->getDungeonLevel()->numberOfRooms()) {
                    *_display << "\nYou have not entered a number in the valid range. Please choose between 1-"
                              << Game::instance()->getBuilder()->getDungeonLevel()->numberOfRooms()
                              << ")\n";
                    roomCheck = false;
                }
            }while(roomCheck == false);

            Game::instance()->getBuilder()->getDungeonLevel()->retrieveRoom(roomNum)->operator<<(*_display);
            dungeonExploreMenu();
        } break;

        case('r'):
            conditions = true;
            *_display << "\nReturning to previous menu.\n";
            dungeonViewMenu();
            break;

        default:
            *_display << "You did not enter a valid choice. Please try again.\n";
            conditions = false;
            break;
        }
    }while(conditions == false);
}

}
