//
//  miniJeu.cpp
//  sdlcommande
//
//  Created by MacBook Pro on 31/01/2018.
//  Copyright © 2018 MacBook Pro. All rights reserved.
//

#include "MiniJeu.hpp"
#include "constants.h"

MiniJeu::MiniJeu(SDL_Surface *screen, SDL_Window *window, int typeAttaque, int niveau) : m_typeAttaque(typeAttaque), m_niveauAct(niveau), m_screen(screen), m_window(window)
{
    initialisation();
}

void MiniJeu::initialisation()
{
    switch (m_typeAttaque) {
        case ATT_LOURDE:
            m_nom = "attaqueLourde";
            m_dimensions = {100, 100, TAILLE_CASE*10, TAILLE_CASE*NB_ETAGES};
            break;
        case ATT_RAPIDE:
            m_nom = "attaque rapide";
            m_dimensions = {100, 100, 400, 400};
            break;
            
        default:
            break;
    }
}
