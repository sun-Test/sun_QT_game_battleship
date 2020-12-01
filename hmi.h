#ifndef HMI_H
#define HMI_H
#include <QObject>
#include <string>
#include <iostream>
#include <regex>
#include <QDebug>
#include <ship_2d.h>

using namespace std;
class hmi : public QObject
{
    Q_OBJECT
public:
    hmi();
    void startService(void);
    bool parsePosition(string const &  strPosition);

public slots:
    void handleHitFire(bool bGetHit);
    void handleSunkFire(ship_2d const & cref_sunkShip);
    void handleMultipleFired(void);
    void handleFleetSunk(int iScore_in);
    void handleGameRoundeFinished(void);
    void handleReportBoardState(unordered_set<int> firedPositions, unordered_set<int> hitPositions, unordered_set<int> sunkPositions);


signals:
    void inputPosition(int id1, int id2);
    void requestGameRoundState(void);
    void requestGameRoundBoardState(void);
    void requestGameReset(void);

private:
    string prvStr_menu="menu: \n    quit: input 'q' \n    reset game: input 'r' \n    show board: input 's' \n    position format: one character (A-J) with a number (0-9), for instance: A5";
    const int prvI_HmiSize=10;
    const char prvC_unfiredPosition='X';
    const char prvC_firedPosition='F';
    const char prvC_hitPosition='H';
    const char prvC_sunkPosition='O';
};

#endif // HMI_H
