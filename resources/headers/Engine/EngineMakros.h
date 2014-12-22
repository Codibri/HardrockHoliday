
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

#define ENGINE_PHYSICS static_cast<PhysicsModule*>(Engine::getInstance()->engineModules->accessPublicModule(typeid(PhysicsModule)))
#define ENGINE_SOUND_MANAGER static_cast<SoundManager*>(Engine::getInstance()->engineModules->accessPublicModule(typeid(SoundManager)))
#define ENGINE_INPUT_DEVICE static_cast<InputDevice*>(Engine::getInstance()->engineModules->accessPublicModule(typeid(InputDevice)))
#define ENGINE_STATE_MACHINE static_cast<StateMachine*>(Engine::getInstance()->engineModules->accessPrivateModule(typeid(StateMachine)))

#endif