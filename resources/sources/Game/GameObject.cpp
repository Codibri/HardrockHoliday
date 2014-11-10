
//by Alexander Weiﬂ, 2014

#include "Game\GameObject.h"


GameObject::GameObject(Vektoria::CPlacement position) : _position(position), _geometry(nullptr)
{}


GameObject::~GameObject()
{}


void GameObject::update(float timeDelta, float time)
{
	//does nothing
}


Vektoria::CPlacement* GameObject::getPlacement() 
{
	return &_position;
}