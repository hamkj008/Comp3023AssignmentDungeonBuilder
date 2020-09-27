#ifndef WALL_H
#define WALL_H

#include "Core/dungeon/roomedge.h"


namespace core::dungeon {

/**
 * @brief The Wall class
 * Abstract RoomEdge class that is the base class for wall types.
 * Walls are like Doorways but unconnectable as a passage.
 */
class Wall : public RoomEdge
{
public:
    Wall();
    virtual ~Wall();

};
}
#endif // WALL_H
