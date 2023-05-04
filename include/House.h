#ifndef HOUSE_H
#define HOUSE_H
#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <vector>
#include <ctime>
#include <algorithm>
#include "../const.h"
#include "Cell.h"

using namespace std;

class House
{
    public:
        House();
        virtual ~House();

        void setCellJob(int cellx,int celly,CELL_JOBS cj);
        CELL_TYPE getCellType(int cellx,int celly)
        {
            return allCell[celly][cellx].getType();
        }
        int getCellJobX(CELL_JOBS cj);
        int getCellJobY(CELL_JOBS cj);

        void setCellPoo(int cellx,int celly);

        vector<vector<Cell>> getAllCell(){return allCell;}
    private:
        vector<vector<Cell>> allCell;
        int cellFoodX=0,cellFoodY=0;
        int cellLitterX=0,cellLitterY=0;
};

#endif // HOUSE_H
