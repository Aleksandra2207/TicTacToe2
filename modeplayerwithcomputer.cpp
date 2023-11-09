#include "modeplayerwithcomputer.h"
#include <QTime>
#include <QCoreApplication>

ModePlayerWithComputer::ModePlayerWithComputer(QString sign1, QString sign2, QString name1, QString name2, DifficultyLevel level1, DifficultyLevel level2)
{
    _player1Sign = sign1;
    _player2Sign = sign2;
    game = new MainWindow();
    winnerWindow = new WinnerWindow();
    game->setPlayersName(name1, name2);
    game->onSetSingPlayers(sign1,sign2);
    _pPlayer1 = _playersFactory.createPlayer(person, level1);
    _pPlayer2 = _playersFactory.createPlayer(computer, level1);
    _pPlayer2->setStrategy(_factoryLevel.createLevel(level2));

    _isPlayer2IsComputer=true;
    _isPlayer1IsComputer=false;
    _pPlayer1->setSign(_player1Sign);
    _pPlayer2->setSign(_player2Sign);
    connections();
    otherConnections();
    game->show();
}

void ModePlayerWithComputer::onStart()
{
    _countNoEmptyCell = 0;
    _ch=2;
    //если человек выбрал X, то он ходит первым
    if(_player1Sign=="X")
    {
        game->onPassPlayer1Move(_isPlayer1IsComputer);
    }
    if(_player1Sign=="0")
    {
        game->onPassPlayer2Move(_isPlayer2IsComputer);
        _pPlayer2->makeMove(game->getField());
    }
}

void ModePlayerWithComputer:: otherConnections()
{
        connect(_pPlayer2, &Players::finishMove, game, &MainWindow::onMakeComputerMove);
}

void ModePlayerWithComputer::onPassMoveToPlayer2()
{
    game->onPassPlayer2Move(_isPlayer2IsComputer);
    delay();
    _pPlayer2->makeMove(game->getField());
}

void ModePlayerWithComputer::delay()
{
    QTime dieTime= QTime::currentTime().addSecs(1);
    while (QTime::currentTime() < dieTime)
        QCoreApplication::processEvents(QEventLoop::AllEvents, 2000);
}
