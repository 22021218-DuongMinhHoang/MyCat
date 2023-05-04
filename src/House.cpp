#include "House.h"

House::House()
{
    //ctor
    for(int y = 0; y < NUM_OF_CELL_Y; y++)
    {
        vector<Cell> vt;
        for(int x = 0; x< NUM_OF_CELL_X; x++)
        {

            Cell c;
            c.setCellxy(x,y);
            c.setPos();
            if((y==0 && (x!=3 || x!=5 || x!=6))||(y==2 && x==1)||(y==5 && (x==0 || x==1 || x==8))||(y==4 && x==8))
            {c.setType(CELL_OBSTACLE);}
            else c.setType(CELL_ROAD);
            c.setJob(CELL_NO_JOB);
            vt.push_back(c);
        }
        allCell.push_back(vt);
    }
    cellFoodX=0; cellFoodY=0;
}

House::~House()
{
    //dtor
}

void House::setCellJob(int cellx,int celly,CELL_JOBS cj)
{
    switch(cj)
    {
    case CELL_FOOD:
        allCell[celly][cellx].setJob(CELL_FOOD);
        cellFoodX = cellx; cellFoodY = celly;
        break;
    case CELL_LITTER:
        allCell[celly][cellx].setJob(CELL_LITTER);
        cellLitterX = cellx; cellLitterY = celly;
        break;
    }
}

int House::getCellJobX(CELL_JOBS cj)
{
    switch(cj)
    {
    case CELL_FOOD:
        return cellFoodX;
    case CELL_LITTER:
        return cellLitterX;
    }
    return 0;
}

int House::getCellJobY(CELL_JOBS cj)
{
    switch(cj)
    {
    case CELL_FOOD:
        return cellFoodY;
    case CELL_LITTER:
        return cellLitterY;
    }
    return 0;
}

