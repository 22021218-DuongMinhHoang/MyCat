#include "Texture.h"

bool init(SDL_Window* &window, SDL_Renderer* &renderer,int screenWidth, int screenHeight, const char* windowTitle)
{
    bool success = true;
    if(SDL_Init(SDL_INIT_VIDEO)<0)
    {
        cout << "init error SDL_ERROR: " << SDL_GetError();
        success = false;
    }
    else
    {
        window=SDL_CreateWindow(windowTitle,SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,screenWidth,screenHeight,SDL_WINDOW_FULLSCREEN);
        if(window==nullptr)
        {
            cout<< "could not create window SDL_Error: " << SDL_GetError();
            success = false;
        }
        else
        {
            renderer=SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
            if(renderer==nullptr)
            {
                cout<< "could not create renderer SDL_Error: " << SDL_GetError();
                success=false;
            }
            else
            {
                SDL_SetRenderDrawColor(renderer,255,255,255,255);
                int flags = IMG_INIT_PNG;
                if(!IMG_Init(flags)&flags)
                {
                    cout << "could not init img IMG error: " << IMG_GetError();
                    success = false;
                }
                if(TTF_Init() == -1)
                {
                    cout << "could not init TTF error: " << TTF_GetError();
                    success = false;
                }
            }
        }
    }
    return success;
}

void close(SDL_Window* window, SDL_Renderer* renderer)
{
    SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	TTF_Quit();
    SDL_Quit();
    IMG_Quit();
    window = nullptr;
    renderer = nullptr;
}

void renderTexture(int x,int y,int width,int height,SDL_Texture* texture,SDL_Renderer* renderer)
{
    SDL_Rect rect = {x,y,width,height};
    SDL_RenderCopy(renderer,texture,NULL,&rect);
}

void renderTexturefromTexture(int x,int y,int width,int height,int mini_x,int mini_y,int mini_width,int mini_height,SDL_Texture* texture,SDL_Renderer* renderer)
{
    SDL_Rect rect = {x,y,width,height};
    SDL_Rect mini_rect = {mini_x,mini_y,mini_width,mini_height};
    SDL_RenderCopy(renderer,texture,&mini_rect,&rect);
}

void setButtons(map<string,Button>& theButton)
{
    theButton["menu"].setPos(0,0);

    theButton["fillBowl"].setPos(1080,60);
    theButton["shovel"].setPos(1170,60);
    theButton["pet"].setPos(1260,60);
    theButton["excercise"].setPos(1080,150);
    theButton["pillE"].setPos(1170,150);
    theButton["pillP"].setPos(1260,150);
    theButton["pillQ"].setPos(1080,240);
    theButton["pillA"].setPos(1170,240);
    theButton["pillPQA"].setPos(1260,240);

    theButton["myMeo"].setPos(60,330);
    theButton["meoTip"].setPos(180,330);
    theButton["ZooTube"].setPos(60,450);
    theButton["map"].setPos(180,450);

    theButton["shop"].setPos(60,300);
    theButton["vet"].setPos(60,390);
    theButton["work"].setPos(150,450);
    theButton["house"].setPos(240,450);

    theButton["homeButton"].setPos(120,570);
    theButton["appButton"].setPos(60,570);
    theButton["backButton"].setPos(210,570);

    theButton["minusFood"].setPos(24*30,4*30);
    theButton["plusFood"].setPos(26*30,4*30);
    theButton["minusFood10"].setPos(24*30,6*30);
    theButton["plusFood10"].setPos(26*30,6*30);
    theButton["minusFood100"].setPos(24*30,8*30);
    theButton["plusFood100"].setPos(26*30,8*30);
    theButton["minusPillE"].setPos(24*30,10*30);
    theButton["plusPillE"].setPos(26*30,10*30);
    theButton["minusPillP"].setPos(24*30,12*30);
    theButton["plusPillP"].setPos(26*30,12*30);
    theButton["minusPillQ"].setPos(24*30,14*30);
    theButton["plusPillQ"].setPos(26*30,14*30);
    theButton["minusPillA"].setPos(24*30,16*30);
    theButton["plusPillA"].setPos(26*30,16*30);
    theButton["minusPillPQA"].setPos(24*30,18*30);
    theButton["plusPillPQA"].setPos(26*30,18*30);
    theButton["buy"].setPos(32*30,18*30);

}

