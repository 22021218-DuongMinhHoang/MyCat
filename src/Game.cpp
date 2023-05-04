#include "Game.h"

Game::Game()
{
    //ctor
    myCat.setPos(getRandomPos());
    myHouse.setCellJob(2,3,CELL_FOOD);
    myHouse.setCellJob(5,5,CELL_LITTER);
}

Game::~Game()
{
    //dtor
    delete &myHouse;
    delete &myCat;
    delete &Astar;
}

void Game::catMoreFull(int n)
{
    myCat.moreFull(n);
}

void Game::catGetHungry()
{
    Uint32 timer = SDL_GetTicks();
    if((timer/1000)%2==0 && timer - timeHungry >= 2000 && !myCat.getIsFull() && myCat.getCatMove()!=CAT_MOVE_SLEEP)
    {
        myCat.moreFull(-1);
        timeHungry = timer;
        if(myCat.getFull()<=0) myCat.moreHealth(myCat.getFull()*2);
    }
    if(myCat.getFull()<=50 && !isMoving) {gCat = GAME_CAT_GOTOEAT;}

}

void Game::catWantPoo()
{
    Uint32 timer = SDL_GetTicks();
    if((timer/1000)%1==0 && timer - timeFeelPoo >= 1000 && myCat.getIsFull() && myCat.getCatMove()!=CAT_MOVE_SLEEP)
    {
        myCat.morePoo(1);
        timeFeelPoo = timer;
        if(myCat.getPoo()>=50) myCat.moreHealth(-myCat.getPoo()/10);
    }
    if(myCat.getPoo()>=20 && !isMoving){ gCat = GAME_CAT_GOTOPOO;}

}

void Game::catGetSleepy(LTime theTime)
{
    if(theTime.getHourValue()>=22 && !isMoving){gCat = GAME_CAT_GOTOSLEEP;}
}

void Game::catGoToCell()
{
    if(Astar.ifPossible() && isMoving)
    {
        Astar.goToGoal(&myCat.getPos(),&goal,myCat,frame);
        if(myCat.getPos().x == goal.x && myCat.getPos().y == goal.y)
        {
            int timer = SDL_GetTicks();
            switch(gCat)
            {
            case GAME_CAT_GOTOEAT:
                myCat.setCatMove(CAT_MOVE_EAT);
                break;
            case GAME_CAT_GOTOPOO:
                myCat.setCatMove(CAT_MOVE_POO);
                break;
            case GAME_CAT_GOTOSOMEWHERE:
                {
                    gCat = GAME_CAT_WAITING;
                    lastMove = timer;
                    isMoving = false;
                    break;
                }
            case GAME_CAT_GOTOSLEEP:

                myCat.setCatMove(CAT_MOVE_SLEEP);
                break;
            }
        }
    }
}

void Game::catEat()
{
    if(gCat == GAME_CAT_GOTOEAT && myCat.getCatMove()==CAT_MOVE_EAT)
    {
        int timer = SDL_GetTicks();
        if(bowlIsFull)
        {
            if(motionStop==0) {motionStop = timer;frame=0;}
            else if(motionStop!=0 && timer - motionStop >= 2400)
            {
                myCat.setFull(100);
                myCat.moreHealth(20);
                myCat.moreLove(10);

                myCat.setIsFull(true);
                setBowlIsFull(false);

                isMoving = false;

                motionStop = 0;
                lastMove=timer;

                gCat = GAME_CAT_WAITING;
                myCat.setCatMove(CAT_MOVE_NOTHING);
            }
        }
    }
}

void Game::catPoo()
{
    if(gCat == GAME_CAT_GOTOPOO && myCat.getCatMove()==CAT_MOVE_POO)
    {
        int timer = SDL_GetTicks();
        if(shitInBox<=5)
        {
            if(motionStop==0) {motionStop = timer;frame=0;}
            else if(motionStop!=0 && timer - motionStop >= 2400)
            {
                myCat.setPoo(0);
                myCat.moreHealth(10);

                myCat.setIsFull(false);
                shitInBox++;

                isMoving = false;

                motionStop = 0;
                lastMove=timer;

                gCat = GAME_CAT_WAITING;
                myCat.setCatMove(CAT_MOVE_NOTHING);
            }
        }
    }
}

