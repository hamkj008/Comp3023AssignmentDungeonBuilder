#include "dungeonlevel.h"
#include <sstream>
#include <iostream>
#include <vector>
#include <string>
#include <sstream>


namespace core::dungeon {

DungeonLevel::DungeonLevel(std::string &name, int &width, int &height)
    :_name{name}, _width{width}, _height{height}, _dungeonDisplay{}, _rooms{}
{
    std::cout << "DungeonLevel created" << std::endl;
}

DungeonLevel::~DungeonLevel()
{
    std::cout << "DungeonLevel deleted" << std::endl;
}


bool DungeonLevel::addRoom(std::shared_ptr<Room>& room) {
    _rooms->push_back(room);
    return true;
}

Room* DungeonLevel::retrieveRoom(int &id) {

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
    int w = _width;
    std::stringstream ss{};

//    while(w > 0) {
//        for(std::size_t i{0}; i < _rooms.size(); i++) {
//            std::array<std::string, 5> roomDisplay = _rooms[i].display();
//            for(std::size_t i{0}; i < _rooms.size(); i++) {
//                ss << roomDisplay[i];
//            }
//        }
//        std::cout << r.display() << std::endl;
    }


//}

}
