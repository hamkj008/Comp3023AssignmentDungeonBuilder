#include <iostream>
#include "magicaldungeonlevelbuilder.h"
#include "Core/dungeon/magical/magicaldungeonlevel.h"
#include "Core/creatures/monster.h"
#include "Core/dungeon/magical/alchemistslaboratory.h"
#include "Core/dungeon/magical/enchantedlibrary.h"
#include "Core/items/item.h"
#include "Core/items/weapon.h"
#include "Core/items/consumable.h"
#include "Core/game.h"


namespace core::dungeon::magical {

MagicalDungeonLevelBuilder::MagicalDungeonLevelBuilder()
    : _magicItemList{}, _magicCreatureList{}
{
    std::shared_ptr<core::items::Item> healthPotion = std::make_shared<core::items::Consumable>("Health Potion");
    _magicItemList.push_back(healthPotion);
    std::shared_ptr<core::items::Item> molotovCocktail = std::make_shared<core::items::Consumable>("Molotov Cocktail");
    _magicItemList.push_back(molotovCocktail);
    std::shared_ptr<core::items::Item> resistancePotion = std::make_shared<core::items::Consumable>("Resistance Potion");
    _magicItemList.push_back(resistancePotion);
    std::shared_ptr<core::items::Item> boomerang = std::make_shared<core::items::Weapon>("Boomerang");
    _magicItemList.push_back(boomerang);
    std::shared_ptr<core::items::Item> wizardsStaff = std::make_shared<core::items::Weapon>("Wizards Staff");
    _magicItemList.push_back(wizardsStaff);
    std::shared_ptr<core::items::Item> magicWand = std::make_shared<core::items::Weapon>("Magic Wand");
    _magicItemList.push_back(magicWand);

    std::shared_ptr<core::creatures::AbstractCreature> goblin = std::make_shared<core::creatures::Monster>("Goblin");
    _magicCreatureList.push_back(goblin);
    std::shared_ptr<core::creatures::AbstractCreature> evilWizard = std::make_shared<core::creatures::Monster>("Evil Wizard");
    _magicCreatureList.push_back(evilWizard);
    std::shared_ptr<core::creatures::AbstractCreature> dragon = std::make_shared<core::creatures::Monster>("Dragon");
    _magicCreatureList.push_back(dragon);

}
void MagicalDungeonLevelBuilder::buildDungeonLevel(std::string name, int width, int height) {
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

    _dungeonLevel = std::make_shared<MagicalDungeonLevel>(name, width, height);

   std::cout << "number of rooms " << _dungeonLevel->numberOfRooms() << std::endl;

   int i{0};
   while(i < _dungeonLevel->numberOfRooms()) {
       std::shared_ptr<Room> room = buildRoom(i);
       _dungeonLevel->addRoom(room);
       std::cout << "after room" << std::endl;
       std::cout << room->id() << std::endl;
       i++;
   }
}

std::shared_ptr<Room> MagicalDungeonLevelBuilder::buildRoom(int id) {
    double randomDouble = Game::instance()->randomDouble();
    std::shared_ptr<Room> room;

    if(randomDouble > 0.2) {
        room = std::make_shared<EnchantedLibrary>(id);
    }
    else {
        room = std::make_shared<AlchemistsLaboratory>(id);
    }
    return room;
}

void MagicalDungeonLevelBuilder::buildDoorway(std::shared_ptr<Room> &origin,
     std::shared_ptr<Room> &destination, Room::Direction direction, MoveConstraints constraints) {

}

void MagicalDungeonLevelBuilder::buildEntrance(std::shared_ptr<Room> &room, Room::Direction direction) {

}

void MagicalDungeonLevelBuilder::buildExit(std::shared_ptr<Room> &room, Room::Direction direction) {

}

void MagicalDungeonLevelBuilder::buildItem(std::shared_ptr<Room> &room) {
    double randomDouble = Game::instance()->randomDouble();
    int max = 5;
    int min = 0;
    int randomItemNum = randomDouble * ((max + 1) - min) + min;
    std::cout << "range 0 - 5 " << randomItemNum << std::endl;

    std::shared_ptr<core::items::Item> newItem = _magicItemList[randomItemNum]->clone();

    room->setItem(newItem);
}

void MagicalDungeonLevelBuilder::buildCreature(std::shared_ptr<Room> &room, bool isBoss) {
    double randomDouble = Game::instance()->randomDouble();
    int max = 2;
    int min = 0;
    int randomCreatureNum = randomDouble * ((max + 1) - min) + min;
    std::cout << "range 0 - 2 " << randomCreatureNum << std::endl;

    std::shared_ptr<core::creatures::AbstractCreature> newCreature = _magicCreatureList[randomCreatureNum]->clone();
    newCreature->setBoss(isBoss);
    room->setCreature(newCreature);
}

}
