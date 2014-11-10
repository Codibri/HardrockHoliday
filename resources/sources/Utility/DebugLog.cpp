	
//by Alexander Weiﬂ, 2014

#include "Utility\DebugLog.h"


DebugLog* DebugLog::_instance = nullptr;


DebugLog::DebugLog()
{}


DebugLog::~DebugLog()
{}


DebugLog* DebugLog::getInstance()
{
	if (nullptr == _instance)
	{
		_instance = new DebugLog();
		return _instance;
	}

	return _instance;
}


void DebugLog::log(std::string& debugMessage)
{
#ifdef _Debug
		std::cout << debugMessage << std::endl;
#endif
}