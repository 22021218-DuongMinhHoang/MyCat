#ifndef CAT_H
#define CAT_H
#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <string>
#include <SDL_ttf.h>
#include <cmath>
#include "gameFunc.h"

using namespace std;

//cat direction
enum DIRECTION
{
    DIRECTION_UP,
    DIRECTION_DOWN,
    DIRECTION_RIGHT,
    DIRECTION_LEFT
};

//cat movement
enum CAT_MOVE
{
    CAT_MOVE_NOTHING,
    CAT_MOVE_WALK,
    CAT_MOVE_JUMP,
    CAT_MOVE_EAT,
    CAT_MOVE_POO,
    CAT_MOVE_SLEEP,
    CAT_MOVE_SOMETHING
};

//pill
enum PILL
{
    PILL_E,
    PILL_P,
    PILL_Q,
    PILL_A,
    PILL_PQA
};

class Cat
{
    public:
        Cat();
        virtual ~Cat();

        //all cat stat
        int getFull(){return mFull;}
        void setFull(int n){mFull = n;}
        void moreFull(int n){mFull += n;}

        int getLove(){return mLove;}
        void setLove(int n){mLove = n;}
        void moreLove(int n){mLove += n;}

        int getPoo(){return mPoo;}
        void setPoo(int n){mPoo = n;}
        void morePoo(int n){mPoo += n;}

        int getHealth(){return mHealth;}
        void setHealth(int n){mHealth = n;}
        void moreHealth(int n){mHealth += n;}

        int getAge(){return mAge;}
        void setAge(int n){mAge = n;}
        void moreAge(int n){mAge += n;}

        bool getIsFull(){return isFull;}
        void setIsFull(bool yes){isFull=yes;}

        bool getIsHungry(){return isHungry;}
        void setIsHungry(bool yes){isHungry=yes;}

        bool getIsSick(){return isSick;}
        bool getSickP(){return sickP;}
        bool getSickQ(){return sickQ;}
        bool getSickA(){return sickA;}

        //cat position
        void setPos(SDL_Point p){Pos.x = p.x; Pos.y = p.y;}
        void setPos(int x,int y){Pos.x = x; Pos.y = y;}

        int getx(){return Pos.x;}
        int gety(){return Pos.y;}

        SDL_Point& getPos(){return Pos;}

        //direction
        void changeDirection(DIRECTION d){dCat = d;}
        DIRECTION getDirection(){return dCat;}

        //cat movement
        void setCatMove(CAT_MOVE cm){cMove=cm;}
        CAT_MOVE getCatMove(){return cMove;}

        //sick and drink pill
        void getSick();
        void drinkPill(PILL p);

    private:
        SDL_Point Pos = {0,0};
        int mFull = 150;
        int mLove = 0;
        int mPoo = 0;
        int mHealth = 50;
        int mAge = 0;
        bool isFull = false;
        bool isHungry = false;
        DIRECTION dCat = DIRECTION_DOWN;
        CAT_MOVE cMove = CAT_MOVE_NOTHING;

        bool isSick = false;
        bool sickP = false;//hung fast
        bool sickQ = false;//poo fast
        bool sickA = false;//health down over time
};

#endif // CAT_H
