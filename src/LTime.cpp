#include "LTime.h"

LTime::LTime()
{
    //ctor
    theTime = SDL_GetTicks();
    theMinute = 0;
    theHour = 0;
    theDay = 0;
    showDay =  "";
    showHour = "";
    showMinute = "";
    tState = TIME_CONTINUE;
}

LTime::~LTime()
{
    //dtor
}

void LTime::setTime()
{
    if(tState == TIME_CONTINUE)
    {
        theTime = SDL_GetTicks();
        Uint32 timeWithSecond = (theTime - sumStop)/1000 ;
        theDay = timeWithSecond/720;
        theHour = (timeWithSecond - theDay*720)/30;
        theMinute = (timeWithSecond - theDay*720)%30;
        theMinute*=2;
        if(theHour==0) skip(360);
        if(theDay<10) showDay = '0' + to_string(theDay);
        else showDay = to_string(theDay);
        if(theHour<10) showHour = '0' + to_string(theHour);
        else showHour = to_string(theHour);
        if(theMinute<10) showMinute = '0' + to_string(theMinute);
        else showMinute = to_string(theMinute);
    }

}

void LTime::start()
{
    if(tState != TIME_CONTINUE)
    {
        theTime = SDL_GetTicks();
        timeStart = theTime;
        tState = TIME_CONTINUE;
        sumStop += timeStart - timeStop;
    }
}

void LTime::stop()
{
    if(tState != TIME_STOP)
    {
        theTime = SDL_GetTicks();
        timeStop = theTime;
        tState = TIME_STOP;
    }
}

void LTime::skip(int minute)
{
    sumStop-=(minute/2)*1000;
}
