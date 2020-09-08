#ifndef MONSTER_H
#define MONSTER_H

#include "abstractcreature.h"


namespace core::creatures {


class Monster final : public AbstractCreature
{
public:
    Monster(std::string name);
    ~Monster();


    virtual AbstractCreature* clone() const override;

    char displayCharacter() const override;

private:
    char _displayCharacter;

};
}
#endif // MONSTER_H
