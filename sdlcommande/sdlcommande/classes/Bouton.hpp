//
//  Bouton.hpp
//  sdlcommande
//
//  Created by MacBook Pro on 21/11/2017.
//  Copyright © 2017 MacBook Pro. All rights reserved.
//

#ifndef Bouton_hpp
#define Bouton_hpp

#include <stdio.h>
#include <SDL2/SDL.h>
#include <string>
#include "Widget.hpp"

class Bouton : public Widget
{
public:
    Bouton();
    Bouton(std::string chemin);
    Bouton(std::string chemin, SDL_Rect position);
    Bouton(std::string chemin, SDL_Rect position, bool estAffiche);
    
    bool estClique(SDL_Event event) const;
    
    ~Bouton();

};

#endif /* Bouton_hpp */
