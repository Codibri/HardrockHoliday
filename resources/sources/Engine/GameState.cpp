
/*by Alexander Weiß, 2014
 _____           _ _ _          _ 
/  __ \         | (_) |        (_)
| /  \/ ___   __| |_| |__  _ __ _ 
| |    / _ \ / _` | | '_ \| '__| |
| \__/\ (_) | (_| | | |_) | |  | |
 \____/\___/ \__,_|_|_.__/|_|  |_|*/

#include "Engine\GameState.h"
#include "Engine\Engine.h"


GameState::GameState() : State("GameState")
{
	_scene.init(&Engine::getInstance()->globalResources.vektoriaCoreElements.scene,
				&Engine::getInstance()->globalResources.vektoriaCoreElements.root);

	_scene.initViewport(&Engine::getInstance()->globalResources.vektoriaCoreElements.frame);

	_scene.loadLevel(1);
}


GameState::~GameState()
{}


NextState GameState::update(float deltaTime, float time)
{
	_scene.tick(deltaTime, time);


	return _stateName;
}




