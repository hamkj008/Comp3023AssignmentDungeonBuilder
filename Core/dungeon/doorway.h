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
    virtual bool isEntrance() const;
    virtual bool isExit() const;

    virtual void setPassage(bool passage) = 0;

private:
    std::string _description;


};
}
#endif // DOORWAY_H
