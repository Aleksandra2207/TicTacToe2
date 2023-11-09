#include "modefactory.h"
#include "modetwoplayers.h"
#include "modetwocomputers.h"
#include "modeplayerwithcomputer.h"

ModeFactory::ModeFactory()
{

}

GameMode *ModeFactory::createMode(Modes id, QString sign1, QString sign2, QString name1, QString name2, DifficultyLevel level1, DifficultyLevel level2)
{
    switch(id)
    {
        case modeTwoPerson: return new ModeTwoPlayers(sign1, sign2, name1, name2, level1, level2);
        case modePerson_Computer:return new ModePlayerWithComputer(sign1, sign2, name1, name2, level1, level2);
        case modeTwoComputer:return new ModeTwoComputers(sign1, sign2, name1, name2, level1, level2);
    }
}
