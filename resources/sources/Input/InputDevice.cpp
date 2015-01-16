// Mareike

#include "Input\InputDevice.h"

InputDevice::InputDevice(CFrame* frame) : EngineModule() {
	// TODO: Testen, ob Falcon angeschlossen (siehe anderes Projekt)
	// TODO: Wenn keine Falcon, dann Keyboard verwenden (immer nur 1)
	// TODO: (optional) Falls Probleme mit Falcon, dann auch  im laufenden Spiel wechseln ermöglichen
	useFalcon = true;

	if (useFalcon){
		falcon = new Falcon();
		if (falcon->getFalconReadyState() == 0) {
			useFalcon = false;
		}
		//falcon->move_To_Origin();
	}
	//else if (!useFalcon) {
		frame->AddDeviceKeyboard(keyboard.getDeviceKeyboard());
		xPosition = 0.0;
		yPosition = 0.0;
		zPosition = 0.0;
	//}
}

InputDevice::~InputDevice() {
}

void InputDevice::update(float deltaTime, float time) {
	if (useFalcon){
		/*count++;
		if (count == 1000) {
			std::cout << "Rumble an" << std::endl;
			falcon->rumble(true, 10.0);
		}
		if (count == 1250) {
			std::cout << "Rumble aus" << std::endl;
			falcon->rumble(false, 10.0);
		}*/

		count++;
		if (count == 1200) {
			std::cout << "1" << std::endl;
			falcon->setSandSimulationActive(true);
		}
		if (count == 1800) {
			std::cout << "0" << std::endl;
			falcon->setSandSimulationActive(false);
		}

		xPosition = falcon->getNewPosition(0);
		yPosition = falcon->getNewPosition(1);
		zPosition = falcon->getNewPosition(2);
		falcon->updateBlockAndRumble();
	}
	else if (!useFalcon){
		xPosition = keyboard.getNewXPosition(xPosition);
		zPosition = keyboard.getNewZPosition(zPosition);
	}

	waitTimeFalcon++;

	if ((waitTimeFalcon > 80) && isKeyPressed(Game_Inputs::Falcon_Active_Key)) {
		if (useFalcon || (!useFalcon && falcon->getFalconReadyState() == 1)) {
			useFalcon = !useFalcon;
			waitTimeFalcon = 0;
		}
	}


	// Nur zum Testen
	/*if (isKeyPressed(Game_Inputs::Reset_Key))
		std::cout << "Reset -> Tab Key!" << std::endl;
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
		if (falcon->isKeyPressed(key)) {
			return true;
		}
	}
	if (keyboard.isKeyPressed(key)) {
		return true;
	}
	return false;
}


// Falcon
void InputDevice::move_To_Origin() {
	if (useFalcon){
		falcon->move_To_Origin();
	}
}

void InputDevice::fallDown() {}

void InputDevice::onPlayerDead() {}

void InputDevice::onPlayerReset() {}

void InputDevice::setSandSimulationActive(bool active) {
	falcon->setSandSimulationActive(active);
}