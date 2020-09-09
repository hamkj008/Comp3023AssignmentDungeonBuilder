#ifndef ROCKCHAMBER_H
#define ROCKCHAMBER_H

#include "Core/dungeon/room.h"


namespace core::dungeon::basic {


class RockChamber final : public Room {

public:
    RockChamber(int unsigned &id);


    virtual std::string description() const override;

private:
    std::string _description;

};
}
#endif // ROCKCHAMBER_H
