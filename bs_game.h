#ifndef BS_GAME_H
#define BS_GAME_H
#include <QObject>
#include <settings.h>
#include <player.h>
#include <game_round.h>
#include <hmi.h>

class bs_game : public QObject
{
    Q_OBJECT
public:
    bs_game();
    ~bs_game();
    void initGame(void);
    void deinitGame(void);
    void resetGame(void);
    game_round* pubP_gameRound;
    hmi* pubPHmi;

public slots:
    void handleReset(void);
private:
    settings* prvPSettings;
    player* prvPPlayer;

};

#endif // BS_GAME_H
