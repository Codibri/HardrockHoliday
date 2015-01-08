// Mareike

#include "Input\InputDevice.h"

InputDevice::InputDevice(CFrame* frame) : EngineModule() {
	// TODO: Testen, ob Falcon angeschlossen (siehe anderes Projekt)
	// TODO: Wenn keine Falcon, dann Keyboard verwenden (immer nur 1)
	// TODO: (optional) Falls Probleme mit Falcon, dann auch  im laufenden Spiel wechseln ermöglichen
	useFalcon = false;

	if (useFalcon){
		falcon = new Falcon();
		//falcon->move_To_Origin();
	}
	else if (!useFalcon) {
		frame->AddDeviceKeyboard(keyboard.getDeviceKeyboard());
		xPosition = 0.0;
		yPosition = 0.0;
		zPosition = 0.0;
	}
}

InputDevice::~InputDevice() {
}

void InputDevice::update(float deltaTime, float time) {
	if (useFalcon){
		/*count++;
		if (count == 100) {
			std::cout << "Rumble an" << std::endl;
			falcon->rumble(true, 8.0);
		}
		if (count == 300) {
			std::cout << "Rumble aus" << std::endl;
			falcon->rumble(false, 8.0);
		}*/
		xPosition = falcon->getNewPosition(0);
		yPosition = falcon->getNewPosition(1);
		zPosition = falcon->getNewPosition(2);
		falcon->updateBlockAndRumble();
	}
	else if (!useFalcon){
		xPosition = keyboard.getNewXPosition(xPosition);
		zPosition = keyboard.getNewZPosition(zPosition);
	}
	// Nur zum Testen
	if (isKeyPressed(Game_Inputs::Reset_Key))
		std::cout << "Reset -> Tab Key!" << std::endl;
	if (isKeyPressed(Game_Inputs::End_Key))
		std::cout << "End -> Space Key!" << std::endl;
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
		falcon->rumble(on, strength);
	}
};

void InputDevice::block(bool on, Direction direction) {
	if (useFalcon){
		// TODO: Falcon
	}
};


// Game Steuerung (Neu, Beenden)
bool InputDevice::isKeyPressed(Game_Inputs key) {
	if (useFalcon){
		return falcon->isKeyPressed(key);
	}
	else {
		return keyboard.isKeyPressed(key);
	}
	return false;
}


// Falcon
void InputDevice::move_To_Origin() {
	if (useFalcon){
		falcon->move_To_Origin();
	}
}

void InputDevice::fallDown() {
	// TODO
}