
/*by Alexander Weiﬂ, 2014
 _____           _ _ _          _ 
/  __ \         | (_) |        (_)
| /  \/ ___   __| |_| |__  _ __ _ 
| |    / _ \ / _` | | '_ \| '__| |
| \__/\ (_) | (_| | | |_) | |  | |
 \____/\___/ \__,_|_|_.__/|_|  |_|*/

#ifndef ENGINE_MAKROS_H
#define ENGINE_MAKROS_H


// These are makros to make coding life easier / cleaner later on.

#define ENGINE Engine::getInstance()

//#define MAKRO_NAME static_cast<ModuleClass*>(Engine::getInstance()->engineModules->accesPublicModule(typeid(ModuleClass)))


#define ENGINE_STATE_MACHINE this->accessPrivateModule(typeid(StateMachine))

//TODO finish these
//#define AUDIO Engine::getInstance()->modules.
//#define PHYSICS Engine::getInstance()->modules.

#endif