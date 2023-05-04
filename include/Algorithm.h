#ifndef ALGORITHM_H
#define ALGORITHM_H
#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <vector>
#include <ctime>
#include <algorithm>
#include "../const.h"
#include "Cell.h"
#include "gameFunc.h"
#include "Cat.h"

using namespace std;

//set pos cat and goal,
//findway(vector cell,cat,goal),
//get to goal

class Algorithm
{
    public:
        Algorithm();
        virtual ~Algorithm();

        Cell* findBest();

        //void getAllCell();

        bool Astar();

        void openMoreCell(Cell* c);

        int findCellInVector(vector<Cell> vt,Cell c)
        {
            int length = vt.size();
            for(int i=0;i<length;i++)
            {
                if(vt[i].getx() == c.getx() && vt[i].gety() == c.gety())
                {
                    return i;
                }
            }
            return -1;
        }

        void setAlgorithm(SDL_Point start,SDL_Point finish)
        {
            catStart.x = start.x;
            catStart.y = start.y;
            goal.x = finish.x;
            goal.y = finish.y;
        }

        Cell* getRightWay(){return way;}

        int getNumOfHandleCell(HANDLE_CELL hc)
        {
            int num=0;
            for(int y = 0; y < NUM_OF_CELL_Y; y++)
            {
                for(int x = 0; x< NUM_OF_CELL_X; x++)
                {
                    if(allOfCell[y][x].getHandleCell()==hc) num++;
                }
            }
            return num;
        }

        void copyVector(vector<vector<Cell>> aoc,SDL_Point* cat, SDL_Point* finish);
        void findWay(vector<vector<Cell>> aoc,SDL_Point* cat, SDL_Point* finish);
        void goToGoal(SDL_Point* cat, SDL_Point* finish,Cat& theCat,int& frame);

        bool ifPossible(){return ok;}
        void setIsPossible(bool yes){ok=yes;}

        void resetAlgorithm();

    private:
        SDL_Point catStart ;
        SDL_Point goal;
        int goalCellx,goalCelly ;
        int catCellx,catCelly;

        int setime = 0;

        vector<vector<Cell>> allOfCell;
        bool ok = false;
        Cell* way;

};

#endif // ALGORITHM_H
