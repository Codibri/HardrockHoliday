
//by Alexander Weiß, 2014

#include "Engine\GameState.h"


GameState::GameState() : State("GameState"), _hwnd(Engine::getInstance()->globalResources.hWnd)
{
	_rootVektoria.Init(Engine::getInstance()->globalResources.splash);
	_frameVektoria.Init(Engine::getInstance()->globalResources.hWnd);

	_cameraVektoria.Init();
	_viewportVektoria.InitFull(&_cameraVektoria);

	_rootVektoria.AddFrameHere(&_frameVektoria);
	_frameVektoria.AddViewport(&_viewportVektoria);

	_scene.init(&_sceneVektoria, &_rootVektoria);
	_scene.loadLevel(1);
}


GameState::~GameState()
{}


NextState GameState::update(float deltaTime, float time)
{
	_rootVektoria.Tick(deltaTime);

	std::string debugMSG = "Updated " + _stateName;
	DEBUG_OUT(debugMSG)

	return _stateName;
}

