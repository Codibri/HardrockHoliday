// Mareike

#include "Input/Keyboard.h"

Keyboard::Keyboard() {
}

Keyboard::~Keyboard() {
}

float Keyboard::getNewXPosition(float oldPosition) {

	if (deviceKeyboard.KeyPressed(DIK_LEFT))
		std::cout << "DIK_LEFT" << std::endl;

	if (deviceKeyboard.KeyPressed(DIK_LEFT) && (oldPosition > -1.0))		// Links gedrückt
		return oldPosition - 0.002;
	else if (deviceKeyboard.KeyPressed(DIK_RIGHT) && (oldPosition < 1.0)) // Rechts gedrückt
		return oldPosition + 0.002;
	else 
		return oldPosition;
}

float Keyboard::getNewYPosition(float oldPosition) {
	return 0.0;
}

CDeviceKeyboard* Keyboard::getDeviceKeyboard() {	//<- kann nicht funktionieren so ;)		(Da CDeviceKeybord in diesem Falle kopiert wird. Sollte wohl ein Pointer sein)
	return &deviceKeyboard;
}