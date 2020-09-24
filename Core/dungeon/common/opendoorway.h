#ifndef OPENDOORWAY_H
#define OPENDOORWAY_H

#include "Core/dungeon/doorway.h"

namespace core::dungeon::common {


class OpenDoorway : public Doorway
{
public:
    OpenDoorway();


    virtual std::string description() const override;
    virtual char displayCharacter() override;
    virtual bool isPassage() const override;

    bool isEntrance() override;
    bool isExit() override;

    std::ostream& operator <<(std::ostream &display) override;

private:
    std::string _description;
    char _character;
    bool _passage;

};
}
#endif // OPENDOORWAY_H
