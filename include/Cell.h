#ifndef CELL_H
#define CELL_H
#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <string>
#include <SDL_ttf.h>
#include <cmath>
#include "../const.h"

using namespace std;

enum CELL_TYPE
{
    CELL_START,
    CELL_GOAL,
    CELL_ROAD,
    CELL_OBSTACLE
};

enum HANDLE_CELL
{
    CELL_OPEN,
    CELL_CLOSE,
    CELL_NONE
};

enum CELL_JOBS
{
    CELL_FOOD,
    CELL_LITTER,
    CELL_NO_JOB
};
class Cell
{
    public:
        Cell();
        Cell(int x,int y){Pos.x = x; Pos.y = y;}
        Cell(SDL_Point p){Pos.x = p.x; Pos.y = p.y;}
        Cell& operator= (const Cell& );

        virtual ~Cell();

        void setx(int x){Pos.x = x;}
        void sety(int y){Pos.y = y;}
        void setPos(int x,int y){Pos.x = x; Pos.y = y;}
        void setPos(SDL_Point p) {Pos.x = p.x; Pos.y = p.y;}
        void setPos(){Pos.x = cellx*CELL_SIZE + CELL_SIZE/2 + FLOOR_X; Pos.y = celly*CELL_SIZE + CELL_SIZE/2 +FLOOR_Y;}

        void setCellxy(int x,int y){cellx=x;celly=y;}
        void setCellxy(){cellx = (Pos.x - CELL_SIZE/2 - FLOOR_X)/CELL_SIZE; celly = (Pos.y - CELL_SIZE/2 - FLOOR_Y)/CELL_SIZE;}

        void setg(SDL_Point p)
        { g=sqrt( pow(Pos.x-p.x,2) + pow(Pos.y-p.y,2) ); }
        void seth(SDL_Point p)
        {
            h=sqrt( pow(Pos.x-p.x,2) + pow(Pos.y-p.y,2) );
        }
        void setf()
        {
            f = g + h;
        }
        void setStat(SDL_Point goal,SDL_Point cat)
        {
            setg(goal); seth(cat); setf();
        }

        void setType(CELL_TYPE t){type = t;}
        void setJob(CELL_JOBS cj){cJob = cj;}
        CELL_JOBS getJob(){return cJob;}

        void setg(int n) {g = n;}
        void seth(int n) {h = n;}
        void setf(int n) {f = n;}

        int getx(){return Pos.x;}
        int gety(){return Pos.y;}
        SDL_Point getPos(){return Pos;}
        int geth(){return h;}
        int getg(){return g;}
        int getf(){return f;}
        CELL_TYPE getType(){return type;}


        int getCellx(){return cellx;}
        int getCelly(){return celly;}

        Cell* prev = nullptr;

        void setHandleCell(HANDLE_CELL hc){cHandle = hc;}
        HANDLE_CELL getHandleCell(){return cHandle;}
    private:
        int cellx=0,celly=0;
        SDL_Point Pos;
        HANDLE_CELL cHandle = CELL_NONE;
        CELL_TYPE type = CELL_ROAD;
        CELL_JOBS cJob = CELL_NO_JOB;
        //g: from cell to goal
        int g=0;
        //h: from cell to cat
        int h=0;
        //f: g + h
        int f=g+h;

};

#endif // CELL_H
