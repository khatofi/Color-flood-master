/**
*	\file solveur_rapide.h
*	\brief prototypes des fonctions et structures nécessaires pour l'application Color Flood
*	\author Loubna Anthea Abdellah Bader
*	\version 3.0
*	\date 10 Mai 2017
*/

#ifndef _SOLVEUR_RAPIDE_H
#define _SOLVEUR_RAPIDE_H

#include <stdbool.h>
#include <stdlib.h>
#include "grid_color.h"

/**
*	\fn grid copy(grid g)
*	\brief copie la grille passée en paramètre g dans une autre grille g1
*	\param  g la grille qu'on cherche à copier
*	\return grid une copie g1 de la grille de départ g
*/
grid copy(grid g);
/**
*	\fn bool choixpertinent(grid g,char c)
*	\brief permet de savoir si une couleur est adjacente à la composante connexe d'une grille g
*	\param  g la grille 
*	\param  c la couleur à tester 
*	\return bool true si la couleur est adjacente à la composante connexe et false sinon
*/
bool choixpertinent(grid g,char c);
/**
*	\fn int compteur(grid g)
*	\brief permet de calculer la taille de la composante connexe d'une grille g
*	\param  g la grille 
*	\return int taille de la composante connexe
*/
int compteur(grid g);
/**
*	\fn size_tache(grid g, char couleurs[6])
*	\brief permet de choisir une couleur qui est un choix pertinent et qui permet une plus grande composante connexe
*	\param  g la grille
*	\param couleurs[6] tableau des caractères couleur qu'on parcourt pour renvoyer la meilleur couleur adjacente
*	\return char la couleur adjacente qui permet une plus grande composante connexe
*/
char size_tache(grid g, char couleurs[6]);
/**
*	\fn void solution_rapide(grid grille_depart, char sol[100], int *i)
*	\brief résout la grille passée en paramètre
*	\param  grille_depart la grille
*	\param  sol[100] tableau où on stocke la solution
*	\param  *i le pointeur pour calculer le nombre de coups
*	\return void c'est une fonction de type void
*/
void solution_rapide(grid grille_depart, char sol[100], int *i);
#endif
