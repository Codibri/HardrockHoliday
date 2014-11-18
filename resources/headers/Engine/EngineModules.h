
//by Alexander Weiﬂ, 2014

#ifndef ENGINE_MODULES_H
#define ENGINE_MODULES_H

#include <map>
#include <memory>
#include <typeindex>
#include "EngineModule.h"
#include "Utility\DebugLog.h"


// gathers all main modules that the Engine provides globally to all other classes
class EngineModules
{
public:
	EngineModules();

	virtual ~EngineModules();

	// adds an EngineModule to be returned through the access method. Returns FALSE if an EngineModule of this type is already added, otherwise TRUE
	bool addModule(EngineModule* engineModule, std::type_index moduleType);

	// returns a pointer to an added EngineModule. Returns nullptr if the requested module is not found
	EngineModule* access(std::type_index moduleType) const;

	// updates all EngineModules and should be called each game cycle. Its mandatory to implemented this seperately for each game
	virtual void update(float deltaTime, float time) = 0;

protected:
	// add / create the EngineModule instances in this method. Its mandatory to implemented this seperately for each game.
	// You need to call this in the Ctor of your derived class because c++ does not let you call an overriden virtual method from a base class
	virtual void initialize() = 0;

	std::map<std::type_index, EngineModule*> _modules;
};

#endif


