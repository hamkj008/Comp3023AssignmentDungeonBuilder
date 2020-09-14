#include <iostream>
#include <memory>
#include <sstream>

#include "room.h"
#include "Core/dungeon/roomedge.h"
#include "wall.h"
#include "doorway.h"


namespace core::dungeon {


Room::Room(int &id)
    : _id{id},
      _description{}

{
    std::cout << "Room created" << std::endl;
}
Room::~Room() {
    std::cout << "Room deleted" << std::endl;
}

std::string Room::description() const {
    return _description;
}

std::array<std::string, 5> Room::display() {
    std::stringstream ss{};

    _northEdge = std::make_shared<Wall>();
    _southEdge = std::make_shared<Wall>();
    _eastEdge = std::make_shared<Wall>();
    _westEdge = std::make_shared<Wall>();

    _northEdge->setDirection(Direction::North);
    _southEdge->setDirection(Direction::South);
    _eastEdge->setDirection(Direction::East);
    _westEdge->setDirection(Direction::West);

    // Set top
    ss << "+";
    for(int i{0}; i < 9; ++i) {
        if(i == 4) {
            ss << " ";
        }
        else {
            ss << _northEdge->displayCharacter();
        }
    }
    ss << "+";
    std::string top{ss.str()};
    ss.str("");

    ss << _eastEdge->displayCharacter();
    for(int i = 0; i < 9; ++i) {
        ss << " ";
    }
    ss << _westEdge->displayCharacter();
    std::string mid1{ss.str()};
    std::string mid2{ss.str()};
    std::string mid3{ss.str()};

    ss.str("");
    ss << "+";
    for(int i{0}; i < 9; ++i) {
        if(i == 4) {
            ss << " ";
        }
        else {
            ss << _southEdge->displayCharacter();
        }
    }
    ss << "+";
    std::string bottom{ss.str()};


    std::array<std::string, 5> roomDisplay{};

    roomDisplay[0] = top;
    roomDisplay[1] = mid1;
    roomDisplay[2] = mid2;
    roomDisplay[3] = mid3;
    roomDisplay[4] = bottom;

    return roomDisplay;
}

int Room::id() const {
   return _id;
}

core::items::Item* Room::item() const {
    return _item;
}


void Room::setItem(core::items::Item &newItem) {
    _item = &newItem;
}

core::creatures::AbstractCreature* Room::creature() {

    return _creature;
}

void Room::setCreature(core::creatures::AbstractCreature &newCreature) {
    _creature = &newCreature;
}

}
