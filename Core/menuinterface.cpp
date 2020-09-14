#include "menuinterface.h"
#include "game.h"
#include <string>
#include <sstream>

namespace core {


MenuInterface::MenuInterface(std::ostream &display, std::istream &input)
    : _display{&display}, _input{&input}
{

}


void MenuInterface::displayWelcome(std::string author, std::string title){
    std::ostringstream stringstream;
    stringstream << "\nWelcome to: " << title << "\n"
      << "\t\t" << "developed by " << author << "\n"
      << "\t COMP3023 Software Development with C++\n";
    *_display << stringstream.str();


}

void MenuInterface::run() {
    std::string enter{""};
    do {
        *_display << "\n*Press Enter to continue*\n";
        getline(*_input, enter);

    }while(enter.length() != 0);
    bool conditions = true;

    do{
        *_display << "\nWhat would you like to do?\n"
                    "\t(g)enerate the example level\n"
                    "\t(r)andom dungeon level\n"
                    "\t(q)uit\n";


        char selection{};
        *_input >> selection;

        std::string levelName{};
        int width{};
        int height{};

        switch(selection) {
            case('g'):
                conditions = true;
                Game::instance()->createExampleLevel();
                break;

            case('r'): {
                conditions = true;

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

                Game::instance()->createRandomLevel(levelName, width, height);
               } while(conditions == true);
            }
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
             }  break;
            default:
                *_display << "You did not enter a valid choice. Please try again.\n";
                conditions = false;
        }
    } while(conditions == false);
}

}
