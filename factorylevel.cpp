#include "factorylevel.h"
#include "ieasystrategycomputer.h"

FactoryLevel::FactoryLevel()
{

}

IStrategyComputer* FactoryLevel::createLevel(DifficultyLevel id)
{
    switch(id)
    {
        case easyLevel: return new IEasyStrategyComputer ();
    }
    return nullptr;
}
