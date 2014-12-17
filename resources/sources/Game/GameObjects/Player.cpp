#include "Game\GameObjects\Player.h"
#include "Graphics\playervisual.h"
#include "Engine\EngineMakros.h"
#include "Engine\Engine.h"


Player::Player() : PhysicalGameObject(Vektoria::CPlacement(), "Player", PhysicalProperties(new phyX::SphereCollider(this, BOULDER_RADIUS, 1, false), 1, true)), _alive(true)
{
	this->initialize();
}


Player::Player(Vektoria::CPlacement position) : PhysicalGameObject(position, "Player", PhysicalProperties(new phyX::SphereCollider(this, BOULDER_RADIUS, 1, false), 1, true)), _alive(true), _startingPosition(position)
{
	this->initialize();
}


void Player::initialize()
{
	_position.AddPlacement(&_rotation);
	_visual = new PlayerVisual(&_rotation, &_position);

	this->GetRigidBody()->GetCollider()->SetLayer(_name);

	_gameOverImage.Init("GameResources\\Textures\\GameOverScreen.png");
	_gameOverOverlay.InitFull(&_gameOverImage, false);
	_gameOverOverlay.SetTransparency(0.4f);
	if (ENGINE->globalResources.vektoriaCoreElements.viewport != nullptr)
	{
		ENGINE->globalResources.vektoriaCoreElements.viewport->AddOverlay(&_gameOverOverlay);
	}

	this->reset();
}


Player::~Player()
{}


void Player::update(float deltaTime, float time)
{
	_visual->update(deltaTime, time);

	this->reactToInput();

	this->updateRotation();

	PhysicalGameObject::update(deltaTime, time);

	_oldPosition = _position.GetTranslation();
}


void Player::reactToInput()
{
	InputDevice* inputDevice = ENGINE_INPUT_DEVICE;

	if (inputDevice)
	{
		if (this->isAlive())
		{
			float x = inputDevice->getXPosition();
			PhysicalGameObject::GetRigidBody()->AddForce(Vektoria::CHVector(1, 0, 0), x, false);

			float z = inputDevice->getYPosition();
			z = 0.2; // <- this is for debug purposes only. TODO: delete when inputDevice is capable of returning real z values
			PhysicalGameObject::GetRigidBody()->AddForce(Vektoria::CHVector(0, 0, 1), -z, false);
		}
		else
		{
			bool reset = false;
			//reset = inputDevice->isResetButtonPressed();
			if (reset)
			{
				this->reset();
			}
		}
	}
}


void Player::onCollision(phyX::RigidBodyOwner* other, float timeDelta)
{
	std::string name = std::type_index(typeid(*other)).name();

	if (std::type_index(typeid(LochFalle)).name() == name) 
	{
		this->GetRigidBody()->GetCollider()->SetLayer("PitGround");
		_alive = false;
		_gameOverOverlay.SwitchOn();
	}
}


bool Player::isAlive() const
{
	return _alive;
}


void Player::updateRotation()
{
	_deltaDistanceMoved = _oldPosition - _position.GetTranslation();
	_rotation.RotateZDelta(_deltaDistanceMoved.x / BOULDER_RADIUS);
	_rotation.RotateXDelta(-_deltaDistanceMoved.z / BOULDER_RADIUS);
}


void Player::reset()
{
	_position.m_mLocal = _startingPosition.m_mLocal;
	_position.TranslateY(1.0f); //set a little bit higher to give the physics the chance to detect a collision with the ground

	_gameOverOverlay.SwitchOff();
}