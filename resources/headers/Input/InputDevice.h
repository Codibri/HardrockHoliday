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

	float getXPosition();
	float getYPosition();

	// Forcefeedback
	void rumble(bool on, float strength);
	void block(bool on, Direction direction);

private:
	float xPosition;
	float yPosition;

	Keyboard keyboard;		// SemikolonFehler kommt wenn sich Dateien gegenseitig includen
	Falcon falcon;			
	bool useFalcon;
};

#endif