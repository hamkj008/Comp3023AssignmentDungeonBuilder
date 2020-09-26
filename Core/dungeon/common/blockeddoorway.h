#ifndef BLOCKEDDOORWAY_H
#define BLOCKEDDOORWAY_H

#include "Core/dungeon/doorway.h"

namespace core::dungeon::common {


class BlockedDoorway : public Doorway
{
public:
    BlockedDoorway();


    virtual std::string description() const override;
    virtual char displayCharacter() override;
    virtual bool isPassage() const override;


    virtual void setPassage(bool passage) override;

    std::ostream& operator <<(std::ostream &display) override;

private:
    std::string _description;
    char _character;
    bool _passage;
};
}
#endif // BLOCKEDDOORWAY_H
