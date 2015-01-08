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
		return oldPosition - 0.001;
	else if (deviceKeyboard.KeyPressed(DIK_DOWN) && (oldPosition < 1.0))	// Zurück/Bremsen gedrückt
		return oldPosition + 0.001;
	else
		return oldPosition;
}

bool Keyboard::isKeyPressed(Game_Inputs key) {
	switch (key) {
	case Game_Inputs::Reset_Key:
		return deviceKeyboard.KeyPressed(DIK_TAB);
	case Game_Inputs::End_Key:
		return deviceKeyboard.KeyPressed(DIK_SPACE);
	}
	return false;
}

CDeviceKeyboard* Keyboard::getDeviceKeyboard() {
	return &deviceKeyboard;
}