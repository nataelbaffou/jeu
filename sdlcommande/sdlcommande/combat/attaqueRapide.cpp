//
//  attaqueRapide.cpp
//  sdlcommande
//
//  Created by MacBook Pro on 30/12/2017.
//  Copyright © 2017 MacBook Pro. All rights reserved.
//

/*
 jeu de plateforme minimaliste
 but :
    récupérer un objet
 jeu :
    se déplacer et éviter les pieges jusqu'à l'objet
*/

#include "attaqueRapide.hpp"
#include "constants.h"

AttaqueRapide::AttaqueRapide(SDL_Surface *screen, SDL_Window *window, int typeAttaque, int niveau) : MiniJeu(screen, window, typeAttaque, niveau)
{

}
