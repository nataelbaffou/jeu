//
//  Widget.hpp
//  sdlcommande
//
//  Created by MacBook Pro on 25/11/2017.
//  Copyright © 2017 MacBook Pro. All rights reserved.
//

#ifndef Widget_hpp
#define Widget_hpp

#include <stdio.h>
#include <SDL2/SDL.h>
#include <string>

class Widget
{
public:
    Widget();
    Widget(std::string chemin);
    Widget(std::string chemin, SDL_Rect position);
    Widget(std::string chemin, SDL_Rect position, bool estAffiche);
    ~Widget();
    
    void cacher();
    void afficher();
    bool get_estAffiche() const;
    
    SDL_Surface *get_image() const;
    void set_image(std::string chemin);
    
    int get_hauteur() const;
    int get_largeur() const;
    
    int get_positionX() const;
    void set_positionX(int positionX);
    
    int get_positionY() const;
    void set_positionY(int positionY);
    
    SDL_Rect *get_position();
    
protected:
    SDL_Surface *m_image;
    SDL_Rect m_position;
    bool m_estAffiche;
};

#endif /* Widget_hpp */
