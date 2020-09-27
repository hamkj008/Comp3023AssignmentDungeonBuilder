#ifndef WEAPON_H
#define WEAPON_H

#include "item.h"
#include <memory>

namespace core::items {

/**
 * @brief The Weapon class
 * These items are all weapons.
 */
class Weapon final : public Item {

public:
    Weapon(std::string name);

    virtual std::shared_ptr<Item> clone() override;

};
}
#endif // WEAPON_H
