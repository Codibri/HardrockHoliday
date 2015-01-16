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

	// Falcon Init, auf Nullposition fahren, Seitenforces aktivieren
	void makeReady();
	int getFalconReadyState();

	float getNewPosition(int direction);

	void update();

	// Game Steuerung (Neu, Beenden)
	bool isKeyPressed(Game_Inputs key);

	// Schnittstellen für Forcefeedback
	void rumble(bool on, float strength);
	void block(bool on, Direction direction);
	void move_To_Origin();
	void fallDown();
	void setSandSimulationActive(bool active);

	// Positionsüberprüfung: Überprüfe, ob Motoren aufgrund der neuen Position gesperrt werden müssen
	// Rumble, falls an
	void updateBlockAndRumble();

private:
	FalconManager falconManager;
	bool rumbleOn = false;
	float rumbleStrength = 0.0;
	int falconReadyState;
};

#endif