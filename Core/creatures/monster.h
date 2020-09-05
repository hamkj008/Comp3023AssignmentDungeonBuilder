#ifndef MONSTER_H
#define MONSTER_H

#include "abstractcreature.h"


namespace core::creatures {


class Monster final : public AbstractCreature
{
public:
    Monster();

    AbstractCreature& clone() const override;

};
}
#endif // MONSTER_H
