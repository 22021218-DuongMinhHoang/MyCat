#include "Algorithm.h"

Algorithm::Algorithm()
{
    //ctor

}

Algorithm::~Algorithm()
{
    //dtor
}

Cell* Algorithm::findBest()
{
    int minf = 10000, minx = goalCelly, miny = goalCellx, minh = 10000;

    for(int y = 0; y < NUM_OF_CELL_Y; y++)
    {
        for(int x = 0; x< NUM_OF_CELL_X; x++)
        {
            if(allOfCell[y][x].getHandleCell()==CELL_OPEN)
            {
                if(allOfCell[y][x].getf()<minf)
                {
                    minf = allOfCell[y][x].getf();
                    minx = x;
                    miny = y;
                }
                else if(allOfCell[y][x].getf() == minf)
                {
                    if(allOfCell[y][x].geth()<= minh)
                    {
                        minh = allOfCell[y][x].geth();
                        minx = x;
                        miny = y;
                    }
                }
            }
        }
    }
    return &allOfCell[miny][minx];
}

void Algorithm::openMoreCell(Cell* c)
{
    for(int i=0; i<4; i++)
    {
        int cx = 0,cy = 0;
        switch(i)
        {
        case 0:
            cx = c->getCellx() - 1;
            cy = c->getCelly();
            break;
        case 1:
            cx = c->getCellx();
            cy = c->getCelly() - 1;
            break;
        case 2:
            cx = c->getCellx() + 1;
            cy = c->getCelly();
            break;
        case 3:
            cx = c->getCellx();
            cy = c->getCelly() + 1;
            break;
        }
        if(cy<=5 && cy>=0 && cx>=0 && cx<=8)
        {
            Cell* newc = &allOfCell[cy][cx];
            if( newc->getType()!= CELL_OBSTACLE )
            {
                int px = c->getx(),qx = newc->getx(), py = c->gety(), qy = newc->gety(), dis = sqrt( pow(px-qx,2) + pow(py-qy,2));
                if(newc->getHandleCell()==CELL_CLOSE)
                {
                    if(newc->getg() > c->getg() + dis)
                    {
                        newc->setStat(goal,catStart);
                        newc->setHandleCell(CELL_OPEN);
                    }
                }
                else if(newc->getHandleCell()==CELL_OPEN)
                {
                    if(newc->getg() > c->getg() + dis)
                    {
                        newc->setStat(goal,catStart);
                        newc->setg(c->getg() + dis);
                        newc->setf();
                        newc->prev = c;
                    }
                }
                else if(newc->getHandleCell()==CELL_NONE)
                {
                    newc->setHandleCell(CELL_OPEN);
                    newc->setStat(goal,catStart);
                    newc->setg(c->getg() + dis);
                    newc->setf();
                    newc->prev = c;
                }
            }
        }

    }
}

bool Algorithm::Astar()
{
    allOfCell[goalCelly][goalCellx].setHandleCell(CELL_OPEN);
    while(getNumOfHandleCell(CELL_OPEN)!=0)
    {
        Cell* c = findBest();
        allOfCell[c->getCelly()][c->getCellx()].setHandleCell(CELL_CLOSE);
        if(c->getType()==CELL_START)
        {
            way = c;
            ok =true;
            return true;
        }
        else
        {
            openMoreCell(c);
            if(getNumOfHandleCell(CELL_OPEN)==0) {ok=false;return false;}
        }
    }
    return false;
}

void Algorithm::copyVector(vector<vector<Cell>> aoc,SDL_Point* cat, SDL_Point* finish)
{
    allOfCell.clear();
    for(int y = 0; y < NUM_OF_CELL_Y; y++)
    {
        vector<Cell> c;
        for(int x = 0; x< NUM_OF_CELL_X; x++)
        {
            c.push_back(aoc[y][x]);
        }
        allOfCell.push_back(c);
    }
    goal = { finish->x, finish->y };
    catStart = { cat->x, cat->y };
    goalCellx = (goal.x - CELL_SIZE/2 - FLOOR_X)/CELL_SIZE; goalCelly = (goal.y - CELL_SIZE/2 - FLOOR_Y)/CELL_SIZE;
    catCellx = (catStart.x - CELL_SIZE/2 - FLOOR_X)/CELL_SIZE; catCelly = (catStart.y - CELL_SIZE/2 - FLOOR_Y)/CELL_SIZE;
}

void Algorithm::findWay(vector<vector<Cell>> aoc,SDL_Point* cat, SDL_Point* finish)
{
    if(!ok)
    {
        copyVector(aoc,cat,finish);
        int cellcatx = turnToCellX(cat->x), cellcaty = turnToCellY(cat->y),
        cellgoalx = turnToCellX(finish->x), cellgoaly = turnToCellY(finish->y);

        allOfCell[cellgoaly][cellgoalx].setType(CELL_GOAL);
        allOfCell[cellcaty][cellcatx].setType(CELL_START);

        for(int y = 0; y < NUM_OF_CELL_Y; y++)
        {
            for(int x = 0; x< NUM_OF_CELL_X; x++)
            {
                allOfCell[y][x].setStat(*finish,*cat);
            }
        }

        Astar();
    }
}

void Algorithm::goToGoal(SDL_Point* cat, SDL_Point* finish,Cat& theCat,int& frame)
{
    int timer = SDL_GetTicks();
    if(ok)
    {
        if(way!=nullptr)
        {
            int cellx = turnToCellX(way->getx()),celly = turnToCellY(way->gety()),
            cellnowx=turnToCellX(cat->x),cellnowy=turnToCellY(cat->y);
            if(isPlaceNeedJump(cellnowx,cellnowy) || isHighPlace(cellx,celly) || isPlaceNeedJump(cellx,celly) || isHighPlace(cellnowx,cellnowy))
            {

                theCat.setCatMove(CAT_MOVE_JUMP);
            }
            else theCat.setCatMove(CAT_MOVE_WALK);
        }
        if( timer - setime>=15)
        {
            if(cat->x != way->getx())
            {
                if(way->getx() < cat->x) {cat->x-=1; theCat.changeDirection(DIRECTION_LEFT);}
                if(way->getx() > cat->x) {cat->x+=1; theCat.changeDirection(DIRECTION_RIGHT);}
            }
            if(cat->y != way->gety())
            {
                if(way->gety() < cat->y) {cat->y-=1; theCat.changeDirection(DIRECTION_UP);}
                if(way->gety() > cat->y) {cat->y+=1; theCat.changeDirection(DIRECTION_DOWN);}
            }
            setime = timer;
            if(cat->x == way->getx() && cat->y == way->gety() && way->prev!=nullptr ) {way = way->prev;frame=0;}
            if(cat->x == finish->x && cat->y == finish->y)
            {
                theCat.setCatMove(CAT_MOVE_NOTHING);
                resetAlgorithm();
            }
        }
    }
}

void Algorithm::resetAlgorithm()
{
    ok = false;
    allOfCell.clear();
    way = nullptr;
    setime = 0;
}
