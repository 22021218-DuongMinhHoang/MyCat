#ifndef GAMEFUNC_H
#define GAMEFUNC_H
#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <vector>
#include <ctime>
#include <algorithm>
#include "../const.h"

using namespace std;

int turnToCellX(int x);
int turnToCellY(int y);
int turnToX(int cellx);
int turnToY(int celly);

int randomNumber(int minnum,int maxnum);

bool isHighPlace(int cellx,int celly);
//vailoi
bool isPlaceNeedJump(int cellx,int celly);
#endif // GAMEFUNC_H
