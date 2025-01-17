#ifndef CONSUMABLE_H
#define CONSUMABLE_H

#include "item.h"


namespace core::items {

/**
 * @brief The Consumable class
 * The concrete consumable items class
 */
class Consumable final : public Item {

public:
    Consumable(std::string name);

    virtual std::shared_ptr<Item> clone() override;

};
}
#endif // CONSUMABLE_H
