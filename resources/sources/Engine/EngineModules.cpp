
/*by Alexander Weiß, 2014
 _____           _ _ _          _ 
/  __ \         | (_) |        (_)
| /  \/ ___   __| |_| |__  _ __ _ 
| |    / _ \ / _` | | '_ \| '__| |
| \__/\ (_) | (_| | | |_) | |  | |
 \____/\___/ \__,_|_|_.__/|_|  |_|*/

#include "Engine\EngineModules.h"


EngineModules::EngineModules()
{
	_lock_publicModules.clear();
	_lock_privateModules.clear();
}


EngineModules::~EngineModules()
{
	this->deletePublicModules();
	this->deletePrivateModules();
}


bool EngineModules::addPublicModule(EngineModule* engineModule, std::type_index moduleType)
{
	bool success = false;

	while (_lock_publicModules.test_and_set())
	{}

	if (_publicModules.end() == _publicModules.find(moduleType))
	{
		_publicModules[moduleType] = engineModule;
		success = true;
	}

	_lock_publicModules.clear();

	return success;
}


bool EngineModules::addPrivateModule(EngineModule* engineModule, std::type_index moduleType)
{
	bool success = false;

	while (_lock_privateModules.test_and_set())
	{}

	if (_privateModules.end() == _privateModules.find(moduleType))
	{
		_privateModules[moduleType] = engineModule;
		success = true;
	}

	_lock_privateModules.clear();

	return success;
}


EngineModule* EngineModules::accessPublicModule(std::type_index moduleType)
{
	EngineModule* module = nullptr;

	while (_lock_publicModules.test_and_set())
	{}

	if (_publicModules.end() != _publicModules.find(moduleType))
	{
		module = _publicModules.at(moduleType);
	}
	else
	{
		DEBUG_OUT("Error (EngineModules): Module of moduleType was not found. Returned a nullptr. \n");
	}

	_lock_publicModules.clear();

	return module;
}


EngineModule* EngineModules::accessPrivateModule(std::type_index moduleType)
{
	EngineModule* module = nullptr;

	while (_lock_privateModules.test_and_set())
	{}

	if (_privateModules.end() != _privateModules.find(moduleType))
	{
		module = _privateModules.at(moduleType);
	}
	else
	{
		DEBUG_OUT("Error (EngineModules): Module of moduleType was not found. Returned a nullptr. \n");
	}

	_lock_privateModules.clear();

	return module;
}


void EngineModules::deletePublicModules()
{
	while (_lock_publicModules.test_and_set())
	{}

	for (std::map<std::type_index, EngineModule*>::iterator it = _publicModules.begin(); it != _publicModules.end(); ++it)
	{
		delete it->second;
	}

	_lock_publicModules.clear();
}


void EngineModules::deletePrivateModules()
{
	while (_lock_privateModules.test_and_set())
	{}

	for (std::map<std::type_index, EngineModule*>::iterator it = _privateModules.begin(); it != _privateModules.end(); ++it)
	{
		delete it->second;
	}

	_lock_privateModules.clear();
}