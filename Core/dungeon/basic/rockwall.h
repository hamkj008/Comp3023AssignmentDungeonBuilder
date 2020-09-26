#ifndef ROCKWALL_H
#define ROCKWALL_H

#include "Core/dungeon/wall.h"


namespace core::dungeon::basic {


class RockWall : public Wall
{
public:
    RockWall();


    virtual std::string description() const override;
    virtual char displayCharacter() override;
    virtual bool isPassage() const override;

    std::ostream& operator <<(std::ostream &display) override;
};
}
#endif // ROCKWALL_H
