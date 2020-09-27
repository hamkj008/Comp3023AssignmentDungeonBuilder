#ifndef MAGICWALL_H
#define MAGICWALL_H

#include "Core/dungeon/wall.h"


namespace core::dungeon::magical {

/**
 * @brief The MagicWall class
 * A concrete RoomEdge class like Doorways but unconnectable as a passage.
 */
class MagicWall : public Wall
{
public:
    MagicWall();


    virtual std::string description() const override;
    virtual char displayCharacter() override;
    virtual bool isPassage() const override;

    /**
     * @brief operator <<
     * @param display
     * @return std::ostream&
     * Formats the object to be described in the describe menu.
     */
    virtual std::ostream& operator <<(std::ostream &display) override;
};
}
#endif // MAGICWALL_H
