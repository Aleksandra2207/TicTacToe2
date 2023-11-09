#ifndef MODATWOCOMPUTERS_H
#define MODATWOCOMPUTERS_H

#include <QObject>
#include <QWidget>
#include "gamemode.h"

class ModeTwoComputers: public GameMode
{
    Q_OBJECT
public:
    ModeTwoComputers(QString sign1, QString sign2, QString name1, QString name2, DifficultyLevel level1, DifficultyLevel level2);
    virtual void onStart() final;
    void otherConnections();
    virtual void onPassMoveToPlayer2() final;
    virtual void onPassMoveToPlayer1()final;

private:
     void delay();
};

#endif // MODATWOCOMPUTERS_H
