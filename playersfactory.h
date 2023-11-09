#ifndef PLAYERSFACTORY_H
#define PLAYERSFACTORY_H
#include "players.h"
#include "computer.h"
#include "person.h"
#include "defins.h"
#include "factorylevel.h"

class PlayersFactory
{
public:
    PlayersFactory();
    Players* createPlayer(playersType id, DifficultyLevel level);
//private:
//    FactoryLevel _factoryLevel;

};

#endif // PLAYERSFACTORY_H
