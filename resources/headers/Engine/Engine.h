
/*by Alexander Weiﬂ, 2014
 _____           _ _ _          _ 
/  __ \         | (_) |        (_)
| /  \/ ___   __| |_| |__  _ __ _ 
| |    / _ \ / _` | | '_ \| '__| |
| \__/\ (_) | (_| | | |_) | |  | |
 \____/\___/ \__,_|_|_.__/|_|  |_|*/
                                  
#ifndef ENGINE_H
#define ENGINE_H

#include "Engine\EngineMakros.h"
#include "Engine\EngineModules.h"
#include "Engine\GlobalResources.h"


// The Engine is available to all other classes as it is a singleton. It provides important core-services to many other classes through the modules it holds. 
class Engine
{
public:
	static Engine* getInstance();

	~Engine();

	EngineModules* engineModules;
	static GlobalResources globalResources;

private:
	static Engine* _instance;

	Engine();
};

#endif