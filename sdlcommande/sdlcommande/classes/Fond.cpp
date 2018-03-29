//
//  Fond.cpp
//  sdlcommande
//
//  Created by MacBook Pro on 05/12/2017.
//  Copyright © 2017 MacBook Pro. All rights reserved.
//

#include "Fond.hpp"
#include "constants.h"
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include <vector>
#include <string>
#include <fstream>
#include <iostream>

using namespace std;

Fond::Fond()
{
    
}

Fond::Fond(int fondConstante) : m_valeurFondActuel(fondConstante)
{
    
    for (int i = 0; i<10; i++) {
        m_tableauImages[i] = new SDL_Surface;
    }
    initialiserTableauNombres();
    initialiserTableauImages();
}

Fond::~Fond()
{
    for (int i = 0; i<10; i++) {
        delete m_tableauImages[i];
    }
    
    delete m_surfaceFondActuel;
}

void Fond::initialiserTableauImages()
{
    // initialisation des images cf constants.h
    m_tableauImages[HERBE] = IMG_Load(IMAGE_HERBE.c_str());
    m_tableauImages[MAISON] = IMG_Load(IMAGE_MAISON.c_str());
    m_tableauImages[CASE_ROUGE] = IMG_Load(IMAGE_CASE_ROUGE.c_str());
}

void Fond::initialiserTableauNombres()
{
    actualiserNomFondActuel();
    ifstream fichier(m_nomFondActuel.c_str());
    
    int nbLignes = chercherNombreLignes();
    int nbColonnes = chercherNombreColonnes();
    char charTexture = NULL;
    int nombreTexture = NULL;
    vector<int> ligne;
    
    for (int i = 0; i<nbLignes; i++) {
        for (int j = 0; j<nbColonnes; j++) {
            fichier.get(charTexture);
            if (int(charTexture)<48) {
                fichier.get(charTexture);
            }
            nombreTexture = int(charTexture) - 48;
            ligne.push_back(nombreTexture);
        }
        m_tableauNombres.push_back(ligne);
        ligne.clear();
    }
}

void Fond::actualiserNomFondActuel()
{
    switch (m_valeurFondActuel) {
        case VILLAGE1:
            m_nomFondActuel = FICHIER_FOND1;
            break;
        case FOND1:
            m_nomFondActuel = FICHIER_FOND1;
        default:
            cout << "erreur :  " << m_valeurFondActuel << " ne correspond à aucune constante";
            break;
    }
}

void Fond::definirFond(int nomNouveauFond)
{
    m_nomFondActuel = nomNouveauFond;
    initialiserTableauNombres();
    initialiserTableauImages();
}

int Fond::get_positionX()
{
    return m_position.x * TAILLE_CASE;
}

int Fond::get_positionY()
{
    return m_position.y * TAILLE_CASE;
}

SDL_Surface *Fond::get_renduFond()
{
    
    return m_surfaceFondActuel;
}

void Fond::deplacementBas()
{
    m_position.y++;
}

void Fond::deplacementHaut()
{
    m_position.y--;
}

void Fond::deplacementDroite()
{
    m_position.x++;
}

void Fond::deplacementGauche()
{
    m_position.x--;
}

int Fond::chercherNombreColonnes() const
{
    int nbColonnes = -1;
    char lettre = 'a';
    
    ifstream fichierFondComptage(m_nomFondActuel.c_str());
    
    while (int(lettre) != 10) {
        fichierFondComptage.get(lettre);
        nbColonnes++;
    }
    return nbColonnes;
}

int Fond::chercherNombreLignes() const
{
    int nbLignes = 0;
    string phrase;
    ifstream fichierFondComptage(m_nomFondActuel.c_str());
    while (getline(fichierFondComptage, phrase)) {
        nbLignes++;
    }
    return nbLignes;
}