void setTexts(map<string,Text>& theText,SDL_Renderer* renderer)
{
    theText["food"].newText(renderer,"   ",100);
    theText["foodprice"].newText(renderer,"   ",100);

    theText["pillE"].newText(renderer,"   ",100);
    theText["pillEprice"].newText(renderer,"   ",100);

    theText["pillP"].newText(renderer,"   ",100);
    theText["pillPprice"].newText(renderer,"   ",100);

    theText["pillQ"].newText(renderer,"   ",100);
    theText["pillQprice"].newText(renderer,"   ",100);

    theText["pillA"].newText(renderer,"   ",100);
    theText["pillAprice"].newText(renderer,"   ",100);

    theText["pillPQA"].newText(renderer,"   ",100);
    theText["pillPQAprice"].newText(renderer,"   ",100);

    theText["sumPrice"].newText(renderer,"   ",100);

    theText["day"].newText(renderer,"   ",100);

    theText["money"].newText(renderer,"   ",100);

    theText["catfood"].newText(renderer,"   ",100);

    theText["showPillE"].newText(renderer,"   ",100);

    theText["showPillP"].newText(renderer,"   ",100);

    theText["showPillQ"].newText(renderer,"   ",100);

    theText["showPillA"].newText(renderer,"   ",100);

    theText["showPillPQA"].newText(renderer,"   ",100);

    theText["showTime"].newText(renderer,"   ",100);

    theText["health"].newText(renderer,"   ",100);

    theText["isSick"].newText(renderer,"   ",100);

    theText["love"].newText(renderer,"   ",100);
}

void freeTexts(map<string,Text>& theText)
{
    theText["food"].freeText();
    theText["foodprice"].freeText();

    theText["pillE"].freeText();
    theText["pillEprice"].freeText();

    theText["pillP"].freeText();
    theText["pillPprice"].freeText();

    theText["pillQ"].freeText();
    theText["pillQprice"].freeText();

    theText["pillA"].freeText();
    theText["pillAprice"].freeText();

    theText["pillPQA"].freeText();
    theText["pillPQAprice"].freeText();

    theText["sumPrice"].freeText();

    theText["day"].freeText();

    theText["money"].freeText();

    theText["catfood"].freeText();

    theText["showPillE"].freeText();

    theText["showPillP"].freeText();

    theText["showPillQ"].freeText();

    theText["showPillA"].freeText();

    theText["showPillPQA"].freeText();

    theText["showTime"].freeText();

    theText["health"].freeText();

    theText["isSick"].freeText();

    theText["love"].freeText();
}

void renderButton(map<string,Button>& theButton,string buttonName,Gallery& theGallery,string picName,SDL_Renderer* renderer)
{
    renderTexture(theButton[buttonName].getx(),theButton[buttonName].gety(),BUTTON_SIZE,BUTTON_SIZE,theGallery.getTexture(picName),renderer);
}

void renderButtonWithFrame(map<string,Button>& theButton,string buttonName,Gallery& theGallery,string picName,SDL_Renderer* renderer)
{
    renderTexture(theButton[buttonName].getx(),theButton[buttonName].gety(),BUTTON_SIZE,BUTTON_SIZE,theGallery.getTexture("buttonFrame"),renderer);
    renderTexture(theButton[buttonName].getx(),theButton[buttonName].gety(),BUTTON_SIZE,BUTTON_SIZE,theGallery.getTexture(picName),renderer);
}

