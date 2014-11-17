
//by Alexander Weiﬂ, 2014

#ifndef ENGINE_H
#define ENGINE_H

#include "Engine\EngineMakros.h"
#include "Engine\EngineModules.h"
#include "Engine\GlobalResources.h"


// the Engine is available to all other classes as it is a singleton. It provides important core-services to many other classes through the modules it holds 
class Engine
{
public:
	static Engine* getInstance();

	~Engine();

	EngineModules* engineModules;
	static GlobalResources globalResources;

private:
	void initialize();

	static Engine* _instance;

	Engine();
};

#endif