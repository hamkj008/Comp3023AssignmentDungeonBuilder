#ifndef DUNGEONLEVEL_H
#define DUNGEONLEVEL_H

#include <string>
#include <vector>
#include "room.h"


namespace core::dungeon {


class DungeonLevel
{
public:
    DungeonLevel();
    DungeonLevel(std::string &name, int &width, int &height);
    virtual ~DungeonLevel();


    virtual bool addRoom(std::shared_ptr<Room> &room);
    virtual std::shared_ptr<Room> retrieveRoom(int id);
    virtual int width();
    virtual int height();
    virtual int numberOfRooms();
    virtual std::string name();
    virtual std::string description() const = 0;
    virtual std::vector<std::string> display();

private:
    std::string _name;
    int _width;
    int _height;

    std::vector<std::string> _dungeonDisplay;
    std::vector<std::shared_ptr<Room>> _roomList;
};
}
#endif // DUNGEONLEVEL_H
