//
//  deplacement.cpp
//  sdlcommande
//
//  Created by MacBook Pro on 19/11/2017.
//  Copyright © 2017 MacBook Pro. All rights reserved.
//

#include "deplacement.hpp"
#include "Basiques.hpp"
#include "constants.h"
#include <stdio.h>
#include <fstream>
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>

#include <iostream>

SDL_Surface* genererFondComplet(SDL_Surface* screen)
{
    SDL_Surface *texture = NULL, *fondEntier = NULL;
    
    char charTexture = NULL;
    int nombreTexture = NULL;
    int nombreLignes = chercherNombreLignes();
    int nombreColonnes = chercherNombreColonnes();
    
    
    SDL_Rect positionTexture;
    positionTexture.x = 0;
    positionTexture.y = 0;
    
    ifstream fichierFond("images/fonds/fond1.txt");
    
    fondEntier = SDL_CreateRGBSurface(SDL_SWSURFACE, nombreColonnes*TAILLE_CASE, nombreLignes*TAILLE_CASE, 32, 0, 0, 0, 0);
    SDL_FillRect(fondEntier, NULL, SDL_MapRGB(screen->format, 255, 255, 255));
    
    for (int i = 0; i<nombreLignes; i++) {
        for (int j = 0; j<nombreColonnes; j++) {
            fichierFond.get(charTexture);
            if (int(charTexture)<48) {
                fichierFond.get(charTexture);
            }
            nombreTexture = int(charTexture) - 48;
            if(not (nombreTexture == VIDE))
            {
                texture = choixTexture(nombreTexture, screen);
                SDL_BlitSurface(texture, NULL, fondEntier, &positionTexture);
            }
            positionTexture.x += TAILLE_CASE;
        }
        positionTexture.x = 0;
        positionTexture.y += TAILLE_CASE;
    }
    
    SDL_FreeSurface(texture);
    return fondEntier;
}

SDL_Surface* genererFondAffiche(SDL_Surface* screen, SDL_Window *window, SDL_Surface *fondComplet, SDL_Rect positionJoueur)
{
    int screenWidth, screenHeight;
    SDL_GetWindowSize(window, &screenWidth, &screenHeight);
    
    SDL_Surface *fondAffiche = NULL;
    fondAffiche = SDL_CreateRGBSurface(SDL_SWSURFACE, screenWidth, screenHeight, 32, 0, 0, 0, 0);
    SDL_FillRect(fondAffiche, NULL, SDL_MapRGB(screen->format, 0, 0, 0));
    
    SDL_Rect positionFond, fondACopier;
    positionFond.x = 0;
    positionFond.y = 0;
    fondACopier.x = positionJoueur.x - (screenWidth/2);
    fondACopier.y = positionJoueur.y - (screenHeight/2);
    fondACopier.w = screenWidth;
    fondACopier.h = screenHeight;
    
    SDL_BlitSurface(fondComplet, &fondACopier, fondAffiche, &positionFond);
    
    return fondAffiche;
}

SDL_Surface* choixTexture(int nombre, SDL_Surface* screen)
{
    switch (nombre)
    {
        case HERBE:
        {
            SDL_Surface *herbe = NULL;
            herbe = IMG_Load(IMAGE_HERBE.c_str());
            return herbe;
            break;
        }
        case CASE_ROUGE:
        {
            SDL_Surface *caseRouge = NULL;
            caseRouge = IMG_Load(IMAGE_CASE_ROUGE.c_str());
            return caseRouge;
            break;
        }
        case MAISON:
        {
            SDL_Surface *maison = NULL;
            maison = IMG_Load(IMAGE_MAISON.c_str());
            return maison;
            break;
        }
    }
    
    SDL_Surface *noir = NULL;
    noir = SDL_CreateRGBSurface(SDL_SWSURFACE, TAILLE_CASE, TAILLE_CASE, 32, 0, 0, 0, 0);
    SDL_FillRect(noir, NULL, SDL_MapRGB(screen->format, 0, 0, 0));
    
    return noir;
}

int seDeplacer(SDL_Surface *screen, SDL_Window *window)
{
    int screenWidth, screenHeight;
    SDL_GetWindowSize(window, &screenWidth, &screenHeight);
    
    SDL_Surface *fondSurface = NULL, *fondComplet = NULL, *joueur = NULL;
    
    fondComplet = genererFondComplet(screen);
    
    joueur = IMG_Load(IMAGE_PERSO.c_str());
    
    int positionRelativeJoueurAbscisse = 25;
    int positionRelativeJoueurOrdonnee = 18;
    int tailleMapAbscisse = chercherNombreColonnes();
    int tailleMapOrdonnee = chercherNombreLignes();
    
    SDL_Rect positionFond, positionJoueurReel, positionJoueurEcran;
    positionFond.x = 0;
    positionFond.y = 0;
    positionJoueurEcran.x = screenWidth / 2 - joueur->w / 2;
    positionJoueurEcran.y = screenHeight / 2 - joueur->h / 2 ;
    positionJoueurReel.x = positionRelativeJoueurAbscisse * TAILLE_CASE;
    positionJoueurReel.y = positionRelativeJoueurOrdonnee * TAILLE_CASE;
    
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
                    case SDLK_UP:
                        if(positionRelativeJoueurOrdonnee > 1)
                            positionRelativeJoueurOrdonnee --;
                        break;
                    case SDLK_DOWN:
                        if(positionRelativeJoueurOrdonnee < tailleMapOrdonnee - 1)
                            positionRelativeJoueurOrdonnee ++;
                        break;
                    case SDLK_RIGHT:
                        if(positionRelativeJoueurAbscisse < tailleMapAbscisse - 1)
                            positionRelativeJoueurAbscisse ++;
                        break;
                    case SDLK_LEFT:
                        if(positionRelativeJoueurAbscisse > 1)
                            positionRelativeJoueurAbscisse --;
                        break;
                    case SDLK_ESCAPE:
                        continuer = 0;
                        break;
                }
                break;
        }
        positionJoueurReel.x = positionRelativeJoueurAbscisse * TAILLE_CASE;
        positionJoueurReel.y = positionRelativeJoueurOrdonnee * TAILLE_CASE;
        fondSurface = genererFondAffiche(screen, window, fondComplet, positionJoueurReel);
        SDL_BlitSurface(fondSurface, NULL, screen, &positionFond);
        SDL_BlitSurface(joueur, NULL, screen, &positionJoueurEcran);
        SDL_UpdateWindowSurface(window);
    }
    SDL_FreeSurface(fondSurface);
    SDL_FreeSurface(fondComplet);
    SDL_FreeSurface(joueur);
    return 1;
}

void deplacementHaut()
{
    
}

int chercherNombreColonnes()
{
    int nombreColonnes = -1;
    char lettre = 'a';
    
    ifstream fichierFondComptage("images/fonds/fond1.txt");
    
    while (int(lettre) != 10) {
        fichierFondComptage.get(lettre);
        nombreColonnes++;
    }
    return nombreColonnes;
}

int chercherNombreLignes()
{
    int nombreLignes = 0;
    string phrase;
    ifstream fichierFondComptage("images/fonds/fond1.txt");
    while (getline(fichierFondComptage, phrase)) {
        nombreLignes++;
    }
    return nombreLignes;
}
