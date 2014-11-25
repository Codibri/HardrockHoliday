
/*by Alexander Weiﬂ, 2014
 _____           _ _ _          _ 
/  __ \         | (_) |        (_)
| /  \/ ___   __| |_| |__  _ __ _ 
| |    / _ \ / _` | | '_ \| '__| |
| \__/\ (_) | (_| | | |_) | |  | |
 \____/\___/ \__,_|_|_.__/|_|  |_|*/

#ifndef ENGINE_MODULES_H
#define ENGINE_MODULES_H

#include <map>
#include <memory>
#include <atomic>
#include <typeindex>
#include "EngineModule.h"
#include "Utility\DebugLog.h"


// Gathers all main modules that the Engine provides globally to all other classes.
class EngineModules
{
public:
	EngineModules();

	virtual ~EngineModules();

	// Adds an EngineModule to be returned through the access method. Returns FALSE if an EngineModule of this type is already added, otherwise TRUE.
	bool addPublicModule(EngineModule* engineModule, std::type_index moduleType);

	// Adds an EngineModule to be managed by EngineModules itself.
	bool addPrivateModule(EngineModule* engineModule, std::type_index moduleType);

	// Returns a pointer to an added EngineModule. Returns a nullptr if the requested module is not found.
	EngineModule* accessPublicModule(std::type_index moduleType);

	// Updates all EngineModules and should be called each game cycle. Its mandatory to implemented this seperately for each game.
	virtual void update(float deltaTime, float time) = 0;

protected:
	// Add / create the EngineModule instances in this method. Its mandatory to implemented this seperately for each game.
	// You need to call this in the Ctor of your derived class because c++ does not let you call an overriden virtual method from a base class.
	virtual void initialize() = 0;

	EngineModule* accessPrivateModule(std::type_index moduleType);
	void deletePublicModules();
	void deletePrivateModules();

	std::map<std::type_index, EngineModule*> _publicModules;
	std::map<std::type_index, EngineModule*> _privateModules;
	std::atomic_flag _lock_publicModules;
	std::atomic_flag _lock_privateModules;
};

#endif


