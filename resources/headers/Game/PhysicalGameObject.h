
/*by Alexander Weiﬂ, 2014
 _____           _ _ _          _ 
/  __ \         | (_) |        (_)
| /  \/ ___   __| |_| |__  _ __ _ 
| |    / _ \ / _` | | '_ \| '__| |
| \__/\ (_) | (_| | | |_) | |  | |
 \____/\___/ \__,_|_|_.__/|_|  |_|*/

#ifndef PHYSICAL_GAME_OBJECT_H
#define PHYSICAL_GAME_OBJECT_H

#include "Game\GameObject.h"
#include "Physics\RigidBodyOwner.h"
#include "Physics\Utilities.h"
#include "Physics\Collider.h"


// A PhysicalGameObject represents a base template for every object in a Scene that will use a physical collision service of some kind. Its designated to be inherited from.
class PhysicalGameObject : public GameObject, public phyX::RigidBodyOwner
{
public:
	PhysicalGameObject(Vektoria::CPlacement position, const std::string& name, phyX::Collider* collider, float mass, bool hasGravity);

	~PhysicalGameObject();

	// This will be called once after collision with another collider.
	virtual void onCollision(phyX::RigidBodyOwner* other, float timeDelta);

	// This will be called during collision with another collider.
	virtual void duringCollision(phyX::RigidBodyOwner* other, float timeDelta);
};

#endif