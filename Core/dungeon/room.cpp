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
    std::stringstream stringstream{};
    std::array<std::string, 5> roomDisplay{};

    // Set top
    stringstream << "+----" << _northEdge->displayCharacter() << "----+";
    roomDisplay[0] = stringstream.str();
    stringstream.str("");

    // set mid1
    stringstream << "|         |";
    roomDisplay[1] = stringstream.str();
    stringstream.str("");

    // set mid2
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

    stringstream << _westEdge->displayCharacter() << "   " << creatureDisplay <<
                   bossDisplay << itemDisplay << "   " << _eastEdge->displayCharacter();

    roomDisplay[2] = stringstream.str();
    stringstream.str("");


    // set mid3
    stringstream << "|         |";
    roomDisplay[3] = stringstream.str();
    stringstream.str("");

    // set bottom
    stringstream << "+----" << _southEdge->displayCharacter() << "----+";
    roomDisplay[4] = stringstream.str();
    stringstream.str("");

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

void Room::setEdge(Room::Direction direction, std::shared_ptr<RoomEdge> roomEdge) {

    if(direction == Room::Direction::North) {
        _northEdge = roomEdge;
        _northEdge->setDirection(Room::Direction::North);
    }
    else if(direction == Room::Direction::South) {
        _southEdge = roomEdge;
        _southEdge->setDirection(Room::Direction::South);
    }
    else if(direction == Room::Direction::East) {
        _eastEdge = roomEdge;
        _eastEdge->setDirection(Room::Direction::East);
    }
    else if(direction == Room::Direction::West) {
        _westEdge = roomEdge;
        _westEdge->setDirection(Room::Direction::West);
    }

}
std::shared_ptr<RoomEdge> Room::getEdge(Room::Direction direction) {

    if(direction == Room::Direction::North) {
        return _northEdge;
    }
    else if(direction == Room::Direction::South) {
        return _southEdge;
    }
    else if(direction == Room::Direction::East) {
        return _eastEdge;
    }
    else {
        return _westEdge;
    }
}

std::ostream& Room::operator <<(std::ostream &display) {
    display << "\nRoom *" << id() << "* is...\n"
           << description()
           << "\nTo the NORTH is ";
    getEdge(Room::Direction::North)->operator<<(display);
    display << "\nTo the SOUTH is ";
    getEdge(Room::Direction::South)->operator<<(display);
    display << "\nTo the EAST is ";
    getEdge(Room::Direction::East)->operator<<(display);
    display << "\nTo the WEST is ";
    getEdge(Room::Direction::West)->operator<<(display);

    if(creature() != nullptr) {
        display << "\n";
        _creature->operator<<(display);
    }
    if(item() != nullptr) {
        display << "\n";
        _item->operator<<(display);
    }
    display << "\n";
    return display;
}

}
