// Mareike

#include "Engine\Keyboard.h"

Keyboard::Keyboard() : EngineModule() {
	// Testen, ob Falcon angeschlossen (siehe anderes Projekt)

	// Wenn keine Falcon, dann Keyboard initialisieren
	// CDeviceKeyboard keyboard;
	//_frameVektoria.AddDeviceKeyboard(&keyboard)
	xPosition = 0.0;
	yPosition = 0.0;
}

Keyboard::~Keyboard() {

}

void Keyboard::update(float deltaTime, float time) {
	//if (keyboard::KeyPressed(DIK_LEFT) && xPosition > -1.0) // Links gedrückt
		//xPosition -= 0.01;
	//if (keyboard::KeyPressed(DIK_RIGHT) && xPosition < 1.0) // Rechts gedrückt
		//xPosition += 0.01;
}

float Keyboard::getXPosition() {
	return xPosition;
}

float Keyboard::getYPosition(){
	return yPosition;
}