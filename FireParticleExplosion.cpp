//============================================================================
// Name        : FireParticleExplosion.cpp
// Author      : Vivek
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <SDL.h>
#include "Screen.h"
#include <stdlib.h>
#include <time.h>
#include "Swarm.h"

using namespace std;

int main(int argc, char *argv[]){

	srand(time(NULL));
	Screen screen(800, 600);
	if(screen.init() == false){
		cout << "Couldn't Initialize SDL "<<endl;
		return -1;
	}

	Swarm swarm;

	//Game_Loop--------------------------------------
	while(true){

		int elapsed = SDL_GetTicks();
		int green = ((1+sin(elapsed * 0.0001)) * 128);
		int red = ((1+sin(elapsed * 0.0002)) * 128);
		int blue = ((1+sin(elapsed * 0.0003)) * 128);

		Particle* pParticles = swarm.getParticles();
		for(int i=0; i<swarm.NPARTICLES; i++){
			Particle points = pParticles[i];
			int x = (points.m_x+1) * (screen.SCREEN_WIDTH/2);
			int y = (points.m_y+1) * (screen.SCREEN_HEIGHT/2);

			screen.setPixel(x,y,red,green,blue);
		}

		/*
		for(int x=0; x<screen.SCREEN_WIDTH; x++){
			for(int y=0; y<screen.SCREEN_HEIGHT; y++){

				screen.setPixel(x,y,red,green,blue);
			}
		}*/

		screen.update();
		if(screen.processEvents() == false)
			break;
	}
	//------------------------------------------------

	screen.close();

	return 0;
}