void renderAllButton(map<string,Button>& theButton,Game& theGame,Gallery& theGallery,SDL_Renderer* renderer)
{
    if(theGame.getGamePlace()==GAME_PLACE_HOUSE)
    {
        if(!theButton["fillBowl"].isMouseInButton()) renderButtonWithFrame(theButton,"fillBowl",theGallery,"catbowl",renderer);
        else {
                renderButtonWithFrame(theButton,"fillBowl",theGallery,"catbowlfull",renderer);
                renderButtonOutline(theButton["fillBowl"],2,renderer);
        }

        if(!theButton["menu"].isMouseInButton()) renderButton(theButton,"menu",theGallery,"menuButton",renderer);
        else {
                renderButton(theButton,"menu",theGallery,"menuButton",renderer);
                renderButtonOutline(theButton["menu"],2,renderer);
        }

        if(!theButton["shovel"].isMouseInButton()) renderButtonWithFrame(theButton,"shovel",theGallery,"shovel",renderer);
        else {
                renderButtonWithFrame(theButton,"shovel",theGallery,"shovelLitter",renderer);
                renderButtonOutline(theButton["shovel"],2,renderer);
        }

        if(!theButton["pet"].isMouseInButton()) renderButtonWithFrame(theButton,"pet",theGallery,"pet",renderer);
        else {
                renderButtonWithFrame(theButton,"pet",theGallery,"pet",renderer);
                renderButtonOutline(theButton["pet"],2,renderer);
        }

        if(!theButton["excercise"].isMouseInButton()) renderButtonWithFrame(theButton,"excercise",theGallery,"excercise",renderer);
        else {
                renderButtonWithFrame(theButton,"excercise",theGallery,"excercise",renderer);
                renderButtonOutline(theButton["excercise"],2,renderer);
        }

        if(!theButton["pillE"].isMouseInButton()) renderButtonWithFrame(theButton,"pillE",theGallery,"pillE",renderer);
        else {
                renderButtonWithFrame(theButton,"pillE",theGallery,"pillE",renderer);
                renderButtonOutline(theButton["pillE"],2,renderer);
        }

        if(!theButton["pillP"].isMouseInButton()) renderButtonWithFrame(theButton,"pillP",theGallery,"pillP",renderer);
        else {
                renderButtonWithFrame(theButton,"pillP",theGallery,"pillP",renderer);
                renderButtonOutline(theButton["pillP"],2,renderer);
        }

        if(!theButton["pillQ"].isMouseInButton()) renderButtonWithFrame(theButton,"pillQ",theGallery,"pillQ",renderer);
        else {
                renderButtonWithFrame(theButton,"pillQ",theGallery,"pillQ",renderer);
                renderButtonOutline(theButton["pillQ"],2,renderer);
        }

        if(!theButton["pillA"].isMouseInButton()) renderButtonWithFrame(theButton,"pillA",theGallery,"pillA",renderer);
        else {
                renderButtonWithFrame(theButton,"pillA",theGallery,"pillA",renderer);
                renderButtonOutline(theButton["pillA"],2,renderer);
        }

        if(!theButton["pillPQA"].isMouseInButton()) renderButtonWithFrame(theButton,"pillPQA",theGallery,"pillPQA",renderer);
        else {
                renderButtonWithFrame(theButton,"pillPQA",theGallery,"pillPQA",renderer);
                renderButtonOutline(theButton["pillPQA"],2,renderer);
        }
    }

    if(theGame.getPhoneApp()==PHONE_APP_SCREEN)
    {
        if(theButton["myMeo"].isMouseInButton()) renderButtonOutline(theButton["myMeo"],2,renderer);

        if(theButton["meoTip"].isMouseInButton()) renderButtonOutline(theButton["meoTip"],2,renderer);

        if(theButton["ZooTube"].isMouseInButton()) renderButtonOutline(theButton["ZooTube"],2,renderer);

        if(theButton["map"].isMouseInButton()) renderButtonOutline(theButton["map"],2,renderer);
    }
    else if(theGame.getPhoneApp()==PHONE_APP_MAP)
    {
        if(theButton["shop"].isMouseInButton()) renderButtonOutline(theButton["shop"],2,renderer);

        if(theButton["vet"].isMouseInButton()) renderButtonOutline(theButton["vet"],2,renderer);

        if(theButton["work"].isMouseInButton()) renderButtonOutline(theButton["work"],2,renderer);

        if(theButton["house"].isMouseInButton()) renderButtonOutline(theButton["house"],2,renderer);
    }
    if(theGame.getGamePlace()==GAME_PLACE_SHOP)
    {
        if(theButton["minusFood"].isMouseInButton()) renderButtonOutline(theButton["minusFood"],2,renderer);
        if(theButton["plusFood"].isMouseInButton()) renderButtonOutline(theButton["plusFood"],2,renderer);

        if(theButton["minusFood10"].isMouseInButton()) renderButtonOutline(theButton["minusFood10"],2,renderer);
        if(theButton["plusFood10"].isMouseInButton()) renderButtonOutline(theButton["plusFood10"],2,renderer);

        if(theButton["minusFood100"].isMouseInButton()) renderButtonOutline(theButton["minusFood100"],2,renderer);
        if(theButton["plusFood100"].isMouseInButton()) renderButtonOutline(theButton["plusFood100"],2,renderer);

        if(theButton["minusPillE"].isMouseInButton()) renderButtonOutline(theButton["minusPillE"],2,renderer);
        if(theButton["plusPillE"].isMouseInButton()) renderButtonOutline(theButton["plusPillE"],2,renderer);

        if(theButton["minusPillP"].isMouseInButton()) renderButtonOutline(theButton["minusPillP"],2,renderer);
        if(theButton["plusPillP"].isMouseInButton()) renderButtonOutline(theButton["plusPillP"],2,renderer);

        if(theButton["minusPillQ"].isMouseInButton()) renderButtonOutline(theButton["minusPillQ"],2,renderer);
        if(theButton["plusPillQ"].isMouseInButton()) renderButtonOutline(theButton["plusPillQ"],2,renderer);

        if(theButton["minusPillA"].isMouseInButton()) renderButtonOutline(theButton["minusPillA"],2,renderer);
        if(theButton["plusPillA"].isMouseInButton()) renderButtonOutline(theButton["plusPillA"],2,renderer);

        if(theButton["minusPillPQA"].isMouseInButton()) renderButtonOutline(theButton["minusPillPQA"],2,renderer);
        if(theButton["plusPillPQA"].isMouseInButton()) renderButtonOutline(theButton["plusPillPQA"],2,renderer);

        if(theButton["buy"].isMouseInButton()) renderButtonOutline(theButton["buy"],2,renderer);
    }
}

