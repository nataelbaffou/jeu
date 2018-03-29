//
//  dialogue.hpp
//  sdlcommande
//
//  Created by MacBook Pro on 19/11/2017.
//  Copyright © 2017 MacBook Pro. All rights reserved.
//

#ifndef dialogue_hpp
#define dialogue_hpp

#include <stdio.h>
#include <string>
#include <SDL2/SDL.h>

using namespace std;

void blitterMessage(string texte, int perso, SDL_Surface *screen);
string chercherTexte(int perso, int phrase);
SDL_Surface* imagePerso(int perso);
int afficherDiscussion(SDL_Surface *screen, SDL_Window *window, int phrase, int perso);

#endif /* dialogue_hpp */
