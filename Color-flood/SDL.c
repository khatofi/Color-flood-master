#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_rotozoom.h>
#include <SDL/SDL_mixer.h>
#include "grid_color.h"
#include "SDL.h"

/*
 compilation soous Linux : gcc -o exSDL exSDL.c -lSDL -lSDL_ttf -lSDL_gfx -lSDL_mixer
 compilation sur Mac : gcc -o exSDL -I/Library/Frameworks/SDL.framework/Headers  exSDL.c SDLmain.m -framework SDL -framework Cocoa
*/


void initialise(){
	const SDL_VideoInfo* info = NULL;
	/*Initialisation video */
	if( SDL_Init( SDL_INIT_VIDEO ) < 0 ) {
		/* Failed, exit. */
		fprintf( stderr, "Video initialization failed: %s\n", SDL_GetError( ) );
		SDL_Quit( );
	}
	/*initialisation TTF*/
	if(TTF_Init() == -1){
		fprintf(stderr, "Erreur d'initialisation de TTF_Init : %s\n", TTF_GetError());
		exit(EXIT_FAILURE);
  	}
	info = SDL_GetVideoInfo( );
	if( !info ) {
		fprintf( stderr, "Video query failed: %s\n", SDL_GetError( ) );
		SDL_Quit( );
  }
	//Initialisation de l'API Mixer
	if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) == -1){
   printf("%s", Mix_GetError());
	}
}

void drawRectangle(SDL_Surface *ecran, int px, int py, int size, int r, int g, int b) {
    SDL_Rect rect;

    rect.x=px;
    rect.y=py;
    rect.h=rect.w=size;

    SDL_FillRect(ecran, &rect, SDL_MapRGB(ecran->format, r, g, b));
    SDL_Flip(ecran);
}

void fillScreen(SDL_Surface *ecran, int r, int g, int b) {
    SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, r, g, b));
    SDL_Flip(ecran);
}

void drawTexture(SDL_Surface *ecran,int px, int py,double zoom, SDL_Surface *ima)
{
	SDL_Rect rect;
	rect.x = px;
	rect.y = py;
  ima=rotozoomSurface(ima,0,zoom,1);
	SDL_BlitSurface(ima, NULL, ecran, &rect);
  SDL_Flip(ecran);
  SDL_FreeSurface(ima);
}

void drawcolor(SDL_Surface *ecran,int px,int py,double size,char c){
  SDL_Surface *blue=NULL,*green=NULL,*red=NULL,*yellow=NULL,*purple=NULL,*grey=NULL;
  blue=SDL_LoadBMP("Minerals/blue01.bmp");
  red=SDL_LoadBMP("Minerals/red01.bmp");
  yellow=SDL_LoadBMP("Minerals/yellow03.bmp");
  purple=SDL_LoadBMP("Minerals/purple01.bmp");
  grey=SDL_LoadBMP("Minerals/grey01.bmp");
  green=SDL_LoadBMP("Minerals/green01.bmp");

	switch (c) {
    case 'V':
      drawTexture(ecran,px,py,size,green);break;
    case 'R':
      drawTexture(ecran,px,py,size,red);break;
    case 'B':
      drawTexture(ecran,px,py,size,blue);break;
    case 'J':
      drawTexture(ecran,px,py,size,yellow);break;
    case 'M':
      drawTexture(ecran,px,py,size,purple);break;
    case 'G':
      drawTexture(ecran,px,py,size,grey);break;
    default:
            break;
    }

    SDL_Flip(ecran);
    SDL_FreeSurface(green);
    SDL_FreeSurface(blue);
    SDL_FreeSurface(red);
    SDL_FreeSurface(yellow);
    SDL_FreeSurface(purple);
    SDL_FreeSurface(grey);

}

void fondmenu(SDL_Surface *ecran){
  SDL_Surface *pluie=NULL,*ateam=NULL;
  pluie=SDL_LoadBMP("Minerals/pluiecouleurs.bmp");
  ateam=SDL_LoadBMP("Minerals/Ateam.bmp");

	drawTexture(ecran,0,0,0.4,pluie);
  drawTexture(ecran,400,720,0.5,ateam);

	SDL_Flip(ecran);
	SDL_FreeSurface(pluie);
  SDL_FreeSurface(ateam);
}

