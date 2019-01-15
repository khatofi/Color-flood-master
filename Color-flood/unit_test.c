#include "CUnit/CUnit.h"
#include "CUnit/Basic.h"
#include "unit_test.h"

bool test_egalite(grid g1, grid g2){

	if(g1.size != g2.size){
		printf("taille\n");
		return false;
	}
	else{
		for(int i = 0; i < g1.size; i = i+1){
			for(int j = 0; j < g1.size; j = j+1){
				if((g1.array[i][j] != g2.array[i][j]) || (g1.belong[i][j] != g2.belong[i][j])){
					return false;
				}
			}
		}
	}

	return true;
}

void test_copy(void){
	grid g1 = init_grid(0);
	grid g2 = copy(g1);

	grid g3 = init_grid(1);
	grid g4 = copy(g3);

	grid g5 = init_grid(12);
	grid g6 = copy(g5);

	CU_ASSERT(test_egalite(g1, g2) == true);
	CU_ASSERT(test_egalite(g3, g4) == true);
	CU_ASSERT(test_egalite(g5, g6) == true);

	free_grid(&g1);
	free_grid(&g2);
	free_grid(&g3);
	free_grid(&g4);
	free_grid(&g5);
	free_grid(&g6);
}

void test_compteur(void){
	
	grid g1 = allocate_grid(1);
	grid g2 = allocate_grid(2);
	grid g3 = allocate_grid(5);
	grid g4 = allocate_grid(10);

	init_grid_file("grille1", &g1);
	init_grid_file("grille2", &g2);
	init_grid_file("grille3", &g3);
	init_grid_file("grille4", &g4);

	detect_flood(&g1, 0, 0, g1.array[0][0]);
	detect_flood(&g2, 0, 0, g2.array[0][0]);
	detect_flood(&g3, 0, 0, g3.array[0][0]);
	detect_flood(&g4, 0, 0, g4.array[0][0]);

	CU_ASSERT(compteur(g1) == 1);
	CU_ASSERT(compteur(g2) == 2);
	CU_ASSERT(compteur(g3) == 13);
	CU_ASSERT(compteur(g4) == 26);

	free_grid(&g1);
	free_grid(&g2);
	free_grid(&g3);
	free_grid(&g4);
}

void test_choixpertinent(void){

	char couleurs[6] = {'B', 'V', 'G', 'R', 'M', 'Y'}; 

	grid g1 = init_grid(4);
	grid g2 = init_grid(12);
	grid g3 = init_grid(20);

	detect_flood(&g1, 0, 0, g1.array[0][0]);
	detect_flood(&g2, 0, 0, g2.array[0][0]);
	detect_flood(&g3, 0, 0, g3.array[0][0]);

	int compteur_g1 = compteur(g1);
	int compteur_g2 = compteur(g2);
	int compteur_g3 = compteur(g3);

	for(int i = 0; i < 6; i = i+1){
		if(choixpertinent(g1, couleurs[i])){
			grid g1_bis = copy(g1);
			
			CU_ASSERT(couleurs[i] != g1.array[0][0]);

			change_color(&g1_bis, couleurs[i]);
			refresh_grid(&g1_bis);
			detect_flood(&g1_bis, 0, 0, g1_bis.array[0][0]);

			CU_ASSERT(compteur(g1_bis) >= compteur_g1);

			free_grid(&g1_bis);
		}

		if(choixpertinent(g2, couleurs[i])){
			grid g2_bis = copy(g2);
			
			CU_ASSERT(couleurs[i] != g2.array[0][0]);

			change_color(&g2_bis, couleurs[i]);
			refresh_grid(&g2_bis);
			detect_flood(&g2_bis, 0, 0, g2_bis.array[0][0]);

			CU_ASSERT(compteur(g2_bis) >= compteur_g2);

			free_grid(&g2_bis);
		}

		if(choixpertinent(g3, couleurs[i])){
			grid g3_bis = copy(g3);
			
			CU_ASSERT(couleurs[i] != g3.array[0][0]);

			change_color(&g3_bis, couleurs[i]);
			refresh_grid(&g3_bis);
			detect_flood(&g3_bis, 0, 0, g3_bis.array[0][0]);

			CU_ASSERT(compteur(g3_bis) >= compteur_g3);

			free_grid(&g3_bis);
		}
	}

	free_grid(&g1);
	free_grid(&g2);
	free_grid(&g3);
}

void test_size_tache(void){

	char couleurs[6] = {'B', 'V', 'G', 'R', 'M', 'Y'}; 

	grid g1 = allocate_grid(1);
	grid g2 = allocate_grid(2);
	grid g3 = allocate_grid(5);
	grid g4 = allocate_grid(10);

	init_grid_file("grille1", &g1);
	init_grid_file("grille2", &g2);
	init_grid_file("grille3", &g3);
	init_grid_file("grille4", &g4);

	detect_flood(&g1, 0, 0, g1.array[0][0]);
	detect_flood(&g2, 0, 0, g2.array[0][0]);
	detect_flood(&g3, 0, 0, g3.array[0][0]);
	detect_flood(&g4, 0, 0, g4.array[0][0]);

	CU_ASSERT(size_tache(g1, couleurs) == 'B');
	CU_ASSERT(size_tache(g2, couleurs) == 'G');
	CU_ASSERT(size_tache(g3, couleurs) == 'G');
	CU_ASSERT(size_tache(g4, couleurs) == 'R');

	free_grid(&g1);
	free_grid(&g2);
	free_grid(&g3);
	free_grid(&g4);
}

void test_solution_rapide(void){

	grid g1 = init_grid(1);
	grid g2 = init_grid(6);
	grid g3 = init_grid(12);
	grid g4 = init_grid(20);

	char sol1[1000] = {'0'};
	char sol2[1000] = {'0'};
	char sol3[1000] = {'0'};
	char sol4[1000] = {'0'};

	int iter1 = 0;
	int iter2 = 0;
	int iter3 = 0;
	int iter4 = 0;

	solution_rapide(g1, sol1, &iter1);
	solution_rapide(g2, sol2, &iter2);
	solution_rapide(g3, sol3, &iter3);
	solution_rapide(g4, sol4, &iter4);
	
	for(int i = 0; i <= iter1; i = i+1){
		detect_flood(&g1, 0, 0, g1.array[0][0]);
		change_color(&g1, sol1[i]);
		refresh_grid(&g1);
	}

	for(int i = 0; i <= iter2; i = i+1){
		detect_flood(&g2, 0, 0, g2.array[0][0]);
		change_color(&g2, sol2[i]);
		refresh_grid(&g2);
	}

	for(int i = 0; i <= iter3; i = i+1){
		detect_flood(&g3, 0, 0, g3.array[0][0]);
		change_color(&g3, sol3[i]);
		refresh_grid(&g3);
	}

	for(int i = 0; i <= iter4; i = i+1){
		detect_flood(&g4, 0, 0, g4.array[0][0]);
		change_color(&g4, sol4[i]);
		refresh_grid(&g4);
	}

	CU_ASSERT(test_same_colour(&g1));
	CU_ASSERT(test_same_colour(&g2));
	CU_ASSERT(test_same_colour(&g3));
	CU_ASSERT(test_same_colour(&g4));

	free_grid(&g1);
	free_grid(&g2);
	free_grid(&g3);
	free_grid(&g4);
}