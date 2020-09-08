#ifndef WEAPON_H
#define WEAPON_H

#include "item.h"


namespace core::items {


class Weapon final : public Item {

public:
    Weapon(std::string name);
    ~Weapon();

    virtual Item* clone() override;

};
}
#endif // WEAPON_H
