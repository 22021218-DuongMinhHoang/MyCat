#include "Gallery.h"

Gallery::Gallery(SDL_Renderer* _renderer)
{
    //ctor
    renderer = _renderer;
}

Gallery::~Gallery()
{
    //dtor
//    freeImg();
//    freeChunksAndMusics();
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

    pictures["openMeoTip"] = loadImage("openMeoTip.png");
    if(pictures["openMeoTip"]==nullptr) return false;
    id.push_back("openMeoTip");

    pictures["openZooTube"] = loadImage("openZooTube.png");
    if(pictures["openZooTube"]==nullptr) return false;
    id.push_back("openZooTube");

    pictures["makingVideo"] = loadImage("makingVideo.png");
    if(pictures["makingVideo"]==nullptr) return false;
    id.push_back("makingVideo");

    pictures["working"] = loadImage("working.png");
    if(pictures["working"]==nullptr) return false;
    id.push_back("working");

    pictures["atVet"] = loadImage("atVet.png");
    if(pictures["atVet"]==nullptr) return false;
    id.push_back("atVet");

    pictures["menu"] = loadImage("menu.png");
    if(pictures["menu"]==nullptr) return false;
    id.push_back("menu");

    pictures["start"] = loadImage("start.png");
    if(pictures["start"]==nullptr) return false;
    id.push_back("start");

    pictures["showMeoTip"] = loadImage("showMeoTip.png");
    if(pictures["showMeoTip"]==nullptr) return false;
    id.push_back("showMeoTip");

    pictures["gameOver"] = loadImage("gameOver.png");
    if(pictures["gameOver"]==nullptr) return false;
    id.push_back("gameOver");

    pictures["letter"] = loadImage("letter.png");
    if(pictures["letter"]==nullptr) return false;
    id.push_back("letter");

    pictures["transition"] = loadImage("transition.png");
    if(pictures["transition"]==nullptr) return false;
    id.push_back("transition");

    pictures["end"] = loadImage("end.png");
    if(pictures["end"]==nullptr) return false;
    id.push_back("end");

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

void Gallery::loadMusicsAndChunks()
{
    chunks["meow"]=Mix_LoadWAV("meow.wav");
    chunkId.push_back("meow");

    chunks["eating"]=Mix_LoadWAV("eating.wav");
    chunkId.push_back("eating");

    chunks["excercise"]=Mix_LoadWAV("excercise.wav");
    chunkId.push_back("excercise");

    chunks["crying"]=Mix_LoadWAV("crying.wav");
    chunkId.push_back("crying");

    chunks["happi"]=Mix_LoadWAV("happi.wav");
    chunkId.push_back("happi");

    chunks["poo"]=Mix_LoadWAV("poo.wav");
    chunkId.push_back("poo");

    chunks["angry"]=Mix_LoadWAV("angry.wav");
    chunkId.push_back("angry");

    chunks["heal"]=Mix_LoadWAV("heal.wav");
    chunkId.push_back("heal");

    chunks["working"]=Mix_LoadWAV("working.wav");
    chunkId.push_back("working");

    musics["theme"]=Mix_LoadMUS("myCatTheme.wav");
    musicId.push_back("theme");
}

void Gallery::playChunk(string name)
{
    if(Mix_Playing(-1)==0) Mix_PlayChannel(-1,chunks[name],0);
}

void Gallery::playChunk(string name,int loop)
{
    if(Mix_Playing(-1)==0) Mix_PlayChannel(-1,chunks[name],loop);
}

void Gallery::playMusic(string name)
{
    Mix_PlayMusic(musics[name],-1);
}

void Gallery::freeChunksAndMusics()
{
    int chunksNum = chunkId.size();
    for(int i=0;i<chunksNum;i++)
    {
        Mix_FreeChunk(chunks[chunkId[i]]);
        chunks[chunkId[i]] = nullptr;
    }

    int musicsNum = musicId.size();
    for(int i=0;i<musicsNum;i++)
    {
        Mix_FreeMusic(musics[musicId[i]]);
        musics[musicId[i]] = nullptr;
    }
}
