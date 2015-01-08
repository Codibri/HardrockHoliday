
/*by Alexander Weiß, 2014
 _____           _ _ _          _ 
/  __ \         | (_) |        (_)
| /  \/ ___   __| |_| |__  _ __ _ 
| |    / _ \ / _` | | '_ \| '__| |
| \__/\ (_) | (_| | | |_) | |  | |
 \____/\___/ \__,_|_|_.__/|_|  |_|*/

#include "Engine\HardrockHolidayModules.h"
#include "Engine\Engine.h"


HardrockHolidayModules::HardrockHolidayModules() : EngineModules()
{
	this->initialize();
}


HardrockHolidayModules::~HardrockHolidayModules()
{}


void HardrockHolidayModules::update(float deltaTime, float time)
{
	EngineModule* inputDevice = this->accessPublicModule(typeid(InputDevice));
	EngineModule* stateMachine = this->accessPrivateModule(typeid(StateMachine));
	EngineModule* physicsModule = this->accessPublicModule(typeid(PhysicsModule));
	EngineModule* soundManager = this->accessPublicModule(typeid(SoundManager));

	// Pre-Updates
	if (inputDevice) { inputDevice->preUpdate(deltaTime, time); }

	if (stateMachine){ stateMachine->preUpdate(deltaTime, time); }

	if (physicsModule){ physicsModule->preUpdate(deltaTime, time); }

	if (soundManager){ soundManager->preUpdate(deltaTime, time); }

	// Updates
	if (inputDevice) { inputDevice->update(deltaTime, time); }

	if (stateMachine){ stateMachine->update(deltaTime, time); }

	if (physicsModule){ physicsModule->update(deltaTime, time); }

	if (soundManager){ soundManager->update(deltaTime, time); }

	// Post-Updates
	if (inputDevice) { inputDevice->postUpdate(deltaTime, time); }

	if (stateMachine){ stateMachine->postUpdate(deltaTime, time); }

	if (physicsModule){ physicsModule->postUpdate(deltaTime, time); }

	if (soundManager){ soundManager->postUpdate(deltaTime, time); }
}


void HardrockHolidayModules::initialize()
{
	PhysicsModule* physicsModule = new PhysicsModule();
	this->addPublicModule(physicsModule, typeid(PhysicsModule));


	SoundManager* soundManager = new SoundManager();
	this->addPublicModule(soundManager, typeid(SoundManager)); 


	InputDevice* inputDevice = new InputDevice(&Engine::globalResources.vektoriaCoreElements.frame);
	this->addPublicModule(inputDevice, typeid(InputDevice));


	StateMachine* stateMachine = new StateMachine();
	this->addPrivateModule(stateMachine, typeid(StateMachine));
}


void HardrockHolidayModules::run()
{
	StateMachine* stateMachine = static_cast<StateMachine*>(this->accessPrivateModule(typeid(StateMachine)));

	std::shared_ptr<State> gameState = std::shared_ptr<State>(new GameState());

	std::string beginningState = gameState->getName();

	stateMachine->addState(std::move(gameState));

	stateMachine->startExecution(beginningState);
}