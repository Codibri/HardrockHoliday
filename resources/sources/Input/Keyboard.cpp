// Mareike

#include "Input/Keyboard.h"

Keyboard::Keyboard() {
}

Keyboard::~Keyboard() {
}

float Keyboard::getNewXPosition(float oldPosition) {
	if (deviceKeyboard.KeyPressed(DIK_LEFT) && oldPosition > -1.0f) // Links gedrückt
		return oldPosition - 0.1f;
	if (deviceKeyboard.KeyPressed(DIK_RIGHT) && oldPosition < 1.0f) // Rechts gedrückt
		return oldPosition + 0.1f;
	else //elseZweig wegen Compilerwarnung
		return 0;
}

float Keyboard::getNewYPosition(float oldPosition) {
	return 0.0;
}

CDeviceKeyboard Keyboard::getDeviceKeyboard() {
	return deviceKeyboard;
}