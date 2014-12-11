#include "Game\GameObjects\Player.h"
#include "Graphics\playervisual.h"
#include "Engine\EngineMakros.h"
#include "Engine\Engine.h"


Player::Player() : PhysicalGameObject(Vektoria::CPlacement(), new phyX::SphereCollider(this, 0.1, 1, false), 1, false)
{
	_position.AddPlacement(&_rotationPlacement);
	_visual = new PlayerVisual(&_rotationPlacement, &_position);
}


Player::Player(Vektoria::CPlacement position) : PhysicalGameObject(position, new phyX::SphereCollider(this, 0.1, 1, false), 1, false)
{
	_position.AddPlacement(&_rotationPlacement);
	_visual = new PlayerVisual(&_rotationPlacement, &_position);
}


Player::~Player()
{}


void Player::update(float deltaMillis, float time)
{
	this->reactToInput();

	PhysicalGameObject::update(deltaMillis, time);
}


void Player::reactToInput()
{
	InputDevice* inputDevice = ENGINE_INPUT_DEVICE;

	if (inputDevice)
	{
		float x = inputDevice->getXPosition();
		PhysicalGameObject::GetRigidBody()->AddForce(Vektoria::CHVector(1, 0, 0), x, false);

		float y = inputDevice->getYPosition();
		PhysicalGameObject::GetRigidBody()->AddForce(Vektoria::CHVector(0, 0, 1), -y, false);
	}

	// TODO: Spieler abhängig von Bewegungsrichtung rotieren
	//_rotationPlacement.RotateX(-1 * 1.5);
}