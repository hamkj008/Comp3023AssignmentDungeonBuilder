#ifndef MONSTER_H
#define MONSTER_H

#include "abstractcreature.h"


class Monster : public AbstractCreature
{
public:
    Monster();


    AbstractCreature clone() override;

};

#endif // MONSTER_H
