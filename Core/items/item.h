#ifndef ITEM_H
#define ITEM_H

#include <string>


namespace core::items {

class Item
{
public:
    Item();
    Item(std::string &name);


    virtual Item& clone() = 0;
    virtual std::string name() const;
//    virtual char displayCharacter() const;

private:
    std::string _name;
    char _character;
};
}
#endif // ITEM_H
