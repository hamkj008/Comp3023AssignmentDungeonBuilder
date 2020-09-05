#ifndef WEAPON_H
#define WEAPON_H

#include "item.h"


namespace core::items {

class Weapon final : public Item {

public:
    Weapon();


    virtual Item& clone() override;

//    virtual char displayCharacter() const override;

};
}
#endif // WEAPON_H
