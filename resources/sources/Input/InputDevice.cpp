// Mareike

#include "Input\InputDevice.h"

InputDevice::InputDevice(CFrame* frame) : EngineModule() {
	// Testen, ob Falcon angeschlossen (siehe anderes Projekt)
	// Wenn keine Falcon, dann Keyboard verwenden
	frame->AddDeviceKeyboard(&keyboard.getDeviceKeyboard());
	xPosition = 0.0;
	yPosition = 0.0;
}

InputDevice::~InputDevice() {
	
}

void InputDevice::update(float deltaTime, float time) {
	keyboard.getNewXPosition(xPosition);
}

float InputDevice::getXPosition() {
	return xPosition;
}

float InputDevice::getYPosition(){
	return yPosition;
}