// Mareike

#include "Input/Keyboard.h"

Keyboard::Keyboard() {
}

Keyboard::~Keyboard() {
}

float Keyboard::getNewXPosition(float oldPosition) {
	if (deviceKeyboard.KeyPressed(DIK_LEFT) && oldPosition > -1.0)		// Links gedrückt
	{
		float a = oldPosition - 0.02;
		std::cout << oldPosition << std::endl;
		return a;
	}
		
	else if (deviceKeyboard.KeyPressed(DIK_RIGHT) && oldPosition < 1.0) // Rechts gedrückt
		return oldPosition + 0.02;
	else
		std::cout << oldPosition << std::endl;
		
		return oldPosition;
}

float Keyboard::getNewYPosition(float oldPosition) {
	return 0.0;
}

CDeviceKeyboard* Keyboard::getDeviceKeyboard() {	//<- kann nicht funktionieren so ;)		(Da CDeviceKeybord in diesem Falle kopiert wird. Sollte wohl ein Pointer sein)
	return &deviceKeyboard;
}

void testKeyboard(CDeviceKeyboard deviceKeyboard) {
	if (deviceKeyboard.KeyPressed(DIK_W))
		std::cout << "asd" << std::endl;
}