#include "Shop.h"

Shop::Shop()
{
    //ctor
}

Shop::~Shop()
{
    //dtor
}

void Shop::pickFood(int num)
{
    cFood+=num;sumPrice+=num;
}
void Shop::pickPillE(int num)
{
    pillE+=num;sumPrice+=num*15;
}
void Shop::pickPillP(int num)
{
    pillP+=num;sumPrice+=num*20;
}
void Shop::pickPillQ(int num)
{
    pillQ+=num;sumPrice+=num*20;
}
void Shop::pickPillA(int num)
{
    pillA+=num;sumPrice+=num*20;
}
void Shop::pickPillPQA(int num)
{
    pillPQA+=num;sumPrice+=num*30;
}

void Shop::resetShop()
{
    cFood = 0;
    pillE = 0;
    pillP = 0;
    pillQ = 0;
    pillA = 0;
    pillPQA = 0;
    sumPrice=0;
}

void Shop::buy(Game& theGame)
{
    if(theGame.getMoney()>=sumPrice && cFood>=0 && pillE>=0 && pillP>=0 && pillQ>=0 && pillA>=0 && pillPQA>=0)
    {
        theGame.moreMoney(-sumPrice);
        theGame.moreFood(cFood);
        theGame.morePillE(pillE);
        theGame.morePillP(pillP);
        theGame.morePillQ(pillQ);
        theGame.morePillA(pillA);
        theGame.morePillPQA(pillPQA);
        resetShop();
    }
}
