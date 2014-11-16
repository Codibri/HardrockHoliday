#include "Game\GameObjects\Player.h"


Player::Player() : PhysicalGameObject(Vektoria::CPlacement())
{
	_position.AddPlacement(&_rotationPlacement);
}


Player::Player(Vektoria::CPlacement position) : PhysicalGameObject(position)
{
	_position.AddPlacement(&_rotationPlacement);
}


Player::~Player()
{
}


void Player::update(float deltaMillis, float time){


	// Beispielsweise spieler noch vorne bewegen
	_position.TranslateZDelta(-deltaMillis);

	_rotationPlacement.RotateX(-time * 1.5);

	// Gameobject.tick()
	GameObject::update(deltaMillis, time);
}


