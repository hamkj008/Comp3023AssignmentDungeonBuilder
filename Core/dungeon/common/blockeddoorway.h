#ifndef BLOCKEDDOORWAY_H
#define BLOCKEDDOORWAY_H

#include "Core/dungeon/doorway.h"

namespace core::dungeon::common {

/**
 * @brief The BlockedDoorway class
 * Concrete Door type class
 */
class BlockedDoorway final : public Doorway
{
public:
    BlockedDoorway();


    virtual std::string description() const override;
    virtual char displayCharacter() override;

    /**
     * @brief isPassage
     * @return true if connected as a Passage.
     * If connected to another doorway type, the connection becomes a Passage.
     */
    virtual bool isPassage() const override;
    virtual void setPassage(bool passage) override;

    /**
     * @brief operator <<
     * @param display
     * @return
     * Formats the object to be described in the describe menu.
     */
    virtual std::ostream& operator <<(std::ostream &display) override;

private:
    std::string _description;
    char _character;
    bool _passage;
};
}
#endif // BLOCKEDDOORWAY_H
