#ifndef FACTORYLEVEL_H
#define FACTORYLEVEL_H

#include <QObject>
#include <QWidget>
#include "defins.h"
#include "istrategycomputer.h"

class FactoryLevel
{
public:
    FactoryLevel();
    IStrategyComputer* createLevel(DifficultyLevel id);
};

#endif // FACTORYLEVEL_H
