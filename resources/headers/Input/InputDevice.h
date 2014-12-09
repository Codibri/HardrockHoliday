// Mareike u. Flip

#ifndef INPUTDEVICE_H
#define INPUTDEVICE_H

#include "Engine\EngineModules.h"
#include "Input/Keyboard.h"
#include "Input/Input.h"

enum Direction
{
	Left,
	Right
};

using namespace Vektoria;

class InputDevice : public EngineModule {
public:
	InputDevice(CFrame* frame);

	virtual ~InputDevice();

	void update(float deltaTime, float time) override;

	float getXPosition();

	float getYPosition();
	//Keyboard keyboard;
	//Schnittstellen fuer Forcefeedback
	void rumble(bool on, float strength);
	void block(bool on, Direction direction);

private:
	float xPosition;
	float yPosition;

	//ist Falcon angeschlossen
	bool falcon;
	
};

#endif