#ifndef GALLERY_H
#define GALLERY_H
#include <iostream>
#include <iostream>
#include <string>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>
#include <map>
#include <vector>

using namespace std;

class Gallery
{
    public:
        Gallery(SDL_Renderer* _renderer);
        virtual ~Gallery();
        bool loadGallery();
        SDL_Texture* getTexture(string path);
        void playChunk(string name);
        void playChunk(string name,int loop);
        void playMusic(string name);
        void loadMusicsAndChunks();
        void freeImg();
        void freeChunksAndMusics();
        void freeAll(){freeImg();freeChunksAndMusics();}
    private:
        SDL_Renderer* renderer;
        SDL_Texture* loadImage(string path);
        map<string,SDL_Texture*> pictures;
        map<string,Mix_Music*> musics;
        map<string,Mix_Chunk*> chunks;
        vector<string> id;
        vector<string> chunkId;
        vector<string> musicId;
};

#endif // GALLERY_H
