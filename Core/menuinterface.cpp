#include "menuinterface.h"
#include "game.h"

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
//    std::ostringstream stringstream;
    *_display << "\n*Press Enter to continue*\n";


    *_display << "\nWhat would you like to do?\n"
              "\t(g)enerate the example level\n"
              "\t(r)andom dungeon level\n"
              "\t(q)uit\n";


    char selection{};
    *_input >> selection;

    string levelName{};
    int width{};
    int height{};
    char quit;

    switch(selection) {
        case('g'):
            Game::instance().createExampleLevel();
            break;

        case('r'):
            *_display << "\nWhat would you like to call the level? \n";
            *_input >> levelName;
            *_display << "\nHow many rows in *" << levelName << "*? \n";
            *_input >> width;
            *_display << "\nHow many columns in *" << levelName << "*? \n";
            *_input >> height;
            Game::instance().createRandomLevel(levelName, width, height);
            break;

        case('q'):

            *_display << "\nAre you sure you want to quit?\n";
            *_input >> quit;
            switch(quit) {
                case('n'):
                    run();
                    break;
            }
            break;
    }
}

}
