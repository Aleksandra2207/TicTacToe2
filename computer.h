#ifndef COMPUTER_H
#define COMPUTER_H

#include <QObject>
#include <QWidget>
#include <QPushButton>
#include "players.h"
#include "ieasystrategycomputer.h"

class Computer: public Players
{
    Q_OBJECT
public:
    Computer();
    void makeMove (QStringList field) final;
   virtual void setStrategy (IStrategyComputer* strategy) final;

};

#endif // COMPUTER_H
