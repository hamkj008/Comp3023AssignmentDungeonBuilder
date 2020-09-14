#ifndef LOCKEDDOOR_H
#define LOCKEDDOOR_H

#include "Core/dungeon/doorway.h"

namespace core::dungeon::common {


class LockedDoor : public Doorway, RoomEdge
{
public:
    LockedDoor();


    virtual std::string description() const override;
    virtual char displayCharacter() const override;
    virtual bool isPassage() const override;

private:
    std::string _description;
    char _character;
    bool _passage;
};
}
#endif // LOCKEDDOOR_H
