
//by Alexander Weiﬂ, 2014

#include "Engine\EngineModules.h"


EngineModules::EngineModules()
{}


EngineModules::~EngineModules()
{
	for (std::map<std::type_index, void*>::iterator it = _modules.begin(); it != _modules.end(); ++it)
	{
		delete it->second;
	}
}


bool EngineModules::addModule(void* engineModule, std::type_index moduleType)
{
	bool success = false;

	if (_modules.end() == _modules.find(moduleType))
	{
		_modules[moduleType] = engineModule;
		success = true;
	}

	return success;
}


void* EngineModules::access(std::type_index moduleType) const
{
	void* module = nullptr;

	if (_modules.end() != _modules.find(moduleType))
	{
		module = _modules.at(moduleType);
	}
	else
	{
		DEBUG_OUT("Error (EngineModules): module of moduleType was not found. Returned a nullptr. \n");
	}

	return module;
}

