#ifndef BUTTON_H
#define BUTTON_H
#include <iostream>
#include <iostream>
#include <string>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include "../const.h"

using namespace std;

enum BUTTON_STATE
{
    BUTTON_DOWN,
    BUTTON_UP
};

enum MOUSE_IN_BUTTON
{
    MOUSE_IN,
    MOUSE_OUT
};

class Button
{
    public:
        Button();
        Button(int x,int y,int width,int height);
        virtual ~Button();

        bool isMouseInButton();
        bool isButtonDown();
        bool handleEvent(SDL_Event* e);

        void setPos(int x,int y) {position.x = x; position.y = y;}
        void setPos(SDL_Point p) {position.x = p.x; position.y = p.y;}

        void setButtonSize(int width,int height){bWidth = width; bHeight = height;}

        int getx() {return position.x;}
        int gety() {return position.y;}

        int getWidth(){return bWidth;}
        int getHeight(){return bHeight;}

    private:
        BUTTON_STATE bState;
        MOUSE_IN_BUTTON bMouse;
        SDL_Point position;
        int bWidth, bHeight;
};

#endif // BUTTON_H
