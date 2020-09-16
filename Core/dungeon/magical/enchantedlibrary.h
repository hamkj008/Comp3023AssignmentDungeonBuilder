#ifndef ENCHANTEDLIBRARY_H
#define ENCHANTEDLIBRARY_H

#include "Core/dungeon/room.h"


namespace core::dungeon::magical {


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
