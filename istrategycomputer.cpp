#include "istrategycomputer.h"
#include <QDebug>

IStrategyComputer::IStrategyComputer()
{

}

QList<int> IStrategyComputer::findCurrectCell(QStringList field)
{
    QList <int> emplyCells;
    for(int i=0; i<field.length();i++)
    {
        if (field.at(i).isEmpty() == true)
           emplyCells.append(i);
    }
     qDebug() <<"we are from IStrategyComputer::findCurrectCell";
     return emplyCells;
}
