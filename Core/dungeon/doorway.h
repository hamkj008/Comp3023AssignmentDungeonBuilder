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


//    virtual std::string description() const override;
//    virtual char displayCharacter() const override;
//    virtual bool isPassage() const override;
};
}
#endif // DOORWAY_H
