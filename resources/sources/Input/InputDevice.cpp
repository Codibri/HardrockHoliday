// Mareike

#include "Input\InputDevice.h"

InputDevice::InputDevice(CFrame* frame) : EngineModule() {
	// TODO: Testen, ob Falcon angeschlossen (siehe anderes Projekt)
	// TODO: Wenn keine Falcon, dann Keyboard verwenden (immer nur 1)
	// TODO: (optional) Falls Probleme mit Falcon, dann auch  im laufenden Spiel wechseln ermöglichen
	useFalcon = false;

	if (useFalcon){
		//TODO benutze Falcon
	}
	else if (!useFalcon) {
		frame->AddDeviceKeyboard(keyboard.getDeviceKeyboard());
		xPosition = 0.0;
		yPosition = 0.0;
	}
}

InputDevice::~InputDevice() {
}

void InputDevice::update(float deltaTime, float time) {
	if (useFalcon){
		// TODO: Falcon
	}
	else if (!useFalcon){
		xPosition = keyboard.getNewXPosition(xPosition);
	}
}

// Position und Bewegung
float InputDevice::getXPosition() {
	return xPosition;
}

float InputDevice::getYPosition(){
	return yPosition;
}


// Forcefeedback
void InputDevice::rumble(bool on, float strength){
	if (useFalcon){
		// TODO: Falcon
	}
};

void InputDevice::block(bool on, Direction direction){
	if (useFalcon){
		// TODO: Falcon
	}
};