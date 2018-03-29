//
//  constants.h
//  sdlcommande
//
//  Created by MacBook Pro on 18/11/2017.
//  Copyright © 2017 MacBook Pro. All rights reserved.
//

#ifndef constants_h
#define constants_h

#include <string>
#include <stdio.h>

using namespace std;

//Screen dimension constants
const int SCREEN_WIDTH = 1280;
const int SCREEN_HEIGHT = 800;
const int TAILLE_CASE = 40;

//Dialogues

const int TEMPS_VITESSE_TEXTE = 40;

//Fonds
const int VILLAGE1 = 0;
const int FOND1 = 1;

string const FICHIER_VILLAGE1 = "images/fonds/village1.txt";
string const FICHIER_FOND1 = "images/fonds/fond1.txt";

//Personnages constants
const int GALDIOS = 1;
const int BALDION = 2;
const int ELEYNA = 3;

string const IMAGE_GALDIOS = "images/personnages/galdios.png";
string const IMAGE_BALDION = "images/personnages/baldion.png";
string const IMAGE_ELEYNA = "images/personnages/eleyna.png";

string const TEXTE_GALDIOS = "texte/galdios.txt";
string const TEXTE_BALDION = "texte/baldion.txt";
string const TEXTE_ELEYNA = "texte/eleyna.txt";

//Textures
const int NB_TEXTURE_WIDTH = SCREEN_WIDTH / TAILLE_CASE;
const int NB_TEXTURE_HEIGHT = SCREEN_HEIGHT / TAILLE_CASE;

string const IMAGE_HERBE = "images/textures/herbe.png";
string const IMAGE_CASE_ROUGE = "images/textures/caseRouge.png";
string const IMAGE_MAISON = "images/textures/maison.png";
string const IMAGE_VIDE = "images/textures/vide.png";
string const IMAGE_PERSO = "images/textures/personnage.png";
string const IMAGE_NOIR = "images/textures/noir.png";
string const IMAGE_GRIS = "images/textures/gris.png";

enum Texture {VIDE, QQCHOSE, SORTIE, HERBE, MAISON, CASE_ROUGE, ARBRE};

//Boutons
string const IMAGE_BOUTON_1 = "images/bouton1.png";
string const IMAGE_BOUTON_2 = "images/bouton2.png";
string const IMAGE_BOUTON_EXIT = "images/Exit.png";

//Parties du programme
const int QUITTER = 0;
const int ACCUEIL = 1;
const int DEPLACEMENT = 2;
const int COMBAT = 3;
const int CHAPITRE1 = 4;
const int CHAPITRE2 = 1;

//objets jeux
const string IMAGE_BILLE_BLANCHE = "images/combat/attaqueLourde/billeBlanche.png";
const string IMAGE_FOND_NIVEAU_1 = "images/combat/attaqueLourde/niveau1.png";

//COMBAT

//types d'attaques
enum Attaques {ATT_LOURDE, ATT_RAPIDE};

//attaque lourde
const int NB_ETAGES = 10;
const int LARGEUR_ETAGE = 20;

#endif /* constants_h */
