#ifndef MAGICWALL_H
#define MAGICWALL_H

#include "Core/dungeon/wall.h"


namespace core::dungeon::magical {


class MagicWall : public Wall
{
public:
    MagicWall();


    virtual std::string description() const override;
    virtual char displayCharacter() override;
    virtual bool isPassage() const override;

    virtual std::ostream& operator <<(std::ostream &display) override;
};
}
#endif // MAGICWALL_H
