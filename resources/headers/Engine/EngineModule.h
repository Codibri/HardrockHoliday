
//by Alexander Weiﬂ, 2014

#ifndef ENGINE_MODULE_H
#define ENGINE_MODULE_H


// derive from this class to provide a core engine module for the games engine
class EngineModule
{
public:
	EngineModule();

	virtual ~EngineModule();

	// this method is called each game cycle by the Engine at any time before the update methode is called
	virtual void preUpdate();

	// this method is called each game cycle by the Engine at any time after the preUpdate method has been called but before postUpdate is called
	virtual void update(float deltaTime, float time);

	// this method is called each game cycle by the Engine at any time after the update method has been called
	virtual void postUpdate();
};

#endif