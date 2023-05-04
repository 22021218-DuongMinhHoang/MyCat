#include "Text.h"

Text::Text(SDL_Renderer* r,string txt,int sizef)
{
    //ctor
    font = TTF_OpenFont("arialr.ttf",sizef);
    renderer = r;
    text = loadText(txt);
}

Text::Text()
{

}

Text::~Text()
{
    //dtor
    freeText();
}

SDL_Texture* Text::loadText(string txt)
{
    //freeText();
    SDL_Color textcolor = {255,255,255};
    SDL_Texture* newTexture = nullptr;
    SDL_Surface* textSurface = TTF_RenderText_Blended_Wrapped(font,txt.c_str(),textcolor,0);
    if(textSurface == nullptr)
    {
        printf( "Unable to render text surface! SDL_ttf Error: %s\n", TTF_GetError() );
    }
    else
    {
        newTexture = SDL_CreateTextureFromSurface(renderer,textSurface);
        if(newTexture == nullptr)
        {
            cout<<"could not create texture from surface "<<SDL_GetError()<<endl;
        }
		SDL_FreeSurface(textSurface);
    }
    return newTexture;
}

void Text::setText(string txt)
{
    freeText();
    text = loadText(txt);
}

void Text::newText(SDL_Renderer* r,string txt,int sizef)
{
    font = TTF_OpenFont("arialr.ttf",sizef);
    renderer = r;
    text = loadText(txt);
}
