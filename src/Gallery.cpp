#include "Gallery.h"

Gallery::Gallery(SDL_Renderer* _renderer)
{
    //ctor
    renderer = _renderer;
}

Gallery::~Gallery()
{
    //dtor
    freeImg();
}

SDL_Texture* Gallery::loadImage(string path)
{
    SDL_Texture* newTexture = nullptr;
    SDL_Surface* newSurface = IMG_Load(path.c_str());

    if(newSurface==nullptr)
    {
        cout<<"could not load img: "<<IMG_GetError()<<endl;
    }
    else
    {
        SDL_SetColorKey(newSurface,SDL_TRUE,SDL_MapRGB(newSurface->format,0,255,255));
        newTexture = SDL_CreateTextureFromSurface(renderer,newSurface);
        if(newTexture == nullptr)
        {
            cout<<"could not load texture: "<<path.c_str()<<IMG_GetError()<<endl;
        }
    }

    SDL_FreeSurface(newSurface);

    return newTexture;
}

bool Gallery::loadGallery()
{
    pictures["myCat"] = loadImage("MyCat.png");
    if(pictures["myCat"]==nullptr) return false;
    id.push_back("myCat");

    pictures["HouseBackground"] = loadImage("HouseBackground.png");
    if(pictures["HouseBackground"]==nullptr) return false;
    id.push_back("HouseBackground");

    pictures["catbowl"] = loadImage("catbowl.png");
    if(pictures["catbowl"]==nullptr) return false;
    id.push_back("catbowl");

    pictures["catbowlfull"] = loadImage("catbowlfull.png");
    if(pictures["catbowlfull"]==nullptr) return false;
    id.push_back("catbowlfull");

    pictures["litter"] = loadImage("litter.png");
    if(pictures["litter"]==nullptr) return false;
    id.push_back("litter");

    pictures["menuButton"] = loadImage("menuButton.png");
    if(pictures["menuButton"]==nullptr) return false;
    id.push_back("menuButton");

    pictures["shovel"] = loadImage("shovel.png");
    if(pictures["shovel"]==nullptr) return false;
    id.push_back("shovel");

    pictures["shovelLitter"] = loadImage("shovelLitter.png");
    if(pictures["shovelLitter"]==nullptr) return false;
    id.push_back("shovelLitter");

    pictures["pet"] = loadImage("pet.png");
    if(pictures["pet"]==nullptr) return false;
    id.push_back("pet");

    pictures["excercise"] = loadImage("excercise.png");
    if(pictures["excercise"]==nullptr) return false;
    id.push_back("excercise");

    pictures["shopBackground"] = loadImage("shopBackground.png");
    if(pictures["shopBackground"]==nullptr) return false;
    id.push_back("shopBackground");

    pictures["phone"] = loadImage("phone.png");
    if(pictures["phone"]==nullptr) return false;
    id.push_back("phone");

    pictures["pillE"] = loadImage("pillE.png");
    if(pictures["pillE"]==nullptr) return false;
    id.push_back("pillE");

    pictures["pillP"] = loadImage("pillP.png");
    if(pictures["pillP"]==nullptr) return false;
    id.push_back("pillP");

    pictures["pillQ"] = loadImage("pillQ.png");
    if(pictures["pillQ"]==nullptr) return false;
    id.push_back("pillQ");

    pictures["pillA"] = loadImage("pillA.png");
    if(pictures["pillA"]==nullptr) return false;
    id.push_back("pillA");

    pictures["pillPQA"] = loadImage("pillPQA.png");
    if(pictures["pillPQA"]==nullptr) return false;
    id.push_back("pillPQA");

    pictures["buttonFrame"] = loadImage("buttonFrame.png");
    if(pictures["buttonFrame"]==nullptr) return false;
    id.push_back("buttonFrame");

    pictures["notepad"] = loadImage("notepad.png");
    if(pictures["notepad"]==nullptr) return false;
    id.push_back("notepad");

    pictures["myMeo"] = loadImage("myMeo.png");
    if(pictures["myMeo"]==nullptr) return false;
    id.push_back("myMeo");

    pictures["meoTip"] = loadImage("meoTip.png");
    if(pictures["meoTip"]==nullptr) return false;
    id.push_back("meoTip");

    pictures["map"] = loadImage("map.png");
    if(pictures["map"]==nullptr) return false;
    id.push_back("map");

    pictures["ZooTube"] = loadImage("ZooTube.png");
    if(pictures["ZooTube"]==nullptr) return false;
    id.push_back("ZooTube");

    pictures["openMap"] = loadImage("openMap.png");
    if(pictures["openMap"]==nullptr) return false;
    id.push_back("openMap");

    pictures["openMyMeo"] = loadImage("openMyMeo.png");
    if(pictures["openMyMeo"]==nullptr) return false;
    id.push_back("openMyMeo");

    pictures["openZooTube"] = loadImage("openZooTube.png");
    if(pictures["openZooTube"]==nullptr) return false;
    id.push_back("openZooTube");

    pictures["makingVideo"] = loadImage("makingVideo.png");
    if(pictures["makingVideo"]==nullptr) return false;
    id.push_back("makingVideo");

    pictures["working"] = loadImage("working.png");
    if(pictures["working"]==nullptr) return false;
    id.push_back("working");

    return true;
}

SDL_Texture* Gallery::getTexture(string path)
{
    return pictures[path];
}

void Gallery::freeImg()
{
    int num = id.size();
    for(int i=0;i<num;i++)
    {
        SDL_DestroyTexture(pictures[id[i]]);
        pictures[id[i]] = nullptr;
    }
}
