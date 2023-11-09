#ifndef ISTRATEGYCOMPUTER_H
#define ISTRATEGYCOMPUTER_H

#include <QObject>
#include <QWidget>

class IStrategyComputer: public QObject
{
    Q_OBJECT
public:
    IStrategyComputer();
    virtual int makeMove (QStringList field)= 0;
protected:
     QList <int> findCurrectCell(QStringList field);
};

#endif // ISTRATEGYCOMPUTER_H
