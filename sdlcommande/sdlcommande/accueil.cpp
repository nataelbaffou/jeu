//
//  accueil.cpp
//  
//
//  Created by MacBook Pro on 30/12/2017.
//

#include "accueil.hpp"
#include "Basiques.hpp"
#include "constants.h"
#include "Bouton.hpp"
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>

int accueil(SDL_Surface *screen, SDL_Window *window)
{
    int screenWidth, screenHeight;
    SDL_GetWindowSize(window, &screenWidth, &screenHeight);
    
    SDL_Surface *couleurDeFond = NULL;
    couleurDeFond = SDL_CreateRGBSurface(SDL_SWSURFACE, screenWidth, screenHeight, 32, 0, 0, 0, 0);
    
    Bouton bouton1(IMAGE_BOUTON_1.c_str());
    Bouton bouton2(IMAGE_BOUTON_2.c_str());
    Bouton bouton3(IMAGE_BOUTON_1.c_str());
    Bouton boutonExit(IMAGE_BOUTON_EXIT.c_str());
    
    bouton1.afficher();
    bouton2.afficher();
    bouton3.afficher();
    boutonExit.afficher();
    
    SDL_Rect positionFond;
    positionFond.x = 0;
    positionFond.y = 0;
    
    bouton1.set_positionX(30);
    bouton1.set_positionY(50);
    bouton2.set_positionX(bouton1.get_positionX());
    bouton2.set_positionY(bouton1.get_positionY() + bouton1.get_hauteur() + 20);
    bouton3.set_positionX(bouton1.get_positionX());
    bouton3.set_positionY(bouton2.get_positionY() + bouton2.get_hauteur() + 20);
    boutonExit.set_positionX(screenWidth - boutonExit.get_largeur());
    boutonExit.set_positionY(0);
    
    // initialisation
    
    SDL_SetWindowIcon(window, IMG_Load("images/icone.bmp"));
    
    Uint32 couleurFond = SDL_MapRGB(screen->format, 0, 0, 0);
    SDL_FillRect(couleurDeFond, NULL, couleurFond);
    SDL_BlitSurface(couleurDeFond, NULL, screen, &positionFond);
    
    SDL_BlitSurface(bouton1.get_image(), NULL, screen, bouton1.get_position());
    SDL_BlitSurface(bouton2.get_image(), NULL, screen, bouton2.get_position());
    SDL_BlitSurface(boutonExit.get_image(), NULL, screen, boutonExit.get_position());
    
    
    SDL_UpdateWindowSurface( window );
    
    SDL_WarpMouseInWindow(window, screen->w/2, screen->h/2);
    
    int continuer = 1;
    SDL_Event event;
    
    while (continuer)
    {
        SDL_PollEvent(&event);
        switch(event.type)
        {
            case SDL_QUIT:
                continuer = 0;
                break;
                
            case SDL_KEYDOWN:
                switch(event.key.keysym.sym)
            {
                case SDLK_ESCAPE:
                    continuer = 0;
                    break;
            }
                break;
            case SDL_MOUSEBUTTONDOWN:
                switch (event.button.button)
                {
                    case SDL_BUTTON_LEFT:
                        if (bouton1.estClique(event) and bouton1.get_estAffiche())
                        {
                            /*
                            couleurFond = SDL_MapRGB(screen->format, 255, 0, 0);
                            chapitre1 = true;
                            bouton1.cacher();
                            bouton2.cacher();
                            */
                            return CHAPITRE1;
                        }
                        if (bouton2.estClique(event) and bouton2.get_estAffiche())
                        {
                            /*
                            couleurFond = SDL_MapRGB(screen->format, 0, 0, 255);
                            testDeplacemeent = true;
                            bouton2.cacher();
                            */
                            return DEPLACEMENT;
                        }
                        if (bouton3.estClique(event) and bouton3.get_estAffiche())
                        {
                            return COMBAT;
                        }
                        if (boutonExit.estClique(event))
                        {
                            return QUITTER;
                        }
                        break;
                }
                break;
        }
        SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 255, 255, 255));
        SDL_FillRect(couleurDeFond, NULL, couleurFond);
        SDL_BlitSurface(couleurDeFond, NULL, screen, &positionFond);
        if (bouton1.get_estAffiche()) {
            SDL_BlitSurface(bouton1.get_image(), NULL, screen, bouton1.get_position());
        }
        if (bouton2.get_estAffiche()) {
            SDL_BlitSurface(bouton2.get_image(), NULL, screen, bouton2.get_position());
        }
        if (bouton3.get_estAffiche()){
            SDL_BlitSurface(bouton3.get_image(), NULL, screen, bouton3.get_position());
        }
        SDL_BlitSurface(boutonExit.get_image(), NULL, screen, boutonExit.get_position());
        /*if (chapitre1) {
            mainChapitre1(screen, window);
            chapitre1 = false;
        }
        if (testDeplacemeent) {
            seDeplacer(screen, window);
            testDeplacemeent = false;
        }*/
        SDL_UpdateWindowSurface(window);
    }
    SDL_FreeSurface(couleurDeFond);
    return QUITTER;
}
