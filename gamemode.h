#ifndef GAMEMODE_H
#define GAMEMODE_H

#include <mainwindow.h>
#include <QObject>
#include <QWidget>
#include "winnerwindow.h"
#include "computer.h"
#include "welcomewindow.h"
#include "players.h"
#include "computer.h"
#include "person.h"
#include "playersfactory.h"



class GameMode: public QObject
{
    Q_OBJECT
public:
    GameMode();
    virtual void onStart() = 0;
    bool checkForFinish(QString value, QStringList field);
    virtual void onPassMoveToPlayer2();
    virtual void onPassMoveToPlayer1();
    void connections();

public slots:
        void onFinish(QString winner);
        virtual void onNewGame();
        void onCheckForFinish(QStringList cells, QString player);

signals:
    void Player2Move();
    void Player1Move();
    void finish(QString winner);
    void player1MoveIsComplited();
    void player2MoveIsComplited();

protected:
    MainWindow* game;
    Players* _pPlayer1;
    Players* _pPlayer2;
    bool _isPlayer1IsComputer;
    bool _isPlayer2IsComputer;
    PlayersFactory _playersFactory;
    FactoryLevel _factoryLevel;
    WinnerWindow* winnerWindow;
    int _ch=2;
    int _countNoEmptyCell=0;
    QString _player1Sign;
    QString _player2Sign;

};

#endif // GAMEMODE_H
