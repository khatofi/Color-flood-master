/**
*	\file grid_color.h
*	\brief prototypes des fonctions et structures nécessaires pour la réalisation du jeu
*	\author Loubna Anthea Abdellah Bader
*	\version 3.0
*	\date 27 Feb 2017
*/

#ifndef _GRID_COLOR_H
#define _GRID_COLOR_H
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>
/**
*	\struct grid grid_color.h
*	\brief char **array and int size tableau 2d et sa taille
*/
typedef struct grid grid;
struct grid
{
	char **array;
    int **belong;
	int size;

};


/**
*	\fn grid allocate_grid(int n)
*	\brief alloue la mémoire pour une grille de taille n*n
*	\param n la taille de la grille
*	\return grid une grille vide alloué en mémoire
*/
grid allocate_grid(int n);

/**
*	\fn grid init_grid(int n)
*	\brief initialise la grille de taille n*n à partir de valeurs aléatoires
*	\param  n la taille de la grille
*	\return grid une grille initialisée par des valeurs aléatoires
*/
grid init_grid(int n);

/**
*	\fn void free_grid(grid *grille)
*	\brief libère la memoire occupée par une grille
*	\param *grille adresse de la grille à libérer
*	\return ne retourne rien, c'est une fonction de type void
*/
void free_grid(grid *grille);

/**
*	\fn void fill_file(char name_file[], int n)
*	\brief pour remplir un fichier avec des charactères aléatoires
*	\param name_file nom du fichier
*	\param n nombre de charactères à générer
*	\return ne retourne rien fonction de type void
*/
void fill_file(char name_file[], int n);

/**
*	\fn int count_file(char name_file[])
*	\brief compte le nombre de caractères dans un fichier implémenté par fill_file
*	\param name_file[] le nom du fichier
*	\return le nombre de caractères contenus dans le fichier implémenté à l'aide de fill_file
*/
int count_file(char name_file[]);

/**
*	\fn void init_grid_file(char name_file[], grid *grille)
*	\brief pour remplir une grille à partir d'un fichier
*	\param name_file nom du fichier
*	\param *grille adresse de la grille
*	\return ne retourne rien fonction de type void
*/
void init_grid_file(char name_file[], grid *grille);

/**
*	\fn void fill_file_grid(char name_file_array[], char name_file_belong[], grid* grille)
*	\brief pour remplir un fichier avec les charactères contenus dans le tableau array de la grille et un autre fichier avec les entiers contenus dans le tableau belong de la grille
*	\param name_file_array nom du fichier à remplir avec les caractères
*	\param name_file_belong nom du fichier à remplir avec les entiers
*	\param n nombre de charactères à générer
*	\return ne retourne rien fonction de type void
*/
void fill_file_grid(char name_file_array[], char name_file_belong[], grid* grille);

/**
*	\fn void grid_print(grid *grille)
*	\brief pour afficher une grille
*	\param *grille adresse de la grille à afficher
*	\return une fonction de type void
*/
void grid_print(grid *grille);

/**
*	\fn int test_is_color(char couleur)
*	\brief teste si couleur est une des couleurs utilisées
*	\param couleur la couleur à tester
*	\return 1 si le couleur appartient à la liste des couleurs utilisées
*	\return 0 si le couleur n'appartient pas à la liste des couleurs utilisées
*/
int test_is_color(char couleur);

/**
*	\fn void set_grid(grid *grille,int x,int y,char couleur)
*	\brief pour modifier la grille
*	\param *grille adresse de la grille pour accéder et modifier simplement ses variables
*	\param x abscisse de la case à modifier
*	\param y ordonnée de la case à modifier
*	\param couleur la nouvelle couleur
*	\return une fonction de type void
*/
void set_grid(grid *grille,int x,int y,char couleur);

/**
*	\fn detect_flood(grid *g,int x,int y,char couleur)
*	\brief identifie la tâche en se basant sur l'algorithme de remplissage par diffusion
*	\param *grille adresse de la grille 
*	\param x abscisse de l'origine de la tâche
*	\param y ordonnée de l'origine de la tâche
*	\param couleur couleur de l'origine de la tâche
*	\return void c'est une fonction de type void
*/
void detect_flood(grid *g,int x,int y,char couleur);

/**
*	\fn change_color(grid *grille, char couleur)
*	\brief change la couleur des cases appartenant à la tâche par la couleur entrée en paramètre
*	\param *grille adresse de la grille 
*	\param couleur la nouvelle couleur à étaler
*	\return void c'est une fonction de type void
*/
void change_color(grid *g,char couleur);

/**
*	\fn refresh_grid(grid *g)
*	\brief remet à 0 le tableau d'appartenance à la tâche
*	\param *grille adresse de la grille 
*	\return void c'est une fonction de type void
*/
void refresh_grid(grid *g);

/**
*	\fn int test_same_colour(grid *grille)
*	\brief teste si toutes les cases de la grille ont la même couleur
*	\param *grille adresse de la grille à tester
*	\return retourne 1 si les cases ont toutes la même couleur et 0 sinon
*/
int test_same_colour(grid *grille);

#endif