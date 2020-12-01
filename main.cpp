#include <QCoreApplication>
#include <iostream>
#include <ship_2d.h>
#include <unordered_set>
#include <set>
#include <fleet.h>
#include <board2d.h>
#include <game_round.h>
#include <bs_game.h>
#include <hmi.h>

using namespace std;

bool Witness::enable_Witness=false;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    bs_game * pGame= new bs_game();

    pGame->pubP_gameRound->startRound();
    pGame->pubPHmi->startService();

    exit(0);

    return a.exec();
}

