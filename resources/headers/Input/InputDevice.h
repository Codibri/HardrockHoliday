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

							// -1				1
	float getXPosition();	// Links			Rechts
	float getYPosition();	// Unten			Oben
	float getZPosition();	// Vorne (am Gerät)	Hinten (weg vom Gerät)

	// TODO: Alex Schnittstelle
	// In Loch gefallen
	void fallDown();

	// Forcefeedback - noch nicht aktiv
	void rumble(bool on, float strength);
	void block(bool on, Direction direction);

private:
	float xPosition;
	float yPosition;
	float zPosition;

	Keyboard keyboard;		// SemikolonFehler kommt wenn sich Dateien gegenseitig includen
	Falcon* falcon;
	bool useFalcon;
};

#endif