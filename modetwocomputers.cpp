#include "modetwocomputers.h"
#include <QTime>
#include <QCoreApplication>


ModeTwoComputers::ModeTwoComputers(QString sign1, QString sign2, QString name1, QString name2, DifficultyLevel level1, DifficultyLevel level2)
{
    _player1Sign = sign1;
    _player2Sign = sign2;
    game = new MainWindow();
    winnerWindow = new WinnerWindow();
    game->setPlayersName(name1, name2);
    game->onSetSingPlayers(sign1,sign2);
    _pPlayer1 = _playersFactory.createPlayer(computer, level1);
    _pPlayer1->setStrategy(_factoryLevel.createLevel(level1));
    _pPlayer2 = _playersFactory.createPlayer(computer, level2);
    _pPlayer2->setStrategy(_factoryLevel.createLevel(level2));
    _isPlayer1IsComputer=true;
    _isPlayer2IsComputer=true;
    _pPlayer1->setSign(_player1Sign);
    _pPlayer2->setSign(_player2Sign);
    connections();
    otherConnections();
    game->show();
}

void ModeTwoComputers::onStart()
{
    _countNoEmptyCell = 0;
    _ch=2;

    if(_player1Sign=="X")
    {
        game->onPassPlayer1Move(_isPlayer1IsComputer);
        _pPlayer1->makeMove(game->getField());
    }
    if(_player1Sign=="0")
    {
        game->onPassPlayer2Move(_isPlayer2IsComputer);
        _pPlayer2->makeMove(game->getField());
    }
}

void ModeTwoComputers:: otherConnections()
{
    connect(_pPlayer2, &Players::finishMove, game, &MainWindow::onMakeComputerMove);
    connect(_pPlayer1, &Players::finishMove, game, &MainWindow::onMakeComputerMove);
}

void ModeTwoComputers::onPassMoveToPlayer2()
{
    game->onPassPlayer2Move(_isPlayer2IsComputer);
    delay();
    _pPlayer2->makeMove(game->getField());
}

void ModeTwoComputers::onPassMoveToPlayer1()
{
    game->onPassPlayer1Move(_isPlayer1IsComputer);
    delay();
    _pPlayer1->makeMove(game->getField());
}

void ModeTwoComputers::delay()
{
    QTime dieTime= QTime::currentTime().addSecs(1);
    while (QTime::currentTime() < dieTime)
        QCoreApplication::processEvents(QEventLoop::AllEvents, 2000);
}
