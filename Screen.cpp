/*
 * Screen.cpp
 *
 *  Created on: 05-Feb-2016
 *      Author: vivek
 */

#include "Screen.h"

Screen::Screen(int width, int height){
	SCREEN_WIDTH = width;
	SCREEN_HEIGHT = height;
	window = NULL;
	renderer = NULL;
	texture = NULL;
	buffer = NULL;
}

bool Screen::init(){

	if(SDL_Init(SDL_INIT_VIDEO) < 0){
		cout << "SDL Init Failed" << endl;
		return false;
	}

	window = SDL_CreateWindow("TestWindow", SDL_WINDOWPOS_UNDEFINED,
			SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	if(window == NULL){
		cout << "Couldn't create window " << SDL_GetError()<<endl;
		SDL_Quit();
		return false;
	}

	renderer = SDL_CreateRenderer(window, 1, SDL_RENDERER_PRESENTVSYNC);
	if( renderer == NULL){
		cout << "Couidn't create renderer"<< endl;
		SDL_DestroyWindow(window);
		SDL_Quit();
		return false;
	}

	texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888,
			SDL_TEXTUREACCESS_STATIC, SCREEN_WIDTH, SCREEN_HEIGHT);
	if( texture == NULL){
		cout << "Couidn't create texture"<< endl;
		SDL_DestroyRenderer(renderer);
		SDL_DestroyWindow(window);
		SDL_Quit();
		return false;
	}

	buffer = new Uint32[SCREEN_WIDTH*SCREEN_HEIGHT];
	memset(buffer, 0, SCREEN_WIDTH*SCREEN_HEIGHT*sizeof(Uint32));

	return true;
}

void Screen::clearBuffer(){
	memset(buffer, 0, SCREEN_WIDTH*SCREEN_HEIGHT*sizeof(Uint32));
}

void Screen::setPixel(int x, int y, Uint8 red, Uint8 green, Uint8 blue){

	if(x<0 || x>=SCREEN_WIDTH || y<0 || y>=SCREEN_HEIGHT)
		return;

	Uint32 color = 0;

	color += red;
	color <<= 8;
	color += green;
	color <<= 8;
	color += blue;
	color <<= 8;
	color += 0xFF;

	buffer[(y*SCREEN_WIDTH) + x] = color;
}

void Screen::update(){
	SDL_UpdateTexture(texture, NULL, buffer, SCREEN_WIDTH*sizeof(Uint32));
	SDL_RenderClear(renderer);
	SDL_RenderCopy(renderer, texture, NULL, NULL);
	SDL_RenderPresent(renderer);
}

bool Screen::processEvents(){
	SDL_Event event;
	if(SDL_PollEvent(&event)){
				if(event.type == SDL_QUIT)
					return false;
			}
	return true;
}

void Screen::close(){
		SDL_DestroyRenderer(renderer);
		SDL_DestroyTexture(texture);
		SDL_DestroyWindow(window);
		SDL_Quit();
}

Screen::~Screen() {
	delete [] buffer;
}

