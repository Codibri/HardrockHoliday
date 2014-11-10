
//by Alexander Weiﬂ, 2014

#ifndef GAME_STATE_H
#define GAME_STATE_H

#include "State.h"
#include "Engine.h"
#include "..\Utility\DebugLog.h"


// the State is a superstate for everything that happens in the game itself. It holds the Scene, the Objects and everything else basically
class GameState : public State
{
public:
	GameState();

	~GameState();

	NextState update(float deltaTime);

private:
	HWND _hwnd;

	//Vektoria Elemente
	Vektoria::CRoot _root;
	Vektoria::CFrame _frame;
	Vektoria::CViewport _viewport;
	Vektoria::CCamera _camera;
};

#endif