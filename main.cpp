#include <iostream>
#include <iostream>
#include <string>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <vector>
#include <ctime>
#include <map>
#include "Texture.h"
#include "Button.h"
#include "Text.h"
#include "Algorithm.h"
#include "LTime.h"
#include "Game.h"
#include "Shop.h"

using namespace std;


int main(int argc, char* argv[])
{
    srand(time(0));
    SDL_Window* window = nullptr;
    SDL_Renderer* renderer = nullptr;

    if(!init(window,renderer,SCREEN_WIDTH,SCREEN_HEIGHT,WINDOW_TITLE))
    {
        cout<<"Init Fail"<<endl;
    }
    else
    {
        int frametime = 0;
        Gallery gallery(renderer);
        SDL_Event e;
        bool quit = false;
        map<string,Button> theButton;
        map<string,Text> theText;
        setButtons(theButton);
        setTexts(theText,renderer);
        Button b;

        b.setPos(0,0);
        Shop theShop;
        LTime theTime;

        gallery.loadGallery();
        Game theGame;


        while(!quit)
        {

            SDL_SetRenderDrawColor(renderer,255,200,40,255);
            SDL_RenderClear(renderer);


            while(SDL_PollEvent(&e)!=0)
            {
                if(e.type==SDL_QUIT) quit = true;
                else if(e.type == SDL_KEYDOWN)
                {
                    switch(e.key.keysym.sym)
                    {
                    case SDLK_ESCAPE:
                        quit = true;
                        break;
                    case SDLK_UP:
                        theTime.start();
                        break;
                    case SDLK_DOWN:
                        theTime.stop();
                        break;
                    case SDLK_RIGHT:
                        theTime.skip(30);
                        break;
                    }
                }
                if(b.handleEvent(&e)){quit=true;}
                handleAllButton(theButton,&e,theGame,theShop,theTime);



            }

            theTime.setTime();

            renderNotePad(theGame,gallery,renderer,theTime,theText);


            theGame.atWork(theTime);
            theGame.atVet(theTime);
            if(theGame.getGamePlace()==GAME_PLACE_HOUSE)
            {
                renderHouse(theGame,gallery,renderer);
                theGame.catStart(theTime);
                renderCat(theGame,gallery,renderer,theTime,frametime);
            }

            else if(theGame.getGamePlace()==GAME_PLACE_SHOP)
            {
                renderShop(theGame,gallery,theShop,renderer,theText);
            }


            SDL_Rect rect = {b.getx(),b.gety(),BUTTON_SIZE,BUTTON_SIZE};
            if(b.isButtonDown())
            {
                SDL_SetRenderDrawColor(renderer,0,255,0,255);
            }
            else SDL_SetRenderDrawColor(renderer,255,0,0,255);
            SDL_RenderFillRect(renderer,&rect);

//            for(int i=0;i<45;i++)
//            {
//                SDL_SetRenderDrawColor(renderer,0,0,0,255);
//                SDL_RenderDrawLine(renderer,i*30,0,i*30,SCREEN_HEIGHT);
//            }
//            for(int i=0;i<25;i++)
//            {
//                SDL_SetRenderDrawColor(renderer,0,0,0,255);
//                SDL_RenderDrawLine(renderer,0,i*30,SCREEN_WIDTH,i*30);
//            }

            Text showHungry(renderer," ",50);
            string  hung = to_string(theGame.getCatFull())+'\n'+to_string(theGame.getCatPoo()) +
            '\n' + "CatFood: " + to_string(theGame.getCatFood()) + '\n' + "Health: " + to_string(theGame.getCatHealth())
            + '\n' + "Shit: " + to_string(theGame.getShit());
            showHungry.setText(hung);

            renderTexture(0,75,100,100,showHungry.getText(),renderer);
            showHungry.freeText();
            renderPhone(theGame,gallery,renderer,theTime,theText);
            renderAllButton(theButton,theGame,gallery,renderer);
            SDL_RenderPresent(renderer);

        }
        freeTexts(theText);
        close(window,renderer);
    }
    return 0;
}
