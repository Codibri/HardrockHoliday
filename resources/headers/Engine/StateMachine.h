
/*by Alexander Weiﬂ, 2014
 _____           _ _ _          _ 
/  __ \         | (_) |        (_)
| /  \/ ___   __| |_| |__  _ __ _ 
| |    / _ \ / _` | | '_ \| '__| |
| \__/\ (_) | (_| | | |_) | |  | |
 \____/\___/ \__,_|_|_.__/|_|  |_|*/

#ifndef STATE_MACHINE_H
#define STATE_MACHINE_H

#include "EngineModule.h"
#include "State.h"
#include "Utility\DebugLog.h"


// A StateMachine is capable of holding a number of states that it can manage. It updates a single actives State in its own update method
class StateMachine : public EngineModule
{
public:
	StateMachine();

	virtual ~StateMachine();

	// Begins execution of the StateMachine with the named state as the first set state (allows to call update afterwards).
	// Ignored if the named state has not been added yet.
	// Ignored if already running.
	void startExecution(const StateName& stateName);

	// Adds a new state to the StateMachine which can then be activated (switched to).
	// Needs to be called once before starExecution() otherwise the StateMachine won't have any valid states.
	// Ignored if the StateMachne is already running.
	void addState(std::shared_ptr<State> state);

	// Calls the StateMachine to update its states and then switches to a new state if the current state signals to do so, otherwise keeps the current state active.
	// Ignored if no valid state is set.
	void update(float deltaTime, float time) override;

	// Is the StateMachine currently running? FALSE until startExecution has been called successfully, TRUE afterwards as long no error has occurred during any update.
	bool isRunning() const;

private:
	bool activateState(const StateName& stateName);

	std::map<StateName, std::shared_ptr<State>> _states;
	std::shared_ptr<State> _currentState;
	bool _isRunning;
};

#endif