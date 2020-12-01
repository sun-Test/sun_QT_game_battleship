QT += core
QT -= gui

TARGET = sunQT_Console_Battleship
CONFIG += console
CONFIG -= app_bundle

#CONFIG += c++11
QMAKE_CXXFLAGS += -std=c++17

TEMPLATE = app

SOURCES += main.cpp \
    ship_2d.cpp \
    board2d.cpp \
    fleet.cpp \
    bs_game.cpp \
    player.cpp \
    game_round.cpp \
    settings.cpp \
    witness.cpp \
    hmi.cpp

HEADERS += \
    ship_2d.h \
    board2d.h \
    fleet.h \
    bs_game.h \
    player.h \
    game_round.h \
    settings.h \
    witness.h \
    hmi.h

