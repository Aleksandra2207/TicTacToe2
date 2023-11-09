#ifndef PERSON_H
#define PERSON_H

#include <QObject>
#include <QWidget>
#include "players.h"

class Person: public Players
{
    Q_OBJECT
public:
    Person();
    virtual void makeMove (QStringList field) final;
    virtual void setStrategy (IStrategyComputer* strategy) final;

};
#endif // PERSON_H
