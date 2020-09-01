#ifndef ITEM_H
#define ITEM_H

#include <string>


class Item
{
public:
    Item(std::string);


    virtual Item clone();
    std::string name();
    char displayCharacter();

private:
    std::string _name;
    char _character;
};

#endif // ITEM_H
