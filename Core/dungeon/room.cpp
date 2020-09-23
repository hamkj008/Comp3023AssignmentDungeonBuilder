#include <iostream>
#include <memory>
#include <sstream>

#include "room.h"
#include "Core/dungeon/roomedge.h"
#include "wall.h"
#include "Core/dungeon/common/lockeddoor.h"
#include "Core/dungeon/basic/rockwall.h"
#include "Core/dungeon/common/onewaydoor.h"

namespace core::dungeon {


Room::Room(int id)
    : _northEdge{}, _southEdge{}, _eastEdge{}, _westEdge{},
      _id{id}, _description{}, _creature{}, _item{}
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

    // Set top
    ss << "+";
    for(std::size_t i{}; i < _northEdge.size(); ++i) {
        ss << _northEdge[i]->displayCharacter();
    }
    ss << "+";
    std::string top{ss.str()};
    ss.str("");

    // set mid1
    ss << _westEdge[0]->displayCharacter();
    ss << "         ";
    ss << _eastEdge[0]->displayCharacter();
    std::string mid1{ss.str()};
    ss.str("");

    // set mid2
    std::stringstream mid2sstream{};
    char itemDisplay{};
    if(_item == nullptr) {
        itemDisplay = ' ';
    }
    else {
        itemDisplay = _item->displayCharacter();
    }

    char creatureDisplay{};
    if(_creature == nullptr) {
        creatureDisplay = ' ';
    }
    else {
        creatureDisplay = _creature->displayCharacter();
    }

    char bossDisplay{};
    if(_creature == nullptr) {
        bossDisplay = ' ';
    }
    else if(_creature->isBoss() == true) {
        bossDisplay = '*';
    }
    else {
        bossDisplay = ' ';
    }

    mid2sstream << _westEdge[1]->displayCharacter() << "   " << creatureDisplay <<
                   bossDisplay << itemDisplay << "   " << _eastEdge[1]->displayCharacter();

    std::string mid2{mid2sstream.str()};
    ss.str("");


    ss << _westEdge[2]->displayCharacter();
    ss << "         ";
    ss << _eastEdge[2]->displayCharacter();
    std::string mid3{ss.str()};
    ss.str("");

    // set bottom
    ss << "+";
    for(std::size_t i{}; i < _southEdge.size(); ++i) {
        ss << _southEdge[i]->displayCharacter();
    }
    ss << "+";
    std::string bottom{ss.str()};
    ss.str("");

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

std::shared_ptr<core::items::Item> Room::item() {
    return _item;
}


void Room::setItem(std::shared_ptr<core::items::Item> &newItem) {
    _item = newItem;
}

std::shared_ptr<core::creatures::AbstractCreature> Room::creature() {
    return _creature;
}

void Room::setCreature(std::shared_ptr<core::creatures::AbstractCreature> &newCreature) {
    _creature = newCreature;
}

void Room::setEdge(Room::Direction direction, std::shared_ptr<RoomEdge> &roomEdge) {
    roomEdge->setDirection(direction);

    std::shared_ptr<Wall> wall = std::dynamic_pointer_cast<Wall>(roomEdge);
    if(wall == nullptr) {
        if(direction == Room::Direction::North) {
            _northEdge[4] = roomEdge;
        }
        else if(direction == Room::Direction::South) {
            _southEdge[4] = roomEdge;
        }
        else if(direction == Room::Direction::East) {
            _eastEdge[1] = roomEdge;
        }
        else if(direction == Room::Direction::West) {
            _westEdge[1] = roomEdge;
        }
    }
    else {
        if(direction == Room::Direction::North) {
            for(std::size_t i{0}; i < _northEdge.size(); ++i) {
                if(_northEdge[i] == nullptr) {
                    _northEdge[i] = roomEdge;
                    break;
                }
            }
        }
        else if(direction == Room::Direction::South) {
            for(std::size_t i{0}; i < _southEdge.size(); ++i) {
                if(_southEdge[i] == nullptr) {
                    _southEdge[i] = roomEdge;
                }
            }
        }
        else if(direction == Room::Direction::East) {
            for(std::size_t i{0}; i < _eastEdge.size(); ++i) {
                if(_eastEdge[i] == nullptr) {
                    _eastEdge[i] = roomEdge;
                }
            }
        }
        else if(direction == Room::Direction::West) {
            for(std::size_t i{0}; i < _westEdge.size(); ++i) {
                if(_westEdge[i] == nullptr) {
                    _westEdge[i] = roomEdge;
                }
            }
        }
    }
}


}
