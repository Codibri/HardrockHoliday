
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
	_rootVektoria.Init(Engine::getInstance()->globalResources.splash);
	_frameVektoria.Init(Engine::getInstance()->globalResources.hWnd);


	_rootVektoria.AddScene(&_sceneVektoria);

	_scene.init(&_sceneVektoria, &_rootVektoria);
	_scene.initViewport(&_viewportVektoria);

	_rootVektoria.AddFrameHere(&_frameVektoria);

	_frameVektoria.AddViewport(&_viewportVektoria);

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

