#ifndef ONEWAYDOOR_H
#define ONEWAYDOOR_H

#include "Core/dungeon/doorway.h"

namespace core::dungeon::common {


class OneWayDoor : public Doorway
{
public:
    OneWayDoor(bool entrance, bool exit);

    virtual std::string description() const override;
    virtual char displayCharacter() override;
    virtual bool isPassage() const override;

    virtual bool isEntrance() const override;
    virtual bool isExit() const override;

    virtual void setPassage(bool passage) override;

    std::ostream& operator <<(std::ostream &display) override;

private:
    std::string _description;
    char _character;
    bool _passage;
    bool _entrance;
    bool _exit;
};
}
#endif // ONEWAYDOOR_H