void afficherMenu(SDL_Surface *ecran,int size){
	SDL_Rect position;
	char sizeg[100];
	SDL_Color couleurNoire;
  SDL_Surface *menu1=NULL,*menu2=NULL,*menu3=NULL;
	couleurNoire.r=0;
	couleurNoire.g=0;
	couleurNoire.b=0;
	TTF_Font *police = NULL;
	police = TTF_OpenFont("LOTD.ttf", 23);

	drawRectangle(ecran,480,430,150,255,255,255);
  sprintf(sizeg,"Entrer la taille de la grille :  <|  %d  |>",size);
  menu1=TTF_RenderText_Blended(police,sizeg,couleurNoire);
  position.x = 50;
	position.y = 500;
	SDL_BlitSurface(menu1, NULL, ecran,&position);
	menu2=TTF_RenderText_Blended(police, "QUIT",couleurNoire);
	position.x = 50;
	position.y = 700;
  SDL_BlitSurface(menu2, NULL, ecran,&position);
  menu3=TTF_RenderText_Blended(police,"FACILE          MOYEN          DIFFICILE",couleurNoire);
  position.x = 50;
	position.y = 600;
  SDL_BlitSurface(menu3, NULL, ecran,&position);

	SDL_Flip(ecran);
  SDL_FreeSurface(menu1);
  SDL_FreeSurface(menu2);
  SDL_FreeSurface(menu3);
}


void dessinerfleche(SDL_Surface *ecran,int fleche){
	switch(fleche%3){
    	case 0:
				drawRectangle(ecran,35,500,10,0,0,0);
				drawRectangle(ecran,35,600,10,255,255,255);
		    drawRectangle(ecran,35,700,10,255,255,255);
		    break;
    	case 1:
				drawRectangle(ecran,35,600,10,0,0,0);
				drawRectangle(ecran,35,500,10,255,255,255);
	      drawRectangle(ecran,35,700,10,255,255,255);
	      break;
      case 2:
				drawRectangle(ecran,35,700,10,0,0,0);
				drawRectangle(ecran,35,500,10,255,255,255);
	      drawRectangle(ecran,35,600,10,255,255,255);
	      break;
    }
    SDL_Flip(ecran);
}

void choisirniveau(SDL_Surface *ecran,int niveau){
  switch(niveau%3){
    	case 0:
				drawRectangle(ecran,35,600,10,0,0,0);
				drawRectangle(ecran,260,600,10,255,255,255);
	      drawRectangle(ecran,480,600,10,255,255,255);
      	break;
    	case 1:
				drawRectangle(ecran,35,600,10,255,255,255);
				drawRectangle(ecran,260,600,10,0,0,0);
	      drawRectangle(ecran,480,600,10,255,255,255);
      	break;
      case 2:
				drawRectangle(ecran,35,600,10,255,255,255);
				drawRectangle(ecran,260,600,10,255,255,255);
	      drawRectangle(ecran,480,600,10,0,0,0);
	      break;
    }
    SDL_Flip(ecran);

}
void interface(SDL_Surface *ecran){
  SDL_Surface *blue=NULL,*green=NULL,*red=NULL,*yellow=NULL,*purple=NULL,*grey=NULL,*hint=NULL,*reset=NULL,*back=NULL,*son=NULL;
  blue=SDL_LoadBMP("Minerals/blue02.bmp");
  red=SDL_LoadBMP("Minerals/red02.bmp");
  yellow=SDL_LoadBMP("Minerals/yellow02.bmp");
  purple=SDL_LoadBMP("Minerals/purple02.bmp");
  grey=SDL_LoadBMP("Minerals/grey02.bmp");
  green=SDL_LoadBMP("Minerals/green02.bmp");
  hint=SDL_LoadBMP("Minerals/hint.bmp");
  reset=SDL_LoadBMP("Minerals/reset.bmp");
  back=SDL_LoadBMP("Minerals/menu.bmp");
  son=SDL_LoadBMP("Minerals/son.bmp");

	drawTexture(ecran,80,680,0.13,green);
	drawTexture(ecran,160,680,0.13,red);
	drawTexture(ecran,240,680,0.13,blue);
	drawTexture(ecran,320,680,0.13,yellow);
	drawTexture(ecran,400,680,0.13,purple);
	drawTexture(ecran,480,680,0.13,grey);
  drawTexture(ecran,0,760,1.2,hint);
  drawTexture(ecran,300,10,0.7,reset);
  drawTexture(ecran,400,10,0.7,back);
  drawTexture(ecran,500,10,0.7,son);

  SDL_Flip(ecran);

  SDL_FreeSurface(green);
  SDL_FreeSurface(blue);
  SDL_FreeSurface(red);
  SDL_FreeSurface(yellow);
  SDL_FreeSurface(purple);
  SDL_FreeSurface(grey);
  SDL_FreeSurface(hint);
  SDL_FreeSurface(reset);
  SDL_FreeSurface(back);

}

