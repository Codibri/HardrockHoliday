
/*by Alexander Weiﬂ, 2014
 _____           _ _ _          _ 
/  __ \         | (_) |        (_)
| /  \/ ___   __| |_| |__  _ __ _ 
| |    / _ \ / _` | | '_ \| '__| |
| \__/\ (_) | (_| | | |_) | |  | |
 \____/\___/ \__,_|_|_.__/|_|  |_|*/

#include "Engine\State.h"


State::State(const StateName& stateName) : _stateName(stateName)
{}


State::~State()
{}


void State::onActivation()
{
	std::cout << _stateName.c_str() << " activated. \n";
}


void State::onDeactivation()
{
	std::cout << _stateName.c_str() << " deactivated. \n";
}


const StateName State::getName() const
{
	return _stateName;
}