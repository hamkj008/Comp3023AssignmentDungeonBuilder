#include "dungeonlevel.h"
#include <sstream>
#include <iostream>
#include <vector>
#include <string>
#include <sstream>


namespace core::dungeon {

DungeonLevel::DungeonLevel(std::string &name, int &width, int &height)
    :_name{name}, _width{width}, _height{height}, _dungeonDisplay{}, _roomList{}
{
    std::cout << "DungeonLevel created" << std::endl;
}

DungeonLevel::~DungeonLevel()
{
    std::cout << "DungeonLevel deleted" << std::endl;
}


bool DungeonLevel::addRoom(std::shared_ptr<Room>& room) {
    _roomList.push_back(room);
    return true;
}

std::shared_ptr<Room> DungeonLevel::retrieveRoom(int id) {
    return _roomList[id - 1];
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
std::string  DungeonLevel::description() const {

}

std::vector<std::string> DungeonLevel::display() {
    std::stringstream ss{};
    std::array<std::string, 5> roomDisplay{};
    std::array<std::string, 5> rDisplay{};

    int dungeonHeight{};
    int start{};
    int end = _width;

    while(dungeonHeight < _height) {
        // Holds the number of lines in the room.
        for(std::size_t i{0}; i < roomDisplay.size(); ++i) {
            // appends each line in the row together depending on the width
            for(int j = start; j < end; ++j) {
                roomDisplay = _roomList[j]->display();
                ss << roomDisplay[i];
                if(i == 2) {
                    ss << "--";
                }
                else {
                    ss << "  ";
                }
            }
            _dungeonDisplay.push_back(ss.str());
            ss.str("");
        }
        ss << "+    |    +";
        _dungeonDisplay.push_back(ss.str());
        ss.str("");
        start += _width;
        end += _width;
        dungeonHeight ++;
    }

    return _dungeonDisplay;
}


}
