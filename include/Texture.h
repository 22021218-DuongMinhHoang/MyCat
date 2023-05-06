#ifndef TEXTURE_H
#define TEXTURE_H

#include <iostream>
#include <string>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include "../const.h"
#include "Gallery.h"
#include "Game.h"
#include "Button.h"
#include "Text.h"
#include "Shop.h"

using namespace std;

bool init(SDL_Window* &window, SDL_Renderer* &renderer,int screenWidth, int screenHeight, const char* windowTitle);

void close(SDL_Window* window, SDL_Renderer* renderer);

void renderTexture(int x,int y,int width,int height,SDL_Texture* texture,SDL_Renderer* renderer);

void renderTexturefromTexture(int x,int y,int width,int height,
                              int mini_x,int mini_y,int mini_width,int mini_height,
                              SDL_Texture* texture,SDL_Renderer* renderer);

void setButtons(map<string,Button>& theButton);

void setTexts(map<string,Text>& theText,SDL_Renderer* renderer);

void freeTexts(map<string,Text>& theText);

void handleAllButton(map<string,Button>& theButton,SDL_Event* e,Game& theGame,Shop& theShop,LTime& theTime);

void renderButton(map<string,Button>& theButton,string buttonName,Gallery& theGallery,string picName,SDL_Renderer* renderer);

void renderButtonWithFrame(map<string,Button>& theButton,string buttonName,Gallery& theGallery,string picName,SDL_Renderer* renderer);

void renderAllButton(map<string,Button>& theButton,Game& theGame,Gallery& theGallery,SDL_Renderer* renderer);

void renderMenu(Game& theGame,Gallery& gallery,SDL_Renderer* renderer);

void renderGameOver(Game& theGame,Gallery& gallery,SDL_Renderer* renderer,map<string,Text>& theText,bool& letter,Button again,Button getOut);

void renderButtonOutline(Button theButton,int thick,SDL_Renderer* renderer);

void renderHouse(Game& theGame,Gallery& gallery,SDL_Renderer* renderer);

void renderWork(Game& theGame,Gallery& gallery,SDL_Renderer* renderer);

void renderVet(Game& theGame,Gallery& gallery,SDL_Renderer* renderer);

void renderCat(Game& theGame,Gallery& gallery,SDL_Renderer* renderer,LTime& theTime);

void renderShop(Game& theGame,Gallery& gallery,Shop& theShop,SDL_Renderer* renderer,map<string,Text>& theText);

void renderPhone(Game& theGame,Gallery& gallery,SDL_Renderer* renderer,LTime& theTime,map<string,Text>& theText);

void renderNotePad(Game& theGame,Gallery& gallery,SDL_Renderer* renderer,LTime& theTime,map<string,Text>& theText);

void renderTransition(Gallery& gallery,SDL_Renderer* renderer,Game& theGame);

void renderEveryThing(Game& theGame,Gallery& gallery,SDL_Renderer* renderer,LTime& theTime,map<string,Button>& theButton,map<string,Text>& theText,Shop& theShop,Button again,Button getOut);
#endif // TEXTURE_H
