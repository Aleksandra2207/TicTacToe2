#ifndef IEASYSTRATEGYCOMPUTER_H
#define IEASYSTRATEGYCOMPUTER_H

#include "istrategycomputer.h"
#include <QRandomGenerator>


class IEasyStrategyComputer: public IStrategyComputer
{
public:
    IEasyStrategyComputer();
    virtual int makeMove (QStringList field) final;
};

#endif // IEASYSTRATEGYCOMPUTER_H
