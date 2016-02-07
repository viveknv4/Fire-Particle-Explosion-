/*
 * Swarm.cpp
 *
 *  Created on: 06-Feb-2016
 *      Author: vivek
 */

#include "Swarm.h"

Swarm::Swarm() {
	m_particles = new Particle[NPARTICLES];

}

Swarm::~Swarm() {
	delete [] m_particles;
}

void Swarm::update(){
	for(int i = 0; i<NPARTICLES; i++){
		m_particles[i].update();
	}
}

