#ifndef QUARTZCHAMBER_H
#define QUARTZCHAMBER_H

#include "Core/dungeon/room.h"

class AbstractCreature;

namespace core::dungeon::basic {


class QuartzChamber : public Room
{
public:

    QuartzChamber();


    virtual std::string description() const override;
    virtual std::string display() override;
    virtual int id() const override;
    virtual core::items::Item item() const override;
    virtual void setItem(core::items::Item newItem) override;
    virtual core::creatures::AbstractCreature creature() override;
    virtual void setCreature(core::creatures::AbstractCreature newCreature) override;


};
}
#endif // QUARTZCHAMBER_H
