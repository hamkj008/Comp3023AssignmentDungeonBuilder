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

    bool isEntrance() override;
    bool isExit() override;

    std::ostream& operator <<(std::ostream &display) override;

private:
    std::string _description;
    char _character;
    bool _entrance;
    bool _exit;
    bool _passage;
};
}
#endif // ONEWAYDOOR_H
