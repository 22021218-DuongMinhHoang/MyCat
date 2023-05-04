#include "Button.h"

Button::Button()
{
    //ctor
    bState = BUTTON_UP;
    bMouse = MOUSE_OUT;
    position.x = 0;
    position.y = 0;
    bWidth = BUTTON_SIZE;
    bHeight = BUTTON_SIZE;
}

Button::~Button()
{
    //dtor
}

Button::Button(int x,int y,int width,int height)
{
    bState = BUTTON_UP;
    bMouse = MOUSE_OUT;
    position.x = x;
    position.y = y;
    bWidth = width;
    bHeight = height;
}

bool Button::isMouseInButton()
{
    int mx,my;
    SDL_GetMouseState(&mx,&my);
    if(mx > position.x && mx < position.x + bWidth && my > position.y && my < position.y + bHeight)
    {
        bMouse = MOUSE_IN;
    }
    else bMouse = MOUSE_OUT;
    if(bMouse == MOUSE_IN) return true;
    return false;
}

bool Button::isButtonDown()
{
    if(bState == BUTTON_DOWN) return true;
    return false;
}

bool Button::handleEvent(SDL_Event* e)
{
    int mx,my;
    SDL_GetMouseState(&mx,&my);
    if(mx > position.x && mx < position.x + bWidth && my > position.y && my < position.y + bHeight)
    {
        bMouse = MOUSE_IN;
        if(e->type == SDL_MOUSEBUTTONDOWN)
        {
            bState = BUTTON_DOWN;
            return true;
        }
        else bState = BUTTON_UP;
    }
    else bMouse = MOUSE_OUT;
    return false;
}
