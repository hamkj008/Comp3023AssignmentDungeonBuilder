#ifndef DOORWAY_H
#define DOORWAY_H

#include "roomedge.h"


namespace core::dungeon {


class Doorway : public RoomEdge
{
public:
    Doorway();
    virtual ~Doorway();

    virtual void connect(std::shared_ptr<Doorway> &opposite);
    virtual bool isEntrance();
    virtual bool isExit();

private:
    std::string _description;

};
}
#endif // DOORWAY_H
