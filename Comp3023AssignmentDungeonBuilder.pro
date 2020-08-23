TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        abstractcreature.cpp \
        basicdungeonlevelbuilder.cpp \
        consumable.cpp \
        doorway.cpp \
        dungeonlevel.cpp \
        dungeonlevelbuilder.cpp \
        game.cpp \
        item.cpp \
        magicaldungeonlevel.cpp \
        magicaldungeonlevelbuilder.cpp \
        main.cpp \
        menuinterface.cpp \
        monster.cpp \
        room.cpp \
        roomedge.cpp \
        weapon.cpp

DISTFILES += \
    Doxyfile

HEADERS += \
    abstractcreature.h \
    basicdungeonlevelbuilder.h \
    consumable.h \
    doorway.h \
    dungeonlevel.h \
    dungeonlevelbuilder.h \
    game.h \
    item.h \
    magicaldungeonlevel.h \
    magicaldungeonlevelbuilder.h \
    menuinterface.h \
    monster.h \
    room.h \
    roomedge.h \
    weapon.h
