// Mareike

#include "root.h"

using namespace Vektoria;

class Keyboard {
public:
	Keyboard();

	virtual ~Keyboard();

	float getNewXPosition(float oldPosition);

	float getNewYPosition(float oldPosition);

	CDeviceKeyboard getDeviceKeyboard();

private:
	CDeviceKeyboard deviceKeyboard;
};