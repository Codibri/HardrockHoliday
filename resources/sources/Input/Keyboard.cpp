// Mareike

#include "Input/Keyboard.h"

Keyboard::Keyboard() {
}

Keyboard::~Keyboard() {
}

float Keyboard::getNewXPosition(float oldPosition) {
	if (deviceKeyboard.KeyPressed(DIK_LEFT) && (oldPosition > -1.0))		// Links gedrückt
		return oldPosition - 0.002;
	else if (deviceKeyboard.KeyPressed(DIK_RIGHT) && (oldPosition < 1.0))	// Rechts gedrückt
		return oldPosition + 0.002;
	else 
		return oldPosition;
}

float Keyboard::getNewZPosition(float oldPosition) {
	if (deviceKeyboard.KeyPressed(DIK_UP) && (oldPosition > -1.0))			// Oben/Vorne gedrückt
		return oldPosition - 0.002;
	else if (deviceKeyboard.KeyPressed(DIK_DOWN) && (oldPosition < 1.0))	// Zurück/Bremsen gedrückt
		return oldPosition + 0.002;
	else
		return oldPosition;
}

CDeviceKeyboard* Keyboard::getDeviceKeyboard() {	//<- kann nicht funktionieren so ;)		(Da CDeviceKeybord in diesem Falle kopiert wird. Sollte wohl ein Pointer sein)
	return &deviceKeyboard;
}