void printgrille(SDL_Surface *ecran,grid g){
	int size=g.size;
	int sizerectan=560/size;
  SDL_Surface *blue=NULL,*green=NULL,*red=NULL,*yellow=NULL,*purple=NULL,*grey=NULL;
  blue=SDL_LoadBMP("Minerals/blue01.bmp");
  red=SDL_LoadBMP("Minerals/red01.bmp");
  yellow=SDL_LoadBMP("Minerals/yellow03.bmp");
  purple=SDL_LoadBMP("Minerals/purple01.bmp");
  grey=SDL_LoadBMP("Minerals/grey01.bmp");
  green=SDL_LoadBMP("Minerals/green01.bmp");

	for(int i=0;i<size;i++){
		for(int j=0;j<size;j++){
			switch (g.array[j][i]) {
				case 'V':
					drawTexture(ecran,i*sizerectan+50,j*sizerectan+120,0.9/g.size,green);break;
				case 'R':
					drawTexture(ecran,i*sizerectan+50,j*sizerectan+120,0.9/g.size,red);break;
				case 'B':
					drawTexture(ecran,i*sizerectan+50,j*sizerectan+120,0.9/g.size,blue);break;
				case 'J':
					drawTexture(ecran,i*sizerectan+50,j*sizerectan+120,0.9/g.size,yellow);break;
				case 'M':
					drawTexture(ecran,i*sizerectan+50,j*sizerectan+120,0.9/g.size,purple);break;
				case 'G':
					drawTexture(ecran,i*sizerectan+50,j*sizerectan+120,0.9/g.size,grey);break;
				default:
           			break;
			}
		}
	}
  SDL_FreeSurface(green);
  SDL_FreeSurface(blue);
  SDL_FreeSurface(red);
  SDL_FreeSurface(yellow);
  SDL_FreeSurface(purple);
  SDL_FreeSurface(grey);
}




int nbr_coups(grid grille){
  char solution[100];
  int i=0;
  solution_rapide(grille,solution,&i);
  return i;

}

void printsolution(SDL_Surface *ecran,grid grille){
  int hauteur=780,i=0;char solution[1000]={'0'};
  while(i<80){
    drawRectangle(ecran,140+40*(i%12),hauteur,40,255,255,255);
    i++;
    if(i%12==0){
      hauteur+=30;
    }
  }
  i=0;
  solution_rapide(grille,solution,&i);
  hauteur=780;i=0;
  while(solution[i]){
    drawcolor(ecran,140+40*(i%12),hauteur,0.06,solution[i]);
    i++;
    if(i%12==0){
      hauteur+=30;
    }
  }
  SDL_Flip(ecran);
}


void jouer(SDL_Surface *ecran,grid g,char c){
  detect_flood(&g,0,0,g.array[0][0]);
	change_color(&g,c);
	printgrille(ecran,g);
	refresh_grid(&g) ;
}



