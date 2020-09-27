#ifndef WALL_H
#define WALL_H

#include "Core/dungeon/roomedge.h"


namespace core::dungeon {


class Wall : public RoomEdge
{
public:
    Wall();
    virtual ~Wall();

};
}
#endif // WALL_H