void handleAllButton(map<string,Button>& theButton,SDL_Event* e,Game& theGame,Shop& theShop,LTime& theTime)
{
    if(theButton["menu"].handleEvent(e)){}
    if(theGame.getGamePlace()==GAME_PLACE_HOUSE)
    {
        if(theButton["fillBowl"].handleEvent(e)){theGame.fillBowl();}
        if(theButton["shovel"].handleEvent(e)){theGame.takeShit();}
        if(theButton["pet"].handleEvent(e)){theGame.pet();}
        if(theButton["excercise"].handleEvent(e)){theGame.excercise();}
        if(theButton["pillE"].handleEvent(e)){theGame.pill(PILL_E);}
        if(theButton["pillP"].handleEvent(e)){theGame.pill(PILL_P);}
        if(theButton["pillQ"].handleEvent(e)){theGame.pill(PILL_Q);}
        if(theButton["pillA"].handleEvent(e)){theGame.pill(PILL_A);}
        if(theButton["pillPQA"].handleEvent(e)){theGame.pill(PILL_PQA);}
    }
    if(theGame.getPhoneApp()==PHONE_APP_SCREEN)
    {
        if(theButton["myMeo"].handleEvent(e)){theGame.openApp(PHONE_APP_MYMEO);}
        if(theButton["meoTip"].handleEvent(e)){}
        if(theButton["ZooTube"].handleEvent(e)){theGame.openApp(PHONE_APP_ZOOTUBE);}
        if(theButton["map"].handleEvent(e)){theGame.openApp(PHONE_APP_MAP);}
    }
    else if(theGame.getPhoneApp()==PHONE_APP_MAP)
    {
        if(theButton["shop"].handleEvent(e)){theGame.goToPlace(GAME_PLACE_SHOP,theTime);theShop.resetShop();}
        if(theButton["vet"].handleEvent(e)){theGame.goToPlace(GAME_PLACE_VET,theTime);theShop.resetShop();}
        if(theButton["work"].handleEvent(e)){theGame.goToPlace(GAME_PLACE_WORK,theTime);theShop.resetShop();}
        if(theButton["house"].handleEvent(e)){theGame.goToPlace(GAME_PLACE_HOUSE,theTime);theShop.resetShop();}
    }
    if(theButton["homeButton"].handleEvent(e)){theGame.backToScreen();}
    if(theButton["appButton"].handleEvent(e)){theGame.backToScreen();}
    if(theButton["backButton"].handleEvent(e)){theGame.backToScreen();}

    if(theGame.getGamePlace()==GAME_PLACE_SHOP)
    {
        if(theButton["minusFood"].handleEvent(e)){theShop.pickFood(-1);}
        if(theButton["plusFood"].handleEvent(e)){theShop.pickFood(1);}

        if(theButton["minusFood10"].handleEvent(e)){theShop.pickFood(-10);}
        if(theButton["plusFood10"].handleEvent(e)){theShop.pickFood(10);}

        if(theButton["minusFood100"].handleEvent(e)){theShop.pickFood(-100);}
        if(theButton["plusFood100"].handleEvent(e)){theShop.pickFood(100);}

        if(theButton["minusPillE"].handleEvent(e)){theShop.pickPillE(-1);}
        if(theButton["plusPillE"].handleEvent(e)){theShop.pickPillE(1);}

        if(theButton["minusPillP"].handleEvent(e)){theShop.pickPillP(-1);}
        if(theButton["plusPillP"].handleEvent(e)){theShop.pickPillP(1);}

        if(theButton["minusPillQ"].handleEvent(e)){theShop.pickPillQ(-1);}
        if(theButton["plusPillQ"].handleEvent(e)){theShop.pickPillQ(1);}

        if(theButton["minusPillA"].handleEvent(e)){theShop.pickPillA(-1);}
        if(theButton["plusPillA"].handleEvent(e)){theShop.pickPillA(1);}

        if(theButton["minusPillPQA"].handleEvent(e)){theShop.pickPillPQA(-1);}
        if(theButton["plusPillPQA"].handleEvent(e)){theShop.pickPillPQA(1);}

        if(theButton["buy"].handleEvent(e)){theShop.buy(theGame);}
    }
}

