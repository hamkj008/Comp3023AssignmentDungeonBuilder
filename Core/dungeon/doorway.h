#ifndef DOORWAY_H
#define DOORWAY_H

#include "roomedge.h"


namespace core::dungeon {


class Doorway : public RoomEdge
{
public:
    Doorway();
    virtual ~Doorway();

    void connect(Doorway &opposite);
    bool isEntrance();
    bool isExit();




private:
    std::string _description;
};
}
#endif // DOORWAY_H
