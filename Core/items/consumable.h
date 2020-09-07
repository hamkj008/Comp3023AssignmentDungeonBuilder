#ifndef CONSUMABLE_H
#define CONSUMABLE_H

#include "item.h"


namespace core::items {


class Consumable final : public Item {

public:
    Consumable(std::string name);
    ~Consumable();

    virtual Item* clone() override;
    virtual std::string name() const override;
    virtual char displayCharacter() const override;

private:
    std::string _name;
    char _character;
};
}
#endif // CONSUMABLE_H
