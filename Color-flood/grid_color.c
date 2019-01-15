/**
*	\file grid_color.c
*	\brief bibliothèque permettant de manipuler les structures et les fonctions nécessaires pour la réalisation du jeu
*	\author Loubna Anthea Abdellah Bader
*	\version 3.0
*	\date 25 Feb 2017
*/
#include "grid_color.h"

/*	fonction pour allouer la mémoire pour une grille de taille n de structure grid  
	si n>0 on alloue deux tableaux 2D le premier de caractères pour les couleurs
	et le deuxième d'entiers pour l'appartenance à la tâche
    sinon on renvoie un message d'erreur*/
grid allocate_grid(int n)
{

   grid grille;
   int i;
   
   if(n > 0)
   {
		
	   grille.size = n;
	
		grille.array=malloc(n*sizeof(char*));
		grille.belong=malloc(n*sizeof(int*));
		for(i = 0; i < n; i++)
		{
			grille.array[i] = malloc(n*sizeof(char));
			grille.belong[i] = malloc(n*sizeof(int));
		}
		
	}
	else
	{
		printf("allocation impossible\n");
		grille.size = 0;	
	}
	
	return grille;
}
/*	fonction pour initialiser une grille de structure grid par un tableau de caractères représentant 
	les couleurs,
	si n>0 on remplit les case de grille.array (le tableau de caractères) par les lettres de 
	ce tableau aléatoirement (rand%6)
	sinon on renvoie une grille avec une seule case avec le caractère 0 pour les tests*/

grid init_grid(int n)
{
		grid grille;
		if(n > 0)
		{
			srand(time(NULL));
			grille=allocate_grid(n);

			int i,j;
  	    	char couleurs[6]={'B','V','R','J','M','G'};

			for(i=0; i<n ; i++)
			{
				for(j=0; j<n ; j++)
				{
					grille.array[i][j]=couleurs[rand()%6];
					grille.belong[i][j]=0;
				}
			}
		}
		if(n <= 0)
		{ 
    	 	printf(" Taille non valide n <= 0\n");
    	 	grille = allocate_grid(1);
    	 	grille.array[0][0] = '0';
			grille.belong[0][0] = 0;
		}

		return grille;
}
/*	fonction de libération de la mémoire occupée par une grille de type grid
	on libère la mémoire occupée par les deux tableaux 2D de la grille*/
void free_grid(grid *grille)
{
	int i;

	for(i = 0; i < grille->size ; i++)
	{
		free(grille->array[i]);
		grille->array[i] = NULL;
		free(grille->belong[i]);
		grille->belong[i] = NULL;
	}

	free(grille->array);
	free(grille->belong);
	grille->array = NULL;
	grille->belong = NULL;
}
/*	fonction pour remplir un fichier name_file par n*n caractères pris du tableau couleurs[6]
	si n>0 on ouvre le fichier en mode écriture(création s'il n'existe pas) puis on le remplit 
	aléatoirement par les caractères de couleurs[6], on ferme le fichier pour éviter les fuites 
	mémoire
	sinon on renvoie un message d'erreur*/
void fill_file(char name_file[], int n)
{

	int i;
	char c;
	char couleurs[6]={'B','V','R','J','M','G'};

	if(n > 0){
		FILE * f =fopen(name_file, "w");
		if(f){

			srand(time(NULL));

			for(i = 0; i < n*n; i = i+1)
			{
				c = couleurs[rand()%6];
				fprintf(f, "%c", c);
			}
   		fclose(f);
		}
	}
	else{
		printf("taille non valide\n");
	}
}
/*	fonction pour compter le nombre de caractères (compteur) dans un fichier name_file 
	compteur est initialisé à 0 et tant qu'on lit des caractères (a) on l'incrémente
	on ferme le fichier 
	on retourne le compteur*/

int count_file(char name_file[])
{

	char a;
	int compteur = 0;
	
	FILE * f = fopen(name_file, "r");

	while(fread(&a, sizeof(char), 1, f))
	{
		compteur = compteur+1;
	}

	fclose(f);

	return compteur;
}
/* fonction pour initialiser une grille(son adresse passé en paramètre) à partir d'un fichier name_file
	on compte le nombre de caractères dans le fichier avec count_file
	on ouvre le fichier en mode lecture
	si le fichier existe et si le nombre de caractères de ce fichier est supérieur ou égale à la taille
	de la grille on remplit la grille.array par les caractères du fichier
	sinon on renvoie un message d'erreur et on remplit grille.array par des 0
	grille.array est remplie par des 0 comme précédemment

	sinon si le fichier n'existe pas on renvoie un message d'erreur*/
