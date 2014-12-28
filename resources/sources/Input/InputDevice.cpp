// Mareike

#include "Input\InputDevice.h"

InputDevice::InputDevice(CFrame* frame) : EngineModule() {
	// TODO: Testen, ob Falcon angeschlossen (siehe anderes Projekt)
	// TODO: Wenn keine Falcon, dann Keyboard verwenden (immer nur 1)
	// TODO: (optional) Falls Probleme mit Falcon, dann auch  im laufenden Spiel wechseln ermöglichen
	useFalcon = true;

	frame->AddDeviceKeyboard(keyboard.getDeviceKeyboard());

	if (useFalcon){
		falcon = new Falcon();
	}
	else if (!useFalcon) {
		xPosition = 0.0;
		yPosition = 0.0;
		zPosition = 0.0;
	}
}

InputDevice::~InputDevice() {
}

void InputDevice::update(float deltaTime, float time) {
	if (useFalcon){
		xPosition = falcon->getNewPosition(0);
		yPosition = falcon->getNewPosition(1);
		zPosition = falcon->getNewPosition(2);
	}
	else if (!useFalcon){
		xPosition = keyboard.getNewXPosition(xPosition);
		zPosition = keyboard.getNewZPosition(zPosition);
	}
	// Nur zum Testen
	/*if (isKeyPressed(Game_Inputs::Reset_Key))
		std::cout << "Reset -> Escape Key!" << std::endl;
	if (isKeyPressed(Game_Inputs::End_Key))
		std::cout << "End -> Space Key!" << std::endl;*/
}


// Position und Bewegung
float InputDevice::getXPosition() {
	return xPosition;
}

float InputDevice::getYPosition() {
	return yPosition;
}

float InputDevice::getZPosition() {
	return zPosition;
}


// Forcefeedback
void InputDevice::rumble(bool on, float strength) {
	if (useFalcon){
		// TODO: Falcon
	}
};

void InputDevice::block(bool on, Direction direction) {
	if (useFalcon){
		// TODO: Falcon
	}
};


// Tastatur
bool InputDevice::isKeyPressed(Game_Inputs key) {
	return keyboard.isKeyPressed(key);
}


// Falcon
void InputDevice::move_To_Origin() {
	// TODO
}

void InputDevice::fallDown() {
	// TODO
}