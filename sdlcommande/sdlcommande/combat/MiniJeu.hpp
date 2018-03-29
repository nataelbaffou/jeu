//
//  miniJeu.hpp
//  sdlcommande
//
//  Created by MacBook Pro on 31/01/2018.
//  Copyright © 2018 MacBook Pro. All rights reserved.
//

#ifndef miniJeu_hpp
#define miniJeu_hpp

#include <stdio.h>
#include <SDL2/SDL.h>
#include <string>

class MiniJeu
{
public:
    MiniJeu(SDL_Surface *screen, SDL_Window *window, int typeAttaque, int niveau);
    void initialisation();
    void lancerNiveau();
    //~MiniJeu();
    
protected:
    SDL_Rect m_dimensions;
    std::string m_nom;
    int m_typeAttaque;
    int m_niveauAct;
    SDL_Surface *m_screen;
    SDL_Window *m_window;
};

#endif /* miniJeu_hpp */
