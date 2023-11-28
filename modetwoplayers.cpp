#include "modetwoplayers.h"

void ModeTwoPlayers::onStart()
{
    _countNoEmptyCell = 0;
    _ch=2;
    if(_player1Sign=="X")
    {
        game->onPassPlayer1Move(_isPlayer1IsComputer);
    }
    if(_player2Sign=="X")
    {
        game->onPassPlayer2Move(_isPlayer2IsComputer);
    }
}

ModeTwoPlayers::ModeTwoPlayers(QString sign1, QString sign2, QString name1, QString name2, DifficultyLevel level1, DifficultyLevel level2)
{
    _player1Sign = sign1;
    _player2Sign = sign2;
    game = new MainWindow();
    winnerWindow = new WinnerWindow();
    game->setPlayersName(name1, name2);
    game->onSetSingPlayers(sign1,sign2);
    _pPlayer1 = _playersFactory.createPlayer(person, level1);
    _pPlayer2 = _playersFactory.createPlayer(person, level2);
    _isPlayer1IsComputer=false;
    _isPlayer2IsComputer=false;
    _pPlayer1->setSign(_player1Sign);
    _pPlayer2->setSign(_player2Sign);
    connections();
    game->show();
}

void ModeTwoPlayers::onPassMoveToPlayer2()
{
    game->onPassPlayer2Move(_isPlayer2IsComputer);
}

void ModeTwoPlayers::onPassMoveToPlayer1()
{
    game->onPassPlayer1Move(_isPlayer1IsComputer);
}
