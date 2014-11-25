
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
	this->initialize();
}


HardrockHolidayModules::~HardrockHolidayModules()
{}


void HardrockHolidayModules::update(float deltaTime, float time)
{
	this->accessPrivateModule(typeid(StateMachine))->update(deltaTime, time);

	//TODO: Update the other modules for HardrockHoliday.

	//Physics

	//Audio etc..
}


void HardrockHolidayModules::initialize()
{
	// Initialize the StateMachine for HardrockHoliday.
	StateMachine* stateMachine = new StateMachine();
	this->addPrivateModule(stateMachine, typeid(StateMachine));

	std::shared_ptr<State> gameState = std::shared_ptr<State>(new GameState());

	std::string beginningState = gameState->getName();

	stateMachine->addState(std::move(gameState));

	stateMachine->startExecution(beginningState);

	//TODO: Initialize the other modules for HardrockHoliday.

	//Physics

	//Audio etc..
}