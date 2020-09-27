#ifndef DOORWAY_H
#define DOORWAY_H

#include "roomedge.h"


namespace core::dungeon {

/**
 * @brief The Doorway class
 * The Doorway class is a concrete Room edge, consisting of several types.
 * They form the connections between rooms, creating passages.
 */
class Doorway : public RoomEdge
{
public:
    Doorway();
    virtual ~Doorway();

    /**
     * @brief connect
     * @param opposite
     * Sets the opposite to the opposite direction to the Doorway,
     * then connects the Doorway and its opposite as a Passage.
     */
    virtual void connect(std::shared_ptr<Doorway> &opposite);

    virtual bool isEntrance() const;
    virtual bool isExit() const;

    virtual void setPassage(bool passage) = 0;

private:
    std::string _description;


};
}
#endif // DOORWAY_H
