/*
 * Particle.h
 *
 *  Created on: 05-Feb-2016
 *      Author: vivek
 */

#ifndef PARTICLE_H_
#define PARTICLE_H_

struct Particle {

	double m_x;
	double m_y;
public:
	Particle();
	virtual ~Particle();
};

#endif /* PARTICLE_H_ */