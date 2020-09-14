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
    DungeonLevel(std::string &name, int &width, int &height);
    ~DungeonLevel();


    bool addRoom(std::shared_ptr<Room> &room);
    Room* retrieveRoom(int &id);
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

    std::vector<std::string> _dungeonDisplay;
    std::vector<std::shared_ptr<Room>>* _rooms;
};
}
#endif // DUNGEONLEVEL_H
