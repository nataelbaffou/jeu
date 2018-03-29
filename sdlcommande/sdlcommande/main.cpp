//
//  main.cpp
//  sdlcommande
//
//  Created by MacBook Pro on 13/09/2017.
//  Copyright © 2017 MacBook Pro. All rights reserved.
//

#include "Basiques.hpp"
#include "constants.h"
#include "dialogue.hpp"
#include "deplacement.hpp"
#include "Chapitre1.hpp"
#include "Bouton.hpp"
#include "accueil.hpp"
#include "combat.hpp"
#include <stdio.h>
#include <string>
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>

#include <iostream>

using namespace std;

int main( int argc, char* args[] )
{
    SDL_Window* window = NULL;
    
    if( SDL_Init( SDL_INIT_VIDEO | SDL_INIT_TIMER) < 0 )
    {
        printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
    }
    else
    {
        
        window = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_FULLSCREEN_DESKTOP);
        
        if( window == NULL )
        {
            printf( "La fenêtre n'a pas pu être créée : %s\n", SDL_GetError() );
        }
        else
        {
            SDL_Surface *screen;
            screen = SDL_GetWindowSurface(window);
            
            bool jeuEnCours = true;
            int partieALancer = ACCUEIL;
            
            while (jeuEnCours) {
                switch (partieALancer) {
                    case QUITTER:
                        jeuEnCours = false;
                    case ACCUEIL:
                        partieALancer  = accueil(screen, window);
                        break;
                    case DEPLACEMENT:
                        partieALancer = seDeplacer(screen, window);
                        break;
                    case COMBAT:
                        partieALancer = mainCombat(screen, window);
                        break;
                    case CHAPITRE1:
                        partieALancer = mainChapitre1(screen, window);
                        break;
                    default:
                        messageErreur("aucune partie ne correspond");
                        jeuEnCours = false;
                        break;
                }
            }
            
        }
        
    }
    
    SDL_DestroyWindow( window );
    
    SDL_Quit();
    
    return 0;
}
