	
/*by Alexander Weiﬂ, 2014
 _____           _ _ _          _ 
/  __ \         | (_) |        (_)
| /  \/ ___   __| |_| |__  _ __ _ 
| |    / _ \ / _` | | '_ \| '__| |
| \__/\ (_) | (_| | | |_) | |  | |
 \____/\___/ \__,_|_|_.__/|_|  |_|*/

#include "Utility\DebugLog.h"


DebugLog* DebugLog::_instance = nullptr;


DebugLog::DebugLog()
{}


DebugLog::~DebugLog()
{
	if (nullptr != _instance)
	{
		delete _instance;
	}
}


DebugLog* DebugLog::getInstance()
{
	if (nullptr == _instance)
	{
		_instance = new DebugLog();
		return _instance;
	}

	return _instance;
}


void DebugLog::log(const std::string& debugMessage)
{
#ifdef _Debug
		std::cout << debugMessage << std::endl;
#endif
}