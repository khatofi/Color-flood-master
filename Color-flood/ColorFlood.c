#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include "grid_color.h"
#include "SDL.h"



int main(){

	while(1){
		initialise();

		int size=2,niveau=300;
		SDL_Surface *ecran = NULL;
		ecran=SDL_SetVideoMode(640,960,32,SDL_HWSURFACE);

		SDL_WM_SetCaption("ColorFlood",NULL);

		if(surfer_menu(ecran,&niveau,&size)){
			return 0;
		}
		loop_game(ecran,size,niveau);
		SDL_FreeSurface(ecran);
	}

	TTF_Quit();
	Mix_CloseAudio();
	SDL_Quit();

	return 0;
}
