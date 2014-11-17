
//by Alexander Wei�, 2014

#include "Engine\StateMachine.h"


StateMachine::StateMachine() : EngineModule(), _currentState(nullptr), _isRunning(false)
{}


StateMachine::~StateMachine()
{}


void StateMachine::startExecution(const StateName& stateName)
{
	if (!_isRunning)
	{
		if (activateState(stateName))
		{
			_isRunning = true;
		}
	}
}


void StateMachine::addState(std::shared_ptr<State> state)
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


void StateMachine::update(float deltaTime, float time)
{
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
}


bool StateMachine::isRunning() const
{
	return _isRunning;
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

