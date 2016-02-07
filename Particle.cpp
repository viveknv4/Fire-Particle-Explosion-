/*
 * Particle.cpp
 *
 *  Created on: 05-Feb-2016
 *      Author: vivek
 */

#include "Particle.h"
#include <stdlib.h>

Particle::Particle() {

	//x and y b/w -1 to +1
	m_x = ((2.0*rand())/RAND_MAX) - 1;
	m_y = ((2.0*rand())/RAND_MAX) - 1;

}

Particle::~Particle() {

}

void Particle::update(){
	const double xspeed = 0.01 * (((2.0*rand())/RAND_MAX) - 1);
	const double yspeed = 0.01 * (((2.0*rand())/RAND_MAX) - 1);

	m_x += xspeed;
	m_y += yspeed;
}