int finjeu(SDL_Surface *ecran,TTF_Font *police,int WL,int nbr_mvm){
	SDL_Rect position;
	SDL_Color couleurRouge,couleurBleu,couleurgris;
	couleurRouge.r=255;
	couleurRouge.g=0;
	couleurRouge.b=0;
  couleurgris.r=127;
  couleurgris.g=127;
  couleurgris.b=127;
	couleurBleu.r=0;
	couleurBleu.g=0;
	couleurBleu.b=255;

	if(WL==0){
		SDL_Surface *wintext=NULL;
		police = TTF_OpenFont("LOTD.ttf", 20);
    char win[100];

    	sprintf(win,"Vous avez resolu la grille en %d mouvements",nbr_mvm);
	    wintext=TTF_RenderText_Blended(police,win,couleurBleu);
    	position.x=30;
    	position.y=700;
    	SDL_BlitSurface(wintext, NULL, ecran,&position);
      police = TTF_OpenFont("LOTD.ttf", 15);
      wintext=TTF_RenderText_Blended(police,"appuyer sur une touche pour recommencer",couleurgris);
      position.x=100;
    	position.y=800;

			SDL_BlitSurface(wintext, NULL, ecran,&position);
      SDL_Flip(ecran);
      SDL_Event retry;
      SDL_WaitEvent(&retry);
        while( retry.type ==SDL_MOUSEMOTION){
          SDL_WaitEvent(&retry);
          if(retry.type ==SDL_MOUSEBUTTONUP) return 1;
  		}
    }
	else if(WL==1){
    police = TTF_OpenFont("LOTD.ttf", 50);
    SDL_Surface *losetext=NULL;
		losetext=TTF_RenderText_Blended(police,"Vous avez perdu",couleurRouge);
		position.x=30;
		position.y=700;
		SDL_BlitSurface(losetext, NULL, ecran,&position);
    police = TTF_OpenFont("LOTD.ttf", 15);
    losetext=TTF_RenderText_Blended(police,"appuyer sur une touche pour recommencer",couleurgris);
    position.x=100;
    position.y=900;

		SDL_BlitSurface(losetext, NULL, ecran,&position);
    SDL_Flip(ecran);
		SDL_Event retry;
    SDL_WaitEvent(&retry);
      while( retry.type ==SDL_MOUSEMOTION){
        SDL_WaitEvent(&retry);
        if(retry.type ==SDL_MOUSEBUTTONUP) return 1;
		}
  }
  return 0;
}





int surfer_menu(SDL_Surface *ecran,int *niveau,int *size){
  SDL_Event touche;
  int compteur=1,fleche=300;

  Mix_Music *musique; //Création d'un pointeur de type Mix_Music
  musique = Mix_LoadMUS("Son/menu.mp3"); //Chargement de la musique
  Mix_PlayMusic(musique, -1); //Jouer infiniment la musique

  fillScreen(ecran, 255,255,255);
  afficherMenu(ecran,*size);
  fondmenu(ecran);
  drawRectangle(ecran,10,300,10,255,255,255);
  SDL_Flip(ecran);

  while(compteur){
 		touche.button.button=0;
 		SDL_WaitEvent(&touche);{
		switch(touche.type){
     case SDL_QUIT: return 0;
     case SDL_KEYDOWN: ///Si une touche à été appuyée
        switch(touche.key.keysym.sym){
           case SDLK_DOWN: {
              fleche++;
              dessinerfleche(ecran,fleche);
              break;
           }
           case SDLK_UP: {
             fleche--;
             dessinerfleche(ecran,fleche);
             break;
           }
           case SDLK_RIGHT: {
             switch(fleche%3){
               case 0 : {
                 *size=*size+1;
                 afficherMenu(ecran,*size);
                 break;
               }
               case 1 :{
                 *niveau=*niveau+1;
                 choisirniveau(ecran,*niveau);
               }
             }
             break;
           }
           case SDLK_LEFT: {
             switch(fleche%3){
               case 0 : {
                 if(*size>2){
                   *size=*size-1;
                 }
                 afficherMenu(ecran,*size);
                 break;
               }
               case 1 :{
                 *niveau=*niveau-1;
                 choisirniveau(ecran,*niveau);
               }
             }
             break;
           }
           case SDLK_SPACE:case SDLK_RETURN: ///Si la touche appuyée est espace ou entree
           if(fleche%3==2){
              return 1;
           }
           else compteur=0;
           break;
           case SDLK_ESCAPE: return 1;

            /* Appui sur la touche Echap, on arrête le programme */return 0;
           default : ;
         }
     	default : ;
   		}
 		}
	}
	fillScreen(ecran,255,255, 255);
	Mix_FreeMusic(musique);//Libération de la musique
	SDL_FreeSurface(ecran);
	return 0;
}



