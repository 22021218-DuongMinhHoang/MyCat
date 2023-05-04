#ifndef TEXT_H
#define TEXT_H
#include <iostream>
#include <iostream>
#include <string>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <map>

//text(...)->render text->free text

using namespace std;

class Text
{
    public:
        Text(SDL_Renderer* r,string txt,int sizef);
        Text();
        virtual ~Text();
        SDL_Texture* getText(){return text;}
        void setText(string txt);
        void newText(SDL_Renderer* r,string txt,int sizef);
        void freeText()
        {
            if(text!=nullptr)
            {
                SDL_DestroyTexture(text);
                text = nullptr;
            }
        }
    private:
        TTF_Font* font;
        SDL_Renderer* renderer;
        SDL_Texture* loadText(string txt);
        SDL_Texture* text;
};

#endif // TEXT_H
