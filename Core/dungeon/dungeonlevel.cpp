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
    _rooms.push_back(room);
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
    std::stringstream ss{};
    std::array<std::string, 5> roomDisplay{};
    std::vector<std::string> dungeonDisplay{};

    int dungeonHeight{0};
    while(dungeonHeight < _height) {
        // Width
        for(std::size_t i{0}; i < roomDisplay.size(); ++i) {
            for(int j{0}; j < _width; ++j) {
                roomDisplay = _rooms[j]->display();
                ss << roomDisplay[i] << " ";

            }
            dungeonDisplay.push_back(ss.str());
            ss.str("");
        }
        dungeonHeight ++;
    }
    // Height
//     for(std::size_t i{0}; i < roomDisplay.size(); ++i) {
//         for(int j{0}; j < _height; ++j) {
//             roomDisplay = _rooms[j]->display();
//             ss << roomDisplay[i] << " ";
//         }
//         dungeonDisplay.push_back(ss.str());
//         ss.str("");
//     }
    for(std::string s : dungeonDisplay) {
        std::cout << s << std::endl;
    }
    return dungeonDisplay;
}


}
