//
//  combat.hpp
//  sdlcommande
//
//  Created by MacBook Pro on 30/12/2017.
//  Copyright © 2017 MacBook Pro. All rights reserved.
//

#ifndef combat_hpp
#define combat_hpp

#include <stdio.h>
#include <SDL2/SDL.h>

int mainCombat(SDL_Surface *screen, SDL_Window *window);
Uint32 GetPixel(SDL_Surface* surface, int x, int y);

#endif /* combat_hpp */
