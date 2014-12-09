
/*by Alexander Weiß, 2014
 _____           _ _ _          _ 
/  __ \         | (_) |        (_)
| /  \/ ___   __| |_| |__  _ __ _ 
| |    / _ \ / _` | | '_ \| '__| |
| \__/\ (_) | (_| | | |_) | |  | |
 \____/\___/ \__,_|_|_.__/|_|  |_|*/

#include "Engine\GameState.h"


GameState::GameState() : State("GameState"), _hwnd(Engine::getInstance()->globalResources.hWnd)
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

	std::string debugMSG = "Updated " + _stateName;
	DEBUG_OUT(debugMSG)

	return _stateName;
}

