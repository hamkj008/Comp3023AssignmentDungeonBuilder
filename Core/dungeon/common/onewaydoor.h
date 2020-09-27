#ifndef ONEWAYDOOR_H
#define ONEWAYDOOR_H

#include "Core/dungeon/doorway.h"

namespace core::dungeon::common {

/**
 * @brief The OneWayDoor class
 * Concrete Door type class that also can be set to be an
 * Entrance to the dungeon level as well an Exit.
 */
class OneWayDoor final : public Doorway
{
public:
    OneWayDoor(bool entrance, bool exit);

    virtual std::string description() const override;
    virtual char displayCharacter() override;

    /**
     * @brief isPassage
     * @return true if connected as a Passage.
     * If connected to another doorway type, the connection becomes a Passage.
     */
    virtual bool isPassage() const override;
    virtual void setPassage(bool passage) override;

    virtual bool isEntrance() const override;
    virtual bool isExit() const override;

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
    bool _entrance;
    bool _exit;
};
}
#endif // ONEWAYDOOR_H
