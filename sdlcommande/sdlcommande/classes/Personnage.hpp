//
//  Personnage.hpp
//  sdlcommande
//
//  Created by MacBook Pro on 21/11/2017.
//  Copyright © 2017 MacBook Pro. All rights reserved.
//

#ifndef Personnage_hpp
#define Personnage_hpp

#include <stdio.h>
#include <SDL2/SDL.h>
#include <string>
#include "Widget.hpp"

class Personnage : public Widget
{
public:
    std::string get_nom();
    int get_age();
    
private:
    std::string m_nom;
    int m_age;
};

#endif /* Personnage_hpp */
