#include <iostream>
#include "basicdungeonlevelbuilder.h"
#include "Core/dungeon/basic/rockchamber.h"
#include "Core/dungeon/basic/quartzchamber.h"
#include "Core/creatures/monster.h"
#include "Core/items/weapon.h"
#include "Core/items/consumable.h"
#include "Core/game.h"
#include "Core/dungeon/doorway.h"
#include "Core/dungeon/common/onewaydoor.h"
#include "Core/dungeon/common/opendoorway.h"
#include "Core/dungeon/basic/rockwall.h"


namespace core::dungeon::basic {

BasicDungeonLevelBuilder::BasicDungeonLevelBuilder()
    : _basicItemList{}, _basicCreatureList{}
{
    std::shared_ptr<core::items::Item> healthPotion = std::make_shared<core::items::Consumable>("Health Potion");
    _basicItemList.push_back(healthPotion);
    std::shared_ptr<core::items::Item> molotovCocktail = std::make_shared<core::items::Consumable>("Molotov Cocktail");
    _basicItemList.push_back(molotovCocktail);
    std::shared_ptr<core::items::Item> smokeBomb = std::make_shared<core::items::Consumable>("Smoke Bomb");
    _basicItemList.push_back(smokeBomb);
    std::shared_ptr<core::items::Item> boomerang = std::make_shared<core::items::Weapon>("Boomerang");
    _basicItemList.push_back(boomerang);
    std::shared_ptr<core::items::Item> shortSword = std::make_shared<core::items::Weapon>("Short Sword");
    _basicItemList.push_back(shortSword);
    std::shared_ptr<core::items::Item> battleAxe = std::make_shared<core::items::Weapon>("BattleAxe");
    _basicItemList.push_back(battleAxe);

    std::shared_ptr<core::creatures::AbstractCreature> goblin = std::make_shared<core::creatures::Monster>("Goblin");
    _basicCreatureList.push_back(goblin);
    std::shared_ptr<core::creatures::AbstractCreature> werewolf = std::make_shared<core::creatures::Monster>("Werewolf");
    _basicCreatureList.push_back(werewolf);
    std::shared_ptr<core::creatures::AbstractCreature> evilWizard = std::make_shared<core::creatures::Monster>("Evil Wizard");
    _basicCreatureList.push_back(evilWizard);

}

void BasicDungeonLevelBuilder::buildDungeonLevel(std::string name, int width, int height) {
    if(width < 1) {
        width = 1;
    }
    else if(width > 4) {
        width = 4;
    }
    if(height < 1) {
        height = 1;
    }
    else if(height > 4) {
        height = 4;
    }

    _dungeonLevel = new BasicDungeonLevel(name, width, height);

   std::cout << "number of rooms " << _dungeonLevel->numberOfRooms() << std::endl;

   int i{1};
   while(i <= _dungeonLevel->numberOfRooms()) {
       std::shared_ptr<Room> room = buildRoom(i);
       _dungeonLevel->addRoom(room);
       std::cout << room->id() << std::endl;
       i++;
   }
}

std::shared_ptr<Room> BasicDungeonLevelBuilder::buildRoom(int id) {
    double randomDouble = Game::instance()->randomDouble();
    std::shared_ptr<Room> room;

    if(randomDouble > 0.2) {
        room = std::make_shared<RockChamber>(id);
    }
    else {
        room = std::make_shared<QuartzChamber>(id);
    }
    return room;
}

void BasicDungeonLevelBuilder::buildDoorway(std::shared_ptr<Room> &origin, std::shared_ptr<Room> &destination, Room::Direction direction, MoveConstraints constraints) {



}

void BasicDungeonLevelBuilder::buildEntrance(std::shared_ptr<Room> &room, Room::Direction direction) {
    std::shared_ptr<RoomEdge> entrance = std::make_shared<core::dungeon::common::OneWayDoor>(true, false);
    room->setEdge(direction, entrance);
}

void BasicDungeonLevelBuilder::buildExit(std::shared_ptr<Room> &room, Room::Direction direction) {
    std::shared_ptr<RoomEdge> exit = std::make_shared<core::dungeon::common::OneWayDoor>(false, true);
    room->setEdge(direction, exit);
}

// Select a random item from the list
void BasicDungeonLevelBuilder::buildItem(std::shared_ptr<Room> &room) {
    double randomDouble = Game::instance()->randomDouble();
    int max = 5;
    int min = 0;
    int randomItemNum = randomDouble * ((max + 1) - min) + min;

    std::shared_ptr<core::items::Item> newItem = _basicItemList[randomItemNum]->clone();

    room->setItem(newItem);
}

void BasicDungeonLevelBuilder::buildCreature(std::shared_ptr<Room> &room, bool isBoss) {
    double randomDouble = Game::instance()->randomDouble();
    int max = 2;
    int min = 0;
    int randomCreatureNum = randomDouble * ((max + 1) - min) + min;

    std::shared_ptr<core::creatures::AbstractCreature> newCreature = _basicCreatureList[randomCreatureNum]->clone();
    newCreature->setBoss(isBoss);
    room->setCreature(newCreature);
}

}

