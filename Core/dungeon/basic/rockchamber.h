#ifndef ROCKCHAMBER_H
#define ROCKCHAMBER_H

#include "Core/dungeon/room.h"

namespace core::dungeon::basic {


class RockChamber : public Room {

public:
    RockChamber();


    virtual std::string description() const override;
    virtual std::string display() override;
    virtual int id() const override;
    virtual core::items::Item item() const override;
    virtual void setItem(core::items::Item newItem) override;
    virtual core::creatures::AbstractCreature creature() override;
    virtual void setCreature(core::creatures::AbstractCreature newCreature) override;


};
}
#endif // ROCKCHAMBER_H
