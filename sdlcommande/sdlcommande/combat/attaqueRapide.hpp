//
//  attaqueRapide.hpp
//  sdlcommande
//
//  Created by MacBook Pro on 30/12/2017.
//  Copyright © 2017 MacBook Pro. All rights reserved.
//

#ifndef attaqueRapide_hpp
#define attaqueRapide_hpp

#include <stdio.h>
#include "MiniJeu.hpp"

class AttaqueRapide : public MiniJeu
{
public:
    AttaqueRapide(SDL_Surface *screen, SDL_Window *window, int typeAttaque, int niveau);
    ~AttaqueRapide();
    
private:
    
};

#endif /* attaqueRapide_hpp */
