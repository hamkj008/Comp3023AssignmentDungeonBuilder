#ifndef MONSTER_H
#define MONSTER_H

#include "abstractcreature.h"


namespace core::creatures {

/**
 * @brief The Monster class
 * The concrete creature class
 */
class Monster final : public AbstractCreature
{
public:
    Monster(std::string name);


    virtual std::shared_ptr<AbstractCreature> clone() const override;

    char displayCharacter() const override;

private:
    char _displayCharacter;

};
}
#endif // MONSTER_H
