#ifndef BLOCKEDDOORWAY_H
#define BLOCKEDDOORWAY_H

#include "Core/dungeon/doorway.h"

namespace core::dungeon::common {


class BlockedDoorway : public Doorway, RoomEdge
{
public:
    BlockedDoorway();


    virtual std::string description() const override;
    virtual char displayCharacter() const override;
    virtual bool isPassage() const override;

private:
    std::string _description;
    char _character;
    bool _passage;
};
}
#endif // BLOCKEDDOORWAY_H
