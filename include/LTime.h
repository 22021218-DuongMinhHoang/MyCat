#ifndef LTIME_H
#define LTIME_H
#include <iostream>
#include <string>
#include <SDL.h>

using namespace std;

enum TIME_STATE
{
    TIME_CONTINUE,
    TIME_STOP
};

class LTime
{
    public:
        LTime();
        virtual ~LTime();

        void setTime();

        string getDay(){return showDay;}

        string getHour(){return showHour;}

        string getMinute(){return showMinute;}

        int getMinuteValue(){return theMinute;}
        int getHourValue(){return theHour;}
        int getDayValue(){return theDay;}

        TIME_STATE getState(){return tState;}

        void start();
        void stop();
        void skip(int minute);

        void setState(TIME_STATE setst){tState = setst;}
        void moreSumStop(int n){sumStop+=n;}
    private:
        Uint32 theTime;

        Uint32 theMinute;

        Uint32 theHour;

        Uint32 theDay;

        string showDay,showHour,showMinute;
        float timeStart = 0, timeStop = 0, sumStop = 0;
        TIME_STATE tState;

};

#endif // LTIME_H
