
//by Alexander Weiﬂ, 2014

#ifndef PHYSICAL_GAME_OBJECT_H
#define PHYSICAL_GAME_OBJECT_H

#include "Game\GameObject.h"

class Collider; //TODO: replace by actual physics implementation


// a PhysicalGameObject represents a base template for every object in a Scene that will use a physical collision service of some kind. Its designated to be inherited from
class PhysicalGameObject : public GameObject
{
public:
	PhysicalGameObject(Vektoria::CPlacement position);

	~PhysicalGameObject();

	// this will be called once after collision with another collider
	virtual void onCollision(Collider* collidingObject);

	// this will be called during collision with another collider
	virtual void duringCollision(Collider* collidingObject);

protected:
	//Collider _collider;  //TODO: replace by actual physics imlementation
};

#endif