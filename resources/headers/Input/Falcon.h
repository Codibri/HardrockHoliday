// Mareike u. Flip

#ifndef FALCON_H
#define FALCON_H

#include "Input/Input.h"

class Falcon {
public:
	Falcon();

	virtual ~Falcon();

	//update-methode fuer Falcon benoetigt?
	//void update(float deltaTime, float time);

	float getNewXPosition(float oldPosition);
	float getNewYPosition(float oldPosition);

	//Schnittstellen fuer Forcefeedback
	void rumble(bool on, float strength);
	void block(bool on, Direction direction);
};

#endif