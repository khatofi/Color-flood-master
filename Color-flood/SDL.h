



/**
*	\file SDL.h
*	\brief prototypes des fonctions et structures nécessaires pour l'exécution du jeu en mode graphique
*	\author Loubna Anthea Abdellah Bader
*	\version 3.0
*	\date 10 Mars 2017
*/

#ifndef SDL_H
#define SDL_H

#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include "grid_color.h"
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include "solveur_rapide.h"


/**
*	\fn void initialise()
*	\brief permet d'initialiser video responsable pour l'interface graphique et TTF responsable des polices(ecriture) et Gfx pour la modification des images et finalement sdl_mixer pour le son
*	\return void c'est une fonction de type void
*/
void initialise();
/**
*	\fn drawRectangle(SDL_Surface *ecran, int px, int py, int size, int r, int g, int b)
*	\brief permet de tracer un rectangle sur l'ecran dans les coordonnes (px,py) d'un taille de size avec le systeme de couleurs {RGB}
*	\param *ecran adresse de l'ecran
*	\param px abscisse de l'origine du rectangle
*	\param py ordonnée de l'origine du rectangle
*	\param size taille du rectangle
*	\param r,g,b la couleur du rectangle
*	\return void c'est une fonction de type void
*/
void drawRectangle(SDL_Surface *ecran, int px, int py, int size, int r, int g, int b);
/**
*	\fn fillScreen(SDL_Surface *ecran, int r, int g, int b)
*	\brief permet de remplir entierement une surface sdl par une couleur RGB
*	\param *ecran adresse de l'ecran
*	\param r,g,b la couleur du surface
*	\return void c'est une fonction de type void
*/
void fillScreen(SDL_Surface *ecran, int r, int g, int b);
/**
*	\fn drawTexture(SDL_Surface *ecran,int px, int py,double zoom, SDL_Surface *ima)
*	\brief permet de modifier le zoom d'une image(agrandir ou minimiser) grace rotozoomSurface fourni par SDL_GFX et la tracer sur l'ecran dans les coordonnes definies par px et py
*	\param *ecran adresse de l'ecran
*	\param eran,px,py,zoom,ima
*	\return void c'est une fonction de type void
*/
void drawTexture(SDL_Surface *ecran,int px, int py,double zoom, SDL_Surface *ima);
/**
*	\fn drawcolor(SDL_Surface *ecran,int px,int py,double size,char c)
*	\brief permet de tracer la couleur assoicié a un caractere  et la tracer sur l'ecran dans les coordonnes definies par px et py. Ceci permet le passage d'une grille de caracteres a une gille de carrés colorés
*	\param *ecran adresse de l'ecran
*	\param ecran,px,py,ima;
*	\return void c'est une fonction de type void
*/
void drawcolor(SDL_Surface *ecran,int px,int py,double size,char c);
/**
*	\fn fondmenu(SDL_Surface *ecran)
*	\brief permet de dessiner le fond du menu en tracant l'images d'un pluie de couleurs en haut ainsi le logo de ateam associé a notre equipe
*	\param *ecran adresse de l'ecran
*	\param SDL_Surface cran
*	\return void c'est une fonction de type void
*/
void fondmenu(SDL_Surface *ecran);
/**
*	\fn  afficherMenu(SDL_Surface *ecran,int size,int nbcoups)
*	\brief permet d'afficher le menu constitué du choix de la taille  ainsi le niveau et une option de QUIT.Cette fonction afficher le menu en fonction de la taille du grille qu'on selectionne grace au fleches du clavier
*	\param *ecran adresse de l'ecran
*	\param g grille
*	\param size taille que l'utilisateur veut choisir pour la grille
*	\return void c'est une fonction de type void
*/
void afficherMenu(SDL_Surface *ecran,int size);
/**
*	\fn dessinerfleche(SDL_Surface *ecran,int fleche)
*	\brief permet d'afficher la flèche pour surfer dans le menu et choisir les options de jeu en appuyant sur un entier fleche
*	\param *ecran adresse de l'ecran
*	\param fleche flèche pour de marquer l'emlacement de  fleche au cours de navigation menu
*	\return void c'est une fonction de type void
*/
void dessinerfleche(SDL_Surface *ecran,int fleche);
/**
*	\fn choisirniveau(SDL_Surface *ecran,int niveau)
*	\brief permet de choisir le niveau grace au fleche du curseur afin de choisir le niveau
*	\param *ecran adresse de l'ecran
*	\param niveau :on utilise la flèche pour de marquer l'emlacement de  fleche au cours de navigation sur les niveaux et en sa fonction on choisit le niveau (niveau==fleche%3)
*	\return void c'est une fonction de type void
*/
void choisirniveau(SDL_Surface *ecran,int niveau);
/**
*	\fn interface(SDL_Surface *ecran)
*	\brief permet de tracer l'interface des 6 couleurs qui serait fixe tout au long du jeu et permette au l'utilisateur de choisir la couleur parmi elles ainsi les differents icones de jeu comme: rejouer et revenir_au_menu et controler_son et icone_solution
*	\param *ecran adresse de l'ecran
*	\param g grille
*	\return void c'est une fonction de type void
*/
void interface(SDL_Surface *ecran);
/**
*	\fn void printgrille(SDL_Surface *ecran,grid g)
*	\brief permet de tracer la grille a partir d'une grille initialisée par les chaines de  caractere correspondants aux couleurs
*	\param *ecran adresse de l'ecran
*	\param g grille
*	\return void c'est une fonction de type void
*/
void printgrille(SDL_Surface *ecran,grid g);
/**
*	\fn nbr_coups(grid grille)
*	\brief permet de retourner le nombre de coups fourni par le solveur_rapide
*	\param *ecran adresse de l'ecran
*	\param g grille
*	\return void c'est une fonction de type void
*/
int nbr_coups(grid grille);
/**
*	\fn printsolution(SDL_Surface *ecran,grid grille)
*	\brief permet de tracer la solution dans l'ecran
*	\param *ecran adresse de l'ecran
*	\param g grille
*	\return void c'est une fonction de type void
*/
void printsolution(SDL_Surface *ecran,grid grille);
/**
*	\fn jouer(SDL_Surface *ecran,grid g,char c)
*	\brief permet de changer la couleur de la grille à chaque fois qu'on joue une couleur parmi les 7 à partir d'un caractère de la grille g
*	\param *ecran adresse de l'ecran
*	\param g grille
*	\param char c la couleur joue
*	\return void c'est une fonction de type void
*/
void jouer(SDL_Surface *ecran,grid g,char c);
/**
*	\fn finjeu(SDL_Surface *ecran,TTF_Font *police,int WL,int nbr_mvm)
*	\brief permet d'afficher les messages de fin de jeu(win or lose) et afficher la grille dans son etat final ainsi le nombre de mouvements faits pour gagner
*	\param *ecran adresse de l'ecran
*	\param police police pour ecrire les message
*	\param WL pour designer (win or lose )
*	\param nbr_mvm le nombre de mouvements pour gagner la partie
*	\return void c'est une fonction de type void
*/
int finjeu(SDL_Surface *ecran,TTF_Font *police,int WL,int nbr_mvm);
/**
*	\fn urfer_menu(SDL_Surface *ecran,int *niveau,int *size)
*	\brief c'est l'une des deux fonction principale du jeu qui permet globalement de surfer dans le menu et choisir le niveau et la taille tout cela en se basant sur les fonctions d'affichage du menu ainsi les fleches de choix de niveau et taille
*	\param *ecran adresse de l'ecran
*	\param *niveau:pointeur sur le niveau
*	\param *size:pointeur sur la taille
*	\return void c'est une fonction de type void
*/
int surfer_menu(SDL_Surface *ecran,int *niveau,int *size);
/**
*	\fn urfer_menu(SDL_Surface *ecran,int *niveau,int *size)
*	\brief c'est la deuxieme fonction principale du jeu qui permet globalement la boucle de jeu tout en se basant sur les fonctions conceranantes le jeu ainsi l'interface du jeu et finalament les messages de victoire ou d'echec
*	\param *ecran adresse de l'ecran
*	\param *niveau:le niveau
*	\param *size:la taille
*	\return void c'est une fonction de type void
*/
int loop_game(SDL_Surface *ecran,int size,int niveau);
#endif
