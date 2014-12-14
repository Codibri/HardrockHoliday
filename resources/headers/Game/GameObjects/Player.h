
/*by Alexander Wei�, 2014
 _____           _ _ _          _ 
/  __ \         | (_) |        (_)
| /  \/ ___   __| |_| |__  _ __ _ 
| |    / _ \ / _` | | '_ \| '__| |
| \__/\ (_) | (_| | | |_) | |  | |
 \____/\___/ \__,_|_|_.__/|_|  |_|*/

#ifndef PLAYER_H
#define PLAYER_H

#include "Game\PhysicalGameObject.h"
#include "Physics\SphereCollider.h"
#include "Input\InputDevice.h"
#include "Game\GameObjectPrototypes.h"


class Player : public PhysicalGameObject
{
public:
	Player();
	Player(Vektoria::CPlacement position);
	~Player();

	virtual void update(float deltaMillis, float time) override;
	void reactToInput();
	void onCollision(phyX::RigidBodyOwner* otherCollider, float timeDelta) override;
	bool isAlive() const;

protected:
	Vektoria::CPlacement _rotation;
	bool _alive;
};

#endif