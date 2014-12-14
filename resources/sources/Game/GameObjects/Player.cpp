#include "Game\GameObjects\Player.h"
#include "Graphics\playervisual.h"
#include "Engine\EngineMakros.h"
#include "Engine\Engine.h"


Player::Player() : PhysicalGameObject(Vektoria::CPlacement(), "Player", new phyX::SphereCollider(this, 0.1, 1, false), 1, false), _alive(true)
{
	_position.AddPlacement(&_rotation);
	_visual = new PlayerVisual(&_rotation, &_position);
}


Player::Player(Vektoria::CPlacement position) : PhysicalGameObject(position, "Player", new phyX::SphereCollider(this, 0.1, 1, false), 1, false), _alive(true)
{
	_position.AddPlacement(&_rotation);
	_visual = new PlayerVisual(&_rotation, &_position);
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
		PhysicalGameObject::GetRigidBody()->AddForce(Vektoria::CHVector(1, 0, 0), -0.5, false);

		float y = inputDevice->getYPosition();
		PhysicalGameObject::GetRigidBody()->AddForce(Vektoria::CHVector(0, 0, 1), -0.5, false);
	}

	// TODO: Spieler abhängig von Bewegungsrichtung rotieren
	//_rotationPlacement.RotateX(-1 * 1.5);
}


void Player::onCollision(phyX::RigidBodyOwner* other, float timeDelta)
{
	std::string name = std::type_index(typeid(*other)).name();

	// Collision with wall
	if (std::type_index(typeid(MapWall)).name() == name)
	{
		std::cout << "hit wall" << std::endl;
	}

	// Collision with trap
	else if (std::type_index(typeid(LochFalle)).name() == name)
	{
		std::cout << "hit trap" << std::endl;
	}
}


bool Player::isAlive() const
{
	return _alive;
}