void renderButtonOutline(Button theButton,int thick,SDL_Renderer* renderer)
{
    for(int i=0;i<thick;i++)
    {
        SDL_Rect outline = {theButton.getx()+i,theButton.gety()+i,BUTTON_SIZE-2*i,BUTTON_SIZE-2*i};
        SDL_SetRenderDrawColor(renderer,255,255,255,255);
        SDL_RenderDrawRect(renderer,&outline);
    }
}

void renderHouse(Game& theGame,Gallery& gallery,SDL_Renderer* renderer)
{
    if(theGame.getGamePlace()==GAME_PLACE_HOUSE)
    {
        renderTexture(FLOOR_X,0,HOUSE_WIDTH,SCREEN_HEIGHT,gallery.getTexture("HouseBackground"),renderer);
        SDL_Point p = theGame.getCellPos(CELL_FOOD);
        if(theGame.getBowlIsFull()) {renderTexture(p.x - CELL_SIZE/4 - 10,p.y + CELL_SIZE/16,60,30,gallery.getTexture("catbowlfull"),renderer);}
        else renderTexture(p.x - CELL_SIZE/4 - 10,p.y + CELL_SIZE/16,60,30,gallery.getTexture("catbowl"),renderer);

        SDL_Point l = theGame.getCellPos(CELL_LITTER);
        int minix = 100*theGame.getShit();
        renderTexturefromTexture(l.x - 50,l.y - CELL_SIZE/8,100,40,minix,0,100,40,gallery.getTexture("litter"),renderer);
    }
}

void renderShop(Game& theGame,Gallery& gallery,Shop& theShop,SDL_Renderer* renderer,map<string,Text>& theText)
{
    renderTexture(FLOOR_X,0,HOUSE_WIDTH,SCREEN_HEIGHT,gallery.getTexture("shopBackground"),renderer);

    theText["food"].setText("x"+to_string(theShop.getFood())+"   ");
    renderTexture(29*30,6*30,60,30,theText["food"].getText(),renderer);

    theText["foodprice"].setText(to_string(theShop.getFood())+"   ");
    renderTexture(32*30,6*30,60,30,theText["foodprice"].getText(),renderer);

    theText["pillE"].setText("x"+to_string(theShop.getPillE())+"   ");
    renderTexture(29*30,8*30,60,30,theText["pillE"].getText(),renderer);

    theText["pillEprice"].setText(to_string(theShop.getPillE()*15)+"   ");
    renderTexture(32*30,8*30,60,30,theText["pillEprice"].getText(),renderer);

    theText["pillP"].setText("x"+to_string(theShop.getPillP())+"   ");
    renderTexture(29*30,10*30,60,30,theText["pillP"].getText(),renderer);

    theText["pillPprice"].setText(to_string(theShop.getPillP()*20)+"   ");
    renderTexture(32*30,10*30,60,30,theText["pillPprice"].getText(),renderer);

    theText["pillQ"].setText("x"+to_string(theShop.getPillQ())+"   ");
    renderTexture(29*30,12*30,60,30,theText["pillQ"].getText(),renderer);

    theText["pillQprice"].setText(to_string(theShop.getPillQ()*20)+"   ");
    renderTexture(32*30,12*30,60,30,theText["pillQprice"].getText(),renderer);

    theText["pillA"].setText("x"+to_string(theShop.getPillA())+"   ");
    renderTexture(29*30,14*30,60,30,theText["pillA"].getText(),renderer);

    theText["pillAprice"].setText(to_string(theShop.getPillA()*20)+"   ");
    renderTexture(32*30,14*30,60,30,theText["pillAprice"].getText(),renderer);

    theText["pillPQA"].setText("x"+to_string(theShop.getPillPQA())+"   ");
    renderTexture(29*30,16*30,60,30,theText["pillPQA"].getText(),renderer);

    theText["pillPQAprice"].setText(to_string(theShop.getPillPQA()*30)+"   ");
    renderTexture(32*30,16*30,60,30,theText["pillPQAprice"].getText(),renderer);

    theText["sumPrice"].setText(to_string(theShop.getSumPrice())+"   ");
    renderTexture(29*30,18*30,60,30,theText["sumPrice"].getText(),renderer);
}

