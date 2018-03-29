//
//  Widget.cpp
//  sdlcommande
//
//  Created by MacBook Pro on 25/11/2017.
//  Copyright © 2017 MacBook Pro. All rights reserved.
//

#include "Widget.hpp"
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include <string>

using namespace std;

Widget::Widget(): m_estAffiche(false), m_image(NULL), m_position({0, 0, 0, 0})
{
    
}

Widget::Widget(string chemin) : m_estAffiche(false), m_image(IMG_Load(chemin.c_str())), m_position({0, 0, m_image->w, m_image->h})
{
    
}

Widget::Widget(string chemin, SDL_Rect position) : m_estAffiche(false), m_image(IMG_Load(chemin.c_str())), m_position({position.x, position.y, m_image->w, m_image->h})
{
    
}

Widget::Widget(string chemin, SDL_Rect position, bool estAffiche) : m_estAffiche(estAffiche), m_image(IMG_Load(chemin.c_str())), m_position({position.x, position.y, m_image->w, m_image->h})
{
    
}

Widget::~Widget()
{
    delete m_image;
}

void Widget::afficher()
{
    m_estAffiche = true;
}

void Widget::cacher()
{
    m_estAffiche = false;
}

bool Widget::get_estAffiche() const
{
    return m_estAffiche;
}

SDL_Surface* Widget::get_image() const
{
    return m_image;
}

void Widget::set_image(std::string chemin)
{
    m_image = IMG_Load(chemin.c_str());
}

int Widget::get_hauteur() const
{
    return m_position.h;
}

int Widget::get_largeur() const
{
    return m_position.w;
}

int Widget::get_positionX() const
{
    return m_position.x;
}

int Widget::get_positionY() const
{
    return m_position.y;
}

void Widget::set_positionX(int positionX)
{
    m_position.x = positionX;
}

void Widget::set_positionY(int positionY)
{
    m_position.y = positionY;
}

SDL_Rect* Widget::get_position()
{
    return &m_position;
}
