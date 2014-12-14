
/*by Alexander Wei�, 2014
 _____           _ _ _          _ 
/  __ \         | (_) |        (_)
| /  \/ ___   __| |_| |__  _ __ _ 
| |    / _ \ / _` | | '_ \| '__| |
| \__/\ (_) | (_| | | |_) | |  | |
 \____/\___/ \__,_|_|_.__/|_|  |_|*/

#include "Engine\GameState.h"
#include "Engine\Engine.h"
#include "Audio\SoundManager.h"


GameState::GameState() : State("GameState")
{
	_scene.init(&Engine::getInstance()->globalResources.vektoriaCoreElements.scene,
				&Engine::getInstance()->globalResources.vektoriaCoreElements.root);

	_scene.initViewport(&Engine::getInstance()->globalResources.vektoriaCoreElements.frame);

	_scene.loadLevel(1);

	//SoundManager* soundManager = ENGINE_SOUND_MANAGER; // play background music
}


GameState::~GameState()
{}


NextState GameState::update(float deltaTime, float time)
{
	NextState nextState = _stateName;

	_scene.tick(deltaTime, time);


	return nextState;
}