void renderPhone(Game& theGame,Gallery& gallery,SDL_Renderer* renderer,LTime& theTime,map<string,Text>& theText)
{
    if(theGame.getPhoneApp()==PHONE_APP_SCREEN) renderTexture(0,SCREEN_HEIGHT-600,322,500,gallery.getTexture("phone"),renderer);
    else if(theGame.getPhoneApp()==PHONE_APP_MAP) renderTexture(0,SCREEN_HEIGHT-600,322,500,gallery.getTexture("openMap"),renderer);
    else if(theGame.getPhoneApp()==PHONE_APP_MYMEO)
    {
        renderTexture(0,SCREEN_HEIGHT-600,322,500,gallery.getTexture("openMyMeo"),renderer);
        theText["health"].setText(to_string(theGame.getCatHealth())+"   ");
        renderTexture(6*30,12*30,60,30,theText["health"].getText(),renderer);
        if(theGame.getIsSick()) theText["isSick"].setText("Yes");
        else theText["isSick"].setText("No");
        renderTexture(6*30,14*30,60,30,theText["isSick"].getText(),renderer);
        theText["love"].setText(to_string(theGame.getCatLove())+"   ");
        renderTexture(6*30,16*30,60,30,theText["love"].getText(),renderer);
    }
    else if(theGame.getPhoneApp()==PHONE_APP_ZOOTUBE)
    {
        renderTexture(0,SCREEN_HEIGHT-600,322,500,gallery.getTexture("openZooTube"),renderer);
        renderTexture(FLOOR_X,0,HOUSE_WIDTH,SCREEN_HEIGHT,gallery.getTexture("working"),renderer);
    }
    theText["showTime"].setText(theTime.getHour()+":"+theTime.getMinute());
    renderTexture(125,225,70,20,theText["showTime"].getText(),renderer);
}

void renderNotePad(Game& theGame,Gallery& gallery,SDL_Renderer* renderer,LTime& theTime,map<string,Text>& theText)
{
    renderTexture(FLOOR_X+HOUSE_WIDTH,310,322,450,gallery.getTexture("notepad"),renderer);

    theText["day"].setText(theTime.getDay()+"   ");
    renderTexture(41*30,12*30,60,30,theText["day"].getText(),renderer);

    theText["money"].setText(to_string(theGame.getMoney())+"   ");
    renderTexture(41*30,13*30+4,60,30,theText["money"].getText(),renderer);

    theText["catfood"].setText(to_string(theGame.getCatFood())+"   ");
    renderTexture(41*30,15*30+5,60,30,theText["catfood"].getText(),renderer);

    theText["showPillE"].setText(to_string(theGame.getPillE())+"   ");
    renderTexture(41*30,16*30+5,60,30,theText["showPillE"].getText(),renderer);

    theText["showPillP"].setText(to_string(theGame.getPillP())+"   ");
    renderTexture(41*30,17*30+5,60,30,theText["showPillP"].getText(),renderer);

    theText["showPillQ"].setText(to_string(theGame.getPillQ())+"   ");
    renderTexture(41*30,18*30+5,60,30,theText["showPillQ"].getText(),renderer);

    theText["showPillA"].setText(to_string(theGame.getPillA())+"   ");
    renderTexture(41*30,19*30+5,60,30,theText["showPillA"].getText(),renderer);

    theText["showPillPQA"].setText(to_string(theGame.getPillPQA())+"   ");
    renderTexture(41*30,20*30+5,60,30,theText["showPillPQA"].getText(),renderer);
}

