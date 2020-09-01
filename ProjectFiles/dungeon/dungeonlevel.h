#ifndef DUNGEONLEVEL_H
#define DUNGEONLEVEL_H

#include <string>
#include "room.h"


class DungeonLevel
{
public:
    DungeonLevel(std::string name, int width, int height);


    bool addRoom(Room);
    Room retrieveRoom(int);
    int width();
    int height();
    int numberOfRooms();
    std::string name();
    virtual std::string description();
    virtual std::string display();

private:
    int _width;
    int _height;
    int _numberOfRooms;
    std::string _name;

};

#endif // DUNGEONLEVEL_H
