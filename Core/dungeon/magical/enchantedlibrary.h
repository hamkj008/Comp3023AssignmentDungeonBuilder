#ifndef ENCHANTEDLIBRARY_H
#define ENCHANTEDLIBRARY_H

#include "Core/dungeon/room.h"


namespace core::dungeon::magical {

/**
 * @brief The EnchantedLibrary class
 * A type of room for magical dungeons.
 */
class EnchantedLibrary final : public Room
{
public:

    EnchantedLibrary(int &id);


    virtual std::string description() const override;

private:
    std::string _description;
};
}
#endif // ENCHANTEDLIBRARY_H
