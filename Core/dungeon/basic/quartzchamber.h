#ifndef QUARTZCHAMBER_H
#define QUARTZCHAMBER_H

#include "Core/dungeon/room.h"


namespace core::dungeon::basic {


class QuartzChamber final : public Room
{
public:

    QuartzChamber(int &id);


    virtual std::string description() const override;

};
}
#endif // QUARTZCHAMBER_H
