#ifndef ROCKCHAMBER_H
#define ROCKCHAMBER_H

#include "Core/dungeon/room.h"


namespace core::dungeon::basic {

/**
 * @brief The RockChamber class
 * A type of room for basic dungeons.
 */
class RockChamber final : public Room {

public:
    RockChamber(int &id);


    virtual std::string description() const override;

private:
    std::string _description;

};
}
#endif // ROCKCHAMBER_H
