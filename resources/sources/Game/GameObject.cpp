
/*by Alexander Weiﬂ, 2014
 _____           _ _ _          _ 
/  __ \         | (_) |        (_)
| /  \/ ___   __| |_| |__  _ __ _ 
| |    / _ \ / _` | | '_ \| '__| |
| \__/\ (_) | (_| | | |_) | |  | |
 \____/\___/ \__,_|_|_.__/|_|  |_|*/

#include "Game\GameObject.h"


GameObject::GameObject(Vektoria::CPlacement position) : _position(position), _geometry(nullptr)
{}


GameObject::~GameObject()
{}


void GameObject::update(float timeDelta, float time)
{}


Vektoria::CPlacement* GameObject::getPlacement() 
{
	return &_position;
}


void GameObject::setVisual(Visual* visual)
{
	_visual = visual;
}