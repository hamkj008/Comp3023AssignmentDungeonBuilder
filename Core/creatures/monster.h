#ifndef MONSTER_H
#define MONSTER_H

#include "abstractcreature.h"


namespace core::creatures {


class Monster final : public AbstractCreature
{
public:
    Monster(std::string name);
    ~Monster();


    AbstractCreature* clone() const override;

    virtual std::string name() const override;
    virtual char displayCharacter() const override;


private:
    std::string _name;
    char _character;
};
}
#endif // MONSTER_H
