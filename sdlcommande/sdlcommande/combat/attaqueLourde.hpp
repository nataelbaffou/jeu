//
//  attaqueLourde.hpp
//  sdlcommande
//
//  Created by MacBook Pro on 30/12/2017.
//  Copyright © 2017 MacBook Pro. All rights reserved.
//

#ifndef attaqueLourde_hpp
#define attaqueLourde_hpp

#include <stdio.h>
#include <SDL2/SDL.h>
#include "MiniJeu.hpp"
#include "constants.h"
#include "Widget.hpp"
#include <string>

void chargerNiveau(int niveau, std::string* chemin);
int attaqueLourde(SDL_Surface *screen, SDL_Window *window, int niveau);

class AttaqueLourde : public MiniJeu
{
public:
    AttaqueLourde(SDL_Surface *screen, SDL_Window *window, int typeAttaque, int niveau);
    void lancerNiveau();
    //~AttaqueLourde();
    
private:
    void chargerNiveau(int niveau);
    void ecrireNiveau();
    SDL_Surface* genererImage();
    void deplacementLigne(int direction);
    
    int m_tblEtages[NB_ETAGES][LARGEUR_ETAGE];
    int m_tbLPlacementLignes[NB_ETAGES];
    SDL_Surface *tbl_Surfaces[2];
    Widget bille;
};


#endif /* attaqueLourde_hpp */

