#ifndef PLAYERS_H
#define PLAYERS_H

#include <QObject>
#include <QWidget>
#include "istrategycomputer.h"

class Players: public QObject
{
    Q_OBJECT
public:
    Players();
    void setSign(QString sign);
    virtual void makeMove (QStringList field)= 0;
    virtual void setStrategy (IStrategyComputer* strategy);
signals:
    void finishMove(int cell, QString sign);
protected:
    QString _mySign;
    IStrategyComputer* _pStrategyComputer;
};

#endif // PLAYERS_H
