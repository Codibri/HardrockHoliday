
//by Alexander Weiﬂ, 2014

#include "Engine\Engine.h"
#include "Engine\HardrockHolidayModules.h"


Engine* Engine::_instance = nullptr;

GlobalResources Engine::globalResources;


Engine::Engine()
{}


Engine::~Engine()
{
	if (nullptr != _instance)
	{
		delete _instance;
	}

	if (nullptr != engineModules)
	{
		delete engineModules;
	}
}


Engine* Engine::getInstance()
{
	if (nullptr == _instance)
	{
		_instance = new Engine();

		return _instance;
	}

	return _instance;
}
