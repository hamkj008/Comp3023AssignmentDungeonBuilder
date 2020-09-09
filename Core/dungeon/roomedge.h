#ifndef ROOMEDGE_H
#define ROOMEDGE_H

#include <string>


namespace core::dungeon {


class RoomEdge
{
public:
    RoomEdge();
    virtual ~RoomEdge();

    virtual std::string description() const;
    virtual char displayCharacter() const;
    virtual bool isPassage() const;

};
}
#endif // ROOMEDGE_H
