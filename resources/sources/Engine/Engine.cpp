
//by Alexander Weiﬂ, 2014

#include "Engine\Engine.h"


Engine* Engine::_instance = nullptr;


Engine::Engine()
{}


Engine::~Engine()
{
	if (nullptr != _instance)
	{
		delete _instance;
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
