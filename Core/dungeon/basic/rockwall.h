#ifndef ROCKWALL_H
#define ROCKWALL_H

#include "Core/dungeon/wall.h"


namespace core::dungeon::basic {


class RockWall : public Wall, RoomEdge
{
public:
    RockWall();


    virtual std::string description() const override;


};
}
#endif // ROCKWALL_H
