/*
 * Screen.h
 *
 *  Created on: 05-Feb-2016
 *      Author: vivek
 */

#ifndef SCREEN_H_
#define SCREEN_H_

#include <iostream>
#include <SDL.h>

using namespace std;

class Screen {

	public:
	    int SCREEN_WIDTH;
		int SCREEN_HEIGHT;

	private:
		SDL_Window *window;
		SDL_Renderer *renderer;
		SDL_Texture *texture;
		Uint32 *buffer;

	public:
		Screen(int, int);
		bool init();
		void setPixel(int, int, Uint8, Uint8, Uint8);
		void update();
		bool processEvents();
		void close();
		virtual ~Screen();
};

#endif /* SCREEN_H_ */