int loop_game(SDL_Surface *ecran,int size,int niveau){

  Mix_Music *musique; //Création d'un pointeur de type Mix_Music
  musique = Mix_LoadMUS("Son/jeu.mp3"); //Chargement de la musique
  Mix_PlayMusic(musique, -1); //Jouer infiniment la musique

  grid g,copieg;
  TTF_Font *police = NULL;
  SDL_Rect position;
  SDL_Event event;
  char mouvement[100];
  int nbcoups=1,nbr_mvm=0;
  SDL_Surface *texte=NULL;

  police = TTF_OpenFont("LOTD.ttf", 35);
  g=init_grid(size);printgrille(ecran,g);interface(ecran);copieg=copy(g);
  nbcoups=nbr_coups(g)+1+(niveau%3==1 ? g.size/2:(niveau%3==0 ? (g.size/2)+1:0));
  int cinit=nbcoups;
  sprintf(mouvement,"%d/%d",nbcoups,cinit);
  SDL_Color couleurNoire;couleurNoire.r=0; couleurNoire.g=0;couleurNoire.b=0;
  texte = TTF_RenderText_Blended(police, mouvement,couleurNoire);
  position.x = 100;
  position.y = 25;
  SDL_BlitSurface(texte, NULL, ecran,&position);
  SDL_Flip(ecran);
  SDL_Flip(ecran);
  int son=0;


  int continuer=1;
  while (continuer && !test_same_colour(&g) && nbcoups!=0 ){
    event.button.button=0;
    SDL_WaitEvent(&event);
    switch(event.type){
      case SDL_QUIT:
            continuer = 0;
            break;
      case SDL_KEYDOWN:
      switch (event.key.keysym.sym){
        case SDLK_ESCAPE: /* Appui sur la touche Echap, on arrête le programme */
          continuer = 0;
          break;
        default:break;
      }
      case SDL_MOUSEBUTTONUP:
          if (event.button.button == SDL_BUTTON_LEFT){
            if(event.button.y>680 && event.button.y<760 && event.button.x>80 && event.button.x<550){
              nbr_mvm++;
              drawRectangle(ecran,100,0,120,255,255,255);
              nbcoups--;
              sprintf(mouvement,"%d/%d",nbcoups,cinit);
              texte = TTF_RenderText_Blended(police, mouvement,couleurNoire);
              SDL_BlitSurface(texte, NULL, ecran,&position);
              SDL_Flip(ecran);
              if(event.button.x<150 && event.button.x>80){jouer(ecran,g,'V'); break;}
              if(event.button.x<230 && event.button.x>160){	jouer(ecran,g,'R'); break;	}
              if(event.button.x<310 && event.button.x>240){	jouer(ecran,g,'B'); break;}
              if(event.button.x<390 && event.button.x>320){	jouer(ecran,g,'J'); break;}
              if(event.button.x<470 && event.button.x>400){jouer(ecran,g,'M'); break;}
              if(event.button.x<550 && event.button.x>480){jouer(ecran,g,'G'); break;}
              else break;
            }
            if(event.button.x<400 && event.button.x>300 && event.button.y<80){
              g=copieg;
              copieg=copy(g);
              printgrille(ecran,g);
              nbr_mvm=0;
              drawRectangle(ecran,100,0,120,255,255,255);
              nbcoups=cinit;
              sprintf(mouvement,"%d/%d",nbcoups,cinit);
              texte = TTF_RenderText_Blended(police, mouvement,couleurNoire);
              SDL_BlitSurface(texte, NULL, ecran,&position);
              SDL_Flip(ecran);
            }
            if(event.button.x<150 && event.button.x>20 && event.button.y>800 ){
              printsolution(ecran,g);
            }
            if(event.button.x>400 && event.button.x<500 && event.button.y<80){
              continuer=0;
            }
            if(event.button.x>500 && event.button.x<600 && event.button.y<80){
              son++;
              if(son%2==1)
                {Mix_FreeMusic(musique);break;}
              else
                musique = Mix_LoadMUS("Son/jeu.mp3");Mix_PlayMusic(musique,-1);break;
          }
        }
      }
  }
  if(test_same_colour(&g)) {
		fillScreen(ecran,255,255,255);printgrille(ecran,g);
		if(finjeu(ecran,police,0,nbr_mvm)){
		  free_grid(&g);
		  free_grid(&copieg);
		  return 1;
		};
	}
  if(nbcoups==0 && !test_same_colour(&g)){
		fillScreen(ecran, 255,255,255);
		printgrille(ecran,g);
		if(finjeu(ecran,police,1,nbr_mvm)){
	    free_grid(&g);
	    free_grid(&copieg);
	    return 1;
		};
	}
  free_grid(&g);
  free_grid(&copieg);
  Mix_FreeMusic(musique); //Libération de la musique
  Mix_CloseAudio(); //Fermeture de l'API
  SDL_FreeSurface(ecran);
  TTF_Quit();

  return 0;
}
