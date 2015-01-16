// Mareike

#include "Input/Keyboard.h"

Keyboard::Keyboard() {
}

Keyboard::~Keyboard() {
}

float Keyboard::getNewXPosition(float oldPosition) {
	if (deviceKeyboard.KeyPressed(DIK_LEFT) && (oldPosition > -1.0f))		// Links gedrückt
		return oldPosition - 0.002f;
	else if (deviceKeyboard.KeyPressed(DIK_RIGHT) && (oldPosition < 1.0f))	// Rechts gedrückt
		return oldPosition + 0.002f;
	else 
		return (oldPosition = 0.f);
}

float Keyboard::getNewZPosition(float oldPosition) {
	if (deviceKeyboard.KeyPressed(DIK_UP) && (oldPosition > -1.0f))			// Oben/Vorne gedrückt
		return oldPosition - 0.001f;
	else if (deviceKeyboard.KeyPressed(DIK_DOWN) && (oldPosition < 1.0f))	// Zurück/Bremsen gedrückt
		return oldPosition + 0.001f;
	else
		return (oldPosition = 0.f);
}

bool Keyboard::isKeyPressed(Game_Inputs key) {
	switch (key) {
	case Game_Inputs::Reset_Key:
		return deviceKeyboard.KeyPressed(DIK_TAB);
	case Game_Inputs::End_Key:
		return deviceKeyboard.KeyPressed(DIK_SPACE);
	case Game_Inputs::Falcon_Active_Key:
		return deviceKeyboard.KeyPressed(DIK_LCONTROL);
	}
	return false;
}

CDeviceKeyboard* Keyboard::getDeviceKeyboard() {
	return &deviceKeyboard;
}