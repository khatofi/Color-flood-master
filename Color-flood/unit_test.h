#ifndef _UNIT_TEST_H
#define _UNIT_TEST_H

/**
*	\file unit_test.h
*	\brief prototypes des fonctions et structures nécessaires pour les tests unitaires des fonctions du solveur_rapide
*	\author Loubna Anthea Abdellah Bader
*	\version 3.0
*	\date 13 Mai 2017
*/

#include <stdbool.h>
#include "CUnit/CUnit.h"
#include "CUnit/Basic.h"
#include "grid_color.h"
#include "solveur_rapide.h"

/**
*	 \fn test_egalite(grid g1, grid g2);
*	 \brief teste si les grilles passées en paramètre sont égales
*	 \param g1 une grille
*	 \param g2 une grille 
*	 \return true si les tableaux array et les tableaux belong des grilles contiennent les mêmes informations
*    \return false sinon
*/
bool test_egalite(grid g1, grid g2);

/**
*	 \fn test_copy(void)
*	 \brief test unitaire de la fonction copy
*	 \param  void aucun
*	 \return void fonction de type void
*/
void test_copy(void);

/**
*	 \fn test_compteur(void)
*	 \brief test unitaire de la fonction compteur
*	 \param  void aucun
*	 \return void fonction de type void
*/
void test_compteur(void);

/**
*	 \fn test_choixpertinent(void)
*	 \brief test unitaire de la fonction choixpertinent
*	 \param  void aucun
*	 \return void fonction de type void
*/
void test_choixpertinent(void);

/**
*	 \fn test_size_tache(void)
*	 \brief test unitaire de la fonction size_tache
*	 \param  void aucun
*	 \return void fonction de type void
*/
void test_size_tache(void);

/**
*	 \fn void test_solution_rapide(void)
*	 \brief test unitaire de la fonction solution_rapide
*	 \param  void aucun
*	 \return void fonction de type void
*/
void test_solution_rapide(void);

#endif