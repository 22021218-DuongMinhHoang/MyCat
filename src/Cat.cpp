#include "Cat.h"

Cat::Cat()
{
    //ctor
}

Cat::~Cat()
{
    //dtor
}

void Cat::getSick()
{
    int chanceP = randomNumber(1,100);
    int chanceQ = randomNumber(1,100);
    int chanceA = randomNumber(1,100);
    if(chanceP <= 5 + mAge*20 - mHealth/20)
    {
        isSick = true;
        sickP = true;
    }
    if(chanceQ <= 5 + mAge*20 - mHealth/20)
    {
        isSick = true;
        sickQ = true;
    }
    if(chanceA <= 5 + mAge*20 - mHealth/20)
    {
        isSick = true;
        sickA = true;
    }
}

void Cat::drinkPill(PILL p)
{
    switch(p)
    {
        case PILL_A:
        {
            if(!sickA)
            {
                mHealth-=25;
            }
            else if(sickA)
            {
                mHealth+=10;
                sickA = false;
                if(!sickP && !sickQ) isSick = false;
            }
            break;
        }

        case PILL_P:
        {
            if(!sickP)
            {
                mHealth-=25;
            }
            else if(sickP)
            {
                mHealth+=10;
                sickP = false;
                if(!sickA && !sickQ) isSick = false;
            }
            break;
        }

        case PILL_Q:
        {
            if(!sickQ)
            {
                mHealth-=25;
            }
            else if(sickQ)
            {
                mHealth+=10;
                sickQ = false;
                if(!sickP && !sickA) isSick = false;
            }
            break;
        }

        case PILL_E:
        {
            mLove-=5;
            mHealth+=20;
            break;
        }

        case PILL_PQA:
        {
            mHealth+=25;
            sickA=false;
            sickP=false;
            sickQ=false;
            isSick=false;
        }
    }
}
