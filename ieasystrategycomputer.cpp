#include "ieasystrategycomputer.h"
#include <QDebug>

IEasyStrategyComputer::IEasyStrategyComputer()
{
}

int IEasyStrategyComputer::makeMove(QStringList field)
{
    //ищем свободные клетки
     QList <int> emptyCells = findCurrectCell(field);
     //выбираем рандомную пустую клетку чтобы заполнить ее
     if(emptyCells.isEmpty())
         return NULL;
     if(emptyCells.length()==1)
     {
         return emptyCells.at(0);
     }
     int i = QRandomGenerator::global()->bounded(emptyCells.length()-1);
     qDebug() <<"EasyStrategyComputer::makeMove";
     return emptyCells.at(i);
}
