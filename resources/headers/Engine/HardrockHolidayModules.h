
//by Alexander Wei�, 2014

#ifndef HARDROCK_HOLIDAY_MODULES_H
#define HARDROCK_HOLIDAY_MODULES_H

#include "Engine\EngineModules.h"
#include "Engine\StateMachine.h"
#include "Engine\States.h"
#include "Utility\DebugLog.h"


// implementation of EngineModules for the game HardrockHoliday
class HardrockHolidayModules : public EngineModules
{
public:
	HardrockHolidayModules();

	~HardrockHolidayModules();

protected:
	void initialize() override;
};

#endif