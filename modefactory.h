#ifndef MODEFACTORY_H
#define MODEFACTORY_H
#include "gamemode.h"
#include "defins.h"

class ModeFactory
{
public:
    ModeFactory();
    GameMode* createMode(Modes id, QString sign1, QString sign2, QString name1, QString name2, DifficultyLevel level1, DifficultyLevel level2);

};

#endif // MODEFACTORY_H
