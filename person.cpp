#include "person.h"
#include <QDebug>

Person::Person()
{

}

void Person::makeMove(QStringList field)
{
    qDebug() << "we are from Person::makeMove";
}

void Person::setStrategy(IStrategyComputer *strategy)
{
    qDebug() << "we are from PPerson::setStrategy";
}
