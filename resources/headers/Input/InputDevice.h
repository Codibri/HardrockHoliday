// Mareike u. Flip

#ifndef INPUTDEVICE_H
#define INPUTDEVICE_H

#include "Engine\EngineModules.h"
#include "Input\Keyboard.h"
#include "Input\Falcon.h"

using namespace Vektoria;


class InputDevice : public EngineModule {
public:
	InputDevice(CFrame* frame);

	virtual ~InputDevice();

	void update(float deltaTime, float time) override;

	// Schnittstellen
							// -1				1
	float getXPosition();	// Links			Rechts
	float getYPosition();	// Unten			Oben
	float getZPosition();	// Vorne (am Gerät)	Hinten (weg vom Gerät)

	// TODO: Forcefeedback
	void rumble(bool on, float strength);
	void block(bool on, Direction direction);

	// Game Steuerung (Neu, Beenden)
	bool isKeyPressed(Game_Inputs key);

	// TODO: Falcon
	void move_To_Origin();
	void fallDown();
	void onPlayerDead();
	void onPlayerReset();

private:
	float xPosition;
	float yPosition;
	float zPosition;

	Keyboard keyboard;		// SemikolonFehler kommt wenn sich Dateien gegenseitig includen
	Falcon* falcon;
	bool useFalcon;

	int count = 0;
};

#endif