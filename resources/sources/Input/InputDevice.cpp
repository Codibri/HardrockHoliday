// Mareike

#include "Input\InputDevice.h"

InputDevice::InputDevice(CFrame* frame) : EngineModule() {
	// Testen, ob Falcon angeschlossen (siehe anderes Projekt)
	// Wenn keine Falcon, dann Keyboard verwenden
	useFalcon = false;

	if (useFalcon){
		//TODO benutze Falcon
	}
	else if (!useFalcon){//benutze Keyboard
		frame->AddDeviceKeyboard(&keyboard.getDeviceKeyboard());
	}
	xPosition = 0.0;
	yPosition = 0.0;
}

InputDevice::~InputDevice() {
	
}

void InputDevice::update(float deltaTime, float time) {
	if (useFalcon){
		//TODO benutze Falcon
	}
	else if (!useFalcon){//benutze Keyboard
		//wenn pfeiltasten grdrueckt, dann neue xPosition
		xPosition = keyboard.getNewXPosition(xPosition);
	}
}

float InputDevice::getXPosition() {
	return xPosition;
}

float InputDevice::getYPosition(){
	return yPosition;
}


//Forcefeedback methoden fuer Falcon
void InputDevice::rumble(bool on, float strength){
	if (useFalcon){
		//TODO benutze Falcon Methoden
	}
};

void InputDevice::block(bool on, Direction direction){
	if (useFalcon){
		//TODO benutze Falcon Methoden
	}
};