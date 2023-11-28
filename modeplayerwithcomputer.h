#ifndef MODEPLAYERWITHCOMPUTER_H
#define MODEPLAYERWITHCOMPUTER_H

#include <QObject>
#include <QWidget>
#include "gamemode.h"
#include "defins.h"
#include <QDebug>
#include "factorylevel.h"

class ModePlayerWithComputer: public GameMode
{
    Q_OBJECT
public:
    ModePlayerWithComputer(QString sign1, QString sign2, QString name1, QString name2, DifficultyLevel level1, DifficultyLevel level2);
    virtual void onStart() final;
    void otherConnections();
    virtual void onPassMoveToPlayer2() final;
private:
    void delay();


};

#endif // MODEPLAYERWITHCOMPUTER_H
