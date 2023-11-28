#ifndef MODETWOPLAYERS_H
#define MODETWOPLAYERS_H

#include <QObject>
#include <QWidget>
#include "gamemode.h"

class ModeTwoPlayers: public GameMode
{
    Q_OBJECT
public:
    virtual void onStart() final;
    ModeTwoPlayers(QString sign1, QString sign2, QString name1, QString name2, DifficultyLevel level1, DifficultyLevel level2);
    virtual void onPassMoveToPlayer2() final;
    virtual void onPassMoveToPlayer1()final;

};

#endif // MODETWOPLAYERS_H
