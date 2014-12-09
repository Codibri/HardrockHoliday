// Mareike

#include "Input/Keyboard.h"

Keyboard::Keyboard() {
}

Keyboard::~Keyboard() {
}

float Keyboard::getNewXPosition(float oldPosition) {
	if (deviceKeyboard.KeyPressed(DIK_LEFT) && oldPosition > -1.0) // Links gedrückt
		return oldPosition - 0.1;
	if (deviceKeyboard.KeyPressed(DIK_RIGHT) && oldPosition < 1.0) // Rechts gedrückt
		return oldPosition + 0.1;
}

float Keyboard::getNewYPosition(float oldPosition) {
	return 0.0;
}

CDeviceKeyboard Keyboard::getDeviceKeyboard() {
	return deviceKeyboard;
}