void init_grid_file(char name_file[], grid *grille)
{

	int i, j, n;
	int compteur = count_file(name_file);
	
	FILE * f = fopen(name_file, "r");

	if(f)
	{
		n = grille->size;
		if(compteur >= grille->size*grille->size)
		{
		
			for(i = 0; i < n; i = i+1)
			{
				for(j = 0; j < n; j = j+1)
				{
					fread(&grille->array[i][j], sizeof(char), 1, f);
				}
			}
		}
		else
		{
			printf("fichier trop petit\n");
			for(i = 0; i < n; i = i+1)
			{
				for(j = 0; j < n; j = j+1)
				{
					grille->array[i][j] = '0';
				}
			}
		}

		for(i = 0; i < n; i = i+1)
		{
			for(j = 0; j < n; j = j+1)
			{		
				grille->belong[i][j]=0;
	   		}
   		}	
		fclose(f);
	}
	else
	{
		printf("le fichier ne peut pas être ouvert\n");
	}
}
/* fonction pour mettre le contenu d'une grille (de ses deux tableaux) dans deux fichiers 
	distincts name_file_array[] et name_file_belong[]
	on ouvre les deux fichiers en écriture et si la taille de la grille est valide on les 
	imprime dans les fichiers
	sinon on renvoie un message d'erreur
	on ferme les deux fichiers à la fin pour ne pas avoir de fuites*/
void fill_file_grid(char name_file_array[], char name_file_belong[], grid* grille){

	int i, j, n;
	
	FILE * fa = fopen(name_file_array, "w");
	FILE * fb = fopen(name_file_belong, "w");

	if(fa && fb)
	{
		n = grille->size;
		if(n > 0)
		{
		
			for(i = 0; i < n; i = i+1)
   			{
				for(j = 0; j < n; j = j+1)
   		   		{
					fprintf(fa, "%c", grille->array[i][j]);
					fprintf(fb, "%d", grille->belong[i][j]);
				}
			}
		}
		else
		{
			printf("grille non valide\n");
		}

		fclose(fa);
		fclose(fb);
	}
	else
	{
		printf("le fichier ne peut pas être ouvert\n");
	}
}
/*	fonction d'affichage de la grille */
void grid_print(grid *grille)
{
	int i,j;

	for(i=0 ; i < grille->size; i++)
	{
		for(j=0 ;j < grille->size; j++)
		{
			printf("%c ", grille->array[i][j]);
		}
		printf("\n");
	}
  printf("\n");
}
/* fonction pour tester qu'une couleur passée en paramètres est bien une des couleurs de couleurs[6]
	le resultat est 1 si la couleur appartient à couleurs[6]
	et 0 sinon*/
int test_is_color(char couleur)
{

	int i;
	int test = 0;
	char couleurs[6]={'B','V','R','J','M','G'};
	
	for(i = 0; i < 6; i = i+1)
	{
		if(couleur == couleurs[i])
		{
			return 1;
		}
	}

	return test;
}
/* fonction qui change la couleur d'une case de la grille (grille.array) si les coordonnées
	passées en paramètres sont valides et si la couleur désirée appartient à couleurs[6]*/
void set_grid(grid *grille,int x,int y,char couleur) 
{
	if(test_is_color(couleur) && x >= 0 && x < grille->size && y >= 0 && y < grille->size)
	{
		grille->array[x][y] = couleur;
	}
}
/* identification de la composante 4-connexe avec recursivité inspirée de l'algorithme de remplissage 
	par diffusion*/
void detect_flood(grid *g,int x,int y,char couleur)
{
	if(g->array[x][y]==couleur && g->belong[x][y]==0)
	{
		g->belong[x][y]=1;
		if(x-1>=0) 
		{
			detect_flood(g,x-1,y,couleur);
		}
		if(y-1>=0)
		{
			detect_flood(g,x,y-1,couleur);
		}
		if(x+1<g->size)
		{
			detect_flood(g,x+1,y,couleur);
		}
		if(y+1<g->size)
		{
			detect_flood(g,x,y+1,couleur);
		}
	}
}
/* changement de couleur de la composante 4-connexe d'une grille g par la couleur passée en paramètres
	si la couleur est valide et si la taille de la grille est valide et que la case courante (i,j)
	appartient à la composante 4-connexe g->belong[i][j] == 1 on change sa couleur*/
void change_color(grid *g,char couleur)
{ 
	int n = g->size;
  
	if(test_is_color(couleur))
	{	
		if(n > 0)
		{
			for (int i = 0; i < n; i++)
			{
				for(int j = 0; j < n; j++)
				{
					if(g->belong[i][j] == 1)
					{ 
						set_grid(g, i, j, couleur);
					}
				}
			}
		}
	}
}
/* remise des appartenances à la composante 4-connexe à 0*/
void refresh_grid(grid *g)
{
	int n=g->size;

	for(int i = 0; i < n; i = i+1)
	{
		for(int j = 0; j < n; j = j+1)
		{
			g->belong[i][j]=0;
		}
	}   
}
/* fonction pour tester si toutes les cases d'une grille(adresse passée en paramètres) sont de la 
	même couleur, on déclare une variable test  initialisée à 0 et qui prend 1 si une des cases est 
	de culeur différente*/
int test_same_colour(grid *grille)
{
	int i, j;
	int test;
	test = 1;

	for(i = 0; i < grille->size; i = i+1)
	{
		for(j = 0; j < grille->size; j = j+1)
		{
			if(grille->array[i][j] != grille->array[0][0])
			{
				test = 0;
			}
		}
	}
	return test;
}