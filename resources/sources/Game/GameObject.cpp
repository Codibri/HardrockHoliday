
//by Alexander Weiﬂ, 2014

#include "Game\GameObject.h"


GameObject::GameObject(Vektoria::CHVector position) : _position(position), _geometry(nullptr)
{}


GameObject::~GameObject()
{}


void GameObject::update(float timeDelta)
{
	//does nothing
}