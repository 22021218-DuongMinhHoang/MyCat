#include <iostream>
#include <iostream>
#include <string>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>
#include <ctime>
#include <map>
#include "Texture.h"
#include "Button.h"
#include "Text.h"
#include "LTime.h"
#include "Game.h"
#include "Shop.h"

using namespace std;


int main(int argc, char* argv[])
{
    srand(time(0));
    SDL_Window* window = nullptr;
    SDL_Renderer* renderer = nullptr;

    Button again(17*30,13*30,4*30,3*30);//play again

    Button getOut(25*30,13*30,4*30,3*30);//quit game

    if(!init(window,renderer,SCREEN_WIDTH,SCREEN_HEIGHT,WINDOW_TITLE))
    {
        cout<<"Init Fail"<<endl;
    }
    else
    {
        bool out = false; //for play again
        while(!out)
        {
            SDL_Event e;
            bool quit = false;

            map<string,Button> theButton;
            setButtons(theButton);
            map<string,Text> theText;
            setTexts(theText,renderer);
            Gallery gallery(renderer);
            Shop theShop;
            LTime theTime;
            Game theGame;

            while(!quit)
            {
                SDL_SetRenderDrawColor(renderer,255,200,40,255);
                SDL_RenderClear(renderer);
                while(SDL_PollEvent(&e)!=0)
                {
                    if(e.type==SDL_QUIT) {quit = true;out=true;}
                    else if(e.type == SDL_KEYDOWN)
                    {
                        switch(e.key.keysym.sym)
                        {
                        case SDLK_ESCAPE:
                            quit = true;out=true;
                            break;
                        case SDLK_RIGHT:
                            theTime.skip(30);
                            break;
                        }
                    }
                    if(again.handleEvent(&e)&&theGame.getGameState()==GAME_STATE_OVER) {quit=true;out=false;}
                    if(getOut.handleEvent(&e)&&theGame.getGameState()==GAME_STATE_OVER){quit=true;out=true;}
                    handleAllButton(theButton,&e,theGame,theShop,theTime,gallery);
                }
                renderEveryThing(theGame,gallery,renderer,theTime,theButton,theText,theShop,again,getOut);
                SDL_RenderPresent(renderer);
            }
            freeTexts(theText);
            SDL_RenderClear(renderer);
            gallery.freeAll();
        }
        close(window,renderer);
    }
    return 0;
}
