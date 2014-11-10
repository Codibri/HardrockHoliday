
//by Alexander Weiﬂ, 2014

#ifndef STATE_H
#define STATE_H

#include <iostream>
#include <map>
#include <memory>

typedef std::string StateName;
typedef std::string NextState;


// a State is an object used by a StateMachine to represent a single active state the StateMachine holds. Its designated to be inherited from
class State
{
public:
	State(StateName stateName);

	~State();

	// the State will automatically be updated by the StateMachine it belongs to. Add all its permanently looped logic here
	virtual NextState update(float deltaTime) = 0;

	// will be called when this State is set to be the active State by the StateMachine it belongs to
	virtual void onActivation();

	// will be called when another State is set to be the active State by the StateMachine it belongs to
	virtual void onDeactivation();

	const StateName getName() const;

protected:
	StateName _stateName;

};

#endif





