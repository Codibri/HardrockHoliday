
/*by Alexander Weiﬂ, 2014
 _____           _ _ _          _ 
/  __ \         | (_) |        (_)
| /  \/ ___   __| |_| |__  _ __ _ 
| |    / _ \ / _` | | '_ \| '__| |
| \__/\ (_) | (_| | | |_) | |  | |
 \____/\___/ \__,_|_|_.__/|_|  |_|*/

#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

#include "Root.h"
#include "Graphics\Visual.h"

// The GameObject is the base template for every Object that can appear in a Scene. Its designated to be inherited from. 
class GameObject
{
public:
	GameObject(Vektoria::CPlacement position);

	~GameObject();

	// The GameObject will automatically be updated by the State it belongs to. 
	// Add all its permanently looped logic here.
	virtual void update(float deltaTime, float time);

	// Retrieves a pointer to the placement that is used to position the GameObject.
	Vektoria::CPlacement* getPlacement();

	void setVisual(Visual* visual);

protected:
	Vektoria::CPlacement _position;
	Vektoria::CGeo* _geometry;
	Visual* _visual;
};

#endif