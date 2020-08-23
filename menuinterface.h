#ifndef MENUINTERFACE_H
#define MENUINTERFACE_H

#include <string>


class MenuInterface
{
public:
    MenuInterface(std::ostream display, std::istream input);


    void displayWelcome(std::string author, std::string title);
    void run();

};

#endif // MENUINTERFACE_H
