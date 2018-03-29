//
//  Basiques.hpp
//  sdlcommande
//
//  Created by MacBook Pro on 14/11/2017.
//  Copyright © 2017 MacBook Pro. All rights reserved.
//

#ifndef Basiques_hpp
#define Basiques_hpp

#include <stdio.h>
#include <string>
#include <SDL2/SDL.h>

using namespace std;

bool estClique(SDL_Surface *bouton, SDL_Rect posBouton, SDL_Event event);
void messageErreur(string texte);
void afficherTexture(SDL_Surface *texture);

#endif /* Basiques_hpp */
