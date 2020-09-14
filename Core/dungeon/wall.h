#ifndef WALL_H
#define WALL_H

#include "Core/dungeon/roomedge.h"


namespace core::dungeon {


class Wall : public RoomEdge
{
public:
    Wall();

    virtual std::string description() const override;
    virtual char displayCharacter() const override;

    virtual bool isPassage() const override;
};
}
#endif // WALL_H
