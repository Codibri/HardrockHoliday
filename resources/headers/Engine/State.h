
/*by Alexander Wei�, 2014
 _____           _ _ _          _ 
/  __ \         | (_) |        (_)
| /  \/ ___   __| |_| |__  _ __ _ 
| |    / _ \ / _` | | '_ \| '__| |
| \__/\ (_) | (_| | | |_) | |  | |
 \____/\___/ \__,_|_|_.__/|_|  |_|*/

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
	State(const StateName& stateName);
	
	~State();

	// the State will automatically be updated by the StateMachine it belongs to. Add all its permanently looped logic here
	virtual NextState update(float deltaTime, float time) = 0;

	// will be called when this State is set to be the active State by the StateMachine it belongs to
	virtual void onActivation();

	// will be called when another State is set to be the active State by the StateMachine it belongs to
	virtual void onDeactivation();

	const StateName getName() const;

protected:
	StateName _stateName;

};

#endif





