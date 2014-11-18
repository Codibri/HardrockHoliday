
/*by Alexander Weiﬂ, 2014
 _____           _ _ _          _ 
/  __ \         | (_) |        (_)
| /  \/ ___   __| |_| |__  _ __ _ 
| |    / _ \ / _` | | '_ \| '__| |
| \__/\ (_) | (_| | | |_) | |  | |
 \____/\___/ \__,_|_|_.__/|_|  |_|*/

#ifndef GAME_STATE_H
#define GAME_STATE_H

#include "State.h"
#include "Engine.h"
#include "..\Utility\DebugLog.h"
#include "Game\Scene.h"

// the State is a superstate for everything that happens in the game itself. It holds the Scene, the GameObjects and everything else basically
class GameState : public State
{
public:
	GameState();

	~GameState();

	NextState update(float deltaTime, float time);

private:
	HWND _hwnd;

	//Vektoria Elemente
	Vektoria::CRoot _rootVektoria;
	Vektoria::CFrame _frameVektoria;
	Vektoria::CViewport _viewportVektoria;
	//Vektoria::CCamera _cameraVektoria;
	Vektoria::CScene _sceneVektoria;

	Scene _scene;
};

#endif