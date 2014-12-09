#include "Game\GameObjects\Player.h"
#include "Graphics\playervisual.h"


Player::Player() : PhysicalGameObject(Vektoria::CPlacement())
{
	_position.AddPlacement(&_rotationPlacement);
	_visual = new PlayerVisual(&_rotationPlacement, &_position);
}


Player::Player(Vektoria::CPlacement position) : PhysicalGameObject(position)
{
	_position.AddPlacement(&_rotationPlacement);

	_visual = new PlayerVisual(&_rotationPlacement, &_position);
}


Player::~Player()
{
}


void Player::update(float deltaMillis, float time){


	// Beispielsweise spieler noch vorne bewegen
	_position.TranslateZDelta(-deltaMillis * 0.5);

	// TODO: Spieler abhängig von Bewegungsrichtung rotieren
	_rotationPlacement.RotateX(-time * 1.5);
	

	// Gameobject.tick()
	GameObject::update(deltaMillis, time);
}


