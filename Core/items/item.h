#ifndef ITEM_H
#define ITEM_H

#include <string>
#include <memory>

namespace core::items {

/**
 * @brief The Item class
 * The abstract prototype class used for creating and cloning concrete items.
 */
class Item
{
public:
    Item(std::string &name);
    virtual ~Item();

    virtual std::shared_ptr<Item> clone() = 0;
    virtual std::string name() const;
    virtual char displayCharacter() const;

    /**
     * @brief operator <<
     * @param display
     * @return std::ostream&
     * Formats a description of the item ready for the describe menu.
     */
    std::ostream& operator <<(std::ostream &display);

private:
    std::string _name;
    char _displayCharacter;
};
}
#endif // ITEM_H
