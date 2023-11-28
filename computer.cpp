#include "computer.h"
#include "QDebug"


Computer::Computer()
{
}

void Computer::makeMove(QStringList field)
{
    int i = _pStrategyComputer->makeMove(field);
    qDebug() <<"we are from Computer::makeMove";
    qDebug() << i << "\n";
    emit finishMove(i, _mySign);
}

void Computer::setStrategy(IStrategyComputer *strategy)
{
    _pStrategyComputer = strategy;
}

