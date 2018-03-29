//
//  Fond.hpp
//  sdlcommande
//
//  Created by MacBook Pro on 05/12/2017.
//  Copyright © 2017 MacBook Pro. All rights reserved.
//

#ifndef Fond_hpp
#define Fond_hpp

#include <stdio.h>
#include <SDL2/SDL.h>
#include <vector>
#include <string>

class Fond
{

public:
    Fond();
    Fond(int fondConstante);
    ~Fond();
    
    void definirFond(int nomNouveauFond);
    int get_positionX();
    int get_positionY();
    SDL_Surface* get_renduFond();
    
    void deplacementDroite();
    void deplacementGauche();
    void deplacementHaut();
    void deplacementBas();
    
private:
    void initialiserTableauImages();
    void initialiserTableauNombres();
    void actualiserNomFondActuel();
    
    int chercherNombreLignes() const;
    int chercherNombreColonnes() const;
    
    int m_valeurFondActuel;
    std::string m_nomFondActuel;
    SDL_Rect m_position;
    SDL_Surface* m_surfaceFondActuel;
    std::vector<std::vector<int>> m_tableauNombres;
    SDL_Surface* m_tableauImages[10];
    
};

#endif /* Fond_hpp */
