// Mareike

#include "Engine\EngineModules.h"
#include "Keyboard.h"


class InputDevice : public EngineModule {
public:
	InputDevice(CFrame* frame);

	virtual ~InputDevice();

	void update(float deltaTime, float time) override;

	float getXPosition();

	float getYPosition();

private:
	float xPosition, yPosition;

	Keyboard keyboard;
};