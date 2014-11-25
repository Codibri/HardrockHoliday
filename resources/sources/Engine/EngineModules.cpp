
/*by Alexander Weiﬂ, 2014
 _____           _ _ _          _ 
/  __ \         | (_) |        (_)
| /  \/ ___   __| |_| |__  _ __ _ 
| |    / _ \ / _` | | '_ \| '__| |
| \__/\ (_) | (_| | | |_) | |  | |
 \____/\___/ \__,_|_|_.__/|_|  |_|*/

#include "Engine\EngineModules.h"


EngineModules::EngineModules()
{
	_lock_modules.clear();
}


EngineModules::~EngineModules()
{
	while (_lock_modules.test_and_set())
	{}

	for (std::map<std::type_index, EngineModule*>::iterator it = _modules.begin(); it != _modules.end(); ++it)
	{
		delete it->second;
	}

	_lock_modules.clear();
}


bool EngineModules::addModule(EngineModule* engineModule, std::type_index moduleType)
{
	bool success = false;

	while (_lock_modules.test_and_set())
	{}

	if (_modules.end() == _modules.find(moduleType))
	{
		_modules[moduleType] = engineModule;
		success = true;
	}

	_lock_modules.clear();

	return success;
}


EngineModule* EngineModules::access(std::type_index moduleType)
{
	EngineModule* module = nullptr;

	while (_lock_modules.test_and_set())
	{}

	if (_modules.end() != _modules.find(moduleType))
	{
		module = _modules.at(moduleType);
	}
	else
	{
		DEBUG_OUT("Error (EngineModules): Module of moduleType was not found. Returned a nullptr. \n");
	}

	_lock_modules.clear();

	return module;
}

