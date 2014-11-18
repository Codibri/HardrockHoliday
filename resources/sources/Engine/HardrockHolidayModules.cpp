
//by Alexander Weiß, 2014

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

	//TODO: update the other modules for HardrockHoliday

	//Physics

	//Audio etc..
}


void HardrockHolidayModules::initialize()
{
	DEBUG_OUT("initializing")

	// initialize the StateMachine for HardrockHoliday
	StateMachine* stateMachine = new StateMachine();
	this->addModule(stateMachine, typeid(StateMachine));

	std::shared_ptr<State> gameState = std::shared_ptr<State>(new GameState());

	std::string beginningState = gameState->getName();

	stateMachine->addState(std::move(gameState));

	stateMachine->startExecution(beginningState);

	//TODO: initialize the other modules for HardrockHoliday

	//Physics

	//Audio etc..
}