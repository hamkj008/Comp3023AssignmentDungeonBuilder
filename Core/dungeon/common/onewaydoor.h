#ifndef ONEWAYDOOR_H
#define ONEWAYDOOR_H

#include "Core/dungeon/doorway.h"

namespace core::dungeon::common {


class OneWayDoor : public Doorway
{
public:
    OneWayDoor();


    virtual std::string description() const override;
    virtual char displayCharacter() const override;
    virtual bool isPassage() const override;

private:
    std::string _description;
    char _character;
    bool _passage;
};
}
#endif // ONEWAYDOOR_H
