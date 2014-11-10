#include "Game\GameObjects\Player.h"


Player::Player() : PhysicalGameObject(Vektoria::CPlacement())
{
}


Player::Player(Vektoria::CPlacement position) : PhysicalGameObject(position)
{
}


Player::~Player()
{
}


void Player::update(float deltaMillis, float time){


	// Beispielsweise spieler noch vorne bewegen
	_position.TranslateZDelta(-deltaMillis);


	// Gameobject.tick()
	GameObject::update(deltaMillis, time);
}


