#include "gameFunc.h"

int turnToCellX(int x){return (x - CELL_SIZE/2 - FLOOR_X)/CELL_SIZE;}
int turnToCellY(int y){return (y - CELL_SIZE/2 - FLOOR_Y)/CELL_SIZE;}
int turnToX(int cellx){return cellx*CELL_SIZE + CELL_SIZE/2 + FLOOR_X;}
int turnToY(int celly){return celly*CELL_SIZE + CELL_SIZE/2 + FLOOR_Y;}

int randomNumber(int minnum,int maxnum)
{
    int n=0;
    n = rand()%(maxnum - minnum + 1) + minnum;
    return n;
}

bool isHighPlace(int cellx,int celly)
{
    if(((cellx==5||cellx==6)&&celly==1)||(cellx==5&&celly==5)||(cellx==2&&celly==2)) return true;
    return false;
}

bool isPlaceNeedJump(int cellx,int celly)
{
    if( (celly==1&&(cellx==2||cellx==4||cellx==7)) || (celly==2&&(cellx==3||cellx==5||cellx==6)) || (celly==3&&celly==2) ||
        (celly==4&&cellx==5) || (celly==5&&(cellx==4||cellx==6)) )
    {
        return true;
    }
    return false;
}
