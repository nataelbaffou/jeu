//
//  Basiques.cpp
//  sdlcommande
//
//  Created by MacBook Pro on 14/11/2017.
//  Copyright © 2017 MacBook Pro. All rights reserved.
//

#include "Basiques.hpp"
#include "constants.h"
#include <stdio.h>
#include <string>
#include <SDL2/SDL.h>
#include <iostream>

using namespace std;

bool estClique(SDL_Surface *bouton, SDL_Rect posImage, SDL_Event event)
{
    if (event.button.x >= posImage.x && event.button.x <= (posImage.x + bouton->w) && event.button.y >= posImage.y && event.button.y <= (posImage.y + bouton->h))
    {
        return true;
    }
    return false;
}


void messageErreur(string texte)
{
    SDL_Window *window = NULL;
    SDL_Surface *screen = NULL;
    window = SDL_CreateWindow( "ERREUR", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 200, 100, NULL);
    screen = SDL_GetWindowSurface( window );
    Uint32 couleurFond = SDL_MapRGB(screen->format, 0, 255, 0);
    SDL_FillRect(screen, NULL, couleurFond);
    
    cout << texte;
    
    int continuer = 1;
    SDL_Event event;
    
    while (continuer)
    {
        SDL_PollEvent(&event);
        switch(event.type)
        {
            case SDL_QUIT:
                continuer = 0;
                break;
        }
    }
    SDL_DestroyWindow( window );
}

void afficherTexture(SDL_Surface *texture)
{
    SDL_Window *window = NULL;
    SDL_Surface *screen = NULL;
    window = SDL_CreateWindow( "test", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, texture->w, texture->h, NULL);
    screen = SDL_GetWindowSurface( window );
    Uint32 couleurFond = SDL_MapRGB(screen->format, 0, 255, 0);
    SDL_FillRect(screen, NULL, couleurFond);
    SDL_BlitSurface(texture, NULL, screen, NULL);
    SDL_UpdateWindowSurface(window);
    
    int continuer = 1;
    SDL_Event event;
    
    while (continuer)
    {
        SDL_WaitEvent(&event);
        switch(event.type)
        {
            case SDL_QUIT:
                continuer = 0;
                break;
        }
    }
}
