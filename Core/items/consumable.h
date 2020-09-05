#ifndef CONSUMABLE_H
#define CONSUMABLE_H

#include "item.h"


namespace core::items {


class Consumable final : public Item {

public:
    Consumable();


    virtual Item& clone() override;

//    virtual char displayCharacter() const override;


};
}
#endif // CONSUMABLE_H
