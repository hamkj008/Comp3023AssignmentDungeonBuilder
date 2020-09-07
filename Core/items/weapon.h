#ifndef WEAPON_H
#define WEAPON_H

#include "item.h"


namespace core::items {


class Weapon final : public Item {

public:
    Weapon(std::string name);
    ~Weapon();

    virtual Item* clone() override;

    virtual std::string name() const override;
    virtual char displayCharacter() const override;


private:
    std::string _name;
    char _character;
};
}
#endif // WEAPON_H
