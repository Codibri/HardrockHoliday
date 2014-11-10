
//by Alexander Weiﬂ, 2014

#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

#include "Root.h"


// the GameObject is the base template for every Object that can appear in a Scene. Its designated to be inherited from 
class GameObject
{
public:
	GameObject(Vektoria::CHVector position);

	~GameObject();

	// the GameObject will automatically be updated by the State it belongs to. Add all its permanently looped logic here
	virtual void update(float deltaTime);

protected:
	Vektoria::CHVector _position;
	Vektoria::CGeo* _geometry;
};

#endif