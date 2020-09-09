#include "dungeonlevel.h"

#include <iostream>
#include <vector>
#include <string>
#include <sstream>


namespace core::dungeon {

DungeonLevel::DungeonLevel(std::string &name, int &width, int &height)
    :_name{name}, _width{width}, _height{height}
{

}
DungeonLevel::~DungeonLevel(){
    std::cout << "DungeonLEvel deleted" << std::endl;
}

bool DungeonLevel::addRoom(Room &room) {
    return true;
}

Room DungeonLevel::retrieveRoom(int &id) {

}


int DungeonLevel::width() {
    return _width;
}

int DungeonLevel::height() {
    return _height;
}

int DungeonLevel::numberOfRooms() {
    return _width * _height;
}

std::string DungeonLevel::name() {
    return _name;
}

std::string DungeonLevel::description() {
    std::stringstream ss;
    ss << _name <<
          "Size: " << _width << " x " << _height <<
          "Type: ";
    std::string description{ss.str()};
}

std::vector<std::string> DungeonLevel::display() {

}

}