void Game::catWakeup(LTime theTime)
{
    isMoving = false;
    gCat = GAME_CAT_WAITING;
    myCat.setCatMove(CAT_MOVE_NOTHING);

    motionStop = 0;
    int timer = SDL_GetTicks();
    lastMove=timer;

    canMakeVid = true;
    numPet=0;

    myCat.moreAge(theTime.getDayValue()/2);
    myCat.getSick();
}

SDL_Point Game::getRandomPos()
{
    int cellx = 6, celly =5;
    while(true)
    {
        cellx = randomNumber(0,8); celly = randomNumber(0,5);
        if(myHouse.getCellType(cellx,celly)!=CELL_OBSTACLE) break;
    }
    SDL_Point p = {turnToX(cellx),turnToY(celly)};
    return p;
}

void Game::setCellGoal(CELL_JOBS cj)
{
    int goalx = turnToX(myHouse.getCellJobX(cj)), goaly = turnToY(myHouse.getCellJobY(cj));
    goal = {goalx,goaly};
}

void Game::catMove()
{
    int timer = SDL_GetTicks();
    if(gCat != GAME_CAT_WAITING && !isMoving)
    {
        Astar.resetAlgorithm();
        switch(gCat)
        {
        case GAME_CAT_GOTOEAT:
            Astar.resetAlgorithm();
            setCellGoal(CELL_FOOD);
            Astar.findWay(myHouse.getAllCell(),&myCat.getPos(),&goal);
            isMoving = true;
            break;
        case GAME_CAT_GOTOPOO:
            Astar.resetAlgorithm();
            setCellGoal(CELL_LITTER);
            Astar.findWay(myHouse.getAllCell(),&myCat.getPos(),&goal);
            isMoving = true;
            break;
        case GAME_CAT_GOTOSLEEP:
            Astar.resetAlgorithm();
            goal = {turnToX(5),turnToY(0)};
            Astar.findWay(myHouse.getAllCell(),&myCat.getPos(),&goal);
            isMoving = true;
            break;
        }
    }
    else if(timer - lastMove >= 15000 && gCat == GAME_CAT_WAITING && !isMoving)
    {
        int chance = randomNumber(1,10);
        if(chance<=5)
        {
            Astar.resetAlgorithm();
            goal = getRandomPos();
            gCat = GAME_CAT_GOTOSOMEWHERE;
            Astar.findWay(myHouse.getAllCell(),&myCat.getPos(),&goal);
        }
        else gCat = GAME_CAT_DOSTH;
        isMoving = true;
    }
    if(isMoving && (gCat==GAME_CAT_GOTOEAT||gCat==GAME_CAT_GOTOPOO||gCat==GAME_CAT_GOTOSLEEP||gCat==GAME_CAT_GOTOSOMEWHERE)) {catGoToCell();}
    else if(isMoving && gCat==GAME_CAT_DOSTH)
    {
        catSomething();
    }
    catPet();
    catExcercise();
    catPill();
}

void Game::catSomething()
{
    int chance = randomNumber(1,9);
    if(catDo==CAT_DO_OTHER)
    {
        if(chance<=3) catDo = CAT_DO_LICK;
        else if(chance<=6) catDo = CAT_DO_LIEDOWN;
        else catDo = CAT_DO_MYDIEU;
    }
    int timer = SDL_GetTicks();
    if(motionStop==0) {motionStop = timer;frame=0;}
    else if(motionStop!=0 && timer - motionStop >= 2400)
    {
        isMoving = false;

        motionStop = 0;
        lastMove=timer;

        gCat = GAME_CAT_WAITING;
        myCat.setCatMove(CAT_MOVE_NOTHING);

        catDo = CAT_DO_OTHER;
    }
}



void Game::pet()
{
    if(gCat == GAME_CAT_WAITING && !isMoving)
    {
        numPet++;
        if(numPet<=3)
        {
            isMoving = true;
            gCat = GAME_CAT_PET;
        }
        else myCat.moreLove(-5);
    }
}

void Game::catPet()
{
    if(isMoving && gCat==GAME_CAT_PET)
    {
        int timer = SDL_GetTicks();
        if(motionStop==0) {motionStop = timer;frame=0;}
        else if(motionStop!=0 && timer - motionStop >= 2400)
        {
            myCat.moreLove(10);

            isMoving = false;

            motionStop = 0;
            lastMove=timer;

            gCat = GAME_CAT_WAITING;
            myCat.setCatMove(CAT_MOVE_NOTHING);
        }
    }
}

