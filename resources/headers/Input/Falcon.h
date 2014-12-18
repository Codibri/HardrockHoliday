// Mareike u. Flip

#ifndef FALCON_H
#define FALCON_H

#define DIRECTION_RIGHT		0
#define DIRECTION_LEFT		1
#define DIRECTION_TOP		2
#define DIRECTION_BOTTOM	3
#define DIRECTION_BACK		4
#define DIRECTION_FRONT		5

#define CROSSING_PRECISION	0.2	// in cm

#include "Input/Input.h"
#include "Input/FalconManager.h"
#include <hdl/hdl.h>
#include "hdlu/hdlu.h"

class Falcon {
public:
	Falcon();

	
	virtual ~Falcon();

	float getNewXPosition();

	void update();

	//Schnittstellen fuer Forcefeedback
	void rumble(bool on, float strength);
	//void block(bool on, Direction direction);

private:
	FalconManager falconManager;
};

#endif