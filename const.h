#ifndef CONST_H_INCLUDED
#define CONST_H_INCLUDED

const int SCREEN_WIDTH = 1365;
const int SCREEN_HEIGHT = 764;
const char WINDOW_TITLE[] = "MyCat";

const int BUTTON_SIZE = 60;
const int CELL_SIZE = 80;
const int CAT_SIZE = 100;

const int HOUSE_WIDTH = 720;
const int WALL_HEIGHT = 284;
const int FLOOR_HEIGHT = 480;
const int FLOOR_X = (SCREEN_WIDTH-HOUSE_WIDTH)/2;
const int FLOOR_Y = WALL_HEIGHT;

const int NUM_OF_CELL_X = HOUSE_WIDTH/CELL_SIZE;
const int NUM_OF_CELL_Y = FLOOR_HEIGHT/CELL_SIZE;



#endif // CONST_H_INCLUDED
