#include <iostream>
#include <iostream>
#include <string>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

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
    Button again(17*30,13*30,4*30,3*30);
    Button getOut(25*30,13*30,4*30,3*30);
    bool out = false;

    while(!out)
    {
        if(!init(window,renderer,SCREEN_WIDTH,SCREEN_HEIGHT,WINDOW_TITLE))
        {
            cout<<"Init Fail"<<endl;
        }
        else
        {
            Gallery gallery(renderer);
            gallery.loadGallery();
            SDL_Event e;
            bool quit = false;

            map<string,Button> theButton;
            setButtons(theButton);

            map<string,Text> theText;
            setTexts(theText,renderer);

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
                        case SDLK_UP:

                            break;
                        case SDLK_DOWN:

                            break;
                        case SDLK_RIGHT:
                            theTime.skip(30);
                            break;
                        }
                    }
                    if(again.handleEvent(&e)) {quit=true;out=false;}
                    if(getOut.handleEvent(&e)){quit=true;out=true;}
                    handleAllButton(theButton,&e,theGame,theShop,theTime);
                }



//                Text showHungry(renderer," ",50);
//                string  hung = to_string(theGame.getCatFull())+'\n'+to_string(theGame.getCatPoo()) +
//                '\n' + "CatFood: " + to_string(theGame.getCatFood()) + '\n' + "Health: " + to_string(theGame.getCatHealth())
//                + '\n' + "Shit: " + to_string(theGame.getShit());
//                showHungry.setText(hung);
//
//                renderTexture(0,75,100,100,showHungry.getText(),renderer);
//                showHungry.freeText();





                renderEveryThing(theGame,gallery,renderer,theTime,theButton,theText,theShop,again,getOut);
                for(int i=0;i<9;i++)
                {
                    SDL_SetRenderDrawColor(renderer,0,0,0,255);
                    SDL_RenderDrawLine(renderer,FLOOR_X+i*80,0,FLOOR_X+i*80,SCREEN_HEIGHT);
                }
                for(int i=0;i<6;i++)
                {
                    SDL_SetRenderDrawColor(renderer,0,0,0,255);
                    SDL_RenderDrawLine(renderer,0,WALL_HEIGHT+i*80,SCREEN_WIDTH,WALL_HEIGHT+i*80);
                }
                SDL_RenderPresent(renderer);
            }
            freeTexts(theText);
            close(window,renderer);
        }
    }
    cout<<"end"<<endl;
    return 0;
}
