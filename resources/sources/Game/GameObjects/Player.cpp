#include "Game\GameObjects\Player.h"
#include "Graphics\playervisual.h"


Player::Player() : PhysicalGameObject(Vektoria::CPlacement())
{
	_position.AddPlacement(&_rotationPlacement);
	_visual = new PlayerVisual(getPlacement());
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
	_position.TranslateZDelta(-deltaMillis * 0.5);

	// Mareike
	// Keyboard::getXPosition() --> liefert float [-1;1] zurück
	// _position.TranslateXDelta ...

	_rotationPlacement.RotateX(-time );

	// Gameobject.tick()
	GameObject::update(deltaMillis, time);
}


