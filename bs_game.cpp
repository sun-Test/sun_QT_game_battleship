#include "bs_game.h"

bs_game::bs_game()
{
    initGame();
}
bs_game::~bs_game()
{
    deinitGame();
}
void bs_game::initGame()
{
    prvPSettings = new settings();
    prvPPlayer = new player();
    pubPHmi = new hmi();
    pubP_gameRound = new game_round(*prvPSettings, *prvPPlayer, *pubPHmi);
    connect(pubPHmi, hmi::inputPosition, prvPPlayer, player::getInputPosition);
    connect(prvPPlayer, player::fireAt, pubP_gameRound, game_round::getFiredAtPosition);
    connect(pubP_gameRound, game_round::getHit, pubPHmi, hmi::handleHitFire);
    connect(pubP_gameRound, game_round::getSunk, pubPHmi, hmi::handleSunkFire);
    connect(pubP_gameRound, game_round::multipleFired, pubPHmi, hmi::handleMultipleFired);
    connect(pubPHmi, hmi::requestGameRoundState, pubP_gameRound, game_round::checkGameRoundState);
    connect(pubP_gameRound, game_round::getFleetSunk, pubPHmi, hmi::handleFleetSunk);
    connect(pubP_gameRound, game_round::gameRoundState_finished, pubPHmi, hmi::handleGameRoundeFinished);
    connect(pubPHmi, hmi::requestGameRoundBoardState, pubP_gameRound, game_round::handleRequest_BoardState);
    connect(pubP_gameRound, game_round::reportBoardState, pubPHmi, hmi::handleReportBoardState);

    connect(pubPHmi, hmi::requestGameReset, this, bs_game::handleReset);
}

void bs_game::deinitGame()
{
    disconnect(pubPHmi, hmi::inputPosition, prvPPlayer, player::getInputPosition);
    disconnect(prvPPlayer, player::fireAt, pubP_gameRound, game_round::getFiredAtPosition);
    disconnect(pubP_gameRound, game_round::getHit, pubPHmi, hmi::handleHitFire);
    disconnect(pubP_gameRound, game_round::getSunk, pubPHmi, hmi::handleSunkFire);
    disconnect(pubP_gameRound, game_round::multipleFired, pubPHmi, hmi::handleMultipleFired);
    disconnect(pubPHmi, hmi::requestGameRoundState, pubP_gameRound, game_round::checkGameRoundState);
    disconnect(pubP_gameRound, game_round::getFleetSunk, pubPHmi, hmi::handleFleetSunk);
    disconnect(pubP_gameRound, game_round::gameRoundState_finished, pubPHmi, hmi::handleGameRoundeFinished);
    disconnect(pubPHmi, hmi::requestGameRoundBoardState, pubP_gameRound, game_round::handleRequest_BoardState);
    delete prvPSettings;
    delete prvPPlayer;
    delete pubPHmi;
    delete pubP_gameRound;
}

void bs_game::resetGame()
{
    deinitGame();
    initGame();
}

void bs_game::handleReset()
{
    resetGame();
    pubP_gameRound->startRound();
    pubPHmi->startService();
}

