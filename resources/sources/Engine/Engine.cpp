
/*by Alexander Weiﬂ, 2014
 _____           _ _ _          _ 
/  __ \         | (_) |        (_)
| /  \/ ___   __| |_| |__  _ __ _ 
| |    / _ \ / _` | | '_ \| '__| |
| \__/\ (_) | (_| | | |_) | |  | |
 \____/\___/ \__,_|_|_.__/|_|  |_|*/

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
