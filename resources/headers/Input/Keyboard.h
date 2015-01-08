// Mareike u. Flip

#ifndef KEYBOARD_H
#define KEYBOARD_H

#include "root.h"
#include "Input\Constants.h"

using namespace Vektoria;

class Keyboard {
public:
	Keyboard();

	virtual ~Keyboard();

	float getNewXPosition(float oldPosition);
	float getNewZPosition(float oldPosition);

	// Game Steuerung (Neu, Beenden)
	bool isKeyPressed(Game_Inputs key);

	CDeviceKeyboard* getDeviceKeyboard();

private:
	CDeviceKeyboard deviceKeyboard;
};

#endif