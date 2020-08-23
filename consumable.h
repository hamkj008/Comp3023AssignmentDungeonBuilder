#ifndef CONSUMABLE_H
#define CONSUMABLE_H

#include "item.h"


class Consumable : public Item {

public:
    Consumable();


    Item clone() override;

};

#endif // CONSUMABLE_H
