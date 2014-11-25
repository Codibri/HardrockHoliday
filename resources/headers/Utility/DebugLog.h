
/*by Alexander Weiﬂ, 2014
 _____           _ _ _          _ 
/  __ \         | (_) |        (_)
| /  \/ ___   __| |_| |__  _ __ _ 
| |    / _ \ / _` | | '_ \| '__| |
| \__/\ (_) | (_| | | |_) | |  | |
 \____/\___/ \__,_|_|_.__/|_|  |_|*/

#ifndef DEBUG_LOG_H
#define DEBUG_LOG_H

#include <iostream>

#define DEBUG_OUT(debugMessage) DebugLog::getInstance()->log(debugMessage);


// The DebugLog is global singleton interface for easy debug messages that are only triggered on debug builds.
class DebugLog
{
public:
	~DebugLog();

	static DebugLog* getInstance();

	void log(const std::string& debugMessage);


private:
	DebugLog();

	static DebugLog* _instance;
};

#endif