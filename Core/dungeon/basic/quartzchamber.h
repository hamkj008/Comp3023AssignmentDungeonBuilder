#ifndef QUARTZCHAMBER_H
#define QUARTZCHAMBER_H

#include <memory>
#include "Core/dungeon/room.h"


namespace core::dungeon::basic {


class QuartzChamber final : public Room
{
public:

    QuartzChamber(int &id);


    virtual std::string description() const override;


private:
    std::string _description;
};
}
#endif // QUARTZCHAMBER_H
