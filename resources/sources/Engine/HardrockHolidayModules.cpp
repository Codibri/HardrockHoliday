
/*by Alexander Weiß, 2014
 _____           _ _ _          _ 
/  __ \         | (_) |        (_)
| /  \/ ___   __| |_| |__  _ __ _ 
| |    / _ \ / _` | | '_ \| '__| |
| \__/\ (_) | (_| | | |_) | |  | |
 \____/\___/ \__,_|_|_.__/|_|  |_|*/

#include "Engine\HardrockHolidayModules.h"


HardrockHolidayModules::HardrockHolidayModules() : EngineModules()
{
	initialize();
}

HardrockHolidayModules::~HardrockHolidayModules()
{}


void HardrockHolidayModules::update(float deltaTime, float time)
{
	ENGINE_STATE_MACHINE->update(deltaTime, time);

	//TODO: Update the other modules for HardrockHoliday.

	//Physics

	//Audio etc..
}


void HardrockHolidayModules::initialize()
{
	DEBUG_OUT("initializing")

	// Initialize the StateMachine for HardrockHoliday.
	StateMachine* stateMachine = new StateMachine();
	this->addModule(stateMachine, typeid(StateMachine));

	std::shared_ptr<State> gameState = std::shared_ptr<State>(new GameState());

	std::string beginningState = gameState->getName();

	stateMachine->addState(std::move(gameState));

	stateMachine->startExecution(beginningState);

	//TODO: Initialize the other modules for HardrockHoliday.

	//Physics

	//Audio etc..
}