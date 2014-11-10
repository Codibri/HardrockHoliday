
//by Alexander Weiß, 2014

#include "Engine\GameState.h"


GameState::GameState() : State("GameState"), _hwnd(Engine::getInstance()->globalResources.hWnd)
{
	_root.Init(Engine::getInstance()->globalResources.splash);
	_frame.Init(Engine::getInstance()->globalResources.hWnd);

	_camera.Init();
	_viewport.InitFull(&_camera);

	_root.AddFrameHere(&_frame);
	_frame.AddViewport(&_viewport);
}


GameState::~GameState()
{}


NextState GameState::update(float deltaTime)
{
	_root.Tick(deltaTime);

	std::string debugMSG = "Updated " + _stateName;
	DEBUG_OUT(debugMSG)

	return _stateName;
}

