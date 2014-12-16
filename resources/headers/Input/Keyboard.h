// Mareike u. Flip

#ifndef KEYBOARD_H
#define KEYBOARD_H

#include "root.h"
#include "Input/Input.h"

using namespace Vektoria;

class Keyboard{
public:
	Keyboard();

	virtual ~Keyboard();

	float getNewXPosition(float oldPosition);
	float getNewYPosition(float oldPosition);

	CDeviceKeyboard* getDeviceKeyboard();

	void testKeyboard();

private:
	CDeviceKeyboard deviceKeyboard;
};

#endif