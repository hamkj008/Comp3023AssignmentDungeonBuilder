#ifndef ITEM_H
#define ITEM_H

#include <string>
#include <memory>

namespace core::items {

class Item
{
public:
    Item(std::string &name);
    virtual ~Item();

    virtual std::shared_ptr<Item> clone() = 0;
    virtual std::string name() const;
    virtual char displayCharacter() const;

    std::ostream& operator <<(std::ostream &display);

private:
    std::string _name;
    char _displayCharacter;
};
}
#endif // ITEM_H
