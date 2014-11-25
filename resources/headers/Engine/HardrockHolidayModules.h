
/*by Alexander Weiﬂ, 2014
 _____           _ _ _          _ 
/  __ \         | (_) |        (_)
| /  \/ ___   __| |_| |__  _ __ _ 
| |    / _ \ / _` | | '_ \| '__| |
| \__/\ (_) | (_| | | |_) | |  | |
 \____/\___/ \__,_|_|_.__/|_|  |_|*/

#ifndef HARDROCK_HOLIDAY_MODULES_H
#define HARDROCK_HOLIDAY_MODULES_H

#include "Engine\EngineModules.h"
#include "Engine\StateMachine.h"
#include "Engine\States.h"
#include "Utility\DebugLog.h"


// Implementation of EngineModules for the game HardrockHoliday
class HardrockHolidayModules : public EngineModules
{
public:
	HardrockHolidayModules();

	~HardrockHolidayModules();

protected:
	void update(float deltaTime, float time) override;

	void initialize() override;

};

#endif