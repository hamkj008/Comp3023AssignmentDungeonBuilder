#ifndef WEAPON_H
#define WEAPON_H

#include "item.h"


class Weapon : public Item {

public:
    Weapon();


    Item clone() override;
};

#endif // WEAPON_H
