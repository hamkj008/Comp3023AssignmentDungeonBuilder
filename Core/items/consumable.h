#ifndef CONSUMABLE_H
#define CONSUMABLE_H

#include "item.h"


namespace core::items {


class Consumable final : public Item {

public:
    Consumable(std::string name);

    virtual Item* clone() override;

};
}
#endif // CONSUMABLE_H
