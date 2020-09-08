#include "menuinterface.h"
#include "game.h"
#include <string>
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
    *_display << "\n*Press Enter to continue*\n";


    *_display << "\nWhat would you like to do?\n"
              "\t(g)enerate the example level\n"
              "\t(r)andom dungeon level\n"
              "\t(q)uit\n";


    char selection{};
    *_input >> selection;

    std::string *levelName{};
    int *width{};
    int *height{};

    switch(selection) {
        case('g'):
            Game::instance().createExampleLevel();
            break;

        case('r'): {

            bool termsMet{true};

            *_display << "\nWhat would you like to call the level? \n";
            *_input >> *levelName;

            do {
                *_display << "\nHow many rows in *" << *levelName << "*? \n";
                *_input >> *width;

                if(*width < 1 or *width > 4) {
                   *_display << "\nYou have not entered a number in the valid range. Please choose between 1 - 4";
                    termsMet = false;
                }
                else {
                    termsMet = true;

                    *_display << "\nHow many columns in *" << *levelName << "*? \n";
                    *_input >> *height;

                    if(*height < 1 or *height > 4) {
                       *_display << "\nYou have not entered a number in the valid range. Please choose between 1 - 4";
                        termsMet = false;
                    }
                    else {
                        termsMet = true;
                    }
                }
            } while(termsMet == false);

            Game::instance().createRandomLevel(*levelName, *width, *height);

         }  break;

        case('q'): {
            char quit{};
            *_display << "\nAre you sure you want to quit?\n";
            *_input >> quit;
            switch(quit) {
                case('n'):
                    run();
                    break;
            }
         }  break;
        default:
            *_display << "You did not enter a valid choice. Please try again.\n";
    }
}

}
