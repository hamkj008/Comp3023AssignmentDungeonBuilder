#ifndef ITEM_H
#define ITEM_H

#include <string>


namespace core::items {

class Item
{
public:
    Item();
    Item(std::string &name);
    virtual ~Item();

    virtual Item* clone() = 0;
    virtual std::string name() const;
    virtual char displayCharacter() const;


};
}
#endif // ITEM_H
