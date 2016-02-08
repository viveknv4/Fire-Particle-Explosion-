/*
 * Particle.cpp
 *
 *  Created on: 05-Feb-2016
 *      Author: vivek
 */

#include "Particle.h"
#include <stdlib.h>
#include <math.h>

Particle::Particle() {

	//x and y b/w -1 to +1
	m_x = 0;
	m_y = 0;

	speed = (0.1* rand())/RAND_MAX;
	direction = 2 * M_PI * rand()/RAND_MAX;

}

Particle::~Particle() {

}

void Particle::update(){
	double xspeed = speed * cos(direction);
	double yspeed = speed * sin(direction);

	m_x += xspeed;
	m_y += yspeed;
}

