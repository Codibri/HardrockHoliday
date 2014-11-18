
/*by Alexander Weiﬂ, 2014
 _____           _ _ _          _ 
/  __ \         | (_) |        (_)
| /  \/ ___   __| |_| |__  _ __ _ 
| |    / _ \ / _` | | '_ \| '__| |
| \__/\ (_) | (_| | | |_) | |  | |
 \____/\___/ \__,_|_|_.__/|_|  |_|*/

#ifndef ENGINE_MAKROS_H
#define ENGINE_MAKROS_H


// these are makros to make coding life easier / cleaner later on

#define ENGINE Engine::getInstance()
#define ENGINE_STATE_MACHINE static_cast<StateMachine*>(Engine::getInstance()->engineModules->access(typeid(StateMachine)))

//TODO finish these
//#define AUDIO Engine::getInstance()->modules.
//#define PHYSICS Engine::getInstance()->modules.

#endif