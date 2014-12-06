// Mareike

#include "Engine\EngineModules.h"

class Keyboard : public EngineModule 
{
public:
	Keyboard();

	virtual ~Keyboard();

	void update(float deltaTime, float time) override;

	float getXPosition();

	float getYPosition();
};