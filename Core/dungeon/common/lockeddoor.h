#ifndef LOCKEDDOOR_H
#define LOCKEDDOOR_H

#include "Core/dungeon/doorway.h"

namespace core::dungeon::common {


class LockedDoor : public Doorway
{
public:
    LockedDoor();


    virtual std::string description() const override;
    virtual char displayCharacter() override;
    virtual bool isPassage() const override;

    virtual void setPassage(bool passage) override;

    virtual std::ostream& operator <<(std::ostream &display) override;

private:
    std::string _description;
    char _character;
    bool _passage;
};
}
#endif // LOCKEDDOOR_H