void renderCat(Game& theGame,Gallery& gallery,SDL_Renderer* renderer,LTime& theTime,int& frametime)
{
    int framemax = 3,frame = theGame.frame;
    SDL_Point catPos = theGame.getCatPos();
    if(theGame.getCatMove()==CAT_MOVE_WALK)
    {
        framemax = 3;
        switch(theGame.getCatDirection())
        {
            case DIRECTION_UP:
                renderTexturefromTexture(catPos.x-CAT_SIZE/2,catPos.y-CAT_SIZE/2-30,CAT_SIZE,CAT_SIZE,4*32+frame*32,1,31,31,gallery.getTexture("myCat"),renderer);
                break;
            case DIRECTION_DOWN:
                renderTexturefromTexture(catPos.x-CAT_SIZE/2,catPos.y-CAT_SIZE/2-30,CAT_SIZE,CAT_SIZE,0*32+frame*32,1,31,31,gallery.getTexture("myCat"),renderer);
                break;
            case DIRECTION_LEFT:
                renderTexturefromTexture(catPos.x-CAT_SIZE/2,catPos.y-CAT_SIZE/2-30,CAT_SIZE,CAT_SIZE,0*32+frame*32,1+32,31,31,gallery.getTexture("myCat"),renderer);
                break;
            case DIRECTION_RIGHT:
                renderTexturefromTexture(catPos.x-CAT_SIZE/2,catPos.y-CAT_SIZE/2-30,CAT_SIZE,CAT_SIZE,4*32+frame*32,1+32,31,31,gallery.getTexture("myCat"),renderer);
                break;
        }
    }
    if(theGame.getCatMove()==CAT_MOVE_JUMP)
    {
        framemax = 7;
        switch(theGame.getCatDirection())
        {
        case DIRECTION_UP:
            renderTexturefromTexture(catPos.x-CAT_SIZE/2,catPos.y-CAT_SIZE/2-30,CAT_SIZE,CAT_SIZE,frame*32,1+10*32,31,31,gallery.getTexture("myCat"),renderer);
            break;
        case DIRECTION_DOWN:
            renderTexturefromTexture(catPos.x-CAT_SIZE/2,catPos.y-CAT_SIZE/2-30,CAT_SIZE,CAT_SIZE,frame*32,1+11*32,31,31,gallery.getTexture("myCat"),renderer);
            break;
        case DIRECTION_LEFT:
            renderTexturefromTexture(catPos.x-CAT_SIZE/2,catPos.y-CAT_SIZE/2-30,CAT_SIZE,CAT_SIZE,frame*32,1+9*32,31,31,gallery.getTexture("myCat"),renderer);
            break;
        case DIRECTION_RIGHT:
            renderTexturefromTexture(catPos.x-CAT_SIZE/2,catPos.y-CAT_SIZE/2-30,CAT_SIZE,CAT_SIZE,frame*32,1+8*32,31,31,gallery.getTexture("myCat"),renderer);
            break;
        }
    }
    else if(theGame.getCatMove()==CAT_MOVE_EAT)
    {
        framemax = 7;
        if(theGame.getBowlIsFull())
        {
            renderTexturefromTexture(catPos.x-CAT_SIZE/2,catPos.y-CAT_SIZE/2-30,CAT_SIZE,CAT_SIZE,frame*32,1+32*5,31,31,gallery.getTexture("myCat"),renderer);
        }
        else renderTexturefromTexture(catPos.x-CAT_SIZE/2,catPos.y-CAT_SIZE/2-30,CAT_SIZE,CAT_SIZE,0,5*32+1,31,31,gallery.getTexture("myCat"),renderer);
        SDL_Point p = theGame.getCellPos(CELL_FOOD);
        if(theGame.getBowlIsFull()) {renderTexture(p.x - CELL_SIZE/4 - 10,p.y + CELL_SIZE/16,60,30,gallery.getTexture("catbowlfull"),renderer);}
        else renderTexture(p.x - CELL_SIZE/4 - 10,p.y + CELL_SIZE/16,60,30,gallery.getTexture("catbowl"),renderer);
    }
    else if(theGame.getCatMove()==CAT_MOVE_POO)
    {
        framemax = 7;
        if(theGame.getShit()<=5)
        {
            renderTexturefromTexture(catPos.x-CAT_SIZE/2,catPos.y-CAT_SIZE/2-30,CAT_SIZE,CAT_SIZE,frame*32,1+32*2,31,31,gallery.getTexture("myCat"),renderer);
        }
        else
        {
            renderTexturefromTexture(catPos.x-CAT_SIZE/2,catPos.y-CAT_SIZE/2-30,CAT_SIZE,CAT_SIZE,2*32,1+32*2,31,31,gallery.getTexture("myCat"),renderer);
        }
    }
    else if(theGame.getGameCat()==GAME_CAT_DOSTH)
    {
        framemax = 7;
        switch(theGame.getCatDo())
        {
        case CAT_DO_LICK:
            renderTexturefromTexture(catPos.x-CAT_SIZE/2,catPos.y-CAT_SIZE/2-30,CAT_SIZE,CAT_SIZE,frame*32,1+32*4,31,31,gallery.getTexture("myCat"),renderer);
            break;
        case CAT_DO_LIEDOWN:
            renderTexturefromTexture(catPos.x-CAT_SIZE/2,catPos.y-CAT_SIZE/2-30,CAT_SIZE,CAT_SIZE,frame*32,1+32*6,31,31,gallery.getTexture("myCat"),renderer);
            break;
        case CAT_DO_MYDIEU:
            renderTexturefromTexture(catPos.x-CAT_SIZE/2,catPos.y-CAT_SIZE/2-30,CAT_SIZE,CAT_SIZE,frame*32,1+32*3,31,31,gallery.getTexture("myCat"),renderer);
            break;
        }
    }
    else if(theGame.getCatMove()==CAT_MOVE_SLEEP)
    {
        framemax = 7;
        if(theTime.getHourValue()>=0 && theTime.getHourValue()<22)
        {
            theGame.frame=7;
            theGame.catWakeup(theTime);
        }
        if(frame>=5&&frame<7) theGame.frame=5;
        renderTexturefromTexture(catPos.x-CAT_SIZE/2,catPos.y-CAT_SIZE/2-30,CAT_SIZE,CAT_SIZE,frame*32,1+32*7,31,31,gallery.getTexture("myCat"),renderer);
    }
    else if(theGame.getGameCat()==GAME_CAT_PET)
    {
        framemax = 7;
        renderTexturefromTexture(catPos.x-CAT_SIZE/2,catPos.y-CAT_SIZE/2-30,CAT_SIZE,CAT_SIZE,frame*32,1+32*12,31,31,gallery.getTexture("myCat"),renderer);
    }
    else if(theGame.getGameCat()==GAME_CAT_EXCERCISE)
    {
        framemax = 7;
        renderTexturefromTexture(catPos.x-CAT_SIZE/2,catPos.y-CAT_SIZE/2-30,CAT_SIZE,CAT_SIZE,frame*32,1+32*13,31,31,gallery.getTexture("myCat"),renderer);
    }
    else if(theGame.getGameCat()==GAME_CAT_PILL)
    {
        framemax = 7;
        renderTexturefromTexture(catPos.x-CAT_SIZE/2,catPos.y-CAT_SIZE/2-30,CAT_SIZE,CAT_SIZE,frame*32,1+32*14,31,31,gallery.getTexture("myCat"),renderer);
    }
    if(theGame.getIsMoving())
    {
        int fratime = SDL_GetTicks();
        if(fratime - frametime>300)
        {
            theGame.frame++;
            if(theGame.frame>framemax) theGame.frame=0;
            frametime=fratime;
        }
    }
    else
    {
        theGame.frame=0;
        framemax = 3;
        renderTexturefromTexture(catPos.x-CAT_SIZE/2,catPos.y-CAT_SIZE/2-30,CAT_SIZE,CAT_SIZE,0,3*32+1,31,31,gallery.getTexture("myCat"),renderer);
    }
}
