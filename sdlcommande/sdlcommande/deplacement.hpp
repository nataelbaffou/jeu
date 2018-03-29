//
//  deplacement.hpp
//  sdlcommande
//
//  Created by MacBook Pro on 19/11/2017.
//  Copyright © 2017 MacBook Pro. All rights reserved.
//

#ifndef deplacement_hpp
#define deplacement_hpp

#include <stdio.h>
#include <SDL2/SDL.h>

SDL_Surface* genererFondAffiche(SDL_Surface* screen, SDL_Window *window, SDL_Surface *fondComplet, SDL_Rect positionJoueur);
SDL_Surface* genererFondComplet(SDL_Surface* screen);
SDL_Surface* choixTexture(int nombre, SDL_Surface* screen);
int seDeplacer(SDL_Surface *screen, SDL_Window *window);
int chercherNombreLignes();
int chercherNombreColonnes();

#endif /* deplacement_hpp */
