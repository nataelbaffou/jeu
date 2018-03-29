//
//  attaqueLourde.cpp
//  sdlcommande
//
//  Created by MacBook Pro on 30/12/2017.
//  Copyright © 2017 MacBook Pro. All rights reserved.
//

#include "attaqueLourde.hpp"
#include "constants.h"
#include "Widget.hpp"
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include <string>
#include <iostream>
#include <fstream>
#include <combat.hpp>
#include <stdio.h>

using namespace std;


AttaqueLourde::AttaqueLourde(SDL_Surface *screen, SDL_Window *window, int typeAttaque, int niveau) : MiniJeu(screen, window, typeAttaque, niveau)
{
    
}

void AttaqueLourde::chargerNiveau(int niveau)
{
    int screenWidth, screenHeight;
    SDL_GetWindowSize(m_window, &screenWidth, &screenHeight);
    
    char caract = NULL;
    ifstream file("maps/niveaux/" + m_nom + "/" + to_string(niveau) + ".txt");
    for (int i = 0; i < NB_ETAGES; i++) {
        for (int j = 0; j < LARGEUR_ETAGE; j++) {
            file.get(caract);
            if(int(caract)<48)
            {
                cout << caract;
                file.get(caract);
            }
            cout << caract;
            m_tblEtages[i][j] = caract - 48;
        }
    }
    
    for(int i = 0; i < NB_ETAGES; i++)
    {
        m_tbLPlacementLignes[i] = 5;
    }
    tbl_Surfaces[0] = IMG_Load(IMAGE_NOIR.c_str());
    tbl_Surfaces[1] = IMG_Load(IMAGE_GRIS.c_str());
    bille.set_image(IMAGE_BILLE_BLANCHE.c_str());
    bille.set_positionX(m_dimensions.w/2 - bille.get_largeur()/2 + 20);
    bille.set_positionY(10);
    m_dimensions.x = int(screenWidth / 2 - m_dimensions.w / 2 - 20);
    m_dimensions.y = int(screenHeight / 2 - m_dimensions.h / 2 - 40);
}

SDL_Surface* AttaqueLourde::genererImage()
{
    SDL_Surface* imageGeneree = NULL;
    
    imageGeneree = SDL_CreateRGBSurface(SDL_SWSURFACE, m_dimensions.w+40, m_dimensions.h+TAILLE_CASE+40, 32, 0, 0, 0, 0);
    SDL_FillRect(imageGeneree, NULL, SDL_MapRGB(m_screen->format, 255, 0, 0));
    
    SDL_Rect positionTexture;
    positionTexture.y = 0;
    
    for (int i = 0; i < NB_ETAGES; i++) {
        positionTexture.y = (i+1) * TAILLE_CASE + 20;
        for (int j = 0; j < NB_ETAGES; j++) {
            positionTexture.x = (j) * TAILLE_CASE + 20;
            int posInit = m_tbLPlacementLignes[i];
            switch (m_tblEtages[i][j + posInit]) {
                case 0:
                    SDL_BlitSurface(tbl_Surfaces[0], NULL, imageGeneree, &positionTexture);
                    break;
                case 1:
                    SDL_BlitSurface(tbl_Surfaces[1], NULL, imageGeneree, &positionTexture);
                default:
                    break;
            }
        }
    }
    
    Uint8 r, g, b;
    Uint32 pixel = GetPixel(imageGeneree, bille.get_positionX()+12, bille.get_positionY()+26);
    SDL_GetRGB(pixel, imageGeneree->format, &r, &g, &b);
    if (r > 10 || g > 10 || b > 10) {
        bille.set_positionY(bille.get_positionY()+2);
    }
    
    SDL_BlitSurface(bille.get_image(), NULL, imageGeneree, bille.get_position());
    
    return imageGeneree;
}

void AttaqueLourde::ecrireNiveau()
{
    SDL_Rect positionJeu;
    positionJeu = m_dimensions;
    
    SDL_BlitSurface(genererImage(), NULL, m_screen, &positionJeu);
    SDL_UpdateWindowSurface(m_window);
}

void AttaqueLourde::lancerNiveau()
{
    this->chargerNiveau(m_niveauAct);
    ecrireNiveau();
    
    bool keyRight = true, keyLeft = true;
    
    SDL_Event event;
    int continuer = 1;
    
    while (continuer) {
        
        SDL_PollEvent(&event);
        switch(event.type)
        {
            case SDL_QUIT:
                continuer = 0;
                break;
            case SDL_KEYDOWN:
                switch (event.key.keysym.sym)
            {
                case SDLK_RIGHT:
                    if(keyRight)
                    {
                        deplacementLigne(-1);
                        keyRight = false;
                    }
                    break;
                case SDLK_LEFT:
                    if(keyLeft)
                    {
                        deplacementLigne(1);
                        keyLeft = false;
                    }
                    break;
                case SDLK_ESCAPE:
                    continuer = 0;
                    break;
            }
            case SDL_KEYUP:
                switch (event.key.keysym.sym)
            {
                case SDLK_RIGHT:
                    keyRight = true;
                    break;
                case SDLK_LEFT:
                    keyLeft = true;
                    break;
            }
                break;
        }
        ecrireNiveau();
    }
}

void AttaqueLourde::deplacementLigne(int direction)
{
    int ligne = int((bille.get_positionY()+bille.get_hauteur()-62.0)/(m_dimensions.h/NB_ETAGES)+1);
    m_tbLPlacementLignes[ligne] += direction;
    if(m_tbLPlacementLignes[ligne] < 0)
        m_tbLPlacementLignes[ligne] = 0;
    if(m_tbLPlacementLignes[ligne]>LARGEUR_ETAGE)
        m_tbLPlacementLignes[ligne] = LARGEUR_ETAGE;
}




