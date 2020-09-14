#ifndef OPENDOORWAY_H
#define OPENDOORWAY_H

#include "Core/dungeon/doorway.h"

namespace core::dungeon::common {


class OpenDoorway : public Doorway, RoomEdge

{
public:
    OpenDoorway();


    virtual std::string description() const override;
    virtual char displayCharacter() const override;
    virtual bool isPassage() const override;

private:
    std::string _description;
    char _character;
    bool _passage;

};
}
#endif // OPENDOORWAY_H
