#ifndef GAME_H
#define GAME_H
#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <vector>
#include <ctime>
#include <algorithm>
#include "../const.h"
#include "Cell.h"
#include "Cat.h"
#include "LTime.h"
#include "Algorithm.h"
#include "House.h"
#include "gameFunc.h"


using namespace std;

//cat action
enum GAME_CAT
{
    GAME_CAT_GOTOEAT,
    GAME_CAT_GOTOPOO,
    GAME_CAT_GOTOSOMEWHERE,
    GAME_CAT_WAITING,
    GAME_CAT_DOSTH,
    GAME_CAT_GOTOSLEEP,
    GAME_CAT_PET,
    GAME_CAT_EXCERCISE,
    GAME_CAT_PILL
};

//random thing the cat do
enum CAT_DO
{
    CAT_DO_OTHER,
    CAT_DO_MYDIEU,
    CAT_DO_LICK,
    CAT_DO_LIEDOWN
};

enum GAME_PLACE
{
    GAME_PLACE_HOUSE,
    GAME_PLACE_SHOP,
    GAME_PLACE_VET,
    GAME_PLACE_WORK
};

enum PHONE_APP
{
    PHONE_APP_MYMEO,
    PHONE_APP_MEOTIP,
    PHONE_APP_ZOOTUBE,
    PHONE_APP_MAP,
    PHONE_APP_SCREEN
};

enum GAME_STATE
{
    GAME_STATE_MENU,
    GAME_STATE_PLAY,
    GAME_STATE_OVER
};

//going to place
enum GO_TO
{
    GO_TO_SHOP,
    GO_TO_WORK,
    GO_TO_VET,
    GO_TO_HOUSE,
    GO_TO_NONE,
    GO_TO_GAME,
    GO_TO_END
};

enum GAME_TIME
{
    GAME_TIME_DAY,
    GAME_TIME_NIGHT,
    GAME_TIME_SLEEP
};

class Game
{
    public:
        Game();
        virtual ~Game();

        void catMoreFull(int n);
        void catGetHungry();
        void catWantPoo();
        void catGetSleepy(LTime theTime);
        void makingVid(LTime& theTime);

        int getCatFull(){return myCat.getFull();}
        int getCatPoo(){return myCat.getPoo();}
        int getCatFood(){return catFood;}
        int getCatHealth(){return myCat.getHealth();}
        int getCatLove(){return myCat.getLove();}
        int getCatAge(){return myCat.getAge();}
        int getShit(){return shitInBox;}
        int getMoney(){return money;}
        int getPillE(){return pillE;}
        int getPillP(){return pillP;}
        int getPillQ(){return pillQ;}
        int getPillA(){return pillA;}
        int getPillPQA(){return pillPQA;}
        int getNumPet(){return numPet;}

        void setBowlIsFull(bool yes){bowlIsFull=yes;}
        bool getBowlIsFull(){return bowlIsFull;}
        void fillBowl(){if(!bowlIsFull){bowlIsFull=true;catFood--;}}
        void takeShit(){if(shitInBox>0){shitInBox=0;}}

        SDL_Point getCellPos(CELL_JOBS cj)
        {
            SDL_Point f = {turnToX(myHouse.getCellJobX(cj)),turnToY(myHouse.getCellJobY(cj))};
            return f;
        }

        void catGoToCell();
        void catMove();
        void setCellGoal(CELL_JOBS cj);

        SDL_Point getRandomPos();

        SDL_Point getCatPos(){return myCat.getPos();}



        bool isInShop()
        {
            if(gPlace==GAME_PLACE_SHOP) return true;
            return false;
        }

        void buyFood(int num);
        void moreFood(int n){catFood+=n;}
        void morePillE(int num){pillE+=num;}
        void morePillP(int num){pillP+=num;}
        void morePillQ(int num){pillQ+=num;}
        void morePillA(int num){pillA+=num;}
        void morePillPQA(int num){pillPQA+=num;}
        void moreMoney(int n){money+=n;}

        DIRECTION getCatDirection(){return myCat.getDirection();}
        bool getIsMoving(){return isMoving;}

        CAT_MOVE getCatMove(){return myCat.getCatMove();}
        CAT_DO getCatDo(){return catDo;}
        GAME_CAT getGameCat(){return gCat;}

        void catEat();
        void catPoo();
        void catWakeup(LTime theTime);
        void catPet();
        void catExcercise();
        void catPill();
        void catSomething();
        void catSick();

        void catStart(LTime& theTime);

        void pet();
        void excercise();
        void pill(PILL p);
        bool getIsSick(){return myCat.getIsSick();}

        void openApp(PHONE_APP pa);
        void backToScreen();
        PHONE_APP getPhoneApp(){return gPhone;}

        void atWork(LTime& theTime);
        void atVet(LTime& theTime);
        void goToShop(LTime& theTime);
        void goToHouse(LTime& theTime);
        void goToWork(LTime& theTime);
        void goToVet(LTime& theTime);
        void goToPlace(GAME_PLACE gp,LTime& theTime);

        //animation frame
        int frame = 0;
        int frametime = 0;

        //making zootubevid frame
        int vidFrame = 0;
        int vidFrameTime = 0;

        //transition frame
        int transFrame = 34;
        int transFrameTime =0;
        int transTime=0;

        //for transition
        bool letGo = false,transition=false;
        GO_TO gTo=GO_TO_NONE;

        //game time
        GAME_TIME gTime = GAME_TIME_DAY;

        //place game
        GAME_PLACE getGamePlace(){return gPlace;}

        //game state
        GAME_STATE getGameState(){return gState;}
        void setGameState(GAME_STATE gs){gState=gs;}

        //endgame letter
        bool letter = false;

        void changeScene(LTime& theTime);
    private:
        Cat myCat;
        House myHouse;
        Algorithm Astar;
        Cell* go = nullptr;

        SDL_Point catcell = {0,0};
        SDL_Point goal = {0,0};

        int timeHungry = 0,timeFeelPoo = 0,timeSick=0;
        int motionStop = 0;
        int catFood = 5;
        int pillE = 0;
        int pillP = 0;
        int pillQ = 0;
        int pillA = 0;
        int pillPQA = 0;
        int lastMove = 0;
        int shitInBox = 0;
        int vidStop = 0;
        int numPet = 0;

        int money = 10;
        int workTime = 0;

        bool bowlIsFull = false;
        bool isMoving = false;
        bool canMakeVid = true;

        GAME_CAT gCat = GAME_CAT_WAITING;
        GAME_PLACE gPlace = GAME_PLACE_HOUSE;
        CAT_DO catDo = CAT_DO_OTHER;
        PHONE_APP gPhone = PHONE_APP_SCREEN;
        GAME_STATE gState = GAME_STATE_MENU;
};

#endif // GAME_H
