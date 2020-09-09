#ifndef DUNGEONLEVEL_H
#define DUNGEONLEVEL_H

#include "room.h"
#include <string>
#include <vector>



namespace core::dungeon {


class DungeonLevel
{
public:
    DungeonLevel(std::string &name, int &width, int &height);
    ~DungeonLevel();

    bool addRoom(Room &room);
    Room retrieveRoom(int &id);
    int width();
    int height();
    int numberOfRooms();
    std::string name();
    virtual std::string description();
    std::vector<std::string> display();

private:
    std::string _name;
    int _width;
    int _height;


};
}
#endif // DUNGEONLEVEL_H
