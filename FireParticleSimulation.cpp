#include <iostream>
#include <SDL.h>

using namespace std;

int main(int argc, char *argv[]){

	const int SCREEN_WIDTH = 800;
	const int SCREEN_HEIGHT = 600;

	if(SDL_Init(SDL_INIT_VIDEO) < 0){
		cout << "SDL Init Failed" << endl;
		return -1;
	}
	cout << "SDL Init Succeeded" << endl;

	SDL_Window *window = SDL_CreateWindow("TestWindow", SDL_WINDOWPOS_UNDEFINED, 
			SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	if(window == NULL){
		cout << "Couldnt create window " << SDL_GetError()<<endl;
		SDL_Quit();
		return -1;
	}
	
	SDL_Renderer *renderer = SDL_CreateRenderer(window, 1, SDL_RENDERER_PRESENTVSYNC);
	if( renderer == NULL){
		cout << "Couidn't create renderer"<< endl;
		SDL_DestroyWindow(window);
		SDL_Quit();
		return -1;
	}

	SDL_Texture *texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888,
			SDL_TEXTUREACCESS_STATIC, SCREEN_WIDTH, SCREEN_HEIGHT);
	if( texture == NULL){
		cout << "Couidn't create texture"<< endl;
		SDL_DestroyRenderer(renderer);
		SDL_DestroyWindow(window);
		SDL_Quit();
		return -1;
	}

	Uint32 *buffer = new Uint32[SCREEN_WIDTH*SCREEN_HEIGHT];
	memset(buffer, 0, SCREEN_WIDTH*SCREEN_HEIGHT*sizeof(Uint32));

	SDL_UpdateTexture(texture, NULL, buffer, SCREEN_WIDTH*sizeof(Uint32));
	SDL_RenderClear(renderer);
	SDL_RenderCopy(renderer, texture, NULL, NULL);
	SDL_RenderPresent(renderer);

	//Game_Loop----------------------------------------------------------------------------
	bool quit = false;
	SDL_Event event;

	while(!quit){
		//TheGameRelateProg

		if(SDL_PollEvent(&event)){
			if(event.type == SDL_QUIT)
				quit = true;
		}
	}

	//-------------------------------------------------------------------------------------

	delete [] buffer;
	SDL_DestroyRenderer(renderer);
	SDL_DestroyTexture(texture);
	SDL_DestroyWindow(window);
	SDL_Quit();

	return 0;
}
