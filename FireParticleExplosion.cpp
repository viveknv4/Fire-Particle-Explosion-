//============================================================================
// Name        : FireParticleExplosion.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <SDL.h>
#include "Screen.h"

using namespace std;

int main(int argc, char *argv[]){

	Screen displayOnScreen(800, 600);
	if(displayOnScreen.init() == false){
		cout << "Couldn't Initialize SDL "<<endl;
		return -1;
	}

	//Game_Loop--------------------------------------

	while(true){
		//TheGameRelateProg
		if(displayOnScreen.processEvents() == false)
			break;
	}

	//------------------------------------------------

	displayOnScreen.close();

	return 0;
}
