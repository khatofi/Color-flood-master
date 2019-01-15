
#include "solveur_rapide.h"


grid copy(grid g)
{
	int n=g.size;
	grid g1=init_grid(g.size);

	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			g1.array[i][j]=g.array[i][j];
			g1.belong[i][j]=g.belong[i][j];
		}
	}

	return g1;
}

bool choixpertinent(grid g,char c)
{
	if(g.array[0][0]==c)
	{
		return false;
	}

	int n=g.size;
	detect_flood(&g,0,0,g.array[0][0]);
	grid g1=copy(g);
	change_color(&g1,c);
	refresh_grid(&g1);
	detect_flood(&g1,0,0,g1.array[0][0]);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(g1.belong[i][j]!=g.belong[i][j])
			{
				free_grid(&g1);
				return true;
			}
		}
	}

	free_grid(&g1);
	return false;
}

int compteur(grid g)
{
	int c = 0;

	for(int i = 0; i < g.size; i = i+1)
	{
		for(int j = 0; j < g.size; j = j+1)
		{
			if(g.belong[i][j] == 1)
			{

					c = c+1;
		    }
		}
	}

	return c;
}

char couleurs[6]={'G','V','R','J','M','B'};


char size_tache(grid g, char couleurs[6])
{
	int tache=compteur(g);
	int tache_bis=0;
	char couleur_res;
	
	if(g.size <= 1){
		printf("taille non valide\n");
		return(g.array[0][0]);
	}
	
	int i=0;
	for(i=0; i<6 ; i++)
	{
		grid g2=copy(g);
		if(choixpertinent(g2,couleurs[i]))
		{

			change_color(&g2, couleurs[i]);
			refresh_grid(&g2);
			detect_flood(&g2,0,0,g2.array[0][0]);
			tache_bis=compteur(g2);			
			if(tache <= tache_bis)
			{
				tache=tache_bis;
				couleur_res=couleurs[i];
				
			}

		}
		free_grid(&g2);
		

	 } 
	 return couleur_res;
}


void solution_rapide(grid grille_depart,char sol[1000],int *i)
{
	
	char c;   
   grid g2=copy(grille_depart);
   detect_flood(&g2,0,0,g2.array[0][0]);
	c=size_tache(g2,couleurs);
	sol[*i]=c;
   change_color(&g2,c);
   refresh_grid(&g2); 
   if(!test_same_colour(&g2))
	{
						
		*i=*i+1;
		solution_rapide(g2,sol,i);
						
	}  
	free_grid(&g2);
		   
}
	   

       
