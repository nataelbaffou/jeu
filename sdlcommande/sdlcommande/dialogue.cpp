//
//  dialogue.cpp
//  sdlcommande
//
//  Created by MacBook Pro on 19/11/2017.
//  Copyright © 2017 MacBook Pro. All rights reserved.
//

#include "dialogue.hpp"
#include "constants.h"
#include "Basiques.hpp"
#include <stdio.h>
#include <string>
#include <string.h>
#include <fstream>
#include <SDL2/SDL.h>
#include <SDL2_ttf/SDL_ttf.h>
#include <SDL2_image/SDL_image.h>

using namespace std;

void blitterMessage(string texte, int perso, SDL_Surface *screen)
{
    
    if(TTF_Init() == -1)
    {
        fprintf(stderr, "Erreur d'initialisation de TTF_Init : %s\n", TTF_GetError());
        exit(EXIT_FAILURE);
    }
    else
    {
        SDL_Surface *dialogueFond = NULL, *surfacePerso = NULL, *surfaceTexte = NULL;
        dialogueFond = IMG_Load("images/dialogue.png");
        surfacePerso = imagePerso(perso);
        SDL_Rect positionTexte, positionPerso, positionFond;
        positionFond.x = 10;
        positionFond.y = 400;
        positionTexte.x = positionFond.x + 20;
        positionTexte.y = positionFond.y + 20;
        positionPerso.x = positionFond.x + dialogueFond->w + 10;
        positionPerso.y = positionFond.y + 10;
        TTF_Font *police = NULL;
        
        police = TTF_OpenFont("fonts/times.ttf", 20);
        SDL_Color couleurBleue = {0, 0, 255};
        SDL_Color couleurBlanc = {255, 255, 255};
        
        surfaceTexte = TTF_RenderUTF8_Shaded(police, texte.c_str(), couleurBleue, couleurBlanc);
        
        SDL_BlitSurface(dialogueFond, NULL, screen, &positionFond);
        SDL_BlitSurface(surfaceTexte, NULL, screen, &positionTexte);
        SDL_BlitSurface(surfacePerso, NULL, screen, &positionPerso);
        
        SDL_FreeSurface(dialogueFond);
        SDL_FreeSurface(surfaceTexte);
        SDL_FreeSurface(surfacePerso);
        
        TTF_CloseFont(police);
        TTF_Quit();
    }
}

string chercherTexte(int perso, int phrase)
{
    string nomFichierTexte, message;
    switch (perso) {
        case GALDIOS:
            nomFichierTexte = TEXTE_GALDIOS;
            break;
        case BALDION:
            nomFichierTexte = TEXTE_BALDION;
            break;
        case ELEYNA:
            nomFichierTexte = TEXTE_ELEYNA;
            break;
    }
    
    ifstream fichierTexte(nomFichierTexte.c_str());
    
    if(fichierTexte)
    {
        for (int i = 0; i <= phrase; i++) {
            if(not getline(fichierTexte, message))
            {
                break;
            }
        }
    }
    else
    {
        messageErreur("impossible d'ouvrir le fichier : " + nomFichierTexte);
    }
    
    return message;
}

SDL_Surface* imagePerso(int perso)
{
    SDL_Surface *imageProfile = NULL;
    switch (perso) {
        case GALDIOS:
            imageProfile = IMG_Load(IMAGE_GALDIOS.c_str());
            break;
        case BALDION:
            imageProfile = IMG_Load(IMAGE_BALDION.c_str());
            break;
        case ELEYNA:
            imageProfile = IMG_Load(IMAGE_ELEYNA.c_str());
            break;
    }
    return imageProfile;
}

int afficherDiscussion(SDL_Surface *screen, SDL_Window *window, int phrase, int perso)
{
    string texte = chercherTexte(perso, phrase);
    
    int nombreCaract  = 0;
    int longueurTexte = int(texte.size());
    int tempsActuel = SDL_GetTicks();
    int tempsPrecedent = tempsActuel;
    
    SDL_Event event;
    int continuer = 1;
    bool toucheRetour = true;
    
    while (continuer) {
        
        SDL_PollEvent(&event);
        switch(event.type)
        {
            case SDL_QUIT:
                continuer = 0;
                break;
            case SDL_KEYDOWN:
                switch (event.key.keysym.sym) {
                    case SDLK_ESCAPE:
                        continuer = 0;
                        break;
                    case SDLK_RETURN:
                        if(not toucheRetour)
                        {
                            if (nombreCaract == longueurTexte) {
                                continuer = 0;
                            }
                            nombreCaract = longueurTexte;
                            toucheRetour = true;
                        }
                        break;
                }
                break;
            case SDL_KEYUP:
                switch (event.key.keysym.sym) {
                    case SDLK_RETURN:
                        toucheRetour = false;
                        break;
                }
        }
        tempsActuel = SDL_GetTicks();
        if (tempsActuel - tempsPrecedent > TEMPS_VITESSE_TEXTE and nombreCaract < longueurTexte) {
            tempsPrecedent = tempsActuel;
            nombreCaract++;
        }
        
        blitterMessage(texte.substr(0, nombreCaract), perso, screen);
        SDL_UpdateWindowSurface(window);
    }
    return 1;
}
