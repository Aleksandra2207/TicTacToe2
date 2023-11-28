#include "playersfactory.h"
#include <string.h>



PlayersFactory::PlayersFactory()
{
}

Players* PlayersFactory::createPlayer(playersType id, DifficultyLevel level)
{
    switch(id)
    {
        case person: return new Person();
        case computer: return new Computer();
    }
}
