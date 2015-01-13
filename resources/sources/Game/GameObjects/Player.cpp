#include "Game\GameObjects\Player.h"
#include "Graphics\playervisual.h"
#include "Engine\EngineMakros.h"
#include "Engine\Engine.h"


class Goal;

Player::Player() : PhysicalGameObject(Vektoria::CPlacement(), "Player", PhysicalProperties(new phyX::SphereCollider(this, BOULDER_RADIUS, 1, false), 0.3f, true)),
	_alive(true), _crashing(false), _won(false), _rolling(false), _falling(false)
{
	this->initialize();
}


Player::Player(Vektoria::CPlacement position) : PhysicalGameObject(position, "Player", PhysicalProperties(new phyX::SphereCollider(this, BOULDER_RADIUS, 1, false), 1, true)), 
	_alive(true), _crashing(false), _won(false), _rolling(false), _falling(false), _startingPosition(position)
{
	this->initialize();
}


void Player::initialize()
{
	_courseTime.AddToViewPort(Engine::globalResources.vektoriaCoreElements.viewport);
	_courseTime.Show();

	_position.AddPlacement(&_rotation);
	_visual = new PlayerVisual(&_rotation, &_position);

	this->GetRigidBody()->GetCollider()->SetLayer(_name);

	_gameOverImage.Init("GameResources\\Textures\\GameOverScreen.png");
	_gameOverOverlay.Init(&_gameOverImage, Vektoria::CFloatRect(0.2f, 0.2f, 0.6f, 0.6f), false);

	_gameOverImage.Init("GameResources\\Textures\\GameWinScreen.png");
	_gameWinOverlay.Init(&_gameWinImage, Vektoria::CFloatRect(0.2f, 0.2f, 0.6f, 0.6f), false);

	if (ENGINE->globalResources.vektoriaCoreElements.viewport != nullptr)
	{
		ENGINE->globalResources.vektoriaCoreElements.viewport->AddOverlay(&_gameOverOverlay);
		ENGINE->globalResources.vektoriaCoreElements.viewport->AddOverlay(&_gameWinOverlay);
	}

	this->reset();
}


Player::~Player()
{}


void Player::update(float deltaTime, float time)
{
	_visual->update(deltaTime, time);

	this->reactToInput(deltaTime);

	this->updateRotation();

	PhysicalGameObject::update(deltaTime, time);

	_oldPosition = _position.GetTranslation();

	_courseTime.Update(deltaTime, time);
	_rumbleTimeout.Update(deltaTime, time);


	SoundManager* soundManager = ENGINE_SOUND_MANAGER;
	if (soundManager)
	{
		if (!_rolling)
		{
			if (_deltaDistanceMoved.z > 0.0005 || _deltaDistanceMoved.x > 0.0005)
			{
				_rolling = true;
				soundManager->play(Sound::StoneRolling, true);
				printf("Play Rolling");
			}
		}
		else
		{
			if (_deltaDistanceMoved.z < 0.0005 && _deltaDistanceMoved.x < 0.0005)
			{
				_rolling = false;
				soundManager->stop(Sound::StoneRolling);
			}
		}

		if (!_falling)
		{
			if (_deltaDistanceMoved.y > 0.1)
			{
				_falling = true;
				soundManager->play(Sound::StoneFalling, true);
			}
		}
		else
		{
			if (_deltaDistanceMoved.y < 0.1)
			{
				_falling = false;
				soundManager->stop(Sound::StoneFalling);
			}
		}
	}
}


void Player::reactToInput(float deltaTime)
{
	InputDevice* inputDevice = ENGINE_INPUT_DEVICE;
	if (inputDevice)
	{
		if (_rumbleTimeout.GetMilliSeconds() > 1000)
		{
			_rumbleTimeout.Stop();
			_rumbleTimeout.Reset();
			inputDevice->rumble(false, 10);
			_crashing = false;
		}

		if (inputDevice->isKeyPressed(Game_Inputs::End_Key))
		{
			Engine::globalResources.endThisMess = true;
		}

		if (inputDevice->isKeyPressed(Game_Inputs::Reset_Key))
		{
			this->reset();
		}

		if (this->isAlive())
		{
			float x = inputDevice->getXPosition();
			int direction = -1;
			if (x > 0)
			{
				direction = 1;
			}
			x = abs(x);
			//PhysicalGameObject::GetRigidBody()->AddForce(Vektoria::CHVector(1, 0, 0), x, false);
			//PhysicalGameObject::GetRigidBody()->AddImpulse(Vektoria::CHVector(direction, 0, 0), 200 * x * deltaTime, false);
			PhysicalGameObject::GetRigidBody()->AddForce(Vektoria::CHVector((float)direction, 0, 0), 40.f * x * deltaTime, false);

			float z = inputDevice->getZPosition();
			if (z > 0)
			{
				z = 0;
			}
			z = abs(z);
			//z = 0.03; // <- this is for debug purposes only. TODO: delete when inputDevice is capable of returning real z values
			//PhysicalGameObject::GetRigidBody()->AddForce(Vektoria::CHVector(0, 0, 1), 5*z, false);
			//PhysicalGameObject::GetRigidBody()->AddImpulse(Vektoria::CHVector(0, 0, -1), 200 * z * deltaTime, false);
			PhysicalGameObject::GetRigidBody()->AddForce(Vektoria::CHVector(0, 0, -1.0f), 20.f * z * deltaTime, false);
		}
	}
}


void Player::onCollision(phyX::RigidBodyOwner* other, float timeDelta)
{
	std::string name = std::type_index(typeid(*other)).name();

	if (other->GetRigidBody()->GetCollider()->GetCollisionLayerName() == "PitGround")
	{
		PhysicalGameObject::GetRigidBody()->Freeze(true, false, true);
	}

	if (std::type_index(typeid(LochFalle)).name() == name) 
	{
		//die
		if (_alive)
		{
			this->GetRigidBody()->GetCollider()->SetLayer("PitGround");
			_alive = false;
			_gameOverOverlay.SwitchOn();
			_courseTime.Stop();
		}
	}

	if (std::type_index(typeid(MapWall)).name() == name)
	{
		//crash
		if (!_crashing)
		{
			InputDevice* inputDevice = ENGINE_INPUT_DEVICE;
			if (inputDevice)
			{
				_rumbleTimeout.Start();
				inputDevice->rumble(true, 10);
				_crashing = true;
			}
		}
	}

	if (std::type_index(typeid(LevelEnd)).name() == name)
	{
		//win
		if (!_won)
		{
			_gameWinOverlay.SwitchOn();
			_won = true;
		}
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
	//_position.TranslateZDelta(-8.f); //debug position

	PhysicalGameObject::GetRigidBody()->Freeze(false, false, false);

	_gameOverOverlay.SwitchOff();
	_gameWinOverlay.SwitchOff();

	_courseTime.Reset();
	_courseTime.Start();

	_alive = true;
	_won = false;
	_crashing = false;
	_rolling = false;
	_falling = false;

	SoundManager* soundManager = ENGINE_SOUND_MANAGER;
	if (soundManager)
	{
		soundManager->stop(Sound::StoneRolling);
		soundManager->stop(Sound::StoneFalling);
		soundManager->stop(Sound::StoneBreaking);
	}
}