void Game::excercise()
{
    if(gCat == GAME_CAT_WAITING && !isMoving)
    {
        isMoving = true;
        gCat = GAME_CAT_EXCERCISE;
    }
}

void Game::catExcercise()
{
    if(isMoving && gCat==GAME_CAT_EXCERCISE)
    {
        int timer = SDL_GetTicks();
        if(motionStop==0) {motionStop = timer;frame=0;}
        else if(motionStop!=0 && timer - motionStop >= 2400)
        {
            myCat.moreFull(-40);
            myCat.moreHealth(10);

            isMoving = false;

            motionStop = 0;
            lastMove=timer;

            gCat = GAME_CAT_WAITING;
            myCat.setCatMove(CAT_MOVE_NOTHING);
        }
    }
}

void Game::pill(PILL p)
{
    if(gCat == GAME_CAT_WAITING && !isMoving)
    {
        isMoving = true;
        gCat = GAME_CAT_PILL;
        switch(p)
        {
        case PILL_E:
            if(pillE>0) {myCat.drinkPill(p);pillE--;}
            break;
        case PILL_P:
            if(pillP>0) {myCat.drinkPill(p);pillP--;}
            break;
        case PILL_Q:
            if(pillQ>0) {myCat.drinkPill(p);pillQ--;}
            break;
        case PILL_A:
            if(pillA>0) {myCat.drinkPill(p);pillA--;}
            break;
        case PILL_PQA:
            if(pillPQA>0) {myCat.drinkPill(p);pillPQA--;}
            break;
        }
    }
}

void Game::catPill()
{
    if(isMoving && gCat==GAME_CAT_PILL)
    {
        int timer = SDL_GetTicks();
        if(motionStop==0) {motionStop = timer;frame=0;}
        else if(motionStop!=0 && timer - motionStop >= 2400)
        {
            myCat.moreHealth(50);

            isMoving = false;

            motionStop = 0;
            lastMove=timer;

            gCat = GAME_CAT_WAITING;
            myCat.setCatMove(CAT_MOVE_NOTHING);
        }
    }
}

void Game::catStart(LTime& theTime)
{
    catGetHungry();
    catWantPoo();
    catGetSleepy(theTime);
    catMove();
    catEat();
    catPoo();
    makingVid(theTime);
    catSick();
}

void Game::openApp(PHONE_APP ap)
{
    if(gPhone == PHONE_APP_SCREEN)
    {
        switch(ap)
        {
        case PHONE_APP_MYMEO:
            gPhone = PHONE_APP_MYMEO;
            break;
        case PHONE_APP_MEOTIP:
            gPhone = PHONE_APP_MEOTIP;
            break;
        case PHONE_APP_ZOOTUBE:
            if(gPlace==GAME_PLACE_HOUSE && canMakeVid) gPhone = PHONE_APP_ZOOTUBE;
            break;
        case PHONE_APP_MAP:
            gPhone = PHONE_APP_MAP;
            break;
        }
    }
}

void Game::backToScreen()
{
    if(gPhone != PHONE_APP_SCREEN)
    {
        gPhone = PHONE_APP_SCREEN;
    }
}

void Game::goToShop(LTime& theTime)
{
    if(gPlace!=GAME_PLACE_SHOP && theTime.getHourValue()<21)
    {
        isMoving = false;
        gCat = GAME_CAT_WAITING;
        theTime.skip(30);
        Astar.resetAlgorithm();
        motionStop=0;
        if(bowlIsFull)
        {
            myCat.setFull(100);
            myCat.setIsFull(true);
            bowlIsFull = false;
        }
        else
        {
            myCat.moreFull(-20);
            myCat.setIsFull(false);
        }
        if(shitInBox>5)
        {
            myCat.morePoo(40);
            myCat.setIsFull(true);
        }
        else
        {
            myCat.setPoo(0);
            myCat.setIsFull(false);
            shitInBox++;
        }
        if(myCat.getIsSick()) myCat.moreHealth(-30);
        gPlace = GAME_PLACE_SHOP;
    }
}

