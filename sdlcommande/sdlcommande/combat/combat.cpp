//
//  combat.cpp
//  sdlcommande
//
//  Created by MacBook Pro on 30/12/2017.
//  Copyright © 2017 MacBook Pro. All rights reserved.
//

#include "combat.hpp"
#include "constants.h"
#include "Basiques.hpp"
#include "Widget.hpp"
#include "attaqueLourde.hpp"
#include <SDL2/SDL.h>
#include "Bouton.hpp"

int mainCombat(SDL_Surface *screen, SDL_Window *window)
{
    int screenWidth, screenHeight;
    SDL_GetWindowSize(window, &screenWidth, &screenHeight);
    /*
    Bouton bouton1(IMAGE_BOUTON_1.c_str());
    bouton1.afficher();
    bouton1.set_positionX(500);
    bouton1.set_positionY(200);
    
    SDL_Surface *fondJeu = NULL;
    fondJeu = SDL_CreateRGBSurface(SDL_SWSURFACE, screenWidth/2, screenHeight/2, 32, 0, 0, 0, 0);
    SDL_Rect positionFondJeu;
    positionFondJeu.x = (screenWidth - screenWidth/2)/2;
    positionFondJeu.y = (screenHeight - screenHeight/2)/2;
    Uint32 couleurFond = SDL_MapRGB(screen->format, 0, 255, 0);
    SDL_FillRect(fondJeu, NULL, couleurFond);
    
    SDL_BlitSurface(fondJeu, NULL, screen, &positionFondJeu);
    SDL_BlitSurface(bouton1.get_image(), NULL, screen, bouton1.get_position());
    
    SDL_UpdateWindowSurface(window);
    */
    //SDL_Delay(3000);
    
    //attaqueLourde(screen, window, 1);
    
    AttaqueLourde jeu(screen, window, ATT_LOURDE, 1);
    jeu.lancerNiveau();
    
    return 1;
}

Uint32 GetPixel(SDL_Surface* surface, int x, int y)
{
    int bpp = surface->format->BytesPerPixel;
    /*  p est l'addresse du pixel que l'on veut récupérer */
    Uint8 *p = (Uint8 *)surface->pixels + y * surface->pitch + x * bpp;
    
    switch(bpp)
    {
        case 1:
            return *p;
            
        case 2:
            return *(Uint16 *)p;
            
        case 3:
            if(SDL_BYTEORDER == SDL_BIG_ENDIAN)
                return p[0] << 16 | p[1] << 8 | p[2];
            else
                return p[0] | p[1] << 8 | p[2] << 16;
            
        case 4:
            return *(Uint32 *)p;
            
        default:
            return 0;  /* Ne devrait pas arriver, mais supprime les avertissements du compilateur */
    }
}
