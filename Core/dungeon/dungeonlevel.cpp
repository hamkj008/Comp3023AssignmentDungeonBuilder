#include "dungeonlevel.h"
#include <sstream>
#include <string>
#include "Core/dungeon/roomedge.h"


namespace core::dungeon {

DungeonLevel::DungeonLevel(std::string &name, int &width, int &height)
    :_name{name}, _width{width}, _height{height}, _dungeonDisplay{}, _roomList{}
{

}

DungeonLevel::~DungeonLevel()
{

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



std::vector<std::string> DungeonLevel::display() {
    // Concatenates each line of the row of the dungeon level
    std::stringstream stringstream{};
    // Holds the number of lines in the room.
    std::array<std::string, 5> roomDisplay{};
    // hstream is a container for displaying the connections between each height/row level in the dungeon.
    std::stringstream hstream{};

    int dungeonHeight{1};
    int start{};
    int end = _width;

    // Guard to stop the display from mulitplying if called again.
    if(_dungeonDisplay.size() == 0) {

        // dungeonHeight increments after each row has been completed.
        while(dungeonHeight <= _height) {
            // For each line of the room display
            for(std::size_t i{0}; i < roomDisplay.size(); ++i) {
                // appends the line of each room in the row together depending on the width
                for(int j = start; j < end; ++j) {
                    roomDisplay = _roomList[j]->display();
                    stringstream << roomDisplay[i];

                    // Appends the bridge connections between doors if there is a passage
                    // or puts a gap in between the rooms for each column.
                    if(_roomList[j]->id() < end) {
                        if(i == 2) {
                            if(_roomList[j]->getEdge(Room::Direction::East)->isPassage() == true){
                                stringstream << "--";
                            }
                            else {
                                stringstream << "  ";
                            }
                        }
                        else {
                            stringstream << "  ";
                        }
                    }
                    // Appends the bridge connections between doors if there is a passage
                    // or puts a gap in between the rooms for each row.
                    if(i == 4){
                        if(_roomList[j]->getEdge(Room::Direction::South)->isPassage() == true){
                            hstream << "     |     ";
                        }
                        else {
                            hstream << "           ";
                        }
                        if(_roomList[j]->id() < end) {
                            hstream << "  ";
                         }
                    }
                }
                // Adds each line to the total display
                _dungeonDisplay.push_back(stringstream.str());
                stringstream.str("");
            }
            // Once the lines of the room are done, adds an extra line for the row connections.
            if(dungeonHeight < _height){
                _dungeonDisplay.push_back(hstream.str());
                hstream.str("");
            }
            // Moves on to the next row by incrementing the next set of rooms.
            stringstream.str("");
            start += _width;
            end += _width;
            dungeonHeight ++;
        }
    }
    return _dungeonDisplay;
}


}
