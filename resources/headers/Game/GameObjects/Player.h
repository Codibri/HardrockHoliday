
/*by Alexander Weiﬂ, 2014
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

const float BOULDER_RADIUS = 0.1f;

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
	void updateRotation();

protected:
	void initialize();

	Vektoria::CPlacement _rotation;
	Vektoria::CHVector _oldPosition;
	Vektoria::CHVector _deltaDistanceMoved;
	bool _alive;
};

#endif