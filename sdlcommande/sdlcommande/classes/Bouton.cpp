//
//  Bouton.cpp
//  sdlcommande
//
//  Created by MacBook Pro on 21/11/2017.
//  Copyright © 2017 MacBook Pro. All rights reserved.
//

#include "Bouton.hpp"
#include <SDL2/SDL.h>
#include <string>
#include <SDL2_image/SDL_image.h>

using namespace std;

Bouton::Bouton() : Widget()
{

}

Bouton::Bouton(string chemin) : Widget(chemin)
{
    
}

Bouton::Bouton(string chemin, SDL_Rect position) : Widget(chemin, position)
{
    
}

Bouton::Bouton(string chemin, SDL_Rect position, bool estAffiche) : Widget(chemin, position, estAffiche)
{
    
}

Bouton::~Bouton()
{

}

bool Bouton::estClique(SDL_Event event) const
{
    if (event.button.x >= m_position.x && event.button.x <= (m_position.x + m_image->w) && event.button.y >= m_position.y && event.button.y <= (m_position.y + m_image->h))
    {
        return true;
    }
    return false;
}
