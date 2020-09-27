#ifndef DUNGEONLEVEL_H
#define DUNGEONLEVEL_H

#include <string>
#include <vector>
#include "room.h"


namespace core::dungeon {

/**
 * @brief The DungeonLevel class
 * The Dungeon Level class is the base class for all dungeon levels.
 * It holds the series of rooms and connections bewteen them, as well as the total output,
 * ready to be displayed.
 */
class DungeonLevel
{
public:
    DungeonLevel(std::string &name, int &width, int &height);
    virtual ~DungeonLevel();


    virtual bool addRoom(std::shared_ptr<Room> &room);
    virtual std::shared_ptr<Room> retrieveRoom(int id);
    virtual int width();
    virtual int height();
    virtual int numberOfRooms();
    virtual std::string name();
    virtual std::string description() const = 0;

    /**
     * @brief display
     * @return a vector of strings for each linne of the dungeon display
     */
    virtual std::vector<std::string> display();

    std::ostream& operator <<(std::ostream &display);

protected:
    std::string _name;
    int _width;
    int _height;

private:
    std::vector<std::string> _dungeonDisplay;
    std::vector<std::shared_ptr<Room>> _roomList;
};
}
#endif // DUNGEONLEVEL_H