void Game::goToWork(LTime& theTime)
{
    if(gPlace!=GAME_PLACE_WORK && ((theTime.getHourValue()>=8&&theTime.getHourValue()<=9) || (theTime.getHourValue()>=14&&theTime.getHourValue()<=15)))
    {
        isMoving = false;
        gCat = GAME_CAT_WAITING;
        Astar.resetAlgorithm();
        motionStop=0;
        gPlace = GAME_PLACE_WORK;
        if(bowlIsFull)
        {
            myCat.setFull(100);
            myCat.setIsFull(true);
            bowlIsFull = false;
        }
        else
        {
            myCat.moreFull(-20);
            myCat.setIsFull(false);
        }
        if(shitInBox>5)
        {
            myCat.morePoo(40);
            myCat.setIsFull(true);
        }
        else
        {
            myCat.setPoo(0);
            myCat.setIsFull(false);
            shitInBox++;
        }
        if(myCat.getIsSick()) myCat.moreHealth(-60);
    }
}

void Game::goToVet(LTime& theTime)
{
    if(gPlace!=GAME_PLACE_VET && theTime.getHourValue()<21 && money >= 200)
    {
        isMoving = false;
        gCat = GAME_CAT_WAITING;
        Astar.resetAlgorithm();
        motionStop=0;
        gPlace = GAME_PLACE_VET;
    }
}

void Game::goToHouse(LTime& theTime)
{
    if(gPlace!=GAME_PLACE_HOUSE)
    {
        theTime.skip(30);
        frame = 0;
        motionStop=0;
        lastMove = SDL_GetTicks();
        myCat.setPos(getRandomPos());
        myCat.setCatMove(CAT_MOVE_NOTHING);
        gPlace = GAME_PLACE_HOUSE;
        if(myCat.getIsSick()) myCat.moreHealth(-30);
    }
}

void Game::goToPlace(GAME_PLACE gp,LTime& theTime)
{
    if(gp!=gPlace)
    {
        switch(gp)
        {
        case GAME_PLACE_HOUSE:
            goToHouse(theTime);
            break;
        case GAME_PLACE_SHOP:
            goToShop(theTime);
            break;
        case GAME_PLACE_WORK:
            goToWork(theTime);
            break;
        case GAME_PLACE_VET:
            goToVet(theTime);
            break;
        }
    }
}

void Game::atWork(LTime& theTime)
{
    if(gPlace==GAME_PLACE_WORK)
    {
        int timer = SDL_GetTicks();
        if(motionStop==0) {motionStop = timer;}
        else if(motionStop!=0 && timer - motionStop >= 3000)
        {
            workTime++;
            money+= (10 + workTime)/5 + 10;
            theTime.skip(240);
            frame = 0;
            motionStop=0;
            lastMove = SDL_GetTicks();
            myCat.setPos(getRandomPos());
            myCat.setCatMove(CAT_MOVE_NOTHING);
            gPlace = GAME_PLACE_HOUSE;
        }
    }
}

void Game::atVet(LTime& theTime)
{
    if(gPlace==GAME_PLACE_VET)
    {
        int timer = SDL_GetTicks();
        if(motionStop==0) {motionStop = timer;}
        else if(motionStop!=0 && timer - motionStop >= 3000)
        {
            money-=200;
            myCat.drinkPill(PILL_PQA);
            myCat.moreHealth(70);
            myCat.setFull(100);
            myCat.setPoo(0);
            myCat.moreLove(30);
            myCat.setIsFull(false);

            theTime.skip(240);
            frame = 0;
            motionStop=0;
            lastMove = SDL_GetTicks();

            myCat.setPos(getRandomPos());
            myCat.setCatMove(CAT_MOVE_NOTHING);
            gPlace = GAME_PLACE_HOUSE;

        }
    }
}

void Game::makingVid(LTime& theTime)
{
    if(theTime.getHourValue()>=23) canMakeVid = false;
    if(gPhone==PHONE_APP_ZOOTUBE)
    {
        int timer = SDL_GetTicks();
        if(vidStop==0) {vidStop = timer;}
        else if(vidStop!=0 && timer - vidStop >= 3000)
        {
            vidStop = 0;
            money+=myCat.getHealth()/10+myCat.getLove()/5;
            theTime.skip(60);
            gPhone = PHONE_APP_SCREEN;
            canMakeVid = false;
        }
    }
}

void Game::catSick()
{
    if(myCat.getIsSick())
    {
        int timer = SDL_GetTicks();
        if(timer - timeSick >= 1000)
        {
            myCat.moreHealth(-1);
            if(myCat.getSickP()) myCat.moreFull(-5);
            if(myCat.getSickQ()) myCat.morePoo(5);
            if(myCat.getSickA()) myCat.moreHealth(-2);
            timeSick = timer;
        }
    }
}
