
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
	void onCollision(phyX::RigidBodyOwner* otherCollider, float timeDelta) override;
	bool isAlive() const;

protected:
	void initialize();
	void updateRotation();
	void reset();
	void reactToInput(float deltaTime);

	Vektoria::CPlacement _startingPosition;

	//TODO: make Boulder inherit from player and seperate the specialized and general logic
	Vektoria::CPlacement _rotation;
	Vektoria::CHVector _oldPosition;
	Vektoria::CHVector _deltaDistanceMoved;

	//TODO: move this out of player to a kind of game flow class
	Vektoria::CImage _gameOverImage;
	Vektoria::COverlay _gameOverOverlay;

	bool _alive;
};

#endif