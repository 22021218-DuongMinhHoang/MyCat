#ifndef SHOP_H
#define SHOP_H

#include <iostream>
#include <iostream>
#include <string>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <vector>
#include <ctime>
#include "Game.h"
#include "../const.h"

using namespace std;

class Shop
{
    public:
        Shop();
        virtual ~Shop();
        void pickFood(int num);
        void pickPillE(int num);
        void pickPillP(int num);
        void pickPillQ(int num);
        void pickPillA(int num);
        void pickPillPQA(int num);

        void resetShop();
        void buy(Game& theGame);

        int getFood(){return cFood;}
        int getPillE(){return pillE;}
        int getPillP(){return pillP;}
        int getPillQ(){return pillQ;}
        int getPillA(){return pillA;}
        int getPillPQA(){return pillPQA;}
        int getSumPrice(){return sumPrice;}

    private:
        int cFood = 0;
        int pillE = 0;
        int pillP = 0;
        int pillQ = 0;
        int pillA = 0;
        int pillPQA = 0;
        int sumPrice=0;
};

#endif // SHOP_H
