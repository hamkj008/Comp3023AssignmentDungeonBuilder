#ifndef DUNGEONLEVEL_H
#define DUNGEONLEVEL_H

#include "room.h"
#include <string>
#include <vector>



namespace core::dungeon {


class DungeonLevel
{
public:
    DungeonLevel();
    DungeonLevel(std::string name, int width, int height);


    bool addRoom(Room &room);
    Room retrieveRoom(int id);
    int width();
    int height();
    int numberOfRooms();
    std::string name();
    virtual std::string description();
    std::vector<std::string> display();

private:
    int _width;
    int _height;
    int _numberOfRooms;
    std::string _name;

};
}
#endif // DUNGEONLEVEL_H
