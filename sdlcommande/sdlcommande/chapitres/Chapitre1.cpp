//
//  Chapitre1.cpp
//  sdlcommande
//
//  Created by MacBook Pro on 14/11/2017.
//  Copyright © 2017 MacBook Pro. All rights reserved.
//

#include "Chapitre1.hpp"
#include "Basiques.hpp"
#include "dialogue.hpp"
#include "deplacement.hpp"
#include "constants.h"
#include <stdio.h>
#include <SDL2/SDL.h>

int mainChapitre1(SDL_Surface *screen, SDL_Window *window)
{
    afficherDiscussion(screen, window, 0, GALDIOS);
    afficherDiscussion(screen, window, 0, BALDION);
    afficherDiscussion(screen, window, 1, GALDIOS);
    afficherDiscussion(screen, window, 1, BALDION);
    afficherDiscussion(screen, window, 2, GALDIOS);
    afficherDiscussion(screen, window, 2, BALDION);
    return CHAPITRE2;
}
