#ifndef MENUINTERFACE_H
#define MENUINTERFACE_H

#include <string>
#include <iostream>
#include <sstream>

namespace core {


class MenuInterface {

public:
    MenuInterface(std::ostream &display, std::istream &input);
//    ~MenuInterface();


    void displayWelcome(std::string author, std::string title);

    void run();



private:
    std::ostream *_display;
    std::istream *_input;

};
}

#endif // MENUINTERFACE_H
