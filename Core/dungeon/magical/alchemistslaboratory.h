#ifndef ALCHEMISTSLABORATORY_H
#define ALCHEMISTSLABORATORY_H

#include "Core/dungeon/room.h"


namespace core::dungeon::magical {

/**
 * @brief The AlchemistsLaboratory class
 * A type of room for magical dungeons.
 */
class AlchemistsLaboratory final : public Room
{
public:

    AlchemistsLaboratory(int &id);


    virtual std::string description() const override;

private:
    std::string _description;
};
}
#endif // ALCHEMISTSLABORATORY_H
