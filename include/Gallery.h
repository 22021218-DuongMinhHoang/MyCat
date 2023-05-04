#ifndef GALLERY_H
#define GALLERY_H
#include <iostream>
#include <iostream>
#include <string>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
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
        void freeImg();
    private:
        SDL_Renderer* renderer;
        SDL_Texture* loadImage(string path);
        map<string,SDL_Texture*> pictures;
        vector<string> id;
};

#endif // GALLERY_H
