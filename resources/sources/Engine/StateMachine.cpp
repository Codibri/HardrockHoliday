
/*by Alexander Weiﬂ, 2014
 _____           _ _ _          _ 
/  __ \         | (_) |        (_)
| /  \/ ___   __| |_| |__  _ __ _ 
| |    / _ \ / _` | | '_ \| '__| |
| \__/\ (_) | (_| | | |_) | |  | |
 \____/\___/ \__,_|_|_.__/|_|  |_|*/

#include "Engine\StateMachine.h"


StateMachine::StateMachine() : EngineModule(), _currentState(nullptr), _isRunning(false)
{
	_lock_machine.clear();
}


StateMachine::~StateMachine()
{}


void StateMachine::startExecution(const StateName& stateName)
{
	while (_lock_machine.test_and_set())
	{}

	if (!_isRunning)
	{
		if (activateState(stateName))
		{
			_isRunning = true;
		}
	}

	_lock_machine.clear();
}


void StateMachine::addState(std::shared_ptr<State> state)
{
	while (_lock_machine.test_and_set())
	{}

	if (!_isRunning)
	{
		if (state != nullptr)
		{
			_states[state->getName()] = state;
		}
		else
		{
			DEBUG_OUT("Error (StateMachine): Couldn't add state as state was a nullptr. \n")
		}
	}
	else
	{
		DEBUG_OUT("Error (StateMachine): Couldn't add state as the StateMachine was already running. Initialize all states before calling startExecution(). \n")
	}

	_lock_machine.clear();
}


void StateMachine::update(float deltaTime, float time)
{
	while (_lock_machine.test_and_set())
	{}

	if (_isRunning)
	{
		if (_currentState != nullptr)
		{
			NextState nextState = _currentState->update(deltaTime, time);

			if (_currentState->getName() != nextState)
			{
				_isRunning = activateState(nextState);
			}
		}
		else
		{
			_isRunning = false;
		}
	}
	else
	{
		DEBUG_OUT("Error (StateMachine): StateMachine is currently not running. Call \"startExecution()\" first. \n")
	}

	_lock_machine.clear();
}


bool StateMachine::isRunning()
{
	bool isRunning = false;

	while (_lock_machine.test_and_set())
	{}

	isRunning = _isRunning;

	_lock_machine.clear();

	return isRunning;
}


bool StateMachine::activateState(const StateName& stateName)
{
	bool success = false;

	if (_currentState != nullptr)
	{
		_currentState->onDeactivation();
	}

	try
	{
		_currentState = _states.at(stateName);
		_currentState->onActivation();
		success = true;
	}
	catch (const std::out_of_range&)
	{
		DEBUG_OUT("Error (StateMachine): State not found. \n")
	}

	return success;
}

