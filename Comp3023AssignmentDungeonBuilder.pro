TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        Core/dungeon/basic/basicdungeonlevelbuilder.cpp \
        Core/creatures/abstractcreature.cpp \
        Core/creatures/monster.cpp \
        Core/dungeon/basic/quartzchamber.cpp \
        Core/dungeon/basic/rockchamber.cpp \
        Core/dungeon/doorway.cpp \
        Core/dungeon/dungeonlevel.cpp \
        Core/dungeon/dungeonlevelbuilder.cpp \
        Core/dungeon/wall.cpp \
        Core/items/consumable.cpp \
        Core/game.cpp \
        Core/items/item.cpp \
        Core/dungeon/magical/magicaldungeonlevel.cpp \
        Core/dungeon/magical/magicaldungeonlevelbuilder.cpp \
        Core/main.cpp \
        Core/menuinterface.cpp \
        Core/dungeon/room.cpp \
        Core/dungeon/roomedge.cpp \
        Core/items/weapon.cpp

DISTFILES += \
    Doxyfile

HEADERS += \
    Core/dungeon/basic/basicdungeonlevelbuilder.h \
    Core/creatures/abstractcreature.h \
    Core/creatures/monster.h \
    Core/dungeon/basic/quartzchamber.h \
    Core/dungeon/basic/rockchamber.h \
    Core/dungeon/doorway.h \
    Core/dungeon/dungeonlevel.h \
    Core/dungeon/dungeonlevelbuilder.h \
    Core/dungeon/wall.h \
    Core/items/item.h \
    Core/items/consumable.h \
    Core/game.h \
    Core/dungeon/magical/magicaldungeonlevel.h \
    Core/dungeon/magical/magicaldungeonlevelbuilder.h \
    Core/menuinterface.h \
    Core/dungeon/room.h \
    Core/dungeon/roomedge.h \
    Core/items/weapon.h
