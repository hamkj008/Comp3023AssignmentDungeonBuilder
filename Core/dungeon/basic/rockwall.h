#ifndef ROCKWALL_H
#define ROCKWALL_H

#include "Core/dungeon/wall.h"


namespace core::dungeon::basic {

/**
 * @brief The RockWall class
 * A concrete RoomEdge class like Doorways but unconnectable as a passage.
 */
class RockWall : public Wall
{
public:
    RockWall();

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
#endif // ROCKWALL_H
