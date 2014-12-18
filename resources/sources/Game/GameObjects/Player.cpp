#include "Game\GameObjects\Player.h"
#include "Graphics\playervisual.h"
#include "Engine\EngineMakros.h"
#include "Engine\Engine.h"


Player::Player() : PhysicalGameObject(Vektoria::CPlacement(), "Player", new phyX::SphereCollider(this, 0.1, 1, false), 1, false), _alive(true)
{
	this->initialize();
}


Player::Player(Vektoria::CPlacement position) : PhysicalGameObject(position, "Player", new phyX::SphereCollider(this, 0.1, 1, false), 1, false), _alive(true)
{
	this->initialize();
}


void Player::initialize()
{
	_position.AddPlacement(&_rotation);
	_visual = new PlayerVisual(&_rotation, &_position);

	this->GetRigidBody()->GetCollider()->SetLayer(_name);
}


Player::~Player()
{}


void Player::update(float deltaMillis, float time)
{
	//_position.TranslateZ(-time * 2.5);

	this->reactToInput();

    PhysicalGameObject::update(deltaMillis, time);
}


void Player::reactToInput()
{
	
	
	InputDevice* inputDevice = ENGINE_INPUT_DEVICE;

	if (inputDevice && this->isAlive())
	{
		float x = inputDevice->getXPosition();
		PhysicalGameObject::GetRigidBody()->AddForce(Vektoria::CHVector(1, 0, 0), x, false);
		if (x != 0){
			std::cout << "";
		}

		float y = inputDevice->getYPosition();
		PhysicalGameObject::GetRigidBody()->AddForce(Vektoria::CHVector(0, 0, 1), -0.5, false);
	}
	
	// TODO: Spieler abhängig von Bewegungsrichtung rotieren
	//_rotationPlacement.RotateX(-1 * 1.5);
}


void Player::onCollision(phyX::RigidBodyOwner* other, float timeDelta)
{
	std::string name = std::type_index(typeid(*other)).name();

	if (std::type_index(typeid(LochFalle)).name() == name) 
	{
		this->GetRigidBody()->GetCollider()->SetLayer("PitGround");
		
		//_alive = false;
	}
}


bool Player::isAlive() const
{
	return _alive;
}