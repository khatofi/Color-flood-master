#include "loop_game.h"
#include "grid_color.h"
#include "solveur_rapide.h"

/*	on demande à l'utilisateur de saisir une couleur , si celle ci n'est pas valide et 
	tant que l'utilisateur ne quitte pas avec 'Q' on lui redemande de sasir une couleur
	valide*/
char get_colour()
{
	char c;
	char tmp[3];
	
	printf("Entrer une couleur (B, V, R, G, Y ou M), Q pour quitter ou H pour afficher une solution possible:\n");
	printf("Option choisie: ");
	scanf("%s", tmp);
	c = tmp[0];

	while(!test_is_color(c) && c != 'Q' && c != 'H')
	{
		printf("Entrer une couleur, Q ou H:\n");
		scanf("%s", tmp);
		c = tmp[0];
	}

    return c;
}

/*	on demande à l'utilisateur de saisir une taille de la grille tant que la taille n'est pas valide
	c-à-d supérieure strictement à 1 on lui redemande de saisir une taille valide*/
int get_size()
{
    int s;

    printf("Entrer la taille de la grille (supérieure à 1):\n");
	scanf("%d",&s);
	
	while(s <= 1)
	{
		printf("Entrer la taille de la grille:\n");
		scanf("%d", &s);
	}

    return s;
}

/*	on calcule le nombre de coups nécessaire pour résoudre la grille à l'aide du 
	solveur_rapide*/
int get_nombre_coups(grid g)
{
	int nb;
	int iter = 0;
	char sol[100];
	
	solution_rapide(g, sol, &iter);

	nb = iter;
	return nb;
}

/* 
	on demande le niveau de jeux et on retourne le nombre de coups à rajouter en
	fonction de ce qui est entré
*/
int get_level(){
	int level = 0;
	int coups_extra;

	printf("\n");
	printf("Choisissez la difficulté:\n");
	printf("1: Facile\n");
	printf("2: Moyen\n");
	printf("3: Difficile\n");
	
	while(!(level == 1 || level == 2 || level == 3)){

		scanf("%d", &level);

		switch(level){
			case 1:
				coups_extra = 11;
				break;
			case 2:
				coups_extra = 4;
				break;
			case 3:
				coups_extra = 1;
				break;
			default:
				printf("Nombre non valide.\n");
				break;
		}
	}

	return coups_extra;
}

/*	effectue les changements nécessaires à la grille à chaque tour de jeu*/
void turn(int *coups_restants, int *nbr_mvm, grid *g, char c, int nombre_coups)
{
	
	change_color(g, c);
	refresh_grid(g);
	*nbr_mvm = *nbr_mvm+1;
	*coups_restants = *coups_restants-1;
	printf("\n");
	grid_print(g);
	//printf("Il vous reste %d coups\n", *coups_restants);
	printf("Coups joués: %d/%d\n", *nbr_mvm, nombre_coups);
	printf("\n");
	detect_flood(g, 0, 0, g->array[0][0]);
}

/*	si la grille est de couleur unie -> Victoire
	sinon si l'utilisateur quitte au milieu de la partie -> Au revoir
	sinon l'utilisateur perd*/
void check(grid *g, int test_quit, int nbr_mvm)
{
	if(test_same_colour(g))
	{
		printf("Victoire! Vous avez resolu la grille en %d mouvements \n",nbr_mvm);
	}
	else
	{
		if(test_quit)
		{
			printf("Partie non terminée, Au revoir!\n");
		}
		else
		{
			printf("Vous avez perdu :( \n");
		}
	}
}

/*
	l'utilisateur saisit une taille qui est testée par la fonction get_size
	il saisit ensuite le nombre de coups autorisés qui doit être valide grace à la fonction get_nombre_coups
	La grille est initialisée aléatoirement à l'aide de init_grid
	on rentre dans la boucle de jeu tant que la grille n'est pas d'une seule couleur et tant que coups_restants>0
	et que l'utilisateur ne quitte pas la partie
	à la fin on fait appel à la fonction check pour tester la victoire, défaite ou fin de partie
*/
void game()
{
	int size;
	int nombre_coups;
	int coups_restants;
	int coups_extra;
	int nbr_mvm = 0;
	int test_quit = 0;
	char c;
	grid g;

	size = get_size();
	g = init_grid(size);

	coups_extra = get_level();

	nombre_coups = get_nombre_coups(g) + coups_extra;

	coups_restants = nombre_coups;

	printf("\n");
	printf("Vous avez %d coups pour résoudre cette grille\n", nombre_coups);
	printf("\n");
	grid_print(&g);
	detect_flood(&g, 0, 0, g.array[0][0]);
		
	while(!test_same_colour(&g) && coups_restants > 0 && !test_quit)
	{
			
            c = get_colour();
			if(c != 'Q')
			{
				if(c != 'H'){
					turn(&coups_restants, &nbr_mvm, &g, c, nombre_coups);
				}
				else{
					int i = 0;
					char sol[1000] = {'0'};
					solution_rapide(g, sol, &i);
					printf("\n");
					printf("Une solution:\n");
					printf("%s\n", sol);
					printf("\n");
					memset (sol, 0, sizeof (sol));
				}
			}
			else
			{
				test_quit = 1;
			}
	}
		
	check(&g, test_quit, nbr_mvm);
	free_grid(&g);
	
}
