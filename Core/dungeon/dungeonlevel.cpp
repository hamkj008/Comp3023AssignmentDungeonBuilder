#include "dungeonlevel.h"

#include <vector>
#include <string>

using namespace std;

namespace core::dungeon {

DungeonLevel::DungeonLevel(std::string name, int width, int height)
    :_name{name}, _width{width}, _height{height}
{

}

bool DungeonLevel::addRoom(Room &room) {

}

Room DungeonLevel::retrieveRoom(int id) {

}

int DungeonLevel::width() {

}

int DungeonLevel::height() {

}

int DungeonLevel::numberOfRooms() {

}

std::string DungeonLevel::name() {

}

std::string DungeonLevel::description() {
    std::string description{"Example Dungeon Level \n"
                            "Size: " + static_cast<string>(_width) + _height};
}

std::vector<string> DungeonLevel::display() {

}

}
